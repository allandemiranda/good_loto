/**
 * @file Primos.h
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief
 * @version 0.1
 * @date 08-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef PRIMOS_H_
#define PRIMOS_H_

#include <vector>

class Primos {
 private:
  unsigned long quantidadeDeJogos;
  std::vector<unsigned int> numerosPrimos = {2,  3,  5,  7,  11, 13, 17, 19, 23,
                                             29, 31, 37, 41, 43, 47, 53, 59};
  bool sePrimos(unsigned long);
  long double cacularPorcentagem(unsigned long, unsigned long);
  std::vector<unsigned long> resultado;

 public:
  unsigned long getResultado(unsigned long);
  long double getResultadoPorcentagem(unsigned long);
  Primos(std::vector<std::vector<unsigned long>>&);
};

#endif