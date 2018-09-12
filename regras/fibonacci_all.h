/**
 * @brief Regras geradas pela analise dos números de fibonacci
 * 
 * @file fibonacci_all.h
 * @author Allan de Miranda Silva
 * @date 08-09-2018
 */
#include <iterator>
#include <vector>
#include <algorithm>

/**
 * @brief Função que verifica somente todas as regras fibonacci
 * 
 * @param primeiro Aponta para o primeiro número do jogo que queremos analisar
 * @return true Para se todas as regras estão valendo
 * @return false Para se pelomenos uma regra não está valendo
 */
bool regras_gerais_fibonacci(int *primeiro){
    // Números a analisar
    int numeros_para_analise[] = {1,2,3,5,8,13,21};

    // Tamanho das Amostras
    int tamanho_amostra_vetor_soma[] = {1,2};
    int tamanho_amostra_vetor_ocorrencias[] = {1,2,3,5,8};
    int tamanho_amostra_vetor_binario[] = {1,2,3,5,8,13,21,34,55};

    // Respostas
    std::vector < std::vector <int> > respostas_soma = {
        {
            3, 6, 8, 9, 10, 11, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53
        },
        {
            11, 15, 16, 17, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103
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
            8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18
        },
        {
            16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27
        },
        {
            26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41
        }
    };
    std::vector < std::vector <int> > respostas_binario = {
        {
            10, 11, 100, 101, 110, 111, 1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111, 10001, 10010, 10011, 10100, 10101, 10110, 10111, 11000, 11001, 11010, 11011, 11100, 11101, 11110, 11111, 100001, 100010, 100011, 100100, 100101, 100110, 100111, 101000, 101001, 101010, 101011, 101100, 101101, 101110, 101111, 110000, 110001, 110010, 110011, 110100, 110101, 110110, 110111, 111000, 111001, 111010, 111011, 111100, 111101, 111110, 111111, 1000000, 1000001, 1000010, 1000011, 1000100, 1000101, 1000110, 1000111, 1001000, 1001001, 1001010, 1001011, 1001100, 1001101, 1001110, 1001111, 1010000, 1010001, 1010010, 1010011, 1010100, 1010101, 1010110, 1010111, 1011000, 1011001, 1011010, 1011011, 1011100, 1011101, 1011110, 1011111, 1100000, 1100001, 1100010, 1100011, 1100100, 1100101, 1100110, 1100111, 1101000, 1101001, 1101010, 1101011, 1101100, 1101101, 1101110, 1101111, 1110000, 1110001, 1110010, 1110011, 1110100, 1110101, 1110110, 1110111, 1111000, 1111001, 1111010, 1111011, 1111100, 1111101, 1111110, 1111111
        },
        {
            1111, 10111, 11010, 11011, 11100, 11101, 11110, 11111, 100101, 100111, 101011, 101100, 101101, 101110, 101111, 110010, 110011, 110101, 110111, 111001, 111010, 111011, 111100, 111101, 111110, 111111, 1000110, 1000111, 1001001, 1001011, 1001101, 1001110, 1001111, 1010011, 1010101, 1010110, 1010111, 1011011, 1011100, 1011101, 1011110, 1011111, 1100011, 1100100, 1100101, 1100110, 1100111, 1101000, 1101001, 1101011, 1101100, 1101101, 1101110, 1101111, 1110001, 1110010, 1110011, 1110100, 1110101, 1110110, 1110111, 1111000, 1111001, 1111010, 1111011, 1111100, 1111101, 1111110, 1111111
        },
        {
            11011, 11101, 11111, 100111, 101111, 110111, 111010, 111011, 111101, 111110, 111111, 1001111, 1010011, 1010111, 1011011, 1011101, 1011110, 1011111, 1100111, 1101001, 1101011, 1101101, 1101110, 1101111, 1110011, 1110101, 1110110, 1110111, 1111010, 1111011, 1111100, 1111101, 1111110, 1111111
        },
        {
            111011, 111111, 1011111, 1101111, 1110111, 1111011, 1111101, 1111110, 1111111
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