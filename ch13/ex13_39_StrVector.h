//
//  StrVector.h
//
//  Created by Tang Chengming on 2021/8/4.
//
//  @Brief  ex13.39 创建
//          ex13.40 添加 ctor, 参数为std::initializer_list
//          ex13.49 添加 move ctor, move op=, 修改 expandCapacity
//

#ifndef CPP_PRIMER5_StrVector_H
#define CPP_PRIMER5_StrVector_H

#include <string>
#include <cstddef>
#include <memory>
#include <initializer_list>

class StrVector {
public:
    // --------------------- 构造函数 ---------------------
    // strAllocator 默认初始化
    StrVector() : data_(nullptr), size_(0), capacity_(0) {}

    // ex13.40
    StrVector(std::initializer_list<std::string> initList);

    // --------------------- 拷贝控制 ---------------------

    // copy ctor
    StrVector(StrVector const &);

    // copy op=
    StrVector &operator=(StrVector const &);

    // dtor
    ~StrVector();

    // move ctor
    StrVector(StrVector &&) noexcept;

    // move op=
    StrVector &operator=(StrVector &&) noexcept;

    // --------------------- 功能函数 ---------------------

    void pushBack(std::string const &);

    std::string *begin() const;

    std::string *end() const;

    std::size_t size() const;

    std::size_t capacity() const;

    void resize(std::size_t newSize);

    void reserve(std::size_t newCapacity);

    void popBack();

private:
    static std::allocator<std::string> sStrAllocator_;
    std::string *data_;          // 指向首元素
    std::size_t size_;           // 大小
    std::size_t capacity_;      // 容量

    // --------------------- 工具函数 ---------------------

    // 分配内存，并从另一处拷贝对象
    // 内存容量和大小相等
    static std::pair<std::string *, std::size_t> allocateAndCopy(std::string const *data, std::size_t size);

    // 销毁已经构造的对象，并回收内存
    void destroyAndDeallocate();

    // 保证最少有一个空位置
    void checkCapacity();

    // 扩容
    void expandCapacity();
};

#endif //CPP_PRIMER5_StrVector_H
