/**
 * @brief Programa para gerar analise em cima dos núemros de Fibonacci - Ciclo
 * 
 * @file fibonacci_ciclo.cpp
 * @author Allan de Miranda Silva
 * @date 08-09-2018
 */
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <cmath>
#include "../numeros_sorteados.h"

// ### REGRA FIBONACCI PARA CICLO ###
// y y F 1 2 3 "4" F 1 2 3 4 "5" F .....
// Menor ciclo 0 (números seguidos)
// Maior ciclo 20 (passou 20 números sem sair)


int main(void){
    int numeros_p_analise[] = {1,2,3,5,8,13,21}; // números Fibonacci da cartela

    std::vector <int> ocorrencias; // Qunatidade de ocorrencias por jogo

    // Verificar ciclos    
    for(auto *i = std::begin(numeros_sorteados); i<std::end(numeros_sorteados); ++i){
        for(int *j = std::begin(numeros_p_analise); j<std::end(numeros_p_analise); ++j){
            if(*j == *i){
                int ciclo(0);
                for(auto *k = i + 1; k<std::end(numeros_sorteados); ++k){
                    bool flag = false;
                    for(int *m = std::begin(numeros_p_analise); m<std::end(numeros_p_analise); ++m){
                        if(*k == *m){
                            ocorrencias.push_back(ciclo);
                            flag = true;
                            break;
                        }
                    }
                    if(flag){
                        ciclo = 0;
                    } else {
                        ++ciclo;
                    }
                }
                break;
            }
        }
    }

    // Verificar qual a maior e menor ocorrência para montar tabela
    auto maior_ocorrencia = ocorrencias[0];
    auto menor_ocorrencia = ocorrencias[0];
    for(auto i = ocorrencias.cbegin(); i < ocorrencias.cend(); ++i){
        if(*i > maior_ocorrencia){
            maior_ocorrencia = *i;
        }
        if(*i < menor_ocorrencia){
            menor_ocorrencia = *i;
        }
    }

    // Montar a tabela de análise
    for(auto i(menor_ocorrencia); i <= maior_ocorrencia; ++i){
        int cont(0);
        for(auto j = ocorrencias.cbegin(); j < ocorrencias.cend(); ++j){
            if(i == *j){
                ++cont;
            }
        }
        std::cout << "Ciclo " << i << " saiu " << cont << " vezes." << std::endl;
    }

    return 0;
}