//
//  StrVector.cpp
//
//  Created by Tang Chengming on 2021/8/4.
//
//  @Brief  
//

#include "ex13_39_StrVector.h"

std::allocator<std::string> StrVector::sStrAllocator_ = std::allocator<std::string>();

// copy ctor
StrVector::StrVector(StrVector const &rhs) {
    // 分配内存并从 rhs 拷贝对象
    auto p = StrVector::allocateAndCopy(rhs.data_, rhs.size_);
    data_ = p.first;
    capacity_ = size_ = p.second;
}

// copy op=
StrVector &StrVector::operator=(StrVector const &rhs) {
    // 拷贝 rhs 的数据
    auto const p = StrVector::allocateAndCopy(rhs.data_, rhs.size_);
    // 销毁动态内存中的 std::string 对象，并回收内存
    destroyAndDeallocate();
    // 让 this 管理之前拷贝 rhs 的内存
    data_ = p.first;
    capacity_ = size_ = p.second;
    return *this;
}

// dtor
StrVector::~StrVector() {
    destroyAndDeallocate();
}

// move ctor
StrVector::StrVector(StrVector &&rhs)  noexcept : data_(rhs.data_), size_(rhs.size_), capacity_(rhs.capacity_) {
    rhs.data_ = nullptr;
    rhs.size_ = 0;
    rhs.capacity_ = 0;
}

// move op=
StrVector &StrVector::operator=(StrVector &&rhs) noexcept{
    if (this != &rhs) {
        delete data_;
        data_ = rhs.data_;
        size_ = rhs.size_;
        capacity_ = rhs.capacity_;
        rhs.size_ = rhs.capacity_ = 0;
        rhs.data_ = nullptr;
    }
    return *this;
}

void StrVector::pushBack(std::string const &str) {
    checkCapacity();
    // 构造元素
    sStrAllocator_.construct(data_ + size_, str);
    ++size_;
}

std::string *StrVector::begin() const {
    return data_;
}

std::string *StrVector::end() const {
    return data_ + size_;
}

std::size_t StrVector::size() const {
    return size_;
}

std::size_t StrVector::capacity() const {
    return capacity_;
}

void StrVector::popBack() {
    if (size_ == 0) {
        return;
    }
    --size_;
    sStrAllocator_.destroy(data_ + size_);
}

void StrVector::resize(std::size_t newSize) {
    while (size_ != newSize) {
        if (size_ < newSize) {
            pushBack(std::string());
        } else {
            popBack();
        }
    }
}

void StrVector::reserve(std::size_t newCapacity) {
    while (capacity_ < newCapacity) {
        expandCapacity();
    }
}

std::pair<std::string *, std::size_t> StrVector::allocateAndCopy(std::string const *data, std::size_t size) {
    auto const newData = sStrAllocator_.allocate(size);
    std::uninitialized_copy(data, data + size, newData);
    return {newData, size};
}

void StrVector::destroyAndDeallocate() {
    while (size_ > 0) {
        --size_;
        sStrAllocator_.destroy(data_ + size_);
    }
    sStrAllocator_.deallocate(data_, capacity_);
    data_ = nullptr;
    capacity_ = 0;
}

void StrVector::checkCapacity() {
    if (capacity_ == size_) {
        expandCapacity();
    }
}

void StrVector::expandCapacity() {
    // 分配一块更大的内存
    // 默认的 capacity_ 为0
    std::size_t newCapacity = capacity_ ? capacity_ * 2 : 1;
    auto const newData = sStrAllocator_.allocate(newCapacity);
    // 将原先的 std::string 元素拷贝到新内存
    std::size_t newSize = 0;
    while ( newSize < size_) {
        // 旧内存的 std::string 对象不会再用到，因此通过 std::move 减少性能损耗
        sStrAllocator_.construct(newData + newSize, std::move(*(data_ + newSize)));
        ++newSize;
    }
    // 销毁旧内存的 std::string 元素，并释放旧内存
    destroyAndDeallocate();
    data_ = newData;
    size_ = newSize;
    capacity_ = newCapacity;
}

StrVector::StrVector(std::initializer_list<std::string> initList) {
    auto p = allocateAndCopy(initList.begin(), initList.size());
    data_ = p.first;
    capacity_ = size_ = p.second;
}