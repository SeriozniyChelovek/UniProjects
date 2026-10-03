#include <iostream>
#include "TAnimal.hpp"
#include "TParrot.hpp"

using namespace std;

TParrot::TParrot(size_t c, float w, bool s): TAnimal(c, w, s) {};
  
void TParrot::speak() {
  cout << "Попугайчик говорит привет" << endl;
};

void TParrot::move(int step, int way) {
  cout << "Попугайчик идет " << step << " шагов по маршруту " << way << endl;
};

