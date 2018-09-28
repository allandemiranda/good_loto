#include <iostream>
#include <cstdlib>
#include <ctime> // temporário so para medir tempo
std::time_t result_um;
std::time_t result_dois;

#include <omp.h>

int main(int argc, char const *argv[])
{
    std::srand(std::time(nullptr));    
    int A[1000000];
    int vezes = atoi(argv[1]);
    int tamamnho = std::distance(std::begin(A),std::end(A));
    for(int i(0); i<tamamnho; ++i){
        int random_variable = 1 + std::rand()/((RAND_MAX + 1u)/2);
        A[i] = random_variable;
    }

    result_um = std::time(nullptr);
    long long contador_normal(0);
    for(int j(0); j<vezes; ++j){
        for(int i(0); i<tamamnho; ++i){
            if(A[i]%2==0){
                ++contador_normal;
            }
        }
    }
    result_dois = std::time(nullptr);
    std::cout << "Normal inicial " << std::asctime(std::localtime(&result_um)) << std::endl;
    std::cout << "Normal final " << std::asctime(std::localtime(&result_dois)) << std::endl;
    std::cout << "Valor para normal " << contador_normal << std::endl;

    std::cout << std::endl;

    result_um = std::time(nullptr);
    long long contador_p(0);
    long long cont_a(0); long long cont_b(0); long long cont_c(0); long long cont_d(0);
    #pragma omp parallel
    {
        for(int j(0); j<vezes; ++j){
            #pragma omp sections  
            {                
                #pragma omp section
                {
                    for(int i(((tamamnho/4)*0)); i<((tamamnho/4)*1); ++i){
                        if(A[i]%2==0){
                            ++cont_a;
                        }
                    }
                }
                #pragma omp section
                {
                    for(int i(((tamamnho/4)*1)); i<((tamamnho/4)*2); ++i){
                        if(A[i]%2==0){
                            ++cont_b;
                        }
                    }
                }
                #pragma omp section
                {
                    for(int i(((tamamnho/4)*2)); i<((tamamnho/4)*3); ++i){
                        if(A[i]%2==0){
                            ++cont_c;
                        }
                    }
                }
                #pragma omp section
                {
                    for(int i(((tamamnho/4)*3)); i<((tamamnho/4)*4); ++i){
                        if(A[i]%2==0){
                            ++cont_d;
                        }
                    }
                }                
            }
        }
    }
    contador_p = cont_a + cont_b + cont_c + cont_d;
    result_dois = std::time(nullptr);
    std::cout << "Normal inicial " << std::asctime(std::localtime(&result_um)) << std::endl;
    std::cout << "Normal final " << std::asctime(std::localtime(&result_dois)) << std::endl;
    std::cout << "Valor para normal " << contador_p << std::endl;

    return 0;
}
