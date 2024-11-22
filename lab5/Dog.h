#pragma once
#include "Mammal.h"

class Dog : public Mammal
{
private:
  bool isWild;
  static int dogCount;

public:
  Dog(std::string name, double weight, int age, std::string furColor, bool isWild);
  std::string toString() const override;
  void sayWoof() const;
  void setIsWild(const bool &isWild);
  bool getIsWild();
  static int getDogCount();
  ~Dog();
};