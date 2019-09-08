/**
 * @file Primos.cpp
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief
 * @version 0.1
 * @date 08-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "Primos.h"

/**
 * @brief Construct a new Primos:: Primos object
 *
 * @param jogos Jogos sorteados
 */
Primos::Primos(std::vector<std::vector<unsigned long>>& jogos) {
  for (unsigned long i = 0; i <= jogos[0].size(); ++i) {
    resultado.push_back(0);
  }
  quantidadeDeJogos = jogos.size();

  for (unsigned long i = 0; i < jogos.size(); ++i) {
    unsigned long contador = 0;
#pragma omp parallel for reduction(+ : contador)
    for (unsigned long j = 0; j < jogos[i].size(); ++j) {
      if (sePrimos(jogos[i][j])) {
        contador += 1;
      }
    }
    ++resultado[contador];
  }
}

/**
 * @brief Verifica se é um número é Primo
 *
 * @param numero Número á verificar
 * @return true É um número primo
 * @return false Não é um número primo
 */
bool Primos::sePrimos(unsigned long numero) {
  bool flag = false;

#pragma omp parallel for
  for (unsigned int i = 0; i < numerosPrimos.size(); ++i) {
    if (numerosPrimos[i] == numero) {
#pragma omp critical
      { flag = true; }
#pragma omp cancellation point for
    }
  }

  return flag;
}

/**
 * @brief Retornar o valor da freqência de vezes que aquele tipo saíu em
 * porcentagem (%)
 *
 * @param tipo De 0 para nunca a 6 para todos os números
 * @return long double Resultado em porcentagem
 */
long double Primos::getResultadoPorcentagem(unsigned long tipo) {
  long double final = getResultado(tipo);
  return cacularPorcentagem(quantidadeDeJogos, final);
}

/**
 * @brief Retornar o valor da freqência de vezes que aquele tipo saíu
 *
 * @param tipo De 0 para nunca a 6 para todos os números
 * @return unsigned long Resultado
 */
unsigned long Primos::getResultado(unsigned long tipo) {
  return resultado[tipo];
}

/**
 * @brief Calcular a porcentagem das ocorrências
 *
 * @param montante Qunatidade de jogos analisados
 * @param ocorrencia Quantidade de ocorrencias do tipo
 * @return double Porcentagem (%)
 */
long double Primos::cacularPorcentagem(unsigned long montante,
                                       unsigned long ocorrencia) {
  double resultado = ((double)ocorrencia / (double)montante);
  return (resultado * 100);
}