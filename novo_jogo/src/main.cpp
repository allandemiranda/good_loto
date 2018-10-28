/**
 * @file main.cpp
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief Main
 * @version 0.1
 * @date 2018-10-28
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#include <iostream>
#include <vector>

//#include "main.h"
#include "../include/main.h" // APAGAR ISSO AQUI

int main(int argc, char const *argv[])
{
    loto loto_facil;

    /**
     * @brief Part um
     * 
     */
    std::vector <unsigned long int> regras;
    std::cout << ">>> Preparando para ler regras [data/" << argv[1] << "]" << std::endl;
    if(!obter_regras(argv[1], regras)){
        std::cerr << ">>> Erro ao ler arquivo com regras" << std::endl;
        std::cerr << "--------------------------------------------------" << std::endl;
        return EXIT_FAILURE;
    } else {
        gerar_as_regras(loto_facil);
        std::cout << ">>> Regras lidas e adicionadas!" << std::endl;
    }

    /**
     * @brief parte dois
     * 
     */
    std::cout << ">>> Preparando para ler jogos sorteados [data/" << argv[2] << "]" << std::endl;
    if(!obter_jogos_sorteados(argv[2], loto_facil)){
        std::cerr << ">>> Erro ao ler arquivo com jogos sorteados" << std::endl;
        std::cerr << "--------------------------------------------------" << std::endl;
        return EXIT_FAILURE;
    } else {
        std::cout << ">>> Jogos sorteados lidos e adicionadas!" << std::endl;
    }
    

    // receber jogos que podem sair para passar pelo filtro

    // filtrar e salvar em arquivo

    // Retornar valores sobre filtros
    return 0;
}
