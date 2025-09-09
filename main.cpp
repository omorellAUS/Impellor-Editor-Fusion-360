#include <iostream>
#include <string>

int main() {
    std::string name;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    std::cout << "Welcome, " << name << "! Impellor V2 is ready." << std::endl;
    return 0;
}
