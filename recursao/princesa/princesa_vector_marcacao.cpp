#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int>::iterator buscaProx(std::vector<int> &rodinha, std::vector<int>::iterator espadachim);

std::vector<int>::iterator esfaquear(std::vector<int> &rodinha, std::vector<int>::iterator &espadachim) {
    auto itAux = espadachim;
    while(true) {
      if (espadachim == --rodinha.end()) {
        espadachim = rodinha.begin();
        if (itAux == espadachim) {
          break;
        }
        *espadachim = 0;
        break;
      } else if (*(++espadachim) == 0) {
        continue;
      } else {
        *espadachim = 0;
        break;
      }
    }
  return buscaProx(rodinha, espadachim);
}

std::vector<int>::iterator buscaProx(std::vector<int> &rodinha, std::vector<int>::iterator espadachim) {
  while (true) {
    if (espadachim == --rodinha.end()) {
      espadachim = rodinha.begin();
      continue;
    } else if (*espadachim != 0) {
      return espadachim;
    } else if (*(espadachim + 1) == 0) {
      ++espadachim;
      continue;
    } else {
      return ++espadachim;
    }
  }
}

void imprime(std::vector<int> roda, int espadachim) {
  std::cout << "[ ";
  for (auto i : roda) {
    if (i == 0) {
      continue;
    }
    std::cout << i;
    if (i == espadachim) {
      std::cout << ">";
    }
    std::cout << " ";
  }
  std::cout << " ]" << std::endl;
}

int main() {
  int qtdd_pessoas {}, espadachim {};
  
  std::cin >> qtdd_pessoas >> espadachim;
  std::cin.ignore();
  
  std::vector<int> rodinhaDaMorte {};
  
  for (int preenche = 1; preenche <= qtdd_pessoas; preenche++) {
    rodinhaDaMorte.push_back(preenche);
  }
  
  std::vector<int>::iterator itEspadachim {};
  
  for (auto it = rodinhaDaMorte.begin(); it != rodinhaDaMorte.end(); it++) {
    if (*it == espadachim) {
      itEspadachim = it;
      break;
    }
  }
  
  int contador {1};
  
  while (contador <= qtdd_pessoas) {
    imprime(rodinhaDaMorte, espadachim);
    
    itEspadachim = esfaquear(rodinhaDaMorte, itEspadachim);
    espadachim = *itEspadachim;

    contador++;
  }
}