/**
 * @brief Inclui o gerenciamento das regras globais a ser analisada por suas especificações
 * 
 * @file regras.h
 * @author Allan de Miranda Silva
 * @date 09-09-2018
 */
#include "../analise/numeros_sorteados.h" // Para as regras funcionarem
#include "fibonacci_all.h" // Regras Fibonacci
#include "multiplos_all.h" // Regras Multiplos


/**
 * @brief Função que verifica todas as regras
 * 
 * @param primeiro Aponta para o primeiro número do jogo que queremos analisar
 * @return true Para se todas as regras estão valendo
 * @return false Para se pelomenos uma regra não está valendo
 */
bool regras_gerais(int *primeiro){
    regras_gerais_fibonacci(primeiro){
        regras_gerais_multiplos(primeiro){
            return true;
        }
    }

    return false;
}

