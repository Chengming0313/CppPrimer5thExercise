# C++ Primer 5th 第十一章 习题
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

## 11.1 节练习

### 练习 11.1

> 描述 map 和 vector 的不同.

map 是 associative container, 根据 key 来存储和访问 value, vector 是 sequence container, 根据元素在容器中的位置来存储和访问 value.

### 练习 11.2

> 分别给出最适合 list vector deque map set 的例子.

list : 元素较大(大的对象), 数量预先不知道, 或是程序运行中大小变动很频繁, 顺序访问全部或者很多元素.
vector : 元素较小(int), 预先大概知道元素数目, 程序运行中大小变动不频繁, 总是在尾部添加或删除元素, 需要访问任意位置的元素.
deque : 当需要在头部以及尾部添加或者删除元素, 其它与 vector 一样.
map : 字典类型, 适合根据对象的特征(key)访问对象(value).
set : 集合类型(黑名单、白名单).

### [练习 11.3](ex11_03.cpp)

### [练习 11.4](ex11_04.cpp)

## 11.2.1 节练习

### 练习 11.5

> 解释 map 和 set 的区别.

map 和 set 都是 associative container, 只是 set 的 key 就是 value.

### 练习 11.6

> 解释 set 和 list 的区别.

set 是 associative container, 而 list 是 sequence container. 当需要判断对象是否在某个特定的集合中时, 选择 set.

### [练习 11.7](ex11_07.cpp)

### [练习 11.8](ex11_08.cpp)

## 11.2.2 节练习

### [练习 11.9](ex11_09.cpp)

### 练习 11.10

> 可以定义一个 vector<int>::iterator 到 int 的 map 吗. list<int>::iterator 到 int 的 map 呢.

默认情况下, map 使用 < 比较 key, 而 vector<int>::iterator 可以进行比较, 而 list<int>::iterator 不能进行比较.

### [练习 11.11](ex11_11.cpp)