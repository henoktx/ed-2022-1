#pragma once

#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

std::vector<std::string> preenche_vetor() {
    std::string line{};
    int tamanho {};
    
    std::cin >> tamanho;
    std::cin.ignore();

    std::getline(std::cin, line);
    
    std::stringstream ss(line);

    std::vector<std::string> vet(tamanho);

    for (auto &index : vet) {
        ss >> index;
    }

    return vet;
}

std::vector<int> matching_strings(const std::vector<std::string> &entrada, const std::vector<std::string> &consulta) {
    std::vector<int> result;
    
    for (auto &elemento : consulta) {
        auto aux = std::count(entrada.begin(), entrada.end(), elemento);
        result.push_back(aux);
    }

    return result;
}

template <typename T>

std::ostream& operator<<(std::ostream &os, std::vector<T> vet) {
    os << "[ ";
    
    for (auto i : vet) {
        os << i << " ";
    }

    os << "]";

    return os;
}