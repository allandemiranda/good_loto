/**
 * @file lotofacil._LOTOFACIL_H_
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief Class para organizar resultados da Lotofácil
 * @version 0.1
 * @date 2018-10-27
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#ifndef _LOTOFACIL_H_
#define _LOTOFACIL_H_

#include <vector>
#include <algorithm>
#include <omp.h> // sistemas paralelos -fopenmp

using numeros_tipo_volante = unsigned short int;

class lotofacil{
    private:
        unsigned long int tamanho_dos_jogos = 15;
        std::vector <std::vector <numeros_tipo_volante>> jogos_sorteados;
        // Regra da Soma
        unsigned long int limites_da_soma_superior; // FALTA INICIALIZAR
        unsigned long int limites_da_soma_inferior; // FALTA INICIALIZAR
        // Regra dos Pares x Ímpares
        std::vector <std::vector <numeros_tipo_volante>> pares_possiveis_PxI; // FALTA INICIALIZAR
        // Regra Números em Sequência
        unsigned long int limites_da_sequencia_superior; // FALTA INICIALIZAR
        unsigned long int limites_da_sequencia_inferior; // FALTA INICIALIZAR
    public:
        lotofacil(void);
        unsigned long int adicionar_jogos_sorteados(std::vector <numeros_tipo_volante>);
        bool verificador_regra_limites_da_soma(std::vector <numeros_tipo_volante>);
        bool verificador_regra_PxI(std::vector <numeros_tipo_volante>);
        bool verificador_regra_sequencia(std::vector <numeros_tipo_volante>);
        
};

/**
 * @brief Função para adicionar os jogos já sorteados para posivel uso das regras
 * 
 * @param jogo Jogo que deseja adicionar
 * @return unsigned long int Posição que ele foi adicionado
 */
unsigned long int lotofacil::adicionar_jogos_sorteados(std::vector <numeros_tipo_volante> jogo){
    std::sort(jogo.begin(),jogo.end());
    jogos_sorteados.push_back(jogo);
    return (jogos_sorteados.size()/tamanho_dos_jogos);
}

/**
 * @brief Verificar se a regra do Soma está presente neste jogo
 * 
 * @param jogo Jogo a analisar
 * @return true Se o jogo está dentro do padão
 * @return false Se o jogo não está dentro do padão
 */
bool lotofacil::verificador_regra_limites_da_soma(std::vector <numeros_tipo_volante> jogo){
    // Some os núemros
    unsigned long int soma(0);
    for(numeros_tipo_volante numero : jogo){
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
bool lotofacil::verificador_regra_PxI(std::vector <numeros_tipo_volante> jogo){
    // Definindo valores abstratos
    unsigned short int lado_par(0);
    unsigned short int lado_impar(1);

    // Contar pares e ímpares
    unsigned long int pares(0);
    unsigned long int impares(0);
    for(numeros_tipo_volante numero : jogo){
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
 * @return false Se o jogo não está dentro do padã
 */
bool lotofacil::verificador_regra_sequencia(std::vector <numeros_tipo_volante> jogo){
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

#endif