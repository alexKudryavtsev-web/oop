#include "Animal.h"

double Animal::getWeight() const {
    return this->weight;
};

void Animal::setWeight(double value) {
    this->weight = value;
};

int Animal::getAge() const {
    return this->age;
};

void Animal::setAge(int value) {
    this->age = value;
};

std::string Animal::getName() const {
    return this->name;
};

void Animal::setName(const std::string& value) {
    this->name = value;
};