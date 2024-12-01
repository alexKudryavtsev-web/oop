#include "utils.h"
#include <iostream>

#define CHECK_INPUT_FAIL()                \
  if (cin.fail())                         \
  {                                       \
    cout << "Некорректный ввод." << endl; \
    cin.clear();                          \
    cin.ignore(255, '\n');                \
    return;                               \
  }

using namespace std;

void help()
{
  string menu = "Меню:\n\t"
                "0 - показать меню\n\t"
                "1 - выйти из программы\n\t"
                "2 - добавить животное\n\t"
                "3 - удалить животное\n\t"
                "4 - вывести информацию о всех животных\n\t"
                "5 - вывести информацию о животном\n\t";
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
  CHECK_INPUT_FAIL()

  string name;
  cout << "Введите имя животного: ";
  cin >> name;

  double weight;
  cout << "Введите вес животного (в кг): ";
  cin >> weight;
  CHECK_INPUT_FAIL()

  int age;
  cout << "Введите возраст животного (кол-во целых лет): ";
  cin >> age;
  CHECK_INPUT_FAIL()

  switch (animalChoice)
  {
  case 1:
  {
    string fur;
    cout << "Введите цвет шерсти: ";
    cin >> fur;
    CHECK_INPUT_FAIL()

    string wild;
    cout << "Укажите, собака дикая (да/нет): ";
    std::cin >> wild;

    animals[size++] = new Dog(name, weight, age, fur, wild == "да");
    break;
  }
  case 2:
  {
    string fur;
    cout << "Введите цвет шерсти: ";
    cin >> fur;
    CHECK_INPUT_FAIL()

    string wild;
    cout << "Укажите: кот дикий (да/нет): ";
    std::cin >> wild;
    CHECK_INPUT_FAIL()

    animals[size++] = new Cat(name, weight, age, fur, wild == "да");
    break;
  }
  case 3:
    animals[size++] = new Turtle(name, weight, age);
    break;
  default:
    cout << "Неверный выбор животного." << endl;
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
  CHECK_INPUT_FAIL()

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

void printAnimalInfo(Animal **animals, int size)
{
  if (size == 0)
  {
    cout << "Массив пустой!" << endl;
    return;
  }
  int index;
  cout << "Введите индекс животного для просмотра информации (0-" << size - 1 << "): ";
  cin >> index;
  CHECK_INPUT_FAIL()

  if (index >= 0 && index < size)
  {
    cout << animals[index]->toString() << endl;
  }
  else
  {
    cout << "Неверный индекс!\n";
  }
}
