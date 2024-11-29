#include <iostream>
#include <fstream>
#include <vector>
#include <iostream>
#include <cassert>

#include "utils.h"
#include "island.h"

// Компараторы
bool compareByName(const Island &a, const Island &b) { return a.getName() < b.getName(); }
bool compareByArea(const Island &a, const Island &b) { return a.getArea() < b.getArea(); }
bool compareByPopulation(const Island &a, const Island &b) { return a.getPopulation() < b.getPopulation(); }

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

// 13 тестов
// Для этого теста замокан файл test-set.txt!
void testLoadIslandsFromFile()
{
  std::vector<Island> res;
  std::string testDataSet = "test-set.txt";

  loadIslandsFromFile(res, testDataSet);

  assert(res.size() == 3);

  assert(res[0].getName() == "Island1");
  assert(res[0].getPopulation() == 100);
  assert(res[0].getArea() == 10);

  assert(res[1].getName() == "Island2");
  assert(res[1].getPopulation() == 200);
  assert(res[1].getArea() == 20);

  assert(res[2].getName() == "Island3");
  assert(res[2].getPopulation() == 300);
  assert(res[2].getArea() == 30);

  std::cout << "testLoadIslandsFromFile: All test cases passed!" << std::endl;
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

// 16 тестов
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
  assert(aggregateIslands(emptyIslands, 1, 2) == 0.0);
  assert(aggregateIslands(emptyIslands, 2, 2) == 0.0);

  // Test case 6: Вектор с одним значением
  std::vector<Island> oneIsland;
  oneIsland.emplace_back("Island1", 100.0, 1000);
  assert(aggregateIslands(oneIsland, 1, 1) == 100.0);
  assert(aggregateIslands(oneIsland, 2, 1) == 100.0);
  assert(aggregateIslands(oneIsland, 1, 2) == 1000);
  assert(aggregateIslands(oneIsland, 2, 2) == 1000);

  std::cout << "testAggregateIslands: All test cases passed!" << std::endl;
}

Island getExtremumValue(const std::vector<Island> &islands, int extremum_choice, int characteristic_choice)
{
  if (islands.empty())
  {
    return Island();
  }
  auto compare_func = (characteristic_choice == 1) ? compareByArea : compareByPopulation;
  auto it = (extremum_choice == 1) ? std::min_element(islands.begin(), islands.end(), compare_func) : std::max_element(islands.begin(), islands.end(), compare_func);

  return *it;
}

// 16 тестов
void testExtremumValue()
{
  std::vector<Island> islands;
  islands.emplace_back("Island1", 10.0, 100);
  islands.emplace_back("Island2", 20.0, 200);
  islands.emplace_back("Island3", 30.0, 300);

  // Min Area
  Island minArea = getExtremumValue(islands, 1, 1);
  assert(minArea.getArea() == 10.0);
  // Max Area
  Island maxArea = getExtremumValue(islands, 2, 1);
  assert(maxArea.getArea() == 30.0);
  // Min Population
  Island minPop = getExtremumValue(islands, 1, 2);
  assert(minPop.getPopulation() == 100);
  // Max Population
  Island maxPop = getExtremumValue(islands, 2, 2);
  assert(maxPop.getPopulation() == 300);

  // Пустой вектор
  std::vector<Island> emptyIslands;
  Island emptyResult1 = getExtremumValue(emptyIslands, 1, 1);
  assert(emptyResult1.getArea() == 0.0 && emptyResult1.getPopulation() == 0);

  Island emptyResult2 = getExtremumValue(emptyIslands, 2, 1);
  assert(emptyResult2.getArea() == 0.0 && emptyResult2.getPopulation() == 0);

  Island emptyResult3 = getExtremumValue(emptyIslands, 1, 2);
  assert(emptyResult3.getArea() == 0.0 && emptyResult3.getPopulation() == 0);

  Island emptyResult4 = getExtremumValue(emptyIslands, 2, 2);
  assert(emptyResult4.getArea() == 0.0 && emptyResult4.getPopulation() == 0);

  // Вектор с одним значением
  std::vector<Island> oneIsland;
  oneIsland.emplace_back("Island1", 100.0, 1000);
  assert(getExtremumValue(oneIsland, 1, 1).getArea() == 100.0);
  assert(getExtremumValue(oneIsland, 2, 1).getArea() == 100.0);
  assert(getExtremumValue(oneIsland, 1, 2).getPopulation() == 1000);
  assert(getExtremumValue(oneIsland, 2, 2).getPopulation() == 1000);

  std::cout << "testExtremumValue: All test cases passed!" << std::endl;
}

std::vector<Island> filterByValue(const std::vector<Island> &islands, double threshold, int characteristic_choice)
{
  if (islands.empty())
  {
    return islands;
  }
  auto filtered_islands = [](const Island &i, double t, int c)
  {
    return (c == 1) ? i.getArea() > t : i.getPopulation() > t;
  };

  std::vector<Island> result;
  copy_if(islands.begin(), islands.end(), back_inserter(result),
          [&](const Island &i)
          { return filtered_islands(i, threshold, characteristic_choice); });

  return result;
}

// 8 тестов
void testFilterByValue()
{
  std::vector<Island> islands;
  islands.emplace_back("Island1", 10.0, 100);
  islands.emplace_back("Island2", 20.0, 200);
  islands.emplace_back("Island3", 30.0, 300);
  islands.emplace_back("Island4", 40.0, 400);

  // По площади
  std::vector<Island> filteredByArea = filterByValue(islands, 25.0, 1);
  assert(filteredByArea.size() == 2);
  assert(filteredByArea[0].getArea() == 30.0);
  assert(filteredByArea[1].getArea() == 40.0);
  // По населению
  std::vector<Island> filteredByPopulation = filterByValue(islands, 350, 2);
  assert(filteredByPopulation.size() == 1);
  assert(filteredByPopulation[0].getPopulation() == 400);
  assert(filteredByPopulation[0].getArea() == 40.0);

  // Пустой
  std::vector<Island> emptyIslands;
  std::vector<Island> filteredEmpty = filterByValue(emptyIslands, 10, 1);
  assert(filteredEmpty.empty());

  // Ни один не подходит
  std::vector<Island> noMatches = filterByValue(islands, 1000, 1);
  assert(noMatches.empty());

  std::cout << "testFilterByValue: All test cases passed!" << std::endl;
}
