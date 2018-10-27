#include <iostream>
#include <algorithm>
#include <omp.h> // sistemas paralelos -fopenmp
#include "../analise/numeros_sorteados.h" // Para as regras funcionarem

int main(void){
    int jogo = 1;
    for(int *i = std::end(numeros_sorteados)-15; i>=std::begin(numeros_sorteados)+15; i-=15){
        std::cout << jogo << std::endl;
        int vetor[15];
        #pragma omp parallel for
        for(int j=0; j<15; ++j){
            vetor[j] = *(i+j);
        }
        std::sort(std::begin(vetor), std::end(vetor));
        for(int *j = std::begin(numeros_sorteados); j<i; j+=15){
            int vetor_dois[15];
            #pragma omp parallel for
            for(int k=0; k<15; ++k){
                vetor_dois[k] = *(j+k);
            }
            std::sort(std::begin(vetor_dois),std::end(vetor_dois));
            int contador = 0;
            #pragma omp parallel for reduction(+ : contador)
            for(int *k = std::begin(vetor_dois); k<std::end(vetor_dois); ++k){
                if(std::binary_search(std::begin(vetor),std::end(vetor), *k)){
                    ++contador;
                }
            }
            if(contador == 15){
                std::cout << " AQUI TEM 15 IGUAIS" << std::endl;
            }
        }
        jogo++;
    }
}