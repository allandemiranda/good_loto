/**
 * @brief Regras geradas pela analise dos númros da Coluna 4
 * 
 * @file coluna_4.h
 * @author Allan de Miranda Silva
 * @date 28-09-2018
 */

#include <iterator>
#include <vector>
#include <algorithm>
#include <cmath>

/**
 * @brief Função que verifica somente todas as regras coluna 4
 * 
 * @param primeiro Aponta para o primeiro número do jogo que queremos analisar
 * @return true Para se todas as regras estão valendo
 * @return false Para se pelomenos uma regra não está valendo
 */
bool coluna_4_analise(int *primeiro){
    // Números a analisar
    int numeros_para_analise[] = {4,9,14,19,24};

    // Tamanho das Amostras
    int tamanho_amostra_vetor_soma[] = {1};
    int tamanho_amostra_vetor_ocorrencias[] = {3};
    int tamanho_amostra_vetor_binario[] = {2,3,5,8,13,21,34,55};

    // Respostas
    std::vector < std::vector <int> > respostas_soma = {
        {
            0, 4, 9, 13, 14, 18, 19, 23, 24, 27, 28, 32, 33, 37, 38, 42, 43, 46, 47, 51, 52, 56, 57, 61, 66, 70
        }
    };
    std::vector < std::vector <int> > respostas_ocorrencias = {
        {
            4, 5, 6, 7, 8, 9, 10, 11, 12, 13
        }
    };
    std::vector < std::vector <int> > respostas_binario = {
        {
            1, 11, 100, 101, 110, 111, 1001, 1010, 1011, 1100, 1101, 1110, 1111, 10001, 10010, 10011, 10100, 10101, 10110, 10111, 11000, 11001, 11010, 11011, 11100, 11101, 11110, 11111
        },
        {
            110, 111, 1011, 1101, 1110, 1111, 10011, 10100, 10101, 10110, 10111, 11001, 11010, 11011, 11100, 11101, 11110, 11111
        },
        {
            1111, 10111, 11011, 11101, 11110, 11111
        },
        {
            10111, 11111
        },
        {
            11111
        },
        {
            11111
        },
        {
            11111
        },
        {
            11111
        }
    };

    // Verificar regras
    if(analise_soma(primeiro, std::begin(numeros_para_analise), std::distance(std::begin(numeros_para_analise), std::end(numeros_para_analise)), std::begin(tamanho_amostra_vetor_soma), std::distance(std::begin(tamanho_amostra_vetor_soma), std::end(tamanho_amostra_vetor_soma)), respostas_soma)){
        if(analise_ocorrencias(primeiro, std::begin(numeros_para_analise), std::distance(std::begin(numeros_para_analise), std::end(numeros_para_analise)), std::begin(tamanho_amostra_vetor_ocorrencias), std::distance(std::begin(tamanho_amostra_vetor_ocorrencias), std::end(tamanho_amostra_vetor_ocorrencias)), respostas_ocorrencias)){
            if(analise_binario(primeiro, std::begin(numeros_para_analise), std::distance(std::begin(numeros_para_analise), std::end(numeros_para_analise)), std::begin(tamanho_amostra_vetor_binario), std::distance(std::begin(tamanho_amostra_vetor_binario), std::end(tamanho_amostra_vetor_binario)), respostas_binario)){
                return true;                
            }            
        }        
    }
    return false;
}