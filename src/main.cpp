/**
 * @file main.cpp
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief
 * @version 0.1
 * @date 17-08-2020
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <iostream>

#include "Discreta.h"
#include "Tabela.h"

int main(int argc, char const *argv[]) {
  Tabela teste("data/jogos.csv");

  Discreta testeA(teste);

  double prob[6] = {0, 0, 0, 0, 0, 0};
  int num[6] = {0, 0, 0, 0, 0, 0};

  for (int i = 1; i <= 60; ++i) {
    std::cout << "NUMERO " << i << std::endl;
    std::cout << "| ";
    for (int j = 1; j <= 6; ++j) {
      std::cout << testeA.getResultado(i, j) << " | ";
      if (i <= 9) {
        continue;
      }
      if (prob[j - 1] < testeA.getResultado(i, j)) {
        prob[j - 1] = testeA.getResultado(i, j);
        num[j - 1] = i;
      }
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;

  for (double a : prob) {
    std::cout << a << " | ";
  }
  std::cout << std::endl;
  for (double a : num) {
    std::cout << a << " | ";
  }
  std::cout << std::endl;
  return 0;
}
