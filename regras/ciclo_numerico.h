/**
 * @brief Regras criadas para descidir se o número pode ou não sair nos próximos 15 numeros que serão sorteados
 * 
 * @file ciclo_numerico.h
 * @author Allan de Miranda Silva
 * @date 20-09-2018
 */
#include <vector>
#include <algorithm>
#include <iterator>

/**
 * @brief Verifica se o numero pode ou não sair nos proximos 15 números
 * 
 * @param primeiro Aponta para o primeiro número do jogo que queremos analisar
 * @return true Para se toda a regra está valendo
 * @return false Para se a regra não está valendo
 */
bool numero_pode_sair(int *primeiro){
    for(int i(0); i<15; ++i){
        // Núemro escolhido para análise
        int numero(*(primeiro+i));

        // Vetor de analise
        std::vector <int> analise;

        // Fazer análise
        int tempo_agora(0);
        bool primeira_vez(true);
        for(auto *sequencia=std::begin(numeros_sorteados); sequencia<std::end(numeros_sorteados); sequencia++){
            if(numero == *sequencia){
                primeira_vez = false;
            }
            if(numero != *sequencia){
                tempo_agora++;
            } else {
                analise.push_back(tempo_agora);
                tempo_agora = 0;
            }
        }

        // Ver em que ciclo o número está
        int ciclo_atual(0);
        for(int *j=(std::end(numeros_sorteados)-1); j>=std::begin(numeros_sorteados); --j, ++ciclo_atual){
            if(*j==numero){
                break;
            }
        }

        // Verificar se está no tempo correto para os próximos 15 números
        bool flag(false);
        for(int j : analise){
            for(int k(0); k<15; ++k){
                if((ciclo_atual+k) == j){
                    flag = true;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        if(flag){
            continue;
        } else {
            return false;
        }
    }
    return true;
}

/**
 * @brief Verificar se atingiu o ciclo máximo e sairá todos os números restantes
 * 
 * @return true 
 * @return false 
 */
bool dento_do_ciclo(*primeiro){
    // IMPLEMENTAR ISSO !!!
}