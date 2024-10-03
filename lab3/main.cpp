// Alexander Kudryavtsev, 5130903/30002, variant 8
// Point, Rhomb: L2, P1, F4

#include <iostream>
#include "point.h"
#include "rhomb.h"

using namespace std;

void handleGetPointsInLine();

void handleGetMaxCirclePoint();

void handleCheckFigureCrossing();

int main()
{
  setlocale(LC_ALL, "Russian");

  string help = "help - показать список команд.\n"
                "\tgetPointsInLine - найти такую прямую, на которой лежат макс-ое кол-во точек.\n"
                "\tgetMaxCirclePoint - найти точку, что окружность радиуса R с центром в ней захватит наибольшее количество точек.\n"
                "\tcheckFigureCrossing - проверить пересечение ромбов.\n"
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
    else if (command == "getMaxCirclePoint")
    {
      handleGetMaxCirclePoint();
    }
    else if (command == "checkFigureCrossing")
    {
      handleCheckFigureCrossing();
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
    cout << res[i] << " ";
  }
  cout << endl;

  delete[] arr;
}

void handleGetMaxCirclePoint()
{
  int n;
  cout << "Укажите кол-во точек: ";
  cin >> n;

  double r;
  cout << "Укажите радиус: ";
  cin >> r;

  Point *arr = new Point[n];

  for (int i = 0; i < n; i++)
  {
    double x, y;
    cout << "Введите x и y точки (через пробел): ";
    cin >> x >> y;

    arr[i] = {x, y};
  }

  Point p = getMaxCirclePoint(arr, n, r);

  cout << "Точка: (" << p.getX() << ", " << p.getY() << ")" << endl;
}

void handleCheckFigureCrossing()
{
  double x, y;

  cout << "Введите 3 вершины первого ромба:\n";
  cin >> x >> y;
  Point p1{x, y};
  cin >> x >> y;
  Point p2{x, y};
  cin >> x >> y;
  Point p3{x, y};
  Rhomb r1{p1, p2, p3};

  cout << "Введите 3 вершины второго ромба:\n";
  cin >> x >> y;
  Point p4{x, y};
  cin >> x >> y;
  Point p5{x, y};
  cin >> x >> y;
  Point p6{x, y};

  Rhomb r2{p4, p5, p6};

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