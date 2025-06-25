#include <stdio.h>

int main(void) {
  struct Strecke { 
    float km;           // Anzahl gerannte Kilometer
    int   hoehenmeter;  // Zurueckgelegter Hoehenunterschied
  };

  struct Lauf { 
    struct Strecke* strecke; // Zeiger auf die Strecke
    int             s;       // Benoetigte Sekunden fuer die Strecke
  };

  struct Trainingsplan { 
    struct Lauf morgenrunde;
    struct Lauf mittagsrunde;
    struct Lauf abendrunde;
  };

  struct Trainingsplan montag;
  struct Trainingsplan dienstag;

  struct Strecke finnenbahn = {5, 60}; 
  struct Strecke seeweg     = {3, 0}; 
  struct Strecke waldweg    = {20, 200}; 

  montag.morgenrunde.strecke = &finnenbahn;
  montag.morgenrunde.s = 30 * 60;
  montag.mittagsrunde.strecke = &seeweg;
  montag.mittagsrunde.s = 15 * 60;
  montag.abendrunde.strecke = &waldweg;
  montag.abendrunde.s = 80 * 60;

  dienstag.morgenrunde.strecke = &finnenbahn;
  dienstag.morgenrunde.s = 25 * 60;

  printf("%.0f Meter in %d:%02d Minuten = %.1f km/h\n",
    dienstag.morgenrunde.strecke->km * 1000.f,
    dienstag.morgenrunde.s / 60,
    dienstag.morgenrunde.s % 60,
    dienstag.morgenrunde.strecke->km / dienstag.morgenrunde.s * 3600);

  return 0;
}
