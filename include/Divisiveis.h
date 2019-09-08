/**
 * @file Divisiveis.h
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief
 * @version 0.1
 * @date 07-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef DIVISIVEIS_H_
#define DIVISIVEIS_H_

#include <vector>

class Divisiveis {
 private:
  unsigned long quantidadeDeJogos;
  bool seDivide(unsigned long, unsigned long);
  long double cacularPorcentagem(unsigned long, unsigned long);
  std::vector<unsigned long> resultado;

 public:
  unsigned long getResultado(unsigned long);
  long double getResultadoPorcentagem(unsigned long);
  Divisiveis(std::vector<std::vector<unsigned long>>&, unsigned long);
};

#endif