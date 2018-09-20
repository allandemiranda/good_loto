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
 * @return true As regras estão corretas
 * @return false 
 */
bool dento_do_ciclo(int *primeiro){
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

    if(ciclo == 1){
        int quantidade_para_sair = cartela.size();
        int contador_direto(0);
        for(int i(0); i<15; ++i){
            for(int j(0); j<quantidade_para_sair; ++j){
                if(*(primeiro+i) == cartela[j]){
                    ++contador_direto;
                    break;
                }
            }
        }
        if(contador_direto < quantidade_para_sair){
            return true;
        } else {
            return false;
        }
    }
    if(ciclo >= 9){
        int quantidade_para_sair = cartela.size();
        int contador_direto(0);
        for(int i(0); i<15; ++i){
            for(int j(0); j<quantidade_para_sair; ++j){
                if(*(primeiro+i) == cartela[j]){
                    ++contador_direto;
                    break;
                }
            }
        }
        if(contador_direto == quantidade_para_sair){
            return true;
        } else {
            return false;
        }
    }
    return true;
}