/**
 * @brief Inclui o gerenciamento das regras globais a ser analisada por suas especificações
 * 
 * @file regras.h
 * @author Allan de Miranda Silva
 * @date 09-09-2018
 */
#include "../analise/numeros_sorteados.h" // Para as regras funcionarem
#include "fibonacci.h" // Regras de Fibonacci
#include "multiplos_3.h"


/**
 * @brief Função que verifica todas as regras
 * 
 * @param primeiro Aponta para o primeiro número do jogo que queremos analisar
 * @return true Para se todas as regras estão valendo
 * @return false Para se pelomenos uma regra não está valendo
 */
bool regras_gerais(int *primeiro){
    if(fibonacci_soma(primeiro)){
        if(fibonacci_ocorrencias(primeiro)){
            if(fibonacci_binario(primeiro)){
                //if(fibonacci_ciclo(primeiro)){
                    if(multiplos_3_soma(primeiro)){
                        return true;
                    }
                //}
            }            
        }        
    }

    return false;
}

