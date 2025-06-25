#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef struct Stack Stack;

enum stackError { 
  STACK_OK,
  STACK_VOLL,
  STACK_LEER
};

// Erstellt eine Stack-Struktur mit gegebener maximale
// Anzahl an Slementen.
Stack* stackErstellen(int count);

// Loescht die Stack-Struktur aus dem Speicher
void stackAufraeumen(Stack* stack);

// Gibt die Anzahl Elemente auf dem Stack zurueck.
int stackCount(const Stack* stack);

// Eine int-Zahl auf den Stack legen.
// Return: Fehlercode.
enum stackError stackPush(Stack* stack, int wert);      

// Eine int-Zahl vom Stack abholen.
// Parameter: Pointer auf int-Zahl, die mit dem obersten
//            Stack-Wert gefuellt wird.
// Return: Fehlercode.
enum stackError stackPop(Stack* stack, int* wertPtr);

#endif
