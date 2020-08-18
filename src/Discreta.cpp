/**
 * @file Discreta.cpp
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief
 * @version 0.1
 * @date 17-08-2020
 *
 * @copyright Copyright (c) 2020
 *
 */

#include "Discreta.h"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include "Sorteio.h"
#include "Tabela.h"

/**
 * @brief Construct a new Discreta:: Discreta object
 *
 * @param tabelaJogos Tabela dos sorteios
 */
Discreta::Discreta(Tabela tabelaJogos) {
  try {
    for (unsigned short int i = 1; i <= tabelaJogos.getQuantidade(); ++i) {
      std::vector<unsigned short int> copia =
          tabelaJogos.getSorteio(i).getResultado();
      for (unsigned short int j = 0; j < 6; ++j) {
        sorteiosJuntos.push_back(copia[j]);
      }
    }

    probabilidade.resize(60);
#pragma omp parallel for
    for (unsigned short int i = 1; i <= 60; ++i) {
      std::vector<unsigned short int> posicoes;
      unsigned short int posicao = 1;
      for (unsigned short int numero : sorteiosJuntos) {
        if (numero != i) {
          ++posicao;
        } else {
          posicoes.push_back(posicao);
          posicao = 1;
        }
      }
      posicoes.push_back(posicao);
      unsigned short int last = posicoes.back();
      posicoes.pop_back();
      std::sort(posicoes.begin(), posicoes.end());
      posicoes.push_back(last);
      probabilidade[i - 1] = posicoes;
    }
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    throw;
  }
}

/**
 * @brief Destroy the Discreta:: Discreta object
 *
 */
Discreta::~Discreta(void) {}

/**
 * @brief Get the Resultado object
 *
 * @param numero Número do volante
 * @param posi Posição que deve sair
 * @return double Resultados da probabilidade
 */
double Discreta::getResultado(unsigned short int numero,
                              unsigned short int posi) {
  unsigned short int last = probabilidade[numero - 1].back();
  probabilidade[numero - 1].pop_back();
  if (std::find(std::begin(probabilidade[numero - 1]),
                std::end(probabilidade[numero - 1]),
                posi + last) != std::end(probabilidade[numero - 1])) {
    unsigned short int quantidade = 0;
    for (long unsigned int i = 0; i < probabilidade[numero - 1].size(); ++i) {
      if (probabilidade[numero - 1][i] <= posi + last) {
        if (probabilidade[numero - 1][i] == posi + last) {
          ++quantidade;
        }
      } else {
        break;
      }
    }
    probabilidade[numero - 1].push_back(last);
    return ((double)(quantidade * 100)) /
           ((double)(probabilidade[numero - 1].size() - 1));
  } else {
    probabilidade[numero - 1].push_back(last);
    return 0.0;
  }
}