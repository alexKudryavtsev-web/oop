// Alexander Kudryavtsev, 5130903/30002, variant 1
#include <iostream>
#include "Cat.h"
#include "Dog.h"
#include "Dog.cpp"
#include "Cat.cpp"
#include "People.h"
#include "People.cpp"
#include "Mammal.cpp"
#include "Animal.cpp"
#include "Reptile.cpp"
#include "Turtle.h"
#include "Turtle.cpp"

#include "utils.h"
#include "utils.cpp"

using namespace std;

int main()
{
  setlocale(LC_ALL, "Russian");

  int V = (10 * int('K') + int('A')) % 11;

  cout << "Вариант " << V << endl;

  int size = 0;
  int capacity = 20;

  Animal **animals = new Animal *[capacity];

  help();

  int choice;
  do
  {
    cout << "Введите команду: ";
    cin >> choice;

    if (cin.fail())
    {
      cout << "Некорректный ввод.\n";
      cin.clear();
      cin.ignore(255, '\n');
      continue;
    }

    switch (choice)
    {
    case 0:
      help();
      break;
    case 1:
      break;
    case 2:
      addAnimal(animals, size, capacity);
      break;
    case 3:
      removeAnimal(animals, size);
      break;
    case 4:
      printAnimals(animals, size);
      break;
    default:
      cout << "Такой команды нет.\n";
      break;
    }
  } while (choice != 1);

  delete[] animals;

  return 0;
}
