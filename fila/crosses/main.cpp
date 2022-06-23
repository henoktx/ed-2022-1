#include <iostream>
#include <queue>

int main() {
    std::queue<char> copa_mundo ({'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'});

    int gols_time1, gols_time2;
    
    while (copa_mundo.size() != 1) {
        std::cin >> gols_time1 >> gols_time2;

        char time1 = copa_mundo.front();
        copa_mundo.pop();

        char time2 = copa_mundo.front();
        copa_mundo.pop();
        
        if (gols_time1 > gols_time2) {
            copa_mundo.push(time1);
        } else {
            copa_mundo.push(time2);
        }
    }

    std::cout << "====\n" << copa_mundo.front() << std::endl;
}