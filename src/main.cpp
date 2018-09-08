/**
 * @brief Função que irá gerar os jogos possiveis
 * 
 * @file main.cpp
 * @author Allan de Miranda Silva
 * @date 08-09-2018
 */
#include <iostream>
#include "analise/numeros_sorteados.h"

int main(void){
    // Verificar menor e amiores números que saem em suas posições
    for(int posicao(1); posicao<=15; ++posicao){
        for(auto *i = std::begin(numeros_sorteados); i<std::end(numeros_sorteados); ++i){

        }
    }
    return 0;
}