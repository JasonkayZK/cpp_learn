#include <iostream>

const int ARR_SIZE = 3;

int main() {
    using namespace std;

    char arr[ARR_SIZE];
    cin.get();
    cin.clear();
    cin.get(arr, ARR_SIZE);
    cout << arr << endl;
}