#pragma once

#include <iostream>
#include <vector>

void incendiar(std::vector<std::string> &matagal, int l_pos, int c_pos) {
    int n_linhas = matagal.size();
    int n_colunas = matagal[0].size();

    if (l_pos >= n_linhas || c_pos >= n_colunas || l_pos < 0 || c_pos < 0) {
        return;
    } else if (matagal[l_pos][c_pos] != '#') {
        return;
    }

    matagal[l_pos][c_pos] = 'o';

    incendiar(matagal, l_pos - 1, c_pos);
    incendiar(matagal, l_pos + 1, c_pos);
    incendiar(matagal, l_pos, c_pos - 1);
    incendiar(matagal, l_pos, c_pos + 1);
}

void imprime(std::vector<std::string> &matagal) {
    for(auto percorre : matagal)
        std::cout << percorre << std::endl;
}