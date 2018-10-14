/**
 * @file sortear_10_jogos.cpp
 * @author Allan de Miranda Silva
 * @brief Programa para sortear 10 jogos Harmonicamente
 * @version 0.1
 * @date 06-10-2018
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <vector>
//#include <omp.h> // sistemas paralelos
#include <cstdlib>
#include <ctime>

bool analise_14_pontos(std::vector <int> &jogos, int numero_do_jogo){
    int temp_jogo[15];
    for(int i(0); i<15; ++i){
        temp_jogo[i] = jogos[(numero_do_jogo*15)+i];
    }
    int pontos_maiores(0);
    for(int i(0); i<(jogos.size()/15); ++i){
        int pontos_atual(0);
        for(int j(0); j<15; ++j){
            if(std::binary_search(std::begin(temp_jogo), std::end(temp_jogo), jogos[(i*15)+j])){
                ++pontos_atual;
            } else {
                if((j>=1) and (pontos_atual>=j)){
                    break;
                }
            }
        }
        if(pontos_atual>=14){
            ++pontos_maiores;
            if(pontos_maiores>100){
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    //Pegar valores do vetor
    std::vector <int> jogos_certos;
    std::ifstream ifs("../../src/jogos_certos.txt");
	int val;
    std::cout << "Criando vetor com jogos" << std::endl;
	while (ifs >> val) {
		jogos_certos.push_back(val);
	}
	ifs.close();
    std::cout << "Vetor com jogos criado" << std::endl;

    int quantidade_de_jogos_total = (jogos_certos.size()/15);

    int calculo[10];

    // calculos fibonacci
    int calculo_harmonico[10];
    int calculo_inicial = 0;
    for(int i=0; i<10; ++i){
        int intervalo = quantidade_de_jogos_total/10;
        calculo_harmonico[i] = intervalo + calculo_inicial;
        calculo_inicial = calculo_harmonico[i];
    }

    std::srand(std::time(nullptr));

    // gerar respostas
    std::cout << "JOGOS SORTEADOS" << std::endl;
    int jogo_analisado = 0;
    for(int i(0); i<10; ++i){
        int x = jogo_analisado + std::rand()/((RAND_MAX + 1u)/(calculo_harmonico[i]-1));
        while(false == ((x>=jogo_analisado) and (x<calculo_harmonico[i]))){
            x = jogo_analisado + std::rand()/((RAND_MAX + 1u)/(calculo_harmonico[i]-1));
        }
        while(false == analise_14_pontos(jogos_certos,x)){
            while(false == ((x>=jogo_analisado) and (x<calculo_harmonico[i]))){
                x = jogo_analisado + std::rand()/((RAND_MAX + 1u)/(calculo_harmonico[i]-1));
            }
        }        
        //std::cout << x << " - ";
        std::cout << "{";
        for(int j(0); j<15; ++j){
            std::cout << (jogos_certos[(x*15)+j]) << ", ";
        }
        std::cout << "}," << std::endl;
        jogo_analisado = calculo_harmonico[i];
        
    }
    std::cout << std::endl;

    return 0;
}
