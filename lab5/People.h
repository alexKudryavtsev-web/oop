#pragma once
#include "Animal.h"
#include <string>

class People : private Animal
{
private:
    std::string country;

public:
    People(std::string name, double weight, int age, const std::string &country);
    std::string toString() const override;
    std::string getCountry() const;
};