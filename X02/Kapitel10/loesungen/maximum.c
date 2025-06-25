#include <stdio.h>
#include <limits.h>

int getMax3(int value1, int value2, int value3) {
  if (value1 > value2) {
    if (value1 > value3)
      return value1;
    else
      return value3;
  } else {
    if (value2 > value3)
      return value2;
    else
      return value3;
  }
}

int getMaxn(const int* values, int arrayCount) {
  int max = INT_MIN;
  for (int i = 0; i < arrayCount; ++i) {
    if (values[i] > max)
      max = values[i];
  }
  return max;
}

int areAllLower(const int* values, int arrayCount, int max) {
  for (int i = 0; i < arrayCount; ++i) {
    if (values[i] >= max)
      return 0;
  }
  return 1;
}

#define ANZAHL 5

int main(void) {
  printf("Max von dreien ist: %d\n", getMax3(6, 2, 7));

  int array[ANZAHL] = {5, 1, 9, 7, 2};
  
  printf("Max von vielen ist: %d\n", getMaxn(array, ANZAHL));

  const char* janein = areAllLower(array, ANZAHL, 10) ? "Ja" : "Nein";
  printf("Alle kleiner als 10? %s\n", janein);

  return 0;
}
