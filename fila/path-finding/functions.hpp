#pragma once

#include <iostream>
#include <vector>
#include <queue>

void imprime(std::vector<std::string> &matriz) {
    std::cout << "=======\n";

    for(auto percorre : matriz)
        std::cout << percorre << std::endl;
}

struct Pos{
    int l, c;

    Pos(int l, int c) : l(l), c(c) {}

    bool operator==(Pos x) {
        if (x.l == this->l && x.c == this->c) {
            return true;
        }
        return false;
    }
};

void procura_inicio_fim(std::vector<std::string> &lab, Pos &inicio, Pos &final) {
    for (int l = 0; l < int (lab.size() - 1); l++) {
        for (int c = 0; c < int (lab[0].size() - 1); c++) {
            if (lab[l][c] == 'I') {
                lab[l][c] = ' ';
                inicio.l = l;
                inicio.c = c;
            }
            if (lab[l][c] == 'F') {
                lab[l][c] = ' ';
                final.l = l;
                final.c = c;
            }
        }
    }
}

std::vector<Pos> vizinhos(Pos p) {
    auto [l,c] = p;

    return {{l, c - 1}, {l - 1, c}, {l, c + 1}, {l + 1, c}};
}

void achar_caminho(std::vector<std::string> &lab, std::vector<std::vector<int>> &distance, Pos &inicio, Pos &final);

void procurar_saida(std::vector<std::string> &lab, std::vector<std::vector<int>> &distance, Pos &inicio, Pos &final) {
    bool achou {false};
    
    int nl = lab.size();
    int nc = lab[0].size();

    std::queue<Pos> fila {};

    fila.push(inicio);

    distance[inicio.l][inicio.c] = 0;

    while(!achou) {
        Pos pos_atual = fila.front();
        
        for (auto element : vizinhos(pos_atual)) {
            if (element.l < 0 || element.c < 0 || element.l >= nl || element.c >= nc) {
                continue;
            } else if (lab[element.l][element.c] == ' ' && distance[element.l][element.c] == -1) {
               
                distance[element.l][element.c] = distance[pos_atual.l][pos_atual.c] + 1;
            
                fila.push(element);

                if (element == final) {
                    achou = true;
                }            
            }
        }
        
        fila.pop(); 
    }

    achar_caminho(lab, distance, inicio, final);
    
    imprime(lab);
}

void achar_caminho(std::vector<std::string> &lab, std::vector<std::vector<int>> &distance, Pos &inicio, Pos &final) {
    bool achou {false};

    Pos pos_atual = final;

    while (!achou) {
        for (auto element : vizinhos(pos_atual)) {
            if (distance[element.l][element.c] == distance[pos_atual.l][pos_atual.c] - 1) {
                lab[pos_atual.l][pos_atual.c] = '.';
                
                pos_atual = element;
                
                if (element == inicio) {
                    achou = true;
                }
            }
        }
    }
}