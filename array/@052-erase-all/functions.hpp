#pragma once 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

std::ostream& operator<<(std::ostream &os, std::vector<int> vet) {
    os << "[ ";
    
    for (auto i : vet) {
        os << i << " ";
    }

    os << "]";

    return os;
}

std::stringstream inicializa(std::string &line) {
    std::getline(std::cin, line);
    std::stringstream fluxo(line);

    return fluxo;
}

void preenche(std::vector<int> &fila, std::stringstream fluxo) {
    for (auto &elemento : fila) {
        int aux = 0;

        fluxo >> aux;

        if (std::count(fila.begin(), fila.end(), aux) > 0) {
            std::cout << "Erro → identificação repetida [" << aux << "]" << std::endl;

            return;
        }

        elemento = aux;
    }
}

void ajeitar_fila(std::vector<int> &fila, std::vector<int> &deixaram_fila) {
    for (auto &elemento : deixaram_fila) {
        auto it = std::find(fila.begin(), fila.end(), elemento);
        
        fila.erase(it);        
    }
}
