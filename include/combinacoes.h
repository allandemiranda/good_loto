/**
 * @file combinacoes.h
 * @author Allan de Miranda Silva (allandemrianda@gmail.com)
 * @brief 
 * @version 1.0
 * @date 01-11-2018
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#ifndef _COMBINACOES_H_
#define _COMBINACOES_H_

#include <vector>

class combinacoes
{
    private:       
        std::vector <std::vector <unsigned short int>> todas_combinacoes;
    public:
        combinacoes(std::vector <unsigned short int>, unsigned long int);
        unsigned long int quantidade(void);
        std::vector <unsigned short int> combinacao(unsigned long int);
};

#endif