/**
 * @brief Arquivo que irá conter todas as regas relacionadas a ciclo
 * 
 * @file cilco_all.h
 * @author Allan de Miranda Silva
 * @date 20-09-2018
 */

#include "ciclo_numerico.h"

/**
 * @brief Função que verifica somente todas as regras de ciclos
 * 
 * @param primeiro Aponta para o primeiro número do jogo que queremos analisar
 * @return true Para se todas as regras estão valendo
 * @return false Para se pelomenos uma regra não está valendo
 */
bool regras_gerais_ciclo(int *primeiro){
    if(numero_pode_sair(primeiro)){
        if(dento_do_ciclo(primeiro)){
            if(ciclo_segundo_quantidade(primeiro)){
                if(ciclo_razao_aurea(primeiro)){
                    return true;
                }
            }
        }
    }
    return false;
}
