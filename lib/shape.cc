#include "shape.h"

#include <print>

Rectangle::Rectangle(int width, int height) : width_{width}, height_{height} {}

int Rectangle::GetSize() const {
  std::print("width: {}, height: {}\n", width_, height_);
  return width_ * height_;
}
