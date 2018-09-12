/**
 * @brief Regras geradas pela analise dos númros multilos de 3
 * 
 * @file multiplos_3.h
 * @author Allan de Miranda Silva
 * @date 09-09-2018
 */
#include <iterator>
#include <vector>
#include <algorithm>
#include <cmath>

/**
 * @brief Função que verifica somente todas as regras multiplos de 3
 * 
 * @param primeiro Aponta para o primeiro número do jogo que queremos analisar
 * @return true Para se todas as regras estão valendo
 * @return false Para se pelomenos uma regra não está valendo
 */
bool multiplos_3_analise(int *primeiro){
    // Números a analisar
    int numeros_para_analise[] = {3,6,9,12,15,18,21};

    // Tamanho das Amostras
    int tamanho_amostra_vetor_soma[] = {1,2,3};
    int tamanho_amostra_vetor_ocorrencias[] = {1,2,3,5,8};
    int tamanho_amostra_vetor_binario[] = {1,2,3,5,8,13,21,34,55};

    // Respostas
    std::vector < std::vector <int> > respostas_soma = {
        {
            9, 12, 15, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45, 48, 51, 54, 57, 60, 63, 66, 69, 72, 75, 78, 81, 84
        },
        {
            39, 42, 45, 48, 51, 54, 57, 60, 63, 66, 69, 72, 75, 78, 81, 84, 87, 90, 93, 96, 99, 102, 105, 108, 111, 114, 117, 120, 123, 126, 129, 132, 135, 138, 141, 144, 147, 150, 153, 156, 159
        },
        {
            72, 75, 78, 81, 84, 87, 90, 93, 96, 99, 102, 105, 108, 111, 114, 117, 120, 123, 126, 129, 132, 135, 138, 141, 144, 147, 150, 153, 156, 159, 162, 165, 168, 171, 174, 177, 180, 183, 186, 189, 192, 195, 198, 201, 204, 207, 210, 213, 216, 219, 222, 225, 228, 234
        }
    };
    std::vector < std::vector <int> > respostas_ocorrencias = {
        {
            2, 3, 4, 5, 6
        },
        {
            5, 6, 7, 8, 9, 10, 11, 12
        },
        {
            8, 9, 10, 11, 12, 13, 14, 15, 16, 17
        },
        {
            14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26
        },
        {
            24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41
        }
    };
    std::vector < std::vector <int> > respostas_binario = {
        {
            10, 11, 100, 101, 110, 111, 1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111, 10000, 10001, 10010, 10011, 10100, 10101, 10110, 10111, 11000, 11001, 11010, 11011, 11100, 11101, 11110, 11111, 100000, 100001, 100010, 100011, 100100, 100101, 100110, 100111, 101000, 101001, 101010, 101011, 101100, 101101, 101110, 101111, 110000, 110001, 110010, 110011, 110100, 110101, 110110, 110111, 111000, 111001, 111010, 111011, 111100, 111101, 111110, 111111, 1000000, 1000001, 1000010, 1000011, 1000100, 1000101, 1000110, 1000111, 1001000, 1001001, 1001010, 1001011, 1001100, 1001101, 1001110, 1001111, 1010000, 1010001, 1010010, 1010011, 1010100, 1010101, 1010110, 1010111, 1011000, 1011001, 1011010, 1011011, 1011100, 1011101, 1011110, 1011111, 1100000, 1100001, 1100010, 1100011, 1100100, 1100101, 1100110, 1100111, 1101000, 1101001, 1101010, 1101011, 1101100, 1101101, 1101110, 1101111, 1110000, 1110001, 1110010, 1110011, 1110100, 1110101, 1110110, 1110111, 1111000, 1111001, 1111010, 1111011, 1111100, 1111101, 1111110, 1111111
        },
        {
            1110, 1111, 10001, 10111, 11000, 11011, 11110, 11111, 100011, 100111, 101011, 101101, 101110, 101111, 110001, 110010, 110011, 110100, 110101, 110110, 110111, 111001, 111010, 111011, 111100, 111101, 111110, 111111, 1000111, 1001010, 1001011, 1001101, 1001110, 1001111, 1010001, 1010011, 1010100, 1010101, 1010110, 1010111, 1011001, 1011010, 1011011, 1011100, 1011101, 1011110, 1011111, 1100011, 1100101, 1100110, 1100111, 1101000, 1101001, 1101010, 1101011, 1101100, 1101101, 1101110, 1101111, 1110000, 1110001, 1110010, 1110011, 1110100, 1110101, 1110110, 1110111, 1111000, 1111001, 1111010, 1111011, 1111100, 1111101, 1111110, 1111111
        },
        {
            1111, 11011, 11111, 101111, 110001, 110111, 111011, 111101, 111110, 111111, 1000111, 1001011, 1001110, 1001111, 1010111, 1011011, 1011101, 1011110, 1011111, 1100011, 1100111, 1101011, 1101101, 1101110, 1101111, 1110011, 1110101, 1110110, 1110111, 1111001, 1111011, 1111100, 1111101, 1111110, 1111111
        },
        {
            110111, 111110, 111111, 1010111, 1011111, 1101111, 1110111, 1111011, 1111101, 1111110, 1111111
        },
        {
            1101111, 1110111, 1111111
        },
        {
            1111111
        },
        {
            1111111
        },
        {
            1111111
        },
        {
            1111111
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