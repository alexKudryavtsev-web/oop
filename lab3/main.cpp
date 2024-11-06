// Alexander Kudryavtsev, 5130903/30002, variant 8
// Point, Rhomb: L2, P1, F4

#include <iostream>
#include "point.h"
#include "rhomb.h"
#include "utils.h"
#include "tests.h"

using namespace std;

void handleGetPointsInLine();

void handleGetMaxCirclePoint();

void handleCheckFigureCrossing();

void testGetPointsInLine();

int main()
{
  setlocale(LC_ALL, "Russian");

  string help = "help - показать список команд.\n"
                "\tgetPointsInLine - найти такую прямую, на которой лежат макс-ое кол-во точек.\n"
                "\ttestGetPointsInLine - тест getPointsInLine.\n"
                "\tgetMaxCirclePoint - найти точку, что окружность радиуса R с центром в ней захватит наибольшее количество точек.\n"
                "\ttestGetMaxCirclePoint - тест getMaxCirclePoint.\n"
                "\tcheckFigureCrossing - проверить пересечение ромбов.\n"
                "\ttestCheckFigureCrossing - тест checkFigureCrossing.\n"
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
    else if (command == "getPointsInLine")
    {
      handleGetPointsInLine();
    }
    else if (command == "testGetPointsInLine")
    {
      testGetPointsInLine();
    }
    else if (command == "getMaxCirclePoint")
    {
      handleGetMaxCirclePoint();
    }
    else if (command == "testGetMaxCirclePoint")
    {
      testGetMaxCirclePoint();
    }
    else if (command == "checkFigureCrossing")
    {
      handleCheckFigureCrossing();
    }
    else if (command == "testCheckFigureCrossing")
    {
      testCheckFigureCrossing();
    }
    else
    {
      cout << "Неправильная команда, пожалуйста, попробуйте еще раз." << endl;
    }

    cout << "Введите команду: ";
    cin >> command;
  }
}

void handleGetPointsInLine()
{
  int n;
  cout << "Укажите кол-во точек: ";
  cin >> n;
  if (!checkCorrectInput())
  {
    cout << "Введите корректное число" << endl;
    return;
  }

  Point *arr = new Point[n];

  for (int i = 0; i < n; i++)
  {
    double x, y;
    cout << "Введите x и y точки (через пробел): ";
    cin >> x >> y;

    arr[i] = {x, y};
  }

  int *res;
  int count = getPointsInLine(arr, n, &res);

  cout << "Найдено " << count << " точек: ";

  for (int i = 0; i < count; i++)
  {
    cout << arr[res[i]] << " ";
  }
  cout << endl;

  delete[] arr;
}

void handleGetMaxCirclePoint()
{
  int n;
  cout << "Укажите кол-во точек: ";
  cin >> n;
  if (!checkCorrectInput())
  {
    cout << "Введите корректное число" << endl;
    return;
  }

  if (n <= 0)
  {
    cout << "Введите натуральное число" << endl;
    return;
  }
  double r;
  cout << "Укажите радиус: ";
  cin >> r;
  if (!checkCorrectInput())
  {
    cout << "Введите корректное число" << endl;
    return;
  }

  Point *arr = new Point[n];

  for (int i = 0; i < n; i++)
  {
    double x, y;
    cout << "Введите x и y точки (через пробел): ";
    cin >> x >> y;

    arr[i] = {x, y};
  }

  Point p = getMaxCirclePoint(arr, n, r);

  cout << "Точка: " << p << endl;

  delete arr;
}

void handleCheckFigureCrossing()
{
  double x, y;

  cout << "Введите 4 вершины первого ромба:\n";
  cin >> x >> y;
  Point p1{x, y};
  cin >> x >> y;
  Point p2{x, y};
  cin >> x >> y;
  Point p3{x, y};
  cin >> x >> y;
  Point p4{x, y};
  Rhomb r1{p1, p2, p3, p4};

  if (!r1.isValid())
  {
    cout << "Введенем некорректный ромб\n";
    return;
  }

  cout << "Введите 4 вершины второго ромба:\n";
  cin >> x >> y;
  Point p5{x, y};
  cin >> x >> y;
  Point p6{x, y};
  cin >> x >> y;
  Point p7{x, y};
  cin >> x >> y;
  Point p8{x, y};

  Rhomb r2{p5, p6, p7, p8};
  if (!r2.isValid())
  {
    cout << "Введенем некорректный ромб\n";
    return;
  }

  bool result = checkFigureCrossing(r1, r2);

  if (result)
  {
    cout << "Ромбы пересекаются." << endl;
  }
  else
  {
    cout << "Ромбы не пересекаются." << endl;
  }
}

void testGetPointsInLine()
{
  int n = 5;
  Point arr[] = {{0, 0}, {1, 1}, {2, 2}, {3, 3}, {0, 1}};

  cout << "Точки: ";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  int *res;
  int count = getPointsInLine(arr, n, &res);

  cout << "Найдено " << count << " точек: ";

  for (int i = 0; i < count; i++)
  {
    cout << arr[res[i]] << " ";
  }
  cout << endl;

  cout << "Проверка массива, состоящего из одинаковых элементов" << endl;
  n = 3;
  Point arr1[] = {{1, 1},
                  {1, 1},
                  {1, 1}};

  cout << getPointsInLine(arr1, n, &res) << endl;
}
