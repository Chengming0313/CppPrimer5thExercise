//
//  ex09_47_2.cpp
//
//  Created by aozy on 04/16/2021
//
//  @Brief  Write a program that finds each numeric character
//          and then each alphabetic character in the string "ab2c3d7R4E6".
//          Write two versions of the program. The first should use find_first_of,
//          and the second find_first_not_of.
//
//  @Version find_first_not_of

#include <iostream>
#include <string>

int main() {
    std::string numbers{ "0123456789" };
    std::string alphabet{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };

    std::string str{ "ab2c3d7R4E6" };

    std::cout << "numbers: ";
    for (std::string::size_type pos = 0;
         (pos = str.find_first_not_of(alphabet, pos)) != std::string::npos; ++pos) {
        std::cout << str[pos] << " ";
    }
    std::cout << "\n";

    std::cout << "alphas: ";
    for (std::string::size_type pos = 0;
         (pos = str.find_first_not_of(numbers, pos)) != std::string::npos; ++pos) {
        std::cout << str[pos] << " ";
    }

    return 0;
}
