#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

struct Posicao {
    int linha, coluna;

    Posicao(int linha, int coluna) : linha(linha), coluna(coluna) {}
};

bool pos_eh_valida(std::vector<std::string> &lab, Posicao pos) {
    int nl = lab.size();
    int nc = lab[0].size();
    auto [l, c] = pos;
    
    if (l >= nl - 1 || c >= nc - 1 || l < 1 || c < 1) {
        return false;
    }

    return true;
}

std::vector<Posicao> pegar_vizinhos(const Posicao &pos) {
    auto [l_pos, c_pos] = pos;

    return {{l_pos, c_pos - 1}, {l_pos + 1, c_pos}, {l_pos, c_pos + 1}, {l_pos - 1, c_pos}};
}

bool pode_furar(std::vector<std::string> &lab, Posicao &pos) {
    int count = 0;
    auto aux = pegar_vizinhos(pos);

    if (lab[pos.linha][pos.coluna] == ' ') {
        return false;
    }

    for (auto [l, c] : aux) {
        if (l >= int (lab.size()) || c >= int (lab[0].size()) || l < 0 || c < 0) {
            continue;
        }

        if (lab[l][c] == '#') {
            count++;
        }
    }

    if (count >= 3) {
        return true;
    }

    return false;
}

void derrubar_parede(std::vector<std::string> &lab, Posicao &pos) {
    auto [l, c] = pos;
    
    if (!pos_eh_valida(lab, pos)) {
        return;
    }
    
    if (pode_furar(lab, pos)) {
        lab[l][c] = ' ';
        auto vizinhos = pegar_vizinhos(pos);
        std::random_shuffle(vizinhos.begin(), vizinhos.end());

        for (auto vizinho : vizinhos) {
            derrubar_parede(lab, vizinho);
        }
    } 
}

Posicao decide_inicio(std::vector<std::string> &lab) {
    int l_pos = std::rand() % (lab.size() - 2) + 1; 
    int c_pos = std::rand() % (lab[0].size() - 2) + 1;

    return {l_pos, c_pos};
}

void imprime(std::vector<std::string> &mat) {
    for(auto percorre : mat)
        std::cout << percorre << std::endl;
}