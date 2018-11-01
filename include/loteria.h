/**
 * @file loteria.h
 * @author Allan de Miranda Silva
 * @brief 
 * @version 1.0
 * @date 2018-10-31
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef _LOTERIA_H_
#define _LOTERIA_H_

#include <vector>
#include <string>

/**
 * @brief Aqui ficarão dados necessarios para as loterias
 * 
 */
class loteria
{
private:
    unsigned short int quantidade_numeros_jogados = 0; // Quantidade de números que pode jogar no volante
    unsigned short int quantidade_numeros_sorteados = 0; // Quantidade de números que são sorteados do volante
    std::vector <unsigned short int> numeros_do_volante; // Números do volante do jogo (em ordem crescente) 
    float valor_da_aposta = 0; // Valor por uma aposta simples
    std::vector <std::vector <unsigned short int>> jogos_totais_do_volante; // Todos os jogos possiveis de sair no volante
    std::vector <std::vector <unsigned short int>> jogos_sorteados; // Todos os jogos já sorteados
    bool gerar_modalidade(std::vector <float>, std::string);

public:
    loteria(std::string);
    bool criar_volante(unsigned short int,unsigned short int); // Criar novo volante
    bool editar_quantidade_numeros_jogados(unsigned short int); // Adicionar quantidade de números que podem ser marcados no volante
    bool editar_quantidade_numeros_sorteados(unsigned short int); // Adicionar quantidade de números do volante que é sorteado
    bool editar_valor_da_aposta(float); // Valor em Reias de cada aposta simples
    void adicionar_jogo_possivel_ao_volante(std::vector <unsigned short int>); // Para adicionar novo jogo a lista de jogos possiveis de sair
    unsigned short int verificar_quantidade_numeros_sorteados(void);
    unsigned short int verificar_quantidade_numeros_jogados(void);
    unsigned short int verificar_quantidade_numeros_do_volante(void);
    float verificar_valor_da_aposta(void);
    unsigned long long int verificar_quantidade_jogos_totais_do_volante(void);
    std::vector <unsigned short int> veriticar_numeros_do_volante(void);  
    unsigned long long int verificar_quantidade_jogos_totais_sorteados(void);
    std::vector <unsigned short int> veriticar_jogo_sorteado(unsigned long long int); // Lembrar que inicia em 1 (não em zero)
    void adicionar_jogo_sorteado(std::vector <unsigned short int>);
};

#endif