/**
 * @brief Inclui o gerenciamento das regras globais a ser analisada por suas especificações
 * 
 * @file regras.h
 * @author Allan de Miranda Silva
 * @date 09-09-2018
 */
#include "analises.h" // Analises de regras Diretas
#include "fibonacci_all.h" // Regras Fibonacci
#include "pares_impares_all.h" // Regras Pares e Impares
//#include "multiplos_all.h" // Regras Multiplos
//#include "primos_all.h" // Regras Primos


/**
 * @brief Função que verifica todas as regras
 * 
 * @param primeiro Aponta para o primeiro número do jogo que queremos analisar
 * @return true Para se todas as regras estão valendo
 * @return false Para se pelomenos uma regra não está valendo
 */
bool regras_gerais(int *primeiro){
    if(regras_gerais_fibonacci(primeiro)){
        //if(regras_gerais_multiplos(primeiro)){
            //if(regras_gerais_primos(primeiro)){
                if(regras_gerais_pares_impares(primeiro)){
                    return true;
                }
            //}
        //}
    }
    return false;
}

