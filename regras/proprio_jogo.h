/**
 * @brief Regras geradas pela analise dos números do próprio jogo
 * 
 * @file proprio_jogo.h
 * @author Allan de Miranda Silva
 * @date 13-09-2018
 */

#include <iterator>
#include <vector>
#include <algorithm>

/**
 * @brief Função para verificar quantos números são sorteados e sairam no jogo anterior
 * 
 * @param inicial 
 * @param tamanho_amostra_vetor 
 * @param distancia_tamanho_amostra_vetor 
 * @param respostas 
 * @return true 
 * @return false 
 */
bool proprio_jogo_analise_anterior(int *inicial, int *tamanho_amostra_vetor, int distancia_tamanho_amostra_vetor, std::vector < std::vector <int> > respostas){
    for(auto posicao(0); posicao < distancia_tamanho_amostra_vetor; ++posicao){
        // Correção de jogos para números de elementos
        int tamanho_amostra = (tamanho_amostra_vetor[posicao] * 15);
        
        // Inicialise a Soma
        int soma(0);

        // Inicialização do jogo que será analisado com o jogo anteior
        int quantidade_de_numeros_analisar = 15;
        int numeros_para_analise[15];
        for(auto i(0); i<15; ++i){
            numeros_para_analise[i] = *(inicial + i);
        }

        // Analisar se a amostra for maior que 1 jogo
        for(auto i(0); i<quantidade_de_numeros_analisar; ++i){
            for(auto j(0); j<tamanho_amostra; ++j){
                if(numeros_para_analise[i] == *(std::end(numeros_sorteados) - 1 - j)){
                    soma++;
                }
            }
        }

        // Verificar a ocorencia corresponde aos resultados possiveis
        int tamanho_do_vetor_resposta = respostas[posicao].size();
        bool marcador(true);
        for(auto i(0); i<tamanho_do_vetor_resposta; ++i){
            if(soma == respostas[posicao][i]){
                marcador = false;
                break;
            }
        }
        if(marcador){
            return false;
            break;
        }
    }

    return true;
}

/**
 * @brief Função para somar os resultados e dividir pelo seu amior número sorteado
 * 
 * @param inicial 
 * @param tamanho_amostra_vetor 
 * @param distancia_tamanho_amostra_vetor 
 * @param respostas 
 * @return true 
 * @return false 
 */
bool proprio_jogo_analise_somaDividida(int *inicial, int *tamanho_amostra_vetor, int distancia_tamanho_amostra_vetor, std::vector < std::vector <int> > respostas){
    for(auto posicao(0); posicao < distancia_tamanho_amostra_vetor; ++posicao){
        // Correção de jogos para números de elementos
        int tamanho_amostra = ((*(tamanho_amostra_vetor + posicao) - 1) * 15);        
        
        // Inicialise a Soma
        int soma(0);

        // Inicializar o maior
        int maior = *inicial;

        // Analisar se a amostra for maior que 1 jogo        
        for(auto j(0); j<tamanho_amostra; ++j){    
            soma += *(std::end(numeros_sorteados) - 1 - j);
            if(*(std::end(numeros_sorteados) - 1 - j) > maior){
                maior = *(std::end(numeros_sorteados) - 1 - j);
            }
        }                     

        // Analisar e preencher para o jogo        
        for(auto j(0); j<15; ++j){
            soma += *(inicial + j);
            if(*(inicial + j) > maior){
                maior = *(inicial + j);
            }
        }        

        // Verificar a ocorencia corresponde aos resultados possiveis
        int tamanho_do_vetor_resposta = respostas[posicao].size();
        bool marcador(true); 
        soma = soma / maior;       
        for(auto i(0); i<tamanho_do_vetor_resposta; ++i){
            if(soma == respostas[posicao][i]){
                marcador = false;
                break;
            }
        }
        if(marcador){            
            return false;
            break;
        }
    }

    return true;
}

/**
 * @brief Analisar a soma dos resultados obtidos
 * 
 * @param inicial 
 * @param tamanho_amostra_vetor 
 * @param distancia_tamanho_amostra_vetor 
 * @param respostas 
 * @return true 
 * @return false 
 */
bool proprio_jogo_analise_soma(int *inicial, int *tamanho_amostra_vetor, int distancia_tamanho_amostra_vetor, std::vector < std::vector <int> > respostas){
    for(auto posicao(0); posicao < distancia_tamanho_amostra_vetor; ++posicao){
        // Correção de jogos para números de elementos
        int tamanho_amostra = ((*(tamanho_amostra_vetor + posicao) - 1) * 15);        
        
        // Inicialise a Soma
        int soma(0);

        // Analisar se a amostra for maior que 1 jogo        
        for(auto j(0); j<tamanho_amostra; ++j){    
            soma += *(std::end(numeros_sorteados) - 1 - j);
        }                     

        // Analisar e preencher para o jogo        
        for(auto j(0); j<15; ++j){
            soma += *(inicial + j);
        }        

        // Verificar a ocorencia corresponde aos resultados possiveis
        int tamanho_do_vetor_resposta = respostas[posicao].size();
        bool marcador(true);
        for(auto i(0); i<tamanho_do_vetor_resposta; ++i){
            if(soma == respostas[posicao][i]){
                marcador = false;
                break;
            }
        }
        if(marcador){            
            return false;
            break;
        }
    }

    return true;
}

/**
 * @brief Função para verificar se já foi sorteado o jogo sabendo que ele nunca se repete
 * 
 * @param primeiro 
 * @return true 
 * @return false 
 */
bool nunca_saiu(int *primeiro){
    for(auto *jogo=std::begin(numeros_sorteados); jogo<std::end(numeros_sorteados); jogo+=15){
        int cont(0);
        for(int i(0); i<15; ++i){
            for(int j(0); j<15; ++j){
                if(*(jogo+i)==*(primeiro+j)){
                    ++cont;
                }
            }
        }
        if(cont == 15){
            return false;
        }
    }
    return true;
}

/**
 * @brief Função que verifica somente todas as regras fibonacci
 * 
 * @param primeiro Aponta para o primeiro número do jogo que queremos analisar
 * @return true Para se todas as regras estão valendo
 * @return false Para se pelomenos uma regra não está valendo
 */
bool regras_gerais_proprio_jogo(int *primeiro){

    // Tamanho das Amostras
    int tamanho_amostra_vetor_soma[] = {1,2,3};
    int tamanho_amostra_vetor_anterior[] = {1,2};
    int tamanho_amostra_vetor_somaDividida[] = {1,2,3,5};

    // Respostas
    std::vector < std::vector <int> > respostas_soma = {
        {
            141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 239, 240, 241, 242, 243, 244, 245
        },
        {
            312, 314, 315, 322, 323, 324, 327, 328, 329, 331, 332, 333, 334, 335, 336, 337, 338, 339, 340, 341, 342, 343, 344, 345, 346, 347, 348, 349, 350, 351, 352, 353, 354, 355, 356, 357, 358, 359, 360, 361, 362, 363, 364, 365, 366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 378, 379, 380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 398, 399, 400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 418, 419, 420, 421, 422, 423, 424, 425, 426, 427, 428, 429, 430, 431, 432, 433, 434, 435, 436, 437, 438, 439, 440, 441, 442, 444, 445, 446, 447, 448, 449, 450, 451, 452, 457, 459, 461, 462
        },
        {
            489, 493, 496, 498, 501, 503, 507, 510, 512, 513, 514, 516, 517, 519, 520, 521, 522, 523, 524, 525, 526, 527, 528, 529, 530, 531, 532, 533, 534, 535, 536, 537, 538, 539, 540, 541, 542, 543, 544, 545, 546, 547, 548, 549, 550, 551, 552, 553, 554, 555, 556, 557, 558, 559, 560, 561, 562, 563, 564, 565, 566, 567, 568, 569, 570, 571, 572, 573, 574, 575, 576, 577, 578, 579, 580, 581, 582, 583, 584, 585, 586, 587, 588, 589, 590, 591, 592, 593, 594, 595, 596, 597, 598, 599, 600, 601, 602, 603, 604, 605, 606, 607, 608, 609, 610, 611, 612, 613, 614, 615, 616, 617, 618, 619, 620, 621, 622, 623, 624, 625, 626, 627, 628, 629, 630, 631, 632, 633, 634, 635, 636, 637, 638, 639, 640, 641, 642, 643, 644, 645, 646, 648, 649, 650, 651, 652, 653, 656, 657, 658, 661, 663, 665, 667, 670, 671, 673, 679
        }
    };
    std::vector < std::vector <int> > respostas_anterior = {
        {
            6, 7, 8, 9, 10, 11, 12
        },
        {
            14, 15, 16, 17, 18, 19, 20, 21, 22, 23
        }
    };
    std::vector < std::vector <int> > respostas_somaDividida = {
        {
            6, 7, 8, 9
        },
        {
            3, 14, 15, 16, 17, 18
        },
        {
            20, 21, 22, 23, 24, 25, 26
        },
        {
            34, 35, 36, 37, 38, 39, 40, 41, 42
        }
    };

    // Verificar regras
    if(nunca_saiu(primeiro)){
        if(proprio_jogo_analise_soma(primeiro, std::begin(tamanho_amostra_vetor_soma), std::distance(std::begin(tamanho_amostra_vetor_soma), std::end(tamanho_amostra_vetor_soma)), respostas_soma)){
            if(proprio_jogo_analise_anterior(primeiro, std::begin(tamanho_amostra_vetor_anterior), std::distance(std::begin(tamanho_amostra_vetor_anterior), std::end(tamanho_amostra_vetor_anterior)), respostas_anterior)){
                if(proprio_jogo_analise_somaDividida(primeiro, std::begin(tamanho_amostra_vetor_somaDividida), std::distance(std::begin(tamanho_amostra_vetor_somaDividida), std::end(tamanho_amostra_vetor_somaDividida)), respostas_somaDividida)){
                    return true;
                }
            }
        }
    }

    return false;
}