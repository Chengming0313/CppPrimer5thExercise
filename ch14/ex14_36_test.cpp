//
//  ex14_36_test.cpp
//
//  Created by Tang Chengming on 2021/9/4.
//
//  @Brief  
//

#include "ex14_35_GetLine.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> svec;
    GetLine getLine;
    string aux;

    while (true) {
        aux = getLine();
        if (aux.empty()) {
            break;
        }
        svec.push_back(aux);
    }

    cout << "size: " << svec.size() << "\n";
    for (auto const &str : svec) {
        cout << str << "\n";
    }

    return 0;
}