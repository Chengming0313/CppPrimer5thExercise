//
//  ex13_44.h
//
//  Created by Tang Chengming on 2021/8/5.
//
//  @Brief
//          ex13.49 添加 move ctor, move op=
//          ex13.50 为 move ctor, move op= 添加一条输出语句
//          ex14.7 定义输出运算符
//

#ifndef CPP_PRIMER5_EX13_44_STRING_H
#define CPP_PRIMER5_EX13_44_STRING_H

#include <cstddef>
#include <memory>
#include <iostream>

class String {
    friend std::ostream &operator<<(std::ostream &, String const &);
public:
    // ------------------------- 构造函数 -------------------------
    String() : size_(0), capacity_(0), data_(nullptr) {}

    explicit String(char const *cStr);

    // ------------------------- 拷贝控制 -------------------------

    // copy ctor
    String(String const &);

    // copy op=
    String &operator=(String const &);

    // dtor
    ~String();

    // move ctor
    String (String &&) noexcept;

    // move op=
    String &operator=(String &&) noexcept;

    // ------------------------- 功能函数 -------------------------

    std::size_t size() const {return size_;}

    std::size_t capacity() const {return capacity_;}

    bool empty() const {return size_ == 0;}

    char *begin();

    char *end();

    void pushBack(char ch);

    void popBack();


private:
    // 完成内存的分配和申请
    static std::allocator<char> sCharAllocator_;

    char *data_;            // 指向字符数组首元素
    std::size_t size_;      // 字符数组大小
    std::size_t capacity_;  // 内存容量

    // ------------------------- 工具函数 -------------------------

    void destroyAndDeallocate();

    static std::pair<char *, std::size_t> allocateAndCopy(char const *, std::size_t);

    static std::pair<char *, std::size_t> allocateAndCopy(char const *, std::size_t, std::size_t);

    void checkAndExpand();

    void expand();

    // ------------------------- Debug -------------------------

    void printInfo(char const *prefix);
};

#endif //CPP_PRIMER5_EX13_44_STRING_H
