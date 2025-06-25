#include <stdio.h>
#include <string.h>

int convertRomanDigit(const char digit) {
  int resultat = 0;
  switch (digit) {
  case 'I':
  case 'i':
    resultat = 1;
    break;
  case 'V':
  case 'v':
    resultat = 5;
    break;
  case 'X':
  case 'x':
    resultat = 10;
    break;
  case 'L':
  case 'l':
    resultat = 50;
    break;
  case 'C':
  case 'c':
    resultat = 100;
    break;
  case 'D':
  case 'd':
    resultat = 500;
    break;
  case 'M':
  case 'm':
    resultat = 1000;
    break;
  default :
    resultat = 0;
    break;
  }
  return resultat;
}

int convertRomanNumber(const char* string) {
  int resultat = 0;
  for (int i = 0; i < strlen(string); ++i) {
    resultat += convertRomanDigit(string[i]);
  }
  return resultat;
}

int convertRomanNumberExtended(const char* string) {
  int resultat = 0;
  int prevDigit = 0;
  for (int i = 0; i < strlen(string); ++i) {
    int digit = convertRomanDigit(string[i]);
    switch (digit) {
    case 1:
      resultat += 1;
      prevDigit = 1;
      break;
    case 5:
      if (prevDigit == 1) {
        resultat += 3;
        prevDigit = 0;
      } else {
        resultat += 5;
        prevDigit = 5;
      }
      break;
    case 10:
      if (prevDigit == 1) {
        resultat += 8;
        prevDigit = 0;
      } else {
        resultat += 10;
        prevDigit = 10;
      }
      break;
    case 50:
      if (prevDigit == 10) {
        resultat += 30;
        prevDigit = 0;
      } else {
        resultat += 50;
        prevDigit = 50;
      }
      break;
    case 100:
      if (prevDigit == 10) {
        resultat += 80;
        prevDigit = 0;
      } else {
        resultat += 100;
        prevDigit = 100;
      }
      break;
    case 500:
      if (prevDigit == 100) {
        resultat += 300;
        prevDigit = 0;
      } else {
        resultat += 500;
        prevDigit = 500;
      }
      break;
    case 1000:
      if (prevDigit == 100) {
        resultat += 800;
        prevDigit = 0;
      } else {
        resultat += 1000;
        prevDigit = 1000;
      }
      break;
    }
  }
  return resultat;
}

int main (void) {
  const char* roman1 = "MDCCCCLXXXIIII";
  const char* roman2 = "MCMLXXXIV";
  
  printf("%s = %d\n", roman1, convertRomanNumber(roman1));
  printf("%s = %d\n", roman2, convertRomanNumberExtended(roman2));
  
  return 0;
}
