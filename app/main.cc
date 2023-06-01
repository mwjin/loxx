#include <iostream>

#include "shape.h"

int main(int, char**) {
  Rectangle rect{4, 8};
  std::cout << "Hello, world!" << std::endl;
  std::cout << "Rectangle size: " << rect.GetSize() << std::endl;
}
