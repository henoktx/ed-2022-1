#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "functions.hpp"

int main() {
    std::srand(time(NULL));

    int linhas{}, colunas{};
    float percent{};

    std::cin >> linhas >> colunas >> percent;
    std::cin.ignore();

    percent /= 100;
    int plantar_arvores = linhas * colunas * percent;

    std::vector<std::string> amazonia (linhas, std::string(colunas, 'o'));

    criar_floresta(amazonia, plantar_arvores);
    imprime(amazonia);
}