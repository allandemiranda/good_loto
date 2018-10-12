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

    int jogo[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 14, 17 ,19 ,20, 23 ,24};
    
    std::sort(std::begin(jogo), std::end(jogo));

    std::cout << "Analisando vetor com jogos" << std::endl;
    std::vector <int> analise;
    for(int i=0; i<jogos_possiveis.size(); i+=15){
        int pontos(0);     
        
        for(int j(0); j<(15); ++j){
            if(std::binary_search(std::begin(jogo), std::end(jogo), jogos_possiveis[i+j])){
                ++pontos;
            }
        }               
        
        analise.push_back(pontos);
    }
    std::cout << "Vetor com jogos analisado" << std::endl;
    std::cout << "Ordenando vetor com jogos" << std::endl;
    std::sort(analise.begin(), analise.end());
    std::cout << "Vetor com jogos ordenado" << std::endl;
    std::cout << "Contando ocoorencias" << std::endl;
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
    std::cout << "Ocoorencias contadas" << std::endl;

    return 0;
}
