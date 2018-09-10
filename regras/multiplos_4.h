/**
 * @brief Regras geradas pela analise dos númros multilos de 4
 * 
 * @file multiplos_4.h
 * @author Allan de Miranda Silva
 * @date 10-09-2018
 */
#include <iterator>
#include <vector>
#include <algorithm>
#include <cmath>

bool multiplos_4_soma(int *inicial){
    bool bandeira;
    int numeros_p_analise[] = {4,8,12,16,20,24}; // números da cartela
    int soma(0);

    // primeiro definição    
    bandeira = true;
    for(int *i=inicial; i<(inicial+15); ++i){
        for(int *j=std::begin(numeros_p_analise); j<std::end(numeros_p_analise); ++j){
            if(*i == *j){
                soma += *i;
                break;
            }
        }
    }
        //### Editar variaveis
    int numeros_verdade_um[] = {4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60, 64, 68, 72, 76, 80, 84};
    for(int *i=std::begin(numeros_verdade_um); i<std::end(numeros_verdade_um); ++i){
        if(*i == soma){
            bandeira = false;
            break;
        }
    }
    if(bandeira){
        return false;        
    }

    int quantidade_de_jogos_sorteados = std::distance(std::begin(numeros_sorteados), std::end(numeros_sorteados)) / 15;
    int analise_padrao;
    int soma_analise_padrao;

    // segunda definição
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
        int numeros_verdade_dois[] = {28, 36, 40, 44, 48, 52, 56, 60, 64, 68, 72, 76, 80, 84, 88, 92, 96, 100, 104, 108, 112, 116, 120, 124, 128, 132, 136, 140, 144, 148, 152, 156};
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

bool multiplos_4_ocorrencias(int *inicial){
    // primeiro definição
    int numeros_p_analise[] = {4,8,12,16,20,24}; // números  da cartela
    int cont(0);
    for(int *i=inicial; i<(inicial+15); ++i){
        for(int *j=std::begin(numeros_p_analise); j<std::end(numeros_p_analise); ++j){
            if(*i == *j){
                cont++;
                break;
            }
        }
    }
    if((cont < 2) or (cont > 5)){
        return false;        
    }

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
        if(((cont + cont_analise_padrao) < 4) or ((cont + cont_analise_padrao) > 10)){        
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
        if(((cont + cont_analise_padrao) < 6) or ((cont + cont_analise_padrao) > 15)){
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
        if(((cont + cont_analise_padrao) < 13) or ((cont + cont_analise_padrao) > 22)){
            return false;
        }
    }    

    return true;
}

bool multiplos_4_binario(int *inicial){
    int tamanho_amostra;
    int numeros_p_analise[] = {4,8,12,16,20,24}; // números da cartela
    int tamanho_analise = std::distance(std::begin(numeros_p_analise), std::end(numeros_p_analise));          
    int binario[tamanho_analise];
    int posicao;
    int binario_final;
    std::vector <int> novo_jogo; 
    int quantidade_de_jogos_sorteados = std::distance(std::begin(numeros_sorteados), std::end(numeros_sorteados)) / 15;

    //primeira analise
    
    for(int *i=inicial; i<(inicial+15); ++i){
        novo_jogo.push_back(*i);
    }
    
    for(int j(0); j<tamanho_analise; ++j){
        binario[j] = 0;
    }
    
    posicao = 0;
    for(auto *j = std::begin(numeros_p_analise); j<std::end(numeros_p_analise); ++j){
        for(auto k(0); k<15; ++k){
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
        1, 10, 11, 100, 101, 110, 111, 1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111, 
        10000, 10001, 10010, 10011, 10100, 10101, 10110, 10111, 11000, 11001, 11010, 
        11011, 11100, 11101, 11110, 11111, 100000, 100001, 100010, 100011, 100100, 100101, 
        100110, 100111, 101000, 101001, 101010, 101011, 101100, 101101, 101110, 101111, 
        110000, 110001, 110010, 110011, 110100, 110101, 110110, 110111, 111000, 111001, 
        111010, 111011, 111100, 111101, 111110, 111111
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

    //segunda analise
    tamanho_amostra = 2; // Dois jogos
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
            111, 1001, 1011, 1100, 1110, 1111, 10001, 10010, 10011, 10101, 10110, 10111, 
            11001, 11010, 11011, 11100, 11101, 11110, 11111, 100101, 100111, 101000, 101011, 
            101100, 101101, 101110, 101111, 110001, 110010, 110011, 110101, 110110, 110111,
            111000, 111001, 111010, 111011, 111100, 111101, 111110, 111111
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
    tamanho_amostra = 3; // três jogos
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
            1110, 1111, 10111, 11011, 11101, 11110, 11111, 100111, 101011, 101101, 101111, 
            110101, 110110, 110111, 111001, 111011, 111100, 111101, 111110, 111111
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

    //quarta analise
    tamanho_amostra = 5; // cinco jogos
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
            11111, 101111, 110111, 111011, 111101, 111110, 111111
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
                1111111
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