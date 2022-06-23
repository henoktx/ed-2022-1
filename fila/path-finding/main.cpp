#include <iostream>
#include <vector>
#include <queue>
#include "functions.hpp"

int main() {
    int nl, nc;

    std::cin >> nl >> nc;
    std::cin.ignore();

    std::vector<std::string> lab(nl);

    std::vector<std::vector<int>> distance(nl, std::vector<int>(nc, -1));
    
    for (int linha = 0; linha < nl; linha++) {
        std::getline(std::cin, lab[linha]);
    }
    
    Pos inicio(0, 0), final(0, 0);

    procura_inicio_fim(lab, inicio, final);

    procurar_saida(lab, distance, inicio, final);

    return 0;
}