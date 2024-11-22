#include "Reptile.h"
#include <iostream>

Reptile::Reptile(std::string name, double weight, int age) : Animal()
{
  setName(name);
  setWeight(weight);
  setAge(age);
}

void Reptile::layEggs()
{
  std::cout << "Откладываем яйца" << std::endl;
}
