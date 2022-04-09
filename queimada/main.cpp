#include <iostream>
#include <vector>

void imprime(std::vector<std::string> &matagal);

void incendiar(std::vector<std::string> &matagal, int l_pos, int c_pos);

int main() {
    int n_linhas, n_colunas, l_fogo, c_fogo;

    std::cin >> n_linhas >> n_colunas >> l_fogo >> c_fogo;
    std::cin.ignore();

    std::vector<std::string> floresta (n_linhas);

    for (auto aux = 0; aux < n_linhas; aux++) {
        std::cin >> floresta[aux];
    }

    incendiar(floresta, l_fogo, c_fogo);

    std::cout << "=======" << std::endl;

    imprime(floresta);
}

void incendiar(std::vector<std::string> &matagal, int l_pos, int c_pos) {
    int n_linhas = matagal.size();
    int n_colunas = matagal[0].size();

    if (l_pos >= n_linhas || c_pos >= n_colunas || l_pos < 0 || c_pos < 0) {
        return;
    } else if (matagal[l_pos][c_pos] != '#') {
        return;
    }

    matagal[l_pos][c_pos] = 'o';

    incendiar(matagal, l_pos - 1, c_pos);
    incendiar(matagal, l_pos + 1, c_pos);
    incendiar(matagal, l_pos, c_pos - 1);
    incendiar(matagal, l_pos, c_pos + 1);
}

void imprime(std::vector<std::string> &matagal) {
    for(auto percorre : matagal)
        std::cout << percorre << std::endl;
}