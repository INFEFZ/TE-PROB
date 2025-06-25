#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person Person;
struct Person {
  char* name;
  int alter;
};

void printPerson(const Person* p) {
  printf("%s: %d Jahre alt.\n", p->name, p->alter);
}

void initPerson(Person* p, const char* name, int alter) {
  size_t len = strlen(name);
  p->name = malloc(sizeof(char) * (len + 1));
  strncpy(p->name, name, len);
  p->name[len] = '\0';
  p->alter = alter;
}

Person* allocatePerson(void) {
  Person* person = malloc(sizeof(Person));
  return person;
}

void deallocatePerson(Person* person) {
  free(person->name);
  free(person);
}

#define COUNT 3

int main (void) {
  Person* persons[COUNT];
  for (int i = 0; i < COUNT; ++i)
    persons[i] = allocatePerson();

  initPerson(persons[0], "Tanja Schulz", 42);
  initPerson(persons[1], "Heinrich Dall", 15);
  initPerson(persons[2], "Karl-Heinz Schuler", 64);

  for (int i = 0; i < COUNT; ++i)
    printPerson(persons[i]);

  for (int i = 0; i < COUNT; ++i)
    deallocatePerson(persons[i]);

  return 0;
}
