/**
 * @brief Função de análise binária para as colunas em grupos
 * 
 * @file colunas_grupo_binario.cpp
 * @author Allan de Miranda Silva
 * @date 26-09-2018
 */

// ### REGRA PARA BINÁRIOS ###
// Para 1 jogos
// {1111, 10111, 11011, 11101, 11110, 11111}

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <cmath>
#include "../numeros_sorteados.h"
#include "../../functions/gerar_binario.h"

/**
 * @brief Main
 * 
 * @param argc  
 * @param argv recebe o número de jogos a analisar
 * @return int 
 */
int main(int argc, char *argv[ ]){
    // Números a analisar na cartela
    int numeros_para_analise[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
    int quantidade_de_numeros_analisar = std::distance(std::begin(numeros_para_analise), std::end(numeros_para_analise));

    // Teste de capacidade máxima
    //if(quantidade_de_numeros_analisar > 10){
        //std::cout << "TAMANHO MÁXIMO DE ANÁLISE ATINGIDO" << std::endl;
        //return 0;
    //}

    // Vetor com todas as ocorrências
    std::vector <int> ocorrencias;

    // Quantidade de jogos que será analisado
    int tamanho_amostra = (atoi(argv[1]) * 15);

    // Verificar as ocorrências
    for(auto *jogo = (std::end(numeros_sorteados) - 1); jogo >= (std::begin(numeros_sorteados) + tamanho_amostra - 1) ; jogo -= 15){
        // Inicializar binário
        int binario[quantidade_de_numeros_analisar];
        for(auto i(0); i<quantidade_de_numeros_analisar; ++i){
            binario[i] = 0;
        }
        // Analisar e preencher o binário
        for(auto i(0); i<quantidade_de_numeros_analisar; ++i){
            for(auto j(0); j<tamanho_amostra; ++j){
                if(numeros_para_analise[i] == *(jogo - j)){
                    binario[i] = 1;
                }
            }
        }
        // Gravar binário
        int binario_final(0);
        for(int i(0); i<(quantidade_de_numeros_analisar/5); ++i){            
            for(int j(0); j<5; ++j){
                if(binario[i+(j*5)] == 1){
                    binario_final += std::pow(10, i);
                    break;
                }
            }
        }
        ocorrencias.push_back(binario_final);
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
    int numerador(1);
    for(auto i(0); i<tamanho_resposta; ++i){
        std::cout << "[" << numerador++ << "] " << "Binário " << respostas_valor[i] << " saiu " << respostas_contador[i] << " vezes. " << "( " << (float) ((respostas_contador[i]*100)/maior_contador) << "% )"<< std::endl;
    }

    std::cout << "-----------------------------------" << std::endl;

    std::cout << "Quantidade máxima de binários possiveis: " << rebobinar(quantidade_de_numeros_analisar/5) << std::endl;

    std::cout << "-----------------------------------" << std::endl;

    // Imprimir como um vetor    
    for(auto i(0); i<(tamanho_resposta - 1); ++i){
        std::cout << respostas_valor[i] << ", ";
    }
    std::cout << respostas_valor[(tamanho_resposta - 1)] << std::endl; 

    std::cout << "-----------------------------------" << std::endl;   

    return 0;
}