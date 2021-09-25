# C++ Primer 5th 第十三章 习题

## 14.1 节练习

### 练习 14.1

> 在什么情况下，重载运算符与内置运算符有所区别？什么情况下重载运算符又与内置运算符保持一致。

- 区别
    - 重载运算符本质上是1个函数，因此可以直接通过`()`调用。内置运算符不可以。
    - 重载运算符的参数至少有1个类类型，不能全是内置类型。
    - 一些内置运算符能够保证运算对象的运算顺序，同时具有某些特殊的运算性质，例如短路求值。重载运算符不能保证运算对象的运算顺序以及运算性质。
    - 不是所有的内置运算符都能重载，进一步某些运算符也不建议重载。
- 相同点
    - 重载运算符与内置运算符的优先级与结合律相同。

### [练习 14.2](ex14_2_test.cpp)

> 为 Sales_data 编写输入、输出、加法、复合赋值运算符。

输入、输出必须实现为全局函数。 加法应该实现为全局函数。 复合赋值运算符应该实现为成员函数。

### 练习 14.3

> string 以及 vector 都重载了 == 来比较各自的对象。假设 svec1 以及 svec2 的类型都是 vector<string>。判断下面分别使用了哪个版本的 == 。

```c++
(a) "cobble" == "stone"
(b) svec1[0] == svec2[0]
(c) svec1 == svec2
(d) svec1[0] == "stone"
```

(a) 内置的 == 运算符，比较2个 `char const *`
(b) string 定义的 == 运算符。
(c) vector 定义的 == 运算符。
(d) string 定义的 == 运算符，`char const *`隐式转换为`string`。

### 练习 14.4

> 如何确定下列运算符是否应该实现为成员函数。

```c++
(a) % (b) %= (c) ++ (d) -> (e) << (f) && (g) == (h) ()
```

(a) 具有对称性的运算符，不应该
(b) 应该
(c) 应该
(d) 必须实现为成员函数
(e) 不应该
(f) 不应该重载 &&
(g) 具有对称性的运算符，不应该
(h) 必须实现为成员函数

### 练习 14.5

> 在 7.5.1 节的练习 7.40 中, 编写了下列类中某一个的框架，请问在这个类中应该定义重载的运算符吗？如果是，请写出来。

```c++
(a) Book (b) Date (c) Employee (d) Vehicle (e) Object (f) Tree
```

TODO

## 14.2.1 节练习

### [练习 14.6](ex14_2_test.cpp)

> 为你的 Sales_data 类定义输出运算符。

### 练习 14.7 [Header](../ch13/ex13_44_String.h) [Implementation](../ch13/ex13_44_String.cpp) [Demo](../ch13/ex14_7.cpp)

> 你在 13.5 节练习中曾经编写了一个 String 类, 为它定义一个输出运算符。

### [练习 14.8]()

> 你在 7.5.1 节练习中曾经选择并编写了一个类，为它定义一个输出运算符。

TODO

## 14.2.2 节练习

### [练习 14.9](ex14_2_test.cpp)

> 为你的 Sales_data 类定义输入运算符。

### 练习 14.10

> 对于 Sales_data 的输入运算符来说，如果给定了下面的输入将会发什么什么情况？

```c++
(a) 0-201-99999-9 10 24.95 (b) 10 24.95 0-210-99999-9
```

(a) bookNo = 0-201-99999-9, units_sold = 10, revenue = 249.5
(b) 出现输入错误, bookNo = "", units_sold = 0, revenue = 0.0

### 练习 14.11

> 下面的 Sales_data 输入运算符存在错误吗？如果有，请指出来。对于这个输入运算符如果仍给定上个练习的输入会发什么情况？

```c++
istream& operator>>(istream& in, Sales_data& s) {
double price;
in >> s.bookNo >> s.units_sold >> price;
s.revenue = s.units_sold * price;
return in;
}
```

没有处理输入错误的情况，当输入(b)时，bookNo = "10", units_sold = 24, price = 0.95, revenue = 22.8。

### 练习 14.12

> 你在 7.5.1 节的练习 7.40 中曾经选择并编写了一个类，为它定义一个输入运算符并确保该运算符可以处理输入错误。

TODO

## 14.3 节练习

### [练习 14.13](ex14_2_test.cpp)

> 你认为 Sales_data 还应该支持哪些其它算术运算符？如果有的话，请给出它们的定义。

减法运算符与对应的复合赋值运算符。

### 练习 14.14

> 你觉得为什么调用 operator+= 来定义 operator+ 比其它方法更有效。

- 首先通过调用 operator+= 来定义 operator+ 相比其它的实现方式，不会有性能损耗。
- 其次 operator+= 的执行语义包含在 operator+ 的执行语义中。

### [练习 14.15]()

> 你在 7.5.1 节的练习 7.40 中曾经选择并编写了一个类，你认为它应该含有其它算术运算符吗？如果是，请实现它们；如果不是，解释原因。

TODO

## 14.3.2 节练习

### [练习 14.16]()

> 为你的 StrBlob、StrBlobPtr、StrVec、和 String 分别定义相等运算符和不相等运算符。

TODO

### [练习 14.17]()

> 你在 7.5.1 节的练习 7.40 中曾经选择并编写了一个类，你认为它应该含有相等运算符和不相等运算符吗？如果是，请实现它们；如果不是，解释原因。

## 14.3.2 节练习

### [练习 14.18]()

> 为你的 StrBlob, StrBlobPtr, StrVec, String 定义关系运算符。

TODO

### 练习 14.19

> 你在 7.5.1 节的练习 7.40 中曾经选择并编写了一个类，你认为它应该含有关系运算符吗？如果是，请实现它们；如果不是，解释原因。

TODO

## 14.4 节练习

### [练习 14.20](ex14_2_test.cpp)

> 为你的 Sales_data 类定义加法和复合赋值运算符。

### 练习 14.21

> 编写 Sales_data 的 + 和 += 运算符，使得 + 执行实际的加法操作而 += 调用 +。相比于14.3节以及14.4节对这两个运算符的定义，本题的定义有何缺点。

```c++ "旧版本"
// 1次拷贝初始化 + 1次复合加法赋值
Sales_data operator+(Sales_data const &lhs, Sales_data const &rhs) {
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}

// 2次复合加法赋值
Sales_data &Sales_data::operator+=(Sales_data const &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}
```

```c++ "新版本"
// 1次初始化 + 2 次加法 + 3次赋值
Sales_data &operator+(Sales_data const &lhs, Sales_data const &rhs) {
    Sales_data sum;
    sum.bookNo = lhs.bookNo;
    sum.units_sold = lhs.units_sold + rhs.units_sold;
    sum.revenue = lhs.revenue + rhs.revenue;
    return sum;
}

// 1次加法 + 1次赋值
Sales_data &Sales_data::operator+=(Sales_data const &rhs) {
    *this = *this + rhs;
    return *this;
}
```

比起之前的定义，这种定义有着两个缺点。

- 代码更加繁琐。

- 性能损耗更大，+= 需要创建一个临时变量进行加法操作。

### [练习 14.22](ex14_2_Sales_data.h)

> 定义赋值运算符的一个新版本，使得我们能把一个表示 ISBN 的 string 赋给一个 Sales_data 对象。

### [练习 14.23]

> 为 StrVec 定义一个 initializer_list 赋值运算符。

TODO

### 练习 14.24

> 你在 7.5.1 节的练习 7.40 中曾经选择并编写了一个类，你认为它应该含有拷贝赋值运算符和移动赋值运算符吗？如果是，请实现它们；如果不是，解释原因。

TODO

### 练习 14.25

> 上题的这个类还需要定义其它赋值运算符吗？如果是，请实现它们。同时说明运算对象应该是什么类型并解释原因。

TODO

## 14.5 节练习

### 练习 14.26

> 为你的 StrBlob, StrBlobPtr, StrVec, String 定义下标运算符。

TODO

## 14.6 节练习

### 练习 14.27

> 为 StrBlobPtr 定义递增和递减运算符

### 练习 14.28

> 为 StrBlobPtr 定义加法和减法运算符，使其可以实现指针的算术运算。

### 练习 14.29

> 为什么不定义 const 版本的递增和递减运算符 ？

因为递增和递减运算符的语义会改变对象的状态，因此 const 对象应该禁止递增和递减运算。

## 14.7 节练习

### 练习 14.30

> 为 StrBlobPtr 和 ConstStrBlobPtr 分别添加解引用运算符和箭头运算符。注意：因为 ConstBlobPtr 的数据成员指向 const Vector，所以 ConstStrBlobPtr 中的运算符必须返回常量引用。

### 练习 14.31

> 我们的 StrBlobPtr 没有定义拷贝构造函数、赋值运算符以及析构函数。为什么？

### 练习 14.32

> 定义一个类令其含有指向 StrBlobPtr 对象的指针，为这个类重载箭头运算符。

## 14.8 节练习

### 练习 14.33

> 一个重载的函数调用运算符应该接受几个运算对象？

一个重载的函数调用运算符的形参数目与普通函数的的形参列表一致。例如函数`abs`与`absInt`中的`operator()`形参列表是相同的。

### [14.34](ex14_34_test.cpp)

> 定义一个函数对象类，令其执行 if-then-else 的操作：该类的调用运算符接受三个形参，它首先检查第一个形参，如果成功返回第二个形参的值；如果不成功返回第三个形参的值。

### 14.35 [Header](ex14_35_GetLine.h) [Test](ex14_35_test.cpp)

> 编写一个类似于 PrintString 的类，令其从 istream 中读取一行输入，然后返回一个表示我们所读内容的 string。如果读取失败，返回空 string。

### 14.36 [Test](ex14_36_test.cpp)

> 使用前一个练习定义的类读取标准输入，将每一行保存为 vector 的一个元素。

### 14.37 [Header](ex14_37_Equal.h) [Test](ex14_37_test.cpp)

> 编写一个类令其检查两个值是否相等。使用该对象及标准库算法编写程序，令其替换某个序列中具有给定值的所有实例。

## 14.8.1 节练习

### [练习 14.38]()

> 编写一个类令其检查某个给定的 string 对象的长度是否与一个阈值相等。使用该对象编写程序，统计并报告在输入的文件中长度为1的单词有多少个、长度为2的单词有多少个、......、长度为10的单词又有多少个。

### 练习 14.39

> 修改上一题的程序令其报告长度在1至9之间的单词有多少个、长度在10以上的单词又有多少个。

### 练习 14.40

> 重新编写 10.3.2 节的 biggies 函数，使用函数对象类替换其中的 lambda 表达式。

### 练习 14.41

> 你认为 c++11 标准为什么要增加 lambda? 对于你自己来说，什么情况下会使用 lambda, 什么情况下会使用函数对象。

使用 lambda 比定义函数对象的代码更加简洁。

## 14.8.2 节练习

### [练习 14.42](ex14_42_test.cpp)

> 使用标准库函数对象及适配器定义一条表达式，令其
> (a) 统计大于 1024 的值有多少个
> (b) 找到第一个不等于 pooh 的字符串
> (c) 将所有的值乘以2

### [练习 14.43](ex14_43_test.cpp)

> 使用标准库函数对象判断一个给定的 int 值是否能被 int 容器中的所有元素整除。

## 14.8.3 节练习

### [练习 14.44](ex14_44_test.h)

> 编写一个简单的桌面计算器使其能处理二元运算。

## 14.9.1 节练习

### [练习 14.45]()

> Write conversion operators to convert a Sales_data to string and to double. What values do you think these operators should return?

### [练习 14.46](ex14_2_Sales_data.h)

> Explain whether defining these Sales_data conversion operators is a good idea and whether they should be explicit.

- 为 Sales_data 添加 string 以及 double 的类型转换是个坏主意, 应该用成员函数去实现对应的功能。

- 如果非要写的话，最好加上 explicit 防止隐式类型转换。

### 练习 14.47

> Explain the difference between these two conversion operators:

```c++
struct Integral {
operator const int();   // 函数返回 const int 没有意义，const 会被编译器忽略
operator int() const;   // 保证该函数不会改变对象的状态, 这样 const object 也能够调用
};
```

### 练习 14.48

> Determine whether the class you used in exercise 7.40 from 7.5.1 (p. 291) should have a conversion to bool. If so, explain why, and explain whether the operator should be explicit. If not, explain why not.

TODO

### 练习 14.49

> Regardless of whether it is a good idea to do so, define a conversion to bool for the class from the previous exercise.

TODO

### 练习 14.50

> Show the possible class-type conversion sequences for the initializations of ex1 and ex2. Explain whether the initializations are legal or not.

```c++
struct LongDouble {
    LongDouble(double = 0.0);
    operator double();
    operator float();
};
LongDouble ldObj;
int ex1 = ldObj;    // 非法, ldObj 应该转换成 double 还是 float
float ex2 = ldObj;  // 正确
```

### 练习 14.51

> Show the conversion sequences (if any) needed to call each version of calc and explain why the best viable function is selected.

```c++
void calc(int);
void calc(LongDouble);
double dval;
calc(dval);
```

调用`void calc(int)`，因为`double -> int`的转换比`double -> LongDouble`的转换优先级更高。

### 练习 14.52

> Which operator+, if any, is selected for each of the addition expressions? List the candidate functions, the viable functions, and the type conversions on the arguments for each viable function:

```c++
struct LongDouble {
    // member operator+ for illustration purposes; + is usually a nonmember LongDouble operator+(const SmallInt&); // 1
    // other members as in 14.9.2 (p. 587)
    LongDouble operator+(SmallInt const &);
};
LongDouble operator+(LongDouble&, double); // 2
SmallInt si;
LongDouble ld;
ld = si + ld;   // 编译错误, SmallInt 可以转换为 int, LongDouble 可以转换为 float, double，这会产生二义性
ld = ld + si;   // 精准匹配
```

### 练习 14.53

> Given the definition of SmallInt on page 588, determine whether the following addition expression is legal. If so, what addition operator is used? If not, how might you change the code to make it legal?

```c++
SmallInt s1;
double d = s1 + 3.14;
```

内置的 int + double 以及 SmallInt 定义的 operator+(SmallInt const &, SmallInt const &) 会产生二义性

```c++
// fixed
SmallInt s1;
double d = s1 + static_cast<SmallInt>(3.14);
```