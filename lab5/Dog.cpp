#include "Dog.h"
#include <iostream>

int Dog::dogCount = 0;

Dog::Dog(std::string name, double weight, int age, std::string furColor, bool isWild) : Mammal(name, weight, age, furColor)
{
  this->isWild = isWild;
  Dog::dogCount++;
}

std::string Dog::toString() const
{
  return (this->isWild ? "Дикая собака: " : "Домашная собака: ") + this->getName() + ", вес: " + std::to_string(this->getWeight()) + " кг, возраст: " + std::to_string(this->getAge()) + " лет, шерсть: " + this->getFurColor();
}

void Dog::sayWoof() const
{
  std::cout << "Гав!" << std::endl;
}

void Dog::setIsWild(const bool &isWild)
{
  this->isWild = isWild;
}
bool Dog::getIsWild()
{
  return this->isWild;
}

Dog::~Dog()
{
  dogCount--;
}
int Dog::getDogCount()
{
  return Dog::dogCount;
}