/**
 * @brief Inclui o gerenciamento das regras globais a ser analisada por suas especificações
 * 
 * @file regras.h
 * @author Allan de Miranda Silva
 * @date 09-09-2018
 */
#include "fibonacci_all.h" // Regras Fibonacci
#include "multiplos_all.h" // Regras Multiplos
#include "primos_all.h" // Regras Primos
#include "pares.h"
bool regras_gerais_pares(int *primeiro){
    if(pares_soma(primeiro)){
        if(pares_ocorrencias(primeiro)){
            //if(pares_binario(primeiro)){
                return true;                
            //}            
        }        
    }
    return false;
}

/**
 * @brief Função que verifica todas as regras
 * 
 * @param primeiro Aponta para o primeiro número do jogo que queremos analisar
 * @return true Para se todas as regras estão valendo
 * @return false Para se pelomenos uma regra não está valendo
 */
bool regras_gerais(int *primeiro){
    if(regras_gerais_fibonacci(primeiro)){
        if(regras_gerais_multiplos(primeiro)){
            if(regras_gerais_primos(primeiro)){
                if(regras_gerais_pares(primeiro)){
                    return true;
                }
            }
        }
    }
    return false;
}

