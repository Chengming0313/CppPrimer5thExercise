# C++ Primer 5th 第九章 习题
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

## 9.1 节练习

### 9.1
> Which is the most appropriate—a vector, a deque, or a list—for the following program tasks?Explain the rationale for your choice.If there is no reason to prefer one or another container, explain why not.

> - (a) Read a fixed number of words, inserting them in the container alphabetically as they are entered. We’ll see in the next chapter that associative containers are better suited to this problem.
> - (b) Read an unknown number of words. Always insert new words at the back. Remove the next value from the front.
> - (c) Read an unknown number of integers from a file. Sort the numbers and then print them to standard output.


优先级：vector -> deque -> list
(a) vector : 先在尾部插入, 然后排序
(b) deque: 在尾部插入，头部删除
(c) vector, 元素较小且数目较多, 不要使用 list 或者 forward_list，

---

## 9.2 节练习

### 9.2

> Define a list that holds elements that are deques that hold ints.

```C++
std::list<std::deque<int>> c;
```
---

## 9.2.1 节练习

### 9.3

> What are the constraints on the iterators that form iterator ranges?

1. 他们指向同一个容器中的元素，或者末尾元素后一个位置
2. 递增 begin 一定能够得到 end 

### 9.4

> Write a function that takes a pair of iterators to a vector and an int value. Look for that value in the range and return a bool indicating whether it was found.

```C++
bool find(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end, int target) {
    while (begin != end) {
        if (*begin == target) return true;
        ++begin;
    }
    return false;
}
```

### 9.5

> Rewrite the previous program to return an iterator to the requested element. Note that the program must handle the case where the element is not found.

```C++
std::vector<int>::const_iterator find(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end, int target) {
    while (begin != end) {
        if (*begin == target) return begin;
        ++begin;
    }
    return false;
}
```

### 9.6

> What is wrong with the following program? How might you correct it?

```C++
list<int> lst1;
list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
while (iter1 < iter2)
// ...
```

list 不支持迭代器的 < 运算符。

Fixed
```
while (iter1 != iter2)
```

---

## 9.2.2 节练习

### 9.7

> What type should be used as the index into a vector of ints?

```C++
vector<int>::size_type
```

### 9.8

> What type should be used to read elements in a list of strings? To write them?

```C++
list<string>::const_iterator、list<string>::iterator
```
---

## 9.2.3 节练习

### 9.9

> What is the difference between the begin and cbegin functions?

```
begin 实际上有两个，非const 返回的是 xxx::iterator, const 返回 xxx::const_iterator
cbegin 无论是不是 const 对象, 返回的是 xxx::const_iterator
如果不需要修改元素，推荐使用 cbegin
```

### 9.10

> What are the types of the following four objects?

```C++
vector<int> v1;
const vector<int> v2; 
auto it1 = v1.begin(), it2 = v2.begin(); // vector<int>::iterator，vector<int>::const_iterator
auto it3 = v1.cbegin(), it4 = v4.begin(); // vector<int>::const_iterator，vector<int>::const_iterator
```
---

## 9.2.4 节练习

### [9.11](ex09_11.cpp)

### 9.12

> Explain the differences between the constructor that takes a container to copy and the constructor that takes two iterators.

```
copy ctor 复制所有的元素
iterator ctor 只会复制 [begin, end) 之间的元素
```

### [9.13](ex09_13.cpp)

### [9.14](ex09_14.cpp)
---

## 9.2.7 节练习

### [9.15](ex09_15.cpp)

### [9.16](ex09_16.cpp)

### [9.17](ex09_17.cpp)

> Assuming c1 and c2 are containers, what (if any) constraints does the following usage place on the types of c1 and c2?

```C++
if (c1 < c2)
```

answer:
1. c1 以及 c2 的容器类型必须相同
2. c1 以及 c2 不能是无序关联容器
3. c1 以及 c2 中的元素必须支持 op <
---

## 9.3.1 节练习

### [9.18](ex09_18.cpp)

### [9.19](ex09_19.cpp)

### [9.20](ex09_20.cpp)

### 9.21

> Explain how the loop from page 345 that used the return from insert to addelements to a list would work if we inserted into a vector instead.

```C++
std::vector<std::string> vec;
auto iter = vec.begin();
while (std::cin >> word) {
    iter = vec.insert(iter, word);
}
```

使用 vector 与 list 的效果一样

### [9.22](ex09_22.cpp)

> Assuming iv is a vector of ints, what is wrong with the following program? How might you correct the problem(s)?

```C++
std::vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size() / 2;
while (iter != mid) 
    if (*iter == someVal) 
        iv.insert(iter, someVal * 2);
```

1. 循环不会终止, 因为 iter 没有递增
2. insert 之后, vector 的迭代器会失效, 需要重新赋值
---

## 9.3.2 节练习

### 9.23

> ln the first program in this section on page 346, what would the values of val, val2, val3, and val4 be if c.size() is 1?

```C++
if (!c.empty()) {
    auto val = *c.begin(), val2 = c.front();
    auto last = c.end();
    auto val3 = *(--last);
    auto val4 = c.back();
}
```

val, val2. val3, val4 的值相等

### [9.24](ex09_24.cpp)
---

## 9.3.3 节练习

### [9.25](ex09_25.cpp)

> In the program on page 349 that erased a range of elements, what happens ifelem1 and elem2 are equal? What if elem2 or both elem1 and elem2 are theoff-the-end iterator?

```C++
elem1 = slist.erase(elem1, elem2);
```

```
answer: 1. elem1 等于 elem2，什么都没做
        2. elem2 等于尾后迭代器，删除 elem1 及其之后的所有元素。
        3. elem1 以及 elem2 都等于尾后迭代器, 什么都没做。 
```

### [9.26](ex09_26.cpp)

### [9.27](ex09_27.cpp)

### [9.28](ex09_28.cpp)
---

## 9.3.5 节练习

### [9.29](ex09_29.cpp)

> Given that vec holds 25 elements, what does vec.resize(100) do? What if we next wrote vec.resize(10)?

resize 增大 size 会同步增大 capacity，减小 size 的时候，不能减小 capacity
```
vec(25, 1)...
capacity : 25, size : 25

vec.resize(100)...
capacity : 100, size : 100

vec.resize(10)...
capacity : 100, size : 10
```

### 9.30

> What, if any, restrictions does using the version of resize that takes a single argument place on the element type?

resize(n)要求容器的元素类型必须为内置类型，或者有默认构造函数（包括合成的以及自定义的）。

---

## 9.3.6 节练习

### [9.31](ex09_31.cpp)


list 以及 forward_list 不支持随机访问（iter += 2）
forward_list 不支持 insert 以及 erase 操作，需要使用 insert_after 以及 erase_after。


### [9.32](ex09_32.cpp)

>  In the program on page 354 would it be legal to write the call to insert as follows? If not, why not?

```C++
iter = vi.insert(iter, *iter++);
```

这种递增或者递减运算符的使用会导致表达式的结果未定义，insert 中不知道 iter 是否已经进行了自增。


### [9.33](ex09_33.cpp)

### [9.34](ex09_34.cpp)

> Assuming vi is a container of ints that includes even and odd values, predict the behavior of the following loop. After you've analyzed this loop, write a program to test whether your expectations were correct.

```C++
for (auto iter = v.begin(); iter != v.end();) {
    if (*iter % 2) iter = v.insert(iter, *iter);
    ++iter;
}
```

iter 会无限遍历容器中的第一个奇数

---

## 9.4 节练习

### 9.35

> Explain the difference between a vector’s capacity and its size.

capacity 代表vector容量，表示没有重新分配内存之前，容器最多存储的元素数目。它代表了事先为容器分配的内存大小。
size 代表vector大小，表示容器当前存放的元素数目。

### 9.36

> Can a container have a capacity less than its size?

capacity 不可能小于 size


### 9.37

> Why don’t list or array have a capacity member?

array 固定大小，因此没有 capacity
list 它的内部结构是双向链表，不是数组，因此没有 capacity

### [9.38](ex09_38.cpp)

> Write a program to explore how vectors grow in the library you use.

```
answer: 成倍扩容
```

### 9.39

> Explain what the following program fragment does:

```C++
vector<string> svec;
svec.reserve(1024);
string word;
while (cin >> word) 
    svec.push_back(word);
svec.resize(svec.size() + svec.size() / 2);
```

这段程序中有三个地方可能导致 capacity 改变。
1. reserve, capacity 至少扩容为 1024（一般是1024）
2. push_back，当读取的单词数超过 1024 时，capacity 也会发生扩容
3. resize，只有 svec.size() + svec.size() / 2 超过当前的 capacity 才会发生扩容

### [9.40](ex09_40.cpp)

> 如果上一题的程序读入了 256 个词，在 resize 之后容器的 capacity 可能是多少，如果读入了 512 个、1000 个或 1024 个词呢？

```
256 : 1024
512 : 1024
1000 : 2000
1048 : 2048
```
---

## 9.5.1 节练习

### [9.41](ex09_41.cpp)

### [9.42](ex09_42.cpp)
> Given that you want to read a character at a time into a string, and you know that you need to read at least 100 characters, how might you improve the performance of your program?

reserve(100)

---

## 9.5.2 节练习

### [练习 9.43](ex09_43.cpp)

### [练习 9.44](ex09_44.cpp)

### [练习 9.45](ex09_45.cpp)

### [练习 9.46](ex09_46.cpp)
---

## 9.5.3 节练习

### 练习 9.47 [find_first_of](ex09_47_1.cpp) [find_first_not_of](ex09_47_2.cpp)

### 练习 9.48

> Given the definitions of name and numbers on page 365, what does numbers.find(name) return?

```C++
string numbers("0123456789"), name("r2d2);
```

std::string::npos

### [练习 9.49](ex09_49.cpp)
---

## 9.5.5 节练习

### [练习 9.50.1](ex09_50_1.cpp) [练习 9.59.2](ex09_50_2.cpp)

### [练习 9.51](ex09_51.cpp)

### [练习 9.52](ex09_52.cpp)






