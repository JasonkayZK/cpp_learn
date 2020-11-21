#include <iostream>
#include <cstring>

struct inflatable {
    char name[20];
    float vol;
    double price;
};

int main() {
    using namespace std;

    cout << R"+*(Jim "King" uses "\n" instead of endl.)+*" << '\n';

//    char* c1;
//    cout << *c1 << endl;
//
//    long arr4[] {1,2,3};
//    long* p_arr4 = &arr4[1];
//
//    cout << *p_arr4 << endl;
//    cout << p_arr4[-1] << endl;
//    cout << p_arr4[-2] << endl;
//
//    short tell[10];
//    cout << tell + 1<< endl;
//    cout << &tell + 1 << endl;
//
//    auto *ps = new inflatable;
//    (*ps).price = 21;
//    strcpy(ps->name, "test");
//    cout << (*ps).price << endl;
//    cout << ps->name << endl;
//    delete ps;
}
