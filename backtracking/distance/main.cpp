#include <iostream>
#include "functions.hpp"

int main() {
    std::string linha {};
    int proximidade {};

    std::cin >> linha >> proximidade;
    std::cin.ignore();

    std::cout << std::endl;
    
    solucao(linha, 0, proximidade);

    return 0;
}