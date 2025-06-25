#include "main.h"

size_t anzahl(void) {
  size_t count = 0;
  const float* ptr = arr;
  while (*ptr != 0.f) {
    ++ptr;
    ++count;
  }
  return count;
}
