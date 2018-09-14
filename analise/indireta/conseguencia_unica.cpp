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

int main(int argc, char const *argv[]){
    // Números do cartão
    int numeros_possiveis[25] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};

    // Números a analisar na cartela
    //int numeros_para_analise[] = {3,6,9,12,15,18,21};

    // Verificar as ocorrências

    // Abra o Número inicial do jogo
    for(auto *jogo=std::begin(numeros_sorteados); jogo<(std::end(numeros_sorteados)-15); jogo+=15){ 
        // Abra os números 25 possiveis de sair       
        for(auto se_sair : numeros_possiveis){  
            // Crie as duplas possiveis          
            int dupla[2];            
            for(auto primeira(0); primeira<(25 - 1); ++primeira){
                dupla[0] = numeros_possiveis[primeira];
                for(auto segunda = (primeira + 1); segunda<25; ++segunda){
                    dupla[1] = numeros_possiveis[segunda];
                    // Abra o jogo e veja se o número se_sair esta dentro dele
                    for(auto i(0); i<15; ++i){
                        // Se o número estiver dentro dele
                        if(*(jogo+i)==se_sair){
                            // Verifique se a dupla saiu
                            bool dupla_presente = false;
                            // Abra os números da dupla
                            for(auto j(0); j<2; ++j){
                                // Abra os números do jogo seguinte
                                bool presente = false;
                                for(auto k(0); k<15; ++k){
                                    // Se o número do jogo seguinte for o número da dupla
                                    if(*(jogo+15+k)==(dupla[j])){
                                        // Diga que está presente este número da dupla
                                        presente = true;
                                        break;
                                    }
                                }
                                // Se estiver presente pare, pois queremos duplas que não sai
                                if(presente){
                                    // Avise que alguem da dupla saiu
                                    dupla_presente = true;
                                    break;
                                }
                            }
                            // Alguem da dupla saiu, pare de verificar e passe para próxima dupla
                            if(dupla_presente){
                                break;
                            } else {
                                std::cout << "O número " << se_sair << " saiu, a dupla " << dupla[0] << " e " << dupla[1] << " nunca sairam juntas no jogo seguinte" << std::endl; 
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
