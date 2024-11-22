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

using namespace std;

void handleCommand();

int main()
{
  setlocale(LC_ALL, "Russian");

  Cat cat("Белячок", 3.4, 1, "белый", true);
  cout << cat.toString() << endl;
  cat.setIsWild(false);
  cout << cat.toString() << endl;

  cout << Cat::getCatCount() << endl;

  {
    Cat c("d", 1, 1, "", false);
    cout << Cat::getCatCount() << endl;
  }

  cout << Cat::getCatCount() << endl;
  {
    Dog dog("Бим", 10, 3, "коричневый", false);
    cout << dog.toString() << endl;

    cout << Dog::getDogCount() << endl;
  }

  cout << Dog::getDogCount() << endl;

  {
    cout << People::getPeopleCount() << endl;
    People person("Иван", 80.5, 35, "Россия");
    cout << person.toString() << std::endl;
    cout << "Страна: " << person.getCountry() << std::endl;

    cout << People::getPeopleCount() << endl;
  }

  cout << People::getPeopleCount() << endl;
  Turtle turtle("Крутая", 1, 1);
  cout << turtle.toString() << std::endl;

  return 0;
  int V = (10 * int('K') + int('A')) % 11;

  cout << V;

  string help = "help - показать список команд.\n"
                "\tcommand - команда.\n"
                "\texit - выйти из программы.";

  cout << "Привет!\n\t" << help << endl;
  string command;

  cout << "Введите команду: ";
  cin >> command;

  while (command != "exit")
  {
    if (command == "help")
    {
      cout << help << endl;
    }
    else if (command == "command")
    {
      handleCommand();
    }
    else
    {
      cout << "Неправильная команда, пожалуйста, попробуйте еще раз." << endl;
    }

    cout << "Введите команду: ";
    cin >> command;
  }
}

void handleCommand() {}