## Cpp Learn

Chapter 3 in C++ Primer Plus；

### climits头文件

在climits头文件中声明了在当前操作系统中，当前编译器声明的各个类型的存储大小、最大值、最小值等内容；

和Java、Golang等不同的是，C++中各个类型的大小并不是固定不变的！

代码示例如climits.cpp所示；

climits.cpp

```c++
#include <iostream>
#include <climits>

int main() {
    using namespace std;

    int n_int = INT_MAX;
    short n_short = SHRT_MAX;
    long n_long = LONG_MAX;
    long long n_llong = LLONG_MAX;

    cout << "int is " << sizeof(int) << " bytes" << endl;
    cout << "short is " << sizeof n_short << " bytes" << endl;
    cout << "long is " << sizeof n_long << " bytes" << endl;
    cout << "long long is " << sizeof n_llong << " bytes" << endl;
    cout << endl;

    cout << "Max values:" << endl;
    cout << "int: " << n_int << endl;
    cout << "short: " << n_short << endl;
    cout << "long: " << n_long << endl;
    cout << "long long: " << n_llong << endl;
    cout << endl;

    cout << "Bits per byte = " << CHAR_BIT << endl;

    return 0;
}
```

在win10 64位系统中输出如下：

```
int is 4 bytes
short is 2 bytes
long is 8 bytes
long long is 8 bytes

Max values:
int: 2147483647
short: 32767
long: 9223372036854775807
long long: 9223372036854775807

Bits per byte = 8
```

### 初始化

C++提供的变量初始化方式有下面几种：

```cpp
// 1.声明时初始化
int n_init_1 = 1;
// 2.C++提供的初始化方式
int n_init_2(1);
// 3.大括号初始化
int n_init_3 = {3};
// 或
int n_init_4{3};
```

### 数值越界

对于数值类型来说，如果发生了数值越界：

**① 有符号数**

MAX + 1 = MIN；

MIN - 1 = MAX;

**② 无符号数**

MAX + 1 = 0；

0 - 1 = MAX；

代码示例：见exceed.cpp

### char和int互相转换

char本质上也是整型类型，但是在使用cout智能对象进行输出时，char类型将会被转换为字符，而非对应的ASCII数字！

同时，可以使用`cout.put(ch)`输出单个字符；

`cout.put(ch)`的存在和历史有关：

>   在C++的Release 2.0之前，cout会将字符变量显示为字符，但是字符常量（如‘M’、‘N’等）显示为数字！
>
>   因为C++早期会将全部的字符常量存储为int类型！
>
>   所以在C++ 2.0之前，会出现下面的情况：
>
>   ```cpp
>   // 输出$的ASCII码；
>   cout << '$';
>   // 输出'$'
>   cout.put('$');
>   ```
>
>   C++ Release 2.0之后，C++将字符常量存储为char；
>
>   **这也意味着`cout.put()`已经被淘汰了！**

代码示例：morechar.cpp

### C++字符集

#### **① C++与Unicode**

和Java类似，C++中也可以通过`\u`或者`\U`的方式使用Unicode字符集；

可以在代码或是字符串中随意的使用，例如：

```cpp
#include <iostream>

int main() {
    using namespace std;

    int k\u00F6rper;
    cout << "Eat g\u00E2teau.\n";
}
```

上面的代码可以通过编译，并正确显示：

```
Eat gâteau.
```

#### **② 宽字符类型wchar_t**

C++中原本的char类型仅有8字节，显然即使是unsigned char类型也无法处理世界上全部的字符；

所以宽字符类型：`wchar_t`应运而生；

`wchar_t`是整数类型，其底层类型和具体的系统实习相关：可能是unsigned short或是int类型；

对于cin 和 cout可以看作是char流，此时不再适用于`wchar_t`类型，所以iostream提供了相似的智能对象：`wcin`和`wcout`，用于处理wchar_t流：

`wcin`和`wcout`将每个字符按照一个字符两个字节的wchar_t类型进行存储；

#### **③ char16_t和char32_t**

C++在C11时加入了`char16_t`和`char32_t`类型；

`char16_t`是16位的，`char32_t`是32位的；

C++11使用`前缀（u/U） + 字符串常量`的方式表示`char16_t`和`char32_t`常量，例如：

```cpp
char16_t ch1 = u'q';
char32_t ch2 = U'\U0000222B';
```

对于底层而言，`char16_t`和`char32_t`也都有自己的底层类型，底层类型和各个系统的实现有关；

### const常量

与C98之前使用`#define`宏来声明常量相比，使用const要高端好多了…；

与ANSI C相比：

-   C++和ANSI C的const作用域不同；
-   C++可以使用const声明数组长度；

### 浮点类型

C++中浮点数包括：float、double和long double；

#### **① cfloat头文件**

在C++和C中，要求：

-   浮点数float至少为32为；
-   double至少为48位，且不少于float；
-   long double至少和double一样多；

>   通常：
>
>   float为32位、double为64位、long double为80、96或128位；
>
>   可以在cfloat头文件中查看相关定义；

#### **② 浮点数精度**

float和double表示的精度各不相同；

下面的代码展示了浮点数精度可能会造成的影响：

```cpp
#include <iostream>

const float MILLION = 1.0e6;

int main() {
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);

    float tub = 10.0 / 3.0;
    cout << "tub = " << tub;
    cout << ", a million tubs = " << MILLION * tub;
    cout << ", \nand ten million tubs = " << 10 * MILLION * tub << endl;

    double mint = 10.0 / 3.0;
    cout << "mint = " << mint << " and a million mints = " << mint * MILLION;
}
```

输出结果为：

```
tub = 3.333333, a million tubs = 3333333.250000, 
and ten million tubs = 33333332.000000
mint = 3.333333 and a million mints = 3333333.333333
```

由于**float仅能保证至少6位有效位**，所以`10.0 / 3.0 * 1000000`被计算为了`3333333.250000`；

而**double被确保至少15位有效位**，所以计算并无误差；

>   使用cout.setf配置了std输出流的显示格式；

代码示例：floatnum.cpp

### 求模运算

与Java中浮点数求mod只会使用到求模的整数部分不同；

C++要求求模的两个操作数都必须是整数类型，所以：`5.0 % 1`或是`5 % 1.0`都是无法编译的；

### 强制类型转换

除了在计算时进行自动类型转换之外，C++提供多种强制类型转换的方法：

#### **① 显式转换**

显式的转换可以是下面的方式：

```cpp
(long) n_int;
或
long(n_int);
```

#### **② 强制类型转换运算符**

C++引入了4个强制类型转换运算符，其中`static_cast<>()`可用于将值从一个类型转为另一个类型，例如`static_cast<long>(n_int)`；

