#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <cmath>
#include "functions.hpp"

int main() {
    std::srand(std::time(0));

    auto resolucao = sudoku(4);

    imprime(resolucao);
}