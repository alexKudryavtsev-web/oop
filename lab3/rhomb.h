#pragma once
#include "point.h"
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

class Rhomb
{
private:
  Point p1, p2, p3, p4;

public:
  Rhomb(const Point &p1, const Point &p2, const Point &p3, const Point &p4) : p1(p1), p2(p2), p3(p3), p4(p4) {}

  double getPerimeter() const
  {
    double side1 = distance(p1, p2);

    double side2 = distance(p2, p3);
    return 2 * (side1 + side2);
  }

  double getArea() const
  {
    double side1 = distance(p1, p2);
    double side2 = distance(p2, p3);
    double side3 = distance(p1, p3);

    double s = (side1 + side2 + side3) / 2;
    double areaTriangle1 = sqrt(s * (s - side1) * (s - side2) * (s - side3));

    return 2 * areaTriangle1;
  }

  bool isValid() const
  {
    if (distance(p1, p2) == 0 || distance(p2, p3) == 0 || distance(p3, p4) == 0 || distance(p4, p1) == 0)
    {
      return false;
    }

    return true;
  }

  const Point &getP1() const { return p1; }
  const Point &getP2() const { return p2; }
  const Point &getP3() const { return p3; }
  const Point &getP4() const { return p4; }

  const Point &getPoint(int i) const
  {
    if (i == 0)
      return p1;
    if (i == 1)
      return p2;
    if (i == 2)
      return p3;
    if (i == 3)
      return p4;
  }
};

bool checkLineSegmentCrossing(const Point &p1, const Point &p2, const Point &p3, const Point &p4)
{
  // Вычисляем определитель
  double denominator = (p2.getX() - p1.getX()) * (p4.getY() - p3.getY()) - (p2.getY() - p1.getY()) * (p4.getX() - p3.getX());
  if (denominator == 0)
  {
    return false; // => параллельны
  }

  double numerator_t = (p4.getX() - p3.getX()) * (p1.getY() - p3.getY()) - (p4.getY() - p3.getY()) * (p1.getX() - p3.getX());
  double numerator_u = (p2.getX() - p1.getX()) * (p1.getY() - p3.getY()) - (p2.getY() - p1.getY()) * (p1.getX() - p3.getX());

  double t = numerator_t / denominator;
  double u = numerator_u / denominator;

  // Проверка, пересекаются ли отрезки внутри
  if ((t >= 0 && t <= 1) && (u >= 0 && u <= 1))
  {
    return true;
  }

  // Проверка, лежит ли конечная точка одного отрезка на другом отрезке
  if ((p1.getX() == p3.getX() && p1.getY() == p3.getY()) || (p1.getX() == p4.getX() && p1.getY() == p4.getY()))
  {
    return true;
  }
  if ((p2.getX() == p3.getX() && p2.getY() == p3.getY()) || (p2.getX() == p4.getX() && p2.getY() == p4.getY()))
  {
    return true;
  }
  if ((p3.getX() == p1.getX() && p3.getY() == p1.getY()) || (p3.getX() == p2.getX() && p3.getY() == p2.getY()))
  {
    return true;
  }
  if ((p4.getX() == p1.getX() && p4.getY() == p1.getY()) || (p4.getX() == p2.getX() && p4.getY() == p2.getY()))
  {
    return true;
  }

  return false;
}

double triangleArea(const Point &a, const Point &b, const Point &c)
{
  return std::abs((a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / 2.0);
}

bool isPointInside(const Rhomb &rhomb, const Point &point)
{
  double area1 = triangleArea(rhomb.getP1(), rhomb.getP2(), point);
  double area2 = triangleArea(rhomb.getP2(), rhomb.getP3(), point);
  double area3 = triangleArea(rhomb.getP3(), rhomb.getP4(), point);
  double area4 = triangleArea(rhomb.getP4(), rhomb.getP1(), point);

  double totalArea = rhomb.getArea();

  return std::abs(area1 + area2 + area3 + area4 - totalArea) < 0.0001; // Малая погрешность
}

// F4
bool checkFigureCrossing(const Rhomb &f1, const Rhomb &f2)
{
  // Проверка пересечения сторон ромбов
  for (int i = 0; i < 4; ++i)
  {
    for (int j = 0; j < 4; ++j)
    {
      if (checkLineSegmentCrossing(f1.getPoint(i), f1.getPoint((i + 1) % 4), f2.getPoint(j), f2.getPoint((j + 1) % 4)))
      {
        return true;
      }
    }
  }

  // Проверка пересечения вершин ромбов
  for (int i = 0; i < 4; ++i)
  {
    if (isPointInside(f2, f1.getPoint(i)))
    {
      return true;
    }
  }
  for (int i = 0; i < 4; ++i)
  {
    if (isPointInside(f1, f2.getPoint(i)))
    {
      return true;
    }
  }

  return false;
}
