#include <iostream>
#include <sstream>
#include "functions.hpp"

int main() {
    std::string line{}, cmd{};

    int valor{};

    Vector<int> vet(0);

    while (true) {
        std::getline(std::cin, line);

        std::cout << "$" << line << std::endl << std::endl;

        std::stringstream fluxo(line);

        fluxo >> cmd;

        if (cmd == "end") {
            break;
        } else if (cmd == "init") {
            fluxo >> valor;
            vet = Vector<int>(valor);
        } else if (cmd == "status") {
            std::cout << "size → " << vet.get_size() << " | capacity → " << vet.get_capacity() << std::endl << std::endl;
        } else if (cmd == "add") {
            while (fluxo >> valor) {
                vet.push_back(valor);
            }
        } else if (cmd == "show") {
            std::cout << vet << std::endl << std::endl;
        } else if (cmd == "pop_back") {
            vet.pop_back();
        } else {
            std::cout << "error → invalid command" << std::endl << std::endl;
        }
    }

    return 0;
}