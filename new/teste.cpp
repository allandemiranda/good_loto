#include <iostream>
#include <vector>
#include <algorithm>
#include <omp.h> // sistemas paralelos -fopenmp
#include "../analise/numeros_sorteados.h" // Para as regras funcionarem

int main(){
    std::vector <int> analise;
    for(int *i = std::begin(numeros_sorteados); i<std::end(numeros_sorteados); i+=15){
        int vetor[15];
        for(int k(0); k<15; ++k){
            vetor[k] = *(i+k);
        }
        std::sort(std::begin(vetor),std::end(vetor));
        int sequencia(0);
        int maior_sequencia(0);
        for(int j(0); j<15; ++j){
            if((vetor[j]+1)==(vetor[j+1])){
                ++sequencia;
            } else {
                maior_sequencia = sequencia;
                sequencia = 0;
            }
        }
        analise.push_back(maior_sequencia);
    }
    

    for(int i=0; i<=15; ++i){
        int contador(0);
        for(int j : analise){
            if(j==i){
                ++contador;
            }
        }
        std::cout << i << " - " << contador << std::endl;
    }
}