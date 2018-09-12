/**
 * @brief Regras geradas pela analise dos númros Pares
 * 
 * @file pares.h
 * @author Allan de Miranda Silva
 * @date 10-09-2018
 */
#include <iterator>
#include <vector>
#include <algorithm>

/**
 * @brief Função que verifica somente todas as regras pares
 * 
 * @param primeiro Aponta para o primeiro número do jogo que queremos analisar
 * @return true Para se todas as regras estão valendo
 * @return false Para se pelomenos uma regra não está valendo
 */
bool regras_gerais_pares(int *primeiro){
    // Números a analisar
    int numeros_para_analise[] = {2,4,6,8,10,12,14,16,18,20,22,24};

    // Tamanho das Amostras
    int tamanho_amostra_vetor_soma[] = {1,2};
    int tamanho_amostra_vetor_ocorrencias[] = {1,2,3,5,8};

    // Respostas
    std::vector < std::vector <int> > respostas_soma = {
        {
            38, 40, 42, 44, 46, 48, 50, 52, 54, 56, 58, 60, 62, 64, 66, 68, 70, 72, 74, 76, 78, 80, 82, 84, 86, 88, 90, 92, 94, 96, 98, 100, 102, 104, 106, 108, 110, 112, 114, 116, 118, 120, 122, 124, 126, 128, 130, 132, 134, 136, 138, 140, 142, 144, 146
        },
        {
            90, 92, 94, 96, 104, 110, 112, 114, 116, 122, 124, 126, 128, 130, 132, 134, 136, 138, 140, 142, 144, 146, 148, 150, 152, 154, 156, 158, 160, 162, 164, 166, 168, 170, 172, 174, 176, 178, 180, 182, 184, 186, 188, 190, 192, 194, 196, 198, 200, 202, 204, 206, 208, 210, 212, 214, 216, 218, 220, 222, 224, 226, 228, 230, 232, 234, 236, 238, 240, 242, 244, 246, 248, 250, 252, 254, 256, 260, 262, 264, 266
        }
    };
    std::vector < std::vector <int> > respostas_ocorrencias = {
        {
            3, 4, 5, 6, 7, 8, 9, 10, 11
        },
        {
            10, 11, 12, 13, 14, 15, 16, 17, 18
        },
        {
            16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27
        },
        {
            29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42
        },
        {
            49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66
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