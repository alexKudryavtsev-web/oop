#pragma once
#include <iostream>

using namespace std;

bool checkCorrectInput()
{
  if (cin.fail())
  {
    cin.clear();
    cin.ignore(256, '\n');
  }

  while (cin.peek() != '\n')
  {
    if (cin.peek() != ' ')
    {
      cin.ignore(256, '\n');
      return false;
    }
    else
    {
      cin.ignore(1);
    }
  }

  return true;
}
