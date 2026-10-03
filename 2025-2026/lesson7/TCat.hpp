#ifndef __TCAT__HPP__
#define __TCAT__HPP__

#include <string>
#include "TAnimal.hpp"

using namespace std;

class TCat: public TAnimal {
  
public:
  TCat(size_t c, float w, bool s);
  void speak();
  void move(int, int);
};

#endif
