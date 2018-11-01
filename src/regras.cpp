/**
 * @file regras.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-11-01
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#include <algorithm>
#include <vector>
#include <array>
#include <string>
#include <fstream>
#include <stdexcept>

//#include <omp.h>

#include "../include/regras.h" // < ------ retirar isso depois

regras::regras(loteria volante, std::string file_name = ""){
    if(file_name.size() == 0){
        /// escrever aqui o gerador de regras altomático
    } else {
        std::vector <unsigned short int> vetor;
        std::string route = "../data/regras_"; 
        route = route + file_name; 
        route = route + ".txt";
        std::ifstream teste(route);
        long long valuer_test;
        if(!teste.good()){
            throw std::runtime_error( "Erro ao ler arquivo de regras" );
        }
        while( teste >> valuer_test ){
            if(valuer_test < 0){
                throw std::runtime_error( "Erro ao ler arquivo de regras" );
            }
        }
        teste.close();
        std::ifstream ifs(route);
        unsigned long int valuer;
        while( ifs >> valuer ){
            vetor.push_back(valuer);
        }
        ifs.close();
        if(!adicionar_regras(vetor, volante)){
            throw std::runtime_error( "Erro ao adicionar regras" );
        }
    }
}

std::vector <unsigned short int> regras::gerador_de_regras(loteria modalidade){
    float delimitador = 1; //%
    
    // regra da soma
    analise_da_soma(delimitador, modalidade);

    // regra pares e impares
    analise_do_pares_impares(delimitador, modalidade);

    // regra sequencia
    analise_da_sequencia(delimitador, modalidade);

    // regra primo
    analise_do_primo(delimitador, modalidade);

    // regra múltiplo 3
    analise_do_multiplo_3(delimitador, modalidade);

    // regra fibonacci
    analise_do_fibonacci(delimitador, modalidade);

    // regra dezena repetida  
    analise_da_dezena_repetida(delimitador, modalidade);

}

void regras::analise_da_soma(float delimitador, loteria modalidade){
    std::vector <unsigned long int> analise_soma;
    for(auto i=0; i<=modalidade.verificar_quantidade_jogos_totais_sorteados(); ++i){
        unsigned long int soma = 0;
        #pragma omp parallel for reduction(+ : soma)
        for(auto j=0; j<modalidade.verificar_quantidade_numeros_sorteados(); ++j){
            #pragma omp critical
            {
                soma += modalidade.veriticar_jogo_sorteado(i)[j];
            }
        }
        analise_soma.push_back(soma);
    }
    std::sort(analise_soma.begin(), analise_soma.end());
    struct analise{
        unsigned long int valor;
        unsigned long int quantidade;
        float porcentagem;
    };    
    auto menor_valor(analise_soma.front());
    auto maior_valor(analise_soma.back());
    auto distancia = maior_valor - menor_valor;
    analise soma_analise[distancia];
    for(unsigned long int i = menor_valor, posicao = 0; i<=maior_valor; ++i, ++posicao){
        unsigned long int soma = 0;
        #pragma omp parallel for reduction(+ : soma)
        for(auto j=0; j<analise_soma.size(); ++j){
            if(analise_soma[j] == i){
                #pragma omp critical
                {
                    ++soma;
                }
            }
        }
        soma_analise[posicao].valor = i;
        soma_analise[posicao].quantidade = soma;
    }
    auto maior_quantidade(0);
    for(auto i(0); i<distancia; ++i){
        if(soma_analise[i].quantidade > maior_quantidade){
            maior_quantidade = soma_analise[i].quantidade;
        }
    }
    for(auto i(0); i<distancia; ++i){
        soma_analise[i].porcentagem = (((soma_analise[i].quantidade)*100)/maior_quantidade);
    }
    for(auto i(0); i<distancia; ++i){
        if(soma_analise[i].porcentagem > delimitador){
            if(!adiconar_nova_soma(soma_analise[i].valor, modalidade)){
                throw std::runtime_error( "Erro ao adicionar regra da soma" );
            }
        }
    }
}

bool regras::adicionar_regras(std::vector <unsigned short int> lista_regras, loteria volante){
    if(lista_regras.size()<=quantidade_de_regras_disponiveis){
        return false;
    }
    auto quantidade_num(lista_regras[0]);
    unsigned short int numero_da_regra(1);
    for(auto i(1); i<lista_regras.size(); ++i){
        if(quantidade_num!=0){
            bool indicador(false);
            if(numero_da_regra == 1){
                indicador = adiconar_nova_soma(lista_regras[i], volante);                
            } else {
                if(numero_da_regra == 2){
                    if((i+1) == lista_regras.size()){
                        return false;
                    }
                    indicador = adiconar_novo_pares_impares(lista_regras[i], lista_regras[i+1], volante);
                    --quantidade_num;
                    ++i;                
                } else {
                    if(numero_da_regra == 3){
                        indicador = adiconar_nova_sequencia(lista_regras[i], volante);                
                    } else {
                        if(numero_da_regra == 4){
                            indicador = adiconar_novo_primo(lista_regras[i], volante);                
                        } else {
                            if(numero_da_regra == 5){
                                indicador = adiconar_novo_multiplo_3(lista_regras[i], volante);                
                            } else {
                                if(numero_da_regra == 6){
                                    indicador = adiconar_novo_fibonacci(lista_regras[i], volante);                
                                } else {
                                    if(numero_da_regra == 7){
                                        indicador = adiconar_nova_dezena_repetida(lista_regras[i], volante);                
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if(!indicador){
                return false;;
            } else {
                --quantidade_num;
            }
        } else {
            if(lista_regras[i] == 0){
                return false;
            }
            quantidade_num = lista_regras[i];
            ++numero_da_regra;
        }
        if(((i+1) == lista_regras.size()) and (i != quantidade_de_regras_disponiveis)){
            return false;
        }
    }
    return true;
}

bool regras::adiconar_nova_soma(unsigned short int nova_soma, loteria volante){
    long long soma_maxima = 0;
    #pragma omp parallel for reduction(+ : soma_maxima)
    for(auto i = 0; i<volante.verificar_quantidade_numeros_sorteados(); ++i){
        #pragma omp critical
        {
            soma_maxima += volante.veriticar_numeros_do_volante()[i];
        }
    }
    if(soma_maxima<nova_soma){
        return false;
    }
    long long soma_minima = 0;
    #pragma omp parallel for reduction(+ : soma_minima)
    for(auto i = (volante.verificar_quantidade_numeros_do_volante()-1); i>=(volante.verificar_quantidade_numeros_do_volante()-volante.verificar_quantidade_numeros_sorteados()); --i){
        #pragma omp critical
        {
            soma_minima += volante.veriticar_numeros_do_volante()[i];
        }
    }
    if(soma_minima<nova_soma){
        return false;
    }
    soma.push_back(nova_soma);
    std::sort(soma.begin(), soma.end());
    return true;    
}

bool regras::adiconar_novo_pares_impares(unsigned short int quantidade_par, unsigned short int quantidade_impar, loteria volante){
    if((quantidade_par + quantidade_impar) != volante.verificar_quantidade_numeros_sorteados()){
        return false;
    }
    std::array<unsigned short int, 2> novo_par;
    novo_par[0] = quantidade_par;
    novo_par[1] = quantidade_impar;
    pares_impares.push_back(novo_par);
    return true;
}

bool regras::adiconar_nova_sequencia(unsigned short int quantidade, loteria volante){
    if(quantidade > volante.verificar_quantidade_numeros_sorteados()){
        return false;
    }
    sequencia.push_back(quantidade);
    std::sort(sequencia.begin(), sequencia.end());
    return true;
}

bool regras::adiconar_novo_primo(unsigned short int quantidade, loteria volante){
    if(quantidade > volante.veriticar_numeros_do_volante().back()){
        return false;
    }
    primos.push_back(quantidade);
    std::sort(primos.begin(), primos.end());
    return true;
}

bool regras::adiconar_novo_multiplo_3(unsigned short int quantidade, loteria volante){
    if(quantidade > volante.veriticar_numeros_do_volante().back()){
        return false;
    }
    multiplos_3.push_back(quantidade);
    std::sort(multiplos_3.begin(), multiplos_3.end());
    return true;
}

bool regras::adiconar_novo_fibonacci(unsigned short int quantidade, loteria volante){
    if(quantidade > volante.veriticar_numeros_do_volante().back()){
        return false;
    }
    fibonacci.push_back(quantidade);
    std::sort(fibonacci.begin(), fibonacci.end());
    return true;
}

bool regras::adiconar_nova_dezena_repetida(unsigned short int quantidade, loteria volante){
    if(quantidade > volante.verificar_quantidade_numeros_jogados()){
        return false;
    }
    dezenas_repetidas.push_back(quantidade);
    std::sort(dezenas_repetidas.begin(), dezenas_repetidas.end());
    return true;
}