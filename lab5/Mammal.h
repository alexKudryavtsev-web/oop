#pragma once
#include "Animal.h"
#include <string>

class Mammal : public Animal
{
private:
  std::string furColor;

public:
  Mammal(std::string name, double weight, int age, const std::string &furColor);

  void makeMilk() const;

  std::string getFurColor() const;

  void setFurColor(const std::string &furColor);

  virtual ~Mammal() = default;
};