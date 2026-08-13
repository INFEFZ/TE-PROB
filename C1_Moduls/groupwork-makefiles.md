|                             |                          |                               |
| --------------------------- | ------------------------ | ----------------------------- |
| **Elektrotechniker/-in HF** | **Programmiertechnik B** | ![logo](../x_gitres/logo.png) |

- [1. Gruppenarbeit Moduls](#1-gruppenarbeit-moduls)
  - [1.1. Ziel der Gruppenarbeit](#11-ziel-der-gruppenarbeit)
  - [1.2. Gruppenarbeit A – "Bestehendes Projekt mit Makefile ausstatten"](#12-gruppenarbeit-a--bestehendes-projekt-mit-makefile-ausstatten)
    - [1.2.1. Szenario](#121-szenario)
    - [1.2.2. Vorgegebener Projektcode](#122-vorgegebener-projektcode)
    - [1.2.3. Aufgabenstellung](#123-aufgabenstellung)
    - [1.2.4. Pflichtanforderungen](#124-pflichtanforderungen)
    - [1.2.5. Präsentationsfragen](#125-präsentationsfragen)
  - [1.3. Gruppenarbeit B – "Fehlerhaftes Makefile debuggen"](#13-gruppenarbeit-b--fehlerhaftes-makefile-debuggen)
    - [1.3.1. Szenario](#131-szenario)
    - [1.3.2. Vorgegebener fehlerhafter Code](#132-vorgegebener-fehlerhafter-code)
    - [1.3.3. Aufgabenstellung](#133-aufgabenstellung)
    - [1.3.4. Pflichtanforderungen](#134-pflichtanforderungen)
    - [1.3.5. Präsentationsfragen](#135-präsentationsfragen)
  - [1.4. Gruppenarbeit C – "Modulares Projekt mit Debug- und Release-Build"](#14-gruppenarbeit-c--modulares-projekt-mit-debug--und-release-build)
    - [1.4.1. Szenario](#141-szenario)
    - [1.4.2. Zu erstellende Dateien](#142-zu-erstellende-dateien)
    - [1.4.3. Makefile-Anforderungen](#143-makefile-anforderungen)
    - [1.4.4. Pflichtanforderungen](#144-pflichtanforderungen)
    - [1.4.5. Präsentationsfragen](#145-präsentationsfragen)
  - [1.5. Gruppenarbeit D – "Makefile für das Modularisierungs-Projekt"](#15-gruppenarbeit-d--makefile-für-das-modularisierungs-projekt)
    - [1.5.1. Szenario](#151-szenario)
    - [1.5.2. Ersatz-Projektstruktur (falls kein eigenes Projekt vorhanden)](#152-ersatz-projektstruktur-falls-kein-eigenes-projekt-vorhanden)
    - [1.5.3. Makefile-Anforderungen](#153-makefile-anforderungen)
    - [1.5.4. Pflichtanforderungen](#154-pflichtanforderungen)
    - [1.5.5. Präsentationsfragen](#155-präsentationsfragen)

---

</br>

# 1. Gruppenarbeit Moduls

| **Vorgabe**         | **Beschreibung**                                                                                   |
| :------------------ | :------------------------------------------------------------------------------------------------- |
| **Lernziele**       | Den Zweck und Aufbau eines Makefiles (Target, Dependencies, Recipe) erklären                       |
|                     | Ein Makefile für ein Mehrdateiprojekt mit korrekten Header-Abhängigkeiten erstellen                |
|                     | Makefile-Variablen (CC, CFLAGS, OBJS) und automatische Variablen ($@, $<, $^) einsetzen            |
|                     | Phony-Targets (all, clean, rebuild, help) definieren und deren Notwendigkeit erklären              |
|                     | Den Zeitstempel-Mechanismus von make erklären und das Verhalten bei geänderten Dateien vorhersagen |
|                     | Den Unterschied zwischen Kompilierung (.c → .o) und Linking (.o → Programm) erläutern              |
| **Sozialform**      | Gruppenarbeit: 2-3 Personen                                                                        |
| **Auftrag**         | siehe unten                                                                                        |
| **Hilfsmittel**     |                                                                                                    |
| **Zeitbedarf**      | 60min                                                                                              |
| **Lösungselemente** | Alle Projektdateien inkl. `Makefile`                 "                                             |

> Hinweis zum KI-Einsatz
>
> Ein Makefile, das irgendwie funktioniert, ist kein Beweis für Verständnis.
> In der Präsentation wird jedes Mitglied einzeln gefragt:
>
> - *"Zeig mir die Abhängigkeiten von `main.o` – warum genau diese?"*
> - *"Was passiert beim zweiten `make`-Aufruf ohne Änderung?"*
> - *"Ich ändere jetzt `rechner.h` – welche `.o`-Dateien werden neu kompiliert? Warum?"*
> - *"Was bedeutet `$^` in dieser Zeile?"*
> - *"Warum steht `.PHONY` dort? Was passiert ohne es?"*
> - *"Zeig mir den Unterschied zwischen dem ersten und zweiten `make` in deinem Terminal."*
>
> Das Terminal lügt nicht: `make` muss live ausgeführt werden – mit sichtbarem Output.

## 1.1. Ziel der Gruppenarbeit

Die Lernenden sollen verstehen, wie eine Makefile für die Programmerstellung (Kompilierung und Linken) erstellt und eingesetzt werden kann.

## 1.2. Gruppenarbeit A – "Bestehendes Projekt mit Makefile ausstatten"

### 1.2.1. Szenario

- Ihr übernehmt ein bestehendes C-Projekt, das bisher ohne Makefile kompiliert wurde.
- Eure Aufgabe: das Projekt analysieren, die Abhängigkeiten verstehen und ein vollständiges, professionelles Makefile dazu schreiben.

### 1.2.2. Vorgegebener Projektcode

Erstellt folgende Dateien **exakt** so (Inhalt abtippen oder kopieren):

**`mathe.h`**

```c
#ifndef MATHE_H
#define MATHE_H
 
#define PI 3.14159265358979
 
double potenz(double basis, int exp);
double kreisFlaeche(double r);
double kreisUmfang(double r);
double dreieckHypotenuse(double a, double b);
 
#endif
```

**`mathe.c`**

```c
#include "mathe.h"
#include <math.h>
 
double potenz(double basis, int exp) {
    double ergebnis = 1.0;
    for (int i = 0; i < exp; i++) ergebnis *= basis;
    return ergebnis;
}
 
double kreisFlaeche(double r)          { return PI * r * r; }
double kreisUmfang(double r)           { return 2.0 * PI * r; }
double dreieckHypotenuse(double a, double b) { return sqrt(a*a + b*b); }
```

**`ausgabe.h`**

```c
#ifndef AUSGABE_H
#define AUSGABE_H
 
void ausgabeErgebnis(char *bezeichnung, double wert);
void ausgabeTrennlinie(void);
void ausgabeUeberschrift(char *titel);
 
#endif
```

**`ausgabe.c`**

```c
#include "ausgabe.h"
#include <stdio.h>
 
void ausgabeErgebnis(char *bezeichnung, double wert) {
    printf("  %-25s: %10.4f\n", bezeichnung, wert);
}
void ausgabeTrennlinie(void)         { printf("  %s\n", "------------------------------------"); }
void ausgabeUeberschrift(char *titel){ printf("\n  === %s ===\n", titel); }
```

**`main.c`**

```c
#include <stdio.h>
#include "mathe.h"
#include "ausgabe.h"
 
int main(void) {
    ausgabeUeberschrift("Kreisberechnungen");
    ausgabeErgebnis("Fläche  r=5",   kreisFlaeche(5.0));
    ausgabeErgebnis("Umfang  r=5",   kreisUmfang(5.0));
    ausgabeErgebnis("Fläche  r=10",  kreisFlaeche(10.0));
    ausgabeTrennlinie();
 
    ausgabeUeberschrift("Weitere Berechnungen");
    ausgabeErgebnis("2^10",          potenz(2.0, 10));
    ausgabeErgebnis("Hypotenuse 3/4",dreieckHypotenuse(3.0, 4.0));
    ausgabeTrennlinie();
 
    return 0;
}
```

### 1.2.3. Aufgabenstellung

**Schritt 1 – Abhängigkeiten analysieren:**

Zeichnet den Abhängigkeitsgraph auf Papier:

- Welche `.c`-Datei inkludiert welche `.h`-Datei?
- Welche `.o`-Dateien entstehen?
- Was hängt vom was ab?

```bash
programm
├── main.o     ← main.c inkludiert: ???
├── mathe.o    ← mathe.c inkludiert: ???
└── ausgabe.o  ← ausgabe.c inkludiert: ???
```

**Schritt 2 – Makefile schreiben:**

Erstellt `Makefile` mit folgenden Anforderungen:

```console
Pflicht-Targets:
  all      → kompiliert das Programm (Standard-Target)
  clean    → löscht alle .o Dateien und das Programm
  rebuild  → clean + all in einem Schritt
  help     → zeigt alle Targets mit Beschreibung
 
Pflicht-Variablen:
  CC, CFLAGS, LDFLAGS, TARGET, OBJS
 
Pflicht-Flags:
  -Wall -Wextra -std=c11 -g
 
Pflicht-Struktur:
  Zweistufig: erst .o kompilieren, dann linken
  Korrekte Header-Abhängigkeiten bei jeder .o-Regel
  .PHONY für alle nicht-Datei-Targets
```

**Schritt 3 – Verhalten testen und dokumentieren:**

Führt folgende Befehle aus und notiert den Output:

```bash
make                  # erstes Mal – was wird ausgeführt?
make                  # zweites Mal ohne Änderung – was passiert?
touch mathe.c         # Zeitstempel aktualisieren
make                  # was wird jetzt kompiliert?
touch mathe.h         # Header ändern
make                  # welche .o werden neu gebaut?
make clean            # aufräumen
make rebuild          # alles neu
make help             # Hilfe anzeigen
```

### 1.2.4. Pflichtanforderungen

- [ ] Zweistufige Kompilierung (`.o`-Dateien explizit)
- [ ] Alle Header-Abhängigkeiten korrekt eingetragen
- [ ] Variablen `CC`, `CFLAGS`, `LDFLAGS`, `TARGET`, `OBJS` verwendet
- [ ] Automatische Variablen `$@`, `$<` oder `$^` mindestens einmal
- [ ] Targets `all`, `clean`, `rebuild`, `help` vorhanden
- [ ] `.PHONY` korrekt deklariert
- [ ] Programm kompiliert und läuft korrekt

### 1.2.5. Präsentationsfragen

1. Zeig den Abhängigkeitsgraph den ihr gezeichnet habt – erkläre warum `main.o` von `mathe.h` **und** `ausgabe.h` abhängt.
2. Führe `make` zweimal hintereinander aus – erkläre den Unterschied im Output.
3. Führe `touch mathe.h` aus, dann `make` – welche `.o`-Dateien werden neu gebaut? Warum genau diese?
4. Was bedeutet `$(OBJS:.c=.o)` – was macht diese Syntax?
5. Entferne `.PHONY: clean` – lege dann eine Datei namens `clean` an (`touch clean`). Was passiert bei `make clean`? Warum?

---

---

## 1.3. Gruppenarbeit B – "Fehlerhaftes Makefile debuggen"

### 1.3.1. Szenario

- Ein Studienkollege-/inn hat ein **Makefile** geschrieben – es ist voller Fehler.
- Eure Aufgabe: alle Fehler finden, erklären **warum** sie falsch sind, und ein korrigiertes, verbessertes Makefile abliefern.

### 1.3.2. Vorgegebener fehlerhafter Code

**Projektdateien** (korrekt – nicht ändern):

**`rechner.h`**

```c
#ifndef RECHNER_H
#define RECHNER_H
double add(double a, double b);
double sub(double a, double b);
double mul(double a, double b);
double dvd(double a, double b);
#endif
```

**`rechner.c`**

```c
#include "rechner.h"
#include <stdio.h>
double add(double a, double b) { return a + b; }
double sub(double a, double b) { return a - b; }
double mul(double a, double b) { return a * b; }
double dvd(double a, double b) {
    if (b == 0.0) { printf("Fehler: /0\n"); return 0.0; }
    return a / b;
}
```

**`logger.h`**

```c
#ifndef LOGGER_H
#define LOGGER_H
void logInfo(char *msg);
void logFehler(char *msg);
#endif
```

**`logger.c`**

```c
#include "logger.h"
#include <stdio.h>
void logInfo(char *msg)   { printf("[INFO]  %s\n", msg); }
void logFehler(char *msg) { printf("[ERROR] %s\n", msg); }
```

**`main.c`**

```c
#include <stdio.h>
#include "rechner.h"
#include "logger.h"
int main(void) {
    logInfo("Programm gestartet");
    printf("5 + 3 = %.1f\n", add(5, 3));
    printf("5 / 0 = %.1f\n", dvd(5, 0));
    logInfo("Programm beendet");
    return 0;
}
```

**Das fehlerhafte `Makefile`** (enthält **8 absichtliche Fehler**):

```makefile
cc = gcc
cflags = -Wall -std=c11
TARGET = rechner_demo
 
all: $(TARGET)
 
$(TARGET): main.o rechner.o logger.o
    cc main.o rechner.o logger.o -o $(TARGET)
 
main.o: main.c
    $(cc) $(cflags) -c main.c -o main.o
 
rechner.o: rechner.c
    $(cc) $(cflags) -c rechner.c -o rechner.o
 
logger.o: logger.c
    $(cc) $(cflags) -c logger.c -o logger.o
 
clean:
    rm *.o
    rm $(TARGET)
 
rebuild: all clean
 
.PHONY: all clean
```

### 1.3.3. Aufgabenstellung

**Schritt 1 – Fehleranalyse (15 min):**

Findet und dokumentiert alle Fehler in einer Tabelle:

| #   | Zeile(n) | Fehler | Erklärung | Korrektur |
| --- | -------- | ------ | --------- | --------- |
| 1   |          |        |           |           |
| 2   |          |        |           |           |
| ... |          |        |           |           |

**Hinweis:** Es gibt Fehler in folgenden Kategorien:

- Syntaxfehler (Makefile-Syntax)
- Fehlende Abhängigkeiten (Dependencies unvollständig)
- Logikfehler (falscher Ablauf)
- Fehlende Flags / Libraries
- Unvollständige Deklarationen
**Schritt 2 – Korrigiertes Makefile erstellen:**

Schreibt das vollständig korrigierte Makefile mit allen Verbesserungen.
Ergänzt zusätzlich:

- Variablen `OBJS` und `LDFLAGS`
- Automatische Variablen `$@` und `$^`
- Target `help` mit Beschreibung aller Targets
- Target `debug` mit `-g -DDEBUG` Flags
**Schritt 3 – Verifikation:**

Beweist in der Präsentation live:

```bash
make                  # kompiliert ohne Fehler
./rechner_demo        # läuft korrekt
make clean            # räumt auf
ls *.o 2>/dev/null || echo "Keine .o Dateien – clean hat funktioniert"
make debug            # kompiliert mit Debug-Flags
```

### 1.3.4. Pflichtanforderungen

- [ ] Alle 8 Fehler gefunden und in der Tabelle dokumentiert
- [ ] Korrigiertes Makefile kompiliert ohne Warnungen
- [ ] `OBJS`, `LDFLAGS` als Variablen ergänzt
- [ ] `debug`-Target korrekt implementiert
- [ ] `help`-Target mit `@echo` implementiert
- [ ] `.PHONY` vollständig

### 1.3.5. Präsentationsfragen

1. Erkläre Fehler Nr. 1 aus eurer Tabelle – was genau ist falsch und was passiert dadurch?
2. Warum müssen Variablennamen in Makefiles gross geschrieben sein? (Konvention vs. Pflicht?)
3. Zeigt den Unterschied zwischen `make all` und `make debug` im Terminal-Output.
4. In der Originalversion fehlt `rechner.h` als Dependency bei `rechner.o` – was kann dadurch schiefgehen?
5. `rebuild: all clean` – warum ist die Reihenfolge falsch? Was wäre korrekt?

---

## 1.4. Gruppenarbeit C – "Modulares Projekt mit Debug- und Release-Build"

### 1.4.1. Szenario

- Ihr entwickelt ein Temperaturkonvertierungs-Tool als sauber modularisiertes Projekt **und** schreibt dazu ein Makefile, das sowohl einen Debug- als auch einen Release-Build unterstützt.
- **Ziel**: ein einziges Makefile für zwei völlig unterschiedliche Build-Varianten.

### 1.4.2. Zu erstellende Dateien

**`konverter.h`**

```c
#ifndef KONVERTER_H
#define KONVERTER_H
 
double celsiusZuFahrenheit(double c);
double celsiusZuKelvin(double c);
double fahrenheitZuCelsius(double f);
double kelvinZuCelsius(double k);
 
#endif
```

**`konverter.c`**

```c
#include "konverter.h"
 
double celsiusZuFahrenheit(double c) { return c * 1.8 + 32.0; }
double celsiusZuKelvin(double c)     { return c + 273.15; }
double fahrenheitZuCelsius(double f) { return (f - 32.0) / 1.8; }
double kelvinZuCelsius(double k)     { return k - 273.15; }
```

**`tabelle.h`**

```c
#ifndef TABELLE_H
#define TABELLE_H
 
void tabelleDrucken(double vonCelsius, double bisCelsius, double schrittweite);
void tabelleKopf(void);
 
#endif
```

**`tabelle.c`**

```c
#include "tabelle.h"
#include "konverter.h"
#include <stdio.h>
 
void tabelleKopf(void) {
    printf("%-10s | %-12s | %-10s\n", "Celsius", "Fahrenheit", "Kelvin");
    printf("%-10s-+-%-12s-+-%-10s\n", "----------", "------------", "----------");
}
 
void tabelleDrucken(double von, double bis, double schritt) {
    tabelleKopf();
    for (double c = von; c <= bis; c += schritt) {
        printf("%10.2f | %12.2f | %10.2f\n",
               c,
               celsiusZuFahrenheit(c),
               celsiusZuKelvin(c));
    }
}
```

**`main.c`**

```c
#include <stdio.h>
#include "konverter.h"
#include "tabelle.h"
 
#ifdef DEBUG
    #define LOG(msg) printf("[DEBUG] %s\n", msg)
#else
    #define LOG(msg)
#endif
 
int main(void) {
    LOG("Programm gestartet");
 
    printf("=== Temperaturkonverter ===\n\n");
 
    printf("Einzelkonvertierungen:\n");
    printf("  100°C = %.2f°F\n", celsiusZuFahrenheit(100.0));
    printf("  100°C = %.2f K\n", celsiusZuKelvin(100.0));
    printf("  212°F = %.2f°C\n", fahrenheitZuCelsius(212.0));
 
    printf("\nKonversionstabelle -20°C bis 100°C:\n");
    tabelleDrucken(-20.0, 100.0, 10.0);
 
    LOG("Programm beendet");
    return 0;
}
```

### 1.4.3. Makefile-Anforderungen

Das Makefile muss folgende Build-Varianten unterstützen:

```bash
make              # Standard → Release-Build
make release      # Explizit Release: -O2 -std=c11 -Wall
make debug        # Debug-Build: -g -DDEBUG -Wall -std=c11
make clean        # Alles löschen
make rebuild      # clean + release
make info         # Projektinformationen anzeigen
make help         # Alle Targets beschreiben
```

**Besonderheit:** Debug- und Release-Build sollen **verschiedene Programmnamen** erzeugen:

- Release: `temperatur`
- Debug: `temperatur_debug`
**Target `info` soll ausgeben:**

```console
========================================
  Projekt:    Temperaturkonverter
  Compiler:   gcc
  Version:    $(shell gcc --version | head -1)
  Quelldateien: main.c konverter.c tabelle.c
  Objekte:    main.o konverter.o tabelle.o
========================================
```

**Hinweis `$(shell ...)`:**

```makefile
# $(shell befehl) führt einen Shell-Befehl aus und gibt die Ausgabe zurück
GCC_VERSION = $(shell gcc --version | head -1)
```

### 1.4.4. Pflichtanforderungen

- [ ] `release` und `debug` erzeugen unterschiedliche Programmnamen
- [ ] `DEBUG`-Makro in `main.c` funktioniert (Log-Ausgabe nur bei `make debug`)
- [ ] `$(shell ...)` in `info`-Target verwendet
- [ ] Korrekte Header-Abhängigkeiten (`tabelle.o` hängt von `konverter.h` ab!)
- [ ] Alle Targets mit `.PHONY` deklariert
- [ ] Automatische Variablen `$@`, `$^`, `$<` mindestens je einmal verwendet

### 1.4.5. Präsentationsfragen

1. Zeige live: `make release` und `make debug` – erkläre den Unterschied im Output und im Verhalten des Programms.
2. `tabelle.o` muss auch von `konverter.h` abhängen – warum? Was passiert sonst?
3. Was macht `$(shell gcc --version | head -1)` genau? Wann wird das ausgeführt?
4. Erkläre `#ifdef DEBUG` in `main.c` – wie hängt das mit dem Makefile zusammen?
5. Warum braucht der `debug`-Build `-DDEBUG` als Flag? Wo kommt dieses Symbol her?

---

## 1.5. Gruppenarbeit D – "Makefile für das Modularisierungs-Projekt"

### 1.5.1. Szenario

- Ihr nehmt euer Projekt aus der **Gruppenarbeit D der Modularisierungslektion** (Lagerverwaltungssystem) und stattet es mit einem vollständigen, professionellen **Makefile** aus.
- Falls ihr dieses Projekt nicht habt, verwendet den unten angegebenen Ersatz-Projektcode.

> **Ziel dieser Aufgabe:** Ihr verbindet das Wissen aus der Modularisierungslektion
> mit dem Makefile-Wissen. Das Makefile muss die Abhängigkeiten der Module
> korrekt abbilden – inklusive aller Header-Dateien.

### 1.5.2. Ersatz-Projektstruktur (falls kein eigenes Projekt vorhanden)

```console
projekt_d/
├── main.c
├── lager.h
├── lager.c
├── ausgabe.h
└── ausgabe.c
```

**`ausgabe.h`**

```c
#ifndef AUSGABE_H
#define AUSGABE_H
void ausgabeFehler(char *meldung);
void ausgabeTrennlinie(void);
void ausgabeUeberschrift(char *titel);
void ausgabeArtikelzeile(int nr, char *name, int bestand, double preis);
#endif
```

**`ausgabe.c`**

```c
#include "ausgabe.h"
#include <stdio.h>
void ausgabeFehler(char *m)           { printf("[FEHLER] %s\n", m); }
void ausgabeTrennlinie(void)          { printf("%-50s\n","--------------------------------------------------"); }
void ausgabeUeberschrift(char *titel) { printf("\n=== %s ===\n", titel); }
void ausgabeArtikelzeile(int nr, char *name, int bestand, double preis) {
    printf("%-6d | %-20s | %7d | %8.2f CHF\n", nr, name, bestand, preis);
}
```

**`lager.h`**

```c
#ifndef LAGER_H
#define LAGER_H
#define MAX_ARTIKEL 20
int    lagerHinzufuegen(char *name, int nr, int bestand, double preis);
void   lagerAlleAnzeigen(void);
double lagerGesamtwert(void);
void   lagerMindestbestand(int min);
int    lagerAnzahl(void);
#endif
```

**`lager.c`**

```c
#include "lager.h"
#include "ausgabe.h"
#include <string.h>
#include <stdio.h>
 
typedef struct { char name[50]; int nr; int bestand; double preis; } Artikel;
static Artikel liste[MAX_ARTIKEL];
static int anzahl = 0;
 
int lagerHinzufuegen(char *name, int nr, int bestand, double preis) {
    if (anzahl >= MAX_ARTIKEL) { ausgabeFehler("Lager voll!"); return -1; }
    strncpy(liste[anzahl].name, name, 49);
    liste[anzahl].nr = nr; liste[anzahl].bestand = bestand;
    liste[anzahl].preis = preis; anzahl++;
    return 0;
}
void lagerAlleAnzeigen(void) {
    ausgabeUeberschrift("Lagerbestand");
    for (int i = 0; i < anzahl; i++)
        ausgabeArtikelzeile(liste[i].nr, liste[i].name,
                            liste[i].bestand, liste[i].preis);
    ausgabeTrennlinie();
}
double lagerGesamtwert(void) {
    double s = 0; for (int i = 0; i < anzahl; i++) s += liste[i].bestand * liste[i].preis;
    return s;
}
void lagerMindestbestand(int min) {
    ausgabeUeberschrift("Unterbestand");
    for (int i = 0; i < anzahl; i++)
        if (liste[i].bestand < min)
            printf("  [!] %-20s – %d Stk\n", liste[i].name, liste[i].bestand);
}
int lagerAnzahl(void) { return anzahl; }
```

**`main.c`**

```c
#include <stdio.h>
#include "lager.h"
#include "ausgabe.h"
 
int main(void) {
    lagerHinzufuegen("Schrauben M6x20",    1001, 500,  0.05);
    lagerHinzufuegen("Muttern M6",         1002, 320,  0.03);
    lagerHinzufuegen("Unterlegscheiben",   1003,  15,  0.02);
    lagerHinzufuegen("Bohrer 5mm HSS",     1004,  48,  4.90);
    lagerHinzufuegen("Winkelschleifer",    1005,   3, 89.00);
 
    lagerAlleAnzeigen();
    printf("Gesamtlagerwert: CHF %.2f\n", lagerGesamtwert());
    lagerMindestbestand(20);
    printf("\nAnzahl Artikel: %d\n", lagerAnzahl());
    return 0;
}
```

### 1.5.3. Makefile-Anforderungen

Das Makefile muss folgende Anforderungen erfüllen:

**Targets:**

```bash
make              # Standard → kompiliert alles
make clean        # löscht .o und Programm
make rebuild      # clean + all
make debug        # kompiliert mit -g -DDEBUG
make valgrind     # führt Programm mit valgrind aus (Speicherfehler prüfen)
make lines        # zählt Codezeilen aller .c und .h Dateien
make help         # Hilfe
```

**Target `valgrind`:**

```makefile
valgrind: debug
 valgrind --leak-check=full ./$(TARGET)_debug
```

**Target `lines`** mit `$(shell ...)`:

```makefile
lines:
 @echo "Codezeilen:"
 @wc -l $(SRCS) *.h
```

**Besondere Anforderung – korrekte Abhängigkeitskette:**

`lager.o` hängt von `lager.c` **und** `lager.h` **und** `ausgabe.h` ab.
Diese Abhängigkeit muss explizit im Makefile stehen – begründet in der Präsentation.

### 1.5.4. Pflichtanforderungen

- [ ] Alle `.o`-Regeln mit korrekten Header-Abhängigkeiten
- [ ] `lager.o` hängt explizit von `ausgabe.h` ab (begründbar!)
- [ ] `debug`-Target mit separatem Programmnamen
- [ ] `valgrind`-Target korrekt als abhängig von `debug` definiert
- [ ] `lines`-Target mit `$(shell wc -l ...)` oder direkt `wc -l`
- [ ] Variablen `CC`, `CFLAGS`, `LDFLAGS`, `TARGET`, `SRCS`, `OBJS`
- [ ] `.PHONY` vollständig

### 1.5.5. Präsentationsfragen

1. Zeige die Regel für `lager.o` – warum steht `ausgabe.h` in den Dependencies?
2. Führe `make` aus, ändere dann nur `ausgabe.h` (`touch ausgabe.h`), und führe `make` nochmals aus. Welche `.o`-Dateien werden neu gebaut? Erkläre warum.
3. Was macht `make valgrind`? In welcher Reihenfolge werden die Targets abgearbeitet?
4. Was gibt `make lines` aus? Erkläre `$(shell ...)` oder `wc -l` im Kontext.
5. Erkläre den Unterschied zwischen `SRCS` und `OBJS` in eurem Makefile – wie habt ihr `OBJS` aus `SRCS` abgeleitet?

---

© 2026 Lukas Müller – Licensed under CC BY-NC-ND 4.0
See [LICENSE](/license.md) file for details.
