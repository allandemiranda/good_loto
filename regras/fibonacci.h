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
    
    int tamanho_amostra;
    int numeros_p_analise[] = {1,2,3,5,8,13,21}; // números Fibonacci da cartela
    int tamanho_analise = std::distance(std::begin(numeros_p_analise), std::end(numeros_p_analise));          
    int binario[tamanho_analise];
    int posicao;
    int binario_final;
    std::vector <int> novo_jogo; 
    int quantidade_de_jogos_sorteados = std::distance(std::begin(numeros_sorteados), std::end(numeros_sorteados)) / 15;

    //primeira analise
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
            if(*j == novo_jogo[k]){
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

        // #### análise ### Modificar variáveis
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

    //segunda analise
    tamanho_amostra = 3; // três jogos
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
            if(*j == novo_jogo[k]){
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

        // #### análise ### Modificar variáveis
    int lista_dois [] = {
        11111, 100111, 101111, 110111, 111011, 111101, 111110, 111111, 1010111, 1011101, 1011111, 
        1100111, 1101011, 1101101, 1101111, 1110011, 1110101, 1110110, 1110111, 1111010, 1111011, 
        1111100, 1111101, 1111110, 1111111
    };
    bool flag_dois(true);
    for(int *i=std::begin(lista_dois); i<std::end(lista_dois); ++i){
        if(binario_final == *i){
            flag_dois = false;
            break;
        }
    }
    if(flag_dois){
        return false;
    }

    //terceiro analise
    tamanho_amostra = 5; // cinco jogos
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
            if(*j == novo_jogo[k]){
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

        // #### análise ### Modificar variáveis
    int lista_tres [] = {
        111111, 1011111, 1101111, 1110111, 1111101, 1111110, 1111111
    };
    bool flag_tres(true);
    for(int *i=std::begin(lista_tres); i<std::end(lista_tres); ++i){
        if(binario_final == *i){
            flag_tres = false;
            break;
        }
    }
    if(flag_tres){
        return false;
    }

    //quarto analise
    int numeros_adicionais[] = {8, 13, 21, 34, 55, 89, 144};
    for(int *k=std::begin(numeros_adicionais); k<std::end(numeros_adicionais); ++k){
        tamanho_amostra = *k; // jogos
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
                if(*j == novo_jogo[k]){
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
        if(binario_final != 1111111){
            return false;
        }
    }

    //ANALISE EXTRA POR ERRO INICIAL
    tamanho_amostra = 1; // cinco jogos
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
            if(*j == novo_jogo[k]){
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

        // #### análise ### Modificar variáveis
    int lista_extra [] = {
        10, 11, 100, 101, 110, 111, 1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111, 10001, 10010, 
        10011, 10100, 10101, 10110, 10111, 11000, 11001, 11010, 11011, 11100, 11101, 11110, 11111, 
        100001, 100010, 100011, 100100, 100101, 100110, 100111, 101000, 101001, 101010, 101011, 101100, 
        101101, 101110, 101111, 110000, 110001, 110010, 110011, 110100, 110101, 110110, 110111, 111000, 
        111001, 111010, 111011, 111100, 111101, 111110, 111111, 1000000, 1000001, 1000010, 1000011, 
        1000100, 1000101, 1000110, 1000111, 1001000, 1001001, 1001010, 1001011, 1001100, 1001101, 1001110, 
        1001111, 1010000, 1010001, 1010010, 1010011, 1010100, 1010101, 1010110, 1010111, 1011000, 1011001, 
        1011010, 1011011, 1011100, 1011101, 1011110, 1011111, 1100000, 1100001, 1100010, 1100011, 1100100, 
        1100101, 1100110, 1100111, 1101000, 1101001, 1101010, 1101011, 1101100, 1101101, 1101110, 1101111, 
        1110000, 1110001, 1110010, 1110011, 1110100, 1110101, 1110110, 1110111, 1111000, 1111001, 1111010, 
        1111011, 1111100, 1111101, 1111110, 1111111
    };
    bool flag_extra(true);
    for(int *i=std::begin(lista_extra); i<std::end(lista_extra); ++i){
        if(binario_final == *i){
            flag_extra = false;
            break;
        }
    }
    if(flag_extra){
        return false;
    }
    
    return true;
}

bool fibonacci_ciclo(int *inicial){
    int numeros_p_analise[] = {1,2,3,5,8,13,21}; // números Fibonacci da cartela
    int conte_ciclo(0);
    bool flag_conte_ciclo = false;
    for(int *i=std::end(numeros_sorteados)-1; i>=std::begin(numeros_sorteados); --i, ++conte_ciclo){
        for(int *j=std::begin(numeros_p_analise); j<std::end(numeros_p_analise); ++j){
            if(*i == *j){
                flag_conte_ciclo = true;
                break;
            }
        }
        if(flag_conte_ciclo){
            break;
        }
    }
    if((conte_ciclo + 15) != 20){
        return true;
    }
    for(int *i=inicial; i<(inicial+15); ++i){
        for(int *j=std::begin(numeros_p_analise); j<std::end(numeros_p_analise); ++j){
            if(*i == *j){
                return true;
            }
        }
    }
    return false;
}