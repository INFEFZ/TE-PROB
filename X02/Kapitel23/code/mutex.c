#include <stdio.h>
#include <threads.h>
#include <stdbool.h>

// globale Variable fuer Mutex
mtx_t mutex;

// gemeinsam genutzte Ressource
int i[3] = {0, 0, 0};
int terminate = false;

int writerThread(void* arg) {
  while (!terminate) { 
    mtx_lock(&mutex);

    printf("Schreibe Daten\n");
    ++i[0];
    ++i[1];
    ++i[2];

    mtx_unlock(&mutex);
    thrd_yield();
  }
  return thrd_success;
}

int readerThread(void* arg) {
  while (!terminate) {
    mtx_lock(&mutex);

    printf("lese Daten: %i, %i, %i\n", i[0], i[1], i[2]);

    mtx_unlock(&mutex);
    thrd_yield();
  }
  return thrd_success;
}

int main(void) {
  mtx_init(&mutex, mtx_plain);

  thrd_t reader;
  thrd_t writer;
  thrd_create(&reader, readerThread, NULL);
  thrd_create(&writer, writerThread, NULL);

  for (int i = 0; i < 10000000; ++i) {
    // Threads fuer eine Weile ausfuehren.
  }

  terminate = true;
  thrd_join(reader, NULL);
  thrd_join(writer, NULL);
  mtx_destroy (&mutex);
}
