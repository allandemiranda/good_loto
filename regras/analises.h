/**
 * @brief Aqui contem as funções de analises de grupos
 * 
 * @file analises.h
 * @author Allan de Miranda Silva
 * @date 11-09-2018
 */

#include <iterator>
#include <vector>
#include <algorithm>
#include <cmath>

bool analise_soma(int *inicial, int *numeros_para_analise, int quantidade_de_numeros_analisar, int *tamanho_amostra_vetor, int distancia_tamanho_amostra_vetor, std::vector < std::vector <int> > respostas){
    for(auto posicao(0); posicao < distancia_tamanho_amostra_vetor; ++posicao){
        // Correção de jogos para números de elementos
        int tamanho_amostra = ((*(tamanho_amostra_vetor + posicao) - 1) * 15);        
        
        // Inicialise a Soma
        int soma(0);

        // Analisar se a amostra for maior que 1 jogo
        for(auto i(0); i<quantidade_de_numeros_analisar; ++i){
            for(auto j(0); j<tamanho_amostra; ++j){                
                if(*(numeros_para_analise + i) == *(std::end(numeros_sorteados) - 1 - j)){
                    soma += *(numeros_para_analise + i);
                }
            }
        }              

        // Analisar e preencher para o jogo
        for(auto i(0); i<quantidade_de_numeros_analisar; ++i){
            for(auto j(0); j<15; ++j){
                if(*(numeros_para_analise + i) == *(inicial + j)){
                    soma += *(numeros_para_analise + i);
                }
            }
        }

        // Verificar a ocorencia corresponde aos resultados possiveis
        int tamanho_do_vetor_resposta = respostas[posicao].size();
        bool marcador(true);
        for(auto i(0); i<tamanho_do_vetor_resposta; ++i){
            if(soma == respostas[posicao][i]){
                marcador = false;
                break;
            }
        }
        if(marcador){            
            return false;
            break;
        }
    }

    return true;
}

bool analise_ocorrencias(int *inicial, int *numeros_para_analise, int quantidade_de_numeros_analisar, int *tamanho_amostra_vetor, int distancia_tamanho_amostra_vetor, std::vector < std::vector <int> > respostas){
    for(auto posicao(0); posicao < distancia_tamanho_amostra_vetor; ++posicao){
        // Correção de jogos para números de elementos
        int tamanho_amostra = ((tamanho_amostra_vetor[posicao] - 1) * 15);
        
        // Inicialise a Soma
        int soma(0);

        // Analisar se a amostra for maior que 1 jogo
        for(auto i(0); i<quantidade_de_numeros_analisar; ++i){
            for(auto j(0); j<tamanho_amostra; ++j){
                if(numeros_para_analise[i] == *(std::end(numeros_sorteados) - 1 - j)){
                    soma++;
                }
            }
        }

        // Analisar e preencher para o jogo
        for(auto i(0); i<quantidade_de_numeros_analisar; ++i){
            for(auto j(0); j<15; ++j){
                if(numeros_para_analise[i] == *(inicial + j)){
                    soma++;
                }
            }
        }

        // Verificar a ocorencia corresponde aos resultados possiveis
        int tamanho_do_vetor_resposta = respostas[posicao].size();
        bool marcador(true);
        for(auto i(0); i<tamanho_do_vetor_resposta; ++i){
            if(soma == respostas[posicao][i]){
                marcador = false;
                break;
            }
        }
        if(marcador){
            return false;
            break;
        }
    }

    return true;
}

bool analise_binario(int *inicial, int *numeros_para_analise, int quantidade_de_numeros_analisar, int *tamanho_amostra_vetor, int distancia_tamanho_amostra_vetor, std::vector < std::vector <int> > respostas){
    // Teste de capacidade máxima
    if(quantidade_de_numeros_analisar > 10){
        std::cout << "TAMANHO MÁXIMO DE ANÁLISE ATINGIDO" << std::endl;
        return 0;
    }    

    for(auto posicao(0); posicao < distancia_tamanho_amostra_vetor; ++posicao){
        // Correção de jogos para números de elementos
        int tamanho_amostra = ((tamanho_amostra_vetor[posicao] - 1) * 15);
        
        // Inicializar binário
        int binario[quantidade_de_numeros_analisar];
        for(auto i(0); i<quantidade_de_numeros_analisar; ++i){
            binario[i] = 0;
        }

        // Analisar e preencher o binário se a amostra for maior que 1 jogo
        for(auto i(0); i<quantidade_de_numeros_analisar; ++i){
            for(auto j(0); j<tamanho_amostra; ++j){
                if(numeros_para_analise[i] == *(std::end(numeros_sorteados) - 1 - j)){
                    binario[i] = 1;
                }
            }
        }

        // Analisar e preencher o binário para o jogo
        for(auto i(0); i<quantidade_de_numeros_analisar; ++i){
            for(auto j(0); j<15; ++j){
                if(numeros_para_analise[i] == *(inicial + j)){
                    binario[i] = 1;
                }
            }
        }

        // Gravar binário
        int binario_final(0);
        for(int i(0); i<quantidade_de_numeros_analisar; ++i){
            if(binario[i] == 1){
                binario_final += std::pow(10, i);
            }
        }

        // Verificar a ocorencia corresponde aos resultados possiveis
        int tamanho_do_vetor_resposta = respostas[posicao].size();
        bool marcador(true);
        for(auto i(0); i<tamanho_do_vetor_resposta; ++i){
            if(binario_final == respostas[posicao][i]){
                marcador = false;
                break;
            }
        }
        if(marcador){
            return false;
            break;
        }
    }

    return true;
}