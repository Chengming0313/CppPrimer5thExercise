//
//  ex13_25_26.cpp
//
//  Created by Tang Chengming on 2021/7/14.
//
//  @Brief  StrBlob 的类值版本
//

#include <string>
#include <vector>
#include <memory>
#include <iostream>

class StrBlob {
public:
    using SizeType = std::vector<std::string>::size_type;

    // 构造函数
    StrBlob();

    StrBlob(std::initializer_list<std::string> il);

    SizeType size() const {return data_->size();}

    bool empty() const {return data_->empty();}

    // 添加, 删除元素
    void push_back(std::string const &str) {data_->push_back(str);}

    void pop_back();

    // 元素访问
    std::string &front();

    std::string &back();

    // 13.26 自定义 copy ctor, copy op=
    StrBlob(StrBlob const &x) : data_(std::make_shared<std::vector<std::string>>(*x.data_)){
    }

    StrBlob &operator=(StrBlob const &rhs) {
        if (this == &rhs) {
            return *this;
        }
        data_ = std::make_shared<std::vector<std::string>>(*rhs.data_);
        return *this;
    }

private:
    std::shared_ptr<std::vector<std::string>> data_;
    // 如果 data_[i] 不合法, 抛出一个异常
    void check(SizeType i, std::string const &msg);
};

StrBlob::StrBlob() : data_(std::make_shared<std::vector<std::string>>()) {

}

StrBlob::StrBlob(std::initializer_list<std::string> il) : data_(std::make_shared<std::vector<std::string>>(il)) {}

void StrBlob::check(SizeType i, std::string const &msg) {
    if (i >= data_->size())
    {
        throw std::out_of_range(msg);
    }
}

std::string &StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data_->front();
}

std::string &StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data_->back();
}

void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data_->pop_back();
}

int main() {
    StrBlob sb1{"hello", "world"}, sb2(sb1), sb3;
    sb3 = sb1;

    std::cout << sb1.front() << " " << sb2.front() << " " << sb3.front() << std::endl;

    sb2.front() = "sb2";
    sb3.front() = "sb3";

    std::cout << sb1.front() << " " << sb2.front() << " " << sb3.front() << std::endl;

    return 0;
}