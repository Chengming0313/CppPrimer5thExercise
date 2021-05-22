//
//  ex10_09.cpp
//  cpp primer 5th exercise 10.9
//
//  Created by Tang Chengming on 04/25/2021
//
//  @Brief

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::sort;
using std::string;
using std::unique;
using std::vector;

template <typename Sequence>
void print(Sequence seq) {
    for (auto n : seq) {
        cout << "\"" << n << "\""
             << " ";
    }
    cout << endl;
}

void elimDups(vector<string> &svec) {
    print(svec);

    sort(svec.begin(), svec.end());
    // unique 之后，重复的元素变成了 ""
    auto endUnique = unique(svec.begin(), svec.end());
    print(svec);

    svec.erase(endUnique, svec.end());
    print(svec);
}

int main() {
    vector<string> svec = { "the", "quick", "over", "quick", "red", "slow", "red", "turtle" };
    elimDups(svec);
    return 0;
}
