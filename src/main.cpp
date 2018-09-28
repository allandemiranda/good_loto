/**
 * @brief Função que irá gerar os jogos possiveis
 * 
 * @file main.cpp
 * @author Allan de Miranda Silva
 * @date 08-09-2018
 */
#include <iostream>
#include <algorithm>
#include <fstream>
#include "../analise/numeros_sorteados.h" // Para as regras funcionarem
#include "../regras/regras.h"

#include <omp.h> // sistemas paralelos

#include <ctime> // temporário so para medir tempo
std::time_t result_um;
std::time_t result_dois;

int main(int argc, char *argv[ ]){
    // Marcar hora inicial
    std::cout << "Iniciou às " << __TIME__ << std::endl;

    // economia de memória dos cilcos 
    ciclo_atual_para_funcoes();  
    numeros_podemsair_pelo_ciclo();
    calculo_ciclos_razao_aurea();

////*----
    int jogo_a[] = {1,2,3,4,6,7,8,9,10,12,13,14,17,18,22};
    if(regras_gerais(&jogo_a[0])){ 
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "ERRO" << std::endl;
    }

    if(atoi(argv[1]) == 1){
            return 0;
    }
/////------ 

    
    //std::ofstream outFile ("jogos_certos.txt", std::ios::app);

    // Verificar menor e maiores números que saem em suas posições
    int vetor_maior[15];
    int vetor_menor[15];
    for(int posicao(0); posicao<15; ++posicao){
        int maior(1);
        int menor(25);
        for(auto *i = std::begin(numeros_sorteados); i<std::end(numeros_sorteados); i+=15){
            int jogo_sort[15];
            for(int j(0); j<15; ++j){
                jogo_sort[j] = *(i+j);
            }
            std::sort(std::begin(jogo_sort), std::end(jogo_sort));
            if(jogo_sort[posicao]<menor){
                menor = jogo_sort[posicao];
            }
            if(jogo_sort[posicao]>maior){
                maior = jogo_sort[posicao];
            }
        }
        vetor_maior[posicao] = maior;
        vetor_menor[posicao] = menor;
    }
    //std::cout << vetor_maior[0] << std::endl;
    result_um = std::time(nullptr);
    // Listar todas as possibilidades
    int jogo[15];
    int contar_jogos_possiveis(0);
    #pragma omp parallel for reduction(+:contar_jogos_possiveis)
    for(int a = 1; a<=6 ; ++a){ // 1
        jogo[0] = a;
        for(int b = a + 1; (vetor_menor[1] <= b) and (vetor_maior[1] >= b); ++b){ // 2
            jogo[1] = b;
            for(int c = b + 1; (vetor_menor[2] <= c) and (vetor_maior[2] >= c); ++c){ // 3
                jogo[2] = c;
                for(int d = c + 1; (vetor_menor[3] <= d) and (vetor_maior[3] >= d); ++d){ // 4
                    jogo[3] = d;
                    for(int e = d + 1; (vetor_menor[4] <= e) and (vetor_maior[4] >= e); ++e){ // 5
                        jogo[4] = e;
                        for(int f = e + 1; (vetor_menor[5] <= f) and (vetor_maior[5] >= f); ++f){ // 6
                            jogo[5] = f;
                            for(int g = f + 1; (vetor_menor[6] <= g) and (vetor_maior[6] >= g); ++g){ // 7
                                jogo[6] = g;
                                for(int h = g + 1; (vetor_menor[7] <= h) and (vetor_maior[7] >= h); ++h){ // 8
                                    jogo[7] = h;
                                    for(int i = h + 1; (vetor_menor[8] <= i) and (vetor_maior[8] >= i); ++i){ // 9
                                        jogo[8] = i;
                                        for(int j = i + 1; (vetor_menor[9] <= j) and (vetor_maior[9] >= j); ++j){ // 10
                                            jogo[9] = j;
                                            for(int k = j + 1; (vetor_menor[10] <= k) and (vetor_maior[10] >= k); ++k){ // 11
                                                jogo[10] = k;
                                                for(int l = k + 1; (vetor_menor[11] <= l) and (vetor_maior[11] >= l); ++l){ // 12
                                                    jogo[11] = l;
                                                    for(int m = l + 1; (vetor_menor[12] <= m) and (vetor_maior[12] >= m); ++m){ // 13
                                                        jogo[12] = m;
                                                        for(int n = m + 1; (vetor_menor[13] <= n) and (vetor_maior[13] >= n); ++n){ // 14
                                                            jogo[13] = n;
                                                            for(int o = n + 1; (vetor_menor[14] <= o) and (vetor_maior[14] >= o); ++o){ // 15
                                                                jogo[14] = o; 
                                                                if(regras_gerais(&jogo[0])){ 
                                                                    //for(int gravar(0); gravar < 14; ++gravar){
                                                                        //outFile << jogo[gravar] << " ";
                                                                    //}
                                                                    //outFile << jogo[14] << std::endl;
                                                                    contar_jogos_possiveis+=1;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    result_dois = std::time(nullptr);
    std::cout << "time inicial para " << " " << std::asctime(std::localtime(&result_um)) << std::endl;
    std::cout << "time final para " << " " << std::asctime(std::localtime(&result_dois)) << std::endl;
    std::cout << contar_jogos_possiveis << std::endl;

    return 0;
}