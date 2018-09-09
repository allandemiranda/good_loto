/**
 * @brief Regras geradas pela analise dos númros de fibonacci
 * 
 * @file fibonacci.h
 * @author Allan de Miranda Silva
 * @date 08-09-2018
 */
#include "../analise/numeros_sorteados.h"
#include <iterator>

bool fibonacci_binario_soma(int *inicial){
    int numeros_p_analise[] = {1,2,3,5,8,13,21}; // números Fibonacci da cartela
    int tamanho = std::distance(std::begin(numeros_p_analise), std::end(numeros_p_analise));
    int soma(0);
    for(int i(0); i<15; ++i){
        for(int j(0); j<tamanho; ++j){
            if(*(i+inicial) == *(j+inicial)){
                soma += *(i+inicial);
                break; // pq é 15
            }
        }
    }   
    // A cada 15 números a soma dos números fibonacci que sairão nunca será 0, 1, 2, 4, 5, 7, 12 ou maiores que 53
    if((soma < 3) or (soma == 4) or (soma == 5) or (soma == 7) or (soma == 12) or (soma > 53)){
        return false;
    }

    //checar o ciclo para saber se pode analisar
    int verificar_para_ciclo = 21;
    int tamanho_sorteados = std::distance(std::begin(numeros_sorteados), std::end(numeros_sorteados));
    int q_jogos_sorteados = tamanho_sorteados / verificar_para_ciclo;
    if((q_jogos_sorteados*verificar_para_ciclo)+15)

    

}