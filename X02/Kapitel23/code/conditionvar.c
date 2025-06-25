#include <stdio.h>
#include <threads.h>
#include <stdbool.h>

cnd_t queueNotEmpty, queueNotFull;
mtx_t queueMutex;
#define QUEUE_SIZE 5
int elementZaehler = 0;
int terminate = false;

int producerThread(void* arg) {
  while (!terminate) {
    printf("Erzeuge Daten\n");
    mtx_lock(&queueMutex);

    while (elementZaehler == QUEUE_SIZE) {
      cnd_wait (&queueNotFull, &queueMutex);
    }
    ++elementZaehler;
    cnd_broadcast(&queueNotEmpty);
    
    mtx_unlock(&queueMutex);
  }
  return thrd_success;
}

int consumerThread(void* arg) {
  int threadid = *(int*)arg;
  while (!terminate) {
    printf("Verbrauche Daten Thread %d\n", threadid);
    mtx_lock(&queueMutex);

    while (elementZaehler == 0) {
      cnd_wait(&queueNotEmpty, &queueMutex);
    }
      
    --elementZaehler;
    cnd_broadcast(&queueNotFull);
    
    mtx_unlock(&queueMutex);
  }
  return thrd_success;
}
int main(void) {
  thrd_t producer;
  thrd_t consumer1;
  thrd_t consumer2;
  int consumerid1 = 1;
  int consumerid2 = 2;

  cnd_init(&queueNotFull); 
  cnd_init(&queueNotEmpty);
  mtx_init(&queueMutex, mtx_plain);

  thrd_create(&producer, producerThread, NULL);
  thrd_create(&consumer1, consumerThread, &consumerid1);
  thrd_create(&consumer2, consumerThread, &consumerid2);
  for (int i = 0; i < 10000000; ++i) {
    // Threads arbeiten lassen
  }

  terminate = true;
  thrd_join(producer, NULL);
  thrd_join(consumer1, NULL);
  thrd_join(consumer2, NULL);

  mtx_destroy(&queueMutex);
  cnd_destroy(&queueNotEmpty);
  cnd_destroy(&queueNotFull);
}
