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

/**
 * @brief Função para verificar se um núemro sai no jogo, no jogo seguinte a duplao saiu
 * 
 * @param um Número um da dupla
 * @param dois Número dois da dupla
 * @param numero Número que deve ser verificado se saiu
 * @return true Exite ao menos um jogo onde foi surteado o número e saiu a dupla no jogo seguinte
 * @return false Não exite ao menos um jogo onde foi surteado o número e saiu a dupla no jogo seguinte
 */
bool cheke_dupla(int um, int dois, int tres, int quatro, int cinco, int seis, int numero){    
    for(auto *jogo=std::begin(numeros_sorteados); jogo<(std::end(numeros_sorteados)-15); jogo +=15){        
        bool esta_no_jogo(false);
        for(int i(0); i<15; ++i){
            if(*(jogo+i)==numero){
                esta_no_jogo = true;
            }
        }
        bool esta_na_dupla(false);
        if(esta_no_jogo){
            bool dupla_um(false);
            bool dupla_dois(false);
            bool dupla_tres(false);
            bool dupla_quatro(false);
            bool dupla_cinco(false);
            bool dupla_seis(false);
            for(int j(15);j<30; ++j){
                if(*(jogo+j)== um){
                    dupla_um = true;
                }
                if(*(jogo+j)== dois){
                    dupla_dois = true;
                }
                if(*(jogo+j)== tres){
                    dupla_tres = true;
                }
                if(*(jogo+j)== quatro){
                    dupla_quatro = true;
                }
                if(*(jogo+j)== cinco){
                    dupla_cinco = true;
                }
                if(*(jogo+j)== seis){
                    dupla_seis = true;
                }
            }
            if(dupla_um and dupla_dois and dupla_tres and dupla_quatro and dupla_cinco and dupla_seis){
                esta_na_dupla = true;
            }
        } else {
            continue;
        }
        if(esta_na_dupla){
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[]){
    // Números do cartão
    int numeros_possiveis[25] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};

    // Números a analisar na cartela
    //int numeros_para_analise[] = {3,6,9,12,15,18,21};

    // Verificar as ocorrências 
    for(int i(0); i<25; ++i){
        for(int j(0); j<25; ++j){
            if(i==j){
                continue;
            }
            for(int k(j+1); k<25; ++k){
                if(i==k){
                    continue;
                }
                for(int l(k+1); l<25; ++l){
                    if(i==l){
                        continue;
                    }
                    for(int m(l+1); m<25; ++m){
                        if(i==m){
                            continue;
                        }
                        for(int n(m+1); n<25; ++n){
                            if(i==n){
                                continue;
                            }
                            for(int o(n+1); o<25; ++o){
                                if(i==o){
                                    continue;
                                }
                                if(cheke_dupla(numeros_possiveis[j],numeros_possiveis[k],numeros_possiveis[l],numeros_possiveis[m],numeros_possiveis[n],numeros_possiveis[o],numeros_possiveis[i])){
                                    //std::cout << "sim" << std::endl;
                                } else {
                                    std::cout << numeros_possiveis[i] << " - " << numeros_possiveis[j] << " . " << numeros_possiveis[k] << std::endl;
                                }
                            }
                        }
                    }
                }
            }
        }
    }    

    return 0;
}
