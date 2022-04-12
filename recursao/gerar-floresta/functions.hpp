#pragma once

#include <iostream>
#include <vector>
#include <stdlib.h>

void criar_floresta(std::vector<std::string> &floresta,int &plantar_arvores) {
    int l_pos = std::rand() % int (floresta.size()); 
    int c_pos = std::rand() % int (floresta[0].size());

    if (plantar_arvores <= 0) {
        return;
    } else if (floresta[l_pos][c_pos] == '#') {
        criar_floresta(floresta, plantar_arvores);
    }

    floresta[l_pos][c_pos] = '#';
    --plantar_arvores;

    criar_floresta(floresta, plantar_arvores);
}

void imprime(std::vector<std::string> &matagal) {
    for(auto percorre : matagal)
        std::cout << percorre << std::endl;
}