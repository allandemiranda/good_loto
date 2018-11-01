/**
 * @file regras.h
 * @author Allan de Miranda Silva
 * @brief 
 * @version 1.0
 * @date 2018-10-31
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#ifndef _REGRAS_H_
#define _REGRAS_H_

#include <algorithm>
#include <vector>
#include <array>
#include <string>
#include <fstream>
#include <stdexcept>

#include "loteria.h"

class regras
{
private:
    unsigned short int quantidade_de_regras_disponiveis = 7;
    std::vector <unsigned short int> soma; // Soma dos números sorteados
    std::vector <std::array<unsigned short int, 2>> pares_impares; // Pares e impares sorteados [2]
    std::vector <unsigned short int> sequencia; // Quantidade de números em sequencia
    std::vector <unsigned short int> primos; // Quantidade de números primos
    std::vector <unsigned short int> multiplos_3; // Quantidade de números múltiplos de 3
    std::vector <unsigned short int> fibonacci; // Quantidade de números de Fibonacci
    std::vector <unsigned short int> dezenas_repetidas; // Quantidade de dezenas repetidas do concurso anterior
    bool adicionar_regras(std::vector <unsigned short int>, loteria);
    std::vector <unsigned short int> gerador_de_regras(void);
public:
    regras(loteria, std::string);
    bool adiconar_nova_soma(unsigned short int, loteria);
    bool adiconar_novo_pares_impares(unsigned short int, unsigned short int, loteria); 
    bool adiconar_nova_sequencia(unsigned short int, loteria);
    bool adiconar_novo_primo(unsigned short int, loteria);
    bool adiconar_novo_multiplo_3(unsigned short int, loteria);
    bool adiconar_novo_fibonacci(unsigned short int, loteria);
    bool adiconar_nova_dezena_repetida(unsigned short int, loteria);    
};

regras::regras(loteria volante, std::string file_name = NULL){
    if(file_name.size() == 0){
        /// escrever aqui o gerador de regras altomático
    } else {
        std::vector <unsigned short int> vetor;
        std::string route = "../data/"; 
        route = route + file_name; 
        std::ifstream ifs(route); 
        if(!ifs.good()){
            throw std::runtime_error( "Erro ao ler arquivo de regras" );
        }
        unsigned long int valuer;
        while( ifs >> valuer ){
            vetor.push_back(valuer);
        }
        ifs.close();
        if(!regras::adicionar_regras(vetor, volante)){
            throw std::runtime_error( "Erro ao adicionar regras" );
        }
    }
}

bool regras::adicionar_regras(std::vector <unsigned short int> lista_regras, loteria volante){
    if(lista_regras.size()<=quantidade_de_regras_disponiveis){
        return false;
    }
    auto quantidade_num(lista_regras[0]);
    auto numero_da_regra(1);
    for(auto i(1); i<lista_regras.size(); ++i){
        if(quantidade_num!=0){
            bool indicador = false;
            if(numero_da_regra == 1){
                indicador = adiconar_nova_soma(lista_regras[i], volante);                
            }
            if(numero_da_regra == 2){
                if((i+1) == lista_regras.size()){
                    return false;
                }
                indicador = adiconar_novo_pares_impares(lista_regras[i], lista_regras[i+1], volante);
                --quantidade_num;
                ++i;                
            }
            if(numero_da_regra == 3){
                indicador = adiconar_nova_sequencia(lista_regras[i], volante);                
            }
            if(numero_da_regra == 4){
                indicador = adiconar_novo_primo(lista_regras[i], volante);                
            }
            if(numero_da_regra == 5){
                indicador = adiconar_novo_multiplo_3(lista_regras[i], volante);                
            }
            if(numero_da_regra == 6){
                indicador = adiconar_novo_fibonacci(lista_regras[i], volante);                
            }
            if(numero_da_regra == 7){
                indicador = adiconar_nova_dezena_repetida(lista_regras[i], volante);                
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
        soma_maxima += volante.veriticar_numeros_do_volante()[i];
    }
    if(soma_maxima<nova_soma){
        return false;
    }
    long long soma_minima = 0;
    #pragma omp parallel for reduction(+ : soma_minima)
    for(auto i = (volante.verificar_quantidade_numeros_do_volante()-1); i>=(volante.verificar_quantidade_numeros_do_volante()-volante.verificar_quantidade_numeros_sorteados()); --i){
        soma_minima += volante.veriticar_numeros_do_volante()[i];
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

#endif