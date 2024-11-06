#pragma once
#include "point.h"
#include "rhomb.h"
#include <iostream>

using namespace std;

struct TestCheckFugireCase
{
  Rhomb r1;
  Rhomb r2;
  bool result;
};

void testCheckFigureCrossing()
{
  struct TestCheckFugireCase tests[] = {
      // Тест 1: Пересекаются
      {{Point(0, 0), Point(1, 1), Point(0, 2), Point(-1, 1)}, {Point(0, 1), Point(1, -0.5), Point(0, -2), Point(-1, -0.5)}, true},
      // Тест 2: Не пересекаются
      {{Point(0, 0), Point(1, 1), Point(0, 2), Point(-1, 1)}, {Point(2, 1), Point(3, 2), Point(2, 3), Point(1, 2)}, false},

      // Тест 3: Пересекаются в одной точке
      {{Point(-2, 1), Point(-4, 2), Point(-5, 4), Point(-3, 3)}, {Point(-2, 1), Point(-1, -1), Point(-2, -3), Point(-3, -1)}, true},
      // Тест 4: Вершина лежит внутри другого ромба
      {{Point(2, -2), Point(3, 0), Point(2, 2), Point(1, 0)}, {Point(0, -2), Point(2, -3), Point(3, -2), Point(2, -1)}, true},
      // Тест 5: Ромб лежит внутри другого ромба
      {{Point(-1, 0), Point(0, 1), Point(1, 0), Point(0, -1)}, {Point(-2, 0), Point(0, 2), Point(2, 0), Point(0, -2)}, true},

      // Тест 6: без поворота
      {{Point(0, 0), Point(1, 2), Point(0, 4), Point(-1, 2)}, {Point(-3, 1), Point(-2, 2), Point(-2, 3), Point(-3, 2)}, false},
      // Тест 7: поворот на 45 градусов (влево)
      {{Point(0, 0), Point(-2, 1), Point(-3, 3), Point(-2, 2)}, {Point(-3, 1), Point(-2, 2), Point(-2, 3), Point(-3, 2)}, true},
      // Тест 8: поворот на 90 градусов (влево)
      {{Point(0, 0), Point(-2, -1), Point(-4, 0), Point(-2, 1)}, {Point(-3, 1), Point(-2, 2), Point(-2, 3), Point(-3, 2)}, false},
      // Тест 9: До отображения относительно y = -x
      {{Point(1, 1), Point(3, 2), Point(4, 4), Point(2, 3)}, {Point(0, 1), Point(1, 2), Point(2, 1), Point(1, 0)}, true},
      // Тест 10: После отображения относительно y = -x
      {{Point(-1, -1), Point(-3, -2), Point(-4, -4), Point(-2, -3)}, {Point(0, 1), Point(1, 2), Point(2, 1), Point(1, 0)}, false},
      // Тест 11: Вырожденные ромбы
      {{Point(1, 1), Point(3, 3), Point(5, 5), Point(3, 3)}, {Point(3, 1), Point(4, 3), Point(3, 5), Point(2, 3)}, true},
  };

  for (int i = 0; i < 11; i++)
  {
    std::cout << "№" << i + 1 << " have: " << checkFigureCrossing(tests[i].r1, tests[i].r2) << " wanted: " << tests[i].result << std::endl;
  }
}

struct TestGetMaxCirclePointCase
{
  int r;
  int size;
  Point *arr;
  Point result;
};

void testGetMaxCirclePoint()
{
  Point arr1[] = {{2, 3},
                  {2, 2},
                  {1, 3},
                  {2, 4},
                  {3, 3},
                  {5, 1}};

  Point arr2[] = {{1, 2},
                  {1, 5}};

  struct TestGetMaxCirclePointCase tests[] =
      {
          {2, 6, arr1, {2, 3}},
          {0, 6, arr1, {2, 3}},
          {4, 2, arr2, {1, 2}},
      };

  for (int i = 0; i < 3; i++)
  {
    cout << "have: " << getMaxCirclePoint(tests[i].arr, tests[i].size, tests[i].r) << " wanted: " << tests[i].result << endl;
  }
}
