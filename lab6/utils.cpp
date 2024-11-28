#include <iostream>
#include <fstream>
#include <vector>
#include <iostream>
#include <cassert>

#include "utils.h"
#include "island.h"

void printMenu()
{
  std::string menu = "Меню:\n\t"
                     "0  - вывести меню\n\t"
                     "1  - выйти из программы\n\t"
                     "2  - добавить элемент\n\t"
                     "3  - удалить элемент\n\t"
                     "4  - вывести список\n\t"
                     "5  - сортировать список\n\t"
                     "6  - min или max по характеристике\n\t"
                     "7  - агрегировать по характеристике\n\t"
                     "8  - фильтр по пороговому значению\n\t"
                     "9  - поиск элемента по характеристики\n\t"
                     "10 - запись в файл\n\t"
                     "11 - чтение из файла\n\t"
                     "12 - запуск автотестов";
  std::cout << menu << std::endl;
}

void saveIslandsToFile(const std::vector<Island> &islands, const std::string &filePath)
{
  std::ofstream outFile(filePath);
  if (!outFile)
  {
    std::cerr << "Ошибка открытия файла для записи: " << filePath << std::endl;
    return;
  }

  for (const auto &island : islands)
  {
    outFile << island.getName() << '\n'
            << island.getArea() << '\n'
            << island.getPopulation() << '\n';
  }

  outFile.close();
}

void loadIslandsFromFile(std::vector<Island> &islands, const std::string &filePath)
{
  std::ifstream inFile(filePath);
  if (!inFile)
  {
    std::cerr << "Ошибка открытия файла для чтения: " << filePath << std::endl;
    return;
  }

  islands.clear(); // Очищаем вектор перед загрузкой новых данных
  std::string name;
  double area;
  int population;

  while (std::getline(inFile, name))
  {
    if (inFile >> area >> population)
    {
      inFile.ignore();
      islands.emplace_back(name, area, population);
    }
  }

  inFile.close();
}

double aggregateIslands(const std::vector<Island> &islands, int agg_choice, int characteristic_choice)
{
  if (islands.empty())
  {
    return 0;
  }

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
    return sum;
  }
  else
  {
    return sum / islands.size();
  }
}

void testAggregateIslands()
{
  std::vector<Island> islands;
  islands.emplace_back("Island1", 10.0, 100);
  islands.emplace_back("Island2", 20.0, 200);
  islands.emplace_back("Island3", 30.0, 300);

  // Test case 1: Нормальный вектор 
  assert(aggregateIslands(islands, 1, 1) == 60.0);
  assert(aggregateIslands(islands, 2, 1) == 20.0);
  assert(aggregateIslands(islands, 1, 2) == 600);
  assert(aggregateIslands(islands, 2, 2) == 200);

  // Test case 5: Пустой вектор
  std::vector<Island> emptyIslands;
  assert(aggregateIslands(emptyIslands, 1, 1) == 0.0);
  assert(aggregateIslands(emptyIslands, 2, 1) == 0.0);

  // Test case 6: Вектор с одним значением
  std::vector<Island> oneIsland;
  oneIsland.emplace_back("Island1", 100.0, 1000);
  assert(aggregateIslands(oneIsland, 1, 1) == 100.0);
  assert(aggregateIslands(oneIsland, 2, 1) == 100.0);
  assert(aggregateIslands(oneIsland, 1, 2) == 1000);
  assert(aggregateIslands(oneIsland, 2, 2) == 1000);

  std::cout << "All test cases passed!" << std::endl;
}
