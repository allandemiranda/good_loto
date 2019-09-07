/**
 * @file ParesEimpares.cpp
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief
 * @version 0.1
 * @date 07-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "ParesEimpares.h"

#include <vector>

/**
 * @brief Construct a new pares Eimpares::pares Eimpares object
 *
 * @param jogos Jogos sorteados
 */
ParesEimpares::ParesEimpares(std::vector<std::vector<unsigned long>>& jogos) {
  for (unsigned long i = 0; i < jogos[0].size(); ++i) {
    resultado.push_back(0);
  }
  quantidadeDeJogos = jogos.size();

#pragma omp parallel for
  for (unsigned long i = 0; i < jogos.size(); ++i) {
    unsigned long contador = 0;
    for (unsigned long j : jogos[i]) {
      if (sePar(j)) {
        ++contador;
      }
    }
    ++resultado[contador];
  }
}

/**
 * @brief Retornar o valor da freqência de vezes que aquele tipo saíu em
 * porcentagem (%)
 *
 * @param tipo De 0 para nunca a 6 para todos os números
 * @return long double Resultado em porcentagem
 */
long double ParesEimpares::getResultadoPorcentagem(unsigned long tipo) {
  long double final = getResultado(tipo);
  return cacularPorcentagem(quantidadeDeJogos, final);
}

/**
 * @brief Retornar o valor da freqência de vezes que aquele tipo saíu
 *
 * @param tipo De 0 para nunca a 6 para todos os números
 * @return unsigned long Resultado
 */
unsigned long ParesEimpares::getResultado(unsigned long tipo) {
  return resultado[tipo];
}

/**
 * @brief Calcular a porcentagem das ocorrências
 *
 * @param montante Qunatidade de jogos analisados
 * @param ocorrencia Quantidade de ocorrencias do tipo
 * @return double Porcentagem (%)
 */
long double ParesEimpares::cacularPorcentagem(unsigned long montante,
                                              unsigned long ocorrencia) {
  double resultado = ((double)ocorrencia / (double)montante);
  return (resultado * 100);
}

/**
 * @brief Verifica se o número é par
 *
 * @param numero Número para verificar
 * @return true É um número par
 * @return false É um número ímpar
 */
bool ParesEimpares::sePar(unsigned long numero) {
  if ((numero % 2) == 0) {
    return true;
  } else {
    return false;
  }
}