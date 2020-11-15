#include <iostream>
#include <climits>

#define ZERO 0

int main() {
    using namespace std;

    short sam = SHRT_MAX;
    unsigned short sue = sam;

    cout << "Sam has " << sam << " dollars and Sue has " << sue << " dollars." << endl;

    cout << "Add 1 to each account." << endl;
    sam += 1;
    sue += 1;
    cout << "Sam has " << sam << " dollars and Sue has " << sue << endl;

    sam = ZERO;
    sue = ZERO;
    cout << "Sam has " << sam << " dollars and Sue has " << sue << endl;

    cout << "Take 1 from each account." << endl;
    sam -= 1;
    sue -= 1;
    cout << "Sam has " << sam << " dollars and Sue has " << sue << endl;
}
