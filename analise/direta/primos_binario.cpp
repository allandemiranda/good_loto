/**
 * @brief Programa para gerar analise em cima dos núemros de Primos - Binário
 * 
 * @file primos_binario.cpp
 * @author Allan de Miranda Silva
 * @date 10-09-2018
 */
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <cmath>
#include "../numeros_sorteados.h"

// ### REGRA PARA BINÁRIO ###
// Com 1 jogos, existem somente 416 padrões
// Com 8 jogos ou mais, todos os números são sorteados

/**
 * @brief Main
 * 
 * @param argc  
 * @param argv recebe o número de jogos a analisar
 * @return int 
 */
int main(int argc, char *argv[ ]){
    int numeros_p_analise[] = {2,3,5,7,11,13,17,19,23}; // números da cartela
    int tamanho_analise = std::distance(std::begin(numeros_p_analise), std::end(numeros_p_analise));

    std::vector <int> ocorrencias; // Quantidade de ocorrencias por jogo
    

    // Verificar as ocorrências
    int tamanho_amostra = 15 * atoi(argv[1]);
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
        ocorrencias.push_back(binario_final);    
    }   

    // Montar a tabela de análise
    std::sort(ocorrencias.begin(), ocorrencias.end());
    auto valor = ocorrencias[0];
    int cont(0);
    int quantidade(0);   
    for(auto i(ocorrencias.cbegin()); i < ocorrencias.cend(); ++i){
        if(valor == *i){
            ++cont;
            if(i+1 == ocorrencias.cend()){
                std::cout << "(" << ++quantidade << ") Binário " << valor << " saiu " << cont << " vezes." << std::endl;
                break;
            }
        } else {
            std::cout << "(" << ++quantidade << ") Binário " << valor << " saiu " << cont << " vezes." << std::endl;
            cont = 1;
            valor = *i;
        }
    }
    std::cout << std::endl;
    std::cout << "-----" << std::endl;
    std::cout << std::endl;
    valor = ocorrencias[0];
    cont = 0;
    quantidade = 0; 
    for(auto i(ocorrencias.cbegin()); i < ocorrencias.cend(); ++i){
        if(valor == *i){
            ++cont;
            if(i+1 == ocorrencias.cend()){                
                std::cout <<  valor << ", ";
                break;
            }
        } else {            
            std::cout <<  valor << ", ";
            cont = 1;
            valor = *i;
        }
    }
    std::cout << std::endl;

    return 0;
}