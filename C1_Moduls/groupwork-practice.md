|                             |                          |                               |
| --------------------------- | ------------------------ | ----------------------------- |
| **Elektrotechniker/-in HF** | **Programmiertechnik B** | ![logo](../x_gitres/logo.png) |

- [1. Gruppenarbeit Moduls](#1-gruppenarbeit-moduls)
  - [1.1. Ziel der Gruppenarbeit](#11-ziel-der-gruppenarbeit)
  - [1.2. Gruppenarbeit A – «Monolithisches Programm zerlegen»](#12-gruppenarbeit-a--monolithisches-programm-zerlegen)
  - [1.3. Gruppenarbeit B – «Kontaktlisten-Modul»](#13-gruppenarbeit-b--kontaktlisten-modul)
  - [1.4. Gruppenarbeit C – «Konfigurations- und Logging-System»](#14-gruppenarbeit-c--konfigurations--und-logging-system)
  - [1.5. Gruppenarbeit D – «Mehrdatei-Projekt von Grund auf»](#15-gruppenarbeit-d--mehrdatei-projekt-von-grund-auf)

---

</br>

# 1. Gruppenarbeit Moduls

| **Vorgabe**         | **Beschreibung**                                                        |
| :------------------ | :---------------------------------------------------------------------- |
| **Lernziele**       | Kennt die Möglichkeiten zur Modularisierung und Strukturierung von Code |
|                     | Kann Funktionen mit und ohne Parameter implementieren                   |
|                     | Kann Funktionen korrekt aufrufen                                        |
| **Sozialform**      | Gruppenarbeit: 2-3 Personen                                             |
| **Auftrag**         | siehe unten                                                             |
| **Hilfsmittel**     |                                                                         |
| **Zeitbedarf**      | 60min                                                                   |
| **Lösungselemente** | Abgabe: Alle Dateien (.h und .c) als Gesamtprojekt                      |
|                     | Funktionierendes Programm und Präsentation (Code erklären), ca. 5 min.  |
|                     | Jedes Gruppenmitglied muss Teile des Codes erklären können              |

> Hinweis zum KI-Einsatz
> Ihr dürft KI-Tools verwenden – aber: Ihr werdet den Code in der Präsentation erklären müssen.
>
> Bei diesen Aufgaben geht es nicht nur darum, dass das Programm läuft – sondern darum, dass ihr die Struktur versteht und begründen könnt.
> In der Präsentation wird jedes Mitglied einzeln gefragt:
>
> - „Warum steht diese Funktion im .h und nicht nur im .c?"
> - „Was passiert, wenn du den Include-Guard weglässt?"
> - „Zeig mir alle Stellen, wo static vorkommt – warum jeweils?"
> - „Welche Datei müsste ich öffnen, um die Berechnungslogik zu ändern?"
> - „Was ändert sich in main.c, wenn ihr die interne Implementierung tauscht?"
>
> Das bedeutet:
>
> - Jede Zeile, die ihr abgebt, müsst ihr verstehen und erklären können
> - Empfehlung: Nutzt KI als Lernhilfe, nicht als Schreibmaschine. Schreibt Teile selbst, lasst andere erklären, diskutiert als Gruppe.
> - Eine Lösung, bei der die Gruppe die Strukturentscheidungen nicht erklären kann, gilt als nicht bestanden – unabhängig davon, ob der Code läuft.

## 1.1. Ziel der Gruppenarbeit

Die Lernenden sollen verstehen, wie Modularisierung mit Header- und Quellcode Dateien in einem grösseren Projekt umgesetzt werden kann.

## 1.2. Gruppenarbeit A – «Monolithisches Programm zerlegen»

**Szenario:**

Das folgende Programm wurde von einem Studenten in einer einzigen Datei geschrieben. Es funktioniert – aber es verletzt alle Prinzipien des modularen Designs.
Eure Aufgabe: das Programm in eine saubere Modulstruktur überführen.

Ausgangscode (`alles_in_einem.c`)

```c
#include <stdio.h>
#include <math.h>
#include <string.h>

// ---- Geometrie ----

double kreisFlaeche(double r) {
    return 3.14159265 * r * r;
}

double kreisUmfang(double r) {
    return 2.0 * 3.14159265 * r;
}

double rechteckFlaeche(double b, double h) {
    return b * h;
}

double rechteckUmfang(double b, double h) {
    return 2.0 * (b + h);
}

double dreieckFlaeche(double b, double h) {
    return 0.5 * b * h;
}

// ---- Statistik ----

double berechneSchnitt(double werte[], int n) {
    double summe = 0.0;
    for (int i = 0; i < n; i++) summe += werte[i];
    return summe / n;
}

static double berechneVarianz(double werte[], int n) {
    double schnitt = berechneSchnitt(werte, n);
    double summe   = 0.0;
    for (int i = 0; i < n; i++) {
        double d = werte[i] - schnitt;
        summe += d * d;
    }
    return summe / n;
}

double berechneStdAbw(double werte[], int n) {
    return sqrt(berechneVarianz(werte, n));
}

double berechneMax(double werte[], int n) {
    double max = werte[0];
    for (int i = 1; i < n; i++)
        if (werte[i] > max) max = werte[i];
    return max;
}

double berechneMin(double werte[], int n) {
    double min = werte[0];
    for (int i = 1; i < n; i++)
        if (werte[i] < min) min = werte[i];
    return min;
}

// ---- Ausgabe ----

int ausgabeAktiv = 1;   // globale Variable

void druckeErgebnis(char *label, double wert) {
    if (ausgabeAktiv) {
        printf("%-20s: %8.4f\n", label, wert);
    }
}

void druckeTrennlinie(void) {
    if (ausgabeAktiv) {
        printf("----------------------------\n");
    }
}

void druckeÜberschrift(char *titel) {
    if (ausgabeAktiv) {
        printf("\n==== %s ====\n", titel);
    }
}

// ---- Hauptprogramm ----

int main(void) {
    // Geometrie testen
    druckeÜberschrift("Geometrie");
    druckeErgebnis("Kreis r=5 Fläche",   kreisFlaeche(5.0));
    druckeErgebnis("Kreis r=5 Umfang",   kreisUmfang(5.0));
    druckeErgebnis("Rechteck 4x6 Fl.",   rechteckFlaeche(4.0, 6.0));
    druckeErgebnis("Dreieck b=3 h=8 Fl.",dreieckFlaeche(3.0, 8.0));
    druckeTrennlinie();

    // Statistik testen
    double messwerte[] = {4.5, 6.2, 3.8, 7.1, 5.0, 4.9, 6.8, 5.5};
    int n = 8;

    druckeÜberschrift("Statistik");
    druckeErgebnis("Schnitt",        berechneSchnitt(messwerte, n));
    druckeErgebnis("Standardabw.",   berechneStdAbw(messwerte, n));
    druckeErgebnis("Maximum",        berechneMax(messwerte, n));
    druckeErgebnis("Minimum",        berechneMin(messwerte, n));
    druckeTrennlinie();

    return 0;
}
```

**Aufgabenstellung:**

**Schritt 1 – Analyse (10 min): Diskutiert als Gruppe:**

- Welche logischen Module erkennt ihr?
- Welche Funktionen sind öffentlich (ins .h), welche privat (nur .c)?
- Wo gehört ausgabeAktiv hin? Wie wird sie korrekt mit extern geteilt?
- Was macht static bei berechneVarianz – und bleibt das so?

**Schritt 2 – Struktur festlegen:**

- Einigt euch auf folgende Dateistruktur und erstellt alle Dateien:

```console
projekt_a/
├── main.c
├── geometrie.h
├── geometrie.c
├── statistik.h
├── statistik.c
├── ausgabe.h
└── ausgabe.c
```

**Schritt 3 – Umsetzung:**

- Jede `.h`-Datei mit korrektem Include-Guard (`#ifndef`)
- `ausgabeAktiv` korrekt mit extern deklarieren
- `berechneVarianz` bleibt `static` (privat in `statistik.c`)
- `PI` als `#define` in `geometrie.h`
- Alle nötigen `#include`-Abhängigkeiten setzen

Schritt 4 – Kompilieren und testen:

```console
gcc main.c geometrie.c statistik.c ausgabe.c -o programm_a -lm
```

**Pflichtanforderungen:**

- [ ] Module mit je `.h` und `.c` erstellt
- [ ] Alle Include-Guards korrekt (`#ifndef` / `#define` /`#endif`)
- [ ] `ausgabeAktiv`: Definition in `ausgabe.c`, `extern`-Deklaration in `ausgabe.h`
- [ ] `berechneVarianz` ist `static` in `statistik.c` und nicht in `statistik.h`
- [ ] `PI` als `#define` in `geometrie.h`
- [ ] Programm kompiliert ohne Warnungen und läuft korrekt

**Präsentationsfragen:**

1. Zeig `statistik.h` und `statistik.c` nebeneinander – was steht wo und warum?
2. `berechneVarianz` ist `static` – was würde passieren, wenn man sie in `main.c` aufrufen wollte?
3. Erkläre `extern int ausgabeAktiv` – wo ist die Definition, wo die Deklaration?
4. Öffne `geometrie.h` – was passiert beim zweiten `#include "geometrie.h"`? Zeig den Guard-Mechanismus.
5. Wenn jemand die Formel für `kreisFlaeche` verbessern will – welche Datei öffnet er? Was ändert sich in `main.c`?

---

</br>

## 1.3. Gruppenarbeit B – «Kontaktlisten-Modul»

**Szenario:**

- Ihr entwickelt ein Modul zur Verwaltung einer einfachen Kontaktliste.
- Das Besondere: `main.c` darf **nicht wissen**, wie die Kontakte intern gespeichert sind.
- Die interne Datenstruktur ist ein Implementierungsdetail – verborgen in `kontakte.c`.

**Projektstruktur:**

```console
projekt_b/
├── main.c
├── kontakte.h     ← nur Prototypen, keine struct-Details
└── kontakte.c     ← struct und interne Logik
```

**Zu implementieren:**

`kontakte.h` – die öffentliche Schnittstelle:

```c
#ifndef KONTAKTE_H
#define KONTAKTE_H

#define MAX_KONTAKTE 50
#define MAX_NAME     50
#define MAX_TEL      20

// Maximale Anzahl öffentlich bekannt – aber NICHT die interne Struktur
int  kontaktHinzufuegen(char *name, char *telefon, int alter);
void kontakteListen(void);
int  kontaktSuchen(char *name);        // gibt Index zurück, -1 = nicht gefunden
void kontaktLoeschen(int index);
int  kontaktAnzahl(void);
void kontakteSortiert(void);           // alphabetisch nach Name ausgeben

#endif
```

**`kontakte.c` – die private Implementierung:**

Die interne Datenstruktur (`struct`) wird nur in `kontakte.c` definiert – nicht in der Header-Datei:

```c
// kontakte.c
#include "kontakte.h"
#include <stdio.h>
#include <string.h>

// Private Datenstruktur – nur in dieser Datei sichtbar
typedef struct {
    char name[MAX_NAME];
    char telefon[MAX_TEL];
    int  alter;
} Kontakt;

// Private globale Variable – static, nicht von aussen zugänglich
static Kontakt liste[MAX_KONTAKTE];
static int     anzahl = 0;

// Private Hilfsfunktion – static
static int istGueltig(int index) {
    return (index >= 0 && index < anzahl);
}

// ... Implementierungen der öffentlichen Funktionen
```

**`main.c` – verwendet nur die Schnittstelle:**

```c
#include <stdio.h>
#include "kontakte.h"

int main(void) {
    kontaktHinzufuegen("Müller Anna",   "079 123 45 67", 28);
    kontaktHinzufuegen("Berger Klaus",  "044 987 65 43", 42);
    kontaktHinzufuegen("Schmid Sophie", "078 555 12 34", 35);
    kontaktHinzufuegen("Bauer Tobias",  "076 222 33 44", 24);
    kontaktHinzufuegen("Fischer Lena",  "079 888 77 66", 31);

    printf("=== Alle Kontakte ===\n");
    kontakteListen();

    printf("\n=== Alphabetisch sortiert ===\n");
    kontakteSortiert();

    int idx = kontaktSuchen("Berger Klaus");
    if (idx >= 0) {
        printf("\nKontakt gefunden an Position %d\n", idx);
        kontaktLoeschen(idx);
        printf("Kontakt gelöscht. Noch %d Kontakte.\n", kontaktAnzahl());
    }

    return 0;
}
```

**Erwartete Ausgabe:**

```console
=== Alle Kontakte ===
[0] Müller Anna      | 079 123 45 67 | 28 Jahre
[1] Berger Klaus     | 044 987 65 43 | 42 Jahre
[2] Schmid Sophie    | 078 555 12 34 | 35 Jahre
[3] Bauer Tobias     | 076 222 33 44 | 24 Jahre
[4] Fischer Lena     | 079 888 77 66 | 31 Jahre

=== Alphabetisch sortiert ===
[0] Bauer Tobias     | 076 222 33 44 | 24 Jahre
[1] Berger Klaus     | 044 987 65 43 | 42 Jahre
[2] Fischer Lena     | 079 888 77 66 | 31 Jahre
[3] Müller Anna      | 079 123 45 67 | 28 Jahre
[4] Schmid Sophie    | 078 555 12 34 | 35 Jahre

Kontakt gefunden an Position 1
Kontakt gelöscht. Noch 4 Kontakte.
```

**Pflichtanforderungen:**

- [ ] `struct Kontakt` ist nur in `kontakte.c` definiert – nicht in `kontakte.h`
- [ ] `liste` und `anzahl` sind `static` in `kontakte.c`
- [ ] `istGueltig` ist `static` (private Hilfsfunktion)
- [ ] `kontakteSortiert` verwendet Bubble Sort mit `strcmp` (kein qsort)
- [ ] Include-Guard in `kontakte.h`
- [ ] `main.c` enthält keinerlei Strukturdetails der Kontakte

**Präsentationsfragen:**

1. Die `struct Kontakt` steht in`kontakte.c`, nicht in `kontakte.h` – was bedeutet das für main.c? Kann `main.c` auf kontakt.name zugreifen?
2. Warum sind `liste` und `anzahl` `static`? Was würde passieren, wenn sie es nicht wären?
3. Erkläre den Bubble-Sort in `kontakteSortiert` – wie vergleichst du Strings?
4. Stell dir vor, ihr wollt intern statt einem Array eine andere Datenstruktur verwenden. Welche Dateien müsst ihr ändern? Welche bleibt unverändert?
5. Öffne `kontakte.h` und erkläre den Include-Guard Zeile für Zeile.

---

</br>

## 1.4. Gruppenarbeit C – «Konfigurations- und Logging-System»

**Szenario:**

Viele Programme brauchen zwei Querschnittsmodule, die von überall genutzt werden:

- ein **Konfigurationsmodul** (globale Einstellungen) und ein **Logging-Modu**l (Protokollierung).
- Ihr baut beide Module – und lernt dabei, wie extern-Variablen über mehrere Module hinweg funktionieren.

**Projektstruktur:**

```console
projekt_c/
├── main.c
├── config.h
├── config.c
├── logger.h
├── logger.c
├── rechner.h
└── rechner.c
```

**Schnittstellenvorgaben:**

```c
// config.h
#ifndef CONFIG_H
#define CONFIG_H

// Öffentlich zugängliche Konfigurationswerte
extern int   cfg_debugModus;      // 0 = aus, 1 = ein
extern int   cfg_dezimalStellen;  // Nachkommastellen für Ausgabe
extern char  cfg_programmName[];  // Programmname

void configLaden(int debug, int dezimal, char *name);
void configAusgeben(void);

#endif


// logger.h
#ifndef LOGGER_H
#define LOGGER_H

// Log-Level Konstanten
#define LOG_INFO    0
#define LOG_WARNING 1
#define LOG_ERROR   2

void logSchreiben(int level, char *nachricht);
void logAnzahlAusgeben(void);

// Nur sichtbar wenn debug aktiv – intern entscheidet logger.c
void logDebug(char *nachricht);

#endif


// rechner.h
#ifndef RECHNER_H
#define RECHNER_H

double rechnerAddiere(double a, double b);
double rechnerSubtrahiere(double a, double b);
double rechnerMultipliziere(double a, double b);
double rechnerDividiere(double a, double b);

#endif
```

**Implementierungshinweise:**

`config.c` definiert die extern-Variablen (Speicher wird hier angelegt):

```c
int  cfg_debugModus     = 0;
int  cfg_dezimalStellen = 2;
char cfg_programmName[] = "MeinProgramm";
```

`logger.c` nutzt cfg_debugModus aus `config.h`und zählt intern mit `static`:

```c
#include "config.h"   // für cfg_debugModus
static int logAnzahl[3] = {0, 0, 0};  // Zähler pro Level – privat
```

`rechner.c` ruft für jede Operation `logSchreiben` und `logDebug` auf:

```c
// Beispiel:
double rechnerDividiere(double a, double b) {
    if (b == 0.0) {
        logSchreiben(LOG_ERROR, "Division durch 0 versucht!");
        return 0.0;
    }
    logDebug("Division erfolgreich");
    return a / b;
}
```

`main.c` setzt Konfiguration, führt Berechnungen durch, zeigt Logs:

```c
configLaden(1, 3, "Rechner-Demo");  // debug=1, 3 Dezimalstellen
// ... Berechnungen ...
logAnzahlAusgeben();
```

**Erwartete Ausgabe:**

```console
[CONFIG] Programm: Rechner-Demo | Debug: EIN | Dezimal: 3
[INFO]    Rechner-Demo gestartet
[DEBUG]   Addition erfolgreich
[DEBUG]   Subtraktion erfolgreich
[DEBUG]   Multiplikation erfolgreich
[ERROR]   Division durch 0 versucht!
[DEBUG]   Division erfolgreich

Ergebnisse:
  10.000 + 3.000 = 13.000
  10.000 - 3.000 =  7.000
  10.000 * 3.000 = 30.000
  10.000 / 0.000 =  0.000  (Fehler)
  10.000 / 3.000 =  3.333

Log-Statistik:
  INFO:    1 Meldungen
  WARNING: 0 Meldungen
  ERROR:   1 Meldungen
```

**Pflichtanforderungen:**

- [ ] `cfg_*`-Variablen: `extern`-Deklaration in `config.h`, Definition in `config.c`
- [ ] `logAnzahl` ist `static` in `logger.c` (privat)
- [ ] `logDebug` gibt nur aus, wenn `cfg_debugModus == 1`
- [ ] `rechner.c` inkludiert `logger.h` (nicht `logger.c`!)
- [ ] Include-Guards in allen `.h`-Dateien
- [ ] Jede `.c`-Datei inkludiert nur was sie wirklich braucht

**Präsentationsfragen:**

1. Erkläre den Unterschied zwischen `extern int cfg_debugModus` in `config.h` und int `cfg_debugModus = 0` in `config.c`.
2. `logAnzahl` ist `static` – könnte `rechner.c` darauf zugreifen? Warum nicht?
3. Welche `#include`-Zeilen stehen in `rechner.c`? Warum nur diese?
4. Was passiert, wenn `cfg_debugModus = 0` gesetzt ist? Welche Ausgaben verschwinden?
5. Was würde passieren, wenn `config.h` den Include-Guard nicht hätte und von sowohl **logger.c** als auch `rechner.c` eingebunden wird?

---

</br>

## 1.5. Gruppenarbeit D – «Mehrdatei-Projekt von Grund auf»

**Szenario:**

- Diese Aufgabe hat keinen Startcode. Ihr entwerft und implementiert ein vollständiges modulares C-Projekt von Grund auf.
- Das Thema: ein einfaches Lagerverwaltungssystem für ein kleines Lager mit Artikeln.

**Anforderungen an das System:**

- Das System verwaltet Artikel mit: Name, Artikelnummer, Lagerbestand, Preis.

**Pflichtfunktionalität:**

| **Funktion**                                | **Modul** |
| ------------------------------------------- | --------- |
| Artikel erfassen (Name, Nr, Bestand, Preis) | lager     |
| Bestand erhöhen / verringern                | lager     |
| Alle Artikel anzeigen                       | lager     |
| Artikel nach Name suchen                    | lager     |
| Gesamtlagerwert berechnen                   | lager     |
| Artikel unter Mindestbestand anzeigen       | lager     |
| Formatierte Ausgabe / Tabellenkopf          | ausgabe   |
| Fehlermeldungen ausgeben                    | ausgabe   |
| Trennlinien / Überschriften                 | ausgabe   |

**Vorgegebene Projektstruktur:**

```console
projekt_d/
├── main.c           ← nur Ablaufsteuerung, kein Business-Logic
├── lager.h          ← öffentliche Schnittstelle Lagerverwaltung
├── lager.c          ← Implementierung (struct intern!)
├── ausgabe.h        ← öffentliche Schnittstelle Ausgabe
└── ausgabe.c        ← Implementierung Ausgabe
```

**Designvorgaben (müssen eingehalten werden):**

```c
// lager.h – Vorgabe Schnittstelle (mindestens):
int  lagerArtikelHinzufuegen(char *name, int nummer, int bestand, double preis);
void lagerBestandErhoehen(int nummer, int menge);
int  lagerBestandVerringern(int nummer, int menge);  // 0=ok, -1=nicht genug Bestand
void lagerAlleAnzeigen(void);
int  lagerSuchen(char *name);         // gibt Artikelnummer zurück, -1=nicht gefunden
double lagerGesamtwert(void);
void lagerMindestbestandAnzeigen(int mindestbestand);
```

```c
// ausgabe.h – Vorgabe Schnittstelle (mindestens):
void ausgabeFehler(char *meldung);
void ausgabeTrennlinie(void);
void ausgabeUeberschrift(char *titel);
void ausgabeArtikelzeile(int nr, char *name, int bestand, double preis);
```

**Designentscheidungen – Gruppe muss begründen können:**

Folgende Entscheidungen trefft ihr selbst – ihr müsst sie in der Präsentation begründen:

1. Wo definiert ihr die struct für einen Artikel? Nur .c oder auch .h?
2. Wie ist das interne Array static deklariert? Warum?
3. Welche Hilfsfunktionen sind static? (z.B. eine findeIndex-Funktion)
4. Welche #include-Abhängigkeiten hat lager.c? Braucht es ausgabe.h?
5. Wie verhindern die Include-Guards konkret eine Mehrfachdeklaration?

**Erwartete Ausgabe (Beispiel):**

```console
========================================
     LAGERVERWALTUNG – Übersicht
========================================
| Nr.  | Artikel               | Bestand | Preis CHF |
| ---- | --------------------- | ------- | --------- |
| 1001 | Schrauben M6x20       | 500     | 0.05      |
| 1002 | Muttern M6            | 320     | 0.03      |
| 1003 | Unterlegscheiben M6   | 15      | 0.02      |
| 1004 | Bohrer 5mm HSS        | 48      | 4.90      |
| 1005 | Winkelschleifer 125mm | 3       | 89.00     |
----------------------------------------
Gesamtlagerwert: CHF 332.45

Artikel unter Mindestbestand (< 20):
  [!] Unterlegscheiben M6  – nur noch 15 Stück
  [!] Winkelschleifer 125mm – nur noch 3 Stück
```

**Pflichtanforderungen:**

- [ ] `struct Artikel` ist `static` / nur in `lager.c` – nicht in `lager.h`
- [ ] Internes Array und Zähler sind `static` in `lager.c`
- [ ] Interne Suchfunktion (z.B. `findeIndex`) ist `static`
- [ ] Alle `.h`-Dateien haben Include-Guards
- [ ] `main.c` enthält keine Berechnungslogik (nur Aufrufe)
- [ ] `ausgabe.c` enthält keine Lagerlogik

**Präsentationsfragen:**

1. Zeig `lager.h` – welche Design-Entscheidungen habt ihr getroffen? Was steht drin, was nicht?
2. Warum ist die interne Suchfunktion `static`? Demonstriere, dass main.c sie nicht aufrufen kann.
3. Erkläre den Include-Guard in einer eurer Header-Dateien Zeile für Zeile.
4. `main.c` importiert `lager.h` – aber nie `lager.c`. Wie weiss der Linker trotzdem, wo `lagerAlleAnzeigen` implementiert ist?
5. Was ist der Unterschied zwischen `#include <stdio.h>` und `#include "lager.h"`? Wo liegt der Unterschied beim Suchen?

---

© 2026 Lukas Müller – Licensed under CC BY-NC-ND 4.0
See [LICENSE](..\license.md) file for details.
