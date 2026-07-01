|                             |                          |                               |
| --------------------------- | ------------------------ | ----------------------------- |
| **Elektrotechniker/-in HF** | **Programmiertechnik B** | ![Logo](../x_gitres/logo.png) |

- [1. Arrays (Datenfelder)](#1-arrays-datenfelder)
  - [1.1. Sinn und Zweck von Arrays](#11-sinn-und-zweck-von-arrays)
  - [1.2. Definition von Arrays](#12-definition-von-arrays)
  - [1.3. Deklaration von Arrays](#13-deklaration-von-arrays)
  - [1.4. Initialisierung von Arrays](#14-initialisierung-von-arrays)
  - [1.5. Zugriff auf ein Element](#15-zugriff-auf-ein-element)
  - [1.6. Arrays und Schleifen](#16-arrays-und-schleifen)
  - [1.7. Arrays als Funktionsparameter](#17-arrays-als-funktionsparameter)
  - [1.8. Zweidimensionale Arrays (2D-Arrays)](#18-zweidimensionale-arrays-2d-arrays)
    - [1.8.1. Deklaration und Initialisierung](#181-deklaration-und-initialisierung)
    - [1.8.2. Zugriff auf Elemente](#182-zugriff-auf-elemente)
    - [1.8.3. 2D-Arrays als Funktionsparameter](#183-2d-arrays-als-funktionsparameter)
- [2. Aufgaben](#2-aufgaben)
  - [2.1. Sololearn Arrays \& Strings](#21-sololearn-arrays--strings)
  - [2.2. Aufgabe Analyse von Array's](#22-aufgabe-analyse-von-arrays)
  - [2.3. Fehlende Überprüfung auf Überschreitung der Feldgrenzen bei Arrays](#23-fehlende-überprüfung-auf-überschreitung-der-feldgrenzen-bei-arrays)
  - [2.4. Aufgabe Temperaturstatistik](#24-aufgabe-temperaturstatistik)

---

</br>

# 1. Arrays (Datenfelder)

## 1.1. Sinn und Zweck von Arrays

**Das Problem ohne Arrays:** Stell dir vor, die Prüfungsnoten von 30 Studierenden sollen gespeichert:

```c
// Ohne Array – ein Albtraum:
int note1, note2, note3, note4, note5; // ... bis note30
printf("%d %d %d ...", note1, note2, note3); // nicht wartbar
```

> **Die Verwendung von 30 Variablen kann zu einer Überforderung führen. Mit 1000 ist es unmöglich.**

**Die Lösung - Array:**

```c
// Mit Array – elegant:
int noten[30];
noten[0] = 5;
noten[1] = 4;
// ...
for (int i = 0; i < 30; i++) {
    printf("Note %d: %d\n", i + 1, noten[i]);
}
```

## 1.2. Definition von Arrays

- **Arrays** sind in C ein grundlegender Datentyp, mit dem sich mehrere Werte **des gleichen Typs** unter einem gemeinsamen Namen speichern lassen.
- Sie sind besonders nützlich, wenn man eine **Sammlung von Daten** bearbeiten oder strukturieren möchte – z.B. eine Liste von Zahlen oder Zeichen.
- Ein Array ist eine Sammlung von Daten **gleichen Typs**, die im zusammenhängenden Speicherbereich abgelegt sind.
- Jedes Element im Array ist über einen **Index** zugreifbar, wobei die Zählung bei **0** beginnt.

```console
Speicher:   [4][5][6][3][5][4][6][5]
Index:       0  1  2  3  4  5  6  7
Name:        noten
```

```c
// Deklaration von 5 Zahlen
int zahlen[5];

// Zugriff Zuweisung Wert (erstes Element)
zahlen[0]=1;

// Zugriff Zuweisung Wert (letztes Element)
zahlen[4]=5;
```

Dies reserviert Speicher für 5 Ganzzahlen (int). Die einzelnen Elemente sind:

- zahlen[0]
- zahlen[1]
- zahlen[2]
- zahlen[3]
- zahlen[4]

![Beispiel](./x_gitres/arrays-zahlen.png)

```c
/*...*/

for (int index = 1 ; index < 5 ; index++) 
{
  printf("%d\n", zahlen[index]);
}
```

## 1.3. Deklaration von Arrays

Ein Array wird deklariert, indem der Datentyp, der Name des Arrays und die Grösse in eckigen Klammern angegeben werden.

Allgemeine Syntax: `<Datentyp> <Arrayname>[<Grösse>];`

**Beispiele:**

```c
int zahlen[10];         // Array aus 10 int-Werten
float noten[5];         // Array aus 5 float-Werten
char buchstaben[26];    // Array aus 26 Zeichen
```

> **Hinweis: Die Grösse muss zur Kompilierzeit bekannt sein (es sei denn, du nutzt dynamische Arrays mit malloc)**

## 1.4. Initialisierung von Arrays

Ein Array kann direkt bei der Deklaration initialisiert werden.

```c
int zahlen[5] = {10, 20, 30, 40, 50};
```

**Automatische Grössenbestimmung:**

```c
int zahlen[] = {4, 8, 12};  // Compiler setzt Grösse auf 3
char name[] = "Max";  // = {'M', 'a', 'x', '\0'}
```

## 1.5. Zugriff auf ein Element

Auf Array-Elemente wird mit dem Index zugegriffen. Dabei gilt: Index 0 ist das erste Element.

```c
int zahlen[3] = {5, 10, 15};

int x = zahlen[1];  // x = 10
zahlen[2] = 20;     // Das dritte Element wird auf 20 gesetzt
```

> **Der Zugriff ausserhalb des gültigen Bereichs (zahlen[3] in obigem Beispiel) führt zu undefiniertem Verhalten!**
> **Es gibt keinen automatischen Schutz vor Indexüberläufen in C.**

## 1.6. Arrays und Schleifen

Arrays werden häufig mit Schleifen verwendet – besonders for-Schleifen – um alle Elemente effizient zu durchlaufen.

```c
#include <stdio.h>

int main() {
    int zahlen[5];

    // Einlesen der Werte
    for (int i = 0; i < 5; i++) {
        printf("Geben Sie Zahl %d ein: ", i + 1);
        scanf("%d", &zahlen[i]);
    }

    // Ausgabe der Werte
    printf("Sie haben eingegeben: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", zahlen[i]);
    }

    return 0;
}
```

**Beispiel: Durchschnitt einer Notenliste berechnen:**

```c
#include <stdio.h>

int main() {
    float noten[4] = {2.3, 1.7, 3.0, 2.0};
    float summe = 0;

    for (int i = 0; i < 4; i++) {
        summe += noten[i];
    }

    float durchschnitt = summe / 4;
    printf("Durchschnitt: %.2f\n", durchschnitt);

    return 0;
}
```

## 1.7. Arrays als Funktionsparameter

- Arrays werden in C **immer als Pointer** übergeben – die Funktion erhält also die Adresse des ersten Elements.
- Das bedeutet: **Änderungen in der Funktion wirken auf das Original!**

```c
#include <stdio.h>

// Array-Parameter: int arr[] ist gleichbedeutend mit int *arr
void verdoppleAlle(int arr[], int anzahl) {
    for (int i = 0; i < anzahl; i++) {
        arr[i] *= 2;   // verändert das ORIGINAL
    }
}

double berechneSchnitt(int arr[], int anzahl) {
    int summe = 0;
    for (int i = 0; i < anzahl; i++) {
        summe += arr[i];
    }
    return (double)summe / anzahl;
}

int main(void) {
    int werte[] = {3, 6, 9, 12};
    int n = 4;

    printf("Schnitt vorher: %.1f\n", berechneSchnitt(werte, n));  // 7.5
    verdoppleAlle(werte, n);
    printf("Schnitt nachher: %.1f\n", berechneSchnitt(werte, n)); // 15.0

    return 0;
}
```

> **Die Grösse des Arrays muss immer separat als Parameter übergeben werden, da die Funktion die Grösse selbst nicht kennt.**

---

## 1.8. Zweidimensionale Arrays (2D-Arrays)

Ein 2D-Array ist ein Array von Arrays – man kann es sich als Tabelle (Zeilen × Spalten) vorstellen.

**Stundenplan (3 Tage × 4 Lektionen):**

|            | **Lektion 0** | **Lektion 1** | **Lektion 2** | **Lektion 3** |
| ---------- | ------------- | ------------- | ------------- | ------------- |
| **Tag 0:** | Mathe         | Deutsch       | Physik        | Sport         |
| **Tag 1:** | Englisch      | Chemie        | Mathe         | Deutsch       |
| **Tag 2:** | Sport         | Physik        | Englisch      | Chemie        |

```console
Speicher: stundenplan[0][0] = Mathe
          stundenplan[0][1] = Deutsch
          stundenplan[1][2] = Mathe
          ...
```

### 1.8.1. Deklaration und Initialisierung

```c
// Deklaration: [Zeilen][Spalten]
int matrix[3][4];   // 3 Zeilen, 4 Spalten → 12 Elemente total

// Initialisierung mit verschachtelter Liste (lesbar)
int tabelle[3][4] = {
    {1,  2,  3,  4},   // Zeile 0
    {5,  6,  7,  8},   // Zeile 1
    {9, 10, 11, 12}    // Zeile 2
};

// Initialisierung flach (gleich, aber weniger lesbar)
int tabelle2[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

// Alles auf 0
int nullmatrix[3][4] = {0};
```

### 1.8.2. Zugriff auf Elemente

```c
// Zugriff: [Zeile][Spalte]
tabelle[1][2] = 99;              // Zeile 1, Spalte 2 überschreiben
printf("%d\n", tabelle[0][3]);   // Zeile 0, Spalte 3 ausgeben: 4
```

### 1.8.3. 2D-Arrays als Funktionsparameter

Bei 2D-Arrays muss die Spaltenanzahl im Parametertyp angegeben werden:

```c
#include <stdio.h>

#define ZEILEN  3
#define SPALTEN 4

void zeigeMatrix(int m[ZEILEN][SPALTEN]) {
    for (int z = 0; z < ZEILEN; z++) {
        for (int s = 0; s < SPALTEN; s++) {
            printf("%4d", m[z][s]);
        }
        printf("\n");
    }
}

int berechneZeilensumme(int m[ZEILEN][SPALTEN], int zeile) {
    int summe = 0;
    for (int s = 0; s < SPALTEN; s++) {
        summe += m[zeile][s];
    }
    return summe;
}

int main(void) {
    int matrix[ZEILEN][SPALTEN] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    zeigeMatrix(matrix);
    printf("Summe Zeile 1: %d\n", berechneZeilensumme(matrix, 1)); // 26

    return 0;
}
```

---

</br>

# 2. Aufgaben

## 2.1. Sololearn Arrays & Strings

| **Vorgabe**         | **Beschreibung**                                          |
| :------------------ | :-------------------------------------------------------- |
| **Lernziele**       | Verstehen wie Array's deklariert und initialisiert werden |
|                     | Kann auf einzelne Elemente eines Array's zugreifen        |
|                     | Kann ein Wert in einem Array setzen                       |
| **Sozialform**      | Einzelarbeit                                              |
| **Auftrag**         | siehe unten                                               |
| **Hilfsmittel**     |                                                           |
| **Zeitbedarf**      | 15min                                                     |
| **Lösungselemente** | Sololearn Kapitel erfolgreich abgeschlossen               |

Starte auf Sololearn den Kurs [**Einführung in C**](https://www.sololearn.com/de/learn/courses/c-introduction?location=2) und arbeite die Lektion **Arrays & Strings** durch.

---

## 2.2. Aufgabe Analyse von Array's

| **Vorgabe**         | **Beschreibung**                                          |
| :------------------ | :-------------------------------------------------------- |
| **Lernziele**       | Verstehen wie Array's deklariert und initialisiert werden |
|                     | Kann auf einzelne Elemente eines Array's zugreifen        |
|                     | Kann ein Wert in einem Array setzen                       |
| **Sozialform**      | Einzelarbeit                                              |
| **Auftrag**         | siehe unten                                               |
| **Hilfsmittel**     |                                                           |
| **Zeitbedarf**      | 10min                                                     |
| **Lösungselemente** | Ausgabeliste der Zahlen                                   |

Überlege, was das folgende Programm ausgibt. Überzeuge dich durch einen Programmlauf.

```c
#include <stdio.h>

int main(void) {
  size_t i;
  int ar[100];

  for (i = 0; i < 100; i = i + 1)
    ar[i] = 1;

  ar[11] = -5;
  ar[12] = ar[12] + 1;
  ar[13] = ar[0] + ar[11] + 4;

  for (i = 10; i <= 14; i = i + 1) 
    printf("ar[%2d] = %4d\n", (int)i, ar[i]);

  return 0;
}
```

## 2.3. Fehlende Überprüfung auf Überschreitung der Feldgrenzen bei Arrays

| **Vorgabe**         | **Beschreibung**                                          |
| :------------------ | :-------------------------------------------------------- |
| **Lernziele**       | Verstehen wie Array's deklariert und initialisiert werden |
|                     | Kann auf einzelne Elemente eines Array's zugreifen        |
|                     | Kann ein Wert in einem Array setzen                       |
| **Sozialform**      | Einzelarbeit                                              |
| **Auftrag**         | siehe unten                                               |
| **Hilfsmittel**     |                                                           |
| **Zeitbedarf**      | 10min                                                     |
| **Lösungselemente** | Ergebnis Analyse                                          |

- Führe einen Programmlauf mit dem folgenden Programm durch.
- Analysieren das Ergebnis!

```c
#include <stdio.h>

int main(void) {

  int i = 16; 
  int k = 21; 
  int l = 22; 
  int p = 23; 
  int q = 24;

  int ar[100];

  for (size_t i = 0; i < 100; i = i + 1)
    ar[i] = 27;

  printf("i ist %d\n", i); 
  printf("ar[-1] ist %d\n", ar[-1]); 
  printf("ar[0] ist %d\n", ar[0]); 
  printf("ar[100] ist %d\n", ar[100]); 
  printf("ar[101] ist %d\n", ar[101]); 
  printf("ar[102] ist %d\n", ar[102]); 
  printf("ar[103] ist %d\n", ar[103]); 
  printf("ar[-2] ist %d\n", ar[-2]); 
  printf("ar[-3] ist %d\n", ar[-3]); 
  printf("k ist %d\n", k);
  printf("l ist %d\n", l);
  printf("p ist %d\n", p);
  printf("q ist %d\n", q);

  return 0;
}
```

## 2.4. Aufgabe Temperaturstatistik

| **Vorgabe**         | **Beschreibung**                                          |
| :------------------ | :-------------------------------------------------------- |
| **Lernziele**       | Verstehen wie Array's deklariert und initialisiert werden |
|                     | Kann auf einzelne Elemente eines Array's zugreifen        |
|                     | Kann ein Array mit Schleifen verwenden                    |
| **Sozialform**      | Einzelarbeit                                              |
| **Auftrag**         | siehe unten                                               |
| **Hilfsmittel**     |                                                           |
| **Zeitbedarf**      | 30min                                                     |
| **Lösungselemente** | Lauffähiges Programm                                      |

Schreibe ein C-Programm, das die Tageshöchsttemperaturen für eine Woche (7 Tage) in einem Array speichert und folgende Anforderungen erfüllt:

- Deklariere ein Array von 7 Gleitkommazahlen (float), das die Temperaturen speichert.
- Lasse den Benutzer über die Konsole die Temperaturen für jeden Wochentag eingeben.
- Gebe alle eingegebenen Temperaturen in einer Zeile aus.
- Berechne den Durchschnitt der Temperaturen.
- Gebe die höchste und die niedrigste Temperatur aus.
- **Hinweise**: Verwende eine Schleife zur Eingabe und zur Ausgabe.
- Benutze Variablen für die `Summe`, das `Maximum` und das `Minimum`.
- Nutze eine Initialisierung von `max` mit einem sehr kleinen Wert und von `min` mit einem sehr grossen Wert.

**Beispielausgabe:**

```console
Geben Sie die Temperatur für Tag 1 ein: 21.5
Geben Sie die Temperatur für Tag 2 ein: 23.0
...
Geben Sie die Temperatur für Tag 7 ein: 19.8

Eingegebene Temperaturen: 21.5 23.0 22.3 24.1 20.5 18.9 19.8

Durchschnittstemperatur: 21.43
Höchste Temperatur: 24.1
Niedrigste Temperatur: 18.9
```

---

© 2026 Lukas Müller – Licensed under CC BY-NC-ND 4.0
See [LICENSE](..\license.md) file for details.
