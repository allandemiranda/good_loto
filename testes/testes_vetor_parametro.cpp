#include <iterator>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

void teste(std::vector <std::vector <int>> vet){
    for(int i(0); i<vet.size(); ++i){
        for(int j(0); j<vet[i].size(); ++j)
        std::cout << vet[i][j] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    std::vector <std::vector <int>> vetor = {{1,2,3},{4,5},{6},{7,8,9}};
    teste(vetor);
    return 0;
}
