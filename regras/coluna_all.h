/**
 * @brief Para organizar as regras das Colunas
 * 
 * @file coluna_all.h
 * @author Allan de Miranda Silva
 * @date 28-09-2018
 */
#include "coluna_1.h" // Regras da Linha 1
#include "coluna_2.h" // Regras da Linha 2
#include "coluna_3.h" // Regras da Linha 3
#include "coluna_4.h" // Regras da Linha 4
#include "coluna_5.h" // Regras da Linha 5
#include "colunas.h" // Regras das Linhas

/**
 * @brief Função que verifica somente todas as regras das linhas
 * 
 * @param primeiro Aponta para o primeiro número do jogo que queremos analisar
 * @return true Para se todas as regras estão valendo
 * @return false Para se pelomenos uma regra não está valendo
 */
bool regras_gerais_colunas(int *primeiro){ 
    if(coluna_1_analise(primeiro)){
        if(coluna_2_analise(primeiro)){
            if(coluna_3_analise(primeiro)){
                if(coluna_4_analise(primeiro)){
                    //if(coluna_5_analise(primeiro)){ -> *** desativado pois corresponde a multiplos de 5 ***
                        if(colunas_analise(primeiro)){
                            return true;
                        }
                    //}
                }
            }
        }
    }
                        
    return false;
}