#include <iostream>
#include <algorithm>
#include <omp.h> // sistemas paralelos -fopenmp
#include "../analise/numeros_sorteados.h" // Para as regras funcionarem

int main(void){
    int jjj = 1727;
    for(int *busca_um = std::end(numeros_sorteados)-15; busca_um>=std::begin(numeros_sorteados)+15; busca_um-=15){
        std::cout << jjj << std::endl;
        int vetor[9];
        for(int * _a = busca_um; _a<=busca_um+15; ++_a){
            vetor[0] = *_a;
            for(int * _b = _a+1; _b<=busca_um+15; ++_b){
                vetor[1] = *_b;
                for(int * _c = _b+1; _c<=busca_um+15; ++_c){
                    vetor[2] = *_c;
                    for(int * _d = _c+1; _d<=busca_um+15; ++_d){
                        vetor[3] = *_d;
                        for(int * _e = _d+1; _e<=busca_um+15; ++_e){
                            vetor[4] = *_e;
                            for(int * _f = _e+1; _f<=busca_um+15; ++_f){
                                vetor[5] = *_f;
                                for(int * _g = _f+1; _g<=busca_um+15; ++_g){
                                    vetor[6] = *_g;
                                    for(int * _h = _g+1; _h<=busca_um+15; ++_h){
                                        vetor[7] = *_h;
                                        for(int * _i = _h+1; _i<=busca_um+15; ++_i){
                                            vetor[8] = *_i;
                                            
                                                for(int * busca_dois = std::begin(numeros_sorteados); busca_dois<busca_um; busca_dois+=15){
                                                    int contador = 0;
                                                    #pragma omp parallel for reduction(+ : contador)
                                                    for(int busca_tres=0; busca_tres<std::distance(std::begin(vetor),std::end(vetor)); ++busca_tres){
                                                        if(std::binary_search(busca_dois, busca_dois+15, vetor[busca_tres])){
                                                            ++contador;
                                                        }
                                                    }
                                                    if(contador == std::distance(std::begin(vetor),std::end(vetor))){
                                                        std::cout << "No " << jjj << " Existe " << contador << " numros que foi sorteado e saiu antes" << std::endl;
                                                        break;
                                                    }
                                                }                                              
                                            
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        jjj--;
    }
}