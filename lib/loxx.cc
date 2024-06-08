#include "loxx.h"

#include <fstream>
#include <iostream>
#include <iterator>

#include "scanner.h"

namespace loxx {
void Loxx::RunFile(const std::string& file_path) {
  std::ifstream in_file{file_path};
  if (!in_file) {
    std::cerr << "Can't open the file \"" << file_path << '\"' << std::endl;
    return;
  }

  // Read all bytes and store them in a string
  std::string source{std::istreambuf_iterator<char>(in_file),
                     std::istreambuf_iterator<char>()};
  Run(source);
  if (HasError()) exit(65);
}

void Loxx::RunPrompt() {
  std::string line{};
  for (;;) {
    std::cout << ">> ";
    auto& no_error = std::getline(std::cin, line);
    if (!no_error) break;
    Run(line);
    ResetError();  // Ignore errors from the previous prompt
  }
}

void Loxx::Error(int line, const std::string& message) {
  ReportError(line, std::string{}, message);
}

bool Loxx::HasError() { return has_error_; }

void Loxx::SetError() { has_error_ = true; }

void Loxx::ResetError() { has_error_ = false; }

void Loxx::Run(const std::string& source) {
  std::cout << "Compile \"" << source << "\"" << std::endl;
  std::cout << std::endl
            << "========== Scanning ==========" << std::endl
            << std::endl;
  Scanner scanner{source};
  auto& tokens = scanner.ScanTokens();
  if (HasError()) return;
  for (const auto& token : tokens) std::cout << token << std::endl;
}

void Loxx::ReportError(int line, const std::string& where,
                       const std::string& message) {
  std::cerr << "[line " << line << "] Error" << where << ": " << message
            << std::endl;
  SetError();
}

bool Loxx::has_error_{false};
}  // namespace loxx
