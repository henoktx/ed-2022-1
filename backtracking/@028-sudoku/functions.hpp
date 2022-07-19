#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <cmath>

void imprime(const std::vector<std::vector<int>> &vet) {
    for (auto& linha : vet) {
        std::cout << "[ ";
        
        for (auto& elemento : linha) {
            std::cout << elemento << " ";
        }
        
        std::cout << "]" << std::endl;
    }
}

bool pos_valida(int l, int c, int tam) {  
    if (l >= 0 && c >= 0 && l < tam && c < tam) {
        return true;
    }

    return false;
}

bool num_valido_lin_col(const std::vector<std::vector<int>> &tabuleiro, int l, int c) {
    int tam = tabuleiro.size();
    int valor = tabuleiro[l][c];  

    for (int index = 0; index < tam; index++) {
        if (index != l && index != c && (tabuleiro[index][c] == valor || tabuleiro[l][index] == valor)) {
            return false;
        }
    }

    return true;
}

bool num_valido_quadrante(const std::vector<std::vector<int>> &tabuleiro, int l, int c) {
    int tam = tabuleiro.size();
    int valor = tabuleiro[l][c];
    
    int tam_quadrante = std::sqrt(tam);
    int inicio_l = l - (l % tam_quadrante);
    int inicio_c = c - (c % tam_quadrante);

    for (int i = inicio_l; i < inicio_l + tam_quadrante; i++) {
        for (int j = inicio_c; j < inicio_c + tam_quadrante; j++) {
            if (i != l && j != c && tabuleiro[i][j] == valor) {
                return false;
            }
        }
    }

    return true;
}

std::pair<int, int> prox_pos(int l, int c, int tam) {
    if (c == tam - 1) {
        return {l + 1, 0};
    }
    
    return {l, c + 1};
}

bool resolve_sudoku(std::vector<std::vector<int>> &tabuleiro, int l, int c) {
    static std::vector<int> valores = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    int tam = tabuleiro.size();

    if (l == tam || c == tam) {
        return true;
    } else if (!pos_valida(l, c, tam)) {
        return false;
    }
    
    std::random_shuffle(valores.begin(), valores.end());

    for (auto escolha : valores) {
        tabuleiro[l][c] = escolha;
        
        if (!num_valido_lin_col(tabuleiro, l, c) || !num_valido_quadrante(tabuleiro, l, c)) {
            tabuleiro[l][c] = 0;
            continue;
        }
        
        auto [prox_l, prox_c] = prox_pos(l, c, tam);

        if (resolve_sudoku(tabuleiro, prox_l, prox_c)) {
            return true;
        }
    }

    return false;
}

std::vector<std::vector<int>> sudoku(int tam) {
    std::vector<std::vector<int>> resposta(tam, std::vector<int>(tam, 0));

    resolve_sudoku(resposta, 0, 0);

    return resposta;
}