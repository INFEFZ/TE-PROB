|                             |                          |                               |
| --------------------------- | ------------------------ | ----------------------------- |
| **Elektrotechniker/-in HF** | **Programmiertechnik B** | ![Logo](../x_gitres/logo.png) |

- [1. Pointer](#1-pointer)
  - [1.1. Was sind Pointer](#11-was-sind-pointer)
  - [1.2. Definition von Pointer-Typen](#12-definition-von-pointer-typen)
  - [1.3. Definition von Pointer-Variablen](#13-definition-von-pointer-variablen)
  - [1.4. Wozu dient das \*-Zeichen?](#14-wozu-dient-das--zeichen)
  - [1.5. Adress-Operator \&](#15-adress-operator-)
  - [1.6. NULL-Pointer](#16-null-pointer)
  - [1.7. Zugriff auf ein Objekt mit Pointer](#17-zugriff-auf-ein-objekt-mit-pointer)
  - [1.8. Pointer auf void (void-Pointer)](#18-pointer-auf-void-void-pointer)
  - [1.9. Häufige Fehler im Umgang mit Pointern](#19-häufige-fehler-im-umgang-mit-pointern)
    - [1.9.1. Uninitialisierte Pointer verwenden](#191-uninitialisierte-pointer-verwenden)
    - [1.9.2. Zugriff auf freigegebenen Speicher (Dangling Pointer)](#192-zugriff-auf-freigegebenen-speicher-dangling-pointer)
    - [1.9.3. NULL-Pointer dereferenzieren](#193-null-pointer-dereferenzieren)
    - [1.9.4. Pointer-Typen nicht korrekt casten](#194-pointer-typen-nicht-korrekt-casten)
    - [1.9.5. Verwechslung von \* und \&](#195-verwechslung-von--und-)
  - [1.10. Zusammenfassung](#110-zusammenfassung)
- [2. Aufgaben](#2-aufgaben)
  - [2.1. Aufgabe Pointer](#21-aufgabe-pointer)

---

</br>

# 1. Pointer

## 1.1. Was sind Pointer

- **Pointer** (Zeiger) gehören zu den mächtigsten, aber auch komplexesten Konzepten der Programmiersprache C.
- Sie erlauben es, direkt auf Speicheradressen zuzugreifen und damit sehr flexibel und effizient zu programmieren.
- Gleichzeitig bergen sie viele Fehlerquellen.

## 1.2. Definition von Pointer-Typen

- Ein **Pointer-Typ** gibt an, auf welchen Datentyp ein Pointer zeigt.
- Jeder **Pointer** in C hat genau einen Typ, der bestimmt, wie der Speicherinhalt interpretiert wird, auf den der Pointer zeigt.

```c
int *ptr1;     // Pointer auf int
char *ptr2;    // Pointer auf char
float *ptr3;   // Pointer auf float
double *ptr4;  // Pointer auf double
```

> Der **Pointer-Typ** ist wichtig für Operationen wie Dereferenzierung (*ptr) und **Zeigerarithmetik**, da er bestimmt, wie viele Bytes bei einer Operation berücksichtigt werden.

## 1.3. Definition von Pointer-Variablen

Eine Pointer-Variable speichert die Adresse einer anderen Variablen.

```c
int zahl = 42;
int *ptr = &zahl;
```

- **`zahl`** ist eine normale int-Variable.
- **`&zahl`** liefert die Adresse dieser Variable.
- **`ptr`** ist ein Zeiger auf int, der die Adresse von zahl speichert.

## 1.4. Wozu dient das *-Zeichen?

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

## 1.5. Adress-Operator &

Mit dem Adress-Operator **`&`** erhält man die Speicheradresse einer Variable.

```c
int zahl = 99;
int *ptr = &zahl;
```

## 1.6. NULL-Pointer

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

## 1.7. Zugriff auf ein Objekt mit Pointer

Mit einem Pointer kann man auf eine Variable zugreifen und ihren Wert lesen oder verändern.

```c
int a = 5;
int *p = &a;

printf("%d\n", *p);  // liest den Wert (5)
*p = 10;             // schreibt neuen Wert (a ist jetzt 10)
```

## 1.8. Pointer auf void (void-Pointer)

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

## 1.9. Häufige Fehler im Umgang mit Pointern

### 1.9.1. Uninitialisierte Pointer verwenden

```c
int *p;
*p = 5;  // führt zu undefiniertem Verhalten!
```

### 1.9.2. Zugriff auf freigegebenen Speicher (Dangling Pointer)

```c
int *p = malloc(sizeof(int));
free(p);
*p = 10;  // Fehler: Zugriff nach free!
```

### 1.9.3. NULL-Pointer dereferenzieren

```c
int *p = NULL;
printf("%d", *p);  // Absturz (Segmentation Fault)
```

### 1.9.4. Pointer-Typen nicht korrekt casten

```c
void *vp;
double d = 3.14;
vp = &d;
printf("%d", *(int *)vp);  // falscher Cast → undefiniert!
```

### 1.9.5. Verwechslung von * und &

```c
int x = 5;
int *p = x;     // falsch, erwartet Adresse → `int *p = &x;`
```

## 1.10. Zusammenfassung

- **`&`** bedeutet **"Adresse von"**
- **`*`** bedeutet **"Inhalt an der Adresse"**
- Pointer müssen deklariert und oft initialisiert werden (z.B. `int *p = NULL;`)

Pointer sind ein zentrales Konzept in C, das viele Leistungsfähigkeiten bietet:

- Direkter Speicherzugriff
- Effiziente Datenmanipulation
- Flexible Datenstrukturen (z. B. verkettete Listen, Arrays, Funktionen als Parameter)
- > **Gleichzeitig erfordern sie sorgfältigen Umgang, da Fehler schwerwiegende Folgen haben können (Abstürze, Speicherlecks, undefiniertes Verhalten).**

---

</br>

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

- Schreibe ein C-Programm, das den Umgang mit **Pointern** demonstriert.
- Deklariere eine int-Variable `x` und weise ihr den Wert 25 zu.
- Deklariere einen Pointer `px`, der auf `x` zeigt.
- Gebe die Adresse von `x` und den Wert von `x` über den Pointer `px` aus.
- Ändere den Wert von `x` über den Pointer `px` auf 50.
- Gebe den neuen Wert von `x` aus.
- Erstelle einen `void*`-Pointer, der auf `x` zeigt, und zeige mit Type-Casting, wie man den Wert von `x` über diesen `void*`-Pointer ausgibt.

---

© 2026 Lukas Müller – Licensed under CC BY-NC-ND 4.0
See [LICENSE](..\license.md) file for details.
