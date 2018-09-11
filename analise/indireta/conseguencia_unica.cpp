/**
 * @brief Qunado um número sai, que outros sempre saem
 * 
 * @file conseguencia_unica.cpp
 * @author Allan de Miranda Silva
 * @date 11-09-2018
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "../numeros_sorteados.h"

int main(int argc, char const *argv[])
{
    std::vector <int> ocorrencias;
    int tamanho_amostra = std::atoi(argv[1]);
    int numero = std::atoi(argv[2]);

    for(auto *i = std::begin(numeros_sorteados), analise(0); i<std::end(numeros_sorteados); ++i, ++analise){
        if((i + (tamanho_amostra * 15)) >= std::end(numeros_sorteados)){
            break;
        } else {
            if(analise < 15){
                if(*i == numero){
                    i += (15 - analise);
                    analise = 15;
                }
            } else {
                if(analise < (tamanho_amostra * 15)){
                    ocorrencias.push_back(*i);
                } else {
                    analise = 0;
                }
            }
        }
    }    
    return 0;
}
