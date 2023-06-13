#include "loxx.h"

#include <fstream>
#include <iostream>

void loxx::RunFile(std::string file_path) {
  std::ifstream in_file{file_path};
  std::string source{};
  in_file >> source;
  Run(source);
}
void loxx::RunPrompt() {
  std::string line{};
  while (std::getline(std::cin, line)) Run(line);
}

void loxx::Run(std::string& source) {
  std::cout << "Run " << source << std::endl;
}
