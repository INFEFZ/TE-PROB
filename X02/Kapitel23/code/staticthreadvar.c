#include <stdio.h>
#include <threads.h>
#include <stdbool.h>

int terminate = false;
mtx_t mutex;

int threadfunction(void* arg) {
  int threadid = *(int*)arg;
  
  static int count = 0;     // Variable ist static!

  while (!terminate) { 
    mtx_lock(&mutex);
    ++count;
    printf("count = %03i, Thread %d\n", count, threadid);
    mtx_unlock(&mutex);
    thrd_yield();
  }
  
  return thrd_success;
}

int main(void) {
  int threadids[4] = {1, 2, 3, 4}; 
  thrd_t thr1, thr2, thr3, thr4;

  mtx_init(&mutex, mtx_plain);
  thrd_create(&thr1, threadfunction, &threadids[0]);
  thrd_create(&thr2, threadfunction, &threadids[1]);
  thrd_create(&thr3, threadfunction, &threadids[2]);
  thrd_create(&thr4, threadfunction, &threadids[3]);

  for (int i = 0; i < 10000000; ++i) {
    // eine Weile warten...
  }

  terminate = true;
  thrd_join(thr1, NULL);
  thrd_join(thr2, NULL);
  thrd_join(thr3, NULL);
  thrd_join(thr4, NULL);
  mtx_destroy(&mutex);
}
