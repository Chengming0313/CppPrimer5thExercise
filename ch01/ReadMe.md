# C++ Primer 5th 第一章练习题

## 1.1 节练习

### 练习 1.1
> 查阅你使用的编译器文档，确定它所使用的文件命名约定。编译并运行第2页的main程序。
```
F:\Project\CLionProjects\cpp-primer5\ch01>g++ -o ex1_1.exe ex1_1.cpp

F:\Project\CLionProjects\cpp-primer5\ch01>.\ex1_1.exe

F:\Project\CLionProjects\cpp-primer5\ch01>echo %ERRORLEVEL%
0
```

### 练习 1.2

> 改写程序，让它返回-1，观察结果。
```
F:\Project\CLionProjects\cpp-primer5\ch01>g++ -o ex1_2.exe ex1_2.cpp

F:\Project\CLionProjects\cpp-primer5\ch01>.\ex1_2.exe

F:\Project\CLionProjects\cpp-primer5\ch01>echo %ERRORLEVEL%
-1
```

## 1.2 节练习

### [练习 1.3](ex1_3.cpp)
> 在标准输出上打印Hello World。

### [练习 1.4](ex1_4.cpp)

> 使用乘法运算符*，打印两个数的积。

### [练习 1.5](ex1_5.cpp)

> 重写1.2 节中的程序，将每个运算对象的输出语句放在一条独立语句中。

### 练习 1.6

> 解释下列程序片段是否合法
> 
```C++
// 不合法，去除每一行末尾的分号。
std::cout << "The sum of " << v1
    << " and " << v2
    << " is " << v1 + v2 << std::endl;
```


## 1.3 节练习
### 练习 1.7

> 编译一个包含不正确嵌套注释的程序，观察编译器返回的错误信息。
```C++
// output: error: expected primary-expression before '/' token
int main()
{
    /*/**/
    */ 
    return 0;
}
```

### 练习 1.8

> 指出下列哪些输出语句是合法的？
> 
```C++
// 除了第三条输出语句，都是合法的。
std::cout << "/*";
std::cout << "*/";
// std::cout << /* "*/" */;
std::cout << /* "*/ " */ ";
std::cout << /* "*/" /* "/*" */;
```


### 1.4.1 节练习

### [练习 1.9](ex1_9.cpp)

### [练习 1.10](ex1_10.cpp)

### [练习 1.11](ex1_11.cpp)



### 1.4.2 节练习
##### Exercise 1.12
> What does the following for loop do? What is the final value of sum?
```C++
int sum = 0;
for (int i_ = -100; i_ <= 100; ++i_)
    sum += i_;
```
计算-100到100的所有整数之和，sum = 0

##### Exercise 1.13
> 使用for循环重做1.4.1 节练习
- 1.9
```C++
int main()
{
    int sum = 0;
    for (int i_ = 50; i_ <= 100; ++i_)
    {
        sum += i_;
    }
    std::cout << "The sum from 50 to 100 inclusive is " << sum << std::endl;
}
```
- 1.10
```C++
int main()
{
    for (int i_ = 10; i_ >= 0; --i_)
    {
        std::cout << i_ << std::endl;
    }
    return 0;
}
```
- 1.11
```C++
int main()
{
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    if (v1 > v2)
    {
        int temp = v1;
        v1       = v2;
        v2       = temp;
    }
    for (int i_ = v1; i_ <= v2; ++i_)
    {
        std::cout << i_ << std::endl;
    }
    return 0;
}
```

##### Exercise 1.14
> 对比for循环和while循环，这两种循环的优缺点是什么？
```
for循环与while循环之间可以互相转化。for循环适合循环次数已知的情况。
```

##### Exercise 1.15
> 编写程序，熟悉编译器生成的错误信息。
```
sytax error、type error、declaration error...
```

### 1.4.3 节练习
##### Exercise 1.16
> 编写程序，从键盘输入一组数求和。
```C++
int main()
{
    int sum = 0, x = 0;
    while (std::cin >> x)
    {
        sum += x;
    }
    std::cout << sum << std::endl;
    return 0;
}
```


### 1.4.4 节练习
##### Exercise 1.17
> 如果输入的所有值相等，本节的程序会输出什么？如果没有重复值，程序又会输出什么？
```
答：输入n个x值输出：x occurs n times
    输入n个不同的值：每个值输出一行
```

##### Exercise 1.18
> 验证1.17的结论。
```
input: 1 1 1 1 1 ^Z
output: 1 occurs 5 times

input: 1 2 3 4 5^Z
output: 1 occurs 1 times
        2 occurs 1 times
        3 occurs 1 times
        4 occurs 1 times
        5 occurs 1 times
```
##### Exercise 1.19
> 修改1.11中编写的程序，使其能够处理用户输入的第一个数比第二个数大的情况。
```C++
int main()
{
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    if (v1 > v2)
    {
        int tmp = v1;
        v1      = v2;
        v2      = tmp;
    }
    while (v1 <= v2)
    {
        std::cout << v1 << " ";
        ++v1;
    }
    std::cout << std::endl;
    return 0;
}
```


### 1.5.1 节练习
##### Exercise 1.20
> 使用提供的Sales_item.h文件，编写程序。读取一组书籍销售记录，将每条记录打印到标准输出上。
```C++
// PowerShell 重定向：Get-Content  .\data\book_sales |  ./ex1_20
int main()
{
    Sales_item item;
    while (std::cin >> item)
    {
        std::cout << item << std::endl;
    }
    return 0;
}
```
##### Exercise 1.21
> 读取两个isbn相同的Sales_item对象，输出它们的和。
```C++
// Get-Content .\data\1_21.in | ./ex1_21
int main()
{
    Sales_item item1, item2;
    std::cin >> item1 >> item2;
    std::cout << item1 + item2;
    return 0;
}
```
##### Exercise 1.22
> 读取多个具有相同isbn的Sales_item对象，输出它们的和。
```C++
// Get-Content  .\data\1_22.in |  ./ex1_22
int main()
{
    Sales_item sum_item, item;
    if (std::cin >> item)
    {
        sum_item = item;
        while (std::cin >> item)
        {
            sum_item += item;
        }
    }
    std::cout << sum_item << std::endl;
    return 0;
}
```


### 1.5.2 节练习
##### Exercise 1.23
> 读取多条销售记录，统计每个isbn号的销售记录数。
```C++
int main()
{
    Sales_item curItem, item;
    if (std::cin >> curItem)
    {
        int cnt = 1;
        while (std::cin >> item)
        {
            if (item.isbn() == curItem.isbn())
            {
                ++cnt;
                continue;
            }
            std::cout << curItem.isbn() << ": " << cnt << std::endl;
            curItem = item;
            cnt     = 1;
        }
        std::cout << curItem.isbn() << ": " << cnt << std::endl;
    }
    return 0;
}
```
##### Exercise 1.24
> 验证1.23编写的程序的结果。
```
Get-Content  .\data\1_23.in |  ./ex1_23
0-201-70353-X: 1
0-201-82470-1: 1
0-201-88954-4: 4
0-399-82477-1: 2
0-201-78345-X: 2
```


### 1.6 节练习
##### Exercise 1.25
> 编写本节中给出的书店程序。
```C++
int main()
{
    Sales_item total, item;
    if (std::cin >> item)
    {
        total = item;
        while (std::cin >> item)
        {
            if (item.isbn() == total.isbn())
            {
                total += item;
                continue;
            }
            std::cout << total << std::endl;
            total = item;
        }
        std::cout << total << std::endl;
        return 0;
    }
    else
    {
        std::cerr << "No data" << std::endl;
        return -1;
    }
}
```



