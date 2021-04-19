//
//  ex09_52.cpp
//  cpp primer 5th exercise 9.52
//
//  Created by Tang Chengming on 04/17/2021
//
//  @Brief  Use a stack to process parenthesized expressions.
//          When you see an open parenthesis, note that it was seen.
//          When you see a close parenthesis after an open parenthesis,
//          pop elements down to and including the open parenthesis off the stack.
//          push a value onto the stack to indicate that a parenthesized expression was replaced.

#include <iostream>
#include <stack>
#include <string>

int main() {
    std::string      expr{ "This is (Tang Chengming) !" };
    std::stack<char> stk;

    bool inParenthesis = false;
    for (auto ch : expr) {
        if (ch == '(') {
            inParenthesis = true;
            continue;
        }
        else if (ch == ')') {
            inParenthesis = false;
        }
        if (inParenthesis) stk.push(ch);
    }

    std::string res;
    while (!stk.empty()) {
        res.push_back(stk.top());
        stk.pop();
    }

    std::cout << std::string(res.crbegin(), res.crend()) << std::endl;

    return 0;
}
