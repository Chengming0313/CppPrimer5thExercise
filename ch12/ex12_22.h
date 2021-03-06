// 比起 StrBlobPtr, ConstStrBlobPtr 修改了或者添加了以下内容
// 1. 构造函数 ConstStrBlobPtr(StrBlob const &strBlob, std::size_t=0) {...}
// 2. 不能通过 ConstStrBlob 修改 (StrBlob) vector, std::string const &deref() const {...}
// 3. begin -> ConstStrBlobPtr cbegin() const;
// 4. end -> ConstStrBlobPtr cend() const;

#ifndef CPP_PRIMER_CMT_12_22
#define CPP_PRIMER_CMT_12_22

#include <initializer_list>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

// 前置声明
// StrBlobPtr 此时是一个 incomplete class
class ConstStrBlobPtr;

class StrBlob {
public:
    using SizeType = std::vector<std::string>::size_type;
    // exercise 12.22 用得到
    friend class ConstStrBlobPtr;

    // 构造函数
    StrBlob() : _data(std::make_shared<std::vector<std::string>>()) {}
    StrBlob(std::initializer_list<std::string> li)
        : _data(std::make_shared<std::vector<std::string>>(li)) {}
    SizeType size() const { return _data->size(); }
    bool     empty() const { return _data->empty(); }

    // 添加和删除元素
    void pushBack(std::string const &str) { _data->push_back(str); }
    void popBack();

    // 元素访问
    std::string &      front();
    std::string const &front() const;
    std::string &      back();
    std::string const &back() const;

    // exercise 12.9
    // 这里不能直接定义, 因为 ConstStrBlobPtr 是 incomplete class
    ConstStrBlobPtr cbegin() const;
    ConstStrBlobPtr cend() const;

private:
    std::shared_ptr<std::vector<std::string>> _data;
    void                                      check(SizeType index, std::string const &msg) const;
};

inline void StrBlob::check(SizeType index, std::string const &msg) const {
    if (index >= size()) throw std::out_of_range(msg);
}

inline void StrBlob::popBack() {
    check(0, "popBack on empty StrBlob");
    _data->pop_back();
}

inline std::string &StrBlob::front() {
    check(0, "front on empty StrBlob");
    return _data->front();
}

inline std::string const &StrBlob::front() const {
    check(0, "front on empty StrBlob");
    return _data->front();
}

inline std::string &StrBlob::back() {
    check(0, "back on empty StrBlob");
    return _data->back();
}

inline std::string const &StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return _data->back();
}

class ConstStrBlobPtr {
public:
    // 构造函数
    ConstStrBlobPtr() : _curr(0) {}
    explicit ConstStrBlobPtr(StrBlob const &strBlob, std::size_t sz = 0) : _wptr(strBlob._data), _curr(sz) {}

    // 解引用
    // exercise 12.22
    // 这里返回的是 std::string const &
    std::string const &deref() const {
        auto p = check(_curr, "dereference past end");
        return (*p)[_curr];
    }
    // 前缀递增
    ConstStrBlobPtr &incr() {
        // 如果 _curr 指向容器的尾后, 就不能递增它
        check(_curr, "increment past end of StrBlobPtr");
        ++_curr;
        return *this;
    }
    // op !=
    // 需要确保指向同一个 StrBlob
    bool operator!=(ConstStrBlobPtr const &p) { return p._curr != _curr; }

private:
    // 检查底层 vector 是否被销毁 以及 _curr 是否越界
    std::shared_ptr<std::vector<std::string>> check(std::size_t        index,
                                                    std::string const &msg) const {
        auto ret = _wptr.lock();
        if (!ret) throw std::runtime_error("unbound StrBlobPtr");
        if (index >= ret->size()) throw std::out_of_range(msg);
        return ret;
    }
    std::weak_ptr<std::vector<std::string>>
                _wptr;  // 保存一个 weak_ptr, 意味着底层 vector 可能会被销毁
    std::size_t _curr;  // 在数组中当前位置
};

inline ConstStrBlobPtr StrBlob::cbegin() const {
    return ConstStrBlobPtr(*this);
}
inline ConstStrBlobPtr StrBlob::cend() const {
    return ConstStrBlobPtr(*this, size());
}

#endif