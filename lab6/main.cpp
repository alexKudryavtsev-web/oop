// Alexander Kudryavtsev, 5130903/30002, variant 4
// Island
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "island.h"
#include "island.cpp"
#include "utils.h"
#include "utils.cpp"

using namespace std;

// Компараторы
bool compareByName(const Island &a, const Island &b) { return a.getName() < b.getName(); }
bool compareByArea(const Island &a, const Island &b) { return a.getArea() < b.getArea(); }
bool compareByPopulation(const Island &a, const Island &b) { return a.getPopulation() < b.getPopulation(); }

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
    case 5:
    {
      if (islands.empty())
      {
        std::cout << "Список пустой.\n";
        break;
      }
      int sort_choice;
      std::cout << "Выберите характеристику для сортировки:\n";
      std::cout << "1. По имени\n";
      std::cout << "2. По площади\n";
      std::cout << "3. По населению\n";
      std::cin >> sort_choice;
      switch (sort_choice)
      {
      case 1:
        std::sort(islands.begin(), islands.end(), compareByName);
        break;
      case 2:
        std::sort(islands.begin(), islands.end(), compareByArea);
        break;
      case 3:
        std::sort(islands.begin(), islands.end(), compareByPopulation);
        break;
      default:
        std::cout << "Неверный выбор.\n";
      }
      std::cout << "Острова отсортированы!\n";
      break;
    }
    case 6:
    {
      if (islands.empty())
      {
        std::cout << "Список пустой.\n";
        break;
      }
      int agg_choice, characteristic_choice;
      std::cout << "Выберите функцию:\n";
      std::cout << "1. Сумма\n";
      std::cout << "2. Среднее\n";
      std::cin >> agg_choice;
      std::cout << "Выберите характеристику:\n";
      std::cout << "1. Площадь\n";
      std::cout << "2. Население\n";
      std::cin >> characteristic_choice;

      double sum = 0;
      if (characteristic_choice == 1)
      {
        for (const auto &island : islands)
          sum += island.getArea();
      }
      else
      {
        for (const auto &island : islands)
          sum += island.getPopulation();
      }

      if (agg_choice == 1)
      {
        std::cout << "Суммарное значение: " << sum << std::endl;
      }
      else
      {
        std::cout << "Среднее значение: " << sum / islands.size() << std::endl;
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