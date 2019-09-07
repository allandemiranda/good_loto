/**
 * @file Fibonacci.cpp
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief
 * @version 0.1
 * @date 07-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "Fibonacci.h"

/**
 * @brief Construct a new Fibonacci:: Fibonacci object
 *
 * @param jogos Jogos sorteados
 */
Fibonacci::Fibonacci(std::vector<std::vector<unsigned long>>& jogos) {
  for (unsigned long i = 0; i < jogos[0].size(); ++i) {
    resultado.push_back(0);
  }
  quantidadeDeJogos = jogos.size();

#pragma omp parallel for
  for (unsigned long i = 0; i < jogos.size(); ++i) {
    unsigned long contador = 0;
    for (unsigned long j : jogos[i]) {
      if (seFibo(j)) {
        ++contador;
      }
    }
    ++resultado[contador];
  }
}

/**
 * @brief Verifica se é um número de fibonacci
 *
 * @param numero Número para verificar
 * @return true É um número de fibonacci
 * @return false Não é um número de fibonacci
 */
bool Fibonacci::seFibo(unsigned long numero) {
  bool flag = false;

#pragma omp parallel for
  for (unsigned int i = 0; i < numerosDeFibo.size(); ++i) {
    if (numerosDeFibo[i] == numero) {
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
long double Fibonacci::getResultadoPorcentagem(unsigned long tipo) {
  long double final = getResultado(tipo);
  return cacularPorcentagem(quantidadeDeJogos, final);
}

/**
 * @brief Retornar o valor da freqência de vezes que aquele tipo saíu
 *
 * @param tipo De 0 para nunca a 6 para todos os números
 * @return unsigned long Resultado
 */
unsigned long Fibonacci::getResultado(unsigned long tipo) {
  return resultado[tipo];
}

/**
 * @brief Calcular a porcentagem das ocorrências
 *
 * @param montante Qunatidade de jogos analisados
 * @param ocorrencia Quantidade de ocorrencias do tipo
 * @return double Porcentagem (%)
 */
long double Fibonacci::cacularPorcentagem(unsigned long montante,
                                          unsigned long ocorrencia) {
  double resultado = ((double)ocorrencia / (double)montante);
  return (resultado * 100);
}