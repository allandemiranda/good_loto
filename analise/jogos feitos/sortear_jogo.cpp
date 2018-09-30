#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <vector>
#include <omp.h> // sistemas paralelos

void pegar_jogos(std::vector <int> &jogos){
    std::ifstream ifs("../../src/jogos_certos.txt");
	int val;
    std::cout << "Criando vetor com jogos" << std::endl;
	while (ifs >> val) {
		jogos.push_back(val);
	}
	ifs.close();
    std::cout << "Vetor com jogos criado" << std::endl;
}

int quantidade_maior(std::vector <int> jogos_possiveis, std::vector <int> &maiores_jogos){
    int quantidade_do_maior(0);
    int porcentagem(0);
    for(int i(0); i<jogos_possiveis.size(); i+=15){
        if(porcentagem==10000){
            std::cout << "Processando: " << (((i+1)*100)/jogos_possiveis.size()) << std::endl;
            porcentagem = 1;
        } else {
            porcentagem++;
        }
        int jogo_amostra[15];        
        for(int j(0); i<15; ++j){
            jogo_amostra[j] = jogos_possiveis[i+j];
        }
        int quantidade_de_jogos_com_13_pontos(0);
        int quantidade_de_jogos_com_13_pontos_1(0);
        int quantidade_de_jogos_com_13_pontos_2(0);
        int quantidade_de_jogos_com_13_pontos_3(0);
        int quantidade_de_jogos_com_13_pontos_4(0);
        #pragma omp parallel
        {        
            #pragma omp sections
            {            
                #pragma omp section
                {
                    for(int j((jogos_possiveis.size()/4)*0); j<((jogos_possiveis.size()/4)*1); j+=15){
                        int jogo_analizar[15];            
                        for(int k(0); k<15; ++k){
                            jogo_analizar[j] = jogos_possiveis[j+k];
                        } 
                        int pontos_atual(0);  
                        for(int k(0); k<15; ++k){
                            if(std::binary_search(std::begin(jogo_analizar), std::end(jogo_analizar), jogo_amostra[k])){
                                ++pontos_atual;
                            }
                        }
                        if(pontos_atual >= 13){
                            ++quantidade_de_jogos_com_13_pontos_1;
                        }
                    }
                }
                #pragma omp section
                {
                    for(int j((jogos_possiveis.size()/4)*1); j<((jogos_possiveis.size()/4)*2); j+=15){
                        int jogo_analizar[15];            
                        for(int k(0); k<15; ++k){
                            jogo_analizar[j] = jogos_possiveis[j+k];
                        } 
                        int pontos_atual(0);  
                        for(int k(0); k<15; ++k){
                            if(std::binary_search(std::begin(jogo_analizar), std::end(jogo_analizar), jogo_amostra[k])){
                                ++pontos_atual;
                            }
                        }
                        if(pontos_atual >= 13){
                            ++quantidade_de_jogos_com_13_pontos_2;
                        }
                    }
                }
                #pragma omp section
                {
                    for(int j((jogos_possiveis.size()/4)*2); j<((jogos_possiveis.size()/4)*3); j+=15){
                        int jogo_analizar[15];            
                        for(int k(0); k<15; ++k){
                            jogo_analizar[j] = jogos_possiveis[j+k];
                        } 
                        int pontos_atual(0);  
                        for(int k(0); k<15; ++k){
                            if(std::binary_search(std::begin(jogo_analizar), std::end(jogo_analizar), jogo_amostra[k])){
                                ++pontos_atual;
                            }
                        }
                        if(pontos_atual >= 13){
                            ++quantidade_de_jogos_com_13_pontos_3;
                        }
                    }
                }
                #pragma omp section
                {
                    for(int j((jogos_possiveis.size()/4)*3); j<((jogos_possiveis.size()/4)*4); j+=15){
                        int jogo_analizar[15];            
                        for(int k(0); k<15; ++k){
                            jogo_analizar[j] = jogos_possiveis[j+k];
                        } 
                        int pontos_atual(0);  
                        for(int k(0); k<15; ++k){
                            if(std::binary_search(std::begin(jogo_analizar), std::end(jogo_analizar), jogo_amostra[k])){
                                ++pontos_atual;
                            }
                        }
                        if(pontos_atual >= 13){
                            ++quantidade_de_jogos_com_13_pontos_4;
                        }
                    }
                }
            }
        }
        quantidade_de_jogos_com_13_pontos = quantidade_de_jogos_com_13_pontos_1 + quantidade_de_jogos_com_13_pontos_2 + quantidade_de_jogos_com_13_pontos_3 + quantidade_de_jogos_com_13_pontos_4;
        if(quantidade_de_jogos_com_13_pontos>quantidade_do_maior){
            maiores_jogos.clear();
            for(int j(0); j<15; ++j){
                maiores_jogos.push_back(jogo_amostra[j]);
            }
            quantidade_do_maior = quantidade_de_jogos_com_13_pontos;
        }
        if(quantidade_de_jogos_com_13_pontos == quantidade_do_maior){
            for(int j(0); j<15; ++j){
                maiores_jogos.push_back(jogo_amostra[j]);
            }
        }
    }
    return quantidade_do_maior;
}

void limpeza(int *jogo, std::vector <int> &jogos_possiveis){
    int jogo_aqui[15];    
    for(int i(0); i<15; ++i){
        jogo_aqui[i] = jogo[i];
    }
    for(int i(0); i<jogos_possiveis.size(); i+=15){
        int pontos(0);
        int pontos_1(0);
        int pontos_2(0);
        int pontos_3(0);      
        #pragma omp parallel
        {        
            #pragma omp sections
            {            
                #pragma omp section
                {
                    for(int j(0); j<5; ++j){
                        if(std::binary_search(std::begin(jogo_aqui), std::end(jogo_aqui), jogos_possiveis[i+j])){
                            ++pontos_1;
                        }
                    }
                }
                #pragma omp section
                {
                    for(int j(5); j<10; ++j){
                        if(std::binary_search(std::begin(jogo_aqui), std::end(jogo_aqui), jogos_possiveis[i+j])){
                            ++pontos_2;
                        }
                    }
                }
                #pragma omp section
                {
                    for(int j(10); j<15; ++j){
                        if(std::binary_search(std::begin(jogo_aqui), std::end(jogo_aqui), jogos_possiveis[i+j])){
                            ++pontos_3;
                        }
                    }
                }
            }
        }
        pontos = pontos_1 + pontos_2 + pontos_3;
        if(pontos>=13){
            jogos_possiveis.erase((jogos_possiveis.begin()+i),(jogos_possiveis.begin()+i+15));
            i-=15;
        }
    }
}

int quantidade_maior_seguinte(std::vector <int> jogos_possiveis, std::vector <int> pre_limpeza, std::vector <int> &maiores){
    for(int i(0); i<(pre_limpeza.size()/15); i+=15){
        limpeza((&pre_limpeza[i]), jogos_possiveis);
    }
    return quantidade_maior(jogos_possiveis,maiores);
}

int main(int argc, char const *argv[])
{
    std::vector <int> jogos_possiveis;
    pegar_jogos(jogos_possiveis);

    if(atoi(argv[1])==1){
        std::vector <int> maiores_jogos;
        int quantidade = quantidade_maior(jogos_possiveis,maiores_jogos);
        std::cout << "Primeiros maiores jogos " << std::endl;
        for(int i(0); i<maiores_jogos.size(); i+=15){
            std::cout << i << " - ";
            for(int j(0); j<15; ++j){
                std::cout << maiores_jogos[i+j] << " ";
            }
            std::cout << "- " << quantidade << std::endl;
        }
    }

    if(atoi(argv[1])==2){
        // colocar jogos a ser limpo aqui
        std::vector <int> vetor_para_limpar = {};
        
        std::vector <int> novo_maiores;
        int quantidade_nova = quantidade_maior_seguinte(jogos_possiveis,vetor_para_limpar, novo_maiores);
        std::cout << "Maiores jogos seguintes" << std::endl;
        for(int i(0); i<novo_maiores.size(); i+=15){
            std::cout << i << " - ";
            for(int j(0); j<15; ++j){
                std::cout << novo_maiores[i+j] << " ";
            }
            std::cout << "- " << quantidade_nova << std::endl;
        }
    }    

    return 0;
}
