/**
 * @brief Programa para gerar analise em cima dos núemros Multiplos de 3 - Soma
 * 
 * @file multiplos_3_soma.cpp
 * @author Allan de Miranda Silva
 * @date 09-09-2018  
  */

// ### REGRA PARA SOMA ### Soma dos resultados que podem sair
// Para 1 jogo
// {9, 12, 15, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45, 48, 51, 54, 57, 60, 63, 66, 69, 72, 75, 78, 81, 84}
// Para 2 jogos
// {39, 42, 45, 48, 51, 54, 57, 60, 63, 66, 69, 72, 75, 78, 81, 84, 87, 90, 93, 96, 99, 102, 105, 108, 111, 114, 117, 120, 123, 126, 129, 132, 135, 138, 141, 144, 147, 150, 153, 156, 159}
// Para 3 jogos
// {72, 75, 78, 81, 84, 87, 90, 93, 96, 99, 102, 105, 108, 111, 114, 117, 120, 123, 126, 129, 132, 135, 138, 141, 144, 147, 150, 153, 156, 159, 162, 165, 168, 171, 174, 177, 180, 183, 186, 189, 192, 195, 198, 201, 204, 207, 210, 213, 216, 219, 222, 225, 228, 234}

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
    // Números a analisar na cartela
    int numeros_para_analise[] = {3,6,9,12,15,18,21};

    // Vetor com todas as ocorrências
    std::vector <int> ocorrencias;

    // Quantidade de jogos que será analisado
    int tamanho_amostra = (atoi(argv[1]) * 15);

    // Verificar as ocorrências
    for(auto *jogo = (std::end(numeros_sorteados) - 1), soma(0); jogo >= (std::begin(numeros_sorteados) + tamanho_amostra - 1) ; jogo -= 15, soma = 0){
        for(auto i : numeros_para_analise){
            for(auto j(0); j<tamanho_amostra; ++j){
                if(i == *(jogo - j)){
                    soma += i;
                }
            }
        }
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