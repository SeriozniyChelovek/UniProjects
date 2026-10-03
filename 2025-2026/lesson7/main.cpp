#include <iostream>

#include "TAnimal.hpp"
#include "TCat.hpp"
#include "THorse.hpp"
#include "TParrot.hpp"

#include "../lesson5/TString.hpp"
#include "colors.hpp"

using namespace std;

float maxWeight(TAnimal** zoo, size_t zoo_len) {
  float res = 0;
  float weight;
  for (size_t i = 0; i < zoo_len; i++) {
	weight = zoo[i]->getWeight();
	if (weight > res) res = weight;
  }
  return res;
}

size_t countColor(TAnimal** zoo, size_t zoo_len, size_t color_id) {
  float res = 0;
  for (size_t i = 0; i < zoo_len; i++) {
	if (zoo[i]->getColor() == color_id) res++;
  }
  return res;
}

size_t findCatPair(TAnimal** zoo, size_t zoo_len, size_t color, bool sex) {
  TCat* catptr;
  for (size_t i = 0; i < zoo_len; i++) {
	catptr = dynamic_cast<TCat*>(zoo[i]);
	if (catptr)
	  if (zoo[i]->getColor() == color)
		if (zoo[i]->getSex() != sex)
		  return i;
  }
  return zoo_len;
}

int main() {

  TAnimal sereja{0, 10.0, 1};
  TCat manya{1, 15.7, 0};
  THorse loshad{0, 150.3, 1};
  TParrot kesha{2, 3, 1};

  const size_t zoo_l = 4;
  TAnimal* zoo[zoo_l] = {&sereja, &manya, &loshad, &kesha};
  
  for (TAnimal* an: zoo) {
	cout << COLORLIST[an->getColor()] << endl;
	an->speak();
	an->move(5, 1);
  }

  cout << endl << endl;

  double mw;
  mw = maxWeight(zoo, zoo_l);
  cout << "Максимальный вес животного: " << mw << endl;

  size_t num;
  size_t col = 1;
  num = countColor(zoo, zoo_l, col);
  cout << COLORLIST[col] << ": " << num << endl;

  num = findCatPair(zoo, zoo_l, col, 0); // 0 - самка => ищем самца и vice versa

  if (num != zoo_l)
	cout << num << " - индекс пары для котика с введёнными данными" << endl;
  else
	cout << "Котик соответствующий условиям не был найден" << endl;
  return 0;
}
