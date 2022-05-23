#include <iostream>
#include <vector>
#include "functions.hpp"

int main() {
    int n_lin {}, n_col {}; 
    auto inicio = std::make_pair(0,0);
    auto final = std::make_pair(0,0);

    std::cin >> n_lin >> n_col;
    std::cin.ignore();

    std::vector<std::string> labirinto(n_lin);

    for (int count_lin = 0; count_lin < n_lin; count_lin++) {
        std::cin >> labirinto[count_lin];
    }

    procura_inicio__fim(labirinto, inicio, final);
    trilhar_caminho(labirinto, inicio.first, inicio.second, final);

    imprime(labirinto);
}