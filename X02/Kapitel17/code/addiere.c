#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
  if (argc == 3) {
    int resultat = atoi(argv[1]) + atoi(argv[2]);
    printf("%s + %s = %d\n", argv[1], argv[2], resultat);
  } else {
    printf("Bitte 2 Zahlen eingeben.\n");
  }
  return 0;
}
