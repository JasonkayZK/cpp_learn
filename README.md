## Cpp Learn

C++ Primer Plus第四章： 复合类型

### 数组

#### **① 数组声明**

使用下面的格式声明数组：

```cpp
typeName arrayName[arraySize];
```

这一点和Go以及Java中的`[]type varName`声明数组不同；

同时：

-   **C++中数组大小必须为const或是常量表达式，不能为动态数组！**
-   **C++中数组被称为复合类型，即必须使用其他类型创建；同时，char数组和long数组为不同的类型；**
-   **C++中数组不可以相互赋值！即使是相同类型、相同大小的数组！**

例如，下面的代码无法通过编译：

```cpp
int arr1[20]{1,2,3};
int arr2[20];
arr2 = arr1;
```

#### **② 数组访问**

可以使用`arr[i]`访问数组，但是需要注意：**C++不会检查下标的有效性！**

所以下面的代码能够被编译，并且正常执行：

```cpp
int ar1[] = {1,2,3,4};
cout << ar1[-1] << endl;
```

和Go或者Python中不同的是：`ar[-1]`表示的是ar数组内存位置之前的内存区域！

<font color="#f00">**C++对于数组越界访问并没有做限制！这在最近的这些编程语言中简直是不可想象的！但是现代编程语言由于对数组越界访问做出了限制，所以也会丧失掉部分的性能；**</font>

#### **③ 数组初始化**

**1.提供初始化大小进行初始化：**

例如：

```cpp
int cards[4] = {1,2,3,4};
```

如果提供的元素数少于数组大小，则剩下的元素会由编译器赋值为0；

例如：

```cpp
int ar1[4] = {1,2};
for (int i : ar1) {
    cout << i << endl;
}
```

如果提供的元素个数大于数组大小，则无法通过编译；

<font color="#f00">**如果数组声明时，未进行初始化，则此时虽然分配了地址，但是访问时都是内存中的随机数！**</font>

例如：

```cpp
int ar1[1000];
for (int i : ar1) {
    cout << i << endl;
}
// 输出为：
7249632
9
0
-17304
0
-17152
0
……
```

**2.不提供初始化大小进行初始化**

初始化数组时也可以不指定大小，例如：

```cpp
int ar1[] {1,2,3};
for (int i : ar1) {
    cout << i << endl;
}
```

此时会由编译器计算元素个数；

>   但是不推荐这种方式，因为编译器计算的结果可能和你想象的不同：初始化时漏掉了一个值；

**3.C++11初始化方法**

C++提供了大括号初始化方式，可用于所有类型；

在使用大括号进行初始化时，可能会有：

```cpp
// 1.可省略等号
double money[4] {1.2, 3.2, 3.3, 2.1};
// 2.空的大括号表示全部初始化为0值
double money[4] {};
// 3.大括号禁止缩窄转换
long arr1[] = {25, 3.0}; // 禁止double转long
char arr2[] = {'h', 1001212}; // 禁止1001212转char
```

需要注意的是第二点：`double money[4] {}`和`double money[4]`是完全不同的！

一个会全部初始化为零值，另一个则全部是随机数！

<br/>

### C风格字符串

C++中处理字符串的方式有两种：

-   C语言风格的字符串：**以`\0`结尾**；
-   使用C++中的string类库；

例如下面的两个字符数组：

```cpp
char arr1[] = {'a', 'b', 'c', 'd'}; // 非C类型字符串
char arr2[] = {'a', 'b', 'c', '\0'}; // C类型字符串
```

>   **`\0`对于C风格字符串至关重要！**
>
>   **C++中包括cout的那些函数，都是逐个处理字符串中的字符，直到遇到空字符为止！**
>
>   所以有下面的几种情况：
>
>   ```cpp
>   char arr1[] {'f', 'a', 't', 'a', 's', '\0'};
>   cout << arr1 << endl; // fatas
>   
>   char arr2[] {'f', 'a', '\0', 'a', 's'};
>   cout << arr2 << endl; // fa
>   
>   char arr3[] {'f', 'a', 't', 'a', 's'};
>   cout << arr3 << endl; // fatasfa
>   ```
>
>   arr1由于是标准的C风格的字符串，所以正常输出；
>
>   arr2在输出至arr2末尾之前就遇到了`\0`，所以未完全输出arr2中的内容；
>
>   arr3由于是非标准的C风格字符串，所以cout会继续访问并其后的内存地址，直到遇到了`\0`(在内存中也是0X0)；
>
>   **好在通常情况下内存中为0的区域比较多，否则arr3会不停输出！**
>
>   <font color="#f00">**arr3所示的这种情况是相当危险的！**</font>

#### **① 初始化字符串**

存储在char数组中的字符串可以使用单个字符进行初始化：

```cpp
// 别忘了最后的\0
char str[] = {'a', 'b', 'c', '\0'};
```

但是更多的是使用字符串常量进行初始化：

```cpp
char bird[] = "test";
```

此时，双引号括起的字符串会隐式的添加空字符`\0`；

>   此外，使用C++中类似于cin等输入的字符串，在读到char数组时，也会自动的加上结尾的空字符；

>   有时字符串很长，可以使用两个字符串合并为单个；
>
>   C++允许这么做：
>
>   <font color="#f00">**与通常的Java、Go使用 + 连接不同，C++使用空白符（空格、Tab、换行符）分隔的字符串常量都会自动拼接；**</font>
>
>   例如：
>
>   ```cpp
>   char arr[] {"Bozo" "234"};
>   cout << arr << endl;
>   cout << sizeof(arr) << endl;
>   ```
>
>   此时第一个字符串末尾的`\0`会被第二个字符串的首个字符取代；

#### **② 数组中使用字符串**

将字符串存放在char数组中，可以使用初始化为字符串常量，或是使用cin读入的方式；

例如：

string_with_arr.cpp

```cpp
#include <iostream>
#include <cstring>

const int ARR_SIZE = 15;

int main() {
    using namespace std;

    char name1[ARR_SIZE];
    cout << "What's name1? ";
    cin >> name1;
    cout << "Name1: " << name1 << endl;
    cout << "your name has " << strlen(name1) << " letters." << endl;
    cout << "your name is stored in an array of " << sizeof(name1) << endl;

    char name2[ARR_SIZE] = "C++boy";
    cout << "name2: " << name2 << endl;
    cout << "name2 length: " << strlen(name2) << ", arr size: " << sizeof(name2) << endl;

    cout << "change name2" << endl;
    name2[3] = '\0';
    cout << "name2: " << name2 << "!" << endl;
    cout << "name2 length: " << strlen(name2) << ", arr size: " << sizeof(name2) << endl;
}
```

从上可知：

-   char数组大小仅仅决定了字符串的存储上限，可以使用`sizeof`获取数组大小；
-   `strlen`返回了存储在数组中的字符串长度，计算方法是直到遇到了`\0`，并且计算结果长度不包括`\0`；
-   对于C类型字符串：`实际存放字符串数组最小大小 = strlen(字符串) + 1`；

#### **③ 字符串输入**

由于无法通过键盘直接输入一个空字符，所以在C++中：

在cin进行数据输入时，使用空白符（空格、Tab、换行）来确定字符串的结束位置，所以cin只能读取单个单词，并自动在结尾添加空白符；

目前使用cin有两个无法解决的问题：

-   无法直接读入含有空白符的输入；
-   无法防止将包含30个字符的字符串放到20个字符的数组中；

>   如果数组大小不够，则cin多出来的部分不会被丢弃，而是会强行覆盖至数组后面的位置，见下面这个例子：
>
>   cin_overflow.cpp
>
>   ```cpp
>   #include <iostream>
>   
>   int main() {
>       using namespace std;
>   
>       char arr[4];
>       cin >> arr;
>       cout << arr;
>   }
>   ```
>
>   上面的例子输入`abcdef`输出为：
>
>   ```
>   abcdef
>   ```
>
>   但是arr明明只有4个大小，为什么能输出6个字符呢？
>
>   这是因为上面提到的：cout在输出时实际上是单个字符判断，直到遇到`\0`停止；而cin覆盖了arr后的部分，直到abcdef全部输出后，在f后加了`\0`；

既然，cin有这些问题，那么就要有解决的方案；

##### **1.每次读入一行输入**

istream中提供了getline和get都可以读取一行代码直到换行符，区别在于：

-   getline读取后会丢弃换行符；
-   get会将换行符继续保留在输入流中；

###### **Ⅰ。getline()函数**

getline以回车作为分隔符，读取整行；getline(*char, int)有两个参数：数组名称（char指针），以及一个整型表示要读取的字符数；

>   **如果数组大小为20，可以指定整型最大为20，则函数最多读取19个字符！**
>
>   防止输入溢出；

getline会读取到回车或指定的长度后停止，并在最后添加一个空字符；

###### **Ⅱ。get()函数**

get函数有多个重载实现，其中一种是无参数的get()可以从输入流中读取一个字符(即便是换行符)；

另一种和getline类似：get(char*，int)；

<font color="#f00">**与getline不同的是，get函数读取至换行符后停止，并保持换行符在输入流中！**</font>

将上面两张get函数结合即可读取单行输入：

```cpp
// 读入一行
cin.get(name, SIZE).get();
// 读入下一行
cin.get(dessert, SIZE).get();
```

第一个带参的get会读取到一行结束，第二个无参的get将换行符吃掉；

>   为什么要设计get这种读取输入方式呢？
>
>   首先，老的C++没有getline实现；
>
>   其次，get可以使输入更仔细：例如使用get读入一行时，如何知道停止读取的原因是已经读取了整行、还是由于数组已经填满了呢？
>
>   **通过判断无参get获取到的是否是换行符来判断！**
>
>   -   如果get获取的是换行符，则说明读取了一行；
>   -   否则说明该行还有其他输入；

###### **Ⅲ。空行及其他问题**

**空行问题**

当getline或get读取空行时，会设置失效位（failbit），此时，此后的cin输入将会全部被阻断！

例如下面的例子：

cin_empty_line.cpp

```cpp
#include <iostream>

const int ARR_SIZE = 3;

int main() {
    using namespace std;

    char arr[ARR_SIZE];
    cin.get();
//    cin.clear();
    cin.get(arr, ARR_SIZE);
    cout << arr << endl;
}
```

在输入时，如果首先输入了一个空行（直接回车），则程序不等第二个get执行，会直接输出并退出；

这是因为get读取到了一个空行后会设置失效位（failbit）；

添加了`cin.clear`之后，重置了失效位（failbit），此后可以正常输出了！

**输入字符串比分配的长**

当输入的字符串比分配的空间要长时：<font color="#f00">**getline和get都会把多余的字符都留在输入队列中，但是getline会设置失效位（failbit），并关闭后面的输入，此时需要使用`cin.clear`清除失效位（failbit）；**</font>

例如下面的例子：

cin_longer_line.cpp

```cpp
#include <iostream>
#include <cstring>

const int ARR_SIZE = 3;

int main() {
    using namespace std;

    char arr[ARR_SIZE];
    cin.get(arr, ARR_SIZE);
//    cin.getline(arr, ARR_SIZE);
    cout << arr << endl << endl;

//    cin.clear();

    memset(arr, 0, ARR_SIZE);
    cin.get(arr, ARR_SIZE);
//    cin.getline(arr, ARR_SIZE);
    cout << arr << endl;
}

```

假设输入为“abcdef”；

-   当使用get接收输入时，输出分别为：“ab”和“cd”；
-   当使用getline接收输入时：
    -   如果不加`cin.clear`则输出仅为“ab”，后面的输入被阻断；
    -   如果加上`cin.clear`，则输出和使用get一致；

###### **④ 混合使用cin和getline**

看下面的例子：

```cpp
#include <iostream>

int main() {
    using namespace std;

    cout << "Get year: " << endl;
    int year;
    cin >> year;

//  cin.get();
    
    cout << "Get address: " << endl;
    char address[80];
    cin.getline(address, 80);

    cout << "Year: " << year << ", address: " << address << endl;
}
```

输入年份1966之后，程序直接结束，并输出：

```
Get year: 
1966
Get address: 
Year: 1966, address: 
```

没有读到address的原因是：

当cin读取年份时，将回车生成的换行符留在了输入队列中；所以后面的cin.getline看到换行符后，以为是一个空行，就将空行赋值给了数组；

可以通过加入一个get()吃掉这个换行符解决；

<br/>

### string类

C++98和5加入了string类，此时可以直接使用string类而非char数组存储字符串；

要使用string，必须包括string头文件；

>   是`#include<string>`而非`#include<cstring>`！

下面是一个使用string的例子：

string_demo.cpp

```cpp
#include <iostream>
#include <string>

int main() {
    using namespace std;

    string str1;
    cout << "Enter str: " << endl;
    cin >> str1;
    cout << "Input is: " << str1 << endl;

    string str2 = "panther";
    cout << "The second letter in " << str2 << " is: " << str2[1] << endl;
}
```

输入tester，可得输出：

```
Enter str: 
tester
Input is: tester
The second letter in panther is: a
```

上面的小栗子可以看出，使用string对象和char数组几乎相同：

-   可以使用C风格字符串初始化string；
-   可以使用cin将输入直接存入string；
-   可以使用cout直接输出string；
-   可以使用数组直接访问存储在string中的字符；

#### **① 初始化**

可以使用C-Style风格的字符串，和初始化列表初始化：

```cpp
string str1 = "abc";
string str2 = {"abc"};
string str2 {"abc"};
```

#### **② 赋值、拼接**

对于char数组而言，是不能直接赋值给另一个char数组的，但是string可以：

```cpp
char arr1[5] = "test";
char arr2[5];
// 非法
arr2 = arr1;

string str1 = "test";
string str2;
// 合法
str2 = str1;
```

对于char数组拼接，需要使用的`cstring`头文件中的`strcat`函数；

而对于string类而言，由于重载了+运算符，所以可以直接使用`+`拼接；

#### **③ string操作和char数组操作比较**

C语言在cstring头文件中提供了strcpy、strcat等函数用于char数组的操作；

下面一个代码对两种方式的操作进行了比较：

char_string_comp.cpp

```cpp
#include <iostream>
#include <cstring>
#include <string>

int main() {
    using namespace std;

    char arr1[20];
    char arr2[20] = "jaguar";
    string str1;
    string str2 = "panther";

    // 赋值
    str1 = str2;
    strcpy(arr1, arr2);

    // 添加
    str1 += " paste";
    strcat(arr1, " juice");

    // 求长
    cout << "str1 len: " << str1.length() << endl;
    cout << "arr1 len: " << strlen(arr1) << endl;
}
```

相比于使用char数组操作字符串，使用string类更为简单一些；

例如下述操作：

```cpp
str3 = str1 + str2;
// C-Style
strcpy(arr3, arr1);
strcat(arr3, arr2);
```

<red>**此外，当数组容量不够时，使用strcat或是其他类似的函数可能会导致危险！**</font>

例如：

```cpp
char site[10] = "house";
strcat(site, " of pancakes");
```

<red>**当strcat视图将全部字符赋值到site中时，将会覆盖相邻内存！**</font>

<red>**这是相当危险的！**</font>

**而string具有自动调整大小的功能；**

>   C函数库也提供了其他函数，例如：strncat、strncpy；
>
>   但是使用这些函数无疑增加了代码复杂度；

#### **④ string类IO**

string可以使用getline进行输入（在标准库声明的，并非iostream库中cin的成员函数！）；

例如：

str_io.cpp

```cpp
#include <iostream>
#include <string>
#include <cstring>

int main() {
    using namespace std;

    char arr[20];
    string str;

    cout << "length of arr before input: " << strlen(arr) << endl;
    cout << "length of str before input: " << str.length() << endl;

    cout << "Enter arr: " << endl;
    cin.getline(arr, 20);
    cout << "Entered arr: " << arr << endl;

    cout << "Enter str: " << endl;
    getline(cin, str);
    cout << "Entered str: " << str << endl;

    cout << "length of arr after input: " << strlen(arr);
    cout << "length of str after input: " << str.length();
}
```

下面是输出结果：

```
length of arr before input: 27
length of str before input: 0
Enter arr: 
abcd
Entered arr: abcd
Enter str: 
abcd
Entered str: abcd
length of arr after input: 4
length of str after input: 4
```

在用户输入前，char数组中就有了27长度的字符串，这是因为：

**声明但未初始化的数组是未定义的，在计算长度时会按照当前地址开始，知道遇到了空字符；**

>   上面使用到的getline并非cin的类方法；
>
>   这是由于在引入string类之前，C++就有了istream类；
>
>   所以istream类中考虑了int、double等类型，但是没有考虑string类型；
>
>   虽然istream中没有处理string类的方法，但是下面的代码还行可以执行的：
>
>   ```
>   cin >> str;
>   ```
>
>   这是由于上面的代码用到了**string类的一个友元函数！**

#### **⑤ 其他形式的字符串常量**

在C++中，除了char类型之外，还有wchar_t、char16_t、char132_t等，都可以表示为字符串类型；

可以使用L、u、U前缀来创建这些字符串常量：

```cpp
wchar_t title[] = L"test";
char16_t name[] = u"test2";
char32_t car[] = U"haha";
```

对于UTF-8编码，可以使用`u8`前缀：

```cpp
const char8_t* utf8 = u8"åäö";
```

>   在C++20中添加了char8_t类型；
>
>   在此之前可以使用`std::string`；

C++还新增了raw字符串，类似于python中的`r"raw string"`该字符串中的字符不会被转义！

raw字符串默认使用`"(`和`)"`作为限定符，并使用`R`来标识，例如：

```cpp
cout << R"(Jim "King" uses "\n" instead of endl.)" << '\n';
```

输出为：

```
Jim "King" uses "\n" instead of endl.
```

需要注意的是：<red>**输入原始字符串时，按下回车不仅会一到下一行，并且还会在原始字符串中添加换行符！**</font>

>   如果原始字符串中包括了`)"`，可以在开头的`"`和`(`之间添加字符串；
>
>   例如使用R`"+*(`和对应的`)+*"`配合**（注意`(`和`"`直接的字符必须一致）**：
>
>   ```cpp
>   cout << R"+*(Jim "King" uses "\n" instead of endl.)+*" << '\n';
>   ```

最后，前缀R可以和其他前缀一起使用，例如`Ru`、`RU`、`RL`等；

<br/>

### 结构struct





<br/>

### 共用体union





<br/>

### 枚举





<br/>

### 指针





<br/>

### new和delete





<br/>

### 动态数组





<br/>

### 动态结构





<br/>

### 几种内存存储方式





<br/>

### vector和array模板类



