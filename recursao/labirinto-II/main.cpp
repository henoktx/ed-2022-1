#include <iostream>
#include <vector>
#include "functions.hpp"

int main(int argc, char * argv[]) {
    std::srand(std::time(NULL));

    int n_linhas {}, n_colunas{};

    if (argc > 2) {
        n_linhas = std::atoi(argv[1]);
        n_colunas = std::atoi(argv[2]);
    }

    std::vector<std::string> labirinto(n_linhas, std::string(n_colunas, '#'));

    auto inicio = decide_inicio(labirinto);

    derrubar_parede(labirinto, inicio);
    imprime(labirinto);

    return 0;
}