#include <iostream>
#include "TBitArr.hpp"
#include "TSet.hpp"

using namespace std;

int main() {
    /*
	size_t bl;
	cout << "Input bit field length" << endl;
	cin >> bl;

	TBitArr bita(bl);
	TBitArr res(bl);

	bool resb;

	cout << "Input string of 0 and 1 as bit field" << endl;
	cin >> bita;
	cout << endl << "You inputed:" << endl;
	cout << bita << endl;

	TBitArr B(bl);
	resb = bita == B;
	cout << "Is your input an empty bit field? : " << resb << endl;

	TBitArr chess5 = (string)"1010101010";
	cout << "chess5: " << endl << chess5 << endl;

	res = bita & chess5;
	cout << "Input & chess5: " << endl << res << endl;

	res = bita | chess5;
	cout << "Input | chess5: " << endl << res << endl;

	res = ~bita;

	cout << "Inverted input: " << endl << res << endl;
	*/

    TBitArr bitarr("110011");
	TSet set1(bitarr);
	cout << "set1: " << set1 << endl;
	TSet set2(6);

	set2.add(3);
	cout << "set2: " << set2 << endl;
	cout << "Is 3 in set2? : " << set2.isIn(3) << endl;
	cout << "Is 4 in set2? : " << set2.isIn(4) << endl;

	set2.add(5);
	cout << "ADD 5 : " << set2 << endl;
	set2.del(3);
	cout << "DEL 3 : " << set2 << endl;

	TBitArr reverse = set2;
	cout << "(TBitArr)set2 : " << reverse << endl;

	TSet set3 = set1 & set2;
	cout << "set3 = set1 & set2 : " << set3 << endl;

	set3 = set1 | set2;
	cout << "set3 = set1 | set2 : " << set3 << endl;

	set3 = ~set1;
	cout << "set1 : " << set1 << endl;
	cout << "~set1 : " << set3 << endl;

	return 0;
}
