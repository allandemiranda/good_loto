/**
 * @file verificador.h
 * @author Allan de Miranda (allandemiranda@gmail.com)
 * @brief 
 * @version 1.0
 * @date 2018-11-02
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#ifndef _VERIFICADOR_H_
#define _VERIFICADOR_H_

#include <vector>

#include "../include/loteria.h"
#include "../include/regras.h"

class verificador
{
private:
    std::vector<std::vector <unsigned short int>> jogos_corretos;
    bool verificador_de_regras(std::vector <unsigned short int>, loteria, regras);
    bool r_soma(std::vector <unsigned short int>, loteria, regras);
    bool r_pares_impares(std::vector <unsigned short int>, loteria, regras); 
    bool r_sequencia(std::vector <unsigned short int>, loteria, regras);
    bool r_primo(std::vector <unsigned short int>, loteria, regras);
    bool r_multiplo_3(std::vector <unsigned short int>, loteria, regras);
    bool r_fibonacci(std::vector <unsigned short int>, loteria, regras);
    bool r_dezena_repetida(std::vector <unsigned short int>, loteria, regras);

public:
    verificador(loteria, regras);
    std::vector<std::vector <unsigned short int>> retornar_jogos_certos(void);
};

#endif