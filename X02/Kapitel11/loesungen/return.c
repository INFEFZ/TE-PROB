#include <stdio.h>
#include <limits.h>

#define MAX 10

int summe(int* a) {
  int sum = 0;
  for (int i = 0; i < MAX; ++i) {
    sum += a[i];
  }
  return sum;
}

int maximum(int* a) {
  int max = INT_MIN;
  for (int i = 0; i < MAX; ++i) {
    if (a[i] > max)
      max = a[i];
  }
  return max;
}

double durchschnitt(int* a) {
  return (double)summe(a) / (double)MAX;
}

void statistik(int* sum, int* max, double* avg, int* a) {
  *sum = summe(a);
  *max = maximum(a);
  *avg = durchschnitt(a);
}

int main(void) {
  int a[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  int sum;
  int max;
  double avg;
  
  statistik(&sum, &max, &avg, a);
  
  printf("Summe: %d\n", sum);
  printf("Maximum: %d\n", max);
  printf("Durchschnitt: %f\n", avg);

  return 0;
}

