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
