|                             |                          |                               |
| --------------------------- | ------------------------ | ----------------------------- |
| **Elektrotechniker/-in HF** | **Programmiertechnik B** | ![logo](../x_gitres/logo.png) |

- [1. Gruppenarbeit Array's](#1-gruppenarbeit-arrays)
  - [1.1. Gruppenarbeit A – «Wetterstation»](#11-gruppenarbeit-a--wetterstation)
  - [1.2. Gruppenarbeit B – «Matrixrechner»](#12-gruppenarbeit-b--matrixrechner)
  - [1.3. Gruppenarbeit C – «Stundenplan-Verwaltung»](#13-gruppenarbeit-c--stundenplan-verwaltung)
  - [1.4. Gruppenarbeit D – «Schüler-Notenverwaltung»](#14-gruppenarbeit-d--schüler-notenverwaltung)

---

</br>

# 1. Gruppenarbeit Array's

| **Vorgabe**         | **Beschreibung**                                                                                 |
| :------------------ | :----------------------------------------------------------------------------------------------- |
| **Lernziele**       | Sinn und Zweck von Arrays erklären und gegenüber Einzelvariablen abgrenzen                       |
|                     | Eindimensionale Arrays deklarieren, initialisieren und auf Elemente zugreifen                    |
|                     | Zweidimensionale Arrays (Matrizen) deklarieren und mit verschachtelten Schleifen verarbeiten     |
|                     | Arrays als Funktionsparameter korrekt übergeben und deren Verhalten (immer als Pointer) erklären |
|                     | Typische Array-Muster (Suchen, Min/Max, Umkehren) implementieren                                 |
| **Sozialform**      | Gruppenarbeit: 2-3 Personen                                                                      |
| **Auftrag**         | siehe unten                                                                                      |
| **Hilfsmittel**     |                                                                                                  |
| **Zeitbedarf**      | 60min                                                                                            |
| **Lösungselemente** | Funktionierendes Programm und Präsentation (Code erklären), ca. 5 min.                           |
|                     | Jedes Gruppenmitglied muss Teile des Codes erklären können                                       |

> Hinweis zum KI-Einsatz
> Ihr dürft KI-Tools verwenden – aber: Ihr werdet den Code in der Präsentation erklären müssen.
> Das bedeutet:
>
> - Jede Zeile, die ihr abgebt, müsst ihr verstehen und erklären können
> - Ihr werdet gefragt: „Was passiert hier genau?", „Warum habt ihr das so gelöst?", „Was gibt diese Funktion zurück?"
> - Eine Lösung, die ihr nicht erklären könnt, gilt als nicht bestanden
> - Empfehlung: Nutzt KI als Lernhilfe, nicht als Schreibmaschine. Schreibt Teile selbst, lasst andere erklären, diskutiert als Gruppe.

## 1.1. Gruppenarbeit A – «Wetterstation»

**Szenario:**

- Eine Wetterstation erfasst stündlich die Temperatur über 24 Stunden sowie über 7 Tage.
- Ihr entwickelt die Auswertungsfunktionen.

**Anforderungen:**

```c
#define STUNDEN 24
#define TAGE     7

// Testdaten (in main() definieren):
double tagTemperaturen[STUNDEN] = {
    12.1, 11.8, 11.3, 10.9, 10.5, 10.8, 12.0, 14.3,
    16.7, 18.2, 19.5, 21.0, 22.3, 23.1, 23.4, 23.0,
    22.1, 20.8, 19.2, 17.6, 16.3, 15.1, 14.0, 13.2
};

double wocheTemperaturen[TAGE][STUNDEN] = {
    {12.1,11.8,11.3,10.9,10.5,10.8,12.0,14.3,16.7,18.2,19.5,21.0,22.3,23.1,23.4,23.0,22.1,20.8,19.2,17.6,16.3,15.1,14.0,13.2},
    {10.0,9.5, 9.1, 8.8, 8.5, 9.0,10.5,12.8,15.1,17.0,18.4,19.9,21.0,21.8,22.0,21.5,20.3,18.9,17.4,15.9,14.5,13.2,12.0,11.1},
    {15.3,14.8,14.2,13.9,13.5,14.0,15.5,17.2,19.0,20.5,21.8,23.2,24.5,25.1,25.3,24.8,23.6,22.0,20.5,18.8,17.4,16.2,15.5,15.0},
    { 8.2, 7.8, 7.3, 6.9, 6.5, 7.0, 8.5,10.3,12.7,14.5,16.0,17.4,18.5,19.2,19.5,19.0,18.0,16.5,15.0,13.4,12.0,10.8, 9.7, 9.0},
    {18.5,17.9,17.3,16.8,16.4,16.9,18.2,20.1,22.3,24.0,25.4,26.8,27.9,28.5,28.7,28.2,27.0,25.5,23.8,22.0,20.5,19.3,18.8,18.3},
    {20.1,19.5,18.9,18.5,18.1,18.6,19.9,21.8,24.0,25.8,27.1,28.5,29.6,30.2,30.5,30.0,28.8,27.2,25.6,23.8,22.3,21.1,20.6,20.1},
    {14.0,13.4,12.9,12.5,12.1,12.6,14.0,15.9,18.1,19.9,21.3,22.7,23.8,24.5,24.7,24.2,23.0,21.4,19.8,18.0,16.5,15.3,14.7,14.2}
};
```

**Zu implementierende Funktionen:**

```c
// Tagesauswertung
double berechneTagesdurchschnitt(double temps[], int anzahl);
void   berechneTagMinMax(double temps[], int anzahl, double *min, double *max);
int    findeWaermstesStunde(double temps[], int anzahl);  // gibt Stundenindex zurück

// Wochenauswertung (2D-Array)
double berechneTagesschnittFuerTag(double woche[][STUNDEN], int tag);
void   zeigeWochenübersicht(double woche[][STUNDEN]);
int    waermsterTag(double woche[][STUNDEN]);             // gibt Tagesindex zurück
```

**Erwartete Ausgabe zeigeWochenübersicht:**

```c
Wochenübersicht:
Tag 1: Ø 16.8°C  | Min: 10.5°C | Max: 23.4°C
Tag 2: Ø 14.9°C  | Min:  8.5°C | Max: 22.0°C
...
Wärmster Tag: Tag 6 (Ø 25.0°C)
```

**Pflichtanforderungen:**

- [ ] `berechneTagMinMax` nutzt Call by Pointer
- [ ] `findeWaermstesStunde` gibt Index zurück (nicht den Wert)
- [ ] `zeigeWochenübersicht` ruft andere Funktionen auf (keine Duplizierung)
- [ ] `#define` für Arraygrössen verwendet

**Präsentationsfragen:**

1. Erkläre `double woche[][STUNDEN]` als Parameter – warum muss `STUNDEN` angegeben werden?
2. Zeig `findeWaermstesStunde` – wie startest du den Vergleich, und warum mit `temps[0]` als Startwert?
3. Was gibt `waermsterTag` zurück – den Temperaturwert oder den Index? Warum macht das Sinn?
4. Was würde passieren, wenn man `temps[24]` aufruft (Index 24 bei 24 Elementen)?

---

</br>

## 1.2. Gruppenarbeit B – «Matrixrechner»

**Szenario:**

- In der Ingenieurmathematik werden Matrizen ständig benötigt.
- Ihr schreibt eine kleine Matrix-Bibliothek für 3×3-Matrizen.

**Anforderungen:**

```c
#define N 3   // 3x3 Matrix

// Testdaten:
int A[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
int B[N][N] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
```

**Zu implementierende Funktionen:**

```c
// Gibt eine Matrix formatiert aus
void zeigeMatrix(int m[N][N], char *name);

// Addiert zwei Matrizen → Ergebnis in Zielmatrix speichern
void addiere(int a[N][N], int b[N][N], int ziel[N][N]);

// Multipliziert zwei Matrizen → Ergebnis in Zielmatrix
void multipliziere(int a[N][N], int b[N][N], int ziel[N][N]);

// Transponiert eine Matrix (Zeilen ↔ Spalten) → in Zielmatrix
void transponiere(int quelle[N][N], int ziel[N][N]);

// Berechnet die Summe der Hauptdiagonale
int spurBerechnen(int m[N][N]);   // Spur = m[0][0] + m[1][1] + m[2][2]
```

**Matrizenmultiplikation:**

`C[i][j] = Summe von A[i][k] * B[k][j]  für k = 0..N-1`

**Erwartete Ausgabe:**

```console
Matrix A:
   1   2   3
   4   5   6
   7   8   9

Matrix B:
   9   8   7
   6   5   4
   3   2   1

A + B:
  10  10  10
  10  10  10
  10  10  10

A * B:
  30  24  18
  84  69  54
 138 114  90

Transponierte von A:
   1   4   7
   2   5   8
   3   6   9

Spur von A: 15
```

**Pflichtanforderungen:**

- [ ] `addiere` und `multipliziere` schreiben in eine separate Zielmatrix (A und B unverändert)
- [ ] `transponiere` schreibt in `ziel`, nicht in `quelle` (warum wäre in-place problematisch?)
- [ ] Drei verschachtelte Schleifen für Matrizenmultiplikation
- [ ] `zeigeMatrix` akzeptiert `char *name` und druckt diesen als Überschrift

**Präsentationsfragen:**

1. Erkläre die drei verschachtelten Schleifen in `multipliziere` – was machen`i, j, k` jeweils?
2. Warum kann `transponiere` nicht direkt in die Originalmatrix schreiben? Demonstriere das Problem.
3. Was ist die Spur einer Matrix? Zeig die Schleife in `spurBerechnen`.
4. Was müsstest du ändern, wenn du auf 4×4-Matrizen wechseln willst?

---

</br>

## 1.3. Gruppenarbeit C – «Stundenplan-Verwaltung»

**Szenario:**

- Eine Schule braucht ein kleines Tool zur Stundenplanverwaltung.
- Der Stundenplan ist als 2D-Array von Strings (char-Pointer) gespeichert.

**Anforderungen:**

```c
#define TAGE     5   // Mo–Fr
#define LEKTIONEN 8  // 8 Lektionen pro Tag

char *stundenplan[TAGE][LEKTIONEN] = {
    {"Mathe",    "Mathe",    "Deutsch",  "Deutsch", "Physik",  "Sport",   "---", "---"},
    {"Englisch", "Englisch", "Chemie",   "Mathe",   "---",     "Deutsch", "---", "---"},
    {"Physik",   "Physik",   "Mathe",    "Englisch", "Chemie", "Chemie",  "---", "---"},
    {"Deutsch",  "Sport",    "Sport",    "Physik",  "Mathe",   "---",     "---", "---"},
    {"Chemie",   "Mathe",    "Englisch", "Englisch","Deutsch", "Physik",  "---", "---"}
};

char *tagnamen[] = {"Montag", "Dienstag", "Mittwoch", "Donnerstag", "Freitag"};
```

**Zu implementierende Funktionen:**

```c
// Gibt einen kompletten Tag aus (alle Lektionen)
void zeigeTagesplan(char *plan[TAGE][LEKTIONEN], char *tage[], int tag);

// Gibt den gesamten Stundenplan als Tabelle aus
void zeigeWochenplan(char *plan[TAGE][LEKTIONEN], char *tage[]);

// Zählt wie oft ein Fach in der Woche vorkommt
int zaehleFach(char *plan[TAGE][LEKTIONEN], char *fach);

// Findet auf welchem Tag ein Fach das erste Mal vorkommt
// Rückgabe: Tagesindex (0=Montag) oder -1 wenn nicht gefunden
int findeFachErsterTag(char *plan[TAGE][LEKTIONEN], char *fach);

// Gibt alle Tage aus, an denen ein Fach vorkommt
void zeigeFachtage(char *plan[TAGE][LEKTIONEN], char *tage[], char *fach);
```

**Erwartete Ausgabe zeigeWochenplan:**

```console
            L1        L2        L3        L4        L5        L6
Montag   | Mathe   | Mathe   | Deutsch | Deutsch | Physik  | Sport
Dienstag | Englisch| Englisch| Chemie  | Mathe   | ---     | Deutsch
...

Mathe kommt 8x pro Woche vor.
Mathe ist erstmals am Montag.
```

> **Hinweis: Zum Vergleich von Strings strcmp() aus <string.h> verwenden:**
>
> ```c
> if (strcmp(plan[t][l], fach) == 0) {  // gleich = 0
>     // Fach gefunden
> }
> ```

**Pflichtanforderungen:**

- [ ] `strcmp` korrekt für String-Vergleiche verwendet (kein `==` für Strings!)
- [ ] `findeFachErsterTag` gibt `-1` zurück wenn nicht gefunden
- [ ] `zeigeFachtage` gibt alle Tage aus (nicht nur den ersten)
- [ ] `zeigeWochenplan` formatiert als Tabelle mit Ausrichtung

**Präsentationsfragen:**

- Warum kann man Strings in C nicht mit `==` vergleichen? Was macht strcmp stattdessen?
- Was ist `char *stundenplan[TAGE][LEKTIONEN]`? Was wird da gespeichert – die Strings selbst oder etwas anderes?
- Erkläre die verschachtelte Schleife in `zaehleFach`.
- Was gibt `findeFachErsterTag` zurück, wenn das Fach nicht existiert? Warum `-1`?

---

</br>

## 1.4. Gruppenarbeit D – «Schüler-Notenverwaltung»

**Szenario:**

- Eine Klasse mit 8 Schülern hat in 5 Fächern Prüfungen geschrieben. Die Noten sind in einem 2D-Array gespeichert.
- Ihr entwickelt das komplette Auswertungssystem.

**Anforderungen:**

````c
#define SCHUELER 8
#define FAECHER  5

char *schuelernamen[SCHUELER] = {
    "Anna", "Ben", "Clara", "David", "Eva", "Felix", "Gina", "Hans"
};

char *faecher[FAECHER] = {
    "Mathe", "Deutsch", "Englisch", "Physik", "Informatik"
};

int noten[SCHUELER][FAECHER] = {
    {5, 4, 6, 4, 6},   // Anna
    {3, 5, 4, 3, 5},   // Ben
    {6, 6, 5, 6, 6},   // Clara
    {4, 3, 4, 5, 4},   // David
    {5, 5, 6, 5, 5},   // Eva
    {2, 3, 3, 2, 4},   // Felix
    {6, 5, 5, 6, 5},   // Gina
    {4, 4, 5, 4, 3}    // Hans
};
````

**Zu implementierende Funktionen:**

```c
// Berechnet Durchschnittsnote eines Schülers (eine Zeile)
double schnittSchueler(int noten[SCHUELER][FAECHER], int schuelerIdx);

// Berechnet Durchschnittsnote in einem Fach (eine Spalte)
double schnittFach(int noten[SCHUELER][FAECHER], int fachIdx);

// Gibt Notenübersicht als formatierte Tabelle aus
void zeigeNotenblatt(int noten[SCHUELER][FAECHER],
                     char *namen[], char *faecher[]);

// Findet den besten Schüler (höchster Gesamtschnitt)
// Gibt Index zurück, Name via Pointer
int besteSchueler(int noten[SCHUELER][FAECHER], char **name);

// Prüft ob Schüler bestanden hat (alle Fächer >= 4)
int hatBestanden(int noten[SCHUELER][FAECHER], int schuelerIdx);

// Gibt Bestanden/Nicht bestanden für alle aus
void zeigeBestehensliste(int noten[SCHUELER][FAECHER], char *namen[]);
```

**Erwartete Ausgabe:**

```console
| Name  | Mathe | Deutsch | Englisch | Physik | Inform. | Ø    |
| ----- | ----- | ------- | -------- | ------ | ------- | ---- |
| Anna  | 5     | 4       | 6        | 4      | 6       | 5.00 |
| Ben   | 3     | 5       | 4        | 3      | 5       | 4.00 |
| Clara | 6     | 6       | 5        | 6      | 6       | 5.80 |
...
-----------|-------|---------|----------|--------|---------|-----
Fachschnitt|  4.4  |   4.4   |   4.8    |   4.4  |   4.9   |

Bester Schüler: Clara (Ø 5.80)

Bestehensliste:
Anna   → BESTANDEN
Ben    → BESTANDEN
...
Felix  → NICHT BESTANDEN
```

**Pflichtanforderungen:**

- [ ] `schnittSchueler` iteriert über Spalten einer Zeile
- [ ] `schnittFach` iteriert über Zeilen einer Spalte
- [ ] `besteSchueler` gibt Index zurück, Name über char **name Pointer
- [ ] `hatBestanden` prüft alle Fächer (ein einziges `< 4` reicht für nicht bestanden)
- [ ] Tabellenformatierung mit `%-10s`, `%5d` etc.

**Präsentationsfragen:**

1. Was ist der Unterschied zwischen `schnittSchueler` und `schnittFach` in der Schleifenstruktur? Zeig beide.
2. `besteSchueler` hat `char **name` als Parameter – was bedeutet das doppelte `*`?
3. Erkläre `hatBestanden` – wann gibst du `0` zurück, wann `1`? Was ist die Logik?
4. Was müsstet ihr ändern, wenn ein 9. Schüler hinzukommt? Welche Stellen im Code betrifft das?

---

© 2026 Lukas Müller – Licensed under CC BY-NC-ND 4.0
See [LICENSE](..\license.md) file for details.
