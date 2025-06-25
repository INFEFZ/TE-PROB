#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

typedef struct person {
   char vorname [80];
   char nachname [80];
   short geburtsjahr;
} person;

void printPerson(const person* const p);

// Weitere exportierte Funktions-Prototypen ...

#endif
