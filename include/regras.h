/**
 * @file regras.h
 * @author Allan de Miranda Silva
 * @brief 
 * @version 1.0
 * @date 2018-10-31
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#ifndef _REGRAS_H_
#define _REGRAS_H_

#include <vector>
#include <array>
#include <string>

#include "loteria.h" // <------ retirar isso depois

class regras
{
private:
    unsigned short int quantidade_de_regras_disponiveis = 7;
    std::vector <unsigned short int> soma; // Soma dos números sorteados
    std::vector <std::array<unsigned short int, 2>> pares_impares; // Pares e impares sorteados [2]
    std::vector <unsigned short int> sequencia; // Quantidade de números em sequencia
    std::vector <unsigned short int> primos; // Quantidade de números primos
    std::vector <unsigned short int> multiplos_3; // Quantidade de números múltiplos de 3
    std::vector <unsigned short int> fibonacci; // Quantidade de números de Fibonacci
    std::vector <unsigned short int> dezenas_repetidas; // Quantidade de dezenas repetidas do concurso anterior
    bool adicionar_regras(std::vector <unsigned short int>, loteria);
    std::vector <unsigned short int> gerador_de_regras(loteria);
    
    void analise_da_soma(float, loteria);
public:
    regras(loteria, std::string);
    bool adiconar_nova_soma(unsigned short int, loteria);
    bool adiconar_novo_pares_impares(unsigned short int, unsigned short int, loteria); 
    bool adiconar_nova_sequencia(unsigned short int, loteria);
    bool adiconar_novo_primo(unsigned short int, loteria);
    bool adiconar_novo_multiplo_3(unsigned short int, loteria);
    bool adiconar_novo_fibonacci(unsigned short int, loteria);
    bool adiconar_nova_dezena_repetida(unsigned short int, loteria);    
};

#endif