#include <iostream>
#include <fstream>
#include <vector>
#include <iostream>

#include "utils.h"
#include "island.h"

void printMenu()
{
  std::string menu = "Меню:\n\t"
                     "0 - вывести меню\n\t"
                     "1 - выйти из программы\n\t"
                     "2 - добавить элемент\n\t"
                     "3 - удалить элемент\n\t"
                     "4 - вывести список\n\t"
                     "5 - сортировать список\n\t"
                     "6 - поиск макс. или мин. элемента\n\t"
                     "7 - фильтр по пороговому значению\n\t"
                     "8 - поиск элемента по характеристики\n\t"
                     "9 - запись в файл\n\t"
                     "10 - чтение из файла";
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
      inFile.ignore(); // Игнорируем символ новой строки после числа
      islands.emplace_back(name, area, population);
    }
  }

  inFile.close();
}