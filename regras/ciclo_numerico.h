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
 * @brief Funções globais para gerar o cilho atual e cossumir menos processo na busca
 * 
 */
std::vector <int> cartela_ciclo_global;
int global_ciclo_atual(0);
void ciclo_atual_para_funcoes(){
    int jogo_analisando(0);

    //std::vector <int> analise;

    // Inicialize o ciclo
    int ciclo(0);
        
    // Criar números da cartela
    //std::vector <int> cartela;
    for(int i(1); i<=25; ++i){
        cartela_ciclo_global.push_back(i);
    }

    std::vector <int> cartela_saiu;

    std::vector <int> temp;

    while(true){        

        // Verificar que números da cartela saiu        
        for(int i(0); i<15; ++i){
            for(int j(0); j<15; ++j){
                if(*(std::begin(numeros_sorteados)+(jogo_analisando*15)+i)==cartela_ciclo_global[j]){
                    cartela_saiu.push_back(cartela_ciclo_global[j]);
                    break;
                }
            }
        }

        // Atualize cartela com os números que não sairam        
        for(auto i(cartela_ciclo_global.begin()); i<cartela_ciclo_global.end(); ++i){
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
            cartela_ciclo_global.clear();
            cartela_saiu.clear();
            for(int i : temp){
                cartela_ciclo_global.push_back(i);
            }            
            ++jogo_analisando;
            temp.clear();           
        } else {
            //analise.push_back(ciclo);
            ciclo = 0;
            cartela_ciclo_global.clear();
            cartela_saiu.clear();
            for(int i(1); i<=25; ++i){
                cartela_ciclo_global.push_back(i);
            }
            ++jogo_analisando;
            temp.clear();
        }

        if(((jogo_analisando*15)+std::begin(numeros_sorteados)) >= std::end(numeros_sorteados)){
            global_ciclo_atual = ciclo;
            break;
        }
    }
}
// ciclo_atual_para_funcoes(); // execultada agora na função main()
//  ### FIM da função global para retornar o ciclo atual

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
    if(global_ciclo_atual == 1){
        int quantidade_para_sair = cartela_ciclo_global.size();
        int contador_direto(0);
        for(int i(0); i<15; ++i){
            for(int j(0); j<quantidade_para_sair; ++j){
                if(*(primeiro+i) == cartela_ciclo_global[j]){
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
    if(global_ciclo_atual >= 9){
        int quantidade_para_sair = cartela_ciclo_global.size();
        int contador_direto(0);
        for(int i(0); i<15; ++i){
            for(int j(0); j<quantidade_para_sair; ++j){
                if(*(primeiro+i) == cartela_ciclo_global[j]){
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

/**
 * @brief Função para determinar quantos numeros são sempre sorteados entre o ciclo 1 e 2
 * 
 * @param inicial Aponta para posição inicial do jogo que pode sair
 * @return true Se são sorteados de 2 a 7 números no ciclo para o ciclo 2
 * @return false 
 */
bool ciclo_segundo_quantidade(int *inicial){
    if(global_ciclo_atual == 1){
        int cont(0);
        for(int i(0); i<15; ++i){
            for(int j : cartela_ciclo_global){
                if(*(inicial + i) == j){
                    cont++;
                    break;
                }
            }
        }
        if((cont >= 2) and (cont <= 7)){
            return true;
        } else {
            return false;
        }
    }
    return true;
}