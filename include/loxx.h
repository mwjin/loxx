#ifndef LOXX_H_
#define LOXX_H_
#include <string>

namespace loxx {
class Loxx {
 public:
  static void RunFile(const std::string& file_path);
  static void RunPrompt();
  static void Error(int line, const std::string& message);
  static bool HasError();
  static void SetError();
  static void ResetError();

 private:
  static void Run(const std::string& source);
  static void ReportError(int line, const std::string& where,
                          const std::string& message);
  static bool has_error_;
};
}  // namespace loxx

#endif  // LOXX_H_
