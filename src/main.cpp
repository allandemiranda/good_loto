/**
 * @file main.cpp
 * @author Allan de Miranda Silva
 * @brief 
 * @version 1.0
 * @date 2018-10-31
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#include <iostream>
#include <string>
#include <fstream>

//#include <omp.h> // sistemas paralelos -fopenmp

#include "../include/combinacoes.h"
#include "../include/loteria.h"
#include "../include/regras.h"
#include "../include/verificador.h"

int main(int argc, char const *argv[])
{
    // Menu
    std::cout << "Bem vindo ao gerador de jogos possíveis de sair" << std::endl;
    std::cout << "Selecione a modalidade:" << std::endl;
        /// Parte do menu para selecionar ainda não desenvolvida
        std::string nome_da_modalidade = "lotofacil";
    std::cout << "Você celecionou a modalidade Lotofácil" << std::endl; // única configurada
    std::cout << "-------------------------------------------------------"  << std::endl;
    // FIM DO MENU

    // desenvolvimento das funções 
    loteria modalidade(nome_da_modalidade);
    regras novas_regras(modalidade,"");
    verificador novo_verificador(modalidade, novas_regras);

    std::cout << "Criando arquivo com os jogos possiveis" << std::endl;
    std::ofstream outFile ("../data/jogos_certos_"+nome_da_modalidade, std::ios::app);
    std::vector<std::vector <unsigned short int>> jogo_final = novo_verificador.retornar_jogos_certos();
    for(auto i(0); i<jogo_final.size(); ++i){
        for(auto j : jogo_final[i]){
            outFile << j << " ";
        }
        outFile << std::endl;
    }
    outFile.close();
    std::cout << "-----------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "Boa sorte" << std::endl;



    return EXIT_SUCCESS;
}
