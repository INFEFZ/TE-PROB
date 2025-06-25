#include <stdio.h>
#include <string.h>

int main(void) {
  const char eingabe[] = "Dieses Programm findet Buchstaben.";
  size_t index = 0;
  
  while (eingabe[index] != '\0') {
    if (eingabe[index] == 'a') {
      break;
    }
    index = index + 1;
  }

  if (eingabe[index] == '\0') {
    printf("Ihr String enthaelt kein 'a'\n");
  } else {
    printf("Das erste a befand sich an Index %d.\n", (int)index);
  }
  
  return 0;
}
