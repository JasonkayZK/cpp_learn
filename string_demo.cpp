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
