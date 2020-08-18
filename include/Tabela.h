/**
 * @file Tabela.h
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief 
 * @version 0.1
 * @date 17-08-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef TABELA_H_
#define TABELA_H_

#include "Sorteio.h"

#include <string>
#include <vector>

class Tabela {
 private:
  unsigned short int quantidade;
  std::vector<Sorteio> sorteios;
  void setQuantidade(unsigned short int);
  void setSorteio(Sorteio);


 public:
  Tabela(std::string);
  ~Tabela(void);
  unsigned short int getQuantidade(void);
  Sorteio getSorteio(unsigned short int);
};

#endif