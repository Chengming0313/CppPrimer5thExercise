# C++ Primer 5th 第十二章 习题
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

## 12.1.1 节练习

### 练习 12.1

> 在此代码的结尾，b1 和 b2各包含多少个元素.

```C++
StrBlob b1;
{
    StrBlob b2 = {"a", "an", "the"};
    b1 = b2;
    b2.push_back("about");
}
```

`b1`: 4
`b2` 是一个`局部自动对象 (local automatical object)`, 此时它的生命周期已经结束. 讨论它包含几个元素没有意义.

### 练习 12.2 [Header](ex12_02.h) [Test](ex12_02_test.cpp)

### 练习 12.3

> StrBlob 需要 const 版本的 push_back 以及 pop_back 吗.

不需要, `const StrBlob` 不应该修改 `vector` (实际上可以做到, `_data->pop_back()`, 不会检查 `_data` 是否是 `const`).

### 练习 12.4

> 在我们的练习函数没有检查 i 是否大于0. 为什么可以忽略.

i 的类型为 `std::vector<std::string>::size_type`, 是无符号整数. 即使传入负数, 也会隐式类型转换成无符号整数.

### 练习 12.5

> 我们未编写接受一个 initializer_list explicit 参数的构造函数. 讨论这个设计策略的优点和缺点.

如果构造函数是 `explicit` 的, 这意味着 `{}` 不能自动转化成 `StrBlob`, 这与 `std::vector` 的设计相悖.

## 12.1.2 节练习

### [练习 12.6](ex12_06.cpp)

### [练习 12.7](ex12_07.cpp)

### 练习 12.8

> 下面的函数是否有错, 如果有, 解释错误原因.

```C++
bool b() {
    int *p = new int;
    // ...
    return p;
}
```

该函数返回类型为 `bool`, 因此 `return p` 之后, 没有指针指向 `p` 分配的内存, 导致不能释放之前分配的内存.
可以考虑使用一个中间变量保存结果, 提前释放内存.
```C++
bool x = p;
delete p;
return x;
```

### 练习 12.9

> 解释下面代码执行的结果.

```C++
int *q = new int(42), *r = new int(100);
r = q;
auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
r2 = q2;
```

`r = q` 导致内存泄漏
`r2 = q2`, `r2`的引用计数减为`0`, 动态销毁对象, 并回收内存.

## 12.1.3 节练习

### 练习 12.10

> 下面的代码调用了 p413 中的 process 函数, 解释此调用是否正确.

```C++
shared_ptr<int> p(new int(42));
process(shared_ptr<int>(p));
```

正确, 引用计数: 1->2->3->2->1

### 练习 12.11

> 如果我们像这样调用 process, 会发生什么.

```C++
process(shared_ptr<int>(p.get()))
```

不能要 `p.get()` 初始化一个智能指针, 这会导致两个独立(引用计数不统一)的智能指针指向同一块动态内存. 
会重复 `delete` 同一块内存. 

### 练习 12.12

> p 和 sp 的定义如下, 对于接下来对 process 的调用, 是否合法.

```C++
auto p = new int();
auto sp = make_shared<int>();

(a) process(sp);
(b) process(new int());
(c) process(p);
(d) process(shared_ptr<int>(p));
```

(a) 合法, 引用计数 1->2->1
(b) 错误, 内置指针不能隐式转换成智能指针
(c) 错误, 同 (b)
(d) 危险, `p` 指向的内存会被释放, `p` 会成为空悬指针

### 练习 12.13

> 执行下面的代码会发生什么.

```C++
auto sp = make_shared<int>();
auto p = sp.get();
delete p;
```

未定义行为, 重复 `delete` 同一块内存

## 12.1.4 节练习

### [练习 12.14 12.15](ex12_04_05.cpp)

## 12.1.5 节练习

### 练习 12.16

> 试图拷贝或赋值 unique_ptr, 编译器给出的错误信息是什么.

```C++
std::unique_ptr<Foo> up(new Foo);
std::unique_ptr<Foo> up2 = up;  // error 1

std::unique_ptr<Foo> up3;
up3 = up;  // error 2
```

```
// 使用 deleted 的拷贝构造函数
error: use of deleted function 'std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = Foo; _Dp = std::default_delete<Foo>]'
// 使用 deleted 的赋值运算符
error: use of deleted function 'std::unique_ptr<_Tp, _Dp>& std::unique_ptr<_Tp, _Dp>::operator=(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = Foo; _Dp = std::default_delete<Foo>]'
```

### 练习 12.17

> 下面的 unique_ptr 声明中, 哪些是合法的, 哪些是错误的.

```C++
int ix = 1024, *pi = &ix, *pi2 = new int(2048);
typedef unique_ptr<int> IntP;
(a) IntP p0(ix);
(b) IntP p1(pi);
(c) IntP p2(pi2);
(d) IntP p3(&ix);
(e) IntP p4(new int(2048))
(f) IntP p5(p2.get())
```

(a) 错误, `ix` 是一个 `int`, 没有对应的构造函数, compile error.
(b) 错误, 尽管 `pi` 是 `int *` 指针, 但它并不指向动态分配的内存, runtime error.
(c) 危险, 不要混用 `smart pointer` 以及 `raw pointer`.
(d) 错误, 同 (b), runtime error.
(e) 合法, 推荐写法.
(f) 错误, `unique_ptr` 没有引用计数, 会导致 `double free`, runtime error.

### 练习 12.18

> shared_ptr 为什么没有 release 成员.

没有意义, 因为 `unique_ptr` 不能拷贝和赋值, 需要通过 `release` 转移所有权, 而 `shared_ptr` 可以拷贝和赋值,
直接就能共享所有权.

### 练习 12.19 [Header](ex12_19.h) [Implementation](ex12_19.h) [Test](ex12_19_test.cpp)

### [练习 12.20](ex12_20.cpp)

### 练习 12.21

> 也可以这也编写 StrBlobPtr 中的 deref 成员. 哪个版本更好.

```C++
std::string &deref() const {
    return (*check(curr, "dereference pass end ))[curr];
}
```

之前版本更好, 这个可读性较差.

### 练习 12.22 [Header](ex12_22.h) [Test](ex12_22_test.cpp)

### [练习 12.23](ex12_23.cpp)

### [练习 12.24](ex12_23.cpp)

### 练习 12.25

> 给定下面的 new 表达式, 你应该如何释放 pa.

```C++
int *pa = new int[10];
```

`delete[] pa;`

## 12.2.2 节练习

### [练习 12.26](ex12_26.cpp)

### 练习 12.27 [Test](ex12_27_30_test.cpp) [TextQuery](ex12_27_30.h) [QueryResult](ex12_27_30.h)

### [练习 12.28](ex12_28.cpp)

### 练习 12.29

> 用 `do while` 重写 `runQueries()`。解释你倾向于哪个版本。

`do while`。

```C++
void runQueries(std::ifilestream &ifs) {
    TextQuery tq(ifs);
    do {
        std::cout << "enter word to query or q to quit: ";
        std::string s;
        if (!(std::cin >> s) || s == "q") {
            break;
        }
        print(std::cout, tq.query(s));
    } while(true);
}
```

## 12.3.2 节练习

### 练习 12.30 同练习12.27 [Header](ex12_27_30.h) [Implementation](ex12_27_30.cpp) [Test](ex12_27_30_test.cpp)

### 练习 12.31

> 如果用 vector 代替 set 保存行号，会有什么差别。

`vector` 没有去重的功能。需要手动去重。

### 练习 12.32

### 练习 12.33







