#include <stdio.h>

int binaer_suchen(int suchbegriff, const int* array, int anzahl) {
  int low = 0;
  int high = anzahl - 1;
  int mid;

  while (low <= high) {
    mid = (low + high) / 2;
    printf("Suche in [%d, %d] an Index %d: %d\n",
      low, high, mid, array[mid]);
      
    if (suchbegriff < array[mid])
       high = mid - 1;
    else if (suchbegriff > array[mid])
       low = mid + 1;
    else
       return mid;  // gefunden
  }
  return -1;        // nicht gefunden
}

int main(void) {
  int array[] = {2, 5, 11, 17, 23, 31, 33, 37, 44, 50, 59, 62}; 
  int anzahl = sizeof(array) / sizeof(int);

  int suchbegriff = 23;
  int index = binaer_suchen(suchbegriff, array, anzahl);
  if (index == -1)
    printf("Nicht gefunden \n");
  else
    printf("Element mit Index %d = %d\n", index, suchbegriff);

  return 0;
}
