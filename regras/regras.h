/**
 * @brief Inclui o gerenciamento das regras globais a ser analisada por suas especificações
 * 
 * @file regras.h
 * @author Allan de Miranda Silva
 * @date 09-09-2018
 */
#include "../analise/numeros_sorteados.h" // Para as regras funcionarem
#include "fibonacci.h" // Regras de Fibonacci
#include "multiplos_3.h" // Regras multiplos de 3
#include "multiplos_4.h" // Regras multiplos de 4
#include "multiplos_5.h" // Regras multiplos de 5
#include "multiplos_6.h" // Regras multiplos de 6
#include "multiplos_7.h" // Regras multiplos de 7
#include "multiplos_8.h" // Regras multiplos de 8
#include "multiplos_9.h" // Regras multiplos de 9
#include "multiplos_10.h" // Regras multiplos de 10
#include "multiplos_11.h" // Regras multiplos de 11
#include "multiplos_12.h" // Regras multiplos de 12


/**
 * @brief Função que verifica todas as regras
 * 
 * @param primeiro Aponta para o primeiro número do jogo que queremos analisar
 * @return true Para se todas as regras estão valendo
 * @return false Para se pelomenos uma regra não está valendo
 */
bool regras_gerais(int *primeiro){
    if(fibonacci_soma(primeiro)){
        if(fibonacci_ocorrencias(primeiro)){
            if(fibonacci_binario(primeiro)){
                if(multiplos_3_soma(primeiro)){
                    if(multiplos_3_ocorrencias(primeiro)){
                        if(multiplos_3_binario(primeiro)){
                            if(multiplos_4_soma(primeiro)){
                                if(multiplos_4_ocorrencias(primeiro)){
                                    if(multiplos_4_binario(primeiro)){
                                        if(multiplos_5_soma(primeiro)){
                                            if(multiplos_5_ocorrencias(primeiro)){
                                                if(multiplos_5_binario(primeiro)){
                                                    if(multiplos_6_soma(primeiro)){
                                                        if(multiplos_6_ocorrencias(primeiro)){
                                                            if(multiplos_6_binario(primeiro)){
                                                                if(multiplos_7_soma(primeiro)){
                                                                    if(multiplos_7_ocorrencias(primeiro)){
                                                                        if(multiplos_7_binario(primeiro)){
                                                                            if(multiplos_8_soma(primeiro)){
                                                                                if(multiplos_8_ocorrencias(primeiro)){
                                                                                    if(multiplos_8_binario(primeiro)){
                                                                                        if(multiplos_9_soma(primeiro)){
                                                                                            if(multiplos_9_ocorrencias(primeiro)){
                                                                                                if(multiplos_9_binario(primeiro)){
                                                                                                    if(multiplos_10_soma(primeiro)){
                                                                                                        if(multiplos_10_ocorrencias(primeiro)){
                                                                                                            if(multiplos_10_binario(primeiro)){
                                                                                                                if(multiplos_11_soma(primeiro)){
                                                                                                                    if(multiplos_11_ocorrencias(primeiro)){
                                                                                                                        if(multiplos_11_binario(primeiro)){
                                                                                                                            if(multiplos_12_soma(primeiro)){
                                                                                                                                if(multiplos_12_ocorrencias(primeiro)){
                                                                                                                                    if(multiplos_12_binario(primeiro)){
                                                                                                                                        return true;
                                                                                                                                    } 
                                                                                                                                }
                                                                                                                            }
                                                                                                                        } 
                                                                                                                    }
                                                                                                                }
                                                                                                            } 
                                                                                                        }
                                                                                                    }
                                                                                                } 
                                                                                            }
                                                                                        }
                                                                                    } 
                                                                                }
                                                                            }
                                                                        } 
                                                                    }
                                                                }
                                                            } 
                                                        }
                                                    }
                                                } 
                                            }
                                        }
                                    } 
                                }
                            }
                        }
                    }
                }                
            }            
        }        
    }

    return false;
}

