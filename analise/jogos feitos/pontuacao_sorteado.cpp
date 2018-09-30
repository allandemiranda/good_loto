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

    int jogo[] = {8,21,15,14,9,3,22,10,24,23,4,5,1,11,7};
    std::sort(std::begin(jogo), std::end(jogo));

    std::cout << "Analisando vetor com jogos" << std::endl;
    std::vector <int> analise;
    for(int i=0; i<jogos_possiveis.size(); i+=15){
        int pontos(0);
        int j;
        //#pragma omp parallel for reduction(+:pontos) private(i,j)
        for(j=0; j<15; ++j){
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
