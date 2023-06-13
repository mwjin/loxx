#include "error.h"

#include <iostream>

namespace loxx {
void ReportError(int line, const std::string& where,
                 const std::string& message) {
  std::cerr << "[line " << line << "] Error" << where << ": " << message;
}
}  // namespace loxx

void loxx::Error(int line, const std::string& message) {
  ReportError(line, std::string{}, message);
}
