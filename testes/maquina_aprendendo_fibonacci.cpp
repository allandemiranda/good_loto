/**
 * @file maquina_aprendendo_fibonacci.cpp
 * @author Allan de Miranda Silva
 * @brief Sistema para identificar aprendizagem de máquina na regra fibonacci
 * @version 0.1
 * @date 19-10-2018
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <omp.h> // sistemas paralelos -fopenmp

#include "../analise/numeros_sorteados.h"

int main(int argc, char const *argv[])
{
    int numeros_para_analise[5]; /// verificar sempre a quantidade aqui
    std::vector <int> resultados;
    for(int a = 1; a<=25; ++a){
        numeros_para_analise[0] = a;
        for(int b = a + 1; b<=25; ++b){
            numeros_para_analise[1] = b;
            for(int c = b + 1; c<=25; ++c){
                numeros_para_analise[2] = c;
                for(int d = c + 1; d<=25; ++d){
                    numeros_para_analise[3] = d;
                    for(int e = d + 1; e<=25; ++e){
                        numeros_para_analise[4] = e;                                                    
                        std::vector <int> analise;
                        for(int *i = std::begin(numeros_sorteados); i<std::end(numeros_sorteados); i+=15){
                            int contador = 0;
                            #pragma omp parallel for reduction(+ : contador)
                            for(int j=0; j<std::distance(std::begin(numeros_para_analise), std::end(numeros_para_analise)); ++j){
                                if(std::binary_search(i,(i+15),numeros_para_analise[j])){
                                    ++contador;
                                }
                            }
                            analise.push_back(contador);
                        }                            
                        for(int i = 0; i<=std::distance(std::begin(numeros_para_analise), std::end(numeros_para_analise)); ++i){
                            int contador_novo = 0;
                            #pragma omp parallel for reduction(+ : contador_novo)
                            for( int j = 0; j<analise.size(); ++j){
                                if(i == analise[j]){
                                    ++contador_novo;
                                }
                            }
                            std::cout << contador_novo << " ";
                        } 
                        std::cout << " & ";
                        for(int i : numeros_para_analise){
                            std::cout << i << " ";
                        }                  
                        std::cout << std::endl;                        
                    }
                }
            }
        }
    } 
    
    return 0;
}
