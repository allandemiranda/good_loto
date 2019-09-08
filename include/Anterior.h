/**
 * @file Anterior.h
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief
 * @version 0.1
 * @date 08-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef ANTERIOR_H_
#define ANTERIOR_H_

#include <vector>

class Anterior {
 private:
  unsigned long quantidadeDeJogos;
  unsigned long checkAnterior(std::vector<unsigned long>,
                              std::vector<unsigned long>);
  long double cacularPorcentagem(unsigned long, unsigned long);
  std::vector<unsigned long> resultado;

 public:
  unsigned long getResultado(unsigned long);
  long double getResultadoPorcentagem(unsigned long);
  Anterior(std::vector<std::vector<unsigned long>>&);
};

#endif