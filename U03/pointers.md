|                             |                          |                                        |
| --------------------------- | ------------------------ | -------------------------------------- |
| **Elektrotechniker/-in HF** | **Programmiertechnik B** | ![IPSO Logo](./x_gitres/ipso_logo.png) |

- [1. Pointer](#1-pointer)
  - [1.1. E-Book](#11-e-book)
  - [1.2. Was sind Pointer](#12-was-sind-pointer)
  - [1.3. Definition von Pointer-Typen](#13-definition-von-pointer-typen)
  - [1.4. Definition von Pointer-Variablen](#14-definition-von-pointer-variablen)
  - [1.5. Wozu dient das \*-Zeichen?](#15-wozu-dient-das--zeichen)
  - [1.6. Adress-Operator \&](#16-adress-operator-)
  - [1.7. NULL-Pointer](#17-null-pointer)
  - [1.8. Zugriff auf ein Objekt mit Pointern](#18-zugriff-auf-ein-objekt-mit-pointern)
  - [1.9. Pointer auf void (void-Pointer)](#19-pointer-auf-void-void-pointer)
  - [1.10. Häufige Fehler im Umgang mit Pointern](#110-häufige-fehler-im-umgang-mit-pointern)
    - [1.10.1. Uninitialisierte Pointer verwenden](#1101-uninitialisierte-pointer-verwenden)
    - [1.10.2. Zugriff auf freigegebenen Speicher (Dangling Pointer)](#1102-zugriff-auf-freigegebenen-speicher-dangling-pointer)
    - [1.10.3. NULL-Pointer dereferenzieren](#1103-null-pointer-dereferenzieren)
    - [1.10.4. Pointer-Typen nicht korrekt casten](#1104-pointer-typen-nicht-korrekt-casten)
    - [1.10.5. Verwechslung von \* und \&](#1105-verwechslung-von--und-)
  - [1.11. Zusammenfassung](#111-zusammenfassung)
- [2. Aufgaben](#2-aufgaben)
  - [2.1. Aufgabe Pointer](#21-aufgabe-pointer)

---

# 1. Pointer

## 1.1. E-Book

![Einführung in Pointer und Arrays](./x_gitres/k08-einführung-in-pointer-und-arrays.pdf)

## 1.2. Was sind Pointer

- **Pointer** (Zeiger) gehören zu den mächtigsten, aber auch komplexesten Konzepten der Programmiersprache C.
- Sie erlauben es, direkt auf Speicheradressen zuzugreifen und damit sehr flexibel und effizient zu programmieren.
- Gleichzeitig bergen sie viele Fehlerquellen.

## 1.3. Definition von Pointer-Typen

- Ein **Pointer-Typ** gibt an, auf welchen Datentyp ein Pointer zeigt.
- Jeder **Pointer** in C hat genau einen Typ, der bestimmt, wie der Speicherinhalt interpretiert wird, auf den der Pointer zeigt.

```c
int *ptr1;     // Pointer auf int
char *ptr2;    // Pointer auf char
float *ptr3;   // Pointer auf float
double *ptr4;  // Pointer auf double
```

> Der **Pointer-Typ** ist wichtig für Operationen wie Dereferenzierung (*ptr) und **Zeigerarithmetik**, da er bestimmt, wie viele Bytes bei einer Operation berücksichtigt werden.

## 1.4. Definition von Pointer-Variablen

Eine Pointer-Variable speichert die Adresse einer anderen Variablen.

```c
int zahl = 42;
int *ptr = &zahl;
```

- **`zahl`** ist eine normale int-Variable.
- **`&zahl`** liefert die Adresse dieser Variable.
- **`ptr`** ist ein Zeiger auf int, der die Adresse von zahl speichert.

## 1.5. Wozu dient das *-Zeichen?

Das *-Zeichen hat zwei verschiedene Bedeutungen, je nach Kontext:

- Bei der Deklaration: `int *ptr;`
- Bei der Dereferenzierung (Zugriff auf den Wert):
  - *p liest den Wert, auf den p zeigt.
  - Dies nennt man Dereferenzieren.
  
```c
int x = 10;
int *p = &x;
printf("%d", *p);  // gibt 10 aus
```

## 1.6. Adress-Operator &

Mit dem Adress-Operator **`&`** erhält man die Speicheradresse einer Variable.

```c
int zahl = 99;
int *ptr = &zahl;
```

## 1.7. NULL-Pointer

- Ein NULL-Pointer zeigt auf nichts.
- Er ist nützlich, um anzuzeigen, dass ein Pointer aktuell ungültig oder leer ist.

```c
int *ptr = NULL;

if (ptr == NULL) {
    printf("Pointer zeigt auf nichts!\n");
}
```

n der <stddef.h>-Bibliothek ist NULL als (void *)0 definiert.

Warum NULL-Pointer verwenden?

- Um nicht initialisierte Pointer zu erkennen.
- Um Abstürze durch ungültigen Speicherzugriff zu vermeiden.
- Um auf besondere Zustände hinzuweisen (z. B. Ende einer Liste).

## 1.8. Zugriff auf ein Objekt mit Pointern

Mit einem Pointer kann man auf eine Variable zugreifen und ihren Wert lesen oder verändern.

```c
int a = 5;
int *p = &a;

printf("%d\n", *p);  // liest den Wert (5)
*p = 10;             // schreibt neuen Wert (a ist jetzt 10)
```

## 1.9. Pointer auf void (void-Pointer)

- Ein void* ist ein generischer Zeiger, der auf einen beliebigen Datentyp zeigen kann.
- Er kann jedoch nicht direkt dereferenziert werden, da der Compiler den Typ nicht kennt.

```c
void *vp;
int zahl = 42;
vp = &zahl;

// Um auf den Wert zuzugreifen, muss gecastet werden:
printf("%d\n", *(int *)vp);
```

Typische Verwendungen:

- In generischen Funktionen (z. B. malloc, qsort)
- Für beliebige Datentypen in Datenstrukturen

## 1.10. Häufige Fehler im Umgang mit Pointern

### 1.10.1. Uninitialisierte Pointer verwenden

```c
int *p;
*p = 5;  // führt zu undefiniertem Verhalten!
```

### 1.10.2. Zugriff auf freigegebenen Speicher (Dangling Pointer)

```c
int *p = malloc(sizeof(int));
free(p);
*p = 10;  // Fehler: Zugriff nach free!
```

### 1.10.3. NULL-Pointer dereferenzieren

```c
int *p = NULL;
printf("%d", *p);  // Absturz (Segmentation Fault)
```

### 1.10.4. Pointer-Typen nicht korrekt casten

```c
void *vp;
double d = 3.14;
vp = &d;
printf("%d", *(int *)vp);  // falscher Cast → undefiniert!
```

### 1.10.5. Verwechslung von * und &

```c
int x = 5;
int *p = x;     // falsch, erwartet Adresse → `int *p = &x;`
```

## 1.11. Zusammenfassung

- **`&`** bedeutet **"Adresse von"**
- **`*`** bedeutet **"Inhalt an der Adresse"**
- Pointer müssen deklariert und oft initialisiert werden (z.B. `int *p = NULL;`)

Pointer sind ein zentrales Konzept in C, das viele Leistungsfähigkeiten bietet:

- Direkter Speicherzugriff
- Effiziente Datenmanipulation
- Flexible Datenstrukturen (z. B. verkettete Listen, Arrays, Funktionen als Parameter)
- > Gleichzeitig erfordern sie sorgfältigen Umgang, da Fehler schwerwiegende Folgen haben können (Abstürze, Speicherlecks, undefiniertes Verhalten).

---

# 2. Aufgaben

## 2.1. Aufgabe Pointer

| **Vorgabe**         | **Beschreibung**                                          |
| :------------------ | :-------------------------------------------------------- |
| **Lernziele**       | Verstehen wie Pointer deklariert und initialisiert werden |
|                     | Kann auf Daten über einen Pointer zugreifen               |
|                     | Kann den Adress-Operator einsetzen                        |
| **Sozialform**      | Einzelarbeit                                              |
| **Auftrag**         | siehe unten                                               |
| **Hilfsmittel**     |                                                           |
| **Zeitbedarf**      | 30min                                                     |
| **Lösungselemente** | Funktionierendes Programm                                 |

- Schreiben Sie ein C-Programm, das den Umgang mit **Pointern** demonstriert.
- Deklarieren Sie eine int-Variable `x` und weisen Sie ihr den Wert 25 zu.
- Deklarieren Sie einen Pointer `px`, der auf `x` zeigt.
- Geben Sie die Adresse von `x` und den Wert von `x` über den Pointer `px` aus.
- Ändern Sie den Wert von `x` über den Pointer `px` auf 50.
- Geben Sie den neuen Wert von `x` aus.
- Erstellen Sie einen void*-Pointer, der auf `x` zeigt, und zeigen Sie mit Type-Casting, wie man den Wert von `x` über diesen `void*`-Pointer ausgibt.
