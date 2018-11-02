/**
 * @file combinacoes.cpp
 * @author Allan de Miranda Silva (allandemrianda@gmail.com)
 * @brief 
 * @version 1.0
 * @date 01-11-2018
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#include <stdexcept>
#include <vector>

#include "../include/combinacoes.h"

combinacoes::combinacoes(std::vector <unsigned short int> volante, unsigned long int tamanho_do_jogo){
    if((volante.size() == 0) or (tamanho_do_jogo == 0) or (tamanho_do_jogo > volante.size())){
        throw std::runtime_error( "Erro ao tentar gerar combinações" );
    }  else {
        if(tamanho_do_jogo == volante.size()){
            todas_combinacoes.push_back(volante);
        } else {
            std::vector <unsigned short int> temp;

            unsigned long int quantidade_numeros_possiveis_de_sair = volante.size();
            unsigned long int quantidade_numeros_sortear = tamanho_do_jogo;

            // gerador
            std::vector <unsigned short int> ponteiros;
            for(unsigned short int i(1); i<=quantidade_numeros_sortear; ++i){
                ponteiros.push_back(i);
            }

            while(true){
                // imprimir
                for(unsigned short int i : ponteiros){
                    temp.push_back(i);
                } 

                bool aqui_flag(false);

                for(auto i(ponteiros.size()-1); i>=0; --i){
                    // somar mais um
                    ponteiros[i] += 1;

                    if(ponteiros[i] > quantidade_numeros_possiveis_de_sair){
                        continue;
                    }

                    if((false) == (i < (ponteiros.size()-1))){                
                        break;
                    }

                    for(auto j = (i+1); j<ponteiros.size(); ++j){
                        ponteiros[j] = 1 + ponteiros[j-1];
                    }

                    bool fim = false;
                    for(auto j = (i+1); j<ponteiros.size(); ++j){
                        if(ponteiros[j] > quantidade_numeros_possiveis_de_sair){                    
                            fim = true;      
                            break;               
                        }
                    }
                    if(!fim){
                        break;
                    }
                    
                    if(i == 0){
                        if(ponteiros.back() > quantidade_numeros_possiveis_de_sair){
                            // return EXIT_SUCCESS;
                            // criação do vetor final
                            for(auto k(0); k<(temp.size()/quantidade_numeros_sortear); ++k){
                                std::vector <unsigned short int> novo_t_temp;
                                for(auto m(0); m<quantidade_numeros_sortear; ++m){
                                    auto temp_variavel_posi = temp[(k*quantidade_numeros_sortear)+m];
                                    --temp_variavel_posi;
                                    novo_t_temp.push_back(volante[temp_variavel_posi]);
                                }
                                todas_combinacoes.push_back(novo_t_temp);
                            }
                            aqui_flag = true;
                            break;
                        }
                    }
                }
                if(aqui_flag){
                    break;
                }
            }
        }        
    }
}

unsigned long int combinacoes::quantidade(void){
    return todas_combinacoes.size();
}

std::vector <unsigned short int> combinacoes::combinacao(unsigned short int posicao){
    if(posicao<1){
        throw std::runtime_error( "Erro ao acessar combinações" );
    } else {
        --posicao;
        return todas_combinacoes[posicao];
    }
}