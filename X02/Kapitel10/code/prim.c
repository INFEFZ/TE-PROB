#include <stdio.h>
#define MAX 30

int main(void) {
  for (int i = 2; i <= MAX; i = i + 1) { 
    int istTeilbar = 0;
    
    for (int k = 2; k < i; ++k) {
      if (i % k == 0) {
        istTeilbar = 1;
      }
    }
    
    if (!istTeilbar) { 
      printf("%d ", i);                 
    }
  }
  return 0;
}
