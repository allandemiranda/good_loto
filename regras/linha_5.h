/**
 * @brief Regras geradas pela analise dos númros da Linha 5
 * 
 * @file linha_5.h
 * @author Allan de Miranda Silva
 * @date 25-09-2018
 */

#include <iterator>
#include <vector>
#include <algorithm>
#include <cmath>

/**
 * @brief Função que verifica somente todas as regras linha 5
 * 
 * @param primeiro Aponta para o primeiro número do jogo que queremos analisar
 * @return true Para se todas as regras estão valendo
 * @return false Para se pelomenos uma regra não está valendo
 */
bool linha_5_analise(int *primeiro){
    // Números a analisar
    int numeros_para_analise[] = {21,22,23,24,25};

    // Tamanho das Amostras
    int tamanho_amostra_vetor_soma[] = {2};
    int tamanho_amostra_vetor_ocorrencias[] = {2,3};
    int tamanho_amostra_vetor_binario[] = {2,3,5,8,13,21,34,55};

    // Respostas
    std::vector < std::vector <int> > respostas_soma = {
        {
            44, 45, 47, 49, 65, 66, 67, 68, 69, 70, 71, 72, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 180, 181, 182, 183, 184, 185, 186, 187, 188, 205, 206, 207, 208, 209, 230
        }
    };
    std::vector < std::vector <int> > respostas_ocorrencias = {
        {
            3, 4, 5, 6, 7, 8, 9
        },
        {
            5, 6, 7, 8, 9, 10, 11, 12, 13
        }
    };
    std::vector < std::vector <int> > respostas_binario = {
        {
            10, 11, 101, 111, 1001, 1010, 1011, 1100, 1101, 1110, 1111, 10001, 10010, 10011, 10100, 10101, 10110, 10111, 11000, 11001, 11010, 11011, 11100, 11101, 11110, 11111
        },
        {
            111, 1001, 1011, 1101, 1110, 1111, 10010, 10011, 10101, 10110, 10111, 11001, 11010, 11011, 11100, 11101, 11110, 11111
        },
        {
            1111, 10111, 11011, 11100, 11101, 11110, 11111
        },
        {
            1111, 11111
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