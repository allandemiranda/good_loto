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

    // Abra o núemro a analisar
    for(int se_sair(0); se_sair<25; ++se_sair){
        // Abra a dupla
        int dupla[2];
        for(int primeiro(0); primeiro<24; ++primeiro){
            if(numeros_possiveis[primeiro]==numeros_possiveis[se_sair]){
                continue;
            }
            dupla[0] = numeros_possiveis[primeiro]; // Primeiro núemro da dupla
            for(int segundo(primeiro+1); segundo<25; ++segundo){
                if(numeros_possiveis[segundo]==numeros_possiveis[se_sair]){
                    continue;
                }
                dupla[1] = numeros_possiveis[segundo]; // Segundo núemro da dupla
                // Cheque nos jogos já sorteados
                // Jogo que vai ver se o número saiu
                bool nova_flag = false;
                bool flag =  false;
                for(auto *jogo=std::begin(numeros_sorteados); jogo<(std::end(numeros_sorteados)-15); jogo+=15){
                    for(int jogo_atual(0); jogo_atual<15; ++jogo_atual){
                        if(*(jogo+jogo_atual)==numeros_possiveis[se_sair]){
                            flag = true;
                        }                        
                    }
                    if(flag){
                        bool flag_seguinte = false;
                        // Jogo que vai olhar no jogo seguinte se  dupla saiu
                        for(int jogo_seguinte(15); jogo_seguinte<30; ++jogo_seguinte){
                            if(*(jogo+jogo_seguinte)==dupla[0]){
                                flag_seguinte = true;
                            }
                            if(*(jogo+jogo_seguinte)==dupla[1]){
                                flag_seguinte = true;
                            }
                        }
                        if(flag_seguinte){
                            break;
                            nova_flag = true;
                        }
                    }
                    if(nova_flag){
                        continue;
                    } else {
                        std::cout << "Se sair número " << numeros_possiveis[se_sair];
                        std::cout << " , nunca sairá os números " << dupla[0] << " e " << dupla[1];
                        std::cout << " no jogo seguinte" << std::endl;
                    }                    
                }

            }
        }
    }
    

    return 0;
}
