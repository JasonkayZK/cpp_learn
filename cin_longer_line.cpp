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
