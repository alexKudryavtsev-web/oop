#include "island.h"
#include <iostream>

Island::Island() : name(""), area(0.0), population(0) {}

Island::Island(const std::string &name, double area, int population) : name(name), area(area), population(population)
{
}

std::string Island::getName() const
{
  return this->name;
}

void Island::setName(const std::string &newName)
{
  this->name = newName;
}

double Island::getArea() const
{
  return this->area;
}

void Island::setArea(double newArea)
{
  if (newArea >= 0)
  {
    this->area = newArea;
  }
}

int Island::getPopulation() const
{
  return this->population;
}

void Island::setPopulation(int newPopulation)
{
  if (newPopulation > 0)
  {
    this->population = newPopulation;
  }
}

std::ostream &operator<<(std::ostream &os, const Island &island)
{
  return os << island.getName() << ": площадь " << island.getArea() << ", население: " << island.getPopulation();
}