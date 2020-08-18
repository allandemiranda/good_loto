/**
 * @file Discreta.h
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief
 * @version 0.1
 * @date 17-08-2020
 *
 * @copyright Copyright (c) 2020
 *
 */

#ifndef DISCRETA_H_
#define DISCRETA_H_

#include <string>
#include <vector>

#include "Tabela.h"

class Discreta {
 private:
  std::vector<unsigned short int> sorteiosJuntos;
  std::vector<std::vector<unsigned short int>> probabilidade;

 public:
  Discreta(Tabela);
  ~Discreta(void);
  double getResultado(unsigned short int, unsigned short int);
};

#endif