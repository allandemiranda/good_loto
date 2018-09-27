/**
 * @brief Programa para gerar analise em cima dos jogos sorteados - todas as ocorrências anteriores
 * 
 * @file proprio_jogo_anterior_todos.cpp
 * @author Allan de Miranda Silva
 * @date 26-09-2018
 */

// ### REGRA PARA OCORRÊNCIAS ### Saem ... vezes no ... jogo anterios
// Para 1 jogos
// {5, 6, 7, 8, 9, 10, 11, 12, 13, 14}

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include "../numeros_sorteados.h"

/**
 * @brief Main
 * 
 * @param argc  
 * @param argv recebe o número de jogos a analisar
 * @return int 
 */
int main(int argc, char *argv[ ]){

    // Vetor com todas as ocorrências
    std::vector <int> ocorrencias;

    // Quantidade de jogos que será analisado
    //int tamanho_amostra = (atoi(argv[1]) * 15); // FIXO --> 15 números ou 1 jogo

    // Verificar as ocorrências
    for(auto *jogo = (std::begin(numeros_sorteados)); jogo<std::end(numeros_sorteados); jogo+=15){
        for(auto *comparacao = std::begin(numeros_sorteados); comparacao<jogo; comparacao+=15){
            int soma(0);
            for(int i(0); i<15; ++i){
                for(int j(0); j<15; ++j){
                    if(*(jogo+i)==*(comparacao+j)){
                        ++soma;
                    }
                }
            }
            ocorrencias.push_back(soma);
        }
    }
    

    // Ordenar ocorrências
    std::sort(ocorrencias.begin(), ocorrencias.end());

    // Contar respostas
    std::vector <int> respostas_valor;
    std::vector <int> respostas_contador;
    auto valor = ocorrencias[0];
    int contador(0);
    for(auto i = ocorrencias.begin(); i<ocorrencias.end(); ++i){      
        if(*i == valor){            
            if((ocorrencias.end()-1) == i){
                ++contador;
                respostas_valor.push_back(valor);
                respostas_contador.push_back(contador);
            } else {
                ++contador;
            }
        } else {
            respostas_valor.push_back(valor);
            respostas_contador.push_back(contador);
            valor = *i;
            contador = 1; 
        }
    }

    // Maior contador para calcular porcentagm
    int maior_contador = respostas_contador[0];
    for(int i : respostas_contador){
        if(i>maior_contador){
            maior_contador = i;
        }
    }

    // Imprimir como uma lista
    auto tamanho_resposta = respostas_valor.size();
    for(auto i = respostas_valor[0]; i <= respostas_valor[tamanho_resposta-1]; ++i){
        bool flag(true);
        for(auto j(0); j<tamanho_resposta; ++j){
            if(i == respostas_valor[j]){
                std::cout << "Soma " << i << " saiu " << respostas_contador[j] << " vezes. " << "( " << (float) ((respostas_contador[j]*100)/maior_contador) << "% )"<< std::endl;
                flag = false;
                break;
            }
        }
        if(flag){
            std::cout << "Soma " << i << " saiu " << 0 << " vezes." << std::endl;
        }
    }

    std::cout << "-----------------------------------" << std::endl;

    // Imprimir como um vetor    
    for(auto i(0); i<(tamanho_resposta - 1); ++i){
        std::cout << respostas_valor[i] << ", ";
    }
    std::cout << respostas_valor[(tamanho_resposta - 1)] << std::endl; 

    std::cout << "-----------------------------------" << std::endl;   

    return 0;
}