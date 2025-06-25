#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <stdbool.h>

int terminate = false;

tss_t tsskey;

typedef struct {
   unsigned char data;
} threadLocalData_t;

void evaluate(void) {
   threadLocalData_t* tld = (threadLocalData_t*)tss_get(tsskey);
   printf("data = %03i, Thread %p\n", tld->data, &(thrd_current()));
}

int threadfunction(void* arg) {
  threadLocalData_t pLocal;

  tss_set(tsskey, &pLocal);

  pLocal.data = *(unsigned char*)arg;
  while (!terminate) {
    ++pLocal.data;
    evaluate();

    if (terminate) {
      break;
    }
    thrd_yield();
  }
  return thrd_success;
}

int main(void) {
   thrd_t thr1;
   thrd_t thr2;

   unsigned char iniVal1 = 0;
   unsigned char iniVal2 = 128;

   tss_create(&tsskey, NULL);
   thrd_create(&thr1, threadfunction, (void*)&iniVal1);
   thrd_create(&thr2, threadfunction, (void*)&iniVal2);

   for (int i = 0; i < 100000000; ++i) {
      // eine Weile warten...
   }

   terminate = true;
   thrd_join(thr1, NULL);
   thrd_join(thr2, NULL);
   tss_delete(tsskey);
}
