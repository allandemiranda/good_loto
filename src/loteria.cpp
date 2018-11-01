/**
 * @file loteria.cpp
 * @author Allan de Miranda Silva
 * @brief 
 * @version 1.0
 * @date 2018-10-31
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#include <vector>
#include <stdexcept>

#include "../include/loteria.h"

unsigned long long int loteria::criar_volante(unsigned short int numero_inicial, unsigned short int numero_final){
    // pegar numero inicial e adicionar ele ao volante até chegar o número final inclusive
    numeros_do_volante.clear();
    unsigned long long int contador(0);
    for(unsigned short int numero = numero_inicial; numero_inicial<=numero_final; ++numero){
        numeros_do_volante.push_back(numero);
        ++contador;
    }
    return contador; // retornar quantidade de números adicionados ao volante
}

void loteria::editar_quantidade_numeros_jogados(unsigned short int quantidade){
    quantidade_numeros_jogados = quantidade;
    if(quantidade_numeros_sorteados == 0){
        editar_quantidade_numeros_sorteados(quantidade);
    }
}

void loteria::editar_quantidade_numeros_sorteados(unsigned short int quantidade){
    quantidade_numeros_sorteados = quantidade;
}

void loteria::editar_valor_da_aposta(float money){
    valor_da_aposta = money;
}

void loteria::adicionar_jogo_possivel_ao_volante(std::vector <unsigned short int> novo_jogo){
    jogos_totais_do_volante.push_back(novo_jogo);
}

unsigned short int loteria::verificar_quantidade_numeros_sorteados(void){
    return quantidade_numeros_sorteados;
}

unsigned short int loteria::verificar_quantidade_numeros_jogados(void){
    return quantidade_numeros_jogados;
}

unsigned short int loteria::verificar_quantidade_numeros_do_volante(void){
    return numeros_do_volante.size();
}

float loteria::verificar_valor_da_aposta(void){
    return valor_da_aposta;
}

unsigned long long int loteria::verificar_quantidade_jogos_totais_do_volante(void){
    return jogos_totais_do_volante.size();
}

std::vector <unsigned short int> loteria::veriticar_numeros_do_volante(void){
    return numeros_do_volante;
}

unsigned long long int loteria::verificar_quantidade_jogos_totais_sorteados(void){
    return jogos_sorteados.size();
}

std::vector <unsigned short int> loteria::veriticar_jogo_sorteado(unsigned long long int numero_do_jogo){
    if((numero_do_jogo == 0) or (numero_do_jogo>jogos_sorteados.size())){
        throw std::runtime_error( "Erro ao tentar obter um jogo sorteado inexistente" );
    } else {
        --numero_do_jogo; // Correção para o número certo, pois inicia em 1 e o vetor em 0
        return jogos_sorteados[numero_do_jogo];
    }
}

void loteria::adicionar_jogo_sorteado(std::vector <unsigned short int> jogo_sorteado){
    if(jogo_sorteado.size() != quantidade_numeros_sorteados){
        throw std::runtime_error( "Erro de compatibilidade ao tentar adicionar um jogo sorteado" );
    } else {
        jogos_sorteados.push_back(jogo_sorteado);
    }
}