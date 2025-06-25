#include <stdio.h>

int getPrime(int i) {
  int primes[] = {
    2, 3, 5, 7, 11, 13, 17, 19, 23,
    31, 37, 41, 43, 47, 59, 61, 67,
    71, 73, 79, 83, 89, 97};
  return (i > 0 && i < 23) ? primes[i] : 0;
}

int main(void) { 
  printf("Primzahl mit Index 5: %d\n", getPrime(5));
  printf("Primzahl mit Index 15: %d\n", getPrime(15));
  printf("Primzahl mit Index 22: %d\n", getPrime(22));
  return 0;
}

