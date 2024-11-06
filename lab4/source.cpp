// Alexander Kudryavtsev, 5130903/3002, variant 3: MaxHeap
#include <iostream>
#include "MaxHeap.h"
#include "MaxHeap.cpp"

using namespace std;

void showMenu();

int main()
{
  MaxHeap heap;
  showMenu();

  while (true)
  {
    int choice;
    cout << "Введите номер операции: ";
    cin >> choice;

    switch (choice)
    {
    case 0:
      showMenu();
      break;
    case 1:
    {
      int value;
      cout << "Введите значение элемента: ";
      cin >> value;
      heap.add(value);
      break;
    }
    case 2:
    {
      int maxValue;
      if (heap.get(maxValue))
      {
        cout << "Извлеченный максимальный элемент: " << maxValue << endl;
      }
      else
      {
        cout << "Куча пуста!" << endl;
      }
      break;
    }
    case 3:
    {
      int maxValue;
      if (heap.peek(maxValue))
      {
        cout << "Максимальный элемент: " << maxValue << endl;
      }
      else
      {
        cout << "Куча пуста!" << endl;
      }
      break;
    }
    case 4:
    {
      int value, *buffer;
      cout << "Введите значение для извлечения: ";
      cin >> value;
      int count = heap.get(value, buffer);
      if (count > 0)
      {
        cout << "Извлеченные элементы: ";
        for (int i = 0; i < count; ++i)
        {
          cout << buffer[i] << " ";
        }
        cout << endl;
        delete[] buffer;
      }
      else
      {
        cout << "Элементов с таким значением нет!" << endl;
      }
      break;
    }
    case 5:
      cout << "Куча: " << heap << endl;
      break;
    case 6:
    {
      MaxHeap heap2;
      cout << "Введите элементы для второй кучи (введите -1 для завершения):" << endl;
      int val;
      cin >> val;
      while (val != -1)
      {
        heap2.add(val);
        cin >> val;
      }

      cout << "Куча 1: " << heap << endl;
      cout << "Куча 2: " << heap2 << endl;

      cout << "Объединение: " << heap + heap2 << endl;
      cout << "Разность (1 - 2): " << heap - heap2 << endl;
      cout << "Разность (2 - 1): " << heap2 - heap << endl;
      cout << "Пересечение: " << (heap & heap2) << endl;
      break;
    }
    case 7:
    {
      MaxHeap heap2;
      cout << "Введите элементы для второй кучи (введите -1 для завершения):" << endl;
      int val;
      cin >> val;
      while (val != -1)
      {
        heap2.add(val);
        cin >> val;
      }

      cout << "Куча 1: " << heap << endl;
      cout << "Куча 2: " << heap2 << endl;

      cout << "heap == heap2: " << (heap == heap2) << endl;
      cout << "heap != heap2: " << (heap != heap2) << endl;
      cout << "heap > heap2: " << (heap > heap2) << endl;
      cout << "heap < heap2: " << (heap < heap2) << endl;
      cout << "heap >= heap2: " << (heap >= heap2) << endl;
      cout << "heap <= heap2: " << (heap <= heap2) << endl;
      break;
    }
    case 8:
      return 0;
    default:
      cout << "Такой опции нет, попробуйте еще раз!" << endl;
    }
  }
  return 0;
}


void showMenu()
{
  cout << "Меню:" << endl;
  cout << "0. Показать меню" << endl;
  cout << "1. Добавить элемент" << endl;
  cout << "2. Извлечь максимальный элемент" << endl;
  cout << "3. Просмотреть максимальный элемент" << endl;
  cout << "4. Извлечь элементы, равные заданному значению" << endl;
  cout << "5. Вывести кучу" << endl;
  cout << "6. Выполнить операции объединения, разности и пересечения" << endl;
  cout << "7. Выполнить операции сравнения" << endl;
  cout << "8. Выход" << endl;
}