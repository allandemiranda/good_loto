/**
 * @file Listadejogos.cpp
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief
 * @version 0.1
 * @date 07-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "Listadejogos.h"

#include <fstream>
#include <iostream>

/**
 * @brief Construct a new Listadejogos:: Listadejogos object
 *
 * @param arquivo Caminho do arquivo
 */
Listadejogos::Listadejogos(std::string arquivo) { getJogos(arquivo); }

/**
 * @brief Retornar um jogo específico
 *
 * @param numero Número do sorteio
 * @return std::vector<unsigned long> Jogo
 */
std::vector<unsigned long> Listadejogos::getJogo(unsigned long numero) {
  return jogos[numero];
}

/**
 * @brief Quantdade de jogos
 *
 * @return unsigned long  Quantidade de jogos
 */
unsigned long Listadejogos::getQuantidadeDeJogos(void) { return jogos.size(); }

/**
 * @brief Capturar todos os jogos em texto
 *
 * @param arquivo Caminho do arquivo
 */
void Listadejogos::getJogos(std::string arquivo) {
  try {
    std::ifstream file(arquivo);
    std::string line;
    while (std::getline(file, line)) {
      std::vector<unsigned long> jogo;
      char c = ' ';
      std::string buff{""};
      unsigned int deletar = 0;
      for (auto n : line) {
        if (n != c) {
          buff += n;
        } else if (n == c && buff != "") {
          if(deletar == 0){
            buff = "";
            ++deletar;
            continue;
          }
          if(deletar == 1){
            buff = "";
            ++deletar;
            continue;
          }
          jogo.push_back(std::stoi(buff));
          buff = "";
        }
      }
      if (buff != "") {
        jogo.push_back(std::stoi(buff));
      }
      jogos.push_back(jogo);
    }
    file.close();
  } catch (const std::ios_base::failure& e) {
    std::cerr << "Erro ao abrir a chave" << std::endl;
  }
}