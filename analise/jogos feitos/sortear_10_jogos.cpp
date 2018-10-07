/**
 * @file sortear_10_jogos.cpp
 * @author Allan de Miranda Silva
 * @brief Programa para sortear 10 jogos na série de fibonacci dentro dos possiveis a sortear
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
#include <omp.h> // sistemas paralelos
#include <cstdlib>
#include <ctime>

int main(int argc, char const *argv[])
{
    //Pegar valores do vetor
    std::vector <int> jogos_certos;
    std::ifstream ifs("../../jogos_certos_1717.txt");
	int val;
    std::cout << "Criando vetor com jogos" << std::endl;
	while (ifs >> val) {
		jogos_certos.push_back(val);
	}
	ifs.close();
    std::cout << "Vetor com jogos criado" << std::endl;

    int quantidade_de_jogos_total = (jogos_certos.size()/15);

    //int fibonacci_numeros[10] = {1,2,4,7,12,20,33,54,88,143}; 
    int fibonacci_numeros[10] = {55,89,110,123,131,136,139,141,142,143}; 
    int calculo_fibonacci[10];

    // calculos fibonacci
    for(int i=0; i<10; ++i){
        int intervalo = ((fibonacci_numeros[i]*quantidade_de_jogos_total)/143);
        calculo_fibonacci[i] = intervalo;
    }

    std::srand(std::time(nullptr));

    // gerar respostas
    std::cout << "JOGOS SORTEADOS" << std::endl;
    int jogo_analisado = 0;
    for(int i(0); i<10; ++i){
        int x = jogo_analisado + std::rand()/((RAND_MAX + 1u)/(calculo_fibonacci[i]-1));
        while(false == ((x>=jogo_analisado) and (x<calculo_fibonacci[i]))){
            x = jogo_analisado + std::rand()/((RAND_MAX + 1u)/(calculo_fibonacci[i]-1));
        }
        std::cout << x << " - ";
        for(int j(0); j<15; ++j){
            std::cout << (jogos_certos[(x*15)+j]) << " ";
        }
        std::cout << std::endl;
        jogo_analisado = calculo_fibonacci[i];
    }
    std::cout << std::endl;

    return 0;
}
