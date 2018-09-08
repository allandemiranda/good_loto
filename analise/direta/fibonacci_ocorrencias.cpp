/**
 * @brief Programa para gerar analise em cima dos núemros de Fibonacci - Ocorrências
 * 
 * @file fibonacci_ocorrencias.cpp
 * @author Allan de Miranda Silva
 * @date 2018-09-07
 */
#include <iostream>
#include <iterator>
#include <vector>
#include "../numeros_sorteados.h"


// ### REGRA FIBONACCI PARA OCORRÊNCIAS ###
// A cada 5 números sorteados saem 0, 1, 2, 3 ou 4 números fibonacci
// A cada 8 números sorteados saem 0, 1, 2, 3, 4 e 5 números fibonacci
// A cada 13 números sorteados saem 1, 2, 3, 4, 5, 6 ou 7 números fibonacci
// A cada 15 números sorteados saem 2, 3, 4, 5, 6 ou 7 números fibonacci **
// A cada 21 números sorteados saem 3, 4, 5, 6, 7, 8 ou 9 números fibonacci
// A cada 34 números sorteados saem 6, 7, 8, 9, 10, 11, 12, 13 ou 14 números fibonacci
// A cada 55 números sorteados saem 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 ou 21 números fibonacci ***
// A cada 89 números sorteados saem 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30 ou 31 números fibonacci
// A cada 144 números sorteados saem 34, 35, 36, 37, 38, 39 ou 40 números fibonacci
// A cada 233 números sorteados saem 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71 ou 72 números fibonacci


/**
 * @brief Main
 * 
 * @param argc  
 * @param argv recebe o número do tamanho da amostra
 * @return int 
 */
int main(int argc, char *argv[ ]){
    int numeros_p_analise[] = {1,2,3,5,8,13,21}; // números Fibonacci da cartela

    std::vector <int> ocorencias; // Qunatidade de ocorrencias por jogo

    // Verificar as ocorrências
    int tamanho_amostra = atoi(argv[1]);
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
            ocorencias.push_back(cont);
        } else {
            break;
        }        
    }

    // Verificar qual a maior e menor ocorrência para montar tabela
    auto maior_ocorrencia = ocorencias[0];
    auto menor_ocorrencia = ocorencias[0];
    for(auto i = ocorencias.cbegin(); i < ocorencias.cend(); ++i){
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
        for(auto j = ocorencias.cbegin(); j < ocorencias.cend(); ++j){
            if(i == *j){
                ++cont;
            }
        }
        std::cout << "Valor " << i << " saiu " << cont << " vezes." << std::endl;
    }
}