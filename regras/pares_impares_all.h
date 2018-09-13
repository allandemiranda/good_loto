/**
 * @brief Para organizar os pares e impares das regras
 * 
 * @file pares_impares_all.h
 * @author Allan de Miranda Silva
 * @date 11-09-2018
 */
#include "pares.h"
#include "impares.h"

/**
 * @brief Função que verifica somente todas as regras pares e impares
 * 
 * @param primeiro Aponta para o primeiro número do jogo que queremos analisar
 * @return true Para se todas as regras estão valendo
 * @return false Para se pelomenos uma regra não está valendo
 */
bool regras_gerais_pares_impares(int *primeiro){
    if(regras_gerais_impares(primeiro)){
        if(regras_gerais_pares(primeiro)){
            return true;
        }
    }
    return false;
}