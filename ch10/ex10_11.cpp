//
//  ex10_11.cpp
//  cpp primer 5th exercise 10.11
//
//  Created by Tang Chengming on 04/28/2021
//
//  @Brief

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::stable_sort;
using std::string;
using std::vector;

template <typename Sequence>
void print(Sequence seq) {
    for (auto n : seq) {
        cout << "\"" << n << "\""
             << " ";
    }
    cout << endl;
}

bool isShorter(string const &lhs, string const &rhs) {
    return lhs.size() < rhs.size();
}

void elimDups(vector<string> &svec) {
    sort(svec.begin(), svec.end());
    auto endUnique = unique(svec.begin(), svec.end());
    svec.erase(endUnique, svec.end());
}

int main() {
    vector<string> svec{ "aaa", "aaa", "ccc", "ccc", "bbb" };

    elimDups(svec);
    print(svec);
    stable_sort(svec.begin(), svec.end(), isShorter);
    print(svec);

    return 0;
}
