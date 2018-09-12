/**
 * @brief Regras geradas pela analise dos númros Impares
 * 
 * @file impares.h
 * @author Allan de Miranda Silva
 * @date 11-09-2018
 */
#include <iterator>
#include <vector>
#include <algorithm>

/**
 * @brief Função que verifica somente todas as regras impares
 * 
 * @param primeiro Aponta para o primeiro número do jogo que queremos analisar
 * @return true Para se todas as regras estão valendo
 * @return false Para se pelomenos uma regra não está valendo
 */
bool regras_gerais_impares(int *primeiro){
    // Números a analisar
    int numeros_para_analise[] = {1,3,5,7,9,11,13,15,17,19,21,23,25};

    // Tamanho das Amostras
    int tamanho_amostra_vetor_soma[] = {1,2};
    int tamanho_amostra_vetor_ocorrencias[] = {1,2,3,5,8};

    // Respostas
    std::vector < std::vector <int> > respostas_soma = {
        {
            41, 42, 43, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 159, 160, 162, 163
        },
        {
            100, 103, 114, 118, 119, 120, 127, 128, 129, 132, 133, 134, 135, 136, 137, 138, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 258, 259, 260, 261, 262, 263, 264, 265, 267, 268, 269, 270, 271, 272, 273, 274, 277, 278, 279, 281, 282, 285, 287, 290, 293, 295
        }
    };
    std::vector < std::vector <int> > respostas_ocorrencias = {
        {
            4, 5, 6, 7, 8, 9, 10, 11
        },
        {
            12, 13, 14, 15, 16, 17, 18, 19, 20
        },
        {
            18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29
        },
        {
            33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45
        },
        {
            54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71
        }
    };

    // Verificar regras
    if(analise_soma(primeiro, std::begin(numeros_para_analise), std::distance(std::begin(numeros_para_analise), std::end(numeros_para_analise)), std::begin(tamanho_amostra_vetor_soma), std::distance(std::begin(tamanho_amostra_vetor_soma), std::end(tamanho_amostra_vetor_soma)), respostas_soma)){
        if(analise_ocorrencias(primeiro, std::begin(numeros_para_analise), std::distance(std::begin(numeros_para_analise), std::end(numeros_para_analise)), std::begin(tamanho_amostra_vetor_ocorrencias), std::distance(std::begin(tamanho_amostra_vetor_ocorrencias), std::end(tamanho_amostra_vetor_ocorrencias)), respostas_ocorrencias)){
            return true;           
        }        
    }
    return false;
}