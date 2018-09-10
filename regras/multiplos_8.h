/**
 * @brief Regras geradas pela analise dos númros multilos de 8
 * 
 * @file multiplos_8.h
 * @author Allan de Miranda Silva
 * @date 10-09-2018
 */
#include <iterator>
#include <vector>
#include <algorithm>
#include <cmath>

bool multiplos_8_soma(int *inicial){
    bool bandeira;
    int numeros_p_analise[] = {8,16,24}; // números da cartela
    int soma(0);

    //...

    int quantidade_de_jogos_sorteados = std::distance(std::begin(numeros_sorteados), std::end(numeros_sorteados)) / 15;
    int analise_padrao;
    int soma_analise_padrao;

    // primeira definição
    analise_padrao = 2;
    bandeira = true;
    if((quantidade_de_jogos_sorteados+analise_padrao-1)%analise_padrao == 0){
        soma_analise_padrao = 0;
        for(int *i=((std::begin(numeros_sorteados))+(15*(quantidade_de_jogos_sorteados + 1 - analise_padrao))); i<std::end(numeros_sorteados); ++i){
            for(int *j=std::begin(numeros_p_analise); j<std::end(numeros_p_analise); ++j){            
                if(*i == *j){
                    soma_analise_padrao += *i;
                    break;
                }
            }
        }
        int numeros_verdade_dois[] = {8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96};
        for(int *i=std::begin(numeros_verdade_dois); i<std::end(numeros_verdade_dois); ++i){
            if(*i == (soma_analise_padrao + soma)){
                bandeira = false;
                break;
            }
        }
        if(bandeira){
            return false;
        }
    }

    // segunda definição
    analise_padrao = 3;
    bandeira = true;
    if((quantidade_de_jogos_sorteados+analise_padrao-1)%analise_padrao == 0){
        soma_analise_padrao = 0;
        for(int *i=((std::begin(numeros_sorteados))+(15*(quantidade_de_jogos_sorteados + 1 - analise_padrao))); i<std::end(numeros_sorteados); ++i){
            for(int *j=std::begin(numeros_p_analise); j<std::end(numeros_p_analise); ++j){            
                if(*i == *j){
                    soma_analise_padrao += *i;
                    break;
                }
            }
        }
        int numeros_verdade_dois[] = {40, 48, 56, 64, 72, 80, 88, 96, 104, 112, 120, 128};
        for(int *i=std::begin(numeros_verdade_dois); i<std::end(numeros_verdade_dois); ++i){
            if(*i == (soma_analise_padrao + soma)){
                bandeira = false;
                break;
            }
        }
        if(bandeira){
            return false;
        }
    }
    
    // fim
    return true;
}

bool multiplos_8_ocorrencias(int *inicial){
    // primeiro definição
    int numeros_p_analise[] = {8,16,24}; // números  da cartela
    int cont(0);
    
    //...

    int quantidade_de_jogos_sorteados = std::distance(std::begin(numeros_sorteados), std::end(numeros_sorteados)) / 15;
    int analise_padrao;
    int cont_analise_padrao;

    // segunda definição
    analise_padrao = 2;
    if((quantidade_de_jogos_sorteados+analise_padrao-1)%analise_padrao == 0){
        cont_analise_padrao = 0;
        for(int *i=((std::begin(numeros_sorteados))+(15*(quantidade_de_jogos_sorteados + 1 - analise_padrao))); i<std::end(numeros_sorteados); ++i){
            for(int *j=std::begin(numeros_p_analise); j<std::end(numeros_p_analise); ++j){            
                if(*i == *j){
                    cont_analise_padrao++;
                    break;
                }
            }
        }
        if(((cont + cont_analise_padrao) < 1) or ((cont + cont_analise_padrao) > 6)){        
            return false;
        }
    }

    // terceira definição
    analise_padrao = 3;
    if((quantidade_de_jogos_sorteados+analise_padrao-1)%analise_padrao == 0){
        cont_analise_padrao = 0;
        for(int *i=((std::begin(numeros_sorteados))+(15*(quantidade_de_jogos_sorteados + 1 - analise_padrao))); i<std::end(numeros_sorteados); ++i){
            for(int *j=std::begin(numeros_p_analise); j<std::end(numeros_p_analise); ++j){            
                if(*i == *j){
                    cont_analise_padrao++;
                    break;
                }
            }
        }
        if(((cont + cont_analise_padrao) < 2) or ((cont + cont_analise_padrao) > 8)){
            return false;
        }
    }
    

    // quarta definição
    analise_padrao = 5;
    if((quantidade_de_jogos_sorteados+analise_padrao-1)%analise_padrao == 0){
        cont_analise_padrao = 0;
        for(int *i=((std::begin(numeros_sorteados))+(15*(quantidade_de_jogos_sorteados + 1 - analise_padrao))); i<std::end(numeros_sorteados); ++i){
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
    }    

    return true;
}

bool multiplos_8_binario(int *inicial){
    int tamanho_amostra;
    int numeros_p_analise[] = {8,16,24}; // números da cartela
    int tamanho_analise = std::distance(std::begin(numeros_p_analise), std::end(numeros_p_analise));          
    int binario[tamanho_analise];
    int posicao;
    int binario_final;
    std::vector <int> novo_jogo; 
    int quantidade_de_jogos_sorteados = std::distance(std::begin(numeros_sorteados), std::end(numeros_sorteados)) / 15;

    //...

    //segunda analise
    tamanho_amostra = 3; // jogos
    if((quantidade_de_jogos_sorteados+tamanho_amostra-1)%tamanho_amostra == 0){
        for(int *i=inicial; i<(inicial+15); ++i){
            novo_jogo.push_back(*i);
        }
        for(int *i=((std::begin(numeros_sorteados))+(15*(quantidade_de_jogos_sorteados + 1 - tamanho_amostra))); i<std::end(numeros_sorteados); ++i){
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
            1, 10, 11, 100, 101, 110, 111
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
    }
    

    //terceira analise
    tamanho_amostra = 5; // jogos
    if((quantidade_de_jogos_sorteados+tamanho_amostra-1)%tamanho_amostra == 0){
        for(int *i=inicial; i<(inicial+15); ++i){
            novo_jogo.push_back(*i);
        }
        for(int *i=((std::begin(numeros_sorteados))+(15*(quantidade_de_jogos_sorteados + 1 - tamanho_amostra))); i<std::end(numeros_sorteados); ++i){
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
            11, 101, 110, 111
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
    }   

    //quinta analise
    int numeros_adicionais[] = {8, 13, 21, 34, 55, 89, 144};
    for(int *k=std::begin(numeros_adicionais); k<std::end(numeros_adicionais); ++k){
        tamanho_amostra = *k; // jogos
        if((quantidade_de_jogos_sorteados+tamanho_amostra-1)%tamanho_amostra == 0){
            for(int *i=inicial; i<(inicial+15); ++i){
                novo_jogo.push_back(*i);
            }
            for(int *i=((std::begin(numeros_sorteados))+(15*(quantidade_de_jogos_sorteados + 1 - tamanho_amostra))); i<std::end(numeros_sorteados); ++i){
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
                111
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
        }
    }    
    
    return true;
}