/**
 * @file Divisiveis.cpp
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief
 * @version 0.1
 * @date 07-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "Divisiveis.h"

/**
 * @brief Construct a new Divisiveis:: Divisiveis object
 *
 * @param jogos Jogos
 * @param numero Núemro para checar divisibilidade
 */
Divisiveis::Divisiveis(std::vector<std::vector<unsigned long>>& jogos,
                       unsigned long numero) {
  for (unsigned long i = 0; i <= jogos[0].size(); ++i) {
    resultado.push_back(0);
  }
  quantidadeDeJogos = jogos.size();

  for (unsigned long i = 0; i < jogos.size(); ++i) {
    unsigned long contador = 0;
#pragma omp parallel for reduction(+ : contador)
    for (unsigned long j = 0; j < jogos[i].size(); ++j) {
      if (seDivide(jogos[i][j], numero)) {
        contador += 1;
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
long double Divisiveis::getResultadoPorcentagem(unsigned long tipo) {
  long double final = getResultado(tipo);
  return cacularPorcentagem(quantidadeDeJogos, final);
}

/**
 * @brief Retornar o valor da freqência de vezes que aquele tipo saíu
 *
 * @param tipo De 0 para nunca a 6 para todos os números
 * @return unsigned long Resultado
 */
unsigned long Divisiveis::getResultado(unsigned long tipo) {
  return resultado[tipo];
}

/**
 * @brief Calcular a porcentagem das ocorrências
 *
 * @param montante Qunatidade de jogos analisados
 * @param ocorrencia Quantidade de ocorrencias do tipo
 * @return double Porcentagem (%)
 */
long double Divisiveis::cacularPorcentagem(unsigned long montante,
                                           unsigned long ocorrencia) {
  double resultado = ((double)ocorrencia / (double)montante);
  return (resultado * 100);
}

/**
 * @brief Verifica se o número divisivel
 *
 * @param numero Número para verificar
 * @param divisor Número divisor
 * @return true É um número divisor
 * @return false É um número divisor
 */
bool Divisiveis::seDivide(unsigned long numero, unsigned long divisor) {
  if ((numero % divisor) == 0) {
    return true;
  } else {
    return false;
  }
}