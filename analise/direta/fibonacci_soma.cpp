/**
 * @brief Programa para gerar analise em cima dos núemros de Fibonacci - Soma
 * 
 * @file fibonacci_soma.cpp
 * @author Allan de Miranda Silva
 * @date 2018-09-07
 */
#include <iostream>
#include <iterator>
#include <vector>
#include "../numeros_sorteados.h"


// ### REGRA FIBONACCI PARA SOMA ###
// A cada 2 números a soma dos números fibonacci que sairão nunca será 12, 17, 19, 20, 25, 27, 28, 30, 31, 32, 33 ou maiores que 34
// A cada 3 números a soma dos números fibonacci que sairão nunca será 33, 38, 40, 41 ou maiores que 42
// A cada 5 números a soma dos números fibonacci que sairão nunca será 33, 38, 40, 41 ou maiores que 42
// A cada 8 números a soma dos números fibonacci que sairão nunca será 33, 40, 41, 45, 46 ou maiores que 47
// A cada 13 números a soma dos números fibonacci que sairão nunca será 0, 51 ou maiores que 52
// A cada 15 números a soma dos números fibonacci que sairão nunca será 0, 1, 2, 4, 5, 7, 12 ou maiores que 53
// A cada 21 números a soma dos números fibonacci que sairão nunca será menores que 13, 15, 17, 18, 23, 69, 70, 72 ou amiores que 74


/**
 * @brief Main
 * 
 * @param argc  
 * @param argv recebe o número de jogos a analisar
 * @return int 
 */
int main(int argc, char *argv[ ]){
    int numeros_p_analise[] = {1,2,3,5,8,13,21}; // números Fibonacci da cartela

    std::vector <int> ocorencias; // Qunatidade de ocorrencias por jogo

    // Verificar as ocorrências
    int tamanho_amostra = 15 * atoi(argv[1]);
    for(auto *i = std::begin(numeros_sorteados); i<std::end(numeros_sorteados); i += tamanho_amostra){        
        int soma(0);
        bool flag = true;
        for(int j(0); j<tamanho_amostra; ++j){
            for(auto *k = std::begin(numeros_p_analise); k<std::end(numeros_p_analise); ++k){
                if((i+j)>=std::end(numeros_sorteados)){
                    flag = false;
                    break;
                }
                if(*k == *(i+j)){
                    soma += *k;
                }
            }
            if(!flag){
                break;
            }
        }
        if(flag){
            ocorencias.push_back(soma);
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
        std::cout << "Soma " << i << " saiu " << cont << " vezes." << std::endl;
    }

    return 0;
}