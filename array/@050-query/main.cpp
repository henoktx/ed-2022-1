#include <iostream>
#include <sstream>
#include <vector>
#include "functions.hpp"

int main() {
    auto entrada = preenche_vetor();
    auto consulta = preenche_vetor();

    std::cout << std::endl << matching_strings(entrada, consulta) << std::endl;

    return 0;
}