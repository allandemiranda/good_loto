/**
 * @file desdobramentos_smart.cpp
 * @author Allan de Miranda Silva
 * @brief   Está função irá apresentar 10 desdobramentos 
 * 
 *          11 jogos
 *          19 números
 *  
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
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <random>

int sorteio_numero(int n_inicial, int n_final){
    std::random_device numero_sorteado;
    std::mt19937 mt(numero_sorteado()); 
    std::uniform_int_distribution<int> dist_numero_sorteado(n_inicial, n_final);
    return dist_numero_sorteado(mt);
}

void sorteio_vetor(int quantidade_de_nuemros, std::vector <int> &numeros){
    for(int i(0); i<quantidade_de_nuemros; ++i){
        bool flag = true;        
        while(flag){            
            auto novo_numero_sorteado = sorteio_numero(1,25);
            flag = false;
            #pragma omp parallel for
            for(int j=0; j<numeros.size(); ++j){
                if(numeros[j]==novo_numero_sorteado){
                    flag = true;
                    #pragma omp cancel for
                }
            } 
            if(!flag){
                numeros.push_back(novo_numero_sorteado);
            }          
        }         
    }
}

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

void adicinar_grupo(std::vector <int> &vetor_manipular, std::vector<int>::iterator p_inicial, std::vector<int>::iterator p_final){
    for(std::vector<int>::iterator i=p_inicial; i<p_final; ++i){
        vetor_manipular.push_back(*i);
    }
}

int main(int argc, char const *argv[])
{
    std::vector <int> jogos_que_vao_sair;
    std::string local_do_arquivo = "jogos_certos_1718.txt";
    if((1 == atoi(argv[2])) or (1 == atoi(argv[3]))){
        if(!lista_jogos_possiveis(local_do_arquivo, jogos_que_vao_sair)){
            std::cout << "erro ao ler arquivo " << std::endl;
            return EXIT_FAILURE;
        } else {
            std::cout << "Vetor na memória" << std::endl;
        }
    }

    // jogos para jogar
    std::vector <int> jogos_para_jogar;
    int q_n_jogos = atoi(argv[1]); // <-------------- QUANTIDADE A ANALISAR
    std::vector <float> analise;
    int num_fixos = 9;
   
    int n_jogos(0);
    for(n_jogos = 0; n_jogos<q_n_jogos; ++n_jogos){
        // Sorteio
        std::vector <int> numeros_sorteados;
        sorteio_vetor(25, numeros_sorteados);
        
        std::vector <std::vector <int>> posicoes_grupos = {
            {1,3},
            {3,5},
            {5,7},
            {7,9},
            {9,11},
            {11,13},
            {13,15},
            {15,17}
        };
        std::vector <std::vector <int>> seguencias_grupos = 
        {
            {1,3,4},
            {1,2,6},
            {1,4,7},
            {1,7,8},
            {2,3,8},
            {2,5,6},
            {3,5,7},
            {3,5,8},
            {4,5,6},
            {4,7,8}
        };

        for(int i(0); i<seguencias_grupos.size(); ++i){   
            adicinar_grupo(jogos_para_jogar, numeros_sorteados.begin(), numeros_sorteados.begin()+num_fixos);         
            for(int j(0); j<seguencias_grupos[i].size(); ++j){
                adicinar_grupo(jogos_para_jogar, (numeros_sorteados.begin()+num_fixos+(posicoes_grupos[(seguencias_grupos[i][j])-1][0]-1)), (numeros_sorteados.begin()+num_fixos+(posicoes_grupos[(seguencias_grupos[i][j])-1][1]-1)));
            }
        }
        
        if(1 == atoi(argv[2])){
            // checar se jogos pdoem sair
            bool bandeira_checar = true;
            #pragma omp parallel for
            for(int i=0; i<jogos_para_jogar.size(); i+=15){
                int novo_vetor_temp[15];
                for(int j=0; j<15; ++j){
                    novo_vetor_temp[j]=jogos_para_jogar[i+j];
                }
                std::sort(std::begin(novo_vetor_temp), std::end(novo_vetor_temp));
                for(int j=0; j<jogos_que_vao_sair.size(); j+=15){                
                    bandeira_checar = true;                
                    for(int k=0; k<15; ++k){
                        if(novo_vetor_temp[k]!=jogos_que_vao_sair[j+k]){                         
                            bandeira_checar = false;
                            break;                         
                        }
                    }
                    if(bandeira_checar){
                        break;
                    }
                }
                if(!bandeira_checar){
                    bandeira_checar = false;
                    #pragma omp cancel for
                }
            }
            if(!bandeira_checar){
                --n_jogos;
                continue;
            } 
        }

        if(1 == atoi(argv[3])){
            //checagem dos 14 pontos maiores que 100
            bool bandeira_dos_14 = false;
            #pragma omp parallel for
            for(int i=0; i<jogos_para_jogar.size(); i+=15){
                int novo_vetor_temp[15];
                for(int j=0; j<15; ++j){
                    novo_vetor_temp[j]=jogos_para_jogar[i+j];
                }
                std::sort(std::begin(novo_vetor_temp), std::end(novo_vetor_temp));
                int pontos_14(0);
                for(int j=0; j<jogos_que_vao_sair.size(); j+=15){ 
                    int pontos_temp(0);  
                    for(int k=0; k<15; ++k){
                        if(std::binary_search(std::begin(novo_vetor_temp), std::end(novo_vetor_temp),jogos_que_vao_sair[j+k])){
                            ++pontos_temp;
                        }
                        if((k>=1) and (pontos_temp < k)){
                            break;
                        }
                    }
                    if(pontos_temp>=14){
                        ++pontos_14;
                    }
                }
                if(pontos_14<100){
                    bandeira_dos_14 = true;
                    #pragma omp cancel for
                }
            }
            if(bandeira_dos_14){
                --n_jogos;
                continue;
            }
        }
    }

    int jogo_que_saiu[15] = {2, 3, 5, 6, 7, 8, 10, 11, 12, 17, 18, 20, 21, 22, 24};
    float valores[15] = {0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,4.00, 8.00, 20.00, 1129.23, 269379.40};       

    for(int i(0); i<n_jogos; ++i){
        std::cout << "JOGADA: " << (i+1) << std::endl;
        std::cout << std::endl;
        auto money(0);
        for(int j(0); j<10; ++j){
            money = money - 2;
            int novo_jogo[15];
            #pragma omp parallel for
            for(int k=0; k<15; ++k){
                novo_jogo[k] = jogos_para_jogar[(i*10*15)+(j*15)+k];
            }
            std::sort(std::begin(novo_jogo), std::end(novo_jogo));
            int pontos(0);            
            for(int k=0; k<15; ++k){
                std::cout << novo_jogo[k] << " ";
                if(std::binary_search(std::begin(novo_jogo), std::end(novo_jogo), jogo_que_saiu[k])){
                    ++pontos;
                }
            }
            std::cout << " - Pontos " << pontos << " - R$" << valores[pontos-1] << " (R$" << (valores[pontos-1]-2.00) << ")" << std::endl;
            money = valores[pontos-1] + money;
        }
        std::cout << std::endl;
        std::cout << "GANHOS NESSA JOGADA: R$" << money << std::endl;
        std::cout << "---------------------------------------------------------------" << std::endl;         
        analise.push_back(money);
    }    

    std::sort(analise.begin(), analise.end());

    float soma(0);
    float n_analise = analise[0];
    int q_analise = 0;
    int maior_vezes(0);
    for(float i : analise){
        soma = soma + i;
        if(i == n_analise){
            ++q_analise;
        } else {            
            maior_vezes += q_analise;
            q_analise = 1;           
            n_analise = i;
        }
    }
    if(q_analise>maior_vezes){
        maior_vezes = q_analise;
    }

    std::cout << "Valor  -  Quantidade" << std::endl;
    n_analise = analise[0];
    std::cout << "R$" << n_analise;
    q_analise = 0;
    for(float i : analise){        
        if(i == n_analise){
            ++q_analise;
        } else {
            std::cout << " - " << q_analise << " vezes ";
            std::cout << "(" << ((q_analise*((float)100))/maior_vezes) << "%)" << std::endl;
            q_analise = 1;
            std::cout << "R$" << i;            
            n_analise = i;
        }
    }
    std::cout << " - " << q_analise << " vezes ";
    std::cout << "(" << ((q_analise*((float)100))/maior_vezes) << "%)" << std::endl;
    std::cout << std::endl;
    std::cout << "TOTAL APURADO: R$" << soma << std::endl;
    std::cout << std::endl;

    return EXIT_SUCCESS;
}