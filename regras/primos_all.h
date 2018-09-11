/**
 * @brief Regras geradas pela analise dos númros Primos
 * 
 * @file primos_all.h
 * @author Allan de Miranda Silva
 * @date 10-09-2018
 */
#include <iterator>
#include <vector>
#include <algorithm>
#include <cmath>

bool primos_soma(int *inicial){
    bool bandeira;
    int numeros_p_analise[] = {2,3,5,7,11,13,17,19,23}; // números da cartela
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
    int numeros_verdade_um[] = {9, 10, 12, 14, 15, 17, 18, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 95, 97, 98, 100};
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
        int numeros_verdade_dois[] = {47, 48, 52, 53, 55, 58, 62, 64, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 176, 178, 180, 182, 190};
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

    // ter definição
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
        int numeros_verdade_dois[] = {79, 81, 104, 106, 107, 115, 116, 119, 121, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 237, 238, 239, 240, 241, 242, 246, 249, 250, 251, 252, 265};
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

bool primos_ocorrencias(int *inicial){
    // primeiro definição
    int numeros_p_analise[] = {2,3,5,7,11,13,17,19,23}; // números da cartela
    int cont(0);
    for(int *i=inicial; i<(inicial+15); ++i){
        for(int *j=std::begin(numeros_p_analise); j<std::end(numeros_p_analise); ++j){
            if(*i == *j){
                cont++;
                break;
            }
        }
    }
    if((cont < 3) or (cont > 8)){
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
        if(((cont + cont_analise_padrao) < 7) or ((cont + cont_analise_padrao) > 15)){        
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
        if(((cont + cont_analise_padrao) < 12) or ((cont + cont_analise_padrao) > 21)){
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
        if(((cont + cont_analise_padrao) < 23) or ((cont + cont_analise_padrao) > 32)){
            return false;
        }
    }    

    return true;
}

bool primos_binario(int *inicial){
    int tamanho_amostra;
    int numeros_p_analise[] = {2,3,5,7,11,13,17,19,23}; // números da cartela
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
        111, 1001, 1011, 1101, 1110, 1111, 10101, 10111, 11001, 11010, 11011, 11100, 11101, 11110, 
        11111, 100011, 100110, 100111, 101001, 101011, 101101, 101110, 101111, 110000, 110001, 110010, 
        110011, 110100, 110110, 110111, 111001, 111010, 111100, 111101, 111110, 111111, 1000011, 1000101, 
        1000111, 1001011, 1001101, 1001110, 1001111, 1010001, 1010010, 1010011, 1010101, 1010110, 1010111, 
        1011000, 1011001, 1011010, 1011011, 1011100, 1011101, 1011110, 1011111, 1100010, 1100011, 1100101,
         1100110, 1100111, 1101000, 1101001, 1101011, 1101100, 1101101, 1101110, 1101111, 1110000, 1110010,
          1110011, 1110100, 1110101, 1110110, 1110111, 1111000, 1111001, 1111010, 1111011, 1111100, 1111101, 
          1111110, 1111111, 10000011, 10000101, 10000110, 10000111, 10001001, 10001011, 10001100, 10001110, 
          10001111, 10010001, 10010010, 10010011, 10010101, 10010110, 10010111, 10011000, 10011001, 10011010, 
          10011011, 10011100, 10011101, 10011110, 10011111, 10100011, 10100101, 10100110, 10100111, 10101001,
           10101010, 10101011, 10101100, 10101101, 10101110, 10101111, 10110001, 10110010, 10110011, 10110100, 
           10110101, 10110110, 10110111, 10111000, 10111001, 10111010, 10111011, 10111100, 10111101, 10111110, 
           10111111, 11000001, 11000010, 11000011, 11000101, 11000110, 11000111, 11001000, 11001001, 11001011,
            11001100, 11001101, 11001110, 11001111, 11010001, 11010010, 11010011, 11010100, 11010101, 11010110,
             11010111, 11011000, 11011001, 11011010, 11011011, 11011100, 11011101, 11011110, 11011111, 11100000,
              11100001, 11100010, 11100011, 11100100, 11100101, 11100110, 11100111, 11101000, 11101001, 11101010,
               11101011, 11101100, 11101101, 11101110, 11101111, 11110000, 11110001, 11110010, 11110011, 11110100, 
               11110101, 11110110, 11110111, 11111000, 11111001, 11111010, 11111011, 11111100, 11111101, 11111110, 
               11111111, 100000110, 100000111, 100001000, 100001001, 100001010, 100001011, 100001100, 100001101, 
               100001110, 100010010, 100010100, 100010101, 100010110, 100010111, 100011001, 100011010, 100011011,
                100011101, 100011110, 100011111, 100100001, 100100010, 100100011, 100100100, 100100101, 100100111,
                 100101001, 100101010, 100101011, 100101101, 100101110, 100101111, 100110001, 100110010, 100110011, 
                 100110101, 100110110, 100110111, 100111001, 100111010, 100111011, 100111100, 100111101, 100111110,
                  100111111, 101000000, 101000001, 101000011, 101000101, 101000110, 101000111, 101001000, 101001001,
                   101001011, 101001100, 101001101, 101001110, 101001111, 101010000, 101010001, 101010011, 101010100,
                    101010101, 101010110, 101010111, 101011000, 101011001, 101011010, 101011011, 101011100, 101011101, 101011110, 101011111, 101100000, 101100001, 101100010, 101100011, 101100100, 101100101, 101100110, 101100111, 101101000, 101101001, 101101010, 101101011, 101101100, 101101101, 101101110, 101101111, 101110000, 101110001, 101110010, 101110011, 101110100, 101110101, 101110110, 101110111, 101111000, 101111001, 101111010, 101111011, 101111100, 101111101, 101111110, 101111111, 110000001, 110000011, 110000100, 110000101, 110000110, 110000111, 110001000, 110001010, 110001100, 110001101, 110001110, 110001111, 110010010, 110010011, 110010100, 110010101, 110010110, 110010111, 110011000, 110011001, 110011010, 110011011, 110011100, 110011101, 110011110, 110011111, 110100010, 110100011, 110100100, 110100101, 110100110, 110100111, 110101000, 110101001, 110101010, 110101011, 110101100, 110101101, 110101110, 110101111, 110110000, 110110001, 110110010, 110110011, 110110100, 110110101, 110110110, 110110111, 110111000, 110111001, 110111010, 110111011, 110111100, 110111101, 110111110, 110111111, 111000001, 111000010, 111000011, 111000100, 111000101, 111000110, 111000111, 111001000, 111001001, 111001010, 111001011, 111001100, 111001101, 111001110, 111001111, 111010000, 111010001, 111010010, 111010011, 111010101, 111010110, 111010111, 111011000, 111011001, 111011010, 111011011, 111011100, 111011101, 111011110, 111011111, 111100000, 111100001, 111100010, 111100011, 111100100, 111100101, 111100110, 111100111, 111101000, 111101001, 111101010, 111101011, 111101100, 111101101, 111101110, 111101111, 111110000, 111110001, 111110010, 111110011, 111110100, 111110101, 111110110, 111110111, 111111000, 111111001, 111111010, 111111011, 111111100, 111111101, 111111110, 111111111
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
            101111, 111011, 1010111, 1011011, 1011111, 1101101, 1101111, 1110111, 1111011, 
            1111101, 1111111, 10011110, 10011111, 10101111, 10110110, 10110111, 10111011, 
            10111101, 10111110, 10111111, 11000111, 11001001, 11001111, 11010111, 11011011,
             11011110, 11011111, 11100000, 11100111, 11101011, 11101101, 11101110, 11101111,
              11110101, 11110111, 11111010, 11111011, 11111100, 11111101, 11111110, 11111111, 
              100011111, 100101111, 100111010, 100111011, 100111101, 100111110, 100111111, 101001111,
               101011011, 101011101, 101011111, 101100101, 101101011, 101101100, 101101101, 101101111, 
               101110001, 101110011, 101110110, 101110111, 101111001, 101111011, 101111100, 101111101,
                101111110, 101111111, 110011011, 110011101, 110011110, 110011111, 110100011, 110101011, 
                110101101, 110101110, 110101111, 110110011, 110110110, 110110111, 110111001, 110111010, 
                110111011, 110111101, 110111110, 110111111, 111000011, 111000111, 111001011, 111001110, 
                111001111, 111010010, 111010011, 111010110, 111010111, 111011001, 111011011, 111011100, 
                111011101, 111011110, 111011111, 111100001, 111100011, 111100101, 111100110, 111100111, 
                111101001, 111101010, 111101011, 111101100, 111101101, 111101110, 111101111, 111110001, 
                111110010, 111110011, 111110101, 111110110, 111110111, 111111001, 111111010, 111111011, 
                111111100, 111111101, 111111110, 111111111
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
            1111111, 10111011, 10111101, 10111111, 11011111, 11101001, 11101111, 11110111, 11111011, 
            11111101, 11111110, 11111111, 100111111, 101011111, 101110111, 101111001, 101111011, 101111101, 
            101111110, 101111111, 110011011, 110011111, 110101111, 110110111, 110111101, 110111110, 110111111, 
            111001111, 111010111, 111011110, 111011111, 111100111, 111101011, 111101110, 111101111, 
            111110011, 111110110, 111110111, 111111010, 111111011, 111111101, 111111110, 111111111
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
            11111111, 101111111, 110111111, 111011111, 111101111, 111110111, 111111011, 111111110, 111111111
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
                111111111
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

/**
 * @brief Função que verifica somente todas as regras Primos
 * 
 * @param primeiro Aponta para o primeiro número do jogo que queremos analisar
 * @return true Para se todas as regras estão valendo
 * @return false Para se pelomenos uma regra não está valendo
 */
bool regras_gerais_primos(int *primeiro){
    if(primos_soma(primeiro)){
        if(primos_ocorrencias(primeiro)){
            if(primos_binario(primeiro)){
                return true;                
            }            
        }        
    }
    return false;
}