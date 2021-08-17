### 2.1.1 节练习
##### Exercise 2.1
> int、long、long long以及short的区别是什么？无符号和带符号类型的区别是什么？float和double的区别是什么？

1. `int`、`long`、`long long`以及`short`占用的字节数不同，能表示的范围不同。short <= int <= long <= long long
2. 无符号只能表示非负整数，带符号类型能表示非负整数，不要混用无符号类型以及带符号类型。
3. 精度不同，一般不会使用`float`。
```C++
int main()
{
    // 0.33333334
    // 0.33333333333333331483
    // 0.33333333333333331483
    float x1       = 1.0 / 3;
    double x2      = 1.0 / 3;
    long double x3 = 1.0 / 3;
    printf("%.8f\n", x1);
    printf("%.20lf\n", x2);
    printf("%.20Lf\n", x3);
    return 0;
}
```

##### Exercise 2.2
> 计算按揭贷款时，利率、本金和贷款选用什么数据类型？

利率、本金和贷款都需要用小数形式保存，因此选用`double`类型


### 2.1.2 节练习
##### Exercise 2.3
> 读程序，写结果。
```C++
    unsigned u = 10, u2 = 42;
    cout << u2 - u << endl;  // 32
    cout << u - u2 << endl;  // 4294967264

    int i_ = 10, i2 = 42;
    cout << i2 - i_ << endl;  // 32
    cout << i_ - i2 << endl;  // -32
    cout << i_ - u << endl;   // 0
    cout << u - i_ << endl;   // 0
```

##### Exercise 2.4
> 编写练习2.3中的程序，验证结果。

```
32
4294967264
32
-32
0
0
```


### 2.1.3 节练习
##### Exercise 2.5
> 指出下列字面值的数据类型。
> 1. 'a', L'a', "a", L"a"
> 2. 10, 10u, 10L, 10UL, 012, 0xc
> 3. 3.14, 3.14f, 3.14L
> 4. 10, 10u, 10., 10e-2

1. char, wchar_t, char数组, wchar_t数组
2. int, unsigned, long, unsigned long, int, int
3. double, float, long double
4. int, unsigned, double, double

##### Exercise 2.6
> 下列两组定义是否有区别。
> int month = 9, day = 7;
> int month = 09, day = 07;

day的定义没有区别，结果都是7，但是`month = 09`会报错。

##### Exercise 2.7
> 下列字面值表示何种含义？它们各自的数据类型是什么？
> (a)"Who goes with F\145rgus?\012"
> (b)3.14e1L (b)1024f (c)3.14L

(a)"Who goes with Fergus?\n" char数组
(b)3.14 long double
(c)1024.0 float
(d)3.14 long double

##### Exercise 2.8
> 利用转义序列编写程序，先输出2M，然后换到新的一行。
> 修改程序，使其先输出2，然后输出制表符，再输出M，最后换到新的一行。

```C++
int main()
{
    cout << "\x32\x4D\n";
    cout << "\x32\t\x4D\n";

    return 0;
}
```


### 2.2.1 节练习
##### Exercise 2.9
> 解释下列定义的含义。对于非法的定义进行修改。
> (a)std::cin >> int input_value;
> (b)int i_ = { 3.14 };
> (c)double salary = wage = 9999.99; 
> (d)int i_ = 3.14;

(a)int input_value; std::cin >> input_value;
(b)int i_ = { 3 }; 存在丢失信息的风险
(c)double wage = 9999.99, salary = wage;
(d)i等于3，double转化为int，忽略小数部分。

##### Exercise 2.10
> 下列变量的初值分别是什么？
> std::string global_str;
> int global_int;
> int main() {
>   int local_int;
>   std:string local_str;
> }

global_str ""
global_int 0
local_int undefined value
local_str "", 默认初始化


### 2.2.2 节练习
##### Exercise 2.11
> 指出下列语句是定义还是声明。
> (a)extern int ix = 1024;
> (b)int iy;
> (c)extern int iz;

(a)定义
(b)定义
(c)声明


### 2.2.3 节练习
##### Exercise 2.12
> 请指出下列哪些名字是非法的？
```
(a) int double = 3.14;
(b) int _;
(c) int catch-22;
(d) int 1_or_2 = 1;
(e) double Double = 3.14;
```

(a) 与关键字重名
(c) 出现非法字符-
(d) 不能以数字开头


### 2.2.4 节练习
##### Exercise 2.13
> 下面程序中j的值是多少
```C++
int i_ = 42;
int main()
{
    int i_ = 100;
    int j = i_;
}
```

100，嵌套作用域中若存在同名变量，内层变量会屏蔽外层变量。

##### Exercise 2.14
> 下面的程序合法吗，如果合法会输出什么？
```C++
int i_ = 100, sum = 0;
for (int i_ = 0; i_ != 10; ++i_)
    sum += i_;
std::cout << i_ << " " << sum << std::endl;
```

合法，输出为```100 45```
因为for循环中的变量i生命周期仅限于for循环，因此输出的实际上是外层的i


### 2.3.1 节练习
##### Exercise 2.15
> 下面哪个定义是不合法的？
```
(a) int ival = 1.01;
(b) int &rval1 = 1.01;
(c) int &rval2 = ival;
(d) int &rval3;
```

(b) 引用不能指向字面值（除了const引用）
(d) 引用必须初始化

##### Exercise 2.16
> 下面哪些赋值是不合法的？为什么？
```
int i_ = 0, &r1 = i_; double d = 0, &r2 = d;
(a) r2 = 3.14159;
(b) r2 = r1;
(c) i_ = r2;
(d) r1 = d;
```

(a) 合法，让d等于3.14159
(b) 合法，发送自动转换，此时d = r2 = 0.0
(c) 合法，double赋值给int
(d) 合法，double赋值给int

##### Exercise 2.17
> 执行下面的代码段，会输出什么结果？
```C++
int i_, &ri = i_;
i_ = 5; ri = 10;
std::cout << i_ << " " << ri << std::endl;
```

`10 10`


### 2.3.2 节练习
##### Exercise 2.18
> 编写代码分别更改指针的值以及指针指向对象的值。

```C++
int num = 0, num2 = 1, *p = &num;
p = &num2; // 修改指针的值
*p = 3;  // 修改指针指向对象的值
```

##### Exercise 2.19
> 说明指针和引用的主要区别。

- 指针是一个对象，可以对其进行赋值和拷贝等操作；引用不是对象，无法进行赋值、拷贝操作。
- 引用必须初始化，指针不强制要求初始化，但建议初始化。
- 引用初始化后，之后的操作实际上都是在绑定的对象上进行操作

##### Exercise 2.20
> 请叙述下面这段代码的作用
```C++
int i_ = 42;
int *p1 = &i_; *p1 = *p1 * *p1;
```

对i进行平方操作

##### Exercise 2.21
> 请解释下列定义
```
int i_ = 0;
(a) double* dp = &i_;
(b) int *ip = i_;
(c) int *p = &i_;
```

(a) 非法，double *指针必须指向double
(b) 非法，不能使用int变量初始化指针，必须使用`&`或者同类型的指针
(c) 合法

##### Exercise 2.22
> 假设p是一个int型指针，说明下列代码的含义。
```C++
if (p) // 判断p是否是空指针
if (*p) // 判断p指向的值是否为0
```

##### Exercise 2.23
> 给定一个指针，你是否能知道它是否指向一个合法的对象？

不能

##### Exercise 2.24
> 下面代码为什么`p`合法而`lp`非法？
```C++
int i_ = 42;
void *p = &i_;
long *lp = &i_;
```

```void *型指针```可以指向任何类型的对象，而```long *型指针```只能指向long类型的对象


### 2.3.3 节练习
##### Exercise 2.25
> 说明下列变量的类型和值。
```C++
(a) int* ip, i_, &r = i_;
(b) int i_, *ip = 0;
(c) int* ip, ip2;
```

(a)ip: int *,  i_: int, r: int &;
(b)i_: int, ip: int *;
(c)ip: int*, ip2: int;


### 2.4.1 节练习
##### Exercise 2.26
> 下面哪些句子是合法的？
```C++
const int buf;      // 非法, const对象必须初始化
int cnt = 0;        // 合法
const int sz = cnt; // 合法
++cnt;              // 合法
++sz;               // 非法，const对象的值不允许改变
```


### 2.4.2 节练习
##### Exercise 2.27
> 下面哪些初始化是合法的？
```C++
(a)int i_ = -1, &r = 0;         
(b)int *const p2 = &i2;        
(c)const int i_ = -1, &r = 0;   
(d)const int *const p3 = &i2;  
(e)const int *p1 = &i2;        
(f)const int &const r2;        
(g)const int i2 = i_, &r = i_;    
```

(a)非法，非常量引用不能引用字面值常量。
(b)合法，因为p2是常量指针，所以p2永远指向变量i2
(c)合法
(d)合法
(e)合法
(f)不合法，引用不存在const
(g)合法
##### Exercise 2.28
> 说明下面的定义是什么意思，挑出其中合法的。
```C++
(a)int i_, *const cp;       
(b)int *p1, *const p2;     
(c)const int ic, &r = ic;  
(d)const int *const p3;    
(e)const int *p;          
```

(a)不合法，常量指针cp必须初始化
(b)不合法，常理指针p2必须初始化
(c)不合法，常量ic必须初始化
(d)不合法，常量指针p3必须初始化
(e)合法，一个指向常量int的指针p

##### Exercise 2.29
> 假设已有上一个练习中定义的变量，则下面哪些语句是合法的？
```C++
(a)i_ = ic;     
(b)p1 = p3;    
(c)p1 = &ic;   
(d)p3 = &ic;   
(e)p2 = p1;    
(f)ic = *p3;   
```

(a)合法
(b)非法，p1是指向非常量的指针，而p3指向常量
(c)非法，ic是常量对象，必须使用指向常量的指针
(d)非法，p3是一个常量指针，不能被赋值
(e)非法，p2是一个常量指针，不能被赋值。
(f)非法，ic是一个常量对象，不能被赋值。


### 2.4.3 节练习
##### Exercise 2.30
> 下列语句中的对象是顶层const还是底层const？
```C++
const int v2 = 0; int v1 = v2;
int *p1 = &v1, &r1 = v1;
const int *p2 = &v2, *const p3 = &i_, &r2 = v2;
```

v2是顶层const，p2是底层const，p3既是顶层const又是底层const，r2是底层const

##### Exercise 2.31
> 假设已有上一个练习中声明的变量，则下面哪些语句合法？请说明顶层const与底层const在语句中的作用。
```C++
(a)r1 = v2; 
(b)p1 = p2; 
(c)p2 = p1; 
(d)p1 = p3; 
(e)p2 = p3; 
```

(a)合法，v2是顶层const，可以赋值给普通变量。
(b)非法，p2是指向常量的指针（底层const），不能赋值给普通指针。
(c)合法，p1是普通指针，p2是指向常量的指针(底层const)，p1可以转化成指向常量的指针。
(d)非法，p3是指向常量的指针(底层const)，不能赋值给普通指针。
(e)合法，p2和p3都是指向常量的指针，而p3还是一个常量指针，可以赋值给普通指针。


### 2.4.4 节练习
##### Exercise 2.32
> 下面的代码是否合法？
```C++
int null = 0, *p = null;
```
```C++
// 修改
int null = 0, *p = &null;
int null = 0, *p = nullptr;
```

非法，不能使用`int型变量`初始化`int *型指针`


### 2.5.2 节练习
##### Exercise 2.33
> 利用本节定义的变量，判断下列语句的运行结果。
```
a=42; // a是一个int型变量，被赋值为42
b=42; // b是一个int型变量，被赋值为42
c=42; // c是一个int型变量，被赋值为42 
d=42; // d是一个int型指针，不能用字面值42赋值
e=42; // d是一个指向const int的指针，不能用字面值42赋值
g=42; // g是一个const int型引用，不能被赋值
```

##### Exercise 2.34
> 基于上一个练习中的变量和语句，编写一段程序，验证结果。
```C++
int main()
{
    int i_ = 0, &r = i_;
    auto a = r;  // int

    const int ci = 0, &cr = ci;
    auto b  = ci;   // int
    auto c  = cr;   // int
    auto d  = &i_;   // int *
    auto e  = &ci;  // const int *
    auto &g = ci;   // const int &

    a = 42;
    b = 42;
    c = 42;
    // d = 42;
    // e = 42;
    // g = 42;

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
    cout << e << endl;
    cout << g << endl;
    return 0;
}
```

##### Exercise 2.35
> 判断下列定义推断出的类型是什么。
```C++
const int i_ = 42;
auto j = i_;
const auto &k = i_; 
auto *p = &i_; 
const auto j2 = i_, &k2 = i_;
```

int j
const int &k
const int *p，注意auto p = &i与auto *p = &i的作用一致
const int j2, const int &k2


### 2.5.3 节练习
##### Exercise 2.36
> 请指出下面变量的类型以及代码结束时的值。
```C++
int a = 3, b = 4;
decltype(a) c = a;  // int c = a
decltype((b)) d = a;  // int &d = a
++c;
++d;
```
代码结束时，d = a = 4, c = 4, b= 4

##### Exercise 2.37
> 请指出下面代码中每个变量的类型和值。
```C++
int a = 3, b = 4;
decltype(a) c = a;  // int c = a
decltype(a = b) d = a;  // int & d = a
```
a = 3, b = 4, c = 3, d = 3

##### Exercise 2.38
> 说明decltype指定类型和auto指定类型有什么区别。举一个decltype指定类型和auto指定类型一样的例子，再举一个不一样的例子。

- decltype指定类型不会用表达式的值初始化变量，而auto会。
- decltype不会忽略变量的顶层const，而auto会。
- decltype推断的变量类型与表达式形式密切相关。

```C++
int main()
{
    int i_        = 0;
    const int ci = 0;

    decltype(i_) a1 = 0;  // int a1
    auto a2        = i_;  // int a2

    decltype(ci) b1 = 0;   // const int b1
    auto b2         = ci;  // int b2
}
```


### 2.6.1 节练习
##### Exercise 2.39
> 编译下面的程序，注意如果忘记写类定义体后面的分号，会发生什么情况？
```C++
struct Foo{}
int main()
{
    return 0;
}
```

`error: expected ';' after struct definition`

##### Exercise 2.40
> 根据自己的理解写出Sales_data类。
```C++
struct Sales_data
{
    std::string bookId;
    unsigned unitsSold;
    double price;
};
```


### 2.6.2 节练习
##### Exercise 2.41
> 使用Sales_data类重写1.5.1、1.5.2以及1.6节的练习。
- 1.5.1 节
```C++
// 读取一条记录，并输出
struct Sales_data
{
    std::string bookId;
    unsigned unitsSold = 0;
    double revenue     = 0.0;
};

int main()
{
    Sales_data record;
    double price;
    std::cin >> record.bookId >> record.unitsSold >> price;
    record.revenue = record.unitsSold * price;
    std::cout << record.bookId << " " << record.unitsSold << " " << record.revenue << std::endl;
    return 0;
}
```
- 1.5.2 节
```C++
// 读取两条具有相同ISBN号的记录，进行合并
struct Sales_data
{
    std::string bookId;
    unsigned unitsSold = 0;
    double revenue     = 0.0;
};

int main()
{
    Sales_data record1, record2;
    double price1, price2;
    std::cin >> record1.bookId >> record1.unitsSold >> price1;
    std::cin >> record2.bookId >> record2.unitsSold >> price2;
    record1.revenue = record1.unitsSold * price1;
    record2.revenue = record2.unitsSold * price2;

    if (record1.bookId == record2.bookId)
    {
        Sales_data record;
        record.bookId    = record1.bookId;
        record.revenue   = record1.revenue + record2.revenue;
        record.unitsSold = record1.unitsSold + record2.unitsSold;
        std::cout << record.bookId << " " << record.unitsSold << " " << record.revenue << std::endl;
        return 0;
    }
    else
    {
        std::cerr << "Data must refer to same ISBN" << std::endl;
        return -1;
    }
}
```
- 1.6 节
```C++
// 书店程序
struct Sales_data
{
    std::string bookId;
    unsigned unitsSold;
    double revenue;
};

int main()
{
    Sales_data total;
    double price;
    if (std::cin >> total.bookId >> total.unitsSold >> price)
    {
        Sales_data record;
        total.revenue = total.unitsSold * price;
        while (std::cin >> record.bookId >> record.unitsSold >> price)
        {
            record.revenue = record.unitsSold * price;
            if (record.bookId == total.bookId)
            {
                total.unitsSold += record.unitsSold;
                total.revenue += total.revenue;
            }
            else
            {
                std::cout << total.bookId << " " << total.unitsSold << " " << total.revenue
                          << std::endl;
                total.bookId    = record.bookId;
                total.unitsSold = record.unitsSold;
                total.revenue   = record.revenue;
            }
        }
        std::cout << total.bookId << " " << total.unitsSold << " " << total.revenue << std::endl;
        return 0;
    }
    else
    {
        std::cerr << "No data?" << std::endl;
        return -1;
    }
}
```


### 2.6.3 节练习
##### Exercise 2.42
> 重写Sales_data.h的头文件，重做2.6.2 节的练习。
- Sales_data.h
```C++
#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>

struct Sales_data
{
    std::string bookId;
    unsigned unitsSold;
    double price;
};
#endif
```