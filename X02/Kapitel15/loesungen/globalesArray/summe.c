#include "main.h"

float summe(void) {
  float sum = 0.f;
  const float* ptr = arr;
  while (*ptr != 0.f) {
    sum += *ptr;
    ++ptr;
  }
  return sum;
}
