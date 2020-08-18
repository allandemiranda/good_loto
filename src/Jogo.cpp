/**
 * @file Jogo.cpp
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief 
 * @version 0.1
 * @date 18-08-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "Jogo.h"

/**
 * @brief Construct a new Jogo:: Jogo object
 *
 * @param b1
 * @param b2
 * @param b3
 * @param b4
 * @param b5
 * @param b6
 */
Jogo::Jogo(unsigned short int b1, unsigned short int b2, unsigned short int b3,
           unsigned short int b4, unsigned short int b5,
           unsigned short int b6) {
  jogo.push_back(b1);
  jogo.push_back(b2);
  jogo.push_back(b3);
  jogo.push_back(b4);
  jogo.push_back(b5);
  jogo.push_back(b6);
}

Jogo::~Jogo() {}