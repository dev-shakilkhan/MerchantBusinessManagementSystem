#include "Utils.h"

int getInt(const std::string &prompt) {
    int value;
    std::cout << prompt;
    std::cin >> value;
    while(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cout << "Invalid input. " << prompt;
        std::cin >> value;
    }
    return value;
}

double getDouble(const std::string &prompt) {
    double value;
    std::cout << prompt;
    std::cin >> value;
    while(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cout << "Invalid input. " << prompt;
        std::cin >> value;
    }
    return value;
}

std::string getString(const std::string &prompt) {
    std::string value;
    std::cout << prompt;
    std::cin.ignore(); // clear newline left in buffer
    std::getline(std::cin, value);
    return value;
}
