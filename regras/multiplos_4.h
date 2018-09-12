/**
 * @brief Regras geradas pela analise dos númros multilos de 4
 * 
 * @file multiplos_4.h
 * @author Allan de Miranda Silva
 * @date 10-09-2018
 */
#include <iterator>
#include <vector>
#include <algorithm>
#include <cmath>

/**
 * @brief Função que verifica somente todas as regras multiplos de 4
 * 
 * @param primeiro Aponta para o primeiro número do jogo que queremos analisar
 * @return true Para se todas as regras estão valendo
 * @return false Para se pelomenos uma regra não está valendo
 */
bool multiplos_4_analise(int *primeiro){
    // Números a analisar
    int numeros_para_analise[] = {4,8,12,16,20,24};

    // Tamanho das Amostras
    int tamanho_amostra_vetor_soma[] = {1,2,3};
    int tamanho_amostra_vetor_ocorrencias[] = {1,2,3,5,8};
    int tamanho_amostra_vetor_binario[] = {1,2,3,5,8,13,21,34,55};

    // Respostas
    std::vector < std::vector <int> > respostas_soma = {
        {
            4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60, 64, 68, 72, 76, 80, 84
        },
        {
            28, 32, 36, 40, 44, 48, 52, 56, 60, 64, 68, 72, 76, 80, 84, 88, 92, 96, 100, 104, 108, 112, 116, 120, 124, 128, 132, 136, 140, 144, 148, 152, 156
        },
        {
            72, 76, 80, 84, 88, 92, 96, 100, 104, 108, 112, 116, 120, 124, 128, 132, 136, 140, 144, 148, 152, 156, 160, 164, 168, 172, 176, 180, 184, 188, 192, 196, 200, 204, 208, 212, 220, 224
        }
    };
    std::vector < std::vector <int> > respostas_ocorrencias = {
        {
            1, 2, 3, 4, 5, 6
        },
        {
            3, 4, 5, 6, 7, 8, 9, 10, 11
        },
        {
            6, 7, 8, 9, 10, 11, 12, 13, 14, 15
        },
        {
            12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24
        },
        {
            21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37
        }
    };
    std::vector < std::vector <int> > respostas_binario = {
        {
            1, 10, 11, 100, 101, 110, 111, 1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111, 10000, 10001, 10010, 10011, 10100, 10101, 10110, 10111, 11000, 11001, 11010, 11011, 11100, 11101, 11110, 11111, 100000, 100001, 100010, 100011, 100100, 100101, 100110, 100111, 101000, 101001, 101010, 101011, 101100, 101101, 101110, 101111, 110000, 110001, 110010, 110011, 110100, 110101, 110110, 110111, 111000, 111001, 111010, 111011, 111100, 111101, 111110, 111111
        },
        {
            100, 111, 1001, 1011, 1100, 1101, 1110, 1111, 10001, 10010, 10011, 10101, 10110, 10111, 11000, 11001, 11010, 11011, 11100, 11101, 11110, 11111, 100101, 100110, 100111, 101000, 101001, 101010, 101011, 101100, 101101, 101110, 101111, 110001, 110010, 110011, 110101, 110110, 110111, 111000, 111001, 111010, 111011, 111100, 111101, 111110, 111111
        },
        {
            1110, 1111, 10111, 11011, 11100, 11101, 11110, 11111, 100111, 101011, 101100, 101101, 101110, 101111, 110011, 110101, 110110, 110111, 111001, 111010, 111011, 111100, 111101, 111110, 111111
        },
        {
            11111, 101111, 110111, 111011, 111101, 111110, 111111
        },
        {
            111011, 111111
        },
        {
            111111
        },
        {
            111111
        },
        {
            111111
        },
        {
            111111
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