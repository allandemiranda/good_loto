/**
 * @brief Programa para gerar analise em cima dos núemros Pares - Soma
 * 
 * @file pares_soma.cpp
 * @author Allan de Miranda Silva
 * @date 10-09-2018
 */

// ### REGRA PARA SOMA ### Soma dos resultados que podem sair
// Para 1 jogo
// {41, 42, 43, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 159, 160, 162, 163}
// Para 2 jogos
// {100, 103, 114, 118, 119, 120, 127, 128, 129, 132, 133, 134, 135, 136, 137, 138, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 267, 268, 269, 270, 271, 272, 273, 274, 277, 278, 279, 281, 282, 285, 287, 290, 293, 295}

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
    int numeros_para_analise[] = {1,3,5,7,9,11,13,15,17,19,21,23,25};

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