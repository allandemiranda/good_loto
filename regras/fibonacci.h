/**
 * @brief Regras geradas pela analise dos númros de fibonacci
 * 
 * @file fibonacci.h
 * @author Allan de Miranda Silva
 * @date 08-09-2018
 */
#include "../analise/numeros_sorteados.h"
#include <iterator>

bool fibonacci_binario_soma(int *inicial){
    // primeiro definição
    int numeros_p_analise[] = {1,2,3,5,8,13,21}; // números Fibonacci da cartela
    int soma(0);
    for(int *i=inicial; i<(inicial+15); ++i){
        for(int *j=std::begin(numeros_p_analise); j<std::end(numeros_p_analise); ++j){
            if(*i == *j){
                soma += *i;
                break;
            }
        }
    }
    if((soma == 0) or (soma == 1) or (soma == 2) or (soma == 4) or (soma == 5) or (soma == 7) or (soma == 12) or (soma > 53)){
        return false;
    } 

    int quantidade_de_jogos_sorteados = std::distance(std::begin(numeros_sorteados), std::end(numeros_sorteados)) / 15;
    int analise_padrao;

    // segunda definição
    analise_padrao = 2;
    if((quantidade_de_jogos_sorteados+1)%analise_padrao != 0){
        return true;
    }
    int soma_analise_padrao = 0;
    for(int *i=((std::begin(numeros_sorteados))+(15*(quantidade_de_jogos_sorteados + 2 - analise_padrao))); i<std::end(numeros_sorteados); ++i){
        for(int *j=std::begin(numeros_p_analise); j<std::end(numeros_p_analise); ++j){
            if(*i == *j){
                soma_analise_padrao += *i;
                break;
            }
        }
    }
    if(((soma + soma_analise_padrao) < 20) or ((soma + soma_analise_padrao) > 100)){
        return false;
    }

    //fim
    return true;  
}