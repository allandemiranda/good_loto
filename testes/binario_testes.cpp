#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <cmath>
#include "../analise/numeros_sorteados.h"

int main(int argc, char *argv[ ]){
    //Vetor de análise final de ocorrências
    std::vector < std::vector bool > ocorrencias;

    //Números para analise
    int numeros_p_analise[] = {2,3,5,7,11,13,17,19,23}; // números da cartela
    auto tamanho_analise = std::distance(std::begin(numeros_p_analise), std::end(numeros_p_analise));

    //Números a ser analisado
    int tamanho_amostra = 15 * atoi(argv[1]);
    for(auto *i = std::begin(numeros_sorteados); i<std::end(numeros_sorteados); i += tamanho_amostra){
        //Verificar se a proxima analise é maior que o número máximo de jogos que já foram sorteados
        if((i+tamanho_amostra) > std::end(numeros_p_analise)){
            break;
        }
        //Vetor que irá conter a ordem
        bool binario[tamanho_analise];
        for(auto j(0); j<tamanho_analise; ++j){
            binario[j] = false;
        }
        //Preencher o vetor Binario com a sequencia esperada
        for(auto *j = std::begin(numeros_p_analise), posicao; j<std::end(numeros_p_analise); ++j, ++posicao){
            for(auto k(0); k<tamanho_amostra; ++k){
                if(*j == *(i+k)){
                    binario[posicao] = true;
                }
            }
        }
        //Colocar o Binário no vector
        std::vector <bool> temporario;
        for(auto i : binario){
            temporario.(i);
        }
        ocorrencias.push_back(temporario);
    }

    for(auto i(0); i<ocorrencias.size(); ++i){
        for(auto j(0); j<ocorrencias[i].size(); ++j){
            if(ocorrencias[i][j] == )
        }
    }






    return 0;
}