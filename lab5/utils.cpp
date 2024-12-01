#include "utils.h"
#include <iostream>

using namespace std;

void help()
{
  string menu = "Меню:\n\t"
                "0 - показать меню\n\t"
                "1 - выйти из программы\n\t"
                "2 - добавить животное\n\t"
                "3 - удалить животное";
  cout << menu << endl;
}

void printAnimals(Animal **animals, int size)
{
  if (size == 0)
  {
    cout << "Массив пустой!" << endl;
    return;
  }
  for (int i = 0; i < size; ++i)
  {
    cout << i << ". " << animals[i]->toString() << endl;
  }
}

void addAnimal(Animal **&animals, int &size, int &capacity)
{
  if (size == capacity)
  {
    capacity *= 2;
    Animal **newAnimals = new Animal *[capacity];
    for (int i = 0; i < size; ++i)
    {
      newAnimals[i] = animals[i];
    }
    delete[] animals;
    animals = newAnimals;
  }
  int animalChoice;
  cout << "Выберите животное (1 - Собака, 2 - Кошка, 3 - Черепаха): ";
  cin >> animalChoice;

  if (cin.fail())
  {
    cout << "Некорректный ввод.\n";
    cin.clear();
    cin.ignore(255, '\n');
    return;
  }

  switch (animalChoice)
  {
  case 1:
    animals[size++] = new Dog("", 1, 1, "рыжий", false);
    break;
  case 2:
    animals[size++] = new Cat("", 1, 1, "светлый", false);
    break;
  case 3:
    animals[size++] = new Turtle("", 1, 1);
    break;
  default:
    cout << "Неверный выбор животного.\n";
  }
}

void removeAnimal(Animal **&animals, int &size)
{
  if (size == 0)
  {
    cout << "Массив пустой!\n";
    return;
  }
  int index;
  cout << "Введите индекс животного для удаления (0-" << size - 1 << "): ";
  cin >> index;

  if (cin.fail())
  {
    cout << "Некорректный ввод.\n";
    cin.clear();
    cin.ignore(255, '\n');
    return;
  }

  if (index >= 0 && index < size)
  {
    delete animals[index];
    for (int i = index; i < size - 1; ++i)
    {
      animals[i] = animals[i + 1];
    }
    size--;
  }
  else
  {
    cout << "Неверный индекс!\n";
  }
}
