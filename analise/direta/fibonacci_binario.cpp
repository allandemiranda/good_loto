/**
 * @brief Programa para gerar analise em cima dos núemros de Fibonacci - Binário
 * 
 * @file fibonacci_binario.cpp
 * @author Allan de Miranda Silva
 * @date 2018-09-08
 */
#include <iostream>
#include <iterator>
#include <vector>
#include <cmath>
#include "../numeros_sorteados.h"

// ### REGRA FIBONACCI PARA BINÁRIO ###

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
        if((i+tamanho_amostra) > std::end(numeros_p_analise)){
            break;
        }
        int tamanho_analise = std::distance(std::begin(numeros_p_analise), std::end(numeros_p_analise));
        int binario[tamanho_analise];
        for(int j(0); j<tamanho_analise; ++j){
            binario[j] = 0;
        }
        int posicao (0);
        for(auto *j = std::begin(numeros_p_analise); j<std::end(numeros_p_analise); ++j){
            for(auto k(0); k<tamanho_amostra; ++k){
                if(*j == *(i+k)){
                    binario[posicao] = 1;
                }
            }
            ++posicao;
        }
        int tamanho_binario = std::distance(std::begin(binario), std::end(binario));
        int binario_final(0);
        for(int j(0); j<tamanho_binario; ++j){
            if(binario[j]==1){
                binario_final += std::pow(10, j);
            }
        }
        ocorencias.push_back(binario_final);    
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
        if(cont){
            std::cout << "Binário " << i << " saiu " << cont << " vezes." << std::endl;
        }        
    }
}