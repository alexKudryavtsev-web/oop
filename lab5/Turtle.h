#pragma once
#include "Reptile.h"
#include <string>

class Turtle : public Reptile
{
public:
  Turtle(std::string name, double weight, int age);
  std::string toString() const override;
};