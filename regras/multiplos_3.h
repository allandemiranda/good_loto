/**
 * @brief Regras geradas pela analise dos númros multilos de 3
 * 
 * @file multiplos_3.h
 * @author Allan de Miranda Silva
 * @date 09-09-2018
 */
#include <iterator>
#include <vector>
#include <algorithm>
#include <cmath>

bool multiplos_3_soma(int *inicial){
    bool bandeira;
    int numeros_p_analise[] = {3,6,9,12,15,18,21}; // números da cartela
    int soma(0);

    // primeiro definição    
    bandeira = true;
    for(int *i=inicial; i<(inicial+15); ++i){
        for(int *j=std::begin(numeros_p_analise); j<std::end(numeros_p_analise); ++j){
            if(*i == *j){
                soma += *i;
                break;
            }
        }
    }
        //### Editar variaveis
    int numeros_verdade_um[] = {15, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45, 48, 51, 54, 57, 60, 63, 66, 69, 72, 75, 78, 81, 84};
    for(int *i=std::begin(numeros_verdade_um); i<std::end(numeros_verdade_um); ++i){
        if(*i == soma){
            bandeira = false;
            break;
        }
    }
    if(bandeira){
        return false;
    }

    int quantidade_de_jogos_sorteados = std::distance(std::begin(numeros_sorteados), std::end(numeros_sorteados)) / 15;
    int analise_padrao;
    int soma_analise_padrao;

    // segunda definição
    analise_padrao = 2;
    bandeira = true;
    if((quantidade_de_jogos_sorteados+1)%analise_padrao != 0){
        return true;
    }
    soma_analise_padrao = 0;
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
    int numeros_verdade_dois[] = {39, 42, 45, 48, 51, 54, 57, 60, 63, 66, 69, 72, 75, 78, 81, 84, 87, 90, 93, 96, 99, 102, 105, 108, 111, 114, 117, 120, 123, 126, 129, 132, 135, 138, 141, 144, 147, 150, 153, 156, 159, 165};
    for(int *i=std::begin(numeros_verdade_dois); i<std::end(numeros_verdade_dois); ++i){
        if(*i == soma){
            bandeira = false;
            break;
        }
    }
    if(bandeira){
        //return false;
    }

    // fim
    return true;
}
