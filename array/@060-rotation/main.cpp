#include <iostream>
#include <vector>
#include <sstream>
#include "functions.hpp"

int main() {
    int tamanho {}, qtdd {};
    std::string line {};

    std::cin >> tamanho >> qtdd;
    std::cin.ignore();

    std::getline(std::cin, line);
    std::stringstream ss(line);

    std::vector<int> vet(tamanho); 
    
    for (auto &elemento : vet) {
        ss >> elemento;
    }

    std::cout << rotaciona(vet, qtdd, tamanho) << std::endl;

    return 0;
}