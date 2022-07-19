#pragma once

#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) 
{
    os << "[ ";
    for (auto i : v)
        os << i << " ";
    os << "]";
    
    return os;
}

void vet(const std::vector<int> &vetor, int pos) {
    if (vetor.size() == 1) {
        std::cout << "vet : [ " << vetor[pos] << " ]" << std::endl;
        return;
    }
    
    if (pos == int (vetor.size() - 1)) {
        std::cout << vetor[pos] << " ]" << std::endl;
        return;
    } else if (pos == 0) {
        std::cout << "vet : [ ";
    }

    std::cout << vetor[pos] << " ";
    pos++;

    vet(vetor, pos);
}

void rvet(const std::vector<int> &vetor, int pos) {
    if (vetor.size() == 1) {
        std::cout << "rvet : [ " << vetor[pos] << " ]" << std::endl;
        return;
    }
    
    if (pos == 0) {
        std::cout << vetor[pos] << " ]" << std::endl;
        return;
    } else if (pos == int (vetor.size() - 1)) {
        std::cout << "rvet : [ ";
    }

    std::cout << vetor[pos] << " ";
    pos--;

    rvet(vetor, pos);
}

int soma(const std::vector<int> &vetor, int pos) {
    if (pos == int (vetor.size() - 1)) {
        return vetor[pos];
    }
    return vetor[pos] + soma(vetor, pos + 1);
}

long int mult(const std::vector<int> &vetor, int pos) {
    if (pos == int (vetor.size() - 1)) {
        return vetor[pos];
    }
    return vetor[pos] * mult(vetor, pos + 1);
}

int min(const std::vector<int> &vetor, int pos) {
    if (pos == int (vetor.size() - 1)) {
        return vetor[pos];
    }
    auto aux = min(vetor, pos + 1);
    return aux < vetor[pos] ? aux : vetor[pos];
}

void inv(std::vector<int> &vetor, int pos_inicial, int pos_final) {
    if (int (vetor.size() - 1) / 2 == pos_final) {
        return;
    }

    std::swap(vetor[pos_inicial], vetor[pos_final]);

    pos_final--;
    pos_inicial++;

    inv(vetor, pos_inicial, pos_final);
}