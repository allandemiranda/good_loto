/**
 * @file main.cpp
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief
 * @version 0.1
 * @date 07-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "Fibonacci.h"
#include "Listadejogos.h"
#include "ParesEimpares.h"

#include <iostream>

int main(void) {
  Listadejogos novaLista("data/listadejogos.txt");

  std::cout << "REGRA Quantidade de Pares" << std::endl;
  ParesEimpares regraUm(novaLista.jogos);
  for (int i = 0; i <= 6; ++i) {
    std::cout << "Resultado para " << i << ": " << regraUm.getResultado(i)
              << " " << regraUm.getResultadoPorcentagem(i) << "%" << std::endl;
  }

  std::cout << std::endl;

  std::cout << "REGRA Quantidade de Fibonacci" << std::endl;
  Fibonacci regraDois(novaLista.jogos);
  for (int i = 0; i < 6; ++i) {
    std::cout << "Resultado para " << i << ": " << regraDois.getResultado(i)
              << " " << regraDois.getResultadoPorcentagem(i) << "%"
              << std::endl;
  }
  return 0;
}
