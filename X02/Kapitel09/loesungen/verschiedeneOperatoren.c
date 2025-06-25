#include <stdio.h>

int main(void) {
  int a = 2;
  int b = 1;
  int* ptr = &b;

  a  = b = 2;
  printf("%d, %d\n", a, b);  // 2, 2
  
  a  = 5 * 3 + 2;
  printf("%d, %d\n", a, b);  // 17, 2
  
  a  = 5 * (3 + 2);
  printf("%d, %d\n", a, b);  // 25, 2
  
  a *= 5 + 5;
  printf("%d, %d\n", a, b);  //250, 2
  
  a %= 2 * 3;
  printf("%d, %d\n", a, b);  // 4, 2
  
  a  = !(--b == 0); 
  printf("%d, %d\n", a, b);  // 1, 1
  
  a  = 0 && 0 + 2;
  printf("%d, %d\n", a, b);  // 0, 1 (Der zweite Teil nach dem && wird nie
                             //       ausgefuehrt.)
  
  a  = b++ * 2;
  printf("%d, %d\n", a, b);  // 2, 2
  
  a  = - 5 - 5; 
  printf("%d, %d\n", a, b);  // -10, 2
  
  a  = -(+b++);
  printf("%d, %d\n", a, b);  // -2, 3
  
  a  = 5 == 5 && 0 || 1;
  printf("%d, %d\n", a, b);  // 1, 3
  
  a  = ((((((b + b) * 2) + b) && b || b)) == b);
  printf("%d, %d\n", a, b);  // 0, 3  (Der Compiler gibt möglicherweise eine
                             //        Warnung aus weil || und && ohne Klammern
                             //        benutzt werden)
  
  a  = b ? 5 - 3 : b;
  printf("%d, %d\n", a, b);  // 2, 3
  
  a  = 5 ** ptr; 
  printf("%d, %d\n", a, b);  // 15, 3
  
  a  = b + (++b);
  printf("%d, %d\n", a, b);  // 7 oder 8, 4
                             // (a ist unbestimmt wegen Auswertungsreihenfolge) 

  return 0;
}
