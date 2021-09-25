//
//  ex14_40_test.cpp
//
//  Created by Tang Chengming on 2021/9/4.
//
//  @Brief  
//

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

void elimDups(vector<string> &words) {
    sort(words.begin(), words.end());
    auto endUnique = unique(words.begin(), words.end());
    words.erase(endUnique, words.end());
}

string make_plural(size_t ctr, string const& word, string const& ending)
{
    return (ctr > 1) ? word + ending : word;
}

class CompareString {
public:
    bool operator()(string const &lhs, string const &rhs) {
        return lhs.size() < rhs.size();
    }
};

class LongerThanN {
public:
    explicit LongerThanN(int sz) : sz(sz) {}
    bool operator()(string const &str) const {
        return str.size() >= sz;
    }
    int sz;
};

void biggies(vector<string> &words, vector<string>::size_type sz) {
    elimDups(words);
    stable_sort(words.begin(), words.end(), CompareString());
    auto wc = find_if(words.begin(), words.end(), LongerThanN(sz));
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "words", "s")
         << " of length " << sz << " or longer" << endl;
}

int main()
{
    vector<string> vec{ "fox", "jumps", "over", "quick", "red", "red", "slow", "the", "turtle" };
    biggies(vec, 4);
}