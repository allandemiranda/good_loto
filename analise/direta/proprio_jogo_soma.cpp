/**
 * @brief Programa para gerar analise em cima dos jogos sorteados - Soma
 * 
 * @file proprio_jogo_soma.cpp
 * @author Allan de Miranda Silva
 * @date 11-09-2018
 */

// ### REGRA PARA SOMA ### Soma dos resultados que podem sair
// Para 1 jogos
// {150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 239, 240, 241}
// Para 2 jogos
// {312, 314, 315, 322, 323, 324, 327, 328, 329, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 348, 349, 350, 351, 352, 353, 354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 378, 379, 380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 398, 399, 400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 418, 419, 420, 421, 422, 423, 424, 425, 426, 427, 428, 429, 430, 431, 432, 433, 434, 435, 436, 437, 438, 439, 440, 441, 442, 444, 445, 446, 447, 448, 449, 450, 451, 452, 457, 459, 461, 462}
// Para 3 jogos
// {489, 493, 496, 498, 501, 503, 507, 510, 512, 513, 514, 516, 517, 519, 520, 521, 522, 523, 524, 525, 526, 527, 528, 529, 530, 531, 532, 533, 534, 535, 536, 537, 538, 539, 540, 541, 542, 543, 544, 545, 546, 547, 548, 549, 550, 551, 552, 553, 554, 555, 556, 557, 558, 559, 560, 561, 562, 563, 564, 565, 566, 567, 568, 569, 570, 571, 572, 573, 574, 575, 576, 577, 578, 579, 580, 581, 582, 583, 584, 585, 586, 587, 588, 589, 590, 591, 592, 593, 594, 595, 596, 597, 598, 599, 600, 601, 602, 603, 604, 605, 606, 607, 608, 609, 610, 611, 612, 613, 614, 615, 616, 617, 618, 619, 620, 621, 622, 623, 624, 625, 626, 627, 628, 629, 630, 631, 632, 633, 634, 635, 636, 637, 638, 639, 640, 641, 642, 643, 644, 645, 646, 648, 649, 650, 651, 652, 653, 656, 657, 658, 661, 663, 665, 667, 670, 671, 673, 679}

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include "../numeros_sorteados.h"

/**
 * @brief Main
 * 
 * @param argc  
 * @param argv recebe o número de jogos a analisar
 * @return int 
 */
int main(int argc, char *argv[ ]){

    // Vetor com todas as ocorrências
    std::vector <int> ocorrencias;

    // Quantidade de jogos que será analisado
    int tamanho_amostra = (atoi(argv[1]) * 15);

    // Fazer a soma
    for(auto *jogo = (std::end(numeros_sorteados) - 1), soma(0); jogo >= (std::begin(numeros_sorteados) + tamanho_amostra - 1) ; jogo -= 15, soma = 0){
        for(auto i(0); i<tamanho_amostra; ++i){                
            soma += *(jogo - i);                
        }        
        ocorrencias.push_back(soma);
    }

    // Ordenar ocorrências
    std::sort(ocorrencias.begin(), ocorrencias.end());

    // Contar respostas
    std::vector <int> respostas_valor;
    std::vector <int> respostas_contador;
    auto valor = ocorrencias[0];
    int contador(0);
    for(auto i = ocorrencias.begin(); i<ocorrencias.end(); ++i){      
        if(*i == valor){            
            if((ocorrencias.end()-1) == i){
                ++contador;
                respostas_valor.push_back(valor);
                respostas_contador.push_back(contador);
            } else {
                ++contador;
            }
        } else {
            respostas_valor.push_back(valor);
            respostas_contador.push_back(contador);
            valor = *i;
            contador = 1; 
        }
    }

    // Maior contador para calcular porcentagm
    int maior_contador = respostas_contador[0];
    for(int i : respostas_contador){
        if(i>maior_contador){
            maior_contador = i;
        }
    }

    // Imprimir como uma lista
    auto tamanho_resposta = respostas_valor.size();
    for(auto i = respostas_valor[0]; i <= respostas_valor[tamanho_resposta-1]; ++i){
        bool flag(true);
        for(auto j(0); j<tamanho_resposta; ++j){
            if(i == respostas_valor[j]){
                std::cout << "Soma " << i << " saiu " << respostas_contador[j] << " vezes. " << "( " << (float) ((respostas_contador[j]*100)/maior_contador) << "% )"<< std::endl;
                flag = false;
                break;
            }
        }
        if(flag){
            std::cout << "Soma " << i << " saiu " << 0 << " vezes." << std::endl;
        }
    }

    std::cout << "-----------------------------------" << std::endl;

    // Imprimir como um vetor    
    for(auto i(0); i<(tamanho_resposta - 1); ++i){
        std::cout << respostas_valor[i] << ", ";
    }
    std::cout << respostas_valor[(tamanho_resposta - 1)] << std::endl; 

    std::cout << "-----------------------------------" << std::endl;   

    return 0;
}