#pragma once
#include "point.h"
#include <cmath>

using namespace std;

class Rhomb
{
private:
  Point p1, p2, p3;

public:
  Rhomb(const Point &p1, const Point &p2, const Point &p3) : p1(p1), p2(p2), p3(p3) {}

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

  const Point &getP1() const { return p1; }
  const Point &getP2() const { return p2; }
  const Point &getP3() const { return p3; }
};

Point project(const Point &point, const Point &start, const Point &end);

bool isPointOnSegment(const Point &point, const Point &start, const Point &end);

// F4
bool checkFigureCrossing(const Rhomb &f1, const Rhomb &f2)
{
  Point p1 = f1.getP1();
  Point p2 = f1.getP2();
  Point p3 = f1.getP3();

  Point p4 = f2.getP1();
  Point p5 = f2.getP2();
  Point p6 = f2.getP3();

  Point center1 = {(p1.getX() + p2.getX() + p3.getX()) / 3, (p1.getY() + p2.getY() + p3.getY()) / 3};
  Point center2 = {(p4.getX() + p5.getX() + p6.getX()) / 3, (p4.getY() + p5.getY() + p6.getY()) / 3};

  double radius1 = sqrt(pow(p1.getX() - center1.getX(), 2) + pow(p1.getY() - center1.getY(), 2));
  double radius2 = sqrt(pow(p4.getX() - center2.getX(), 2) + pow(p4.getY() - center2.getY(), 2));

  Point projection1 = project(center2, p1, p2);
  Point projection2 = project(center1, p4, p5);

  if (isPointOnSegment(projection1, p1, p2) && distance(projection1, center2) <= radius2)
  {
    return true;
  }

  if (isPointOnSegment(projection2, p4, p5) && distance(projection2, center1) <= radius1)
  {
    return true;
  }

  return false;
}

Point project(const Point &point, const Point &start, const Point &end)
{
  double dx = end.getX() - start.getX();
  double dy = end.getY() - start.getY();
  double len2 = dx * dx + dy * dy;
  double dot = (point.getX() - start.getX()) * dx + (point.getY() - start.getY()) * dy;
  double t = dot / len2;

  if (t < 0)
  {
    return start;
  }
  else if (t > 1)
  {
    return end;
  }
  else
  {
    return {start.getX() + t * dx, start.getY() + t * dy};
  }
}

bool isPointOnSegment(const Point &point, const Point &start, const Point &end)
{
  return (point.getX() >= min(start.getX(), end.getX()) && point.getX() <= max(start.getX(), end.getX()) &&
          point.getY() >= min(start.getY(), end.getY()) && point.getY() <= max(start.getY(), end.getY()));
}