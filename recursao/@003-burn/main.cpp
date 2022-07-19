#include <iostream>
#include <vector>
#include "functions.hpp"

int main() {
    int n_linhas, n_colunas, l_fogo, c_fogo;

    std::cin >> n_linhas >> n_colunas >> l_fogo >> c_fogo;
    std::cin.ignore();

    std::vector<std::string> floresta (n_linhas);

    for (auto aux = 0; aux < n_linhas; aux++) {
        std::cin >> floresta[aux];
    }

    incendiar(floresta, l_fogo, c_fogo);

    std::cout << "=======" << std::endl;

    imprime(floresta);
}