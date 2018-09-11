#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <cmath>

size_t rebobinar(int estagio_final, int estagio_atual = 0, size_t soma = 0){
    // Chave de segurança para limite de bits
    if(estagio_final > 10){
        return 0;
    }

    size_t total(0);

    if((soma == 0) and (estagio_atual == 0)){
        std::cout << soma << std::endl;
        total++;
    }

    if(estagio_atual < estagio_final - 1){
        total += rebobinar(estagio_final, estagio_atual + 1, soma);
    }    

    soma += std::pow(10, estagio_atual);
    std::cout << soma << std::endl;
    total++;
    if(estagio_atual < estagio_final - 1){
        total += rebobinar(estagio_final, estagio_atual + 1, soma);
    }
       
    return total;
}

int main(int argc, char *argv[ ]){
    
    auto aqui = rebobinar(4);
    std::cout << aqui << std::endl; 

    return 0;
}