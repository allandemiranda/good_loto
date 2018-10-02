#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <vector>
#include <omp.h> // sistemas paralelos

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
    
    //Procurar aiores vetores
    int maior_pontuacao(0);
    std::vector <int> maiores_jogos;
    int porcentage(1);
    for(int i(0); i<jogos_certos.size(); i+=15){
        if(porcentage == 10){
            std::cout << "Aguarde: " << (((i+1)*10000)/jogos_certos.size()) << "%" << std::endl;
            porcentage = 1;
        } else {
            ++porcentage;
        }

        int pontuacao_atual(0);
        for(int j(0); j<jogos_certos.size(); j+=15){             
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
                        for(int k(0); k<4; ++k){
                            if(std::binary_search(&jogos_certos[i], &jogos_certos[i+15], jogos_certos[j+k])){
                                ++pontos_1;
                            }
                        }
                    }
                    #pragma omp section
                    {
                        for(int k(4); k<8; ++k){
                            if(std::binary_search(&jogos_certos[i], &jogos_certos[i+15], jogos_certos[j+k])){
                                ++pontos_2;
                            }
                        }
                    }
                    #pragma omp section
                    {
                        for(int k(8); k<11; ++k){
                            if(std::binary_search(&jogos_certos[i], &jogos_certos[i+15], jogos_certos[j+k])){
                                ++pontos_3;
                            }
                        }
                    }
                    #pragma omp section
                    {
                        for(int k(11); k<15; ++k){
                            if(std::binary_search(&jogos_certos[i], &jogos_certos[i+15], jogos_certos[j+k])){
                                ++pontos_4;
                            }
                        }
                    }
                }
            }
            pontos =  pontos_1 + pontos_2 + pontos_3 + pontos_4;
            if(pontos>=13){
                ++pontuacao_atual;
            }            
        }
        if(pontuacao_atual >= maior_pontuacao){
            if(pontuacao_atual > maior_pontuacao){
                maiores_jogos.clear();
                maior_pontuacao = pontuacao_atual;
            }
            for(int j(0); j<15; ++j){
                std::cout << jogos_certos[i+j] << " ";
                maiores_jogos.push_back(jogos_certos[i+j]);
            }            
            std::cout << pontuacao_atual << std::endl;
        }
    }

    //Apresentar maiores jogos
    std::cout << "Maiores jogos -> " << maior_pontuacao << std::endl;
    for(int i(0); i<maiores_jogos.size(); i+=15){
        std::cout << i << " - ";
        for(int j(0); j<15; ++j){
            std::cout << maiores_jogos[i+j] << " ";
        }
        std::cout << std:: endl;
    }

    return 0;
}
