// Alexander Kudryavtsev, 5130903/30002, variant 4
// Island
#include <iostream>
#include <vector>
#include <string>

#include "island.h"
#include "island.cpp"
#include "utils.h"
#include "utils.cpp"

using namespace std;

void handleCommand();

int main()
{
  setlocale(LC_ALL, "Russian");

  int v = (int('K') + int('A')) % 8;

  std::vector<Island> islands;

  cout << "Вариант: " << v << endl;

  printMenu();

  int choice;
  do
  {
    cout << "Введите команду: ";
    std::cin >> choice;

    if (std::cin.fail())
    {
      std::cout << "Некорректный ввод. Пожалуйста, введите число.\n";
      std::cin.clear();
      std::cin.ignore(255, '\n');
      continue;
    }

    switch (choice)
    {
    case 0:
      printMenu();
      break;
    case 1:
      break;
    case 2:
    {
      string name;
      int population;
      double area;

      cout << "Укажите название: ";
      cin >> name;

      cout << "Укажите площадь в м^2: ";
      cin >> area;

      cout << "Укажите численность населения: ";
      cin >> population;

      islands.emplace_back(name, area, population);
      std::cout << "Остров добавлен!\n";
      break;
    }
    case 3:
    {
      if (islands.empty())
      {
        std::cout << "Список пустой.\n";
        break;
      }
      std::cout << "Введите номер острова для удаления (с 1): ";
      int index;
      std::cin >> index;
      if (index > 0 && index <= islands.size())
      {
        islands.erase(islands.begin() + index - 1);
        std::cout << "Остров удален!\n";
      }
      else
      {
        std::cout << "Неверный номер острова.\n";
      }
      break;
    }
    case 4:
    {
      if (islands.empty())
      {
        std::cout << "Список пустой.\n";
        break;
      }
      for (size_t i = 0; i < islands.size(); ++i)
      {
        std::cout << i + 1 << ". " << islands[i] << "\n";
      }
      break;
    }
    default:
      cout << "Неверный выбор.\n";
      break;
    }
  } while (choice != 1);

  return 0;
}

void handleCommand() {}