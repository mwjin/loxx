#ifndef LOXX_ERROR_H_
#define LOXX_ERROR_H_
#include <string>

namespace loxx {
void Error(int line, const std::string& message);
}

#endif
