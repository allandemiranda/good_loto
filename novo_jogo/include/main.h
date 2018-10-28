/**
 * @file main.h
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2018-10-28
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#include <fstream>
#include <vector>

#include "../src/loto.cpp" // APAGAR ISSO AQUI

/**
 * @brief 
 * 
 * @param fileName 
 * @param vetor 
 * @return true 
 * @return false 
 */
bool obter_regras(char *fileName, std::vector <unsigned long int> &vetor){
    std::string route = "../data/"; 
    route = route + fileName; 
    std::ifstream ifs(route); 
    if(!ifs.good()){
        return false;
    }
    unsigned long int valuer;
    while( ifs >> valuer ){
        vetor.push_back(valuer);
    }
    if( not ifs.eof() )
        return false;
	ifs.close();

    return true;
}

/**
 * @brief 
 * 
 * @param jogo 
 */
void gerar_as_regras(loto &jogo){
    // gerar todas a regras necessárias com a class jogo
}

/**
 * @brief 
 * 
 * @param fileName 
 * @param vetor 
 * @return true 
 * @return false 
 */
bool obter_jogos_sorteados(char *fileName, loto &jogo){
    std::string route = "../data/"; 
    route = route + fileName; 
    std::ifstream ifs(route); 
    if(!ifs.good()){
        return false;
    }
    unsigned long int valuer;
    std::vector <unsigned short int> vetor;
    unsigned long int contador(0);
    while( ifs >> valuer ){
        if(contador<jogo.tamanho_dos_jogos_usados){
            vetor.push_back(valuer);
            ++contador;
        } else {
            jogo.adicionar_jogos_sorteados(vetor);
            vetor.clear();
            vetor.push_back(valuer);
            contador = 1;
        }
        
    }
    if( not ifs.eof() )
        return false;
	ifs.close();

    return true;
}