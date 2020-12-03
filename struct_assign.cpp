#include <iostream>

struct inflatable {
    char name[20];
    float vol;
    double price;
};

int main() {
    using namespace std;
    inflatable bouquet = {
            "sunflowers",
            0.20,
            12.49
    };

    cout << "bouquet: " << bouquet.name << " for " << bouquet.price << "$" << endl;

    inflatable choice;
    choice = bouquet;
    cout << "choice: " << choice.name << " for " << choice.price << "$" << endl;

    cout << "change bouquet's price" << endl;
    bouquet.price = 29.99;
    cout << "bouquet price: " << bouquet.price << ", choice price: " << choice.price << endl;

    cout << "change bouquet's name" << endl;
    bouquet.name[0] = 'S';
    cout << "bouquet name: " << bouquet.name << ", choice name: " << choice.name << endl;
}
