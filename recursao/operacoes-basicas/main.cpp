#include <iostream>
#include <sstream>
#include <vector>
#include "functions.hpp"

int main() {
    std::string line{};
    std::getline(std::cin, line);
    std::stringstream ss(line);
    
    std::vector<int> vetor{};
    int valor{};

    while (ss >> valor) {
        vetor.push_back(valor);
    }

    std::cout << "==============" << std::endl;

    vet(vetor, 0);

    rvet(vetor, int (vetor.size() - 1));

    std::cout << "soma : " << soma(vetor, 0) << std::endl;

    std::cout << "mult : " << mult(vetor, 0) << std::endl;

    std::cout << "min : " << min(vetor, 0) << std::endl;

    inv(vetor, 0, (vetor.size() - 1));

    std::cout << "inv : " << vetor << std::endl;
}