//
//  ex14_35_test.cpp
//
//  Created by Tang Chengming on 2021/9/4.
//
//  @Brief  
//

#include "ex14_35_GetLine.h"

#include <iostream>

using namespace std;

int main() {
    GetLine getLine;
    string ans = getLine();
    std::cout << "size: " << ans.size() << "\n" << ans << "\n";
    return 0;
}