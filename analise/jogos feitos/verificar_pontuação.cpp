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
	//std::ifstream ifs("../../src/jogos_certos.txt");
    std::ifstream ifs("jogos_certos_1718.txt");
	int val;
    std::cout << "Criando vetor com jogos" << std::endl;
	while (ifs >> val) {
		jogos_possiveis.push_back(val);
	}
	ifs.close();
    std::cout << "Vetor com jogos criado" << std::endl;

    
    std::vector <std::vector <int>> auxi = {
        {1, 2, 3, 4, 8, 9, 10, 11, 13, 15, 17, 18, 20, 22, 24},
        {1, 2, 3, 6, 7, 8, 10, 11, 12, 13, 16, 17, 19, 20, 23},
        {1, 2, 5, 8, 10, 11, 12, 14, 15, 17, 19, 20, 21, 22, 23},
        {1, 3, 4, 6, 11, 12, 13, 14, 16, 17, 18, 20, 22, 24, 25},
        {1, 3, 5, 6, 7, 9, 11, 12, 16, 17, 19, 21, 23, 24, 25},
        {1, 4, 6, 7, 8, 9, 11, 12, 13, 15, 17, 18, 19, 20, 24},
        {2, 3, 6, 7, 8, 9, 11, 12, 14, 16, 17, 18, 19, 22, 25},
        {2, 3, 6, 9, 10, 11, 13, 16, 17, 18, 21, 22, 23, 24, 25},
        {2, 6, 7, 8, 9, 11, 12, 13, 16, 17, 19, 20, 21, 22, 25}
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
