#include "People.h"

int People::peopleCount = 0;

People::People(std::string name, double weight, int age, const std::string &country) : country(country)
{
  setName(name);
  setWeight(weight);
  setAge(age);
  People::peopleCount++;
}

std::string People::toString() const
{
  return getName() + ", вес: " + std::to_string(getWeight()) + " кг, возраст: " + std::to_string(getAge()) + " лет, страна: " + country;
}

std::string People::getCountry() const
{
  return country;
}

People::~People()
{
  peopleCount--;
}
int People::getPeopleCount()
{
  return People::peopleCount;
}
