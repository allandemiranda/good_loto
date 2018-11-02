/**
 * @file verificador.cpp
 * @author Allan de Miranda (allandemiranda@gmail.com)
 * @brief 
 * @version 1.0
 * @date 2018-11-02
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <omp.h> // sistemas paralelos -fopenmp

#include "../include/loteria.h"
#include "../include/regras.h"
#include "../include/verificador.h"

bool verificador::verificador_de_regras(std::vector <unsigned short int> jogo, loteria modalidade, regras filtro){
    if(!r_soma(jogo, modalidade, filtro)){
        return false;
    }
    if(!r_pares_impares(jogo, modalidade, filtro)){
        return false;
    }
    if(!r_sequencia(jogo, modalidade, filtro)){
        return false;
    }
    if(!r_primo(jogo, modalidade, filtro)){
        return false;
    }
    if(!r_multiplo_3(jogo, modalidade, filtro)){
        return false;
    }
    if(!r_fibonacci(jogo, modalidade, filtro)){
        return false;
    }
    if(!r_dezena_repetida(jogo, modalidade, filtro)){
        return false;
    }
    return true;
}

bool verificador::r_dezena_repetida(std::vector <unsigned short int> jogo, loteria modalidade, regras filtro){
    unsigned short int soma = 0;
    auto tamamnho = modalidade.verificar_quantidade_jogos_totais_sorteados();
    --tamamnho;
    #pragma omp parallel for reduction(+ : soma)
    for(auto i=0; i<modalidade.verificar_quantidade_numeros_sorteados(); ++i){
        if(std::binary_search(jogo.begin(), jogo.end(), modalidade.veriticar_jogo_sorteado(tamamnho)[i])){
            #pragma omp critical
            {
                ++soma;
            }
        }
    }
    if(std::binary_search(filtro.v_analisar_dezenas_repetidas().begin(), filtro.v_analisar_dezenas_repetidas().end(), soma)){
        return true;
    } else {
        return false;
    }
}

bool verificador::r_fibonacci(std::vector <unsigned short int> jogo, loteria modalidade, regras filtro){
    unsigned short int soma = 0;
    #pragma omp parallel for reduction(+ : soma)
    for(auto i=0; i<filtro.v_analisar_fibonacci().size(); ++i){
        if(std::binary_search(jogo.begin(), jogo.end(), filtro.v_analisar_fibonacci()[i])){
            #pragma omp critical
            {
                ++soma;
            }
        }
    }
    if(std::binary_search(filtro.v_analisar_fibonacci().begin(), filtro.v_analisar_fibonacci().end(), soma)){
        return true;
    } else {
        return false;
    }
}

bool verificador::r_multiplo_3(std::vector <unsigned short int> jogo, loteria modalidade, regras filtro){
    unsigned short int soma = 0;
    #pragma omp parallel for reduction(+ : soma)
    for(auto i=0; i<filtro.v_analisar_multiplos_3().size(); ++i){
        if(std::binary_search(jogo.begin(), jogo.end(), filtro.v_analisar_multiplos_3()[i])){
            #pragma omp critical
            {
                ++soma;
            }
        }
    }
    if(std::binary_search(filtro.v_analisar_multiplos_3().begin(), filtro.v_analisar_multiplos_3().end(), soma)){
        return true;
    } else {
        return false;
    }
}

bool verificador::r_primo(std::vector <unsigned short int> jogo, loteria modalidade, regras filtro){
    unsigned short int soma = 0;
    #pragma omp parallel for reduction(+ : soma)
    for(auto i=0; i<filtro.v_analisar_primos().size(); ++i){
        if(std::binary_search(jogo.begin(), jogo.end(), filtro.v_analisar_primos()[i])){
            #pragma omp critical
            {
                ++soma;
            }
        }
    }
    if(std::binary_search(filtro.v_analisar_primos().begin(), filtro.v_analisar_primos().end(), soma)){
        return true;
    } else {
        return false;
    }
}

bool verificador::r_sequencia(std::vector <unsigned short int> jogo, loteria modalidade, regras filtro){
    unsigned short int soma = 0;
    #pragma omp parallel for reduction(+ : soma)
    for(auto i=0; i<filtro.v_analisar_sequencia().size(); ++i){
        if(std::binary_search(jogo.begin(), jogo.end(), filtro.v_analisar_sequencia()[i])){
            #pragma omp critical
            {
                ++soma;
            }
        }
    }
    if(std::binary_search(filtro.v_analisar_sequencia().begin(), filtro.v_analisar_sequencia().end(), soma)){
        return true;
    } else {
        return false;
    }
}

bool verificador::r_pares_impares(std::vector <unsigned short int> jogo, loteria modalidade, regras filtro){
    unsigned short int soma = 0;
    #pragma omp parallel for reduction(+ : soma)
    for(auto i=0; i<jogo.size(); ++i){
        if((jogo[i]%2)==0){
            #pragma omp critical
            {
                ++soma;
            }
        }
    }
    for(auto i(0); i<filtro.v_analisar_pares_impares().size(); ++i){
        if(soma == filtro.v_analisar_pares_impares()[i][0]){
            return true;
        }
    }
    return false;
}

bool verificador::r_soma(std::vector <unsigned short int> jogo, loteria modalidade, regras filtro){
    unsigned short int soma = 0;
    #pragma omp parallel for reduction(+ : soma)
    for(auto i=0; i<jogo.size(); ++i){
        #pragma omp critical
        {
            soma += jogo[i];
        }
    }
    if(std::binary_search(filtro.v_analisar_soma().begin(), filtro.v_analisar_soma().end(), soma)){
        return true;
    } else {
        return false;
    }
}

verificador::verificador(loteria modalidade, regras filtro){
    std::cout << "Iniciando a verificação de " << modalidade.verificar_quantidade_jogos_totais_do_volante();
    std::cout << " jogos possíveis de sair" << std::endl;
    std::vector <std::vector <unsigned short int>> todos_jogos = modalidade.verificar_o_jogos_totais_do_volante();
    #pragma omp parallel for
    for(auto i = 0; i<todos_jogos.size(); ++i){
        if(!verificador_de_regras(todos_jogos[i], modalidade, filtro)){
            todos_jogos[i].clear();
        }
    }
    std::cout << "Jogos possiveis de sair analizados" << std::endl;
    unsigned long int contador = 0;
    #pragma omp parallel for reduction(+ : contador)
    for(auto i = 0; i<todos_jogos.size(); ++i){
        if(todos_jogos[i].size() == modalidade.verificar_quantidade_numeros_sorteados()){
            #pragma omp critical
            {
                ++contador;
            }
        }
    }
    std::cout << "Foram gerados " << contador << " jogos possiveis de sair" << std::endl;
    for(auto i(0); i<todos_jogos.size(); ++i){
        if(todos_jogos[i].size() == modalidade.verificar_quantidade_numeros_sorteados()){
            jogos_corretos.push_back(todos_jogos[i]);
        }
    }
    std::cout << "Jogos possiveis de sair montados" << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;
}

std::vector<std::vector <unsigned short int>> verificador::retornar_jogos_certos(void){
    return jogos_corretos;
}