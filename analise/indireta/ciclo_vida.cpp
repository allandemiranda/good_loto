/**
 * @brief Analise a vida de um ciclo de números (vendo que numeros não sairam ainda)
 * 
 * @file ciclo_vida.cpp
 * @author Allan de Miranda Silva
 * @date 20-09-2018
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "../numeros_sorteados.h"

int main(int argc, char const *argv[])
{    
    int jogo_analisando(0);

    std::vector <int> analise;

    // Inicialize o ciclo
    int ciclo(0);
        
    // Criar números da cartela
    std::vector <int> cartela;
    for(int i(1); i<=25; ++i){
        cartela.push_back(i);
    }

    std::vector <int> cartela_saiu;

    std::vector <int> temp;

    while(true){        

        // Verificar que números da cartela saiu        
        for(int i(0); i<15; ++i){
            for(int j(0); j<15; ++j){
                if(*(std::begin(numeros_sorteados)+(jogo_analisando*15)+i)==cartela[j]){
                    cartela_saiu.push_back(cartela[j]);
                    break;
                }
            }
        }

        // Atualize cartela com os números que não sairam        
        for(auto i(cartela.begin()); i<cartela.end(); ++i){
            bool flag_temp(true);
            for(auto j(cartela_saiu.begin()); j<cartela_saiu.end(); ++j){
                if(*i == *j){
                    flag_temp=false;
                    break;
                }
            }
            if(flag_temp){
                temp.push_back(*i);
            }
        }

        if(temp.size()>0){
            ++ciclo;
            cartela.clear();
            cartela_saiu.clear();
            for(int i : temp){
                cartela.push_back(i);
            }            
            ++jogo_analisando;
            temp.clear();           
        } else {
            analise.push_back(ciclo);
            ciclo = 0;
            cartela.clear();
            cartela_saiu.clear();
            for(int i(1); i<=25; ++i){
                cartela.push_back(i);
            }
            ++jogo_analisando;
            temp.clear();
        }

        if(((jogo_analisando*15)+std::begin(numeros_sorteados)) >= std::end(numeros_sorteados)){
            break;
        }
    }

    // Apresentar resultados
    int menor(analise[0]);
    int maior(analise[0]);
    for(int i : analise){
        if( i < menor){
            menor = i;
        }
        if( i > maior){
            maior = i;
        }
    }
    int maior_contador(0);
    for(int i(menor); i<=(maior + 1); ++i){
        int contador(0);
        for(int j : analise){
            if(j == i){
                contador++;
            }
        }
        if(contador>maior_contador){
            maior_contador = contador;
        }
    }
    std::vector <int> respostas_valor;
    for(int i(menor); i<=(maior + 1); ++i){
        int contador(0);
        for(int j : analise){
            if(j == i){
                contador++;
            }
        }
        std::cout << "Ciclo " << i << " saiu " << contador << " vezes (" << (float)((contador*100)/maior_contador) << "%)" << std::endl;
        if(((contador*100)/maior) >= 1){
            respostas_valor.push_back(i);
        }
    }

    std::cout << "-----------------------------------" << std::endl;

    // Imprimir como um vetor    
    for(auto i(0); i<respostas_valor.size()-1; ++i){
        std::cout << respostas_valor[i] << ", ";
    }
    std::cout << respostas_valor[(respostas_valor.size() - 1)] << std::endl; 

    std::cout << "-----------------------------------" << std::endl;


// IMPREMENTAR ISSO !!!
// em seguinda (0) n sai todos
// no 1 tb não sai todos
// e
// no ciclo 9 todos os núemros devem sair

    return 0;
}
