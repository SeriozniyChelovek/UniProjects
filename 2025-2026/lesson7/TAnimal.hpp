#ifndef __TANIMAL__HPP__
#define __TANIMAL__HPP__

using namespace std;

class TAnimal {
  
protected:
  size_t color;
  float weight;
  bool sex;

public:
  TAnimal(size_t c = 0, float w = 0, bool s = 0);

  virtual void speak() {};
  virtual void move(int step, int way) {};

  size_t getColor();
  float getWeight();
  bool getSex();
};

#endif
