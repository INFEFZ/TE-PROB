#include <stdio.h>
#include <time.h>

void f1(void) {
  printf("Druecken Sie bitte Enter:");
  getchar();
}

double evalTime(void (*ptr)(void)) {
  time_t begin, end;
  begin = time(NULL);
  ptr();
  end = time(NULL);
  return difftime(end, begin);
}

int main(void) {
  printf("Zeit bis Enter gedrueckt wurde: %1.0f sec\n",
    evalTime(f1));
  return 0;
}
