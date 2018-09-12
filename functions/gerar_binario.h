/**
 * @brief Função para gerar quantidade de binários existente para o tamnho da amostra
 * 
 * @file gerar_binario.h
 * @author Allan de Miranda Silva
 * @date 11-09-2018
 */

/**
 * @brief Função para calcular números de binários possiveis
 * 
 * @param estagio_final Quantidade de bits que tem a amostra
 * @param estagio_atual 
 * @param soma 
 * @return size_t Retirna quantidade de binários possivis
 */
int rebobinar(int estagio_final, int estagio_atual = 0, int soma = 0){
    // Chave de segurança para limite de bits
    if(estagio_final > 10){
        return 0;
    }

    // Inicializar contagem
    int total(0);

    // Caso seja a primeira rodada
    if((soma == 0) and (estagio_atual == 0)){
        //std::cout << soma << std::endl;
        total++;
    }

    // Rodadas que incluam os zeros
    if(estagio_atual < estagio_final - 1){
        total += rebobinar(estagio_final, estagio_atual + 1, soma);
    }    

    // Rodadas que não incuam zero
    soma += std::pow(10, estagio_atual);
    //std::cout << soma << std::endl;
    total++;
    if(estagio_atual < estagio_final - 1){
        total += rebobinar(estagio_final, estagio_atual + 1, soma);
    }
       
    return total;
}