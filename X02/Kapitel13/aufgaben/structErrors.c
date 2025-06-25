#include <stdio.h>

struct Person { 
  char vorname[30];
  char* nachname;
};

int main(void) {
  struct Person person1 = {"Kathrin", "Knoll"};
  struct Person person2 = {"Thorsten", "Powlov"};
  
  person1.vorname = "Maria";
  person1.nachname = "Hanse";
  printf("%s %s\n", person1.vorname, person1.nachname);

  person1.vorname = person2.vorname;
  person1.nachname = person2.nachname;
  printf("%s %s\n", person1.vorname, person1.nachname);

  person1 = person2;
  printf("%s %s\n", person1.vorname, person1.nachname);
  
  person2.nachname = "Frick";
  printf("%s %s\n", person2.vorname, person2.nachname);

  return 0;
}
