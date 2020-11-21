#include <iostream>

int main() {
    using namespace std;

    cout << "Get year: " << endl;
    int year;
    cin >> year;

//    cin.get();

    cout << "Get address: " << endl;
    char address[80];
    cin.getline(address, 80);

    cout << "Year: " << year << ", address: " << address << endl;
}