/**
 * @file Sorteio.cpp
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief
 * @version 0.1
 * @date 17-08-2020
 *
 * @copyright Copyright (c) 2020
 *
 */

#include "Sorteio.h"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

/**
 * @brief Construct a new Sorteio:: Sorteio object
 *
 * @param dados Informações do Sorteio
 */
Sorteio::Sorteio(std::vector<std::string> dados) {
  try {
    setNumero(dados[0]);
    setData(dados[1]);
    setResultado(dados[2], dados[3], dados[4], dados[5], dados[6], dados[7]);
    setGanhadores(dados[8]);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    throw;
  }
}

/**
 * @brief Destroy the Sorteio:: Sorteio object
 *
 */
Sorteio::~Sorteio(void) {}

/**
 * @brief Get the Pares object
 *
 * @return unsigned short int Quantidade de números pares no Sorteio
 */
unsigned short int Sorteio::getPares(void) {
  try {
    unsigned short int num = 0;
#pragma omp parallel for reduction(+ : num)
    for (unsigned short int i = 0; i < 6; ++i) {
      if (resultado[i] % 2 == 0) {
        num += 1;
      }
    }
    return num;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    throw;
  }
}

/**
 * @brief Get the Impares object
 *
 * @return unsigned short int Quantidade de números ímpares no Sorteio
 */
unsigned short int Sorteio::getImpares(void) {
  try {
    unsigned short int num = getPares();
    return 6 - num;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    throw;
  }
}

/**
 * @brief Get the Fibonacci object
 *
 * @return unsigned short int Quantidade de números Fibonacci no Sorteio
 */
unsigned short int Sorteio::getFibonacci(void) {
  try {
    std::vector<unsigned short int> Fibonacci{1, 2, 3, 5, 8, 13, 21, 34, 55};
    unsigned short int num = 0;
#pragma omp parallel for reduction(+ : num)
    for (unsigned short int i = 0; i < 6; ++i) {
      if (std::find(std::begin(Fibonacci), std::end(Fibonacci), resultado[i]) !=
          std::end(Fibonacci)) {
        num += 1;
      }
    }
    return num;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    throw;
  }
}

/**
 * @brief Get the Primos object
 *
 * @return unsigned short int Quantidade de números primos no Sorteio
 */
unsigned short int Sorteio::getPrimos(void) {
  try {
    std::vector<unsigned short int> Primos{2,  3,  5,  7,  11, 13, 17, 19, 23,
                                           29, 31, 37, 41, 43, 47, 53, 59};
    unsigned short int num = 0;
#pragma omp parallel for reduction(+ : num)
    for (unsigned short int i = 0; i < 6; ++i) {
      if (std::find(std::begin(Primos), std::end(Primos), resultado[i]) !=
          std::end(Primos)) {
        num += 1;
      }
    }
    return num;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    throw;
  }
}

/**
 * @brief Get the Divisiveis object
 *
 * @param numDiv Número para checar divisibilidade
 * @return unsigned short int Quantidade de números divisideis sorteados
 */
unsigned short int Sorteio::getDivisiveis(unsigned short int numDiv) {
  try {
    unsigned short int num = 0;
#pragma omp parallel for reduction(+ : num)
    for (int i = 0; i < 6; ++i) {
      if (resultado[i] % numDiv == 0) {
        num += 1;
      }
    }
    return num;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    throw;
  }
}

/**
 * @brief Get the Sequencia object
 *
 * @return unsigned short int Quantidade de números em seguência no Sorteio
 */
unsigned short int Sorteio::getSequencia(void) {
  try {
    std::vector<unsigned short int> copy_vector(resultado.size());
    std::copy(resultado.begin(), resultado.end(), copy_vector.begin());
    std::sort(copy_vector.begin(), copy_vector.end());
    unsigned short int num = 0;
#pragma omp parallel for reduction(+ : num)
    for (unsigned short int i = 1; i < 6; ++i) {
      if (copy_vector[i] == (copy_vector[i - 1] + 1)) {
        num += 1;
      }
    }
    return num;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    throw;
  }
}

/**
 * @brief Get the Repetidos object
 *
 * @param sorteio_anterior Sorteio para comparação
 * @return unsigned short int Quantidade de números repetidos entre os sorteios
 */
unsigned short int Sorteio::getRepetidos(
    std::vector<unsigned short int> sorteio_anterior) {
  try {
    std::sort(sorteio_anterior.begin(), sorteio_anterior.end());
    std::vector<unsigned short int> sorteio_atual = getResultadoOrdenado();
    unsigned short int num = 0;
    unsigned short int j = 0;
    for (unsigned short int i = 0; i < 6; ++i) {
      for (; j < 6; ++j) {
        if (sorteio_atual[i] <= sorteio_anterior[j]) {
          if (sorteio_atual[i] == sorteio_anterior[j]) {
            ++num;
          }
        } else {
          break;
        }
      }
      if (j == 7) {
        break;
      }
    }
    return num;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    throw;
  }
}

/**
 * @brief Get the Numero object
 *
 * @return unsigned short int Número do sorteio
 */
unsigned short int Sorteio::getNumero(void) { return numero; }

/**
 * @brief Set the Numero object
 *
 * @param numsorteio Número do Sorteio
 */
void Sorteio::setNumero(std::string numsorteio) {
  try {
    numero = std::stoi(numsorteio);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    throw;
  }
}
/**
 * @brief Get the Ganhadores object
 *
 * @return unsigned short int Número de ganahdores do sorteio
 */
unsigned short int Sorteio::getGanhadores(void) { return ganhadores; }

/**
 * @brief Set the Ganhadores object
 *
 * @param numGanhadores Número de ganhadores do sorteio
 */
void Sorteio::setGanhadores(std::string numGanhadores) {
  try {
    ganhadores = std::stoi(numGanhadores);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    throw;
  }
}

/**
 * @brief Get the Data Dia object
 *
 * @return unsigned short int Dia do sorteio
 */
unsigned short int Sorteio::getDataDia(void) {
  try {
    std::string delimiter = "/";
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;
    while ((pos_end = data.find(delimiter, pos_start)) != std::string::npos) {
      token = data.substr(pos_start, pos_end - pos_start);
      pos_start = pos_end + delim_len;
      res.push_back(token);
    }
    res.push_back(data.substr(pos_start));

    return std::stoi(res[0]);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    throw;
  }
}

/**
 * @brief Get the Data Mes object
 *
 * @return unsigned short int Mês do sorteio
 */
unsigned short int Sorteio::getDataMes(void) {
  try {
    std::string delimiter = "/";
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;
    while ((pos_end = data.find(delimiter, pos_start)) != std::string::npos) {
      token = data.substr(pos_start, pos_end - pos_start);
      pos_start = pos_end + delim_len;
      res.push_back(token);
    }
    res.push_back(data.substr(pos_start));

    return std::stoi(res[1]);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    throw;
  }
}

/**
 * @brief Get the Data Ano object
 *
 * @return unsigned short int Ano do sorteio
 */
unsigned short int Sorteio::getDataAno(void) {
  try {
    std::string delimiter = "/";
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;
    while ((pos_end = data.find(delimiter, pos_start)) != std::string::npos) {
      token = data.substr(pos_start, pos_end - pos_start);
      pos_start = pos_end + delim_len;
      res.push_back(token);
    }
    res.push_back(data.substr(pos_start));

    return std::stoi(res[2]);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    throw;
  }
}

/**
 * @brief Set the Data object
 *
 * @param novaData Data do sorteio
 */
void Sorteio::setData(std::string novaData) {
  try {
    data = novaData;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    throw;
  }
}

/**
 * @brief Get the Resultado Posicao object
 *
 * @param posicao Número da posição
 * @return unsigned short int Número sorteado na posição
 */
unsigned short int Sorteio::getResultadoPosicao(unsigned short int posicao) {
  try {
    return resultado[posicao - 1];
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    throw;
  }
}

/**
 * @brief Get the Resultado object
 *
 * @return std::vector<unsigned short int> Resultado do sorteio
 */
std::vector<unsigned short int> Sorteio::getResultado(void) {
  return resultado;
}

/**
 * @brief Get the Resultado Ordenado object
 *
 * @return std::vector<unsigned short int> resultado do sorteio ordenado
 */
std::vector<unsigned short int> Sorteio::getResultadoOrdenado(void) {
  try {
    std::vector<unsigned short int> copy_vector(resultado.size());
    std::copy(resultado.begin(), resultado.end(), copy_vector.begin());
    std::sort(copy_vector.begin(), copy_vector.end());
    return copy_vector;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    throw;
  }
}

/**
 * @brief Set the Resultado object
 *
 * @param n1 Bola 1
 * @param n2 Bola 2
 * @param n3 Bola 3
 * @param n4 Bola 4
 * @param n5 Bola 5
 * @param n6 Bola 6
 */
void Sorteio::setResultado(std::string n1, std::string n2, std::string n3,
                           std::string n4, std::string n5, std::string n6) {
  try {
    resultado.push_back(std::stoi(n1));
    resultado.push_back(std::stoi(n2));
    resultado.push_back(std::stoi(n3));
    resultado.push_back(std::stoi(n4));
    resultado.push_back(std::stoi(n5));
    resultado.push_back(std::stoi(n6));
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    throw;
  }
}