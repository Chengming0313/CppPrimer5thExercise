//
//  ex09_49.cpp
//  cpp primer 5th exercise 9.49
//
//  Created by aozy on 04/17/2021
//
//  @Brief  A letter has an ascender if, as with d or f, part of the letter extends
//          above the middle of the line.
//          A letter has a descender if, as with p or g, part of the letter extends below the line.
//          Write a program that reads a file containing words and reports the longest word
//          that contains neither ascenders nor descenders.

#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream in("CPP_Primer\\ch09\\data\\09_49.in");

    if (in) {
        std::string alphabet{ "aceimnorsuvwxz" };
        std::string longestWord;

        auto updateLongest = [&longestWord, alphabet](std::string const &str) {
            if (str.find_first_not_of(alphabet) == std::string::npos) {
                if (str.size() > longestWord.size()) {
                    longestWord = str;
                }
            }
        };

        std::string str;
        while (in >> str) {
            updateLongest(str);
        }

        std::cout << "longest word: " << longestWord << std::endl;
    }
    else {
        std::cerr << "Not data!\n";
    }

    return 0;
}
