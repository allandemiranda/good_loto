/**
 * @brief Função para gerar binários quando necessário
 * 
 * @file gerar_binarios.cpp
 * @author Allan de Miranda Silva
 * @date 11-09-2018
 */
#include <iostream>
#include <iterator>
#include <algorithm>
#include <cmath>

/**
 * @brief Função bobiná os binários solicitados
 * 
 * @param estagio_final Tamanho do binário
 * @param estagio_atual Zero
 * @param soma Zero
 * @return size_t Retorna quantos binários existem
 */
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

/**
 * @brief 
 * 
 * @param argc 
 * @param argv Número de bits para ter no binário
 * @return int 
 */
int main(int argc, char *argv[ ]){
    
    auto aqui = rebobinar(atoi(argv[1]));
    std::cout << aqui << std::endl; 

    return 0;
}