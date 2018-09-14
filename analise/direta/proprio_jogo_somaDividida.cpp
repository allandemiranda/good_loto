/**
 * @brief Programa para verificar a soma da amostra e dividir pelo seu maior número
 * 
 * @file proprio_jogo_somaDividida.cpp
 * @author Allan de Miranda Silva
 * @date 13-09-2018
 */

// ### REGRA PARA SOMA / MAIOR DIVIDIDA ### Soma dos resultados que podem sair
// Para 1 jogos
// {6, 7, 8, 9}
// Para 2 jogos
// {3, 14, 15, 16, 17, 18}
// Para 3 jogos
// {20, 21, 22, 23, 24, 25, 26}
// Para 5 jogos
// {34, 35, 36, 37, 38, 39, 40, 41, 42}

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
    int tamanho_amostra = (atoi(argv[1]) * 15);

    // Fazer a soma
    for(auto *jogo = (std::end(numeros_sorteados) - 1), soma(0); jogo >= (std::begin(numeros_sorteados) + tamanho_amostra - 1) ; jogo -= 15, soma = 0){
        int maior = *jogo;
        for(auto i(0); i<tamanho_amostra; ++i){                
            soma += *(jogo - i);
            if(*(jogo-i)>maior){
                maior = *(jogo - i);
            }                
        }
        soma = soma / maior;        
        ocorrencias.push_back(soma);
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