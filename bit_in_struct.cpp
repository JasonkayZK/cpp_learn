#include <iostream>

struct t_register {
    unsigned int SN: 4;
    // 字节对齐，这4个bit未被使用！
    unsigned int : 4;
    bool goodIn: 1;
    bool goodOut: 1;
};

int main() {
    using namespace std;

    t_register tr = {0b10001110, true, false};
    if (tr.goodIn) {
        cout << "SN: " << tr.SN << ", goodIn: " << tr.goodIn << ", goodOut: " << tr.goodOut << endl;
    }
}