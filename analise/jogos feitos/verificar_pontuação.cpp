/**
 * @file verificar_pontuação.cpp
 * @author Allan de Miranda Silva
 * @brief Aqui vocÊ pode verificar seu jogo, recebendo como análise a quantidade de pontos que ele
 *          poderia está fazendo com todos os jogos possiveis de sair da listas de jogos certos txt
 * @version 0.1
 * @date 12-10-2018
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <vector>
#include <omp.h> // sistemas paralelos -fopenmp

int main(int argc, char const *argv[])
{
    std::vector <int> jogos_possiveis;
	std::ifstream ifs("../../src/jogos_certos.txt");
	int val;
    std::cout << "Criando vetor com jogos" << std::endl;
	while (ifs >> val) {
		jogos_possiveis.push_back(val);
	}
	ifs.close();
    std::cout << "Vetor com jogos criado" << std::endl;

    
    std::vector <std::vector <int>> auxi = {
        {2,
3,
5,
6,
7,
8,
9,
10,
11,
12,
14,
15,
17,
21,
22}
    };

    for(int jogo_a(0); jogo_a<auxi.size(); jogo_a++){
        
        int jogo[15];
        for(int jogo_b(0); jogo_b<auxi[jogo_a].size(); ++jogo_b){
            jogo[jogo_b]=auxi[jogo_a][jogo_b];
        }

        std::sort(std::begin(jogo), std::end(jogo));

        std::cout << "Analisando jogo: " << std::endl;
        for(int i : jogo){
            std::cout << i << " ";
        }
        std::cout << std::endl;

        std::cout << "Analisando vetor com jogo" << std::endl;
        std::vector <int> analise;
        for(int i=0; i<jogos_possiveis.size(); i+=15){
            int pontos=0;     
            #pragma omp parallel for reduction(+ : pontos)
            for(int j=0; j<(15); ++j){
                if(std::binary_search(std::begin(jogo), std::end(jogo), jogos_possiveis[i+j])){
                    ++pontos;
                }
            } 
            analise.push_back(pontos);
        }
        std::cout << "Vetor com jogo analisado" << std::endl;
        std::cout << "Ordenando vetor com jogo" << std::endl;
        std::sort(analise.begin(), analise.end());
        std::cout << "Vetor com jogos ordenado" << std::endl;
        std::cout << "Contando ocoorências" << std::endl;
        for(int i(0); i<=15; ++i){
            int contador(0);
            for(int j : analise){
                if(i == j){
                    ++contador;
                } else {
                    if(i < j){
                        break;
                    }
                }
            }
            std::cout << "Para " << i << " pontos -> " << contador << " ocorrências" << std::endl;
        }
        std::cout << "Ocoorências contadas" << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
    }
    return 0;
}
