/**
 * @file loto._LOTO_H_
 * @author Allan de Miranda Silva (allandemiranda@gmail.com)
 * @brief Class para organizar resultados da Loto
 * @version 0.1
 * @date 2018-10-27
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#ifndef _LOTO_H_
#define _LOTO_H_

#include <vector>

class loto{
    private:
        unsigned long int tamanho_dos_jogos;
        std::vector <std::vector <unsigned short int>> jogos_sorteados;
        std::vector <std::vector <unsigned short int>> jogos_possiveis;
        // Regra da Soma
            // Maior número
        unsigned long int limites_da_soma_superior;
            // Menor número
        unsigned long int limites_da_soma_inferior;
        // Regra dos Pares x Ímpares
            // {quantidde de pares, quantidade de ímpares}
        std::vector <std::vector < unsigned long int>> pares_possiveis_PxI;
        // Regra Números em Sequência
            // Maior número
        unsigned long int limites_da_sequencia_superior; 
            // Menor número
        unsigned long int limites_da_sequencia_inferior; 
        // Regra Números Primos
            // Números primos possíveis de sair
        std::vector <unsigned short int> numeros_primos;
            // Maior número
        unsigned long int limites_dos_numeros_primos_superior; 
            // Menor número
        unsigned long int limites_dos_numeros_primos_inferior; 
        // Regra Números Múltiplos de Três
        std::vector <unsigned short int> numeros_multiplosdeTres;
            // Maior número
        unsigned long int limites_dos_numeros_multiplosdeTres_superior; 
            // Menor número
        unsigned long int limites_dos_numeros_multiplosdeTres_inferior; 
        // Regra Números Fibonacci
        std::vector <unsigned short int> numeros_fibonacci;
            // Maior número
        unsigned long int limites_dos_numeros_fibonacci_superior; 
            // Menor número
        unsigned long int limites_dos_numeros_fibonacci_inferior; 
        // Regra Dezenas Repetidas do concurso anterior 
            // Maior número
        unsigned long int limites_dos_numeros_dezenasRepetidas_superior; 
            // Menor número
        unsigned long int limites_dos_numeros_dezenasRepetidas_inferior; 

    public:
        void gerar_multiplosdeTres(void);
        void gerar_fibonacci(void);
        void gerar_numerosPrimos(void);
        void gerar_tamanho_dos_jogos(unsigned long int);

        unsigned long int adicionar_jogos_sorteados(std::vector <unsigned short int>);
        unsigned long int quantidade_jogos_sorteados(void);

        unsigned long int adicionar_jogos_possiveis(std::vector <unsigned short int>);
        unsigned long int quantidade_jogos_possiveis(void);
        void apagar_jogo_possivel(unsigned long int);

        unsigned long int tamanho_dos_jogos_usados(void);

        void adicionar_pares_PxI(unsigned long int, unsigned long int);
        void adicionar_limites_da_soma_superior(unsigned long int);
        void adicionar_limites_da_soma_inferior(unsigned long int);   
        void adicionar_limites_da_sequencia_superior(unsigned long int);
        void adicionar_limites_da_sequencia_inferior(unsigned long int);
        void adicionar_limites_dos_numeros_primos_superior(unsigned long int);
        void adicionar_limites_dos_numeros_primos_inferior(unsigned long int);
        void adicionar_limites_dos_numeros_multiplosdeTres_superior(unsigned long int);
        void adicionar_limites_dos_numeros_multiplosdeTres_inferior(unsigned long int);
        void adicionar_limites_dos_numeros_fibonacci_superior(unsigned long int);
        void adicionar_limites_dos_numeros_fibonacci_inferior(unsigned long int);
        void adicionar_limites_dos_numeros_dezenasRepetidas_superior(unsigned long int);
        void adicionar_limites_dos_numeros_dezenasRepetidas_inferior(unsigned long int);

        bool verificador_regra_limites_da_soma(std::vector <unsigned short int>);
        bool verificador_regra_PxI(std::vector <unsigned short int>);
        bool verificador_regra_sequencia(std::vector <unsigned short int>);
        bool verificador_regra_numeros_primos(std::vector <unsigned short int>);
        bool verificador_regra_numeros_multiplosdeTres(std::vector <unsigned short int>);
        bool verificador_regra_numeros_fibonacci(std::vector <unsigned short int>);
        bool verificador_regra_dezenasRepeditas(std::vector <unsigned short int>);
        
};

#endif