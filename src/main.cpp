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

#include "Anterior.h"
#include "Divisiveis.h"
#include "Fibonacci.h"
#include "Listadejogos.h"
#include "ParesEimpares.h"
#include "Primos.h"
#include "Sequencia.h"

#include <iostream>
#include <vector>

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
  for (int i = 0; i <= 6; ++i) {
    std::cout << "Resultado para " << i << ": " << regraDois.getResultado(i)
              << " " << regraDois.getResultadoPorcentagem(i) << "%"
              << std::endl;
  }

  std::cout << std::endl;

  for (auto i(3u); i <= 15; ++i) {
    std::cout << "REGRA Divisivel por " << i << std::endl;
    Divisiveis regraTres(novaLista.jogos, i);
    for (int j = 0; j <= 6; ++j) {
      std::cout << "Resultado para " << j << ": " << regraTres.getResultado(j)
                << " " << regraTres.getResultadoPorcentagem(j) << "%"
                << std::endl;
    }
  }

  std::cout << std::endl;

  std::cout << "REGRA Quantidade de Primos" << std::endl;
  Primos regraQuatro(novaLista.jogos);
  for (int i = 0; i <= 6; ++i) {
    std::cout << "Resultado para " << i << ": " << regraQuatro.getResultado(i)
              << " " << regraQuatro.getResultadoPorcentagem(i) << "%"
              << std::endl;
  }

  std::cout << std::endl;

  std::cout << "REGRA Quantidade do jogo Anterior" << std::endl;
  Anterior regraCinco(novaLista.jogos);
  for (int i = 0; i <= 6; ++i) {
    std::cout << "Resultado para " << i << ": " << regraCinco.getResultado(i)
              << " " << regraCinco.getResultadoPorcentagem(i) << "%"
              << std::endl;
  }

  std::cout << std::endl;

  std::cout << "REGRA Quantidade de números em Seguência" << std::endl;
  Sequencia regraSeis(novaLista.jogos);
  for (int i = 0; i <= 6; ++i) {
    std::cout << "Resultado para " << i << ": " << regraSeis.getResultado(i)
              << " " << regraSeis.getResultadoPorcentagem(i) << "%"
              << std::endl;
  }

  return 0;
}
