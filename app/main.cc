#include <fstream>
#include <iostream>
#include <string>

namespace loxx {
void Run(std::string& source) { std::cout << "Run " << source << std::endl; }

void RunFile(std::string file_path) {
  std::ifstream in_file{file_path};
  std::string source{};
  in_file >> source;
  Run(source);
}
void RunPrompt() {
  std::string line{};
  while (std::getline(std::cin, line)) Run(line);
}
}  // namespace loxx

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
