#include <iostream>
#include "TAnimal.hpp"
#include "THorse.hpp"

using namespace std;

THorse::THorse(size_t c, float w, bool s) : TAnimal(c, w, s) {};
  
void THorse::speak() {
  cout << "Лошадка говорит игого" << endl;
};

void THorse::move(int step, int way) {
  cout << "Лошадка идет " << step << " шагов по маршруту " << way << endl;
};

