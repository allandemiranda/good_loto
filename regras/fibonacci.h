/**
 * @brief Regras geradas pela analise dos númros de fibonacci
 * 
 * @file fibonacci.h
 * @author Allan de Miranda Silva
 * @date 08-09-2018
 */
#include "../analise/numeros_sorteados.h"
#include <iterator>
#include <vector>
#include <algorithm>
#include <cmath>

bool fibonacci_soma(int *inicial){ 
    // primeiro definição
    int numeros_p_analise[] = {1,2,3,5,8,13,21}; // números Fibonacci da cartela
    int soma(0);
    for(int *i=inicial; i<(inicial+15); ++i){
        for(int *j=std::begin(numeros_p_analise); j<std::end(numeros_p_analise); ++j){
            if(*i == *j){
                soma += *i;
                break;
            }
        }
    }
    if((soma == 0) or (soma == 1) or (soma == 2) or (soma == 4) or (soma == 5) or (soma == 7) or (soma == 12) or (soma > 53)){
        return false;
    }

    int quantidade_de_jogos_sorteados = std::distance(std::begin(numeros_sorteados), std::end(numeros_sorteados)) / 15;
    int analise_padrao;
    int soma_analise_padrao;

    // segunda definição
    analise_padrao = 2;
    if((quantidade_de_jogos_sorteados+1)%analise_padrao != 0){
        return true;
    }
    soma_analise_padrao = 0;
    for(int *i=((std::begin(numeros_sorteados))+(15*(quantidade_de_jogos_sorteados + 2 - analise_padrao))); i<std::end(numeros_sorteados); ++i){
        for(int *j=std::begin(numeros_p_analise); j<std::end(numeros_p_analise); ++j){
            if(*i == *j){
                soma_analise_padrao += *i;
                break;
            }
        }
    }
    if(((soma + soma_analise_padrao) < 20) or ((soma + soma_analise_padrao) > 100)){
        return false;
    }

    //fim
    return true;  
}

bool fibonacci_ocorrencias(int *inicial){
    // primeiro definição
    int numeros_p_analise[] = {1,2,3,5,8,13,21}; // números Fibonacci da cartela
    int cont(0);
    for(int *i=inicial; i<(inicial+15); ++i){
        for(int *j=std::begin(numeros_p_analise); j<std::end(numeros_p_analise); ++j){
            if(*i == *j){
                cont++;
                break;
            }
        }
    }
    if((cont < 2) or (cont > 7)){
        return false;
    }

    int quantidade_de_jogos_sorteados = std::distance(std::begin(numeros_sorteados), std::end(numeros_sorteados)) / 15;
    int analise_padrao;
    int cont_analise_padrao;

    // segunda definição
    analise_padrao = 2;
    if((quantidade_de_jogos_sorteados+1)%analise_padrao != 0){
        return true;
    }
    cont_analise_padrao = 0;
    for(int *i=((std::begin(numeros_sorteados))+(15*(quantidade_de_jogos_sorteados + 2 - analise_padrao))); i<std::end(numeros_sorteados); ++i){
        for(int *j=std::begin(numeros_p_analise); j<std::end(numeros_p_analise); ++j){
            if(*i == *j){
                cont_analise_padrao++;
                break;
            }
        }
    }
    if(((cont + cont_analise_padrao) < 5) or ((cont + cont_analise_padrao) > 12)){
        return false;
    }

    // terceira definição
    analise_padrao = 3;
    if((quantidade_de_jogos_sorteados+1)%analise_padrao != 0){
        return true;
    }
    cont_analise_padrao = 0;
    for(int *i=((std::begin(numeros_sorteados))+(15*(quantidade_de_jogos_sorteados + 2 - analise_padrao))); i<std::end(numeros_sorteados); ++i){
        for(int *j=std::begin(numeros_p_analise); j<std::end(numeros_p_analise); ++j){
            if(*i == *j){
                cont_analise_padrao++;
                break;
            }
        }
    }
    if(((cont + cont_analise_padrao) < 9) or ((cont + cont_analise_padrao) > 16)){
        return false;
    }

    // quarta definição
    analise_padrao = 5;
    if((quantidade_de_jogos_sorteados+1)%analise_padrao != 0){
        return true;
    }
    cont_analise_padrao = 0;
    for(int *i=((std::begin(numeros_sorteados))+(15*(quantidade_de_jogos_sorteados + 2 - analise_padrao))); i<std::end(numeros_sorteados); ++i){
        for(int *j=std::begin(numeros_p_analise); j<std::end(numeros_p_analise); ++j){
            if(*i == *j){
                cont_analise_padrao++;
                break;
            }
        }
    }
    if(((cont + cont_analise_padrao) < 17) or ((cont + cont_analise_padrao) > 25)){
        return false;
    }

    // quinta definição
    analise_padrao = 8;
    if((quantidade_de_jogos_sorteados+1)%analise_padrao != 0){
        return true;
    }
    cont_analise_padrao = 0;
    for(int *i=((std::begin(numeros_sorteados))+(15*(quantidade_de_jogos_sorteados + 2 - analise_padrao))); i<std::end(numeros_sorteados); ++i){
        for(int *j=std::begin(numeros_p_analise); j<std::end(numeros_p_analise); ++j){
            if(*i == *j){
                cont_analise_padrao++;
                break;
            }
        }
    }
    if(((cont + cont_analise_padrao) < 30) or ((cont + cont_analise_padrao) > 38)){
        return false;
    }

    //fim
    return true;  
}

bool fibonacci_binario(int *inicial){
    //primeira analise
    int tamanho_amostra;
    int numeros_p_analise[] = {1,2,3,5,8,13,21}; // números Fibonacci da cartela
    int tamanho_analise = std::distance(std::begin(numeros_p_analise), std::end(numeros_p_analise));          
    int binario[tamanho_analise];
    int posicao;
    int binario_final;
    std::vector <int> novo_jogo; 
    int quantidade_de_jogos_sorteados = std::distance(std::begin(numeros_sorteados), std::end(numeros_sorteados)) / 15;


    tamanho_amostra = 2; // Dois jogos
    if((quantidade_de_jogos_sorteados+1)%tamanho_amostra != 0){
        return true;
    }
    for(int *i=inicial; i<(inicial+15); ++i){
        novo_jogo.push_back(*i);
    }
    for(int *i=((std::begin(numeros_sorteados))+(15*(quantidade_de_jogos_sorteados + 2 - tamanho_amostra))); i<std::end(numeros_sorteados); ++i){
        novo_jogo.push_back(*i);
    }

    for(int j(0); j<tamanho_analise; ++j){
        binario[j] = 0;
    }
    
    posicao = 0;
    for(auto *j = std::begin(numeros_p_analise); j<std::end(numeros_p_analise); ++j){
        for(auto k(0); k<tamanho_amostra*15; ++k){
            if(*j == *(inicial+k)){
                binario[posicao] = 1;
            }
        }
        ++posicao;
    }
    binario_final = 0;
    for(int j(0); j<tamanho_analise; ++j){
        if(binario[j]==1){
            binario_final += std::pow(10, j);
        }
    }
    novo_jogo.clear();    

    // análise ### Modificar variáveis
    int lista_um [] = {
        1111, 10111, 11010, 11011, 11100, 11101, 11110, 11111, 100101, 100111, 101011, 
        101100, 101101, 101110, 101111, 110011, 110101, 110111, 111010, 
        111011, 111100, 111101, 111110, 111111, 1000111, 1001001, 1001011, 
        1001101, 1001110, 1001111, 1010011, 1010101, 1010111, 1011011, 1011100, 
        1011101, 1011110, 1011111, 1100011, 1100101, 1100111, 1101000, 1101001, 
        1101010, 1101011, 1101100, 1101101, 1101110, 1101111, 1110001, 1110010, 
        1110011, 1110100, 1110101, 1110110, 1110111, 1111000, 1111001, 1111010, 
        1111011, 1111100, 1111101, 1111110, 1111111
    };
    bool flag_um(true);
    for(int *i=std::begin(lista_um); i<std::end(lista_um); ++i){
        if(binario_final == *i){
            flag_um = false;
            break;
        }
    }
    if(flag_um){
        return false;
    }


    return true;
}