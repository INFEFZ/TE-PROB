#include <stdio.h>

#define MAX 10

int summe(???) { ??? }

int maximum(???) { ??? }

double durchschnitt(???) { ??? }

void statistik(int* sum, int* max, double* avg, ???) { ??? }

int main(void) {
  int a[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  int sum;
  int max;
  double avg;
  
  statistik(???);
  
  printf("Summe: %d\n", sum);
  printf("Maximum: %d\n", max);
  printf("Durchschnitt: %f\n", avg);

  return 0;
}

