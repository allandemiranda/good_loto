#include <vector>
#include <iostream>
#include <iterator>

int main(){
    int vetor[10] = {1,2,3,4,5,6,7,8,9,10}; int aaa = 0;

    std::vector <std::vector <int>> novo_vetor;

    for(int i=0; i<2; ++i){
        std::vector <int> temp;
        for(int j=0; j<5; ++j){
            temp.push_back(vetor[aaa]);
            aaa++;
        }
        novo_vetor.push_back(temp);
    }
    
    for(int i=0; i<2; ++i){
        for(int j=0; j<5; ++j){
            std::cout << novo_vetor[i][j] << " ";
        }
         std::cout << std::endl;
    }
    std::cout << std::endl;
}