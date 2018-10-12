#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <vector>
#include <omp.h> // sistemas paralelos -fopenmp

int main(int argc, char const *argv[])
{
    std::vector <int> jogos_possiveis;
	//std::ifstream ifs("../../src/jogos_certos.txt");
    std::ifstream ifs("jogos_certos_1718.txt");
	int val;
    std::cout << "Criando vetor com jogos" << std::endl;
	while (ifs >> val) {
		jogos_possiveis.push_back(val);
	}
	ifs.close();
    std::cout << "Vetor com jogos criado" << std::endl;

    std::ofstream outFile ("novos_jogos_certos.txt", std::ios::app); 
    int contar_jogos_possiveis(0);

    int acompanhamento_now(0);
    std::cout << acompanhamento_now << "%" << std::endl;
    for(int i(0); i<jogos_possiveis.size(); i+=15){


        if(((i*100)/jogos_possiveis.size())!=acompanhamento_now){
            acompanhamento_now = ((i*100)/jogos_possiveis.size());
            std::cout << acompanhamento_now << "% -> jogos possiveis " << contar_jogos_possiveis << std::endl;
        }     


        int pontos_14 = 0;
        #pragma omp parallel for reduction(+:pontos_14)   
        for(int j=0; j<jogos_possiveis.size(); j+=15){
            int pontos=0;
            for(int k(0); k<15; ++k){
                if(std::binary_search((jogos_possiveis.begin()+i), (jogos_possiveis.begin()+(i+15)), *(jogos_possiveis.begin()+j+k))){                    
                    ++pontos;
                }
                if((k>=1) and (pontos<k)){
                    break;
                }
            }
            if(pontos>=14){
                pontos_14 += 1;
            }
        }        
        if(pontos_14 >= 100){
            for(int gravar(0); gravar < 14; ++gravar){
                outFile << *(jogos_possiveis.begin()+i+gravar) << " ";
            }
            outFile << *(jogos_possiveis.begin()+i+14) << std::endl;  
            contar_jogos_possiveis+=1;
        }
    }    
    outFile.close();
    std::cout << "Jogos possiveis totais: " << contar_jogos_possiveis << std::endl;
    return 0;
}
