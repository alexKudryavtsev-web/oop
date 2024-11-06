#include "MaxHeap.h"

// Вспомогательные методы
void MaxHeap::heapifyUp(int index)
{
    while (index > 0)
    {
        int parentIndex = (index - 1) / 2;
        if (heap[index] > heap[parentIndex])
        {
            std::swap(heap[index], heap[parentIndex]);
            index = parentIndex;
        }
        else
        {
            break;
        }
    }
}

void MaxHeap::heapifyDown(int index)
{
    int leftChildIndex = 2 * index + 1;
    int rightChildIndex = 2 * index + 2;
    int largestIndex = index;

    if (leftChildIndex < size && heap[leftChildIndex] > heap[largestIndex])
    {
        largestIndex = leftChildIndex;
    }
    if (rightChildIndex < size && heap[rightChildIndex] > heap[largestIndex])
    {
        largestIndex = rightChildIndex;
    }

    if (largestIndex != index)
    {
        std::swap(heap[index], heap[largestIndex]);
        heapifyDown(largestIndex);
    }
}

void MaxHeap::resizeHeap(int newCapacity)
{
    int *newHeap = new int[newCapacity];
    for (int i = 0; i < size; ++i)
    {
        newHeap[i] = heap[i];
    }
    delete[] heap;
    heap = newHeap;
    capacity = newCapacity;
}

// Конструктор
MaxHeap::MaxHeap() : heap(nullptr), capacity(0), size(0) {}

// Деструктор
MaxHeap::~MaxHeap()
{
    delete[] heap;
}

// Конструктор копирования
MaxHeap::MaxHeap(const MaxHeap &other) : capacity(other.capacity), size(other.size)
{
    heap = new int[capacity];
    for (int i = 0; i < size; ++i)
    {
        heap[i] = other.heap[i];
    }
}

// Оператор присваивания
MaxHeap &MaxHeap::operator=(const MaxHeap &other)
{
    if (this == &other)
    {
        return *this;
    }
    delete[] heap;
    capacity = other.capacity;
    size = other.size;
    heap = new int[capacity];
    for (int i = 0; i < size; ++i)
    {
        heap[i] = other.heap[i];
    }
    return *this;
}

// Добавление элемента
bool MaxHeap::add(int value)
{
    if (size == capacity)
    {
        if (capacity == 0)
        {
            resizeHeap(1);
        }
        else
        {
            resizeHeap(capacity * 2);
        }
    }
    heap[size] = value;
    heapifyUp(size);
    ++size;
    return true;
}

// Извлечение наибольшего элемента (с удалением)
bool MaxHeap::get(int &value)
{
    if (size == 0)
    {
        return false;
    }
    value = heap[0];
    heap[0] = heap[size - 1];
    --size;
    heapifyDown(0);
    return true;
}

// Чтение наибольшего элемента (без удаления)
bool MaxHeap::peek(int &value)
{
    if (size == 0)
    {
        return false;
    }
    value = heap[0];
    return true;
}

// Извлечение элементов равных value
int MaxHeap::get(int value, int *&buffer)
{
    int count = 0;
    for (int i = 0; i < size; ++i)
    {
        if (heap[i] == value)
        {
            ++count;
        }
    }
    if (count == 0)
    {
        return 0;
    }
    buffer = new int[count];
    int j = 0;
    for (int i = 0; i < size; ++i)
    {
        if (heap[i] == value)
        {
            buffer[j] = heap[i];
            ++j;
        }
    }
    // Удаляем элементы из кучи
    int newSize = size - count;
    int *newHeap = new int[newSize];
    j = 0;
    for (int i = 0; i < size; ++i)
    {
        if (heap[i] != value)
        {
            newHeap[j] = heap[i];
            ++j;
        }
    }
    delete[] heap;
    heap = newHeap;
    size = newSize;
    capacity = newSize;
    return count;
}

// Число элементов
int MaxHeap::count()
{
    return size;
}

// Число элементов равных value
int MaxHeap::count(int value)
{
    int count = 0;
    for (int i = 0; i < size; ++i)
    {
        if (heap[i] == value)
        {
            ++count;
        }
    }
    return count;
}

// Проверка наличия элемента
bool MaxHeap::contains(const int &value) const
{
    for (int i = 0; i < size; ++i)
    {
        if (heap[i] == value)
        {
            return true;
        }
    }
    return false;
}

// Операции объединения
MaxHeap MaxHeap::operator+(const MaxHeap &other) const
{
    MaxHeap result;
    for (int i = 0; i < size; ++i)
    {
        result.add(heap[i]);
    }
    for (int i = 0; i < other.size; ++i)
    {
        result.add(other.heap[i]);
    }
    return result;
}

// Разность (элементы не встречаются в other)
MaxHeap MaxHeap::operator-(const MaxHeap &other) const
{
    MaxHeap result;
    for (int i = 0; i < size; ++i)
    {
        if (!other.contains(heap[i]))
        {
            result.add(heap[i]);
        }
    }
    return result;
}

// Пересечение (уникальные элементы которые есть в обеих структурах данных)
MaxHeap MaxHeap::operator&(const MaxHeap &other) const
{
    MaxHeap result;
    for (int i = 0; i < size; ++i)
    {
        if (other.contains(heap[i]))
        {
            result.add(heap[i]);
        }
    }
    return result;
}

// Операторы сравнения
bool MaxHeap::operator==(const MaxHeap &other) const
{

    if (size != other.size)
    {
        return false;
    }
    for (int i = 0; i < size; ++i)
    {
        if (heap[i] != other.heap[i])
        {
            return false;
        }
    }
    return true;
}

bool MaxHeap::operator!=(const MaxHeap &other) const
{
    return !(*this == other);
}

bool MaxHeap::operator>(const MaxHeap &other) const
{
    for (int i = 0; i < std::min(size, other.size); ++i)
    {
        if (heap[i] > other.heap[i])
        {
            return true;
        }
        else if (heap[i] < other.heap[i])
        {
            return false;
        }
    }
    return size > other.size;
}

bool MaxHeap::operator<(const MaxHeap &other) const
{
    return !(*this > other) && !(*this == other);
}

bool MaxHeap::operator>=(const MaxHeap &other) const
{
    return *this > other || *this == other;
}

bool MaxHeap::operator<=(const MaxHeap &other) const
{
    return *this < other || *this == other;
}

// Вывод MaxHeap в cout
std::ostream &operator<<(std::ostream &os, const MaxHeap &heap)
{
    os << "{ ";
    for (int i = 0; i < heap.size; ++i)
    {
        os << heap.heap[i] << " ";
    }
    os << "}";
    return os;
}