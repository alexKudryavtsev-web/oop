#pragma once
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

class Point
{
private:
  double x, y;

public:
  Point() : x(0), y(0) {}

  Point(double x, double y) : x(x), y(y) {}

  double getX() const
  {
    return x;
  }

  double getY() const
  {
    return y;
  }

  friend std::istream& operator<<(std::istream& is, Point& person);
};

std::ostream& operator<<(std::ostream& os, const Point& obj) {
    // Вывод значений полей объекта
    os << "(" << obj.getX() << ", " << obj.getY() << ")"; 
    return os;
}


double distance(const Point &p1, const Point &p2)
{
  return sqrt(pow(p2.getX() - p1.getX(), 2) + pow(p2.getY() - p1.getY(), 2));
}

// P1:
Point getMaxCirclePoint(Point *points, int size, int R)
{
  int maxCount = 0;
  Point maxPoint = points[0];

  for (int i = 0; i < size; ++i)
  {
    int count = 0;
    for (int j = 0; j < size; ++j)
    {
      if (distance(points[i], points[j]) <= R)
      {
        count++;
      }
    }

    if (count > maxCount)
    {
      maxCount = count;
      maxPoint = points[i];
    }
  }

  return maxPoint;
}

bool areCollinear(const Point &p1, const Point &p2, const Point &p3)
{
  double slope1 = (p2.getY() - p1.getY()) / (p2.getX() - p1.getX());
  double slope2 = (p3.getY() - p2.getY()) / (p3.getX() - p2.getX());
  return std::abs(slope1 - slope2) < 0.000000001;
}

// L2:
int getPointsInLine(Point *points, int size, int **indices)
{
  if (size <= 1)
  {
    *indices = nullptr;
    return size;
  }

  int maxCount = 2;
  int *maxIndices = new int[2];
  maxIndices[0] = 0;
  maxIndices[1] = 1;

  for (int i = 0; i < size; i++)
  {
    for (int j = i + 1; j < size; j++)
    {
      int currentCount = 2;
      int *currentIndices = new int[size];
      currentIndices[0] = i;
      currentIndices[1] = j;

      for (int k = 0; k < size; k++)
      {
        if (k != i && k != j && areCollinear(points[i], points[j], points[k]))
        {
          currentIndices[currentCount++] = k;
        }
      }

      if (currentCount > maxCount)
      {
        maxCount = currentCount;
        delete[] maxIndices;
        maxIndices = new int[maxCount];
        for (int k = 0; k < maxCount; k++)
        {
          maxIndices[k] = currentIndices[k];
        }
      }

      delete[] currentIndices;
    }
  }

  *indices = maxIndices;
  return maxCount;
}