/**
 * @brief Para organizar as regras das Linhas
 * 
 * @file linha_all.h
 * @author Allan de Miranda Silva
 * @date 24-09-2018
 */
#include "linha_1.h" // Regras da Linha 1

/**
 * @brief Função que verifica somente todas as regras das linhas
 * 
 * @param primeiro Aponta para o primeiro número do jogo que queremos analisar
 * @return true Para se todas as regras estão valendo
 * @return false Para se pelomenos uma regra não está valendo
 */
bool regras_gerais_linhas(int *primeiro){ 
    if(linha_1_analise(primeiro)){
        return true;
    }
                        
    return false;
}