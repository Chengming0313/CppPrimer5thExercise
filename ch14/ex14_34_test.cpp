//
//  ex14_34_test.cpp
//
//  Created by Tang Chengming on 2021/9/4.
//
//  @Brief  
//

class IfThenElse {
public:
    int operator()(bool flag, int a, int b) {
        return flag ? a : b;
    }
};

#include <iostream>

using namespace std;

int main() {
    IfThenElse ifThenElse;
    cout << ifThenElse(true, 1, 2) << " " << ifThenElse(false, 1, 2) << "\n";
}