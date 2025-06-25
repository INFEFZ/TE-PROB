#include "enums.h"

void printInfo(const void* arg);

int main(void) {
  struct Auto      meinAuto   = {TYP_PKW, "Trabbi", 180.};
  struct Lastwagen meinBrummi = {TYP_LKW, 10, 40.};
  printInfo(&meinAuto);
  printInfo(&meinBrummi);
  return 0;
}
