/**
 * @file Jogo.h
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief
 * @version 0.1
 * @date 18-08-2020
 *
 * @copyright Copyright (c) 2020
 *
 */

#ifndef JOGO_H_
#define JOGO_H_

#include <vector>

class Jogo {
 private:
  

 public:
  Jogo(unsigned short int, unsigned short int, unsigned short int,
       unsigned short int, unsigned short int, unsigned short int);
  ~Jogo(void);
  std::vector<unsigned short int> jogo;
  bool teste = true;
};



#endif