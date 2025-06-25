#include <limits.h>
#include <time.h>
#include <stdio.h>

int main(void) {
  time_t maxDatum = INT_MAX;
  struct tm* ptrMaxDatum;
  ptrMaxDatum = gmtime(&maxDatum);

  printf("Die 32-Bit-Zeit laeuft ab\n");
  printf("am %02d.%02d.%d\n",
    ptrMaxDatum->tm_mday,
    ptrMaxDatum->tm_mon + 1,
    1900+(ptrMaxDatum->tm_year));
  printf("um %02d:%02d:%02d Uhr\n",
    ptrMaxDatum->tm_hour,
    ptrMaxDatum->tm_min,
    ptrMaxDatum->tm_sec);        
  return 0;
}
