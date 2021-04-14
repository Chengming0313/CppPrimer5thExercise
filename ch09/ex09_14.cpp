#include <iostream>
#include <list>
#include <string>
#include <vector>

int main() {
    std::list<const char *>  lst{ "123", "456", "789" };
    std::vector<std::string> v;
    v.assign(lst.cbegin(), lst.cend());

    for (auto s : v)
        std::cout << s << " ";
    std::cout << '\n';

    return 0;
}