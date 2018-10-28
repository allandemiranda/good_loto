/**
 * @file loto.cpp
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief Arquivo com funções da class loto
 * @version 0.1
 * @date 2018-10-28
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#include <algorithm>
#include <omp.h> // -fopenmp

//#include "loto.h"
#include "../include/loto.h"

/**
 * @brief Verificar quantidade de jogos sorteados que já existe na lista
 * 
 * @return unsigned long int Retorna quantidade
 */
unsigned long int loto::quantidade_jogos_sorteados(void){
    return (jogos_sorteados.size()/tamanho_dos_jogos);
}

/**
 * @brief Adicionar novo jogopossivel
 * 
 * @param jogo Jogo que deve ser adicionado
 * @return unsigned long int Posição que ele foi adicionado
 */
unsigned long int loto::adicionar_jogos_possiveis(std::vector <unsigned short int> jogo){
    jogos_possiveis.push_back(jogo);
    return (jogos_possiveis.size()/tamanho_dos_jogos);
}

/**
 * @brief 
 * 
 * @return unsigned long int 
 */
unsigned long int loto::tamanho_dos_jogos_usados(void){
    return tamanho_dos_jogos;
}

/**
 * @brief 
 * 
 * @return unsigned long int 
 */
unsigned long int loto::quantidade_jogos_possiveis(void){
    return (jogos_possiveis.size()/tamanho_dos_jogos);
}
/**
 * @brief 
 * 
 * @param posicao 
 */
void loto::apagar_jogo_possivel(unsigned long int posicao){
    jogos_possiveis.erase(jogos_possiveis.begin()+posicao);
}

/**
 * @brief 
 * 
 * @param tamanho 
 */
void loto::gerar_tamanho_dos_jogos(unsigned long int tamanho){
    tamanho_dos_jogos = tamanho;
}

/**
 * @brief 
 * 
 * @param valor 
 */
void loto::adicionar_limites_da_soma_superior(unsigned long int valor){
    limites_da_soma_superior = valor;
}

/**
 * @brief 
 * 
 * @param valor 
 */
void loto::adicionar_limites_da_soma_inferior(unsigned long int valor){
    limites_da_soma_inferior = valor;
}

/**
 * @brief 
 * 
 * @param valor 
 */
void loto::adicionar_limites_da_sequencia_superior(unsigned long int valor){
    limites_da_sequencia_superior = valor;
}

/**
 * @brief 
 * 
 * @param valor 
 */
void loto::adicionar_limites_da_sequencia_inferior(unsigned long int valor){
    limites_da_sequencia_inferior = valor;
}

/**
 * @brief 
 * 
 * @param valor 
 */
void loto::adicionar_limites_dos_numeros_primos_superior(unsigned long int valor){
    limites_dos_numeros_primos_superior = valor;
}

/**
 * @brief 
 * 
 * @param valor 
 */
void loto::adicionar_limites_dos_numeros_primos_inferior(unsigned long int valor){
    limites_dos_numeros_primos_inferior = valor;
}

/**
 * @brief 
 * 
 * @param valor 
 */
void loto::adicionar_limites_dos_numeros_multiplosdeTres_superior(unsigned long int valor){
    limites_dos_numeros_multiplosdeTres_superior = valor;
}

/**
 * @brief 
 * 
 * @param valor 
 */
void loto::adicionar_limites_dos_numeros_multiplosdeTres_inferior(unsigned long int valor){
    limites_dos_numeros_multiplosdeTres_inferior = valor;
}

/**
 * @brief 
 * 
 * @param valor 
 */
void loto::adicionar_limites_dos_numeros_fibonacci_superior(unsigned long int valor){
    limites_dos_numeros_fibonacci_superior = valor;
}

/**
 * @brief 
 * 
 * @param valor 
 */
void loto::adicionar_limites_dos_numeros_fibonacci_inferior(unsigned long int valor){
    limites_dos_numeros_fibonacci_inferior = valor;
}

/**
 * @brief 
 * 
 * @param valor 
 */
void loto::adicionar_limites_dos_numeros_dezenasRepetidas_superior(unsigned long int valor){
    limites_dos_numeros_dezenasRepetidas_superior = valor;
}

/**
 * @brief 
 * 
 * @param valor 
 */
void loto::adicionar_limites_dos_numeros_dezenasRepetidas_inferior(unsigned long int valor){
    limites_dos_numeros_dezenasRepetidas_inferior = valor;
}

/**
 * @brief 
 * 
 * @param num_par 
 * @param num_impar 
 */
void loto::adicionar_pares_PxI(unsigned long int num_par, unsigned long int num_impar){
    std::vector <unsigned long int> temp;
    temp.push_back(num_par);
    temp.push_back(num_impar);
    pares_possiveis_PxI.push_back(temp);
}

/**
 * @brief Gerar números múltiplos de três quando for preciso
 * 
 */
void loto::gerar_multiplosdeTres(void){
    // Gerar números
    for(unsigned short int i = 3; i<=tamanho_dos_jogos; i+=3){
        numeros_multiplosdeTres.push_back(i);
    }
}

/**
 * @brief Gerar números fibonacci quando for preciso
 * 
 */
void loto::gerar_fibonacci(void){
    // Verificar até qual número será usado
    unsigned short int fibonacci[] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584};
    unsigned long int posicao_final(0);
    for(unsigned short int i : fibonacci){
        if(i>tamanho_dos_jogos){            
            break;
        } else {
            ++posicao_final;
        }
    }
    // Gerar números
    for(unsigned long int i(0); i<posicao_final; ++i){
        numeros_fibonacci.push_back(fibonacci[i]);
    }
}

/**
 * @brief Gerar números primos quando for preciso
 * 
 */
void loto::gerar_numerosPrimos(void){
    // Verificar até qual número será usado
    unsigned short int numerosPrimos[] =
    {
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 
        53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 
        101, 103, 107, 109, 113, 127, 131, 137, 139, 149,
        151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199
    };
    unsigned long int posicao_final(0);
    for(unsigned short int i : numerosPrimos){
        if(i>tamanho_dos_jogos){            
            break;
        } else {
            ++posicao_final;
        }
    }
    // Gerar números
    for(unsigned long int i(0); i<posicao_final; ++i){
        numeros_primos.push_back(numerosPrimos[i]);
    }
}

/**
 * @brief Função para adicionar os jogos já sorteados para posivel uso das regras
 * 
 * @param jogo Jogo que deseja adicionar
 * @return unsigned long int Posição que ele foi adicionado
 */
unsigned long int loto::adicionar_jogos_sorteados(std::vector <unsigned short int> jogo){
    // Coloqar em ordem o jogo
    std::sort(jogo.begin(),jogo.end());
    // Adicionar jogo
    jogos_sorteados.push_back(jogo);
    // Retornar posição adicionada
    return (jogos_sorteados.size()/tamanho_dos_jogos);
}

/**
 * @brief Verificar se a regra do Soma está presente neste jogo
 * 
 * @param jogo Jogo a analisar
 * @return true Se o jogo está dentro do padão
 * @return false Se o jogo não está dentro do padão
 */
bool loto::verificador_regra_limites_da_soma(std::vector <unsigned short int> jogo){
    // Some os núemros
    unsigned long int soma(0);
    for(unsigned short int numero : jogo){
        soma += numero;
    }

    // Verifique se está dentro das regras
    return ((soma >= limites_da_soma_inferior) and (soma <= limites_da_soma_superior));
}

/**
 * @brief Verificar se a regra dos pares de Pares x Ímpares está presente neste jogo
 * 
 * @param jogo Jogo a analisar
 * @return true Se o jogo está dentro do padão
 * @return false Se o jogo não está dentro do padão 
 */
bool loto::verificador_regra_PxI(std::vector <unsigned short int> jogo){
    // Definindo valores abstratos
    unsigned short int lado_par(0);
    unsigned short int lado_impar(1);

    // Contar pares e ímpares
    unsigned long int pares(0);
    unsigned long int impares(0);
    for(unsigned short int numero : jogo){
        if((numero%2)==0){
            ++pares;
        } else {
            ++impares;
        }
    }

    // Verificar se está dentro da regra
    for(unsigned short int i(0); i<pares_possiveis_PxI.size(); ++i){
        if((pares_possiveis_PxI[i][lado_par] == pares) and (pares_possiveis_PxI[i][lado_impar] == impares)){
            return true;
        }
    }
    return false;
}

/**
 * @brief Verificar se a regra das Sequências está presente neste jogo
 * 
 * @param jogo Jogo a analisar
 * @return true Se o jogo está dentro do padão
 * @return false Se o jogo não está dentro do padão
 */
bool loto::verificador_regra_sequencia(std::vector <unsigned short int> jogo){
    // Verificar maior sequência existente
    unsigned long int sequencia(0);
    unsigned long int maior_sequencia(0);
    for(unsigned long int i(0); i<jogo.size(); ++i){
        if((jogo[i]+1) == (jogo[i+1])){
            ++sequencia;
        } else {
            maior_sequencia = sequencia;
            sequencia = 0;
        }
    }

    // Verificar se maior sequência está na regra
    return ((maior_sequencia>=limites_da_sequencia_inferior)and(maior_sequencia<=limites_da_sequencia_superior));
}

/**
 * @brief Verificar se a regra dos Números Primos está presente neste jogo
 * 
 * @param jogo Jogo a analisar
 * @return true Se o jogo está dentro do padão
 * @return false Se o jogo não está dentro do padão
 */
bool loto::verificador_regra_numeros_primos(std::vector <unsigned short int> jogo){
    // Verificar quantidade de ocorrências
    unsigned long int ocorrencias = 0;
    #pragma omp parallel for reduction(+ : ocorrencias)
    for(unsigned long int i = 0; i<numeros_primos.size(); ++i){
        if(std::binary_search(jogo.begin(),jogo.end(), numeros_primos[i])){
            ++ocorrencias;
        }
    }

    // Verificar limites
    return ((ocorrencias>=limites_dos_numeros_primos_inferior)and(ocorrencias<=limites_dos_numeros_primos_superior));
}

/**
 * @brief Verificar se a regra dos Números Múltiplos de Três está presente neste jogo
 * 
 * @param jogo Jogo a analisar
 * @return true Se o jogo está dentro do padão
 * @return false Se o jogo não está dentro do padão
 */
bool loto::verificador_regra_numeros_multiplosdeTres(std::vector <unsigned short int> jogo){
    // Verificar quantidade de ocorrências
    unsigned long int ocorrencias = 0;
    #pragma omp parallel for reduction(+ : ocorrencias)
    for(unsigned long int i = 0; i<numeros_multiplosdeTres.size(); ++i){
        if(std::binary_search(jogo.begin(),jogo.end(), numeros_multiplosdeTres[i])){
            ++ocorrencias;
        }
    }

    // Verificar limites
    return ((ocorrencias>=limites_dos_numeros_multiplosdeTres_inferior)and(ocorrencias<=limites_dos_numeros_multiplosdeTres_superior));
}

/**
 * @brief Verificar se a regra dos Números Fibonacci está presente neste jogo
 * 
 * @param jogo Jogo a analisar
 * @return true Se o jogo está dentro do padão
 * @return false Se o jogo não está dentro do padão 
 */
bool loto::verificador_regra_numeros_fibonacci(std::vector <unsigned short int> jogo){
    // Verificar quantidade de ocorrências
    unsigned long int ocorrencias = 0;
    #pragma omp parallel for reduction(+ : ocorrencias)
    for(unsigned long int i = 0; i<numeros_fibonacci.size(); ++i){
        if(std::binary_search(jogo.begin(),jogo.end(), numeros_fibonacci[i])){
            ++ocorrencias;
        }
    }

    // Verificar limites
    return ((ocorrencias>=limites_dos_numeros_fibonacci_inferior)and(ocorrencias<=limites_dos_numeros_fibonacci_superior));
}

/**
 * @brief Verificar se a regra das Dezenas Repetidas está presente neste jogo
 * 
 * @param jogo Jogo a analisar
 * @return true Se o jogo está dentro do padão
 * @return false Se o jogo não está dentro do padão
 */
bool loto::verificador_regra_dezenasRepeditas(std::vector <unsigned short int> jogo){
    // Verificar quantidade de ocorrências
    unsigned long int ocorrencias = 0;
    #pragma omp parallel for reduction(+ : ocorrencias)
    for(unsigned long int i = 0; i<tamanho_dos_jogos; ++i){
        if(std::binary_search(jogo.begin(),jogo.end(), jogos_sorteados[jogos_sorteados.size()][i])){
            ++ocorrencias;
        }
    }

    // Verificar limites
    return ((ocorrencias>=limites_dos_numeros_dezenasRepetidas_inferior)and(ocorrencias<=limites_dos_numeros_dezenasRepetidas_superior));
}