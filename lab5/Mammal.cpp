#include "Mammal.h"
#include <iostream>

Mammal::Mammal(std::string name, double weight, int age, const std::string &furColor) : Animal()
{
  setName(name);
  setWeight(weight);
  setAge(age);
  this->furColor = furColor;
}

void Mammal::makeMilk() const
{
  std::cout << "Сделал молоко, чтобы кормить детей" << std::endl;
}

std::string Mammal::getFurColor() const
{
  return furColor;
}

void Mammal::setFurColor(const std::string &furColor)
{
  this->furColor = furColor;
}
