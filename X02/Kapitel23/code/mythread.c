#if !defined(__STDC_NO_THREADS) || __STDC_NO_THREADS__
   #error "Threads are not available"
#endif

#include <stdio.h>
#include <threads.h>
#define THREAD_ANZAHL 5

int ausgabethread(void* arg) {
  int threadid = *(int*)arg;
  printf("Thread Nr. %i meldet sich.\n", threadid);
  return thrd_success;
}

int main(void) {
  // Array-Variable zum Speichern der Threads und IDs.
  thrd_t threads[THREAD_ANZAHL];
  int    threadids[THREAD_ANZAHL];
  int i;

  for (i = 0; i < THREAD_ANZAHL; ++i) {
    printf("Erzeuge Thread Nr. %i.\n", i);
    // Thread erzeugen und ausfuehren.
    threadids[i] = i;
    if (thrd_create(&threads[i], ausgabethread, &threadids[i])
      != thrd_success) {
       printf("Thread Nr. %i wurde nicht erzeugt.\n", i);
    }
  }

  for (i = 0; i < THREAD_ANZAHL; ++i) {
    // Warten, bis Threads beendet wurden.
    thrd_join(threads[i], NULL);
  }
}
