#include <iostream>
#include <vector>

std::vector<int>::iterator esfaquear(std::vector<int> &rodinha, std::vector<int>::iterator &espadachim) {
    if (++espadachim == rodinha.end()) {
        espadachim = rodinha.begin();
    }
    
    espadachim = rodinha.erase(espadachim);

    if (espadachim == rodinha.end()) {
        if (rodinha.size() != 0) {
            espadachim = rodinha.begin();
        }
    }

    return espadachim;
}

void imprime(std::vector<int> &rodinha, int espadachim) {
    std::cout << "[ ";
    
    for (auto aux : rodinha) {
        std::cout << aux;
        if (aux == espadachim) {
            std::cout << ">";
        }
        std::cout << " ";
    } 

    std::cout << "]" << std::endl;
}

int main() {
    int qtddPessoas {}, espadachim{};

    std::cin >> qtddPessoas >> espadachim;
    std::cin.ignore();
    
    std::vector<int> rodinhaDaMorte {};

    for (int preenche = 1; preenche <= qtddPessoas; preenche++) {
        rodinhaDaMorte.push_back(preenche);
    }

    std::vector<int>::iterator itEspadachim;

    for (auto it = rodinhaDaMorte.begin(); it != rodinhaDaMorte.end(); it++) {
        if (*it == espadachim) {
            itEspadachim = it;
            break;
        }
    }

    int contador {1};

    while (contador <= qtddPessoas) {
        imprime(rodinhaDaMorte, espadachim);
        
        itEspadachim = (esfaquear(rodinhaDaMorte, itEspadachim));
        espadachim = *itEspadachim;

        contador++;
    }
}