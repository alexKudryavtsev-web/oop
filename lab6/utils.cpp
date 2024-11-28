#include "utils.h"
#include <iostream>

void printMenu()
{
  std::string menu = "Меню:\n\t"
                     "0 - вывести меню\n\t"
                     "1 - выйти из программы\n\t"
                     "2 - добавить элемент\n\t"
                     "3 - удалить элемент\n\t"
                     "4 - вывести список";

  std::cout << menu << std::endl;
}