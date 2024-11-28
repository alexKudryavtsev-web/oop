#pragma once
#include <string>

class Island
{
private:
  std::string name;
  double area;
  int population;

public:
  Island();
  Island(const std::string &name, double area, int population);

  std::string getName() const;
  void setName(const std::string &newName);

  double getArea() const;
  void setArea(double newArea);

  int getPopulation() const;
  void setPopulation(int newPopulation);
};