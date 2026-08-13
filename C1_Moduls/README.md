|                             |                          |                               |
| --------------------------- | ------------------------ | ----------------------------- |
| **Elektrotechniker/-in HF** | **Programmiertechnik B** | ![Logo](../x_gitres/logo.png) |

- [1. Modularisierung](#1-modularisierung)
  - [1.1. Lernziele](#11-lernziele)
  - [1.2. Warum Modularisierung?](#12-warum-modularisierung)
  - [1.3. Modulares Design – Grundprinzipien](#13-modulares-design--grundprinzipien)
  - [1.4. Schnittstelle und Implementierung trennen](#14-schnittstelle-und-implementierung-trennen)
  - [1.5. Header-Dateien (`.h`)](#15-header-dateien-h)
    - [1.5.1. Aufbau einer Header-Datei](#151-aufbau-einer-header-datei)
    - [1.5.2. Aufbau einer Quellcode-Datei (`.c`)](#152-aufbau-einer-quellcode-datei-c)
    - [1.5.3. Verwendung in `main.c`](#153-verwendung-in-mainc)
  - [1.6. Das Schlüsselwort `#include`](#16-das-schlüsselwort-include)
  - [1.7. Das Schlüsselwort extern](#17-das-schlüsselwort-extern)
    - [1.7.1. `extern` – Deklaration ohne Definition](#171-extern--deklaration-ohne-definition)
    - [1.7.2. `extern` für Funktionen](#172-extern-für-funktionen)
  - [1.8. Das Schlüsselwort `static`](#18-das-schlüsselwort-static)
  - [1.9. Include-Guard mit `#ifndef`](#19-include-guard-mit-ifndef)
    - [1.9.1. Vollständiges Beispiel](#191-vollständiges-beispiel)
  - [1.10. Das vollständige Bild – Modulstruktur in der Praxis](#110-das-vollständige-bild--modulstruktur-in-der-praxis)
  - [1.11. Kompilierung](#111-kompilierung)
    - [1.11.1. Beispiel Visual Studio Code (tasks.json)](#1111-beispiel-visual-studio-code-tasksjson)
  - [1.12. Die goldene Regel der Modularisierung](#112-die-goldene-regel-der-modularisierung)
- [2. Aufgaben](#2-aufgaben)
  - [2.1. Separates Module für Trennstrich-Funktionen](#21-separates-module-für-trennstrich-funktionen)

---

</br>

# 1. Modularisierung

## 1.1. Lernziele

- Nach dieser Lektion können sie ein C-Programm in **mehrere Dateien** aufteilen, Schnittstellen über **Header-Dateien** definieren, Implementierungen kapseln und Include-Guards korrekt einsetzen.
- Du verstehst den Unterschied zwischen `extern` und `static` und kannst erklären, warum modulares Design professionellen Code auszeichnet.

## 1.2. Warum Modularisierung?

Bisher haben wir alles in eine einzige .c-Datei geschrieben. Das funktioniert – aber nur solange das Programm **klein** bleibt.
Stell dir ein reales Projekt vor:

```console
main.c  →  5'000 Zeilen Code
    - Benutzeroberfläche
    - Datenbankzugriffe
    - Berechnungslogik
    - Fehlerbehandlung
    - Hilfsfunktionen
```

**Probleme:**

- Niemand findet sich mehr zurecht
- Zwei Entwickler können nicht gleichzeitig arbeiten (eine Datei = ein Konflikt)
- Eine Änderung an der Datenbank bricht versehentlich die Benutzeroberfläche
- Einzelne Teile lassen sich nicht wiederverwenden
- Tests sind kaum möglich

**Die Lösung: Modulares Design:**

```console
main.c          → Programmstart, Hauptablauf
berechnung.c    → Alle Berechnungsfunktionen
datenbank.c     → Datenbankzugriffe
ausgabe.c       → Bildschirmausgaben
hilfsfunktionen.c → Allgemeine Utilities
```

> **Ein Modul ist eine abgeschlossene Einheit, die eine klar definierte Aufgabe erfüllt, eine saubere Schnittstelle nach aussen anbietet und ihre interne Umsetzung verborgen hält.**

---

## 1.3. Modulares Design – Grundprinzipien

Gutes modulares Design folgt drei **Kernprinzipien**:

- **Hohe Kohäsion (High Cohesion)**: Alles, was zusammengehört, kommt in dasselbe Modul.
  - **Gut**: modul_statistik.c → nur statistische Berechnungen
  - **Schlecht**: misc.c       → Statistik + Dateioperationen + Anzeige
- **Lose Kopplung (Low Coupling)**: Module sollen so wenig wie möglich voneinander wissen. Sie kommunizieren nur über definierte Schnittstellen.
  - **Gut**: modul_a ruft berechneFeld(wert) aus modul_b auf
  - **Schlecht**: modul_a greift direkt auf interne Variable von modul_b zu
- **Information Hiding (Geheimnisprinzip)**: Die interne Implementierung eines Moduls ist nach aussen unsichtbar. Andere Module wissen nur was ein Modul tut, nicht wie es das tut.
  - Analogie: Wenn du ein Auto fährst, kennst du das Lenkrad (Schnittstelle).
          Du musst nicht wissen, wie der Lenkgetriebe intern funktioniert
          (Implementierung). Der Hersteller kann das intern ändern –
          solange das Lenkrad gleich bleibt, merkst du nichts.

**Vorteil**: Die Implementierung kann jederzeit verbessert oder ausgetauscht werden, ohne dass andere Module angepasst werden müssen.

---

## 1.4. Schnittstelle und Implementierung trennen

In C wird diese Trennung durch zwei Dateitypen umgesetzt:

```console
┌─────────────────────────────────────────────────────────────┐
│                      Ein C-Modul                            │
├────────────────────────┬────────────────────────────────────┤
│   modul.h              │   modul.c                          │
│   (Schnittstelle)      │   (Implementierung)                │
│                        │                                    │
│   Was bietet das       │   Wie ist es                       │
│   Modul an?            │   umgesetzt?                       │
│                        │                                    │
│   • Prototypen         │   • Funktionsrümpfe                │
│   • Typdeklarationen   │   • Hilfsvariablen                 │
│   • Konstanten         │   • Interne Hilfsfunktionen        │
│   • Datenstrukturen    │   • Algorithmen                    │
│                        │                                    │
│   Öffentlich sichtbar  │   Verborgen (private)              │
└────────────────────────┴────────────────────────────────────┘
```

> Die .h-Datei ist der **Vertrag** zwischen dem Modul und seinen Nutzern. Alles in der .h-Datei ist öffentlich. Alles nur in der .c-Datei ist privat.

Das Definieren eigener **Module** in C ist sinnvoll aus mehreren Gründen:

- **Wiederverwendbarkeit**: Code kann in verschiedenen Projekten wiederverwendet werden, ohne ihn neu schreiben zu müssen.
- **Modularität**: Der Code wird in logische Einheiten unterteilt, die leichter zu verstehen und zu warten sind.
- **Kapselung**: Interne Implementierungsdetails werden verborgen, nur die notwendigen Schnittstellen werden offengelegt.
- **Wartbarkeit**: Änderungen in einem Modul haben weniger Auswirkungen auf andere Teile des Programms.
- **Lesbarkeit**: Der Code wird klarer und strukturierter, was das Verständnis und die Zusammenarbeit erleichtert.
- **Fehlervermeidung**: Modularer Code fördert eine klare Trennung der Verantwortlichkeiten, was die Wahrscheinlichkeit von Fehlern reduziert.
- **Kompilierungszeit**: Änderungen in einem Modul erfordern nur die Neukompilierung dieses Moduls und nicht des gesamten Projekts.
- **Testbarkeit**: Einzelne Module können isoliert getestet werden, was die Fehlerfindung und -behebung vereinfacht.
- **Teamarbeit**: Verschiedene Teammitglieder können an unterschiedlichen Modulen gleichzeitig arbeiten, ohne Konflikte zu verursachen.
- **Erweiterbarkeit**: Neue Funktionen können durch Hinzufügen neuer Module einfach integriert werden, ohne den bestehenden Code wesentlich zu ändern.

---

## 1.5. Header-Dateien (`.h`)

Eine Header-Datei deklariert die öffentliche Schnittstelle eines Moduls:

- Funktionsprototypen
- Konstanten (#define)
- Typdefinitionen und Strukturen
- Deklarationen von globalen Variablen (extern)

### 1.5.1. Aufbau einer Header-Datei

```c
// rechner.h – Schnittstelle des Moduls "rechner"

#ifndef RECHNER_H      // Include-Guard – verhindert Mehrfacheinbindung
#define RECHNER_H      // (dazu mehr in Abschnitt 8)

// Konstanten
#define PI 3.14159265358979

// Funktionsprototypen (öffentliche Schnittstellen)
double addiere(double a, double b);
double subtrahiere(double a, double b);
double multipliziere(double a, double b);
double dividiere(double a, double b);    // gibt 0.0 zurück bei Division durch 0
double kreisFlaeche(double radius);

#endif  // RECHNER_H
```

> Wichtig: Header-Dateien enthalten keine Funktionsrümpfe und keinen ausführbaren Code – nur Deklarationen.

### 1.5.2. Aufbau einer Quellcode-Datei (`.c`)

```c
// rechner.c – Implementierung des Moduls "rechner"

#include "rechner.h"   // eigene Header-Datei (in Anführungszeichen)
#include <stdio.h>     // Standardbibliothek (in spitzen Klammern)

// Implementierungen der öffentlichen Funktionen
double addiere(double a, double b) {
    return a + b;
}

double subtrahiere(double a, double b) {
    return a - b;
}

double multipliziere(double a, double b) {
    return a * b;
}

double dividiere(double a, double b) {
    if (b == 0.0) {
        printf("Fehler: Division durch 0!\n");
        return 0.0;
    }
    return a / b;
}

double kreisFlaeche(double radius) {
    return PI * radius * radius;
}
```

### 1.5.3. Verwendung in `main.c`

```c
// main.c

#include <stdio.h>
#include "rechner.h"   // Schnittstelle einbinden – keine .c einbinden!

int main(void) {
    double ergebnis = addiere(3.5, 2.1);
    printf("3.5 + 2.1 = %.2f\n", ergebnis);

    printf("Kreisfläche r=5: %.2f\n", kreisFlaeche(5.0));

    return 0;
}
```

---

## 1.6. Das Schlüsselwort `#include`

`#include` ist eine **Präprozessor-Direktive**: Vor der eigentlichen Kompilierung ersetzt der Präprozessor die `#include`-Zeile durch den vollständigen Inhalt der angegebenen Datei.

```c
#include <stdio.h>    // Spitze Klammern: sucht in Systempfaden
                      // Für Standardbibliotheken (stdio, stdlib, string, ...)

#include "rechner.h"  // Anführungszeichen: sucht zuerst im aktuellen Verzeichnis
                      // Für eigene Header-Dateien
```

> `#include` ist simples **Text-Einfügen** – der Präprozessor kennt kein C, er sucht und ersetzt nur.

---

## 1.7. Das Schlüsselwort extern

C-Variablen und -Funktionen sind standardmässig nur in der Datei sichtbar, in der sie definiert sind. Was passiert, wenn zwei Dateien dieselbe Variable gemeinsam nutzen müssen?

```c
// config.c
int debugModus = 1;   // Definition – Speicher wird hier angelegt

// ausgabe.c
// Wie greife ich auf debugModus aus config.c zu?
```

### 1.7.1. `extern` – Deklaration ohne Definition

**extern sagt dem Compiler**: „Diese Variable existiert – aber nicht hier. Suche sie anderswo."

```c
// config.c
int debugModus = 1;        // DEFINITION: Speicher wird angelegt

// config.h
extern int debugModus;     // DEKLARATION: kein Speicher, nur Ankündigung

// ausgabe.c
#include "config.h"        // bringt extern int debugModus; rein

void ausgabe(char *text) {
    if (debugModus) {
        printf("[DEBUG] %s\n", text);
    } else {
        printf("%s\n", text);
    }
}
```

### 1.7.2. `extern` für Funktionen

Funktionsprototypen sind implizit `extern` – das Schlüsselwort kann weggelassen werden, ist aber erlaubt:

```c
// explizit (selten, aber korrekt):
extern double addiere(double a, double b);

// implizit (üblich – genau dasselbe):
double addiere(double a, double b);
```

---

## 1.8. Das Schlüsselwort `static`

**static bei Variablen in Funktionen**:

Eine `static`-Variable in einer Funktion **behält ihren Wert** zwischen Aufrufen – sie wird nur einmal initialisiert.

```c
#include <stdio.h>

int zaehler(void) {
    static int count = 0;   // initialisiert nur beim ERSTEN Aufruf
    count++;
    return count;
}

int main(void) {
    printf("%d\n", zaehler());  // 1
    printf("%d\n", zaehler());  // 2
    printf("%d\n", zaehler());  // 3
    return 0;
}
```

> Nützlich wenn eine Funktion sich ihren Zustand zwischen Aufrufen merken muss, ohne eine globale Variable zu verwenden.

**static bei Funktionen und globalen Variablen – Information Hiding:**

`static` vor einer Funktion oder globalen Variable **beschränkt deren Sichtbarkeit auf die eigene Datei**. Andere `.c`-Dateien können darauf nicht zugreifen – auch nicht mit `extern`.

```c
// statistik.c

#include "statistik.h"

// PRIVATE Hilfsfunktion – nur innerhalb statistik.c sichtbar
static double berechneVarianz(double werte[], int n) {
    // interne Berechnung ...
}

// ÖFFENTLICHE Funktion – in statistik.h deklariert, von aussen nutzbar
double berechneStandardabweichung(double werte[], int n) {
    return sqrt(berechneVarianz(werte, n));  // nutzt private Hilfsfunktion
}
```

```c
// main.c
#include "statistik.h"

int main(void) {
    double werte[] = {4.0, 5.0, 6.0, 3.0, 5.0};

    // erlaubt – öffentlich deklariert in statistik.h
    double s = berechneStandardabweichung(werte, 5);

    // FEHLER – berechneVarianz ist static, nicht sichtbar ausserhalb statistik.c
    // double v = berechneVarianz(werte, 5);

    return 0;
}
```

## 1.9. Include-Guard mit `#ifndef`

**Das Problem: Mehrfacheinbindung**: Grosse Projekte haben oft komplexe Include-Strukturen

```c
main.c
  → #include "berechnung.h"
  → #include "ausgabe.h"
        → #include "berechnung.h"   ← berechnung.h wird ZWEIMAL eingebunden!
```

> Wenn `berechnung.h` zweimal eingebunden wird, werden alle Deklarationen doppelt eingefügt → Compiler-Fehler.

**Die Lösung: Include-Guard:**

```c
// berechnung.h

#ifndef BERECHNUNG_H    // "If Not Defined": falls BERECHNUNG_H noch nicht definiert
#define BERECHNUNG_H    // definiere BERECHNUNG_H (als leeres Symbol)

// ... Inhalt der Header-Datei ...
double addiere(double a, double b);
double subtrahiere(double a, double b);

#endif  // BERECHNUNG_H  ← Ende des #ifndef-Blocks
```

**Wie es funktioniert:**

1. Erster #include "berechnung.h":
   - #ifndef BERECHNUNG_H → BERECHNUNG_H ist noch nicht definiert → true
   - Inhalt wird eingefügt, BERECHNUNG_H wird definiert

2. Zweiter #include "berechnung.h" (selbe Compilation):
   - #ifndef BERECHNUNG_H → BERECHNUNG_H ist jetzt definiert → false
   - Inhalt wird ÜBERSPRUNGEN → kein Fehler

### 1.9.1. Vollständiges Beispiel

```c
// statistik.h

#ifndef STATISTIK_H
#define STATISTIK_H

// Öffentliche Konstanten
#define MAX_WERTE 100

// Öffentliche Funktionsprototypen
double berechneSchnitt(double werte[], int anzahl);
double berechneStandardabweichung(double werte[], int anzahl);
void   zeigeStatistik(double werte[], int anzahl);

// Öffentliche extern-Deklaration (falls nötig)
extern int statistikDebug;

#endif  // STATISTIK_H
```

---

## 1.10. Das vollständige Bild – Modulstruktur in der Praxis

```console
projekt/
├── main.c           → Hauptprogramm
├── statistik.h      → Schnittstelle (öffentlich)
├── statistik.c      → Implementierung (privat)
├── ausgabe.h        → Schnittstelle Ausgabe
└── ausgabe.c        → Implementierung Ausgabe
```

```c
// statistik.h
#ifndef STATISTIK_H
#define STATISTIK_H

double berechneSchnitt(double werte[], int anzahl);
double berechneStandardabweichung(double werte[], int anzahl);

#endif
```

```c
// statistik.c
#include "statistik.h"
#include <math.h>

// Private Hilfsfunktion – nicht in .h, daher static
static double berechneVarianz(double werte[], int anzahl) {
    double schnitt = berechneSchnitt(werte, anzahl);
    double summe   = 0.0;
    for (int i = 0; i < anzahl; i++) {
        double diff = werte[i] - schnitt;
        summe += diff * diff;
    }
    return summe / anzahl;
}

double berechneSchnitt(double werte[], int anzahl) {
    double summe = 0.0;
    for (int i = 0; i < anzahl; i++) summe += werte[i];
    return summe / anzahl;
}

double berechneStandardabweichung(double werte[], int anzahl) {
    return sqrt(berechneVarianz(werte, anzahl));
}
```

```c
// ausgabe.h
#ifndef AUSGABE_H
#define AUSGABE_H

void zeigeErgebnis(double schnitt, double stdabw);

#endif
```

```c
// ausgabe.c
#include "ausgabe.h"
#include <stdio.h>

void zeigeErgebnis(double schnitt, double stdabw) {
    printf("Schnitt:          %.2f\n", schnitt);
    printf("Standardabw.:     %.2f\n", stdabw);
}
```

```c
// main.c
#include <stdio.h>
#include "statistik.h"  // nur .h einbinden!
#include "ausgabe.h"

int main(void) {
    double werte[] = {4.0, 5.0, 6.0, 3.0, 5.0, 4.0, 6.0};
    int n = 7;

    double schnitt = berechneSchnitt(werte, n);
    double stdabw  = berechneStandardabweichung(werte, n);

    zeigeErgebnis(schnitt, stdabw);
    return 0;
}
```

---

## 1.11. Kompilierung

```console
gcc main.c statistik.c ausgabe.c -o statistiktool -lm

// mit start nach Kompilierung
gcc *.c -o statistiktool & ./statistiktool.exe
```

> Jede `.c`-Datei wird separat kompiliert. Der Linker fügt die Teile am Ende zusammen.

### 1.11.1. Beispiel Visual Studio Code (tasks.json)

```json
{
    "tasks": [
        {
            "type": "cppbuild",
            "label": "C/C++: gcc Aktive Datei kompilieren",
            "command": "/usr/bin/gcc",
            "args": [
                "-fdiagnostics-color=always",
                "-g",
                "${fileDirname}/*.c",
                "${fileDirname}/*.h",
                "-o",
                "${fileDirname}/${fileBasenameNoExtension}"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "detail": "Vom Debugger generierte Aufgabe."
        }
    ],
    "version": "2.0.0"
}
```

---

## 1.12. Die goldene Regel der Modularisierung

> Zeige so wenig wie nötig, verberge so viel wie möglich.
> Was in der .h-Datei steht, ist öffentlicher Vertrag.
> Was nur in der .c-Datei steht oder `static` ist, bleibt privates Implementierungsdetail.

---

</br>

# 2. Aufgaben

## 2.1. Separates Module für Trennstrich-Funktionen

| **Vorgabe**         | **Beschreibung**                                                        |
| :------------------ | :---------------------------------------------------------------------- |
| **Lernziele**       | Kennt die Möglichkeiten zur Modularisierung und Strukturierung von Code |
|                     | Kann Funktionen in separate Dateien auslagern                           |
|                     | Kann Funktionen korrekt aufrufen                                        |
| **Sozialform**      | Einzelarbeit                                                            |
| **Auftrag**         | siehe unten                                                             |
| **Hilfsmittel**     |                                                                         |
| **Zeitbedarf**      | 30min                                                                   |
| **Lösungselemente** | Funktionierendes Programm                                               |

Lagere die beiden Trennstrich-Funktionen (siehe Aufgaben Kapitel Funktionen) in einem separates Modul aus z.B. `func.c`.
Erstelle für die beiden Funktionen ein Headerdatei z.B. `func.h`
Rufe die die beiden Funktionen im `main` Programm auf.

---

© 2026 Lukas Müller – Licensed under CC BY-NC-ND 4.0
See [LICENSE](../license.md) file for details.
