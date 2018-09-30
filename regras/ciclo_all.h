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
    bool flag_ciclo_return(false);
    #pragma omp parallel
    {        
        #pragma omp sections
        {            
            #pragma omp section
            {
                if(false == numero_pode_sair(primeiro)){
                    flag_ciclo_return = true;
                    #pragma omp cancel sections
                }
            }
            #pragma omp section
            {
                if(false == dento_do_ciclo(primeiro)){
                    flag_ciclo_return = true;
                    #pragma omp cancel sections
                }
            }
            #pragma omp section
            {
                if(false == ciclo_segundo_quantidade(primeiro)){
                    flag_ciclo_return = true;
                    #pragma omp cancel sections
                }
            }
            #pragma omp section
            {
                if(false == ciclo_razao_aurea(primeiro)){
                    flag_ciclo_return = true;
                    #pragma omp cancel sections
                }
            }
        }        
    }
    if(flag_ciclo_return){
        return false;
    } else {
        return true;
    }
}
