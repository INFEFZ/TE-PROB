#include <stdio.h>

int main(void) {
  
  for (int i = 1; i <= 10; ++i) {
    
    if (i == 7)
      continue;
  
    printf("%d ", i);
    if (i < 5)
      printf("ist kleiner als 5.");
    else if (i > 5)
      printf("ist groesser als 5.");
    else
      printf("ist gleich 5.");

    printf("\n");
  }
  
  return 0;
}

