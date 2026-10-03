#ifndef __TPARROT__HPP__
#define __TPARROT__HPP__

#include <string>
#include "TAnimal.hpp"

using namespace std;

class TParrot: public TAnimal {
  
public:
  TParrot(size_t c, float w, bool s);
  
  void speak();
  
  void move(int step, int way);
};

#endif
