/**
 * @brief Para organizar os multiplos das regras
 * 
 * @file multiplos_all.h
 * @author Allan de Miranda Silva
 * @date 10-09-2018
 */
#include "multiplos_3.h" // Regras multiplos de 3
#include "multiplos_4.h" // Regras multiplos de 4
#include "multiplos_5.h" // Regras multiplos de 5
#include "multiplos_6.h" // Regras multiplos de 6
#include "multiplos_7.h" // Regras multiplos de 7
#include "multiplos_8.h" // Regras multiplos de 8
#include "multiplos_9.h" // Regras multiplos de 9
#include "multiplos_10.h" // Regras multiplos de 10
#include "multiplos_11.h" // Regras multiplos de 11
#include "multiplos_12.h" // Regras multiplos de 12

/**
 * @brief Função que verifica somente todas as regras multiplos
 * 
 * @param primeiro Aponta para o primeiro número do jogo que queremos analisar
 * @return true Para se todas as regras estão valendo
 * @return false Para se pelomenos uma regra não está valendo
 */
bool regras_gerais_multiplos(int *primeiro){ 
    bool flag_multiplos_return(false);
    #pragma omp parallel
    { 
        #pragma omp sections
        { 
            #pragma omp section
            {
                if(false == multiplos_12_analise(primeiro)){
                    flag_multiplos_return = true; 
                    #pragma omp cancel sections                   
                }
            }
            #pragma omp section
            {
                if(false == multiplos_11_analise(primeiro)){
                    flag_multiplos_return = true;
                    #pragma omp cancel sections
                }
            }
            #pragma omp section
            {
                if(false == multiplos_10_analise(primeiro)){
                    flag_multiplos_return = true;
                    #pragma omp cancel sections
                }
            }
            #pragma omp section
            {
                if(false == multiplos_9_analise(primeiro)){
                    flag_multiplos_return = true;
                    #pragma omp cancel sections
                }
            }
            #pragma omp section
            {
                if(false == multiplos_8_analise(primeiro)){
                    flag_multiplos_return = true;
                    #pragma omp cancel sections
                }
            }
            #pragma omp section
            {
                if(false == multiplos_7_analise(primeiro)){
                    flag_multiplos_return = true;
                    #pragma omp cancel sections
                }
            }
            #pragma omp section
            {
                if(false == multiplos_6_analise(primeiro)){
                    flag_multiplos_return = true;
                    #pragma omp cancel sections
                }
            }
            #pragma omp section
            {
                if(false == multiplos_5_analise(primeiro)){
                    flag_multiplos_return = true;
                    #pragma omp cancel sections
                }
            }
            #pragma omp section
            {
                if(false == multiplos_4_analise(primeiro)){
                    flag_multiplos_return = true;
                    #pragma omp cancel sections
                }
            }
            #pragma omp section
            {
                if(false == multiplos_3_analise(primeiro)){
                    flag_multiplos_return = true;
                    #pragma omp cancel sections
                }
            }
        }
    }
    if(flag_multiplos_return){
        return false;
    } else {
        return true;
    }
}