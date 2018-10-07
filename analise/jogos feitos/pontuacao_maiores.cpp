#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <vector>
#include <omp.h> // sistemas paralelos

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

    int jogo[] = {2,3,4,6,10,11,13,15,17,18,20,21,23,24,25};
    std::sort(std::begin(jogo), std::end(jogo));

    std::cout << "Analisando vetor com jogos" << std::endl;
    std::vector <int> analise;
    for(int i=0; i<jogos_possiveis.size(); i+=15){
        int pontos(0); 
        int pontos_1(0);
        int pontos_2(0);
        int pontos_3(0);
        int pontos_4(0);       
        #pragma omp parallel
        {        
            #pragma omp sections
            {            
                #pragma omp section
                {
                    for(int j(0); j<(3); ++j){
                        if(std::binary_search(std::begin(jogo), std::end(jogo), jogos_possiveis[i+j])){
                            ++pontos_1;
                        }
                    }
                }
                #pragma omp section
                {
                    for(int j(3); j<(6); ++j){
                        if(std::binary_search(std::begin(jogo), std::end(jogo), jogos_possiveis[i+j])){
                            ++pontos_2;
                        }
                    }
                }
                #pragma omp section
                {
                    for(int j(6); j<(12); ++j){
                        if(std::binary_search(std::begin(jogo), std::end(jogo), jogos_possiveis[i+j])){
                            ++pontos_3;
                        }
                    }
                }
                #pragma omp section
                {
                    for(int j(12); j<(15); ++j){
                        if(std::binary_search(std::begin(jogo), std::end(jogo), jogos_possiveis[i+j])){
                            ++pontos_4;
                        }
                    }
                }
            }
        }
        pontos = pontos_1 + pontos_2 + pontos_3 + pontos_4;
        analise.push_back(pontos);
    }
    std::cout << "Vetor com jogos analisado" << std::endl;
    std::cout << "Ordenando vetor com jogos" << std::endl;
    std::sort(analise.begin(), analise.end());
    std::cout << "Vetor com jogos ordenado" << std::endl;
    std::cout << "Contando ocoorencias" << std::endl;
    for(int i(0); i<=15; ++i){
        int contador(0);
        //#pragma omp parallel for reduction(+:contador)
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
