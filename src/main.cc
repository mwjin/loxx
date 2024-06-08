#include <iostream>

#include "loxx.h"

using loxx::Loxx;

int main(int argc, char** argv) {
  if (argc > 2) {
    std::cout << "Usage: loxx [script]" << std::endl;
    exit(64);
  } else if (argc == 2) {
    Loxx::RunFile(argv[1]);
  } else {
    Loxx::RunPrompt();
  }
}
