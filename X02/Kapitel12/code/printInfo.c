#include "enums.h"
#include <stdio.h>

void printInfo(const void* arg) {
  switch (*(enum Fahrzeugtyp*) arg) {      // (1)
  
  case TYP_PKW:
    printf("Automarke %s mit %f km/h\n",
       ((struct Auto*)arg)->marke,
       ((struct Auto*)arg)->maxv);
    break;
    
  case TYP_LKW:
    printf("Lastwagen %d-Achser mit %ft\n",
       ((struct Lastwagen*)arg)->achsen,
       ((struct Lastwagen*)arg)->gewicht);
    break;
    
  }
}
