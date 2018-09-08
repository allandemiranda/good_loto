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
#include <algorithm>
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
    int tamanho_analise = std::distance(std::begin(numeros_p_analise), std::end(numeros_p_analise));

    std::vector <int> ocorencias; // Qunatidade de ocorrencias por jogo
    

    // Verificar as ocorrências
    int tamanho_amostra = atoi(argv[1]);
    for(auto *i = std::begin(numeros_sorteados); i<std::end(numeros_sorteados); i += tamanho_amostra){        
        if((i+tamanho_amostra) > std::end(numeros_p_analise)){
            break;
        }        
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
        int binario_final(0);
        for(int j(0); j<tamanho_analise; ++j){
            if(binario[j]==1){
                binario_final += std::pow(10, j);
            }
        }
        ocorencias.push_back(binario_final);    
    }   

    // Montar a tabela de análise
    std::sort(ocorencias.begin(), ocorencias.end());
    auto valor = ocorencias[0];
    int cont(0);    
    for(auto i(ocorencias.cbegin()); i < ocorencias.cend(); ++i){
        if(valor == *i){
            ++cont;
            if(i+1 == ocorencias.cend()){
                std::cout << "Binário " << valor << " saiu " << cont << " vezes." << std::endl;
                // std::cout <<  valor << ", " << std::endl;
                break;
            }
        } else {
             std::cout << "Binário " << valor << " saiu " << cont << " vezes." << std::endl;
             // std::cout <<  valor << ", " << std::endl;
             cont = 1;
             valor = *i;
        }
    }

    return 0;
}