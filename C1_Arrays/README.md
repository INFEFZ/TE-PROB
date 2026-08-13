---
theme: horizon
theme_overrides:
  colors:
    primary: "#164E63"
    accent: "#06B6D4"
    background: "#e9edec"
    text: "#164E63"
    code_bg: "#a8bbc2"
    title_text: "#ffffff"
    section_bg: "#155E75"
  fonts:
    title: Inter, Helvetica Neue, Arial, sans-serif
    body: Inter, Helvetica Neue, Arial, sans-serif
    code: Fira Code, JetBrains Mono, monospace
  header:
    show: false
    text: ""
---
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
  - [2.2. Aufgabe Notendurchschnittsberechnung](#22-aufgabe-notendurchschnittsberechnung)
  - [2.3. Aufgabe Temperaturstatistik](#23-aufgabe-temperaturstatistik)

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

## 2.2. Aufgabe Notendurchschnittsberechnung

| **Vorgabe**         | **Beschreibung**                                          |
| :------------------ | :-------------------------------------------------------- |
| **Lernziele**       | Verstehen wie Array's deklariert und initialisiert werden |
|                     | Kann auf einzelne Elemente eines Array's zugreifen        |
|                     | Kann ein Wert in einem Array setzen                       |
| **Sozialform**      | Einzelarbeit                                              |
| **Auftrag**         | siehe unten                                               |
| **Hilfsmittel**     |                                                           |
| **Zeitbedarf**      | 50min                                                     |
| **Lösungselemente** | Ausgabeliste der Zahlen                                   |

Schreiben Sie ein Programm, welches den Benutzer zur Eingabe von **3 Prüfungsnoten** auffordert und anschliessend die **Durchschnittsnote** berechnet und ausgibt.

**Funktionale Anforderungen:**

- Das Programm fordert den Benutzer nacheinander zur Eingabe von genau 3 Noten auf (z.B. "Bitte Note 1 eingeben:").
- Die Noten können Kommazahlen sein (z.B. 4.5), da im Notensystem Zwischenwerte üblich sind.
- Das Programm berechnet den Durchschnitt der 3 eingegebenen Noten.
- Das Programm gibt die berechnete Durchschnittsnote übersichtlich aus, z.B.:
  
  ```console
  Ihre Durchschnittsnote lautet: 4.83
  ```

- Die Ausgabe soll auf **2 Nachkommastellen** gerundet erfolgen.

**Teil 1 - Lösung mit Flowgorithm:**

Erstellen Sie zuerst ein **Flussdiagramm** in Flowgorithm, welches den Ablauf des Programms grafisch darstellt.

**Wichtige Vorgabe:** Die Noten sollen **nicht** in 3 einzelnen Variablen gespeichert werden, sondern in einem **Feld (Array)** mit der Grösse 3, z.B. `noten[3]` vom Typ Real/Decimal. Sowohl die **Eingabe** als auch die **Berechnung des Durchschnitts** müssen mit einer **Schleife** (For-Schleife) realisiert werden – nicht durch dreimaliges Wiederholen derselben Blöcke von Hand.

**Ihr Flussdiagramm soll folgende Elemente enthalten:**

1. **Deklaration** der benötigten Variablen:
   - Ein Feld `noten` mit Grösse 3 (Real/Decimal-Typ)
   - Eine Zählervariable, z.B. `i` (Integer), für die Schleife
   - Eine Variable `summe` (Real/Decimal, Startwert 0) zur Aufsummierung
   - Eine Variable `durchschnitt` (Real/Decimal) für das Endresultat
2. **Eingabeschleife:** Eine `For`-Schleife (`i` von 1 bis 3), in welcher pro Durchlauf:
   - eine Eingabeaufforderung erscheint (z.B. "Bitte Note {i} eingeben:"),
   - der eingegebene Wert im Feld gespeichert wird: `noten[i] = ...`.
3. **Berechnungsschleife:** Eine zweite `For`-Schleife (`i` von 1 bis 3), in welcher pro Durchlauf der jeweilige Feldwert zur `summe` addiert wird: `summe = summe + noten[i]`.
   - *Hinweis:* Diese Schleife kann auch mit der Eingabeschleife aus Schritt 2 kombiniert werden (Aufsummieren direkt bei der Eingabe) – beides ist zulässig.
4. Einen **Zuweisungs-Block** (Assign) **nach** der/den Schleife(n), welcher den Durchschnitt berechnet: `durchschnitt = summe / 3`.
5. Einen **Ausgabe-Block** (Output), welcher die Durchschnittsnote sauber formatiert ausgibt.

**Testen Sie Ihr Flussdiagramm** direkt in Flowgorithm mit mindestens einem Beispiel (z.B. Noten 5, 4.5 und 5.5 → Durchschnitt 5.0) und kontrollieren Sie, ob das Resultat stimmt. Nutzen Sie dazu auch den **Debug-Modus** von Flowgorithm, um zu beobachten, wie sich die Feldwerte und der Zähler `i` bei jedem Schleifendurchlauf verändern.

> **Abgabe Teil 1:** Screenshot oder Export des Flussdiagramms (`.fprg`-Datei).

**Teil 2 - Lösung in C:**

Setzen Sie denselben Algorithmus nun in der Programmiersprache **C** um.

**Technische Anforderungen:**

- Verwenden Sie einen passenden Datentyp für die Noten und den Durchschnitt (z.B. `float` oder `double`).
- Nutzen Sie `printf()` für die Eingabeaufforderungen und `scanf()` für die Einlesung der Werte.
- Berechnen Sie den Durchschnitt analog zum Flussdiagramm aus Teil 1.
- Formatieren Sie die Ausgabe des Durchschnitts auf **2 Nachkommastellen** (Tipp: Formatangabe bei `printf`, z.B. `%.2f`).
- Achten Sie auf eine saubere und lesbare Code-Struktur (sinnvolle Variablennamen, ggf. Kommentare).

**Beispielhafter Programmablauf (Konsole):**

```console
Bitte Note 1 eingeben: 5
Bitte Note 2 eingeben: 4.5
Bitte Note 3 eingeben: 5.5
Ihre Durchschnittsnote lautet: 5.00
```

**Zusatzaufgabe (freiwillig, für Schnelle):**
Erweitern Sie Ihr C-Programm so, dass ungültige Noten (kleiner als 1 oder grösser als 6) erkannt und mit einer Fehlermeldung abgelehnt werden. Die Eingabe soll so lange wiederholt werden, bis eine gültige Note eingegeben wurde.

> **Abgabe Teil 2:** C-Quellcode (`.c`-Datei), lauffähig und getestet.

---

## 2.3. Aufgabe Temperaturstatistik

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
See [LICENSE](../license.md) file for details.
