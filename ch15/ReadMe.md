# C++ Primer 5th 第十五章练习题

## 15.2.1 节练习

### 练习 15.1

> 虚函数是什么？

虚函数指的是基类希望派生类重新定义(override)的成员函数。
- 基类的虚函数需要在返回类型前添加`virtual`关键字。
- 对于派生类来说，基类定义的虚函数同样也是子类的虚函数。
- 基类应该将析构函数定义为虚函数，无论它的函数体是否为空。

### 练习 15.2

> protected 访问说明符与 private 有何区别？

protected 修饰的成员，派生类可以访问。而 private 修饰的成员，派生类无法访问。其它使用场景 protected 与 private 的含义一致。

### 练习 15.3 [Quote](ex15_3_Quote.h) [Test](ex15_3_test.cpp)

> 定义你自己的 Quote 类和 print_total 函数。

## 15.2.2 节练习

### 练习 15.4

> 下面哪条声明语句是不正确的？请解释原因。

```c++
class Base {...};
(a) class Derived : public Derived {...};
(b) class Derived : private Base {...};
(c) class Derived : public Base;
```

(a)错误。类不能自我继承。因为基类必须已经定义。
(b)错误，这是定义不是声明。
(c)错误，只有类的定义才需要类派生列表。

### 练习 15.5 [Bulk_quote](ex15_5_Bulk_quote.h) [Test](ex15_5_test.cpp)

> 定义你自己的 Bulk_quote 类。

### 练习 15.6

> 将 Quote 和 Bulk_quote 的对象传给 15.2.1 节练习中的 print_total 函数，检查该函数是否正确。

见 练习 15.3 以及 练习 15.5 的测试。

### 练习 15.7 [Limited_quote](ex15_7_Limited_quote.h) [Test](ex15_7_test.cpp)

> 定义一个类使其实现一种数量受限的折扣策略，具体策略是：当购买书籍的数量不超过一个给定的限量时享受折扣，超出的部分将以原价销售。

## 15.2.3 节练习

### 练习 15.8

> 给出静态类型和动态类型的定义。

- 静态类型：编译期间已知的类型，变量的类型或者表达式的类型。
- 动态类型：运行期间实际的类型。

对于指针或者引用类型，它的静态类型和动态类型可能不一致。其它的类型无论何时，静态类型和动态类型肯定都相同。

### 练习 15.9

> 什么情况下表达式的静态类型可能与动态类型不同？请给出三个静态类型与动态类型不同的例子。

当基类的指针或者引用指向派生类对象时。此时静态类型为`Base *`或者`Base &`，而动态类型为`Derived *`或者`Derived &`。

### 练习 15.10

> 解释 284 页中将 ifstream 传递给 Sales_data 的 read 函数是如何工作的。

利用了C++中动态绑定的机制，基类(istream)的引用可以指向派生类(fstream)对象，调用虚函数时会调用`fstream`中的虚函数。

## 15.3 节练习

### 练习 15.11

> 为你的 Quote 类添加一个名为 debug 的虚函数，令其分别显示每个类的数据成员。

### 练习 15.12

> 有必要将一个成员函数同时声明为 override 以及 final 吗？

有必要，override 用来检查它是否覆盖了基类的虚函数，final 则禁止它的派生类覆盖该函数。

### 练习 15.3

> 给定下面的类，解释每个 print 函数的机理。

```c++
class base {
public:
    string name() {return basename;}
    virtual void print(ostream &os) {os << basename;}
private:
    string basename;
};
class derived : public base {
public:
    void print(ostream &os) {
        print(os);
        os << " " << i;
    }
private:
    int i;
};
```
上面代码有问题吗？如果有，应该如何修改？

derived 中的 print 函数出现了递归调用，但是没有终止条件，会导致栈溢出。应该通过作用域访问符调用 base 的 print 函数。
`base::print(os);`。

### 练习 15.14

> 给定上一题中的类以及下面这些对象。说明在运行时调用哪个函数。

```c++
base bobj;      base *bp1 = &bobj;  base &br1 = bobj;
derived dobj;   base *bp2 = &dobj;  base &br2 = dobj;
(a)bobj.print();    (b)bp1->print();    (c)br1.print();
(d)dobj.print();    (e)bp2->print();    (f)br2.print();
```

(a)(b)(c)调用 base::print()
(d)(e)(f)调用 derived::print()

## 15.4 节练习

### 练习 15.15 [Disc_quote](ex15_15_Disc_quote.h) [Bulk_quote](ex15_15_Bulk_quote.h) [Test](ex15_15_test.cpp)

> 定义你自己的 Disc_quote 以及 Bulk_quote

### 练习 15.16 [Limited_quote](ex15_16_Limited_quote.h) [Test](ex15_16_test.cpp)

> 改写 15.7 编写的数量受限的折扣策略，令其继承 Disc_quote。

### 练习 15.17

> 尝试定义一个 Disc_quote 的对象，观察编译器给出的错误信息是什么。

```c++
error: cannot declare variable 'dq' to be of abstract type 'Disc_quote'
```

## 15.5 节练习

### 练习 15.18

> 假设给定了第 543 页和 544 页的类，同时已知每个对象的类型如注释所示，判断下面的哪些赋值语句是合法的。解释那些不合法的语句为什么不被允许。

```c++
Base *p = &d1;  // d1 的类型是 Pub_Derv     合法
p = &d2;        // d2 的类型是 Priv_Derv    不合法
p = &d3;        // d3 的类型是 Prot_Derv    不合法
p = &dd1;       // dd1 的类型是 Derived_from_Public 合法
p = &dd2;       // dd2 的类型是 Derived_from_private 不合法
p = &dd3;       // dd3 的类型是 Derived_from_protected 不合法
```

### 练习 15.19

> 假设 543 页和 544 页中的每个类都有如下形式的成员函数。对于每个类，分别检查上面的函数是否合法。
```c++
void memfcn(Base &b) {
    b = *this;
}
```

只要在`b = *this`这里，能够访问到`this`中`Base`部分的`public`有成员，就是合法的。

`Base`: 合法。
无论采用什么样的派生访问说明符，派生类一定能够访问基类部分的`pub`成员。
`Pub_Derv`: 合法。
`Priv_Derv`: 合法。
`Prot_Derv`: 合法。

`Derived_from_Public`: 合法。
因为在`Priv_Derv`中基类部分的`pub`成员已经是`private`的，它不能被派生类访问。
`Derived_from_Private`: 不合法。
`Derived_from_Protected`: 合法。


### 练习 15.20

> 编写代码检查上面两题的回答是否正确。

### 练习 15.21

> 从下面这些一般性抽象概念中任选一个，将其对应的一组类型组织成一个继承体系。
> (a) 图形文件格式(gif, tiff, jpeg, bmp)
> (b) 图形基元(方格, 圆, 球, 圆锥)
> (c) c++ 语言中的类型(类, 函数, 成员函数)

TODO

### 练习 15.22

> 为上一题编写的类添加虚函数和公有成员以及受保护的成员。

TODO

## 15.6 节练习

> 假设第550页的 D1 类需要覆盖它继承而来的 fcn 函数，你应该如何对其进行修改？如果你修改之后 fcn 匹配了 Base 的定义，则该节的那些调用语句将如何解析。

TODO