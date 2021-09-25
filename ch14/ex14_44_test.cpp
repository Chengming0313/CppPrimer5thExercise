//
//  ex14_44_test.cpp
//
//  Created by Tang Chengming on 2021/9/5.
//
//  @Brief  
//

#include <unordered_map>
#include <functional>
#include <iostream>

int add (int a, int b) {return a + b;}

auto minus = [](int a, int b) {return a - b;};

struct Divide {
    int operator()(int a, int b) const {
        return a / b;
    }
};

std::unordered_map<std::string, std::function<int(int, int)>> calculator = {
        {"+", add},     // function pointer
        {"-", minus},   // named lambda object
        {"*", [](int a, int b) {return a * b;}}, // unnamed lambda
        {"/", Divide{}} // function object
};

int main() {
    int a = 0, b = 0;
    std::string op{};
    std::cout << "please enter as: num operator num\n";
    while (std::cin >> a >> op >> b) {
        std::cout << "answer is " << calculator[op](a, b) << "\n";
        std::cout << "please enter as: num operator num\n";
    }
    return 0;
}