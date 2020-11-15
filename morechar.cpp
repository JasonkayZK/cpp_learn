#include <iostream>

int main() {
    using namespace std;

    char ch = 'M';
    int i = ch;
    cout << "The ASCII code for " << ch << " is " << i << endl;

    cout << "Add one:" << endl;
    ch += 1;
    i = ch;
    cout << "The ASCII code for " << ch << " is " << i << endl;

    // Use cout.put() display a char
    cout << "Using cout.put(ch): ";
    cout.put(ch);
    cout.put('!');

    int c = 5.0 % 1;
}
