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

如果 roster1 以及 roster2 都保存的是C风格字符串，则实际比较的是 char * 是否相同。
