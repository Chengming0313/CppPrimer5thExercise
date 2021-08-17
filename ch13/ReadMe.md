# C++ Primer 5th 第十二章 习题

## 13.1.1 节练习

### 练习 13.1

> 拷贝构造函数是什么。什么时候使用它。

拷贝构造函数是一种特殊的构造函数，它的第一个参数是自身类类型的引用(通常为 T const &), 而且其它的参数（如果有的话）都有默认值.

以下场景可能会使用到拷贝构造函数.
- 用 = 定义变量（拷贝初始化）
- pass by value（将一个对象作为实参传递给非引用类型的形参）
- return by value（一个返回类型为非引用类型的函数返回一个对象）
- 用花括号列表初始化一个数组或者一个聚合类中的元素。
- 初始化标准库容器, 或者调用它的push/insert操作。

### 练习 13.2

> 解释为什么下面的声明非法

```c++
Sales_data::Sales_data(Sales_data rhs);
```

拷贝构造函数的第一个参数类型必须为引用。如果为非引用类型，我们对拷贝构造函数的调用永远也不会成功。
因为当我们将某个对象作为实参传给拷贝构造函数时，需要调用拷贝构造函数，这导致了死循环。

### 练习 13.3

> 当我们拷贝一个 StrBlob 时, 会发生什么, 拷贝一个 StrBlobPtr呢.

StrBlob, StrBlobPtr 都没有定义拷贝构造函数, 编译器为它们定义了合成的拷贝构造函数.
合成的拷贝构造函数, 逐个拷贝对象的非 static 成员, 内置类型的成员直接进行内存拷贝, 类类型的成员调用它的拷贝构造函数进行拷贝.
StrBlob 只有一个 shared_ptr<>类型的成员, 因此会调用 shared_ptr<> 的拷贝构造函数, 引用计数加1.
StrBlobPtr 包括一个 weak_ptr<> 的成员以及一个内置类型的成员, 因此会发生 weak_ptr<> 的拷贝构造函数和内存拷贝.

```c++

```

### 练习 13.4 

> 假定 Point 是一个类类型, 它有一个 public 的拷贝构造函数. 指出下面那些程序片断中那些地方使用了拷贝构造函数.

```c++
Point global;
// 1. pass by value, return by value
Point foo_bar(Point arg) {
    // 2. local, heap 的定义
    Point local = arg, *heap = new Point(global);
    *heap = local;
    // 3. pa 的定义
    Point pa[ 4 ] = { local, *heap };
    return *heap;
}
```

### [练习 13.5](ex13_05_08_11_22.cpp)

> 给定下面的类框架, 编写一个拷贝构造函数, 拷贝所有成员。
> 你的拷贝构造函数应该动态分配一个新的 string。并将对象拷贝到 ps_ 指向的位置. 而不是拷贝 ps_ 本身。

```c++
class HasPtr {
public:
    HasPtr(const std::string &s = std::string())
        : ps_(new std::string(s)), i_(0) {}
private:
    std::string *ps_;
    int i_;
};
```

## 13.1.2 节练习

### 练习 13.6

> 拷贝赋值运算符是什么. 什么时候使用它. 合成拷贝赋值运算符完成什么作用. 什么时候会生成合成拷贝赋值运算符.

拷贝赋值运算符是一个重载了赋值运算符的函数, 通常返回指向左侧对象的引用.

当对类对象进行赋值时，会使用拷贝赋值运算符. 

合成的拷贝赋值运算符会将非 static 成员通过拷贝赋值运算符或者拷贝内存逐个赋值给左侧对象对应的成员. 有事我们也可以通过 `=delete` 禁止该类型对象的赋值操作.

若一个类没有定义自己的拷贝赋值运算符，编译器会为其自动生成合成的拷贝赋值运算符.

### 练习 13.7

> 将一个 StrBlob 赋值给另一个 StrBlob, 会发生什么. 赋值 StrBlobPtr 呢.

StrBlob 以及 StrBlobPtr 都没有定义自己的拷贝赋值运算符. 因此编译器会为它们生成合成的拷贝赋值运算符.

与之前的拷贝构造函数行为类似, 区别在于一个是赋值, 一个是初始化, 因此成员使用到的函数不一样, 执行的操作不一样.

### [练习 13.8](ex13_05_08_11_22.cpp)

> 为 13.1.1 节的 HasPtr 类编写赋值运算符. 类似拷贝运算符, 不应该拷贝 ps_, 应该拷贝 ps_ 指向的对象.

## 13.1.3 节练习

### 练习 13.9

> 析构函数是什么. 合成析构函数完成什么工作. 什么时候生成合成析构函数.

析构函数是类的一个成员函数，没有返回值，也没有形参，函数名为波浪号接类名.

合成析构函数的函数体为空, 当空函数体执行完毕(析构阶段)后, 非静态数据成员会被逐个销毁. 合成析构函数通过指定`=delete`禁止销毁该类对象.

当一个类没有定义析构函数时, 或者指定`=default`, 编译器会为它生成合成析构函数.

### 练习 13.10

> 当一个 StrBlob 对象销毁时会发生什么. StrBlobPtr 销毁呢.

StrBlob, StrBlobPtr 都没有定义析构函数, 因此编译器会为它们生成合成析构函数.
合成析构函数体为空, 在析构阶段销毁对象时, 数据成员的析构函数会被调用.

### [练习 13.11](ex13_05_08_11_22.cpp)

> 为 HasPtr 添加一个析构函数.

### 13.12

> 在下面的代码片断中会发生几次析构函数调用.

```c++
bool fcn(const Sales_data *trans, Sales_data accum) {
    Sales_data item1(*trans), item2(accum);
    return item1.isbn() != item2.isbn();
}
```

3 次, accum, item1, item2 各1次.

### 练习 13.13 [Demo](ex13_13.cpp)

> 理解拷贝控制成员和构造函数的一个好方法是定义一个简单的类, 为该类定义这些成员, 每个成员都打印出自己的名字. 
> 为 X 添加拷贝赋值运算符和析构函数. 并编写一个程序以不同的方式使用X的对象: 
> 将它们作为非引用和引用参数传递, 动态分配它们, 将它门放于容器中. 诸如此类.
> 观察程序的输出, 记住编译器可以略过对拷贝构造函数的调用.

```c++
struct X {
    X() {std::cout << "X()" << std::endl;}
    X(X const &) {std::cout << "X(X const &)" << std::endl;}
};
```

## 13.1.4 节练习

### 练习 13.14

> 假定 numbered 是一个类, 它有一个默认构造函数, 能为每个对象生成一个唯一的序号, 保存在名为 mysn 的数据成员中. 
> 假定 numbered 使用合成的拷贝控制成员, 并给定如下函数.
```c++
void f(numbered s) {cout << s.mysn << endl;}
```
> 则下面代码输出什么内容.
```c++
numbered a, b = a, c = b;
f(a);
f(b);
f(c);
```

合成的拷贝控制函数只是简单的拷贝非static数据成员，因此`a, b, c`的`mysn`相同。
同时`f`的形参`s`与实参的`mysn`也相同，因此会输出3个相同的序号.

### 练习 13.15

> 假定 numbered 定义了一个拷贝构造函数, 能生成新的序号. 这会改变上一题中的输出吗.

会输出3个不同的序号，但这3个序号与`a, b, c`的序号不同。此时存在 6 个序号, 对应 6 次 `copy ctor` 的调用.

### 练习 13.16

> 如果 f 中的参数是 const numbered &, 将会怎样.

输出 3 个不同序号, 对应着`a, b, c`的序号。因为`f`的形参不再是非引用类型，不会调用`copy ctor`。

### [练习 13.17](ex13_17.cpp)

> 编写前3题所描述的numbered和f，验证你是否正确预测了输出结果。

## 13.1.6 节练习

### [练习 13.18](ex13_18_19_Employee.cpp)

> 定义一个Employee类. 它包含雇主的姓名和唯一的雇员证号. 为这个类定义默认构造函数, 以及接受一个表示雇员姓名的string的构造函数. 每个构造函数应该通过递增一个static数据成员来生成唯一的证号.

### [练习 13.19](ex13_18_19_Employee.cpp)

> 你的Employee需要定义它自己的拷贝控制成员吗。

需要定义`copy ctor`以及`copy op=`，因为合成的拷贝构造函数行为不符合预期（序号与rhs相同），合成的拷贝赋值运算符行为不符合预期（序号会被rhs覆盖）。
而析构函数不需要自己定义，因为不需要释放额外的资源。

### 练习 13.20 [TextQuery](../ch12/ex12_27_30.h) [QueryResult](../ch12/ex12_27_30.h)

> 解释当我们拷贝, 赋值或销毁TextQuery, QueryResult类对象, 会发生什么.
```c++
class TextQuery {
    // ...
    using line_no = std::vector<std::string>::size_type;
private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

class QueryResult {
    // ...
private:
    std::string sought;
    std::shared_ptr<std::set<line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};
```

TextQuery
    拷贝构造: 使用合成的`copy ctor`, 
        file: 调用 shared_ptr 的拷贝构造, 引用计数加1. 
        wm: 首先调用 map 的拷贝构造函数, map 里接着调用string, shared_ptr的拷贝构造函数
    拷贝赋值: 使用合成的`copy op=`
        file: 调用 shared_ptr 的拷贝赋值, 原先的引用计数减1，新的引用计数加1
        wm: 调用 map 的`copy op=`, 进而调用 string, shared_ptr 的拷贝赋值
    析构：
        file: 引用数减1, 判断是否需要对 vector 进行析构
        wm: 调用 map 的析构函数, 进而调用 string, shared_ptr 的析构函数
QueryResult
    copy ctor: 合成
        sought: 调用 `std::string` 的拷贝构造函数, 深拷贝.
        lines: 调用 `std::shared_ptr` 的 copy ctor, 对应的 `std::set` 的引用计数加1.
        file: 与 lines 差不多.
    copy op=: 合成
        sought: 调用 `std::string` 的 copy op=, 深拷贝，需要先释放旧内存.
        lines: 调用 `std::shared_ptr`的 copy op=, 旧 set 引用计数减1， 新 set 引用计数加1.
        file: 与 lines 差不多.
    dtor: 合成
        sought: 调用 `std::string` 的 dtor
        lines: 调用 `std::shared_ptr` 的 dtor, 引用计数减1，如果为0，释放成员变量(std::set)
        file: 调用 `std::shared_ptr` 的 dtor, 引用计数减1，如果为0，释放成员变量(std::vector)


### 练习 13.21

> 你认为TextQuery和QueryResult类需要定义它们自己版本的拷贝控制成员吗.

不需要, 它们使用**智能指针**以及**标准库容器**来管理数据, 合成的拷贝控制函数即可保证资源的正确管理.

## 13.2 节练习

### [练习 13.22](ex13_05_08_11_22.cpp)

> 使HasPtr的行为像一个值（深拷贝）。

练习 13.5, 13.8, 13.11 已经完成了`copy ctor, copy op=, dtor`的定义, 我们只需要添加几个功能函数，即可.

## 13.2.1 节练习

### 练习 13.23

> 比较你编写的 HasPtr 和书上的差异.

### 练习13.24

> 如果 HasPtr 没有定义析构函数, 会发生什么. 没有定义拷贝构造函数, 会发生什么.

没有定义析构函数, 会发生内存泄漏. ps_ 被释放, 但是 ps_ 指向的空间不会被释放.
没有定义拷贝构造函数, 多个 ps_ 指向同一块内存, 当其中的某个HasPtr销毁时，导致其它的 ps_ 指向 已经销毁的对象，出现悬挂指针，可能 delete 已经释放的空间.

### [练习 13.25](ex13_25_26.cpp)

> 定义 StrBlob 的类值版本. 继续使用 shared_ptr 管理数据. 
> 为什么要自己定义 copy ctor, copy op=. 
> 为什么不要自己定义 dtor.

- `shared_ptr` 中的 `copy ctor`, `copy op=` 不会分配新的内存, 多个 `shared_ptr` 指向同一份内存.
- `shared_ptr` 实现了引用计数, `shared_ptr` 中的 `dtor` 会自动释放内存, 不需要手动释放.

### [练习 13.26](ex13_25_26.cpp)

## 13.2.2 节练习

### [练习 13.27](ex13_27.cpp)

> 定义你自己的使用引用计数版本的 HasPtr.

### [练习 13.28](ex13_28.cpp)

## 13.3 节练习

### 练习 13.29

> 解释 swap(HasPtr &, HasPtr &) 中对 swap 的调用不会导致递归循环.

```c++
void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;
    swap(lhs.ps_, rhs.ps_); // ps_: string *
    swap(lhs.i_, rhs.i_);   // i_: int
}
```

`ps_` 为 string * 类型, `i_` 为 int 类型, 这里的 swap 为 std::swap, 因此不会导致递归循环.

### [练习 13.30](ex13_30_31.cpp)

### [练习 13.31](ex13_30_31.cpp)

### 练习 13.32

> 类指针的 HasPtr 版本需要自己实现 swap 函数吗.

类指针版本的 HasPtr 不需要自己实现 swap.

```c++
// std::wap 流程
auto temp = v1; // copy ctor
v1 = v2; // copy op=
v2 = temp; // copy op=
```

类指针版本的 HasPtr : ps_[std::string *], use[std::size_t *], i_[int]
类值版本的 HasPtr : ps_[std::string *], i_[int]

类值版本的 HasPtr 的 `copy ctor` 以及 `copy op=` 会发生动态内存的分配与释放, 
因此自定义 swap 可以避免 `copy ctor` 以及 `copy op=` 导致的内存操作, 提升性能.

而类指针版本的 HasPtr 的 `copy ctor` 以及 `copy op=` 不会导致动态内存的分配与释放, 因此自定义 swap 意义不大.

## 13.4 节练习

### 练习 13.33

> 为什么 Message 的成员 save 和 remove 的参数是一个 `Folder &`.
> 为什么不将它定义为 `Folder` 或者 `Folder const &`.

```c++
void save(Folder &);

void remove(Folder &);
```

因为 `save, remove` 需要对传入的参数进行修改, 因此只能是 `Folder &`.

### 练习 13.34 [Header](ex13_34_36_Message.h) [Implementation](ex13_34_36_Message.cpp)

### 练习 13.35

> 如果 Message 使用合成的拷贝控制成员, 将会发生什么.

如果 Message 使用合成的拷贝控制成员, 这会导致 Folder 与 Message 的关系混乱.

- 拷贝初始化时, Folder 不会添加相应的 Message.
- 拷贝赋值时, 之前相关的 Folder 不会移除 lhs 记录, 新的 Folder 不会添加 lhs 的记录.
- 析构时, 相关的 Folder 不会移除 message 的记录.

### 练习 13.36 [Header](ex13_36_Folder.h) [Implementation](ex13_36_Folder.cpp) [Demo](ex13_MessageFolderDemo.cpp)
> 实现Folder

### 练习 13.37 [Header](ex13_34_37_Message.h) [Implementation](ex13_34_37_Message.cpp) [Demo](ex13_MessageFolderDemo.cpp)

> 为Message类添加成员，实现向folders添加或删除一个给定的Folder *

### 练习 13.38
> 为什么没用**拷贝和交换**实现Message的赋值运算符

因为通过`copy and swap`实现赋值运算符，需要3步：`copy ctor`, `swap`, `dtor`。
而Message赋值运算符免疫自赋值，不需要通过局部变量保存rhs状态，只需要 `copy ctor` 以及 `dtor`, 效率更高.

### 练习 13.39 [Header](ex13_39_StrVector.h) [Implementation](ex13_39_StrVector.cpp) [Demo](ex13_39_Demo.cpp)

> 编写StrVec, 实现`reserve`, `capacity`以及`resize`.

### 练习 13.40 [Header](ex13_39_StrVector.h) [Implementation](ex13_39_StrVector.cpp) [Demo](ex13_40_Demo.cpp)

> 为StrVec添加一个构造函数，它接受一个initializer_list参数.

### 练习 13.44 [Header](ex13_44_String.h) [Implementation](ex13_44_String.cpp) [Demo](ex13_44_demo.cpp)

> 编写`std::string`的简化类`String`，至少需要一个默认构造函数以及一个接受C风格字符串的构造函数。使用`allocator`为`String`分配内存。

## 13.6.1 节练习

### 练习 13.45

> 左值引用与右值引用有什么区别

**对象(object)**：存储某个类型值的内存块。

**变量(variable)**：有名字的对象。

**左值(lvalue)**：能够取地址的、有名字的值（存储单元内的值，有实际地址）。

**右值(rvalue)**: 不能取地址，没有名字（不是存储单元内的值，可能是寄存器内的值或者立即数）。

- 返回左值的表达式
    - 返回左值引用的函数
    - 变量表达式  
    - 前缀自增、自减
    - 赋值表达式
    - 下标
    - 解引用
    
- 返回右值的表达式
    - 返回非左值引用的函数
    - 后缀自增、自减
    - 算术运算
    - 关系运算
    - 位运算
    
- 之前提及的引用指的都是左值引用，它只能引用左值（**特例：常量引用能引用右值**），右值引用只能引用右值。

**参考资料**
- [汇编的角度理解左值、右值](https://www.zhihu.com/question/46599246/answer/102830868)
- [理解C++ 右值左值等名词的关键——move](https://mp.weixin.qq.com/s/FVLKbDn2vmAj5tKbnmWzxg)

### 练习13.46

> 什么类型的引用可以绑定到下面的初始化器

```c++
int f();                    
vector<int> vi(100);        
int? r1 = f();              // 右值引用：f() 返回非左值引用
int? r2 = vi[0];            // 左值引用：下标表达式返回左值
int? r3 = r1;               // 左值引用：r1 是变量，返回左值
int? r4 = vi[0] * f();      // 右值引用：算术运算返回右值
```

### [练习 13.47](ex13_47_String.h)

### 练习 13.48 [Demo](ex13_48_demo.cpp)

> 定义一个`vector<String>`并在其上多次调用`push_back`。运行程序观察`String`被拷贝了多少次

push_back 5 次, copy ctor 会被调用 5 + (1 + 2 + 4) = 12 次

```c++
String s1("1");
String s2("2");
String s3("3");
String s4("4");
String s5("5");

std::vector<String> strVec;

strVec.push_back(s1);
strVec.push_back(s2);
strVec.push_back(s3);
strVec.push_back(s4);
strVec.push_back(s5);
std::cout << "size: " << strVec.size() << " capacity: " << strVec.capacity() << std::endl;
```

```c++ 输出
copy ctor: 1
copy ctor: 2
copy ctor: 1
copy ctor: 3
copy ctor: 1
copy ctor: 2
copy ctor: 4
copy ctor: 5
copy ctor: 1
copy ctor: 2
copy ctor: 3
copy ctor: 4
size: 5 capacity: 8
```

## 13.6.2 节练习

### 练习 13.49 
> 为 StrVec, Message, String 添加 move ctor, move op=.

StrVec: [Header](ex13_39_StrVector.h) [Implementation](ex13_39_StrVector.cpp)
Message: [Header](ex13_34_37_Message.h) [Implementation](ex13_34_37_Message.cpp)
Folder: [Header](ex13_36_Folder.h) [Implementation](ex13_36_Folder.cpp)
String: [Header](ex13_44_String.h) [Implementation](ex13_44_String.cpp)

> 为你的 StrVec, Message, Folder 添加一个移动构造函数和一个移动赋值运算符.

### [练习 13.50](ex13_48_demo.cpp)

> String 里为 move ctor 添加输出语句. 重新运行 ex13.48, 观察程序输出.

push_back 5 次, copy ctor 会被调用 5 次用来拷贝构造push_back的实参, move ctor 会被调用 1 + 2 + 4 = 7次用来在扩容中移动元素

```c++
String s1("1");
String s2("2");
String s3("3");
String s4("4");
String s5("5");

std::vector<String> strVec;
strVec.push_back(s1);
strVec.push_back(s2);
strVec.push_back(s3);
strVec.push_back(s4);
strVec.push_back(s5);
std::cout << "size: " << strVec.size() << " capacity: " << strVec.capacity() << std::endl;
```

```c++
copy ctor: 1
copy ctor: 2
move ctor: 1
copy ctor: 3
move ctor: 1
move ctor: 2
copy ctor: 4
copy ctor: 5
move ctor: 1
move ctor: 2
move ctor: 3
move ctor: 4
size: 5 capacity: 8
```

### 练习 13.51

> 为什么`unique_ptr`不能拷贝, 而`clone`函数是合法的，且能够正常工作。

```c++
unique_ptr<int> clone(int num) {
    unique_ptr<int> ret(new int(num));
    return ret;
}
```

`return ret`并不一定需要之前进行`copy ctor`，只有当下面两种情况不会发生时, 才会试图调用`copy ctor`。
- `copy elision`:
    ```c++
    A createA() {
        std::cout << "create A" << std::endl;
        return A();
    }
    
    int main(int argc, char const *argv[])
    {
        A a = createA();
    
        return 0;
    }
    ```
    ```c++
    create A
    ctor
    ```
- `move ctor`
    ```c++
    // 避免编译器优化(copy elision)
    A createA(bool test) {
        A a1, a2;
        if (test) {return a1;}
        else {return a2;}
    }

    int main(int argc, char const *argv[])
    {
        A a = createA(true);
    
        return 0;
    }
    ```
    ```c++
    ctor
    ctor
    move ctor from 0x61fddc to 0x61fe1c
    ```

### 练习 13.52

> 详细描述`p478`中`HasPtr`对象的赋值过程发什么了什么(hp, hp2, rhs)

```c++
// copy ctor
HasPtr(HasPtr const &rhs) : ps(new std::string(*rhs.ps), i(rhs.i) {}

// move ctor
HasPtr(HasPtr &&rhs) noexcept : ps(rhs.ps), i(rhs.i) {
    rhs.ps = nullptr;
}

// copy op=, move op=
HasPtr &operator=(HasPtr rhs) {
    swap(*this, rhs);
    return *this;
}

void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}
```

```c++
hp = hp2;
hp = std::move(hp2);
```

- `hp = hp2`，hp2是左值, 因此调用`copy ctor`初始化`copy op=`的形参`rhs`, 再交换`rhs`和`hp`，等价于`hp2`拷贝到`hp`。
- `hp = std::move(hp2)`，std::move(hp2)是右值, 因此调用`move ctor`初始化`move op=`的形参`rhs`, 再交换`rhs`和`hp`，等价于`hp2`移动到`hp`。

### 练习 13.53

> 从底层效率来看, 通过`copy and swap`实现的赋值运算符并不理想，解释为什么。自己为HasPtr实现移动赋值运算符，分析两个版本移动赋值运算符执行的操作区别。

```c++
// 方法一
// copy op=, move op=
HasPtr &operator=(HasPtr rhs) {
    swap(*this, rhs);
    return *this;
}

void swap(HasPtr &lhs, HasPtr &rhs) {
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

// 方法二
HasPtr &operator=(HasPtr &&rhs) {
    if (this != &rhs) {
        delete ps;
        ps = rhs.ps;
        i = rhs.i;
        rhs.ps = nullptr;
        rhs.i = 0;
    }
    return *this;
}
```

- 方法一
    - 移动构造 `rhs`
    - 交换 `this, rhs`
        - 交换 `ps`, 1 次初始化, 2 次赋值
        - 交换 `i`, 1 次初始化, 2 次赋值
    - 析构 `rhs`
    
- 方法二
    - `delete ps`
    - 4 次赋值
    
### 练习 13.54

> 如果我们定义了另一个版本的移动赋值运算符同时保留拷贝并交换实现的赋值运算符, 会发生什么.

当执行`hp = std::move(hp2)`会发生编译时错误, `error: ambiguous overload for 'operator=' (operand types are 'HasPtr' and 'std::remove_reference<HasPtr&>::type' {aka 'HasPtr'})`

## 13.6.3 节练习

### 练习 13.55

> 为StrBlob定义右值引用版本的push_back

```c++
void pushBack(std::string &&str) {
    data_->push_back(std::move(str));
}
```

### 练习 13.56
> 如果 sorted 定义如下, 会发生什么

```c++
Foo Foo::sorted() const &{
    Foo ret(*this);
    return ret.sorted();
}
```

`*this`是左值, 调用`copy ctor`初始化`ret`, `ret`也是一个左值。因此`ret.sorted()`会递归调用`Foo sorted() const &`，造成栈溢出.

### 练习 13.57
> 如果 sorted 定义如下, 又会发生什么

```c++
Foo Foo::sorted() const &{
    return Foo(*this).sorted();
}
```

可以完成预期操作(利用`Foo Foo::sorted() const &&`), 因为`Foo(*this)`是一个右值。

### [练习 13.58](ex13_58_demo.cpp) 

> 编写 Foo 验证练习 13.56、13.57 的结论





