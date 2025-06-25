// MSVC meldet fuer veraltete, unsichere C-Funktionen wie
// localtime einen Fehler. So wird dieser Fehler ausgeschaltet:
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#ifdef _WIN32
  #include <windows.h>
  #define SleepFunction Sleep
#else
  #include <unistd.h>
  #define SleepFunction sleep
#endif

int main(void) {
  while (1) {
    time_t t = time(0);
    struct tm* now = localtime(&t);

    printf("%d:%d:%d\n", now->tm_hour, now->tm_min, now->tm_sec);
    fflush(stdout);

    if (now->tm_hour == 12) {
      printf("Lunch!");
      break;
    }

    SleepFunction(1);
  }
  return 0;
}
