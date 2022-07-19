#include <iostream>
#include <sstream>
#include "functions.hpp"

int main() {
    Banco *bank;
    
    while(true){
        std::string line, cmd;
        
        getline(std::cin, line);
        
        std::cout << "$" << line << "\n";
        
        std::stringstream ss(line);
        
        ss >> cmd;
        
        if (cmd == "end") {
            break;
        } else if (cmd == "init") {
            int size;
            
            ss >> size;
            
            bank = new Banco(size);

            std::cout << std::endl;
        } else if (cmd == "show") {
            bank->show_all();

            std::cout << std::endl;
        } else if (cmd == "in") {
            std::string name;
            
            int docs, patience;
            
            ss >> name >> docs >> patience;
            
            bank->insere(new Cliente(name, docs, patience));

            std::cout << std::endl;
        } else if (cmd == "tic") {
            bank->passar_tempo();

            std::cout << std::endl;
        } else if (cmd == "finish") {
            while (!bank->vazio())
                bank->passar_tempo();
            
            std::cout << "received: " << bank->get_received() << std::endl;
            
            std::cout << "lost: " << bank->get_lost() << std::endl;
            
            std::cout << "tics: " << bank->get_tics() << std::endl;

            std::cout << std::endl;
        } else {
            std::cout << "fail: command not found\n";

            std::cout << std::endl;
        }
    }
}