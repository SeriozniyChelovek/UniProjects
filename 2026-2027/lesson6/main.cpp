#include <iostream>
#include "TList.hpp"

using namespace std;

int main() {
    cout << "TList\n" << endl;

    TList<int> list;
    cout << "новый список =" << list << "isEmpty: " << list.isEmpty() << endl;

    list.add(1); list.add(2); list.add(3);
    cout << "add(1) add(2) add(3)\nlist =" << list << "getLength: " << list.getLength() << endl;

    list.add(0, 0);
    list.add(5);
    list.add(9, 2);
    cout << "add(0, 0) — в начало\nadd(5, length) — в конец\nadd(9, 2) — в середину\nlist =" << list << endl;

    list[1] = 100;
    cout << "list[1] = 100\nlist =" << list << endl;
    cout << "list[2] = " << list[2] << endl;

    cout << "\npop() = " << list.pop() << "\nlist =" << list << endl;
    cout << "pop(0) = " << list.pop(0) << "\nlist =" << list << endl;
    cout << "pop(1) = " << list.pop(1) << "\nlist =" << list << endl;

    return 0;
}
