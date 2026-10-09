#include <iostream>
#include "TBitArr.hpp"
#include "TSet.hpp"

using namespace std;

template <typename T> void printAll(T* ptr, size_t len) {
    for (size_t i = 0; i < len; i++)
        cout << i << " : " << *ptr[i] << endl;
}

int main() {

    // Все ф-ии TBitArr
    //
    cout << "TBitArr\n";
	TBitArr b0("10001"), b1(60), b2(10);

	b1.set(33);

	TBitArr* barrs[3] = {&b0, &b1, &b2};
	printAll<TBitArr*>(barrs, 3);

	b0.set(1);
	b0.set(2);
	b0.set(4);
	b0.unset(0);
	cout << endl;
	printAll<TBitArr*>(barrs, 3);

	cout << "b0.get(2) : " << b0.get(2) << endl;
	cout << "b0.get(3) : " << b0.get(3) << endl;

    b2 = b0 & b1;
    cout << endl;
    cout << "b2 = b0 & b1" << endl;
    printAll<TBitArr*>(barrs, 3);

    b2 = b0 | b1;
    cout << endl;
    cout << "b2 = b0 | b1" << endl;
    printAll<TBitArr*>(barrs, 3);

    b2 = ~b1;
    cout << endl;
    cout << "b2 = ~b1" << endl;
    printAll<TBitArr*>(barrs, 3);

    cout << "\n\nTSet\n";

    // Все ф-ии TSet
    //

    TSet s0(b0), s1(b1), s2(b2);

	TSet* sets[3] = {&s0, &s1, &s2};
	printAll<TSet*>(sets, 3);

    s0.add(3);
    s0.add(2);
    s0.del(1);

    cout << endl;
    printAll<TSet*>(sets, 3);

    cout << "s0.isIn(0) : " << s0.isIn(0) << endl;
	cout << "s0.isIn(2) : " << s0.isIn(2) << endl;

	TBitArr buffer(10);
	buffer = s0;
	cout << "\n(TBitArr)s0 = " << buffer << endl;

    s2 = s0 & s1;
    cout << endl;
    cout << "s2 = s0 & s1" << endl;
    printAll<TSet*>(sets, 3);

    s2 = s0 | s1;
    cout << endl;
    cout << "s2 = s0 | s1" << endl;
    printAll<TSet*>(sets, 3);

    cout << endl;
    b0 = s0;
    b1 = s1;
    b2 = s2;
    printAll<TBitArr*>(barrs, 3);

	return 0;
}
