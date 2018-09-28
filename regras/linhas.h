/**
 * @brief Regras geradas para analise de todas as linhas em conjunto
 * 
 * @file linhas.h
 * @author Allan de Miranda Silva
 * @date 26-09-2018
 */

#include <iterator>
#include <vector>
#include <algorithm>
#include <cmath>

bool analise_binario_para_linhas(int *inicial, int *numeros_para_analise, int quantidade_de_numeros_analisar, int *tamanho_amostra_vetor, int distancia_tamanho_amostra_vetor, std::vector < std::vector <int> > respostas){      

    for(auto posicao(0); posicao < distancia_tamanho_amostra_vetor; ++posicao){                
        // Inicializar binário
        int binario[quantidade_de_numeros_analisar];
        for(auto i(0); i<quantidade_de_numeros_analisar; ++i){
            binario[i] = 0;
        }

        // Correção de jogos para números de elementos
        int tamanho_amostra = ((tamanho_amostra_vetor[posicao] - 1) * 15);
        if(tamanho_amostra>0){
            // Analisar e preencher o binário se a amostra for maior que 1 jogo
            for(auto i(0); i<quantidade_de_numeros_analisar; ++i){
                for(auto j(0); j<tamanho_amostra; ++j){
                    if(numeros_para_analise[i] == *(std::end(numeros_sorteados) - 1 - j)){
                        binario[i] = 1;
                    }
                }
            }
        }

        // Analisar e preencher para o jogo
        for(auto i(0); i<quantidade_de_numeros_analisar; ++i){
            if(std::binary_search(inicial, inicial+15, numeros_para_analise[i])){
                binario[i] = 1;
            }            
        }

        // Gravar binário
        int binario_final(0);
        for(int i(0); i<(quantidade_de_numeros_analisar/5); ++i){            
            for(int j(0); j<5; ++j){
                if(binario[(i*5)+j] == 1){
                    binario_final += std::pow(10, i);
                    break;
                }
            }
        }

        // Verificar a ocorencia corresponde aos resultados possiveis        
        bool marcador(true);
        if(std::binary_search(respostas[posicao].begin(), respostas[posicao].end(), binario_final)){
            marcador = false;
        }
        if(marcador){
            return false;
        }
    }

    return true;
}

/**
 * @brief Verifica quantidade de numeros que saiu por linha binariamente
 * 
 * @param inicial 
 * @param numeros_para_analise 
 * @param quantidade_de_numeros_analisar 
 * @param tamanho_amostra_vetor 
 * @param distancia_tamanho_amostra_vetor 
 * @param respostas 
 * @return true 
 * @return false 
 */
bool analise_numerico_para_linhas(int *inicial, int *numeros_para_analise, int quantidade_de_numeros_analisar, int *tamanho_amostra_vetor, int distancia_tamanho_amostra_vetor, std::vector < std::vector <int> > respostas){
    for(auto posicao(0); posicao < distancia_tamanho_amostra_vetor; ++posicao){                
        // Inicializar binário
        int binario[quantidade_de_numeros_analisar];
        for(auto i(0); i<quantidade_de_numeros_analisar; ++i){
            binario[i] = 0;
        }

        // Correção de jogos para números de elementos
        int tamanho_amostra = ((tamanho_amostra_vetor[posicao] - 1) * 15);
        if(tamanho_amostra>0){
            // Analisar e preencher o binário se a amostra for maior que 1 jogo
            for(auto i(0); i<quantidade_de_numeros_analisar; ++i){
                for(auto j(0); j<tamanho_amostra; ++j){
                    if(numeros_para_analise[i] == *(std::end(numeros_sorteados) - 1 - j)){
                        binario[i] = 1;
                    }
                }
            }
        }
        
        // Analisar e preencher para o jogo
        for(auto i(0); i<quantidade_de_numeros_analisar; ++i){
            if(std::binary_search(inicial, inicial+15, numeros_para_analise[i])){
                binario[i] = 1;
            }            
        }

        // Gravar binário
        int binario_final_temporario[5];
        for(int i(0); i<(quantidade_de_numeros_analisar/5); ++i){
            binario_final_temporario[i] = 0;
        }        
        for(int i(0); i<(quantidade_de_numeros_analisar/5); ++i){
            int somar_binarios(0);            
            for(int j(0); j<5; ++j){
                if(binario[(i*5)+j] == 1){
                    somar_binarios++;
                }
            }
            binario_final_temporario[i] = somar_binarios;  
        }
        std::sort(std::begin(binario_final_temporario),std::end(binario_final_temporario));
        int binario_final(0);
        for(int i(0); i<(quantidade_de_numeros_analisar/5); ++i){
            binario_final += (binario_final_temporario[i] * std::pow(10, i));
        }        

        // Verificar a ocorencia corresponde aos resultados possiveis        
        bool marcador(true);
        if(std::binary_search(respostas[posicao].begin(), respostas[posicao].end(), binario_final)){
            marcador = false;
        }
        if(marcador){
            return false;
        }
    }

    return true;
}

/**
 * @brief Função que verifica somente todas as regras das linhas
 * 
 * @param primeiro Aponta para o primeiro número do jogo que queremos analisar
 * @return true Para se todas as regras estão valendo
 * @return false Para se pelomenos uma regra não está valendo
 */
bool linhas_analise(int *primeiro){
    // Números a analisar
    int numeros_para_analise[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};

    // Tamanho das Amostras
    int tamanho_amostra_vetor_binario_para_linhas[] = {1};
    int tamanho_amostra_vetor_numerico_para_linhas[] = {1};

    // Respostas
    std::vector < std::vector <int> > respostas_binario_para_linhas = {
        {
            1111, 10111, 11011, 11101, 11110, 11111
        }
    };
    std::vector < std::vector <int> > respostas_numerico_para_linhas = {
        {
            33333, 43332, 44322, 44331, 44421, 44430, 53322, 53331, 54222, 54321, 54330, 54411, 54420, 55221, 55311
        }
    };

    // Verificar regras
    if(analise_binario_para_linhas(primeiro, std::begin(numeros_para_analise), std::distance(std::begin(numeros_para_analise), std::end(numeros_para_analise)), std::begin(tamanho_amostra_vetor_binario_para_linhas), std::distance(std::begin(tamanho_amostra_vetor_binario_para_linhas), std::end(tamanho_amostra_vetor_binario_para_linhas)), respostas_binario_para_linhas)){       
        if(analise_numerico_para_linhas(primeiro, std::begin(numeros_para_analise), std::distance(std::begin(numeros_para_analise), std::end(numeros_para_analise)), std::begin(tamanho_amostra_vetor_numerico_para_linhas), std::distance(std::begin(tamanho_amostra_vetor_numerico_para_linhas), std::end(tamanho_amostra_vetor_numerico_para_linhas)), respostas_numerico_para_linhas)){       
            return true;
        }
    }
    return false;
}