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

## 11.2.3 节练习

### [练习 11.12](ex11_12.cpp)

### [练习 11.13](ex11_13.cpp)

### [练习 11.14](ex11_14.cpp)

## 11.3.1 节练习

### 练习 11.15

> 对一个 int 到 vector<int> 的 map, 其 mapped_type、key_type 和 value_type 分别是什么

key_type int
mapped_type vector<int>
value_type pair<int, vector<int>>

### 练习 11.16

> 使用一个 map 迭代器编写一个表达式, 将一个值赋予一个元素.

```c++
mapIt->second = data;
```

### 练习 11.17

> 假定 c 是一个 string 的 multiset, v 是一个 string 的 vector, 解释下面的调用. 指出每个调用是否合法.

```C++
copy(v.begin(), v.end(), inserter(c, c.end()));  // 合法, 尽管 c 的迭代器是 const 的, 但是可以通过 inserter 进行插入
copy(v.begin(), v.end(), back_inserter(c));      // 非法, c 没有 push_back
copy(c.begin(), c.end(), inserter(v, v.end()));  // 合法, 将 c 中的 string 拷贝到 v 中 
copy(c.begin(), c.end(), back_inserter(v));      // 合法, 将 c 中的 string 拷贝到 v 中
```

### 练习 11.18

> 写出 p382 中 map_it 的类型, 不要使用 auto 或者 decltype

std::map<std::string, std::size_t>::const_iterator, 指向 std::pair<std::string, std::size_t>

### 练习 11.19

> 定义一个变量, 通过对 p379 中名为 bookstore 的 multiset 调用 begin() 来初始化这个变量. 写出变量的类型, 不要使用 auto 或 decltype.

```C++
using CmpFp = bool (*)(SalesData const &, SalesData const &);

bool compareIsbn(SalesData const &lhs, SalesData const &rhs) {
    return lhs.isbn() < rhs.isbn();
}

int main() {
    std::multiset<SalesData, CmpFp>           bookstore(compareIsbn);
    // it 指向 SalesData
    std::multiset<SalesData, CmpFp>::iterator it = bookstore.begin();
    return 0;
}
```

## 11.3.2 节练习

### [练习 11.20](ex11_20.cpp)

### 练习 11.21

> 解释下面循环的作用.

```C++
while (cin >> word) {
    ++word_count.insert({word, 0}).first->second;
}
```

统计单词出现次数

### 练习 11.22

> 给定一个 map<string, vector<int>>, 对此容器的插入一个元素的 insert 版本, 写出其参数类型与返回类型.

```C++
std::pair<std::string, std::vector<int>>
std::pair<std::map<string, std::vector<int>>::iterator, bool>
```

### [练习 11.23](ex11_23.cpp)

## 11.3.4 节练习

### 练习 11.24

> 下面的程序完成什么功能

```C++
map<int, int> m;
m[0] = 1;
```

插入或赋值使得 m[0] => 1

### 练习 11.25

> 对比下面程序和上一题程序

```C++
vector<int> v;
v[0] = 1;
```

未定义行为(UB), 试图访问不存在的内存. 可能导致 segmentation fault, 也有可能不会报错.

### [练习 11.26](ex11_26.cpp)

> 给出一个具体例子说明可以用什么类型对一个 map 进行下标操作, 下标操作返回的数据类型是什么.

```C++
std::map<int, std::string> m;
```

int 
map<int, string>::mapped_type string

## 11.3.5 节练习

### 练习 11.27

> 对于什么问题你会使用 count , 什么问题你会使用 find

对于允许重复关键字的容器 (multi), 优先使用 find, 除非需要统计关键字出现的次数
对于单一关键字的容器, find 以及 count 的效率没有差别

### [练习 11.28](ex11_28.cpp)

> 对于一个 string 到 vector<int> 的 map, 定义一个变量并用 find 初始化.

```C++
std::map<std::string, std::vector<int>> m;
std::map<std::string, std::vector<int>>::iterator item = m.find("hello");
```

### 练习 11.29

> 如果给定的关键字不在容器中, upper_bound lower_bound 以及 equal_range 分别返回什么

upper_bound 以及 lower_bound 返回的结果一致, 都指向给定关键字的插入位置.
equal_range 会返回一对 尾后迭代器 pair

### 练习 11.30

> 对于本节最后一个程序中的输出表达式, 解释运算对象 pos.find->second 的含义

等价于 ((pos.first)->second), 访问书名

### [练习 11.31 & 11.32](ex11_31_32.cpp)

## 11.3.6 节练习

### [练习 11.33](ex11_33.cpp)

### 练习 11.34

> 如果将 transform 中的 find 替换为下标运算符, 会发生什么

```C++
map<string, string> buildMap(ifstream &map_file)
```
不在 map 中的单词会被替换成 ""
注意: map_file 不能是 const 的, 因为 [] 可能会插入键值对.

### 练习 11.35

> buildMap 中, 如果进行如下改写, 会有什么效果.

```C++
trans_map[key] = value.substr(1)
```
改成
```C++
trans_map.insert({key, value.substr(1)})
```

如果重复插入相同的 key, trans_map 中保存的结果不一样.
[key] 会对原来的值更新, 而 insert 不会改变第一次插入的值.

### 练习 11.36

> 如果 mapFile 中的某一行只有 key 以及其后的一个空格, 会发生什么.

transMap[key] 的值为 ""

## 11.4 节练习

### 练习 11.37

> 一个无序容器与其有序版本相比有何优势. 有序版本有何优势.

无序容器通常性能更好, 使用更简单. 适合在元素的有序性较弱或者维护有序性代价较高时使用.
当应用要求必须维护元素的序时，使用有序容器

### [练习 11.38](ex11_38.cpp)
