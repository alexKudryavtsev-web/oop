#pragma once
#include "Animal.h"
#include <string>

class People : private Animal
{
private:
    std::string country;
    People();
    People(const People &p);
  static int peopleCount;

public:
    People(std::string name, double weight, int age, const std::string &country);
    std::string toString() const override;
    std::string getCountry() const;
    static int getPeopleCount();
    ~People();
};