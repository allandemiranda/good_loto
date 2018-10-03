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
    std::ifstream ifs("../../jogos_certos.txt");
	int val;
    std::cout << "Criando vetor com jogos" << std::endl;
	while (ifs >> val) {
		jogos_certos.push_back(val);
	}
	ifs.close();
    std::cout << "Vetor com jogos criado" << std::endl;
    
    //Procurar aiores vetores
    int maior_pontuacao(0);
    int menor_pontuacao_pontos = 13; // Registro da menor pontuação
    std::vector <int> maiores_jogos;
    
    for(int i(0); i<jogos_certos.size(); i+=15){        

        int pontuacao_atual(0);
        int pontuacao_atual_1(0);
        int pontuacao_atual_2(0);
        int pontuacao_atual_3(0);
        int pontuacao_atual_4(0);
        #pragma omp parallel
        {
            #pragma omp sections
            {            
                #pragma omp section
                {
                    for(int j(0*(jogos_certos.size()/4)); j<(1*(jogos_certos.size()/4)); j+=15){             
                        int pontos(0);  
                        for(int k(0); k<15; ++k){
                            if(std::binary_search(&jogos_certos[i], &jogos_certos[i+15], jogos_certos[j+k])){
                                ++pontos;
                                if(pontos >= menor_pontuacao_pontos){
                                    ++pontuacao_atual_1;
                                    break;
                                }
                            }                            
                        } 
                    }
                }  
                #pragma omp section
                {
                    for(int j(1*(jogos_certos.size()/4)); j<(2*(jogos_certos.size()/4)); j+=15){             
                        int pontos(0);  
                        for(int k(0); k<15; ++k){
                            if(std::binary_search(&jogos_certos[i], &jogos_certos[i+15], jogos_certos[j+k])){
                                ++pontos;
                                if(pontos >= menor_pontuacao_pontos){
                                    ++pontuacao_atual_2;
                                    break;
                                }
                            }                            
                        } 
                    }
                } 
                #pragma omp section
                {
                    for(int j(2*(jogos_certos.size()/4)); j<(3*(jogos_certos.size()/4)); j+=15){             
                        int pontos(0);  
                        for(int k(0); k<15; ++k){
                            if(std::binary_search(&jogos_certos[i], &jogos_certos[i+15], jogos_certos[j+k])){
                                ++pontos;
                                if(pontos >= menor_pontuacao_pontos){
                                    ++pontuacao_atual_3;
                                    break;
                                }
                            }                            
                        } 
                    }
                }     
                #pragma omp section
                {
                    for(int j(3*(jogos_certos.size()/4)); j<(4*(jogos_certos.size()/4)); j+=15){             
                        int pontos(0);  
                        for(int k(0); k<15; ++k){
                            if(std::binary_search(&jogos_certos[i], &jogos_certos[i+15], jogos_certos[j+k])){
                                ++pontos;
                                if(pontos >= menor_pontuacao_pontos){
                                    ++pontuacao_atual_4;
                                    break;
                                }
                            }                            
                        } 
                    }
                }           
            }        
        }
        pontuacao_atual = pontuacao_atual_1 + pontuacao_atual_2 + pontuacao_atual_3 + pontuacao_atual_4;
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
