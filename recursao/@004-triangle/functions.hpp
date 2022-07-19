#pragma once

#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v);

std::vector<int> soma(std::vector<int> &vet, std::vector<int> somado, int pos = 0) {  
    if (pos == int (vet.size() - 1)) {
        return somado;
    }
    somado.push_back(vet.at(pos) + (vet.at(pos + 1)));
    return soma(vet, somado, pos + 1);
}

void triangulo_soma(std::vector<int> &vet) {
    if (vet.size() == 0) {
        return;
    }
    std::vector<int> result {soma(vet, {})};
    triangulo_soma(result);
    std::cout << vet << std::endl;
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
    os << "[ ";
    for (auto i : v)
        os << i << " ";
    os << "]";
    
    return os;
}