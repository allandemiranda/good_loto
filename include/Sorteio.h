/**
 * @file Sorteio.h
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief
 * @version 0.1
 * @date 17-08-2020
 *
 * @copyright Copyright (c) 2020
 *
 */

#ifndef SORTEIO_H_
#define SORTEIO_H_

#include <string>
#include <vector>

class Sorteio {
 private:
  std::vector<unsigned short int> resultado;
  unsigned short int numero;
  unsigned short int ganhadores;
  std::string data;
  void setNumero(std::string);
  void setGanhadores(std::string);
  void setData(std::string);
  void setResultado(std::string,std::string,std::string,std::string,std::string,std::string);

 public:
  Sorteio(std::vector<std::string>);
  ~Sorteio(void);
  unsigned short int getPares(void);
  unsigned short int getImpares(void);
  unsigned short int getFibonacci(void);
  unsigned short int getPrimos(void);
  unsigned short int getSequencia(void);
  unsigned short int getDivisiveis(unsigned short int);
  unsigned short int getRepetidos(std::vector<unsigned short int>);
  unsigned short int getNumero(void);  
  unsigned short int getGanhadores(void);  
  unsigned short int getDataDia(void);
  unsigned short int getDataMes(void);
  unsigned short int getDataAno(void);  
  unsigned short int getResultadoPosicao(unsigned short int);
  std::vector<unsigned short int> getResultado(void);
  std::vector<unsigned short int> getResultadoOrdenado(void);
};

#endif