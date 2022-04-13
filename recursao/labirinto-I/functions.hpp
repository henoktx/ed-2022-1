#pragma once

#include <iostream>
#include <vector>

void imprime(std::vector<std::string> &lab) {
    for(auto percorre : lab) {  
        std::cout << percorre << std::endl;
    }
}

void procura_inicio__fim(std::vector<std::string> &lab, std::pair<int, int> &inicio, std::pair<int, int> &final) {
    for (int l = 0; l < int (lab.size() - 1); l++) {
        for (int c = 0; c < int (lab[0].size() - 1); c++) {
            if (lab[l][c] == 'I') {
                lab[l][c] = '_';
                inicio.first = l;
                inicio.second = c;
            }
            if (lab[l][c] == 'F') {
                lab[l][c] = '_';
                final.first = l;
                final.second = c;
            }
        }
    }
}

bool trilhar_caminho(std::vector<std::string> &lab, int l_pos, int c_pos, std::pair<int, int> &final) {
    int n_lin = lab.size();
    int n_col = lab[0].size();

    if (l_pos >= n_lin || c_pos >= n_col || l_pos < 0 || c_pos < 0) {
        return false;
    } else if (lab[l_pos][c_pos] == '#') {
        return false;
    } else if (lab[l_pos][c_pos] == '.') {
        return false;
    } else if (l_pos == final.first && c_pos == final.second) {
        lab[l_pos][c_pos] = '.';
        return true;
    }

    lab[l_pos][c_pos] = '.';

    if (trilhar_caminho(lab, l_pos, c_pos - 1, final)) {lab[l_pos][c_pos] = '.'; return true;}
    if (trilhar_caminho(lab, l_pos + 1, c_pos, final)) {lab[l_pos][c_pos] = '.'; return true;}
    if (trilhar_caminho(lab, l_pos, c_pos + 1, final)) {lab[l_pos][c_pos] = '.'; return true;}
    if (trilhar_caminho(lab, l_pos - 1, c_pos, final)) {lab[l_pos][c_pos] = '.'; return true;}

    lab[l_pos][c_pos] = '_';
    return false;
}