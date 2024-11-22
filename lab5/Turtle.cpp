#include "Turtle.h"
#include <string>

Turtle::Turtle(std::string name, double weight, int age) : Reptile(name, weight, age) {}

std::string Turtle::toString() const
{
  return "Черепаха: " + this->getName() + ", вес: " + std::to_string(this->getWeight()) + " кг, возраст: " + std::to_string(this->getAge()) + " лет";
}
