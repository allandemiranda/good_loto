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
#include <string>
#include <fstream>
#include <stdexcept>

#include "../include/loteria.h"

#include "../include/combinacoes.h"

loteria::loteria(std::string file_name){
    std::vector <float> vetor;
    std::string route = "../data/modalidade_"; 
        route = route + file_name; 
        route = route + ".txt"; 
    route = route + file_name; 
    std::ifstream teste(route);
    float valuer_test;
    if(!teste.good()){
        throw std::runtime_error( "Erro ao ler arquivo de modalidade" );
    }
    while( teste >> valuer_test ){
        if(valuer_test < 0){
            throw std::runtime_error( "Erro ao ler arquivo de modalidade" );
        }
    }
    teste.close();
    std::ifstream ifs(route);
    float valuer;
    while( ifs >> valuer ){
        vetor.push_back(valuer);
    }
    ifs.close();
    if(!gerar_modalidade(vetor, file_name)){
        throw std::runtime_error( "Erro ao adicionar modalidade" );
    }
}

bool loteria::gerar_modalidade(std::vector <float> vetor_modalidade, std::string file_name){
    if(vetor_modalidade.size() != 5){
        return false;
    }
    unsigned short int numero_da_regra(1);
    for(auto i(0); i<vetor_modalidade.size(); ++i){
        bool indicador(false);
        if(numero_da_regra == 1){
            indicador = criar_volante((unsigned short int)vetor_modalidade[i], (unsigned short int)vetor_modalidade[i+1]);
            ++i;
        } else {
            if(numero_da_regra == 2){
                indicador = editar_quantidade_numeros_jogados((unsigned short int)vetor_modalidade[i]);
            } else {
                if(numero_da_regra == 3){
                    indicador = editar_quantidade_numeros_sorteados((unsigned short int)vetor_modalidade[i]);
                } else {
                    if(numero_da_regra == 4){
                        indicador = editar_valor_da_aposta((unsigned short int)vetor_modalidade[i]);
                    }
                }
            }
        }
        if(!indicador){
            return false;
        } else {
            ++numero_da_regra;
        }
    }

    combinacoes nova_combinacao(numeros_do_volante, quantidade_numeros_jogados);
    for(auto i(1); i<=nova_combinacao.quantidade(); ++i){
        adicionar_jogo_possivel_ao_volante(nova_combinacao.combinacao(i));
    }


// adicionar o vetor com jogos sorteados

    std::vector <unsigned short int> vetor;
    std::string route = "../data/jogos_sorteados_"; 
        route = route + file_name; 
        route = route + ".txt"; 
    route = route + file_name; 
    std::ifstream teste(route);
    unsigned short int valuer_test;
    if(!teste.good()){
        throw std::runtime_error( "Erro ao ler arquivo de jogos sorteados" );
    }
    while( teste >> valuer_test ){
        if(valuer_test < 0){
            throw std::runtime_error( "Erro ao ler arquivo de jogos sorteados" );
        }
    }
    teste.close();
    std::ifstream ifs(route);
    unsigned short int valuer;
    while( ifs >> valuer ){
        vetor.push_back(valuer);
    }
    ifs.close();
    for(auto i(0); i<(vetor.size()/quantidade_numeros_sorteados); ++i){
        std::vector <unsigned short int> temp_sorteado_now;
        for(auto j(0); j<quantidade_numeros_sorteados; ++j){
            temp_sorteado_now.push_back(vetor[(i*quantidade_numeros_sorteados)+j]);
        }
        jogos_sorteados.push_back(temp_sorteado_now);
    }

    return true;
}

bool loteria::criar_volante(unsigned short int numero_inicial, unsigned short int numero_final){
    if(numero_final <= numero_inicial){
        return false;
    } else {
        numeros_do_volante.clear();
        for(unsigned short int numero = numero_inicial; numero_inicial<=numero_final; ++numero){
            numeros_do_volante.push_back(numero);
        }
        return true;
    }
}

bool loteria::editar_quantidade_numeros_jogados(unsigned short int quantidade){
    if(quantidade == 0){
        return false;
    } else {
        if(numeros_do_volante.size() == 0){
            throw std::runtime_error( "Necessário configurar o volante antes" );
        } else {
            if(quantidade > numeros_do_volante.size()){
                return false;
            } else {
                quantidade_numeros_jogados = quantidade;
                if(quantidade_numeros_sorteados == 0){
                    editar_quantidade_numeros_sorteados(quantidade);
                    return true;
                } else {
                    return true;
                }
            }
        }
    }
}

bool loteria::editar_quantidade_numeros_sorteados(unsigned short int quantidade){ 
    if(quantidade == 0){
        return false;
    } else {
        quantidade_numeros_sorteados = quantidade;
        return true;
    }
}

bool loteria::editar_valor_da_aposta(float money){
    if(money < 0){
        return false;
    } else {
        valor_da_aposta = money;
        return true;
    }
}

void loteria::adicionar_jogo_possivel_ao_volante(std::vector <unsigned short int> novo_jogo){
    if(novo_jogo.size() != quantidade_numeros_jogados){
        throw std::runtime_error( "Erro ao adicionar novo jogo possivel" );
    } else {
        jogos_totais_do_volante.push_back(novo_jogo);
    }
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