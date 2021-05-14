//
//  ex11_31_32.cpp
//
//  Created by Tang Chengming on 05/13/2021
//
//  @11.31  编写程序, 定义一个作者及其作品的 multimap, 使用 find 在 multimap
//          中查找一个元素并用 erase 删除它. 确保你的程序在元素不在 map 中时也能正常运行.
//
//  @11.32  使用上一题定义的 multimap, 按字典序打印作者列表和他们的作品.

#include <iostream>
#include <map>

using Mp = std::multimap<std::string, std::string>;

//  11.32 multimap 本身有序, 而对于 string 类型的关键字, 默认已经是字典序升序.
void print(Mp const &m) {
    for (auto const &p : m) {
        std::cout << "author: " << p.first << ", book: " << p.second << std::endl;
    }
}

//  11.31 使用 find 以及 erase 删除某作者及他所属的书目
void removeAuthor(Mp &m, std::string const &author) {
    auto item = m.find(author);
    auto cnt = m.count(author);
    while (cnt) {
        m.erase(item);
        ++item;
        --cnt;
    }
}

int main() {
    Mp authors{ { "Hemingway", "The Old Man and the Sea" },
                { "Shakespeare", "The Merchant of Venice" },
                { "Walt Whitman", "Leaves of Grass" },
                { "Shakespeare", "Romeo and Juliet" },
                { "Hemingway", "The Sun Also Rises" } };
    print(authors);
    std::cout << std::endl;

    removeAuthor(authors, "Hemingway");
    print(authors);
    std::cout << std::endl;

    removeAuthor(authors, "xxx");
    print(authors);

    return 0;
}
