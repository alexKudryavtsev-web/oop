#pragma once
#include <string>

class Animal
{
private:
  double weight; // вес в килограммах
  int age;       // возраст в годах
  std::string name;

public:
  virtual std::string toString() const = 0;

  double getWeight() const;
  void setWeight(double value);

  int getAge() const;
  void setAge(int value);

  std::string getName() const;
  void setName(const std::string &value);

  virtual ~Animal() = default;
};