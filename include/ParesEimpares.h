/**
 * @file ParesEimpares.h
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief Classe para controlar números pares e impares
 * @version 0.1
 * @date 07-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef PARESEIMPARES_H_
#define PARESEIMPARES_H_

#include <vector>

class ParesEimpares {
 private:
  unsigned long quantidadeDeJogos;
  bool sePar(unsigned long);
  long double cacularPorcentagem(unsigned long, unsigned long);
  unsigned long pares;
  std::vector<unsigned long> resultado;

 public:
  unsigned long getResultado(unsigned long);
  long double getResultadoPorcentagem(unsigned long);
  ParesEimpares(std::vector<std::vector<unsigned long>>&);
};

#endif