#ifndef LOXX_H_
#define LOXX_H_
#include <string>

namespace loxx {
void RunFile(std::string file_path);
void RunPrompt();
void Run(std::string& source);
}  // namespace loxx

#endif
