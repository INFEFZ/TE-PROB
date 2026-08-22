|                             |                          |                               |
| --------------------------- | ------------------------ | ----------------------------- |
| **Elektrotechniker/-in HF** | **Programmiertechnik B** | ![Logo](../x_gitres/logo.png) |

- [1. Der Speicher in C](#1-der-speicher-in-c)
  - [1.1. Die zentrale Idee: Speicher als Byte-Array](#11-die-zentrale-idee-speicher-als-byte-array)
  - [1.2. Variablen im Speicher](#12-variablen-im-speicher)
  - [1.3. Speicheradressen (Hexadezimalzahlen)](#13-speicheradressen-hexadezimalzahlen)
  - [1.4. Der \& Operator: "Gib mir die Adresse"](#14-der--operator-gib-mir-die-adresse)
  - [1.5. Stack vs. Heap (Übersicht)](#15-stack-vs-heap-übersicht)
    - [**Stack**](#stack)
    - [**Heap**](#heap)
  - [1.6. Warum C so anders ist](#16-warum-c-so-anders-ist)
    - [**Problem: Strings (Zeichenketten)**](#problem-strings-zeichenketten)
    - [**Problem: Flexibilität**](#problem-flexibilität)
  - [1.7. Speicherlayout eines einfachen Programms](#17-speicherlayout-eines-einfachen-programms)
- [2. Aufgaben](#2-aufgaben)
  - [2.1. Speicher visualisieren](#21-speicher-visualisieren)
  - [2.2. Adressen abfragen](#22-adressen-abfragen)

---

</br>

# 1. Der Speicher in C

## 1.1. Die zentrale Idee: Speicher als Byte-Array

**Der Kern-Unterschied zwischen C und modernen Sprachen:**

Moderne Sprachen (Python, Java, C#) verstecken den Speicher. Der Programmierer denkt nur "Ich habe eine Variable x" – die Sprache kümmert sich um den Rest.

**C ist anders:** In C arbeitet der Programmierer direkt mit Speicher-Konzepten.

Ein Computer hat **Speicher** – das ist eine lange Reihe von Bytes:

```bash
Byte 0:     [?]
Byte 1:     [?]
Byte 2:     [?]
Byte 3:     [?]
...
Byte 1000:  [?]
Byte 1001:  [?]
...
```

Jedes Byte hat eine **Adresse** (eine Nummer). Wenn man eine Variable speichert, speichert man sie an einer bestimmten Adresse.

> **Das ist das zentrale Konzept von C:** Programmierer müssen verstehen, wo ihre Daten im Speicher liegen und wie man auf sie zugreift.

---

## 1.2. Variablen im Speicher

Wenn du schreibst:

```c
int x = 5;
int y = 10;
char c = 'A';
```

Dann speichert C das etwa so:

```bash
Adresse:    Inhalt:      Variable:
0x7FFC      [0x00000005] → x (4 Bytes für int)
0x7FF8      [0x0000000A] → y (4 Bytes für int)
0x7FF4      [0x41]       → c (1 Byte für char, Wert 0x41 = 'A')
```

**Wichtig:**

- Der Name `x` ist nur für den Programmierer – intern arbeitet C nur mit Adressen.
- Die Adresse ist einfach eine Nummer (in Hexadezimal, aber nur eine Zahl).
- Verschiedene Datentypen brauchen unterschiedlich viel Speicher: `int` = 4 Bytes, `char` = 1 Byte, etc.

---

## 1.3. Speicheradressen (Hexadezimalzahlen)

Speicheradressen werden meist in **Hexadezimal** dargestellt (0x…), weil das kompakter ist:

| Dezimal | Hexadezimal |
| ------- | ----------- |
| 0       | 0x0         |
| 10      | 0xA         |
| 15      | 0xF         |
| 16      | 0x10        |
| 255     | 0xFF        |
| 4095    | 0xFFF       |

> **Du brauchst Hexadezimal nicht wirklich können – es ist nur eine andere Schreibweise für Zahlen. Wichtig: Die Adresse ist einfach eine Zahl.**

Ein Speicher mit 8 GB hätte Adressen von 0x0 bis etwa 0x200000000.

---

## 1.4. Der & Operator: "Gib mir die Adresse"

Mit dem `&` Operator kannst du die Adresse einer Variablen abfragen:

```c
#include <stdio.h>

int main()
{
    int x = 5;
    
    printf("Wert von x: %d\n", x);           // Gibt 5 aus
    printf("Adresse von x: %p\n", &x);       // Gibt 0x7FFC (oder ähnlich) aus
    
    return 0;
}
```

**Ausgabe könnte sein:**

```bash
Wert von x: 5
Adresse von x: 0x7ffc4e9c
```

> **Das `%p` Format gibt Adressen aus. Die genaue Adresse variiert jedes Mal, wenn das Programm läuft – das ist normal.**

---

## 1.5. Stack vs. Heap (Übersicht)

Der Speicher ist in verschiedene Regionen eingeteilt. Die zwei wichtigsten:

### **Stack**

- Für **lokale Variablen** und **Funktionsaufrufe**
- Automatisch verwaltet (wird automatisch freigegeben, wenn Funktion endet)
- Klein (typischerweise 1–8 MB)
- Schnell
- Statische Grösse (Größe muss zur Compile-Zeit bekannt sein)

```c
int main()
{
    int x = 5;      // Stack
    char name[100]; // Stack (Grösse bekannt)
    return 0;
} // Stack wird automatisch freigegeben
```

### **Heap**

- Für **dynamische Speicherreservierung**
- Manuell verwaltet (mit `malloc()` und `free()`)
- Groß (typischerweise Gigabytes)
- Langsamer als Stack
- Dynamische Grösse (kann zur Laufzeit verändern)

```c
int main()
{
    int *ptr = malloc(sizeof(int)); // Heap
    free(ptr);                      // Manuell freigeben!
    return 0;
}
```

> **Für Anfänger:** Stack ist "sicher" (automatisch), Heap ist "mächtig" (aber man muss aufpassen).

**Speicherlayout eines Programms:**

```bash
Höhere Adressen
┌─────────────────────┐
│  Stack              │  ← lokale Variablen, Funktionsaufrufe
│  ↓ wächst nach unten│
├─────────────────────┤
│  (freier Speicher)  │
├─────────────────────┤
│  Heap               │  ← dynamische Daten
│  ↑ wächst nach oben │
├─────────────────────┤
│  Global/Static Data │  ← globale Variablen
├─────────────────────┤
│  Code               │  ← das Programm selbst
└─────────────────────┘
Niedrigere Adressen
```

---

## 1.6. Warum C so anders ist

### **Problem: Strings (Zeichenketten)**

In Java:

```java
String text = "Hallo";  // Java weiß automatisch die Länge
```

In C:

```c
char text[] = "Hallo";  // Wie merkt C, wo das Wort endet?
```

**Antwort:** Mit einem Endezeichen (`'\0'`), das in der Speicheradresse nach dem letzten Buchstaben liegt.

Das ist möglich, weil C direkt mit Speicher arbeitet. Java/Python verstecken das.

### **Problem: Flexibilität**

Wenn du 1000 Messwerte speichern möchtest, aber nicht weißt, wie viele es wirklich sind:

In Java:

```java
ArrayList<Integer> messwerte = new ArrayList<>();  // Wächst automatisch
```

In C:

```c
int *messwerte = malloc(n * sizeof(int));  // Du musst manuell Speicher reservieren
// ... verwenden ...
free(messwerte);  // Du musst manuell freigeben
```

C ist näher am Hardware, aber schwieriger zu programmieren.

---

## 1.7. Speicherlayout eines einfachen Programms

**Programm:**

```c
#include <stdio.h>

int global_var = 42;  // Globale Variable

int main()
{
    int x = 5;
    int y = 10;
    char name[20] = "Anna";
    
    printf("x = %d\n", x);
    printf("Adresse von x: %p\n", &x);
    
    return 0;
}
```

**Speicherlayout während Ausführung:**

```bash
Adresse      Inhalt
0x7FFC8 ┌────────────────────┐
        │ x = 5 (4 Bytes)    │  Stack (lokale Variablen von main)
0x7FFC4 ├────────────────────┤
        │ y = 10 (4 Bytes)   │
0x7FFC0 ├────────────────────┤
        │ name[20] "Anna\0.."│  (20 Bytes für Array)
0x7FFAC ├────────────────────┤
        │ (Funktions-Kontext)│
...
0x10000 ├────────────────────┤
        │ global_var = 42    │  Global Data (globale Variablen)
...
0x00400 ├────────────────────┤
        │ [Programmcode]     │  Code
0x00000 └────────────────────┘
```

**Wichtige Erkenntnisse:**

- Stack-Variablen haben aufsteigende Adressen (nicht absteigend – das hängt vom System ab)
- Globale Variablen haben eigene Speicher-Region
- Größere Arrays (wie `name[20]`) brauchen mehr Speicher nebeneinander

---

# 2. Aufgaben

## 2.1. Speicher visualisieren

| **Vorgabe**         | **Beschreibung**                                            |
| :------------------ | :---------------------------------------------------------- |
| **Lernziele**       | Kann beschreiben, wie Variablen im Speicher angeordnet sind |
|                     | Kann mit dem & Operator Adressen abfragen                   |
|                     | Versteht die Unterschiede zwischen Wert und Adresse         |
| **Sozialform**      | Einzelarbeit                                                |
| **Auftrag**         | siehe unten                                                 |
| **Hilfsmittel**     | Editor, Compiler, printf()                                  |
| **Zeitbedarf**      | 20min                                                       |
| **Lösungselemente** | Funktionierendes Programm, das Adressen und Werte anzeigt   |

Schreibe ein C-Programm, das Folgendes tut:

- Definiere 5 verschiedene Variablen verschiedener Typen (`int`, `float`, `char`, `double`)
- Gib Wert und Adresse jeder Variablen aus (`%d` und `%p`)
- Beobachte, in welcher Reihenfolge die Adressen angeordnet sind
- Erkläre: Sind die Adressen aufsteigend oder absteigend? Warum?

---

## 2.2. Adressen abfragen

| **Vorgabe**         | **Beschreibung**                                                         |
| :------------------ | :----------------------------------------------------------------------- |
| **Lernziele**       | Kann die Größe von Datentypen abfragen (`sizeof()`)                      |
|                     | Versteht, dass verschiedene Typen unterschiedlich viel Speicher brauchen |
|                     | Kann ein Speicher-Layout zeichnen                                        |
| **Sozialform**      | Partnerarbeit                                                            |
| **Auftrag**         | siehe unten                                                              |
| **Hilfsmittel**     | Papier, Editor, `sizeof()` Operator                                      |
| **Zeitbedarf**      | 25min                                                                    |
| **Lösungselemente** | Tabelle mit sizeof() und Speicher-Visualisierung                         |

Schreibe ein Programm, das die Größe aller wichtigen Datentypen anzeigt:

```c
printf("int:    %lu Bytes\n", sizeof(int));
printf("float:  %lu Bytes\n", sizeof(float));
// ... etc
```

Zeichne dann auf Papier, wie diese Variablen im Speicher hintereinander liegen würden:

```c
int x = 1;
float y = 2.5;
char z = 'A';
double w = 3.14;
```

Berechne die Adresse der letzten Variablen: Wenn `x` bei 0x1000 liegt, wo liegt dann `w`?

---

© 2026 Lukas Müller – Licensed under CC BY-NC-ND 4.0
