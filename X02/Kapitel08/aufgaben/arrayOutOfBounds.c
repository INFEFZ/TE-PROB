#include <stdio.h>

int main(void) {
   
  int i = 16;
  int k = 21;
  int l = 22;
  int p = 23;
  int q = 24;

  int ar[100];

  for (size_t i = 0; i < 100; i = i + 1)
    ar[i] = 27;

  printf("i ist %d\n", i);
  printf("ar[-1] ist %d\n", ar[-1]);
  printf("ar[0] ist %d\n", ar[0]);
  printf("ar[100] ist %d\n", ar[100]);
  printf("ar[101] ist %d\n", ar[101]);
  printf("ar[102] ist %d\n", ar[102]);
  printf("ar[103] ist %d\n", ar[103]);
  printf("ar[-2] ist %d\n", ar[-2]);
  printf("ar[-3] ist %d\n", ar[-3]);
  printf("k ist %d\n", k);
  printf("l ist %d\n", l);
  printf("p ist %d\n", p);
  printf("q ist %d\n", q);
  
  return 0;
}
