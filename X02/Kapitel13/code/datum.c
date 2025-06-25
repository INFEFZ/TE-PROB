#include <time.h>
#include <stdio.h>

int main(void) {
  time_t sekunden;
  time(&sekunden);
  struct tm* zeit = localtime(&sekunden);
  
  printf("Aktuelle Zeitangabe:\n\n");
  printf("%02d:%02d:%02d\n",
    zeit->tm_hour, zeit->tm_min, zeit->tm_sec);
  printf("%02d.%02d.%d \n",
    zeit->tm_mday, zeit->tm_mon + 1, 1900 + (zeit->tm_year));

  char* tag[] = {"Sonntag", "Montag", "Dienstag", "Mittwoch",
                 "Donnerstag", "Freitag", "Samstag"};
  printf("Wochentag: %s\n", tag[zeit->tm_wday]);
  
  return 0;
}
