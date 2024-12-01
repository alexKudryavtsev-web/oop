#include "utils.h"
#include <iostream>
#include <typeinfo>

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
                "5 - вывести информацию о животном\n\t"
                "6 - количество объектов каждого типа (без учёта наследования и возможности преобразования)\n\t"
                "7 - количество объектов заднного типа (с учётом наследования)\n\t";

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
    cin >> wild;

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
    cin >> wild;
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

int countObjectsOfTypeRTTI(Animal **animals, int size, const type_info &type)
{
  int count = 0;
  for (int i = 0; i < size; ++i)
  {
    if (animals[i] != nullptr && typeid(*animals[i]) == type)
    {
      count++;
    }
  }
  return count;
}

int countAnimalsOfTypeInherited(Animal **animals, int size, const std::type_info &type)
{
  if (type == typeid(Animal))
  {
    return size;
  }

  int count = 0;
  for (int i = 0; i < size; ++i)
  {
    if (animals[i] == nullptr)
      break;

    if (type == typeid(Mammal))
    {
      if (dynamic_cast<Mammal *>(animals[i]) != nullptr)
        count++;
    }
    else if (type == typeid(Reptile))
    {
      if (dynamic_cast<Reptile *>(animals[i]) != nullptr)
        count++;
    }
    else if (typeid(*animals[i]) == type)
    {
      count++;
    }
  }
  return count;
}

void processCountObjectsOfEachType(Animal **animals, int size)
{
  if (size == 0)
  {
    cout << "Массив пустой" << endl;
    return;
  }
  cout << "\tAnimal: " << countObjectsOfTypeRTTI(animals, size, typeid(Animal)) << endl;
  cout << "\tMammal: " << countObjectsOfTypeRTTI(animals, size, typeid(Mammal)) << endl;
  cout << "\tReptil: " << countObjectsOfTypeRTTI(animals, size, typeid(Reptile)) << endl;
  cout << "\tDog:    " << countObjectsOfTypeRTTI(animals, size, typeid(Dog)) << endl;
  cout << "\tCat:    " << countObjectsOfTypeRTTI(animals, size, typeid(Cat)) << endl;
  cout << "\tTurtle: " << countObjectsOfTypeRTTI(animals, size, typeid(Turtle)) << endl;
}

void processCountObjectsOfType(Animal **animals, int size)
{
  if (size == 0)
  {
    cout << "Массив пустой" << endl;
    return;
  }
  int choice;
  cout << "Выберите тип:" << endl;
  cout << "\t0 - Animal" << endl;
  cout << "\t1 - Mammal" << endl;
  cout << "\t2 - Reptile" << endl;
  cout << "\t3 - Dog" << endl;
  cout << "\t4 - Cat" << endl;
  cout << "\t5 - Turtle" << endl;
  cin >> choice;
  CHECK_INPUT_FAIL();

  switch (choice)
  {
  case 0:
    cout << "Результат: " << countAnimalsOfTypeInherited(animals, size, typeid(Animal)) << endl;
    break;
  case 1:
    cout << "Результат: " << countAnimalsOfTypeInherited(animals, size, typeid(Mammal)) << endl;
    break;
  case 2:
    cout << "Результат: " << countAnimalsOfTypeInherited(animals, size, typeid(Reptile)) << endl;
    break;
  case 3:
    cout << "Результат: " << countAnimalsOfTypeInherited(animals, size, typeid(Dog)) << endl;
    break;
  case 4:
    cout << "Результат: " << countAnimalsOfTypeInherited(animals, size, typeid(Cat)) << endl;
    break;
  case 5:
    cout << "Результат: " << countAnimalsOfTypeInherited(animals, size, typeid(Turtle)) << endl;
    break;
  default:
    break;
  }
}
