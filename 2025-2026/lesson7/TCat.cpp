#include <iostream>
#include "TAnimal.hpp"
#include "TCat.hpp"

using namespace std;

TCat::TCat(size_t c, float w, bool s): TAnimal(c, w, s) {};
  
void TCat::speak() {
  cout << "Котик говорит мяу" << endl;
};
  
void TCat::move(int step, int way) {
  cout << "Котик идет " << step << " шагов по маршруту " << way << endl;
};

