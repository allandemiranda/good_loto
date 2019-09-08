/**
 * @file Sequencia.cpp
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief
 * @version 0.1
 * @date 08-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "Sequencia.h"

Sequencia::Sequencia(std::vector<std::vector<unsigned long>>& jogos) {
  for (unsigned long i = 0; i <= jogos[0].size(); ++i) {
    resultado.push_back(0);
  }
  quantidadeDeJogos = jogos.size();
  for (unsigned long i = 0; i < jogos.size(); ++i) {
    ++resultado[checkSequencia(jogos[i])];
  }
}

unsigned long Sequencia::checkSequencia(std::vector<unsigned long> jogo) {
  unsigned long sequencia = 0;
  unsigned long sequenciaMaxima = 0;
  for (unsigned long i = 1; i < jogo.size(); ++i) {
    if (jogo[i] == (jogo[i - 1] + 1)) {
      ++sequencia;
    } else {
      if (sequencia > sequenciaMaxima) {
        sequenciaMaxima = sequencia;
      }
      sequencia = 0;
    }
  }
  if (sequencia > sequenciaMaxima) {
    sequenciaMaxima = sequencia;
  }
  return sequenciaMaxima;
}

/**
 * @brief Retornar o valor da freqência de vezes que aquele tipo saíu em
 * porcentagem (%)
 *
 * @param tipo De 0 para nunca a 6 para todos os números
 * @return long double Resultado em porcentagem
 */
long double Sequencia::getResultadoPorcentagem(unsigned long tipo) {
  long double final = getResultado(tipo);
  return cacularPorcentagem(quantidadeDeJogos, final);
}

/**
 * @brief Retornar o valor da freqência de vezes que aquele tipo saíu
 *
 * @param tipo De 0 para nunca a 6 para todos os números
 * @return unsigned long Resultado
 */
unsigned long Sequencia::getResultado(unsigned long tipo) {
  return resultado[tipo];
}

/**
 * @brief Calcular a porcentagem das ocorrências
 *
 * @param montante Qunatidade de jogos analisados
 * @param ocorrencia Quantidade de ocorrencias do tipo
 * @return double Porcentagem (%)
 */
long double Sequencia::cacularPorcentagem(unsigned long montante,
                                          unsigned long ocorrencia) {
  double resultado = ((double)ocorrencia / (double)montante);
  return (resultado * 100);
}