// MerchantBusinessManagementSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main() {
#ifdef __cplusplus
    // Using __cplusplus macro to check C++ version
    if (__cplusplus == 199711L)
        std::cout << "C++98 or C++03" << std::endl;
    else if (__cplusplus == 201103L)
        std::cout << "C++11" << std::endl;
    else if (__cplusplus == 201402L)
        std::cout << "C++14" << std::endl;
    else if (__cplusplus == 201703L)
        std::cout << "C++17" << std::endl;
    else if (__cplusplus == 202002L)
        std::cout << "C++20" << std::endl;
    else if (__cplusplus > 202002L)
        std::cout << "C++23 or newer" << std::endl;
    else
        std::cout << "Unknown C++ version: " << __cplusplus << std::endl;
#else
    std::cout << "Not a C++ compiler" << std::endl;
#endif

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
