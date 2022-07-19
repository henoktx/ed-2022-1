#include <iostream>
#include <sstream>
#include <vector>
#include "functions.hpp"

int main() {
    std::string line{};
    std::getline(std::cin, line);
    std::stringstream ss(line);

    std::vector<int> vetor{};
    int elemento{};

    while (ss >> elemento) {
        vetor.push_back(elemento);
    }

    std::cout << "=========" << std::endl;

    triangulo_soma(vetor);
}