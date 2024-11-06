#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <iostream>

class MaxHeap
{
private:
  int *heap;
  int capacity;
  int size;

  // Вспомогательные методы для поддержания кучи
  void heapifyUp(int index);
  void heapifyDown(int index);
  void resizeHeap(int newCapacity);

public:
  MaxHeap();
  ~MaxHeap();
  MaxHeap(const MaxHeap &other);
  MaxHeap &operator=(const MaxHeap &other);

  // Добавление элемента
  bool add(int value);
  // Извлечение наибольшего элемента (с удалением)
  bool get(int &value);
  // Чтение наибольшего элемента (без удаления)
  bool peek(int &value);
  // Извлечение элементов равных value
  int get(int value, int *&buffer);

  // Число элементов
  int count();
  // Число элементов равных value
  int count(int value);
  // Проверка наличия элемента
  bool contains(const int &value) const;

  // Операции объединения
  MaxHeap operator+(const MaxHeap &other) const;
  // Разность (элементы не встречаются в other)
  MaxHeap operator-(const MaxHeap &other) const;
  // Пересечение (уникальные элементы которые есть в обеих структурах данных)
  MaxHeap operator&(const MaxHeap &other) const;

  // Операторы сравнения двух структур данных
  bool operator==(const MaxHeap &other) const;
  bool operator!=(const MaxHeap &other) const;
  bool operator>(const MaxHeap &other) const;
  bool operator<(const MaxHeap &other) const;
  bool operator>=(const MaxHeap &other) const;
  bool operator<=(const MaxHeap &other) const;

  // Вывод MaxHeap в cout
  friend std::ostream &operator<<(std::ostream &os, const MaxHeap &heap);
};

#endif