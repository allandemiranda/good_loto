#include <iostream>
#include <algorithm>
#include <omp.h> // sistemas paralelos -fopenmp
#include "../analise/numeros_sorteados.h" // Para as regras funcionarem

int main(void){
    int quantidade_de_jogos = (std::distance(std::begin(numeros_sorteados),std::end(numeros_sorteados))/15);
    for(int i=1; i<quantidade_de_jogos; ++i){
        int jogo[15];
        #pragma omp parallel for
        for(int j=0; j<15; ++j){
            jogo[j] = numeros_sorteados[(i*15)+j];
        }
        std::sort(std::begin(jogo), std::end(jogo));
        int jogo_analise[15];
        bool flag = false;
        for(int a=0; a<15; ++a){
            jogo_analise[0] = jogo[a];
            for(int b=a+1; b<15; ++b){
                jogo_analise[1] = jogo[b];
                for(int c=b+1; c<15; ++c){
                    jogo_analise[2] = jogo[c];
                    for(int d=c+1; d<15; ++d){
                        jogo_analise[3] = jogo[d];
                        for(int e=d+1; e<15; ++e){
                            jogo_analise[4] = jogo[e];
                            for(int f=e+1; f<15; ++f){
                                jogo_analise[5] = jogo[f];
                                for(int g=f+1; g<15; ++g){
                                    jogo_analise[6] = jogo[g];
                                    for(int h=g+1; h<15; ++h){
                                        jogo_analise[7] = jogo[h];
                                        for(int j=h+1; j<15; ++j){
                                            jogo_analise[8] = jogo[j];
                                            for(int k=j+1; k<15; ++k){
                                                jogo_analise[9] = jogo[k];
                                                for(int l=k+1; l<15; ++l){
                                                    jogo_analise[10] = jogo[l];
                                                    for(int m=l+1; m<15; ++m){
                                                        jogo_analise[11] = jogo[m];
                                                        for(int n=m+1; n<15; ++n){
                                                            jogo_analise[12] = jogo[n];
                                                            for(int o=n+1; o<15; ++o){
                                                                jogo_analise[13] = jogo[o];
                                                                for(int p=o+1; p<15; ++p){
                                                                    jogo_analise[14] = jogo[p];
                                                                    for(int ii=0; ii<i; ++ii){
                                                                        int contador = 0;
                                                                        int temp[15];
                                                                        #pragma omp parallel for
                                                                        for(int kk=0; kk<15; ++kk){
                                                                            temp[kk]=numeros_sorteados[(ii*15)+kk];
                                                                        }
                                                                        std::sort(std::begin(temp),std::end(temp));
                                                                        #pragma omp parallel for reduction(+ : contador)
                                                                        for(int jj=0; jj<std::distance(std::begin(jogo_analise),std::end(jogo_analise)); ++jj){                                                        
                                                                            if(std::binary_search(std::begin(temp),std::end(temp),jogo_analise[jj])){
                                                                                ++contador;
                                                                            }
                                                                        }
                                                                        if(contador == std::distance(std::begin(jogo_analise),std::end(jogo_analise))){
                                                                            std::cout << "Jogo " << i+1 << " tem " << std::distance(std::begin(jogo_analise),std::end(jogo_analise)) << " números que já saiu" << std::endl;
                                                                            flag = true;
                                                                            break;
                                                                        }
                                                                    }
                                                                    if(flag){
                                                                        break;
                                                                    }
                                                                }
                                                                if(flag){
                                                                    break;
                                                                }
                                                            }
                                                            if(flag){
                                                                break;
                                                            }
                                                        }
                                                        if(flag){
                                                            break;
                                                        }
                                                    }
                                                    if(flag){
                                                        break;
                                                    }
                                                }
                                                if(flag){
                                                    break;
                                                }
                                            }
                                            if(flag){
                                                break;
                                            }
                                        }
                                        if(flag){
                                            break;
                                        }
                                    }
                                    if(flag){
                                        break;
                                    }
                                }
                                if(flag){
                                    break;
                                }
                            }
                            if(flag){
                                break;
                            }
                        }
                        if(flag){
                            break;
                        }
                    }
                    if(flag){
                        break;
                    }
                }
                if(flag){
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        if(!flag){
            std::cout << "Jogo " << i+1 << " OK" << std::endl;
        }
    }
}