/**
 * @file sortear_10_jogos.cpp
 * @author Allan de Miranda Silva
 * @brief Programa para provar a unição dos 3 métodos de sorteio criados
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

    // Jogo correto
    int jogo_correto[15] = {8,21,15,14,9,3,22,10,24,23,4,5,1,11,7};
    std::sort(std::begin(jogo_correto), std::end(jogo_correto));

    int quantidade_de_jogos_total = (jogos_certos.size()/15);

    #pragma omp parallel
    { 
        #pragma omp sections
        { 
            #pragma omp section
            {               

                // calculos harmonico
                int calculo_harmonico[10];
                int calculo_inicial = 0;
                for(int i=0; i<10; ++i){
                    int intervalo = quantidade_de_jogos_total/10;
                    calculo_harmonico[i] = intervalo + calculo_inicial;
                    calculo_inicial = calculo_harmonico[i];
                }

                std::srand(std::time(nullptr));

                // gerar respostas
                while(true){
                    int jogo_analisado = 0;
                    for(int i(0); i<10; ++i){
                        std::time_t result_um = std::time(nullptr);
                        int x = jogo_analisado + std::rand()/((RAND_MAX + 1u)/(calculo_harmonico[i]-1));
                        while(false == ((x>=jogo_analisado) and (x<calculo_harmonico[i]))){
                            x = jogo_analisado + std::rand()/((RAND_MAX + 1u)/(calculo_harmonico[i]-1));
                        }
                        bool flag = false;
                        for(int j(0); j<15; ++j){
                            if((jogos_certos[(x*15)+j])!=jogo_correto[j]){
                                flag = true;
                                break;
                            }
                        }
                        if(flag){
                            jogo_analisado = calculo_harmonico[i];
                            continue;
                        } else {
                            std::cout << "HARMONICO" << std::asctime(std::localtime(&result_um)) << std::endl;
                            std::cout << x << " - ";
                            for(int j(0); j<15; ++j){
                                std::cout << (jogos_certos[(x*15)+j]) << " ";
                            }
                            std::cout << std::endl;
                            #pragma omp cancel sections
                        }                    
                    }
                }
                
            }
            #pragma omp section
            {
                // invertifo fibonacci

                int fibonacci_numeros_inver[10] = {55,89,110,123,131,136,139,141,142,143}; 
                int calculo_fibonacci_inver[10];

                // calculos fibonacci
                for(int i=0; i<10; ++i){
                    int intervalo = ((fibonacci_numeros_inver[i]*quantidade_de_jogos_total)/143);
                    calculo_fibonacci_inver[i] = intervalo;
                }

                std::srand(std::time(nullptr));

                // gerar respostas
                while(true){
                    int jogo_analisado = 0;
                    for(int i(0); i<10; ++i){
                        std::time_t result_um = std::time(nullptr);
                        int x = jogo_analisado + std::rand()/((RAND_MAX + 1u)/(calculo_fibonacci_inver[i]-1));
                        while(false == ((x>=jogo_analisado) and (x<calculo_fibonacci_inver[i]))){
                            x = jogo_analisado + std::rand()/((RAND_MAX + 1u)/(calculo_fibonacci_inver[i]-1));
                        }
                        bool flag = false;
                        for(int j(0); j<15; ++j){
                            if((jogos_certos[(x*15)+j])!=jogo_correto[j]){
                                flag = true;
                                break;
                            }
                        }
                        if(flag){
                            jogo_analisado = calculo_fibonacci_inver[i];
                            continue;
                        } else {
                            std::cout << "INVERTIDO" << std::asctime(std::localtime(&result_um)) << std::endl;
                            std::cout << x << " - ";
                            for(int j(0); j<15; ++j){
                                std::cout << (jogos_certos[(x*15)+j]) << " ";
                            }
                            std::cout << std::endl;
                            #pragma omp cancel sections
                        }
                    }
                }
            }
            #pragma omp section
            {
                // fibonacci normal 

                int fibonacci_numeros[10] = {1,2,4,7,12,20,33,54,88,143}; 
                int calculo_fibonacci[10];

                // calculos fibonacci
                for(int i=0; i<10; ++i){
                    int intervalo = ((fibonacci_numeros[i]*quantidade_de_jogos_total)/143);
                    calculo_fibonacci[i] = intervalo;
                }

                std::srand(std::time(nullptr));

                // gerar respostas
                while(true){
                    int jogo_analisado = 0;
                    for(int i(0); i<10; ++i){
                        std::time_t result_um = std::time(nullptr);
                        int x = jogo_analisado + std::rand()/((RAND_MAX + 1u)/(calculo_fibonacci[i]-1));
                        while(false == ((x>=jogo_analisado) and (x<calculo_fibonacci[i]))){
                            x = jogo_analisado + std::rand()/((RAND_MAX + 1u)/(calculo_fibonacci[i]-1));
                        }
                        bool flag = false;
                        for(int j(0); j<15; ++j){
                            if((jogos_certos[(x*15)+j])!=jogo_correto[j]){
                                flag = true;
                                break;
                            }
                        }
                        if(flag){
                            jogo_analisado = calculo_fibonacci[i];
                            continue;
                        } else {
                            std::cout << "NORMAL FIBO" << std::asctime(std::localtime(&result_um)) << std::endl;
                            std::cout << x << " - ";
                            for(int j(0); j<15; ++j){
                                std::cout << (jogos_certos[(x*15)+j]) << " ";
                            }
                            std::cout << std::endl;
                            #pragma omp cancel sections
                        }
                    }
                }
            }
        }
    }

    return 0;
}
