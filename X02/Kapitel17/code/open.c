#include <stdio.h>

int main(void) {
  FILE * fp;

  if ((fp = fopen("aufgabe.c", "r")) == NULL) {
    printf("aufgabe.c nicht vorhanden\n");
    return 1;
  }
  fclose(fp);
  
  printf("aufgabe.c vorhanden\n");
  return 0;
}
