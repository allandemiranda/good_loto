/**
 * @brief Programa para gerar analise em cima dos núemros Primos - Ocorências
 * 
 * @file primos_ocorrencias.cpp
 * @author Allan de Miranda Silva
 * @date 10-09-2018
 */
#include <iostream>
#include <iterator>
#include <vector>
#include "../numeros_sorteados.h"


// ### REGRA PARA OCORRÊNCIAS ###
// A cada 1 jogo, saem {3, 4, 5, 6, 7, 8} números multiplos
// A cada 2 jogo, saem {7, 8, 9, 10, 11, 12, 13, 14, 15} números multiplos
// A cada 3 jogo, saem {12, 13, 14, 15, 16, 17, 18, 19, 20, 21} números multiplos
// A cada 5 jogo, saem {23, 24, 25, 26, 27, 28, 29, 30, 31, 32} números multiplos

/**
 * @brief Main
 * 
 * @param argc  
 * @param argv recebe o número de jogos a analisar
 * @return int 
 */
int main(int argc, char *argv[ ]){
    int numeros_p_analise[] = {2,3,5,7,11,13,17,19,23}; // números da cartela

    std::vector <int> ocorrencias; // Qunatidade de ocorrencias por jogo

    // Verificar as ocorrências
    int tamanho_amostra = 15 * atoi(argv[1]);
    for(auto *i = std::begin(numeros_sorteados); i<std::end(numeros_sorteados); i += tamanho_amostra){        
        int cont(0);
        bool flag = true;
        for(int j(0); j<tamanho_amostra; ++j){
            for(auto *k = std::begin(numeros_p_analise); k<std::end(numeros_p_analise); ++k){
                if((i+j)>=std::end(numeros_sorteados)){
                    flag = false;
                    break;
                }
                if(*k == *(i+j)){
                    ++cont;
                }
            }
            if(!flag){
                break;
            }
        }
        if(flag){
            ocorrencias.push_back(cont);
        } else {
            break;
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
        std::cout << "Valor " << i << " saiu " << cont << " vezes." << std::endl;
    }
    std::cout << "---" << std::endl;
    for(auto i(menor_ocorrencia); i <= maior_ocorrencia; ++i){
        int cont(0);
        for(auto j = ocorrencias.cbegin(); j < ocorrencias.cend(); ++j){
            if(i == *j){
                ++cont;
            }
        }
        // Colocar regra aqui
        if(cont != 0){
            std::cout << i << ", ";
        }
    }
    std::cout << "---" << std::endl;

    return 0;
}