//
//  ex13_44.cpp
//
//  Created by Tang Chengming on 2021/8/5.
//
//  @Brief  
//

#include "ex13_44_String.h"
#include <cstring>
#include <iostream>

std::allocator<char> String::sCharAllocator_ = std::allocator<char>();

String::String(char const *cStr) {
    std::size_t len = strlen(cStr);
    auto const p = allocateAndCopy(cStr, len);
    data_ = p.first;
    capacity_ = size_ = p.second;
}

// copy ctor
String::String(String const &rhs){

//    std::cout << "copy ctor: " << this << std::endl;
    auto const p = allocateAndCopy(rhs.data_, rhs.size_);
    data_ = p.first;
    capacity_ = size_ = p.second;
    // debug
    printInfo("copy ctor:");
}

// copy op=
String &String::operator=(String const &rhs) {
//    std::cout << "copy op=: " << this << std::endl;
    // 构造一个临时对象存放 rhs 的值
    auto const tmp(rhs);

    // 销毁原对象
    // 释放旧内存
    destroyAndDeallocate();

    // 分配新内存
    // 拷贝临时对象的值
    auto const p = allocateAndCopy(tmp.data_, tmp.size_);
    data_ = p.first;
    capacity_ = size_ = p.second;

    // debug
    printInfo("copy op=:");
    return *this;
}

// dtor
String::~String() {
    destroyAndDeallocate();
}

// move ctor
String::String (String &&rhs) noexcept : data_(rhs.data_), size_(rhs.size_), capacity_(rhs.capacity_) {
//    std::cout << "move ctor: " << this << std::endl;
    // 移动 data_, size_, capacity_
    rhs.data_ = nullptr;
    rhs.size_ = rhs.capacity_ = 0;
    printInfo("move ctor:");
}

// move op=
String &String::operator=(String &&rhs) noexcept {
//    std::cout << "move op=: " << this << std::endl;
    if (this != &rhs) {
        destroyAndDeallocate();
        data_ = rhs.data_;
        size_ = rhs.size_;
        capacity_ = rhs.capacity_;
        rhs.data_ = nullptr;
        rhs.size_ = rhs.capacity_ = 0;
    }
    printInfo("move op=:");
    return *this;
}

char *String::begin() {
    return data_;
}

char *String::end() {
    return data_ + size_;
}

void String::pushBack(char ch) {
    checkAndExpand();
    sCharAllocator_.construct(data_ + size_, ch);
    ++size_;
}

void String::popBack() {
    sCharAllocator_.destroy(data_ + size_ - 1);
    --size_;
}

void String::destroyAndDeallocate() {
    while (size_ > 0) {
        sCharAllocator_.destroy(data_ + size_ - 1);
        --size_;
    }
    sCharAllocator_.deallocate(data_, capacity_);
    data_ = nullptr;
    capacity_ = 0;
}

std::pair<char *, std::size_t> String::allocateAndCopy(char const *cStr, std::size_t len) {
    auto const newData = sCharAllocator_.allocate(len);
    std::uninitialized_copy(cStr, cStr + len, newData);
    return {newData, len};
}

std::pair<char *, std::size_t> String::allocateAndCopy(char const *cStr, std::size_t len, std::size_t capacity) {
    auto const newData = sCharAllocator_.allocate(capacity);
    std::uninitialized_copy(cStr, cStr + len, newData);
    return {newData, len};
}

void String::checkAndExpand() {
    if (capacity_ == size_) {
        expand();
    }
}

void String::expand() {
    std::size_t newCapacity = capacity_ == 0 ? 1 : capacity_ * 2;
    // 分配新内存
    // 拷贝旧内存中的对象
    auto const p = allocateAndCopy(data_, size_, newCapacity);
    // 销毁旧内存中的对象并释放旧内存
    destroyAndDeallocate();
    // 更新成员变量
    data_ = p.first;
    capacity_ = newCapacity;
    size_ = newCapacity / 2;
}

void String::printInfo(char const *prefix) {
    std::cout << prefix << " ";
    for (int i = 0; i < size_; ++i) {
        std::cout << *(data_ + i);
    }
    std::cout << std::endl;
}