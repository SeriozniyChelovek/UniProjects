#include <iostream>
#include "TBitArr.hpp"

using namespace std;

int main() {
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
	
	return 0;
}
