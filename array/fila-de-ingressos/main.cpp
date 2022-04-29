#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include "functions.hpp"

int main() {
    int qtdd_pessoas {}, sairam_da_fila {};
    std::string line {}, line2 {}; 

    std::cin >> qtdd_pessoas;
    std::cin.ignore();

    std::vector<int> fila (qtdd_pessoas);

    preenche(fila, inicializa(line));

    std::cin >> sairam_da_fila;
    std::cin.ignore();

    std::vector<int> deixaram_fila (sairam_da_fila);

    preenche(deixaram_fila, inicializa(line2));

    ajeitar_fila(fila, deixaram_fila);

    std::cout << fila << std::endl;

    return 0;
}