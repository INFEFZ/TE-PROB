#include <stdio.h>
#include <string.h>

int main(void) {
   char string[50] = "concatenate";
   strcat(string, " = zusammenfuegen");
   printf("%s\n", string);
   return 0;
}
