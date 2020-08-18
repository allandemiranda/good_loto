/**
 * @file Tabela.cpp
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief
 * @version 0.1
 * @date 17-08-2020
 *
 * @copyright Copyright (c) 2020
 *
 */

#include "Tabela.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Sorteio.h"

/**
 * @brief Construct a new Tabela:: Tabela object
 *
 * @param arquivo Caminho do arquivo com os dados dos sorteios
 */
Tabela::Tabela(std::string arquivo) {
  try {
    std::ifstream file(arquivo);
    std::string line;
    while (std::getline(file, line)) {
      std::string delimiter = ",";
      size_t pos_start = 0, pos_end, delim_len = delimiter.length();
      std::string token;
      std::vector<std::string> res;
      while ((pos_end = line.find(delimiter, pos_start)) != std::string::npos) {
        token = line.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
      }
      res.push_back(line.substr(pos_start));
      Sorteio temp(res);
      setSorteio(temp);
    }
    file.close();
  } catch (const std::ios_base::failure& e) {
    std::cerr << "Erro ao abrir a arquivo de jogos" << std::endl;
    std::cerr << e.what() << '\n';
  }

  try {
    setQuantidade(sorteios[sorteios.size() - 1].getNumero());
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    throw;
  }
}

/**
 * @brief Destroy the Tabela:: Tabela object
 *
 */
Tabela::~Tabela(void) {}

/**
 * @brief Get the Quantidade object
 *
 * @return unsigned short int Quantidade de jogos sorteados
 */
unsigned short int Tabela::getQuantidade(void) { return quantidade; }

/**
 * @brief Set the Quantidade object
 *
 * @param novaQuantidade Quantidade de jogos sorteados
 */
void Tabela::setQuantidade(unsigned short int novaQuantidade) {
  try {
    quantidade = novaQuantidade;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    throw;
  }
}

/**
 * @brief Get the Sorteio object
 *
 * @param numero Número do sorteio
 * @return Sorteio Objeto Sorteio
 */
Sorteio Tabela::getSorteio(unsigned short int numero) {
  try {
    unsigned short int pos = 0;
#pragma omp parallel for
    for (unsigned short int i = 0; i < getQuantidade(); ++i) {
      if (sorteios[i].getNumero() == numero) {
#pragma omp critical
        { pos = i; }
#pragma omp cancellation point for
      }
    }
    return sorteios[pos];
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    throw;
  }
}

/**
 * @brief Set the Sorteio object
 *
 * @param sorteio Objeto Sorteio
 */
void Tabela::setSorteio(Sorteio sorteio) {
  try {
    sorteios.push_back(sorteio);
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
    throw;
  }
}