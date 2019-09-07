/**
 * @file Listadejogos.h
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief
 * @version 0.1
 * @date 07-09-2019
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef LISTADEJOGOS_H_
#define LISTADEJOGOS_H_

#include <string>
#include <vector>

class Listadejogos {
 private:
  void getJogos(std::string);

 public:
  unsigned long getQuantidadeDeJogos(void);
  std::vector<unsigned long> getJogo(unsigned long);
  std::vector<std::vector<unsigned long>> jogos;
  Listadejogos(std::string);
};

#endif