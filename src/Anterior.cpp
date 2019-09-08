/**
 * @file Anterior.cpp
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief
 * @version 0.1
 * @date 08-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "Anterior.h"

/**
 * @brief Construct a new Anterior:: Anterior object
 *
 * @param jogos Jogos sorteados
 */
Anterior::Anterior(std::vector<std::vector<unsigned long>>& jogos) {
  for (unsigned long i = 0; i <= jogos[0].size(); ++i) {
    resultado.push_back(0);
  }
  quantidadeDeJogos = jogos.size();

  for (unsigned long i = 1; i < jogos.size(); ++i) {
    ++resultado[checkAnterior(jogos[i], jogos[i - 1])];
  }
}

/**
 * @brief Verificar quantos números saem no jogo anterior
 *
 * @param JogoAtual Jogo atual
 * @param JogoAnterior Jogo anterior
 * @return unsigned long Quantidade de números iguas
 */
unsigned long Anterior::checkAnterior(std::vector<unsigned long> JogoAtual,
                                      std::vector<unsigned long> JogoAnterior) {
  unsigned long contador = 0;
  for (unsigned long i = 0; i < JogoAtual.size(); ++i) {
    for (unsigned long j = 0; j < JogoAnterior.size(); ++j) {
      if (JogoAtual[i] == JogoAnterior[j]) {
        ++contador;
        break;
      }
    }
  }
  return contador;
}

/**
 * @brief Retornar o valor da freqência de vezes que aquele tipo saíu em
 * porcentagem (%)
 *
 * @param tipo De 0 para nunca a 6 para todos os números
 * @return long double Resultado em porcentagem
 */
long double Anterior::getResultadoPorcentagem(unsigned long tipo) {
  long double final = getResultado(tipo);
  return cacularPorcentagem(quantidadeDeJogos - 1, final);
}

/**
 * @brief Retornar o valor da freqência de vezes que aquele tipo saíu
 *
 * @param tipo De 0 para nunca a 6 para todos os números
 * @return unsigned long Resultado
 */
unsigned long Anterior::getResultado(unsigned long tipo) {
  return resultado[tipo];
}

/**
 * @brief Calcular a porcentagem das ocorrências
 *
 * @param montante Qunatidade de jogos analisados
 * @param ocorrencia Quantidade de ocorrencias do tipo
 * @return double Porcentagem (%)
 */
long double Anterior::cacularPorcentagem(unsigned long montante,
                                         unsigned long ocorrencia) {
  double resultado = ((double)ocorrencia / (double)montante);
  return (resultado * 100);
}