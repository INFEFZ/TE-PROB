#include <stdio.h>

int length(const char* string) {
  int len = 0;
  while (*string) {
    ++string;
    ++len;
  }
  return len;
}

int check1(const char* str1, const char* str2) {
  // Methode 1 mit for-Schleifen und Index-Berechnungen
  int len1 = length(str1);
  int len2 = length(str2);
  for (int i = 0; i < len1; ++i) {
    for (int j = 0; j < len2; ++j) {
      if (i + j >= len1 || str1[i + j] != str2[j]) {
        break;
      }
      if (j == len2 - 1)
        return i;
    }
  }
  return -1;
}

int check2(const char* str1, const char* str2) {
  // Methode 2 mit reiner Pointer-Arithmetik
  const char* str2Prime = str2;
  int index = 0;
  while (1) {
    const char* str1Prime = str1;
    if (*str1 == '\0')
      return -1;
    while (*str1 == *str2) {
      ++str1;
      ++str2;
    }
    if (*str2 == '\0')
      return index;
    ++index;
    str1 = str1Prime + 1;
    str2 = str2Prime;
  }
}

int main(void) {
 
  int index1 = check1("Fischers Fritz fischt frische Fische", "ris");
  printf("Erstes Vorkommen: %d\n", index1);

  int index2 = check2("Fischers Fritz fischt frische Fische", "ris");
  printf("Erstes Vorkommen: %d\n", index2);
  
  return 0;
}
