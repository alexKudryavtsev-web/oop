#include "Cat.h"
#include <iostream>

Cat::Cat(std::string name, double weight, int age, std::string furColor, bool isWild) : Mammal(name, weight, age, furColor)
{
  this->isWild = isWild;
}

std::string Cat::toString() const
{
  return (this->isWild ? "Дикий кот: " : "Домашний кот: ") + this->getName() + ", вес: " + std::to_string(this->getWeight()) + " кг, возраст: " + std::to_string(this->getAge()) + " лет, шерсть: " + this->getFurColor();
}

void Cat::sayMeow() const
{
  std::cout << "Мяу!" << std::endl;
}

void Cat::setIsWild(const bool &isWild)
{
  this->isWild = isWild;
}
bool Cat::getIsWild()
{
  return this->isWild;
}
