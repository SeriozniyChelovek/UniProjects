#include <iostream>
#include "TQueue.hpp"

// TODO ДОДЕЛАТЬ

using namespace std;

int main() {

    TQueue<int> a(4);
    a.push(1);
    a.push(2);
    a.push(3);
    cout << a << endl;
    int b = a.pop();
    cout << b << endl;
    cout << a << endl;

    return 0;
}
