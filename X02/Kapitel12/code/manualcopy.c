#include <stdio.h>

int main(void) {
  char alpha[30]  = "zu kopierender String";
  char beta[30]   = "";

  int i = 0;
  while (alpha[i] != '\0') {
    beta[i] = alpha[i];
    ++i;
  }
  beta[i] = '\0';
  
  printf("%s\n", alpha);
  printf("%s\n", beta);
  
  return 0;
}
