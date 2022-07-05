#include <iostream>
#include <sstream>
#include "functions.hpp"

int main(){
    std::string line, cmd;
    
    int value;
    
    Vector * v = vector_create(0);

    while(true){
        std::getline(std::cin, line);

        std::cout << "$" << line << std::endl;
        
        std::stringstream ss(line);
        
        ss >> cmd;
        
        if (cmd == "end") {
            break;
        } else if (cmd == "init") {
            ss >> value;
        
            if (v != nullptr)
                vector_destroy(v);
        
            v = vector_create(value);
        } else if (cmd == "status") {
            std::cout << "size:" << v->size << " capacity:" << v->capacity << "\n";
        } else if(cmd == "add") {
            while(ss >> value)
                vector_add(v, value);
        } else if(cmd == "show") {
            std::cout << vector_show(v) << std::endl;
        } else {
            std::cout << "fail: comando invalido\n";
        }
    }
    
    vector_destroy(v);
}