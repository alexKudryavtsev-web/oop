#pragma once
#include "Mammal.h"

class Cat : public Mammal
{
private:
  bool isWild;

public:
  Cat(std::string name, double weight, int age, std::string furColor, bool isWild);
  std::string toString() const override;
  void sayMeow() const;
  void setIsWild(const bool &isWild);
  bool getIsWild();
};