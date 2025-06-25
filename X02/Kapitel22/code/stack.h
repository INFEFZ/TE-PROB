#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

enum stackError { 
  STACK_OK,
  STACK_VOLL,
  STACK_LEER
};

// Eine int-Zahl auf den Stack legen.
// Gibt einen Fehlercode zurueck.
extern enum stackError stackPush(int wert);      

// Eine int-Zahl vom Stack abholen.
// Parameter: Pointer auf int-Zahl, die mit dem obersten
//            Stack-Wert gefuellt wird.
// Gibt einen Fehlercode zurueck.
extern enum stackError stackPop(int* wertPtr);

#endif
