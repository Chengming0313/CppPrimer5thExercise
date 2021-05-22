#### C++中的初始化

C++ 中所有初始化方式都与 list initialization 相关
- list initialization
- aggregate initiallization
- value initialization
- default initialization
- zero initialization

列表初始化形式：
```
[new] T [object] {arg1, arg2, ...}
// eg.
A  a1{};
A  a2 = {};
A *a3 = new A{};
A{}.printData();
(new A{})->printData();
```
1. ##### aggregate type 类型的 list initialization

aggregate type(聚合类) 、数组、vector 都属于 aggregate type
```C++
// 1. 对 aggregate type 进行 list initialization
// 首先逐个初始化，不够的进行 value initialization
int arr1[] = { 1, 2, 3 };   // 没有 value initialization
int arr2[5] = { 1, 2, 3 };  // 内置类型 value initialization

1 2 3 
1 2 3 0 0
```

#### 默认构造函数 合成构造函数