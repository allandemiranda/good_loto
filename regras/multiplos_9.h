/**
 * @brief Regras geradas pela analise dos númros multilos de 9
 * 
 * @file multiplos_9.h
 * @author Allan de Miranda Silva
 * @date 10-09-2018
 */
#include <iterator>
#include <vector>
#include <algorithm>
#include <cmath>

/**
 * @brief Função que verifica somente todas as regras multiplos de 8
 * 
 * @param primeiro Aponta para o primeiro número do jogo que queremos analisar
 * @return true Para se todas as regras estão valendo
 * @return false Para se pelomenos uma regra não está valendo
 */
bool multiplos_9_analise(int *primeiro){
    // Números a analisar
    int numeros_para_analise[] = {9,18};

    // Tamanho das Amostras
    int tamanho_amostra_vetor_soma[] = {3};
    int tamanho_amostra_vetor_ocorrencias[] = {3,8,13,21};
    int tamanho_amostra_vetor_binario[] = {5,8,13,21,34,55};    

    // Respostas
    std::vector < std::vector <int> > respostas_soma = {
        {
            9, 18, 27, 36, 45, 54, 63, 72, 81
        }
    };
    std::vector < std::vector <int> > respostas_ocorrencias = {
        {
            1, 2, 3, 4, 5, 6
        },
        {
            5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
        },
        {
            9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22
        },
        {
            17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34
        }
    };
    std::vector < std::vector <int> > respostas_binario = {
        {
            1, 10, 11
        },
        {
            11
        },
        {
            11
        },
        {
            11
        },
        {
            11
        },
        {
            11
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