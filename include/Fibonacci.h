/**
 * @file Fibonacci.h
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief
 * @version 0.1
 * @date 07-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef FIBONACCI_H_
#define FIBONACCI_H_

#include <vector>

class Fibonacci {
 private:
  unsigned long quantidadeDeJogos;
  std::vector<unsigned int> numerosDeFibo = {1, 2, 3, 5, 8, 13, 21, 34, 55};
  bool seFibo(unsigned long);
  long double cacularPorcentagem(unsigned long, unsigned long);
  std::vector<unsigned long> resultado;

 public:
  unsigned long getResultado(unsigned long);
  long double getResultadoPorcentagem(unsigned long);
  Fibonacci(std::vector<std::vector<unsigned long>>&);
};

#endif