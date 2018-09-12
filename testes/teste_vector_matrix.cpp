#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <cmath>
#include "../analise/numeros_sorteados.h"

int main(void){
    
    std::vector < std::vector <int> > a = {{1,2},{3,4,5},{6}};

    int cont(0);
/*
    for(int i(0); i<6; ++i){
        std::vector <int> temp;
        for(int j(0); j<3; ++j){
            temp.push_back(cont);
            cont++;
        }
        a.push_back(temp);
    }
*/
    for(int i(0); i<a.size(); ++i){
        for(int j(0); j<a[i].size(); ++j){
            std::cout << a[i][j] << " ";
        }
    }
    std::cout << std::endl;




    return 0;
}