#include <stdio.h>

struct Person { 
  char vorname[30];
  char* nachname;
};

void printPerson(struct Person myPerson) {
  printf("%s %s\n", myPerson.vorname, myPerson.nachname);
}

void printPersonPointer(struct Person* myPerson) {
  printf("%s %s\n", myPerson->vorname, myPerson->nachname);
}

int main (void) {
  printPerson((struct Person){"Gudrun", "Tschechov"});
  printPerson((struct Person){"Kai", "Dobermann"});

  printf("\n");

  printPersonPointer(&(struct Person){"Klaus", "Schlegel"});
  printPersonPointer(&(struct Person){"Diana", "Hemmerle"});

  return 0;
}
