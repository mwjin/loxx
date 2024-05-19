#include "loxx.h"

#include <fstream>
#include <iostream>
#include <iterator>

namespace loxx {
void Run(const std::string& source) {
  std::cout << "Get \"" << source << "\"" << std::endl;
}
}  // namespace loxx

void loxx::RunFile(const std::string& file_path) {
  std::ifstream in_file{file_path};
  if (!in_file) {
    std::cerr << "Can't open the file \"" << file_path << '\"' << std::endl;
    return;
  }

  // Read all bytes and store them in a string
  std::string source{std::istreambuf_iterator<char>(in_file),
                     std::istreambuf_iterator<char>()};
  Run(source);
}
void loxx::RunPrompt() {
  std::string line{};
  for (;;) {
    std::cout << ">> ";
    auto& no_error = std::getline(std::cin, line);
    if (!no_error) break;
    Run(line);
  }
}
