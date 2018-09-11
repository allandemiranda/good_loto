/**
 * @brief Programa para gerar analise em cima dos núemros Multiplos de 5 - Soma
 * 
 * @file multiplos_5_soma.cpp
 * @author Allan de Miranda Silva
 * @date 10-09-2018
 */
#include <iostream>
#include <iterator>
#include <vector>
#include "../numeros_sorteados.h"


// ### REGRA PARA SOMA ###
// A cada 1 jogo, a soma dos números mulltiplos de 5 que sairão será
// {5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75}
// A cada 2 jogo, a soma dos números mulltiplos de 5 que sairão será
// {20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100, 105, 110, 115, 120, 125, 130, 135, 140, 145, 150}

/**
 * @brief Main
 * 
 * @param argc  
 * @param argv recebe o número de jogos a analisar
 * @return int 
 */
int main(int argc, char *argv[ ]){
    int numeros_p_analise[] = {5,10,15,20,25}; // números da cartela

    std::vector <int> ocorrencias; // Qunatidade de ocorrencias por jogo

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
            ocorrencias.push_back(soma);
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
        std::cout << "Soma " << i << " saiu " << cont << " vezes." << std::endl;
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