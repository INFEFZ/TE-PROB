#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person Person;
struct Person {
  char name[20];
  int alter;
};

void printPerson(const Person* p) {
  printf("%s: %d Jahre alt.\n", p->name, p->alter);
}

Person* allocatePerson(const char* name, int alter) {
  Person* person = malloc(sizeof(Person));
  strncpy(person->name, name, 20);
  person->alter = alter;
  return person;
}

int main(void) {
  Person* person1 = allocatePerson("Tanja Schulz", 42);
  Person* person2 = allocatePerson("Heinrich Dall", 15);
  Person* person3 = allocatePerson("Karl-Heinz Schuler", 64);

  printPerson(person1);
  printPerson(person2);
  printPerson(person3);

  free(person1);
  free(person2);
  free(person3);

  return 0;
}
