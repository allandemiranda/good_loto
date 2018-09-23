/**
 * @brief Tentativa de criar uma razão aurea entre os cliclos de cada número
 * 
 * @file ciclo_razao_aurea.cpp
 * @author Allan de Miranda Silva
 * @date 23-09-2018
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "../numeros_sorteados.h"

int main(int argc, char const *argv[])
{
    // núemro a analisar
    int numero_analisar(atoi(argv[1]));

    std::cout << "Analisar ciclos do número " << numero_analisar << std::endl;
    std::cout << std::endl;

    // encontre a primeira ocorrência
    int contador_primeira_ocorrencia(0);
    for(int i : numeros_sorteados){
        if(i == numero_analisar){
            break;
        }
        contador_primeira_ocorrencia++;        
    }

    std::cout << "Primeira ocorrência aconteceu na posição " << contador_primeira_ocorrencia << std::endl;
    std::cout << std::endl;

    std::vector <int> analise;

    // analise
    int posicao_atual(contador_primeira_ocorrencia);
    int contador_em_B(0);
    int contador_em_C(0);
    int status(1); // A = 1, B = 2

    for(int i(posicao_atual+1); i<std::distance(std::begin(numeros_sorteados), std::end(numeros_sorteados)); ++i){
        if(status == 1){
            contador_em_B++;
            if(numeros_sorteados[i] == numero_analisar){
                status = 2;
            }
            continue;
        }
        if(status == 2){
            contador_em_C++;
            if(numeros_sorteados[i] == numero_analisar){
                int resposta = (contador_em_B+contador_em_C)/contador_em_C;
                analise.push_back(resposta);

                posicao_atual = posicao_atual + contador_em_B;
                i = posicao_atual;
                status = 1;
                contador_em_B = 0;
                contador_em_C = 0;
            }
        }
    }

    std::cout << "Verificando os " << analise.size() << " resultados" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    // verificar resultados
    std::vector <int> saiu;
    for(int i : analise){
        bool flag(true);
        for(int j : saiu){
            if(i == j){
                flag = false;
                break;
            }
        }
        if(flag){
            saiu.push_back(i);
        }
    }

    std::sort(saiu.begin(), saiu.end());

    for(int i : saiu){
        int contador(0);
        for(int j : analise){
            if(i == j){
                ++contador;
            }
        }
        std::cout << "Razão aurea " << i << " saiu " << contador << " vezes " << std::endl;
    }

    return 0;
}
