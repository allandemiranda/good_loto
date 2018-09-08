/**
 * @brief Programa para gerar analise em cima dos núemros de Fibonacci
 * 
 * @file fibonacci_ocorrencias_individual.cpp
 * @author Allan de Miranda Silva
 * @date 2018-09-07
 */
#include <iostream>
#include <iterator>
#include <vector>
#include "../numeros_sorteados.h"


// ### REGRA FIBONACCI PARA OCORRÊNCIAS ###
// Sempre sairão 2, 3, 4, 5 ou 6 números Fibonacci em um jogo


int main(void){
    int fibonacci_numeros[7] = {1,2,3,5,8,13,21}; // números Fibonacci da cartela

    std::vector <int> ocorencias; // Qunatidade de ocorrencias por jogo

    // Verificar as ocorrências
    for(auto *i = std::begin(numeros_sorteados); i<std::end(numeros_sorteados); i += 15){
        int cont(0);
        for(int j(0); j<15; ++j){
            for(auto *k = std::begin(fibonacci_numeros); k<std::end(fibonacci_numeros); ++k){
                if(*k == *(i+j)){
                    ++cont;
                    break;
                }
            }
        }
        ocorencias.push_back(cont);
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