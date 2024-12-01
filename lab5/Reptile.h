#pragma once
#include "Animal.h"

class Reptile : public Animal
{
public:
  Reptile(std::string name, double weight, int age);
  void layEggs();
  virtual ~Reptile() = default;
};