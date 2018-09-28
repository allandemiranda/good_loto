/**
 * @brief Regras geradas pela analise dos númros da Coluna 3
 * 
 * @file coluna_3.h
 * @author Allan de Miranda Silva
 * @date 28-09-2018
 */

#include <iterator>
#include <vector>
#include <algorithm>
#include <cmath>

/**
 * @brief Função que verifica somente todas as regras coluna 3
 * 
 * @param primeiro Aponta para o primeiro número do jogo que queremos analisar
 * @return true Para se todas as regras estão valendo
 * @return false Para se pelomenos uma regra não está valendo
 */
bool coluna_3_analise(int *primeiro){
    // Números a analisar
    int numeros_para_analise[] = {3,8,13,18,23};

    // Tamanho das Amostras
    int tamanho_amostra_vetor_soma[] = {1};
    int tamanho_amostra_vetor_ocorrencias[] = {5};
    int tamanho_amostra_vetor_binario[] = {2,3,5,8,13,21,34,55};

    // Respostas
    std::vector < std::vector <int> > respostas_soma = {
        {
            0, 3, 8, 11, 13, 16, 18, 21, 23, 24, 26, 29, 31, 34, 36, 39, 41, 42, 44, 47, 49, 52, 54, 57, 62, 65
        }
    };
    std::vector < std::vector <int> > respostas_ocorrencias = {
        {
            9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22
        }
    };
    std::vector < std::vector <int> > respostas_binario = {
        {
            11, 101, 110, 111, 1001, 1010, 1011, 1100, 1101, 1110, 1111, 10000, 10001, 10010, 10011, 10100, 10101, 10110, 10111, 11000, 11001, 11010, 11011, 11100, 11101, 11110, 11111
        },
        {
            11, 111, 1011, 1101, 1110, 1111, 10011, 10101, 10110, 10111, 11001, 11010, 11011, 11100, 11101, 11110, 11111
        },
        {
            1111, 10111, 11011, 11101, 11110, 11111
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