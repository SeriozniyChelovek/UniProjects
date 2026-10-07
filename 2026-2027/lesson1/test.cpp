#include <iostream>
#include "TBitArr.hpp"
#include "TSet.hpp"

using namespace std;

int main() {

    TBitArr b1("101010");
    TBitArr b2("1111");

    TSet s1(b1);
    TSet s2(b2);
    TSet s3(10);


    cout << s1.getMax() << ' ' << s1 << endl;
    cout << s2.getMax() << ' ' << s2 << endl;

    s3 = s1 | s2;

    cout << s3.getMax() << ' ' << s3 << endl;
    TBitArr bitarr3 = s3;
    cout << bitarr3 << endl;

	return 0;
}
