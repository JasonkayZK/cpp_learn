#include <iostream>

int main() {
    using namespace std;

    // 1.声明时初始化
    int n_init_1 = 1;
    // 2.C++提供的初始化方式
    int n_init_2(1);
    // 3.大括号初始化
    int n_init_3 = {3};
    // 或
    int n_init_4{3};

    cout << n_init_1 << n_init_2 << n_init_3 << n_init_4 << endl;
}
