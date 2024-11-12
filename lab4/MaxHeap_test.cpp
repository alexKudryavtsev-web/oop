#include "MaxHeap.h"
#include <iostream>
#include <cassert>

void testAdd()
{
  MaxHeap heap;
  assert(heap.add(10));
  assert(heap.add(20));
  assert(heap.add(5));
  assert(heap.add(15));
  assert(heap.add(30));

  int value;
  assert(heap.get(value));
  assert(value == 30);
  assert(heap.get(value));
  assert(value == 20);
  assert(heap.get(value));
  assert(value == 15);
}

void testGet()
{
  MaxHeap heap;
  heap.add(10);
  heap.add(20);
  heap.add(5);
  heap.add(15);
  heap.add(30);

  int value;
  assert(heap.get(value));
  assert(value == 30);
  assert(heap.get(value));
  assert(value == 20);

  while (heap.get(value))
  {
    std::cout << value << " ";
  }
  std::cout << std::endl;
}

void testPeek()
{
  MaxHeap heap;
  heap.add(10);
  heap.add(20);
  heap.add(5);
  heap.add(15);
  heap.add(30);

  int value;
  assert(heap.peek(value));
  assert(value == 30);
  assert(heap.count() == 5);

  assert(heap.peek(value));
  assert(value == 30);
  assert(heap.count() == 5);
}

void testCount()
{
  MaxHeap heap;
  heap.add(10);
  heap.add(20);
  heap.add(5);
  heap.add(15);
  heap.add(30);
  heap.add(20);
  heap.add(20);
  heap.add(15);
  assert(heap.count() == 8);
  assert(heap.count(20) == 3);
  assert(heap.count(15) == 2);
  assert(heap.count(10) == 1);
  assert(heap.count(100) == 0);
}

void testContains()
{
  MaxHeap heap;
  heap.add(10);
  heap.add(20);
  heap.add(5);
  heap.add(15);
  heap.add(30);

  assert(heap.contains(10));
  assert(heap.contains(20));
  assert(heap.contains(5));
  assert(heap.contains(15));
  assert(heap.contains(30));
  assert(!heap.contains(1));
}
