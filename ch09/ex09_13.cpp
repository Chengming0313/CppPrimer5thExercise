#include <iostream>
#include <list>
#include <vector>

int main() {
    std::list<int>      lst{ 1, 2, 3, 4 };
    std::vector<double> v1(lst.cbegin(), lst.cend());

    for (double d : v1)
        std::cout << d << " ";
    std::cout << '\n';

    std::vector<int>    v2{ 6, 7, 8, 9 };
    std::vector<double> v3(v2.cbegin(), v2.cend());
    for (double d : v3)
        std::cout << d << " ";
    std::cout << '\n';

    return 0;
}