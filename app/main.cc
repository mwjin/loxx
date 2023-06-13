#include <iostream>

#include "loxx.h"

int main(int argc, char** argv) {
  if (argc > 2) {
    std::cout << "Usage: loxx [script]" << std::endl;
    exit(64);
  } else if (argc == 2) {
    loxx::RunFile(argv[1]);
  } else {
    loxx::RunPrompt();
  }
}
