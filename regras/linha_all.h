/**
 * @brief Para organizar as regras das Linhas
 * 
 * @file linha_all.h
 * @author Allan de Miranda Silva
 * @date 24-09-2018
 */
#include "linha_1.h" // Regras da Linha 1
#include "linha_2.h" // Regras da Linha 2
#include "linha_3.h" // Regras da Linha 3
#include "linha_4.h" // Regras da Linha 4
#include "linha_5.h" // Regras da Linha 5

/**
 * @brief Função que verifica somente todas as regras das linhas
 * 
 * @param primeiro Aponta para o primeiro número do jogo que queremos analisar
 * @return true Para se todas as regras estão valendo
 * @return false Para se pelomenos uma regra não está valendo
 */
bool regras_gerais_linhas(int *primeiro){ 
    if(linha_1_analise(primeiro)){
        if(linha_2_analise(primeiro)){
            if(linha_3_analise(primeiro)){
                if(linha_5_analise(primeiro)){
                    return true;
                }
            }
        }
    }
                        
    return false;
}