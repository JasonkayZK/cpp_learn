#include <iostream>

const float MILLION = 1.0e6;

int main() {
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);

    float tub = 10.0 / 3.0;
    cout << "tub = " << tub;
    cout << ", a million tubs = " << MILLION * tub;
    cout << ", \nand ten million tubs = " << 10 * MILLION * tub << endl;

    double mint = 10.0 / 3.0;
    cout << "mint = " << mint << " and a million mints = " << mint * MILLION;
}
