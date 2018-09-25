/**
 * @brief Regras geradas pela analise dos númros da Linha 3
 * 
 * @file linha_3.h
 * @author Allan de Miranda Silva
 * @date 25-09-2018
 */

#include <iterator>
#include <vector>
#include <algorithm>
#include <cmath>

/**
 * @brief Função que verifica somente todas as regras linha 3
 * 
 * @param primeiro Aponta para o primeiro número do jogo que queremos analisar
 * @return true Para se todas as regras estão valendo
 * @return false Para se pelomenos uma regra não está valendo
 */
bool linha_3_analise(int *primeiro){
    // Números a analisar
    int numeros_para_analise[] = {11,12,13,14,15};

    // Tamanho das Amostras
    int tamanho_amostra_vetor_soma[] = {2};
    int tamanho_amostra_vetor_ocorrencias[] = {1,2,3,5};
    int tamanho_amostra_vetor_binario[] = {2,3,5,8,13,21,34,55};

    // Respostas
    std::vector < std::vector <int> > respostas_soma = {
        {
            25, 26, 27, 29, 34, 35, 36, 37, 38, 39, 40, 41, 42, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 100, 101, 102, 103, 104, 105, 106, 107, 108, 115, 116, 117, 118, 119, 130
        }
    };
    std::vector < std::vector <int> > respostas_ocorrencias = {
        {
            1, 2, 3, 4, 5
        },
        {
            2, 3, 4, 5, 6, 7, 8, 9
        },
        {
            4, 5, 6, 7, 8, 9, 10, 11, 12, 13
        },
        {
            9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20
        }
    };
    std::vector < std::vector <int> > respostas_binario = {
        {
            11, 101, 110, 111, 1001, 1010, 1011, 1100, 1101, 1110, 1111, 10001, 10010, 10011, 10100, 10101, 10110, 10111, 11000, 11001, 11010, 11011, 11100, 11101, 11110, 11111
        },
        {
            111, 1011, 1101, 1110, 1111, 10011, 10101, 10110, 10111, 11001, 11010, 11011, 11100, 11101, 11110, 11111
        },
        {
            1111, 10111, 11011, 11101, 11110, 11111
        },
        {
            1111, 11101, 11111
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