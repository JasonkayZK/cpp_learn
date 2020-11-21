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
