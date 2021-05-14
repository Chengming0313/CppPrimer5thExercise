//
//  ex11_26.cpp
//
//  Created by Tang Chengming on 05/12/2021
//
//  @Brief

#include <iostream>
#include <map>
#include <string>
#include <typeinfo>  // typeid
int main() {
    std::map<int, std::string> m{ { 1, "Tom" }, { 2, "Jerry" } };

    using KeyType = std::map<int, std::string>::key_type;
    std::cout << "type to subscript: " << typeid(KeyType).name() << std::endl;
    std::cout << "returned from the subscript operator: " << typeid(decltype(m[0])).name()
              << std::endl;

    return 0;
}
