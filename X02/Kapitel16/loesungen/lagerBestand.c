// MSVC meldet fuer veraltete, unsichere C-Funktionen wie
// fopen einen Fehler.
// Mittels folgender Zeile koennen diese Fehler ausgeschaltet
// werden:
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct Artikel Artikel;
struct Artikel {
  int nummer;
  int bestand;
  double gewicht;
  double preis;
};

#define COUNT 4
#define EUR_USD 0.943

void transferInDollar(const char* dateiNameEuro, const char* dateiNameDollar) {
  Artikel artikel[COUNT];
  FILE* feuro = fopen(dateiNameEuro, "rb");
  fread(artikel, sizeof(Artikel), COUNT, feuro);
  fclose(feuro);

  for (int i = 0; i < COUNT; ++i) {
    artikel[i].preis *= EUR_USD;
  }

  FILE* fdollar = fopen(dateiNameDollar, "wb");
  fwrite(artikel, sizeof(Artikel), COUNT, fdollar);
  fclose(fdollar);
}

int main (void) {
  Artikel artikel[COUNT] = {
    {9169, 500, 6.334,  19.47},
    {4464, 962, 29.358, 15.48},
    {9961, 827, 23.281, 28.15},
    {5436, 827, 11.942,  4.00},
  };

  for (int i = 0; i < COUNT; ++i) {
    printf("%-8d %4d %6.03f %5.02f EUR \n",
      artikel[i].nummer,
      artikel[i].bestand,
      artikel[i].gewicht,
      artikel[i].preis);
  }

  const char* dateiNameEuro = "lager.lst";
  const char* dateiNameDollar = "lagerUSD.lst";

  FILE* feuro = fopen(dateiNameEuro, "wb");
  fwrite(artikel, sizeof(Artikel), COUNT, feuro);
  fclose(feuro);

  transferInDollar(dateiNameEuro, dateiNameDollar);

  return 0;
}

// Speichern der Anzahl Artikel:
// Eine einfache Moeglichkeit ist, die Anzahl vor den eigentlichen Daten in
// derselben Datei zu speichern, beispielsweise mittels folgender Zeile:
//
// fwrite(COUNT, sizeof(int), 1, feuro);
//
// Beim Lesen der Datei muss einfach ebenfalls erst diese Anzahl gelesen werden.
// Dies fuehrt dazu, dass eine Datei ein sogenanntes Dateiformat erhaelt, bei
// welchem genau definiert ist, mit welcher Struktur die Daten angeordnet sind.
// Wenn sich ein Programm nicht an ein bestimmtes Format haelt, so koennen
// Daten nicht korrekt gelesen werden.


// Speichern mittels Strings:
// Bei so einfachen Daten ist die Speicherung mittels Strings problemlos und
// kann sogar vorteilhaft sein. Heutzutage sind beispielsweise haeufig Dateien
// im XML- oder JSON-Format verfuegbar. Dies sind reine Textdateien, welche
// jedoch in sich ein Format definieren.
//
// Nachteile solcher String-Dateien sind:
// - Muessen zuerst interpretiert und in binaere Daten umgewandelt werden. Dies
//   kostet zum einen Zeit, zum anderen sind beispielsweise Umwandlungen von
//   Gleitpunkt-Zahlen nicht in jeder C-Bibliothek genau gleich.
// - Strings brauchen im Allgemeinen mehr Platz als Binaerdaten.
// - Das Lesen von Strings laesst einen Interpretations-Spielraum zu. Kann auch
//   ein Vorteil sein.
// 
// Vorteile sind:
// - Die Daten sind Menschen-lesbar (human-readable).
// - Solche Dateien sind haeufiger fehlertolerant (Interpretations-Spielraum).
//
// Es gibt keine abschliessende Diskussion, ob binaer oder string das bessere
// Dateiformat abgibt. Fuer jede Situation gibt es Vor- und Nachteile.
