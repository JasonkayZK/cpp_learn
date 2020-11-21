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

    cout << "length of arr after input: " << strlen(arr) << endl;
    cout << "length of str after input: " << str.length() << endl;
}
