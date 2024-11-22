#include "People.h"

People::People(std::string name, double weight, int age, const std::string &country) : country(country)
{
  setName(name);
  setWeight(weight);
  setAge(age);
}

std::string People::toString() const
{
  return getName() + ", вес: " + std::to_string(getWeight()) + " кг, возраст: " + std::to_string(getAge()) + " лет, страна: " + country;
}

std::string People::getCountry() const
{
  return country;
}