#include <iostream>
#include "TAnimal.hpp"

using namespace std;

TAnimal::TAnimal(size_t c, float w, bool s): color{c}, weight{w}, sex{s} {};

size_t TAnimal::getColor() {
  return color;
}

float TAnimal::getWeight() {
  return weight;
}

bool TAnimal::getSex() {
  return sex;
}
