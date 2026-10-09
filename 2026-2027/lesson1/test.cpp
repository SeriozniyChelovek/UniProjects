#include <iostream>
#include "TBitArr.hpp"
#include "TSet.hpp"

using namespace std;

int main() {
	cout << "\n---\nДемонстрация TSet\n---\n";

    TBitArr bitarr("0");
	TSet set1(bitarr);
	cout << "set1: " << set1 << endl;
	TSet set2(6);

	set2.add(3);
	set2.add(5);
	set2.add(0);
	set2.del(3);

	cout << "set2: " << set2 << endl;

	cout << "set1: " << set1 << " set2: " << set2 << endl;
	TBitArr reverse = set2;
	cout << "(TBitArr)set2 : " << reverse << endl;

	TSet set3 = set1 & set2;
	cout << "set1 & set2 : " << set3 << endl;

	cout << "set1: " << set1 << " set2: " << set2 << endl;
	set3 = set1 | set2;
	cout << "set1 | set2 : " << set3 << endl;

	return 0;
}
