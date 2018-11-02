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
#include <iostream>
#include <omp.h>

#include "../include/regras.h"

regras::regras(loteria volante, std::string file_name = ""){
    if(file_name.size() == 0){
        gerador_de_regras(volante);
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

void regras::gerador_de_regras(loteria modalidade){
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

void regras::analise_da_dezena_repetida(float delimitador, loteria modalidade){
    std::vector<unsigned short int> vetor_analise;
    // como compara com o anterior, se inicia no segundo jogo
    for(auto i=2; i<=modalidade.verificar_quantidade_jogos_totais_sorteados(); ++i){
        unsigned long int num_repetida = 0;
        #pragma omp parallel for reduction(+ : num_repetida)
        for(auto j=0; j<modalidade.verificar_quantidade_numeros_sorteados(); ++j){
            if(std::binary_search(modalidade.veriticar_jogo_sorteado(i-1).begin(),modalidade.veriticar_jogo_sorteado(i-1).end(),modalidade.veriticar_jogo_sorteado(i)[j])){
                #pragma omp critical
                {   
                    ++num_repetida;
                }
            }
        }
        vetor_analise.push_back(num_repetida);
    }    
    std::sort(vetor_analise.begin(), vetor_analise.end());
    struct analise{
        unsigned short int valor;
        unsigned long int quantidade;
        float porcentagem;
    };    
    auto menor_valor(vetor_analise.front());
    auto maior_valor(vetor_analise.back());
    auto distancia = maior_valor - menor_valor;
    analise nova_analise[distancia];
    for(unsigned short int i = menor_valor, posicao = 0; i<=maior_valor; ++i, ++posicao){
        unsigned long int soma = 0;
        #pragma omp parallel for reduction(+ : soma)
        for(auto j=0; j<vetor_analise.size(); ++j){
            if(vetor_analise[j] == i){
                #pragma omp critical
                {
                    ++soma;
                }
            }
        }
        nova_analise[posicao].valor = i;
        nova_analise[posicao].quantidade = soma;
    }
    auto maior_quantidade(0);
    for(auto i(0); i<distancia; ++i){
        if(nova_analise[i].quantidade > maior_quantidade){
            maior_quantidade = nova_analise[i].quantidade;
        }
    }
    for(auto i(0); i<distancia; ++i){
        nova_analise[i].porcentagem = (((nova_analise[i].quantidade)*100)/maior_quantidade);
    }
    std::cout << "Criando regra das Dezenas Repetidas" << std::endl;
    std::cout << "Valor   -    Quantidade    -    Incluido" << std::endl;
    for(auto i(0); i<distancia; ++i){
        std::cout << nova_analise[i].valor << "  ->  " << nova_analise[i].quantidade << "  ->  ";
        if(nova_analise[i].porcentagem > delimitador){
            std::cout << "SIM" << std::endl;
            if(!adiconar_nova_dezena_repetida(nova_analise[i].valor, modalidade)){
                throw std::runtime_error( "Erro ao adicionar regra das dezenas repetidas" );                
            }
        } else {
            std::cout << "NÃO" << std::endl;
        }
    }
    std::cout << "-------------------------------------------------------"  << std::endl;
}

void regras::analise_do_fibonacci(float delimitador, loteria modalidade){
    std::vector <unsigned short int> temp_numeros_fibonacci;    
    temp_numeros_fibonacci.push_back(0);
    temp_numeros_fibonacci.push_back(1);
    while(temp_numeros_fibonacci.back()<modalidade.veriticar_numeros_do_volante().back()){
        temp_numeros_fibonacci.push_back(*(temp_numeros_fibonacci.end()-2) + *(temp_numeros_fibonacci.end()-1));
    }
    std::vector <unsigned short int> numeros_fibonacci;
    for(auto i : modalidade.veriticar_numeros_do_volante()){
        if(std::binary_search(temp_numeros_fibonacci.begin(), temp_numeros_fibonacci.end(), i)){
            numeros_fibonacci.push_back(i);
        }
    }
    std::vector<unsigned short int> vetor_analise;
    for(auto i=1; i<=modalidade.verificar_quantidade_jogos_totais_sorteados(); ++i){
        unsigned long int num_fi = 0;
        #pragma omp parallel for reduction(+ : num_fi)
        for(auto j=0; j<numeros_fibonacci.size(); ++j){
            if(std::binary_search(modalidade.veriticar_jogo_sorteado(i).begin(),modalidade.veriticar_jogo_sorteado(i).end(), numeros_fibonacci[j])){
                #pragma omp critical
                {
                    ++num_fi;
                }
            }
        }
        vetor_analise.push_back(num_fi);
    }    
    std::sort(vetor_analise.begin(), vetor_analise.end());
    struct analise{
        unsigned short int valor;
        unsigned long int quantidade;
        float porcentagem;
    };    
    auto menor_valor(vetor_analise.front());
    auto maior_valor(vetor_analise.back());
    auto distancia = maior_valor - menor_valor;
    analise nova_analise[distancia];
    for(unsigned short int i = menor_valor, posicao = 0; i<=maior_valor; ++i, ++posicao){
        unsigned long int soma = 0;
        #pragma omp parallel for reduction(+ : soma)
        for(auto j=0; j<vetor_analise.size(); ++j){
            if(vetor_analise[j] == i){
                #pragma omp critical
                {
                    ++soma;
                }
            }
        }
        nova_analise[posicao].valor = i;
        nova_analise[posicao].quantidade = soma;
    }
    auto maior_quantidade(0);
    for(auto i(0); i<distancia; ++i){
        if(nova_analise[i].quantidade > maior_quantidade){
            maior_quantidade = nova_analise[i].quantidade;
        }
    }
    for(auto i(0); i<distancia; ++i){
        nova_analise[i].porcentagem = (((nova_analise[i].quantidade)*100)/maior_quantidade);
    }    
    std::cout << "Criando regra dos Fibonacci" << std::endl;
    std::cout << "Valor   -    Quantidade    -    Incluido" << std::endl;
    for(auto i(0); i<distancia; ++i){
        std::cout << nova_analise[i].valor << "  ->  " << nova_analise[i].quantidade << "  ->  ";
        if(nova_analise[i].porcentagem > delimitador){
            std::cout << "SIM" << std::endl;
            if(!adiconar_novo_fibonacci(nova_analise[i].valor, modalidade)){
                throw std::runtime_error( "Erro ao adicionar regra dos números Fibonacci" );
            }
        } else {
            std::cout << "NÃO" << std::endl;
        }
    }
    std::cout << "-------------------------------------------------------"  << std::endl;
}

void regras::analise_do_multiplo_3(float delimitador, loteria modalidade){
    std::vector <unsigned short int> numeros_multiplos_3;
    for(auto i : modalidade.veriticar_numeros_do_volante()){
        if((i%3)==0){
            numeros_multiplos_3.push_back(i);
        }
    }

    std::vector<unsigned short int> vetor_analise;
    for(auto i=1; i<=modalidade.verificar_quantidade_jogos_totais_sorteados(); ++i){
        unsigned long int num_m_3 = 0;
        #pragma omp parallel for reduction(+ : num_m_3)
        for(auto j=0; j<numeros_multiplos_3.size(); ++j){
            if(std::binary_search(modalidade.veriticar_jogo_sorteado(i).begin(),modalidade.veriticar_jogo_sorteado(i).end(), numeros_multiplos_3[j])){
                #pragma omp critical
                {
                    ++num_m_3;
                }
            }
        }
        vetor_analise.push_back(num_m_3);
    }    
    std::sort(vetor_analise.begin(), vetor_analise.end());
    struct analise{
        unsigned short int valor;
        unsigned long int quantidade;
        float porcentagem;
    };    
    auto menor_valor(vetor_analise.front());
    auto maior_valor(vetor_analise.back());
    auto distancia = maior_valor - menor_valor;
    analise nova_analise[distancia];
    for(unsigned short int i = menor_valor, posicao = 0; i<=maior_valor; ++i, ++posicao){
        unsigned long int soma = 0;
        #pragma omp parallel for reduction(+ : soma)
        for(auto j=0; j<vetor_analise.size(); ++j){
            if(vetor_analise[j] == i){
                #pragma omp critical
                {
                    ++soma;
                }
            }
        }
        nova_analise[posicao].valor = i;
        nova_analise[posicao].quantidade = soma;
    }
    auto maior_quantidade(0);
    for(auto i(0); i<distancia; ++i){
        if(nova_analise[i].quantidade > maior_quantidade){
            maior_quantidade = nova_analise[i].quantidade;
        }
    }
    for(auto i(0); i<distancia; ++i){
        nova_analise[i].porcentagem = (((nova_analise[i].quantidade)*100)/maior_quantidade);
    }    
    std::cout << "Criando regra dos Múltiplos de 3" << std::endl;
    std::cout << "Valor   -    Quantidade    -    Incluido" << std::endl;
    for(auto i(0); i<distancia; ++i){
        std::cout << nova_analise[i].valor << "  ->  " << nova_analise[i].quantidade << "  ->  ";
        if(nova_analise[i].porcentagem > delimitador){
            std::cout << "SIM" << std::endl;
            if(!adiconar_novo_multiplo_3(nova_analise[i].valor, modalidade)){
                throw std::runtime_error( "Erro ao adicionar regra dos números múltiplos de 3" );
            }
        } else {
            std::cout << "NÃO" << std::endl;
        }
    }
    std::cout << "-------------------------------------------------------"  << std::endl;
}

void regras::analise_do_primo(float delimitador, loteria modalidade){
    std::vector <unsigned short int> numeros_primos;
    for(auto i : modalidade.veriticar_numeros_do_volante){
        if(i == 1){
            continue;
        }
        bool existe_divisor = false;
        #pragma omp parallel for
        for(auto j(2); j<i; ++j){
            if((i%j)==0){
                existe_divisor = true;
                #pragma omp cancel for 
            }
        }
        if(!existe_divisor){
            numeros_primos.push_back(i);
        }
    }

    std::vector<unsigned short int> vetor_analise;
    for(auto i=1; i<=modalidade.verificar_quantidade_jogos_totais_sorteados(); ++i){
        unsigned long int num_primos = 0;
        #pragma omp parallel for reduction(+ : num_primos)
        for(auto j=0; j<numeros_primos.size(); ++j){
            if(std::binary_search(modalidade.veriticar_jogo_sorteado(i).begin(),modalidade.veriticar_jogo_sorteado(i).end(), numeros_primos[j])){
                #pragma omp critical
                {
                    ++num_primos;
                }
            }
        }
        vetor_analise.push_back(num_primos);
    }    
    std::sort(vetor_analise.begin(), vetor_analise.end());
    struct analise{
        unsigned short int valor;
        unsigned long int quantidade;
        float porcentagem;
    };    
    auto menor_valor(vetor_analise.front());
    auto maior_valor(vetor_analise.back());
    auto distancia = maior_valor - menor_valor;
    analise nova_analise[distancia];
    for(unsigned short int i = menor_valor, posicao = 0; i<=maior_valor; ++i, ++posicao){
        unsigned long int soma = 0;
        #pragma omp parallel for reduction(+ : soma)
        for(auto j=0; j<vetor_analise.size(); ++j){
            if(vetor_analise[j] == i){
                #pragma omp critical
                {
                    ++soma;
                }
            }
        }
        nova_analise[posicao].valor = i;
        nova_analise[posicao].quantidade = soma;
    }
    auto maior_quantidade(0);
    for(auto i(0); i<distancia; ++i){
        if(nova_analise[i].quantidade > maior_quantidade){
            maior_quantidade = nova_analise[i].quantidade;
        }
    }
    for(auto i(0); i<distancia; ++i){
        nova_analise[i].porcentagem = (((nova_analise[i].quantidade)*100)/maior_quantidade);
    }    
    std::cout << "Criando regra dos Números Primos" << std::endl;
    std::cout << "Valor   -    Quantidade    -    Incluido" << std::endl;
    for(auto i(0); i<distancia; ++i){
        std::cout << nova_analise[i].valor << "  ->  " << nova_analise[i].quantidade << "  ->  ";
        if(nova_analise[i].porcentagem > delimitador){
            std::cout << "SIM" << std::endl;
            if(!adiconar_novo_primo(nova_analise[i].valor, modalidade)){
                throw std::runtime_error( "Erro ao adicionar regra dos números primos" );
            }
        } else {
            std::cout << "NÃO" << std::endl;
        }
    }
    std::cout << "-------------------------------------------------------"  << std::endl;
}

void regras::analise_da_sequencia(float delimitador, loteria modalidade){
    std::vector<unsigned short int> vetor_analise;
    for(auto i=1; i<=modalidade.verificar_quantidade_jogos_totais_sorteados(); ++i){
        unsigned short int maior_quant_sequencia(0);
        unsigned short int sequencia_atual_now(0);
        bool esta_na_sequencia(false);
        for(auto j(1); j<modalidade.verificar_quantidade_numeros_sorteados(); ++j){
            if(!esta_na_sequencia){
                std::vector <unsigned short int> temp = modalidade.veriticar_numeros_do_volante();
                auto posicao_um(0);                
                #pragma omp parallel for
                for(auto k(0); k<modalidade.veriticar_numeros_do_volante().size(); ++k){
                    if(modalidade.veriticar_jogo_sorteado(i)[j-1] == temp[k]){
                        posicao_um = k;                        
                        #pragma omp cancel for 
                    }                    
                }
                auto posicao_dois(0);
                #pragma omp parallel for
                for(auto k(0); k<modalidade.veriticar_numeros_do_volante().size(); ++k){
                    if(modalidade.veriticar_jogo_sorteado(i)[j-1] == temp[k]){
                        posicao_dois = k;                        
                        #pragma omp cancel for 
                    }                    
                }
                if((posicao_um+1)==posicao_dois){
                    esta_na_sequencia = true;
                    ++sequencia_atual_now;
                    continue;
                } else {
                    continue;
                }
            } else {
                std::vector <unsigned short int> temp = modalidade.veriticar_numeros_do_volante();
                auto posicao_um(0);                
                #pragma omp parallel for
                for(auto k(0); k<modalidade.veriticar_numeros_do_volante().size(); ++k){
                    if(modalidade.veriticar_jogo_sorteado(i)[j-1] == temp[k]){
                        posicao_um = k;                        
                        #pragma omp cancel for 
                    }                    
                }
                auto posicao_dois(0);
                #pragma omp parallel for
                for(auto k(0); k<modalidade.veriticar_numeros_do_volante().size(); ++k){
                    if(modalidade.veriticar_jogo_sorteado(i)[j-1] == temp[k]){
                        posicao_dois = k;                        
                        #pragma omp cancel for 
                    }                    
                }
                if((posicao_um+1)==posicao_dois){                    
                    ++sequencia_atual_now;
                    continue;
                } else {
                    esta_na_sequencia = false;
                    if(maior_quant_sequencia<sequencia_atual_now){
                        maior_quant_sequencia = sequencia_atual_now;
                        sequencia_atual_now = 0;
                    } else {
                        sequencia_atual_now = 0;
                    }
                    continue;
                }
            }
        }
        if((esta_na_sequencia) and (maior_quant_sequencia<sequencia_atual_now)){            
            maior_quant_sequencia = sequencia_atual_now;            
        }
        vetor_analise.push_back(maior_quant_sequencia);
    }
    std::sort(vetor_analise.begin(), vetor_analise.end());
    struct analise{
        unsigned short int valor;
        unsigned long int quantidade;
        float porcentagem;
    };    
    auto menor_valor(vetor_analise.front());
    auto maior_valor(vetor_analise.back());
    auto distancia = maior_valor - menor_valor;
    analise nova_analise[distancia];
    for(unsigned short int i = menor_valor, posicao = 0; i<=maior_valor; ++i, ++posicao){
        unsigned long int soma = 0;
        #pragma omp parallel for reduction(+ : soma)
        for(auto j=0; j<vetor_analise.size(); ++j){
            if(vetor_analise[j] == i){
                #pragma omp critical
                {
                    ++soma;
                }
            }
        }
        nova_analise[posicao].valor = i;
        nova_analise[posicao].quantidade = soma;
    }
    auto maior_quantidade(0);
    for(auto i(0); i<distancia; ++i){
        if(nova_analise[i].quantidade > maior_quantidade){
            maior_quantidade = nova_analise[i].quantidade;
        }
    }
    for(auto i(0); i<distancia; ++i){
        nova_analise[i].porcentagem = (((nova_analise[i].quantidade)*100)/maior_quantidade);
    }    
    std::cout << "Criando regra dos Números em Sequência" << std::endl;
    std::cout << "Valor   -    Quantidade    -    Incluido" << std::endl;
    for(auto i(0); i<distancia; ++i){
        std::cout << nova_analise[i].valor << "  ->  " << nova_analise[i].quantidade << "  ->  ";
        if(nova_analise[i].porcentagem > delimitador){
            std::cout << "SIM" << std::endl;
            if(!adiconar_nova_sequencia(nova_analise[i].valor, modalidade)){
                throw std::runtime_error( "Erro ao adicionar regra da números em sequência" );
            }
        } else {
            std::cout << "NÃO" << std::endl;
        }
    }
    std::cout << "-------------------------------------------------------"  << std::endl;
}

void regras::analise_do_pares_impares(float delimitador, loteria modalidade){
    std::vector<unsigned short int> vetor_analise;
    for(auto i=1; i<=modalidade.verificar_quantidade_jogos_totais_sorteados(); ++i){
        unsigned long int num_primos = 0;
        #pragma omp parallel for reduction(+ : num_primos)
        for(auto j=0; j<modalidade.verificar_quantidade_numeros_sorteados(); ++j){
            if((modalidade.veriticar_jogo_sorteado(i)[j]%2)==0){
                #pragma omp critical
                {
                    ++num_primos;
                }
            }
        }
        vetor_analise.push_back(num_primos);
    }
    std::sort(vetor_analise.begin(), vetor_analise.end());
    struct analise{
        unsigned short int valor;
        unsigned short int valor_impar;
        unsigned long int quantidade;
        float porcentagem;
    };    
    auto menor_valor(vetor_analise.front());
    auto maior_valor(vetor_analise.back());
    auto distancia = maior_valor - menor_valor;
    analise nova_analise[distancia];
    for(unsigned short int i = menor_valor, posicao = 0; i<=maior_valor; ++i, ++posicao){
        unsigned long int soma = 0;
        #pragma omp parallel for reduction(+ : soma)
        for(auto j=0; j<vetor_analise.size(); ++j){
            if(vetor_analise[j] == i){
                #pragma omp critical
                {
                    ++soma;
                }
            }
        }
        nova_analise[posicao].valor = i;
        nova_analise[posicao].valor_impar = modalidade.verificar_quantidade_numeros_sorteados() - i;
        nova_analise[posicao].quantidade = soma;
    }
    auto maior_quantidade(0);
    for(auto i(0); i<distancia; ++i){
        if(nova_analise[i].quantidade > maior_quantidade){
            maior_quantidade = nova_analise[i].quantidade;
        }
    }
    for(auto i(0); i<distancia; ++i){
        nova_analise[i].porcentagem = (((nova_analise[i].quantidade)*100)/maior_quantidade);
    }    
    std::cout << "Criando regra dos Números Pares e Impares" << std::endl;
    std::cout << "Valor Par - Valor Impar    -    Quantidade    -    Incluido" << std::endl;
    for(auto i(0); i<distancia; ++i){
        std::cout << nova_analise[i].valor << "  ->  " << nova_analise[i].valor_impar << "  ->  " << nova_analise[i].quantidade << "  ->  ";
        if(nova_analise[i].porcentagem > delimitador){
            std::cout << "SIM" << std::endl;
            if(!adiconar_novo_pares_impares(nova_analise[i].valor, nova_analise[i].valor_impar, modalidade)){
                throw std::runtime_error( "Erro ao adicionar regra da pares e impares" );
            }
        } else {
            std::cout << "NÃO" << std::endl;
        }
    }
    std::cout << "-------------------------------------------------------"  << std::endl;
}

void regras::analise_da_soma(float delimitador, loteria modalidade){
    std::vector <unsigned long int> vetor_analise;
    for(auto i=1; i<=modalidade.verificar_quantidade_jogos_totais_sorteados(); ++i){
        unsigned long int soma = 0;
        #pragma omp parallel for reduction(+ : soma)
        for(auto j=0; j<modalidade.verificar_quantidade_numeros_sorteados(); ++j){
            #pragma omp critical
            {
                soma += modalidade.veriticar_jogo_sorteado(i)[j];
            }
        }
        vetor_analise.push_back(soma);
    }
    std::sort(vetor_analise.begin(), vetor_analise.end());
    struct analise{
        unsigned long int valor;
        unsigned long int quantidade;
        float porcentagem;
    };    
    auto menor_valor(vetor_analise.front());
    auto maior_valor(vetor_analise.back());
    auto distancia = maior_valor - menor_valor;
    analise nova_analise[distancia];
    for(unsigned long int i = menor_valor, posicao = 0; i<=maior_valor; ++i, ++posicao){
        unsigned long int soma = 0;
        #pragma omp parallel for reduction(+ : soma)
        for(auto j=0; j<vetor_analise.size(); ++j){
            if(vetor_analise[j] == i){
                #pragma omp critical
                {
                    ++soma;
                }
            }
        }
        nova_analise[posicao].valor = i;
        nova_analise[posicao].quantidade = soma;
    }
    auto maior_quantidade(0);
    for(auto i(0); i<distancia; ++i){
        if(nova_analise[i].quantidade > maior_quantidade){
            maior_quantidade = nova_analise[i].quantidade;
        }
    }
    for(auto i(0); i<distancia; ++i){
        nova_analise[i].porcentagem = (((nova_analise[i].quantidade)*100)/maior_quantidade);
    }    
    std::cout << "Criando regra da Soma" << std::endl;
    std::cout << "Valor   -    Quantidade    -    Incluido" << std::endl;
    for(auto i(0); i<distancia; ++i){
        std::cout << nova_analise[i].valor << "  ->  " << nova_analise[i].quantidade << "  ->  ";
        if(nova_analise[i].porcentagem > delimitador){
            std::cout << "SIM" << std::endl;
            if(!adiconar_nova_soma(nova_analise[i].valor, modalidade)){
                throw std::runtime_error( "Erro ao adicionar regra da soma" );
            }
        } else {
            std::cout << "NÃO" << std::endl;
        }
    }
    std::cout << "-------------------------------------------------------"  << std::endl;
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

bool regras::adiconar_nova_soma(unsigned long int nova_soma, loteria volante){
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

std::vector <unsigned long int> regras::v_analisar_soma(void){
    return soma;
}

std::vector <std::array<unsigned short int, 2>> regras::v_analisar_pares_impares(void){
    return pares_impares;
}

std::vector <unsigned short int> regras::v_analisar_sequencia(void){
    return sequencia;
}

std::vector <unsigned short int> regras::v_analisar_primos(void){
    return primos;
}

std::vector <unsigned short int> regras::v_analisar_multiplos_3(void){
    return multiplos_3;
}

std::vector <unsigned short int> regras::v_analisar_fibonacci(void){
    return fibonacci;
}

std::vector <unsigned short int> regras::v_analisar_dezenas_repetidas(void){
    return dezenas_repetidas;
}