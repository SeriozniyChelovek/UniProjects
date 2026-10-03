#ifndef __THORSE__HPP__
#define __THORSE__HPP__

#include <string>
#include "TAnimal.hpp"

using namespace std;

class THorse: public TAnimal {

public:
  THorse(size_t c, float w, bool s);
  
  void speak();
  
  void move(int step, int way);
};

#endif
