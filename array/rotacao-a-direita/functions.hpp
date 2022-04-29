#pragma once 

#include <iostream>
#include <vector>

std::vector<int> rotaciona(std::vector<int> &vet, int qtdd, int tamanho) {
    std::vector<int> aux(tamanho);
    
    for (int index = 0; index < tamanho; index++) {
        int prox_pos = (index + qtdd) % tamanho;
        aux.at(prox_pos) = vet.at(index);
    }

    return aux;
}

std::ostream& operator<<(std::ostream &os, std::vector<int> vet) {
    os << "[ ";
    
    for (auto i : vet) {
        os << i << " ";
    }

    os << "]";

    return os;
}