/**
 * @file main.cpp
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief
 * @version 0.1
 * @date 17-08-2020
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include "Discreta.h"
#include "Jogo.h"
#include "Tabela.h"

struct PROBA {
  unsigned short int num;
  double probabi;
};

int main(int argc, char const *argv[]) {
  Tabela table("data/jogos.csv");
  Discreta discre(table);

  std::vector<unsigned short int> numeros_finais;
  for (unsigned short int i = 1; i <= 6; ++i) {
    std::vector<PROBA> ordem;
    for (unsigned short int j = 1; j <= 60; ++j) {
      PROBA a;
      a.num = j;
      a.probabi = discre.getResultado(j, i);
      ordem.push_back(a);
    }
    std::sort(ordem.begin(), ordem.end(),
              [](PROBA a, PROBA b) { return a.probabi < b.probabi; });
    for (unsigned short int j = 1; j <= 12; ++j) {
      if (std::find(std::begin(numeros_finais), std::end(numeros_finais),
                    ordem.back().num) == std::end(numeros_finais)) {
        if (ordem.back().probabi > 0.0) {
          numeros_finais.push_back(ordem.back().num);
        }
      }
      ordem.pop_back();
    }
  }

  std::sort(numeros_finais.begin(), numeros_finais.end());
  std::cout << "Números sorteados: " << std::endl;
  std::cout << "| ";
  for (unsigned short int a : numeros_finais) {
    std::cout << a << " | ";
  }
  std::cout << " TOTAL " << numeros_finais.size() << " números ";
  std::cout << std::endl;
  std::cout << std::endl;

  std::vector<Jogo> jogos;
  for (int b1 = 1; b1 <= 60; ++b1) {
    if (std::find(std::begin(numeros_finais), std::end(numeros_finais), b1) ==
        std::end(numeros_finais)) {
      for (int b2 = b1 + 1; b2 <= 60; ++b2) {
        if (std::find(std::begin(numeros_finais), std::end(numeros_finais),
                      b2) == std::end(numeros_finais)) {
          for (int b3 = b2 + 1; b3 <= 60; ++b3) {
            if (std::find(std::begin(numeros_finais), std::end(numeros_finais),
                          b3) == std::end(numeros_finais)) {
              for (int b4 = b3 + 1; b4 <= 60; ++b4) {
                if (std::find(std::begin(numeros_finais),
                              std::end(numeros_finais),
                              b1) == std::end(numeros_finais)) {
                  for (int b5 = b4 + 1; b5 <= 60; ++b5) {
                    if (std::find(std::begin(numeros_finais),
                                  std::end(numeros_finais),
                                  b1) == std::end(numeros_finais)) {
                      for (int b6 = b5 + 1; b6 <= 60; ++b6) {
                        if (std::find(std::begin(numeros_finais),
                                      std::end(numeros_finais),
                                      b1) == std::end(numeros_finais)) {
                          Jogo temp(b1, b2, b3, b4, b5, b6);
                          jogos.push_back(temp);
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  std::cout << " TOTAL " << jogos.size() << " jogos" << std::endl;

#pragma omp parallel for
  for (unsigned long i = 0; i < jogos.size(); ++i) {
    unsigned short int num = 0;
    for (int j = 0; j < 6; ++j) {
      if (jogos[i].jogo[j] % 2 == 0) {
        ++num;
      }
    }
    if (num != 2 && num != 3 && num != 4) {
      jogos[i].teste = false;
    }
  }

  for (unsigned long i = 0; i < jogos.size(); ++i) {
    if (!jogos[i].teste) {
      jogos.erase(jogos.begin() + i);
      --i;
    }
  }

  std::cout << " TOTAL " << jogos.size() << " jogos PARTE 1 " << std::endl;

#pragma omp parallel for
  for (unsigned long i = 0; i < jogos.size(); ++i) {
    std::vector<unsigned short int> Fibonacci{1, 2, 3, 5, 8, 13, 21, 34, 55};
    unsigned short int num = 0;
    for (unsigned short int j = 0; j < 6; ++j) {
      if (std::find(std::begin(Fibonacci), std::end(Fibonacci),
                    jogos[i].jogo[j]) != std::end(Fibonacci)) {
        ++num;
      }
    }
    if (num != 0 && num != 1 && num != 2) {
      jogos[i].teste = false;
    }
  }

  for (unsigned long i = 0; i < jogos.size(); ++i) {
    if (!jogos[i].teste) {
      jogos.erase(jogos.begin() + i);
      --i;
    }
  }

  std::cout << " TOTAL " << jogos.size() << " jogos PARTE 2 " << std::endl;

#pragma omp parallel for
  for (unsigned long i = 0; i < jogos.size(); ++i) {
    std::vector<unsigned short int> Primos{2,  3,  5,  7,  11, 13, 17, 19, 23,
                                           29, 31, 37, 41, 43, 47, 53, 59};
    unsigned short int num = 0;
    for (unsigned short int j = 0; j < 6; ++j) {
      if (std::find(std::begin(Primos), std::end(Primos), jogos[i].jogo[j]) !=
          std::end(Primos)) {
        ++num;
      }
    }
    if (num == 4 || num == 5 || num == 6) {
      jogos[i].teste = false;
    }
  }

  for (unsigned long i = 0; i < jogos.size(); ++i) {
    if (!jogos[i].teste) {
      jogos.erase(jogos.begin() + i);
      --i;
    }
  }

  std::cout << " TOTAL " << jogos.size() << " jogos PARTE 3 " << std::endl;

#pragma omp parallel for
  for (unsigned long i = 0; i < jogos.size(); ++i) {
    unsigned short int num = 0;
    for (int j = 0; j < 6; ++j) {
      if (jogos[i].jogo[j] % 3 == 0) {
        ++num;
      }
    }
    if (num == 5 || num == 6) {
      jogos[i].teste = false;
    }
  }

  for (unsigned long i = 0; i < jogos.size(); ++i) {
    if (!jogos[i].teste) {
      jogos.erase(jogos.begin() + i);
      --i;
    }
  }

  std::cout << " TOTAL " << jogos.size() << " jogos PARTE 4 " << std::endl;

  for (unsigned long i = 0; i < jogos.size(); ++i) {
    unsigned short int num = 0;
    for (int j = 0; j < 6; ++j) {
      num += jogos[i].jogo[j];
    }
    if (num < 84 || num > 280) {
      jogos[i].teste = false;
    }
  }

  for (unsigned long i = 0; i < jogos.size(); ++i) {
    if (!jogos[i].teste) {
      jogos.erase(jogos.begin() + i);
      --i;
    }
  }

  std::cout << " TOTAL " << jogos.size() << " jogos PARTE 5 " << std::endl;

  for (unsigned long i = 0; i < jogos.size(); ++i) {
    unsigned short int num = 0;
    for (int j = 0; j < 6; ++j) {
      if (std::find(
              std::begin(
                  table.getSorteio(table.getQuantidade()).getResultado()),
              std::end(table.getSorteio(table.getQuantidade()).getResultado()),
              jogos[i].jogo[j]) !=
          std::end(table.getSorteio(table.getQuantidade()).getResultado())) {
        ++num;
      }
    }
    if (num > 2) {
      jogos[i].teste = false;
    }
  }

  for (unsigned long i = 0; i < jogos.size(); ++i) {
    if (!jogos[i].teste) {
      jogos.erase(jogos.begin() + i);
      --i;
    }
  }

  std::cout << " TOTAL " << jogos.size() << " jogos PARTE 6 " << std::endl;

  for (unsigned long i = 0; i < jogos.size(); ++i) {
    unsigned short int num = 0;
    for (int j = 1; j < 6; ++j) {
      if (jogos[i].jogo[j] == (jogos[i].jogo[j - 1] + 1)) {
        ++num;
        if (num > 2) {
          jogos[i].teste = false;
          break;
        }
      }
    }
  }

  for (unsigned long i = 0; i < jogos.size(); ++i) {
    if (!jogos[i].teste) {
      jogos.erase(jogos.begin() + i);
      --i;
    }
  }

  std::cout << " TOTAL " << jogos.size() << " jogos PARTE 7 " << std::endl;

  return 0;
}
