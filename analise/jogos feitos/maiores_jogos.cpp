#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <vector>
#include <omp.h> // sistemas paralelos -fopenmp
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <random>

bool lista_jogos_possiveis(std::string local, std::vector <int> &jogos_possiveis){
    std::ifstream ifs(local);
	int val;
    if(!ifs.good()){
        return false;
    }
	while (ifs >> val) {
		jogos_possiveis.push_back(val);
	}
	ifs.close();
    return true;
}

int analise_11_pontos(std::vector <int> &jogos, int numero_do_jogo){
    int temp_jogo[15];
    for(int i=0; i<15; ++i){
        temp_jogo[i] = jogos[(numero_do_jogo*15)+i];
    }
    int pontos_maiores=0;
    #pragma omp parallel for reduction(+ : pontos_maiores)
    for(int i=0; i<(jogos.size()/15); ++i){
        int pontos_atual=0;        
        for(int j=0; j<15; ++j){
            if(std::binary_search(std::begin(temp_jogo), std::end(temp_jogo), jogos[(i*15)+j])){
                ++pontos_atual;
                if(pontos_atual>=11){
                    break;
                }
            } else {
                if((j>=4) and (pontos_atual>=(j-3))){
                    break;
                }
            }
        }
        if(pontos_atual>=11){
            ++pontos_maiores;            
        }
    }
    return pontos_maiores;
}

int main(int argc, char const *argv[])
{
    std::vector <int> jogos_certos;
    std::string local = "jogos_certos_1718.txt";
    lista_jogos_possiveis(local, jogos_certos);

    int maior_pontuacao = 0;
    for(int i(0); i<jogos_certos.size(); ++i){
        int temp = analise_11_pontos(jogos_certos,i);
        if(temp>maior_pontuacao){
            maior_pontuacao = temp;
            for(int j(0); j<15; ++j){
                std::cout << jogos_certos[(15*i)+j] << " ";
            }
            std::cout << " - " << temp << " pontos 11 ou mais" << std::endl;
        }
    }
    return 0;
}
