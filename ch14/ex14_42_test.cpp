//
//  ex14_42_test.cpp
//
//  Created by Tang Chengming on 2021/9/5.
//
//  @Brief  
//

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

class Greater {
public:
    int data;
    explicit Greater(int data) : data(data) {
    }
    bool operator()(int x) const {
        return x > data;
    }
};

class NotEqualTo {
public:
    string data;
    explicit NotEqualTo(string data) :data (std::move(data)) {
    }
    bool operator()(string const &str) const {
        return str != data;
    }
};

class Multiplies {
public:
    int b;
    explicit Multiplies(int b) : b(b) {}
    void operator()(int &x) const {
        x *= b;
    }
};

int main() {
    vector<int> avec{1, 2, 3, 4, 1023, 1024, 1025};
    cout << count_if(avec.cbegin(), avec.cend(), Greater{1024});
    cout << "\n";

    vector<string> bvec{"pooth", "abc", "pooth"};
    cout << *find_if(bvec.cbegin(), bvec.cend(), NotEqualTo{"pooth"});
    cout << "\n";

    vector<int> cvec{1, 2, 3, 4, 5};
    for_each(cvec.begin(), cvec.end(), Multiplies{2});
    for (auto num : cvec) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}