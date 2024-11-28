// Alexander Kudryavtsev, 5130903/30002, variant 4
// Island
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <limits>

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

  vector<Island> islands;

  cout << "Вариант: " << v << endl;

  printMenu();

  int choice;
  do
  {
    cout << "Введите команду: ";
    cin >> choice;

    if (cin.fail())
    {
      cout << "Некорректный ввод. Пожалуйста, введите число.\n";
      cin.clear();
      cin.ignore(255, '\n');
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
      cout << "Остров добавлен!\n";
      break;
    }
    case 3:
    {
      if (islands.empty())
      {
        cout << "Список пустой.\n";
        break;
      }
      cout << "Введите номер острова для удаления (с 1): ";
      int index;
      cin >> index;
      if (index > 0 && index <= islands.size())
      {
        islands.erase(islands.begin() + index - 1);
        cout << "Остров удален!\n";
      }
      else
      {
        cout << "Неверный номер острова.\n";
      }
      break;
    }
    case 4:
    {
      if (islands.empty())
      {
        cout << "Список пустой.\n";
        break;
      }
      for (size_t i = 0; i < islands.size(); ++i)
      {
        cout << i + 1 << ". " << islands[i] << "\n";
      }
      break;
    }
    case 5:
    {
      if (islands.empty())
      {
        cout << "Список пустой.\n";
        break;
      }
      int sort_choice;
      cout << "Выберите характеристику для сортировки:\n";
      cout << "1. По имени\n";
      cout << "2. По площади\n";
      cout << "3. По населению\n";
      cin >> sort_choice;
      switch (sort_choice)
      {
      case 1:
        sort(islands.begin(), islands.end(), compareByName);
        break;
      case 2:
        sort(islands.begin(), islands.end(), compareByArea);
        break;
      case 3:
        sort(islands.begin(), islands.end(), compareByPopulation);
        break;
      default:
        cout << "Неверный выбор.\n";
      }
      cout << "Острова отсортированы!\n";
      break;
    }
    case 6:
    {
      if (islands.empty())
      {
        cout << "Список пустой.\n";
        break;
      }
      int agg_choice, characteristic_choice;
      cout << "Выберите функцию:\n";
      cout << "1. Сумма\n";
      cout << "2. Среднее\n";
      cin >> agg_choice;
      cout << "Выберите характеристику:\n";
      cout << "1. Площадь\n";
      cout << "2. Население\n";
      cin >> characteristic_choice;

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
        cout << "Суммарное значение: " << sum << endl;
      }
      else
      {
        cout << "Среднее значение: " << sum / islands.size() << endl;
      }
      break;
    }
    case 7:
    {
      if (islands.empty())
      {
        cout << "Список пустой.\n";
        break;
      }
      int characteristic_choice;
      double threshold;
      cout << "Выберите характеристику для отбора:\n";
      cout << "1. Площадь\n";
      cout << "2. Население\n";
      cin >> characteristic_choice;
      cout << "Введите пороговое значение: ";
      cin >> threshold;

      auto filtered_islands = [](const Island &i, double t, int c)
      {
        return (c == 1) ? i.getArea() > t : i.getPopulation() > t;
      };

      vector<Island> result;
      copy_if(islands.begin(), islands.end(), back_inserter(result),
              [&](const Island &i)
              { return filtered_islands(i, threshold, characteristic_choice); });

      if (result.empty())
      {
        cout << "Островов, удовлетворяющих условию, нет.\n";
      }
      else
      {
        for (size_t i = 0; i < result.size(); ++i)
        {
          cout << i + 1 << ". " << result[i] << "\n";
        }
      }
      break;
    }
    case 8:
    {
      if (islands.empty())
      {
        cout << "Список островов пуст.\n";
        break;
      }
      int characteristic_choice;
      double value;
      cout << "Выберите характеристику для поиска:\n";
      cout << "1. Площадь\n";
      cout << "2. Население\n";
      cin >> characteristic_choice;

      // Проверка на корректность ввода characteristic_choice
      if (cin.fail() || (characteristic_choice != 1 && characteristic_choice != 2))
      {
        cout << "Некорректный ввод. Пожалуйста, введите 1 или 2.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
      }

      cout << "Введите значение: ";
      cin >> value;
      // Проверка на корректность ввода value
      if (cin.fail())
      {
        cout << "Некорректный ввод. Пожалуйста, введите число.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
      }

      auto it = find_if(islands.begin(), islands.end(),
                        [&](const Island &i)
                        {
                          return (characteristic_choice == 1) ? i.getArea() == value : i.getPopulation() == value;
                        });

      if (it != islands.end())
      {
        cout << "Найденный остров:\n";
        cout << *it << endl; // Используем перегруженный оператор << для вывода
      }
      else
      {
        cout << "Остров с таким значением не найден.\n";
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
