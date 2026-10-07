#include <iostream>
#include "TBitArr.hpp"
#include "TSet.hpp"

using namespace std;

int main() {
    cout << "---\nДемонстрация TBitArr\n---\n";
	size_t bl;
	cout << "Введите размер битового поля" << endl;
	cin >> bl;

	TBitArr bita(bl);
	TBitArr res(bl);

	bool resb;

	cout << "Введите строку нулей и единиц в качестве содержания битового поля" << endl;
	cin >> bita;
	cout << endl << "Вы ввели:" << endl;
	cout << bita << endl;

	TBitArr B(bl);
	resb = bita == B;
	cout << "Введённое битовое поле - пустое? : " << resb << endl;

	TBitArr chess5 = (string)"1010101010";
	cout << "chess5: " << endl << chess5 << endl;

	res = bita & chess5;
	cout << "Input & chess5: " << endl << res << endl;

	res = bita | chess5;
	cout << "Input | chess5: " << endl << res << endl;

	res = ~bita;

	cout << "~Input: " << endl << res << endl;

	cout << "\n---\nДемонстрация TSet\n---\n";

    //TBitArr bitarr("110011");
	//TSet set1(bitarr);
	TSet set1(bita);
	cout << "set1: " << set1 << " (Составлен из первого введённого битового поля)" << endl;
	TSet set2(6);

	set2.add(3);
	cout << "set2: " << set2 << endl;
	cout << "Есть ли 3 в set2? : " << set2.isIn(3) << endl;
	cout << "Есть ли 4 в set2? : " << set2.isIn(4) << endl;

	set2.add(5);
	cout << "Добавить 5 в set2 : " << set2 << endl;
	set2.add(0);
	cout << "Добавить 0 в set2 : " << set2 << endl;
	set2.del(3);
	cout << "Удалить 3 из set2 : " << set2 << endl;

	TBitArr reverse = set2;
	cout << "(TBitArr)set2 : " << reverse << endl;

	TSet set3 = set1 & set2;
	cout << "set1 & set2 : " << set3 << endl;

	set3 = set1 | set2;
	cout << "set1 | set2 : " << set3 << endl;

	set3 = ~set1;
	cout << "set1 : " << set1 << endl;
	cout << "~set1 : " << set3 << endl;

	return 0;
}
