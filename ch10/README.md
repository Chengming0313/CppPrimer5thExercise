# C++ Primer 5th 第十章 习题
## 环境

### Windows

```
gcc --version : gcc.exe (tdm64-1) 9.2.0
g++ xxx -o xxx.exe -g -Wall -fexec-charset=GBK -std=c++11
```
### Linux

```
gcc (GCC) 4.8.5 20150623 (Red Hat 4.8.5-44)
```
---

## 10.1 节练习

### [练习 10.1](ex10_01.cpp)

### [练习 10.2](ex10_02.cpp)

## 10.2.1 节练习

### [练习 10.3](ex10_03.cpp)

### [练习 10.4](ex10_04.cpp)

程序能够运行，但结果不符合预期，如下所示，`double`类型的元素与`init`相加后，会转换为`int`类型进行保存。

```C++
std::vector<double> vec{ 1.0, 1.1, 1.2 };
double sum = std::accumulate(vec.cbegin(), vec.cend(), 0);
```

```
The sum of vector<double> is 3.
```

### [练习 10.5](ex10_04.cpp)

如果 roster1 以及 roster2 都保存的是C风格字符串，则实际比较的是 char *（地址） 是否相同。

## 10.2.2 节练习

### [练习 10.6](ex10_06.cpp)

### [练习 10.7](ex10_07.cpp)

### 练习 10.8

`back_inserter` 定义在 `<iterator>` 中，而不是 `<algorithm>`。`back_inserter` 会改变大小是因为它重载了赋值运算符。 

## 10.2.3 节练习

### [练习 10.9](ex10_09.cpp)

### 练习 10.10

算法是通过传入的迭代器来操纵容器，而迭代器不能改变完成容器的插入以及删除，因此算法不能改变容器大小。

## 10.3.1 节练习

### [练习 10.11](ex10_11.cpp)

### [练习 10.12](ex10_12.cpp)

### [练习 10.13](ex10_13.cpp)

## 10.3.2 节练习

### [练习 10.14](ex10_14.cpp)

### [练习 10.15](ex10_15.cpp)

### [练习 10.16](ex10_16.cpp)

### [练习 10.17](ex10_17.cpp)

### [练习 10.18](ex10_18.cpp)

### [练习 10.19](ex10_19.cpp)

## 10.3.3 节练习

### [练习 10.20](ex10_20.cpp)

### [练习 10.21](ex10_21.cpp)

## 10.3.4 节练习

### [练习 10.22](ex10_22.cpp)

### 练习 10.23

`std::bind` 比可调用对象的参数多一个.

### [练习 10.24](ex10_24.cpp)

### [练习 10.25](ex10_25.cpp)

## 10.4.1 节练习

### 练习 10.26

> 解释三种插入迭代器的不同之处.

back_inserter front_inserter inserter 创建的迭代器赋值时调用的操作不一样，分别是 push_back push_front insert.

### [练习 10.27](ex10_27.cpp)

### [练习 10.28](ex10_28.cpp)

```C++
std::vector<int> ivec{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
std::vector<int> c1, c2, c3;
std::copy(ivec.cbegin(), ivec.cend(), std::inserter(c1, c1.begin()));   // 1, 2, 3, ..., 8, 9
std::copy(ivec.cbegin(), ivec.cend(), std::back_inserter(c2));          // 1, 2, 3, ..., 8, 9
std::copy(ivec.cbegin(), ivec.cend(), std::front_inserter(c3));         // 9, 8, 7, ..., 2, 1
```

## 10.4.2 节练习

### [练习 10.29](ex10_29.cpp)

### [练习 10.30](ex10_30.cpp)

### [练习 10.31](ex10_31.cpp)

### [练习 10.32](ex10_32.cpp)

### [练习 10.33](ex10_33.cpp)

## 10.4.3 节练习

### [练习 10.34](ex10_34.cpp)

### [练习 10.35](ex10_35.cpp)

### [练习 10.36](ex10_36.cpp)

### [练习 10.37](ex10_37.cpp)

## 10.5.1 节练习

### 练习 10.38

> 列出 5 个迭代器类别, 以及每类迭代器支持的操作.

- input iterator: ==, !=, ++, *, ->
    解引用只能出现在赋值运算右边
    eg. istream_iterator
- output iterator: ++, *
    解引用只能出现在赋值运算左边
    eg. ostream_iterator: *oit++ = data; 等价于 oit = data;
- forward iterator: ==, !=, ++, *, ->
- bidirectional iterator: ==, !=, ++, --, *, ->
- random-access iterator: ==, !=, <, <=, >, >=, ++, --, +, +=, -, -=, -(two iterators), *, ->, iter[n] == * (iter + n)

### 练习 10.39

> list 上的迭代器属于哪一类, vector 呢.

- list: bidirectional iterator
- vector: random-access iterator

### 练习 10.40

> 你认为 copy 要求哪类迭代器, reverse 和 unique 呢

- copy: arg1、arg2: input iterator
        arg3: output iterator
- reverse: arg1、arg2: bidirectional iterator
- unique: arg1、arg2: forward iterator

## 10.5.3 节练习

### 练习 10.41

> 仅根据算法和参数的名字, 描述下面每个标准库算法执行的操作.

```C++ 
replace(beg, end, old_val, new_val);            // 替换 [beg, end) 中的 old_val 为 new_val
replace_if(beg, end, pred, new_val);            // 如果 pred 为真, 替换 [beg, end) 中的 old_val 为 new_val
replace_copy(beg, end, dest, old_val, new_val); // 替换 [beg, end) 中的 old_val 为 new_val, 将结果拷贝到 dest
replace_copy_if(beg, end, dest, pred, new_val); // 如果 pred 为真, 替换 [beg, end) 中的 old_val 为 new_val, 将结果拷贝到 dest
```

## 10.6 节练习

### [练习 10.42](ex10_42.cpp)





