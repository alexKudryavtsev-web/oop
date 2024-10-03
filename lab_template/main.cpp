// Alexander Kudryavtsev, 5130903/30002, variant 8
// Point, Rhomb: L2, P1, F4

#include <iostream>
#include "point.h"
#include "rhomb.h"

using namespace std;

void handleCommand();

int main()
{
  setlocale(LC_ALL, "Russian");

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