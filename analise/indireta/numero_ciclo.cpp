/**
 * @brief Quando um núemro sair qual o maior tempo e menor tempo que ele fica sem sair?
 * 
 * @file numero_ciclo.cpp
 * @author Allan de Miranda Silva
 * @date 18-09-2018
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "../numeros_sorteados.h"

int main(int argc, char const *argv[])
{
    // Núemro escolhido para análise
    int numero(atoi(argv[1]));

    // Vetor de analise
    std::vector <int> analise;

    // Fazer análise
    int tempo_agora(0);
    bool primeira_vez(true);
    for(auto *sequencia=std::begin(numeros_sorteados); sequencia<std::end(numeros_sorteados); sequencia++){
        if(numero == *sequencia){
            primeira_vez = false;
        }
        if(numero != *sequencia){
            tempo_agora++;
        } else {
            analise.push_back(tempo_agora);
            tempo_agora = 0;
        }
    }

    // Apresentar resultados
    int menor(analise[0]);
    int maior(analise[0]);
    for(int i : analise){
        if( i < menor){
            menor = i;
        }
        if( i > maior){
            maior = i;
        }
    }
    std::vector <int> respostas_valor;
    for(int i(menor); i<=(maior + 1); ++i){
        int contador(0);
        for(int j : analise){
            if(j == i){
                contador++;
            }
        }
        std::cout << "Ciclo " << i << " saiu " << contador << " vezes (" << (float)((contador*100)/maior) << "%)" << std::endl;
        if(((contador*100)/maior) >= 1){
            respostas_valor.push_back(i);
        }
    }

    std::cout << "-----------------------------------" << std::endl;

    // Imprimir como um vetor    
    for(auto i(0); i<respostas_valor.size(); ++i){
        std::cout << respostas_valor[i] << ", ";
    }
    std::cout << respostas_valor[(respostas_valor.size() - 1)] << std::endl; 

    std::cout << "-----------------------------------" << std::endl;

    return 0;
}
