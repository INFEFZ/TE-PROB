|                             |                          |                                        |
| --------------------------- | ------------------------ | -------------------------------------- |
| **Elektrotechniker/-in HF** | **Programmiertechnik B** | ![IPSO Logo](./x_gitres/ipso_logo.png) |

- [1. String (Zeichenketten)](#1-string-zeichenketten)
  - [1.1. E-Book](#11-e-book)
  - [1.1. Definition von Strings in C](#11-definition-von-strings-in-c)
  - [1.2. Deklaration von Strings](#12-deklaration-von-strings)
  - [1.3. Initialisierung von Strings](#13-initialisierung-von-strings)
  - [1.4. String-Terminierung (\\0)](#14-string-terminierung-0)
  - [1.5. Ein- und Ausgabe von Strings](#15-ein--und-ausgabe-von-strings)
  - [1.6. Wichtige Stringfunktionen in C (aus `<string.h>`)](#16-wichtige-stringfunktionen-in-c-aus-stringh)
  - [1.7. Beispiele zu Stringfunktionen](#17-beispiele-zu-stringfunktionen)
  - [1.8. Zusammenfassung](#18-zusammenfassung)
- [2. Aufgaben](#2-aufgaben)
  - [2.1. Zeichenketten Länge](#21-zeichenketten-länge)
  - [2.2. Zeichenketten rückwärts](#22-zeichenketten-rückwärts)
  - [2.3. Zeichenketten vergleichen](#23-zeichenketten-vergleichen)
  - [2.4. Zeichenketten verarbeiten](#24-zeichenketten-verarbeiten)

---

# 1. String (Zeichenketten)

- In der Programmiersprache C gibt es **keine** eigene String-Datentypen wie in modernen Sprachen (z. B. String in Java).
- Stattdessen werden Zeichenketten (Strings) in C als **Arrays von Zeichen (char)**dargestellt, die mit einem speziellen **Abschlusszeichen** `'\0'` (Null-Byte) terminiert werden.

## 1.1. E-Book

![Fortgeschrittene Programmierung mit Pointern](./x_gitres/k12-fortgeschrittene-programmierung-mit-pointern)

## 1.1. Definition von Strings in C

- Ein String ist in C eine **Abfolge von Zeichen**, die im Speicher als **char**-Array gespeichert wird.
- Das **letzte Zeichen** eines Strings ist immer das Null-Zeichen **`'\0'`**, das das Ende der Zeichenkette markiert.

```c
char name[] = {'J', 'o', 'h', 'n', '\0'};
```

> Ohne `'\0'` wüsste das Programm nicht, wann die Zeichenkette endet – das ist essentiell für die Stringverarbeitung in C.

## 1.2. Deklaration von Strings

**Leeres Array:**

```c
char wort[10];  // Platz für 9 Zeichen + '\0'
```

**Mit Initialisierung:**

```c
char wort[] = "Hallo";  // Automatische Größe: 6 (inkl. '\0')

// Wichtig:
char wort[] = {'H', 'a', 'l', 'l', 'o'};  // KEIN String, da '\0' fehlt
```

## 1.3. Initialisierung von Strings

Strings können auf zwei Arten initialisiert werden:

**Mit Stringliteralen (empfohlen):**

```c
char text1[] = "Test";  // Automatisch '\0' am Ende
```

**Mit expliziten Zeichen:**

```c
char text2[] = {'T', 'e', 's', 't', '\0'};  // Manuelle Termination
```

> **Ein String muss das Nullzeichen '\0' enthalten, sonst verhalten sich Stringfunktionen undefiniert.**

## 1.4. String-Terminierung (\0)

- Das Zeichen `'\0'` markiert das Ende eines Strings.
- Alle Funktionen der Standardbibliothek wie `strlen()`, `printf()`, `strcpy()` usw. verlassen sich auf dieses Terminierungszeichen.
- Wenn ein `char[]` **nicht** mit `'\0'` abgeschlossen ist, führen Stringoperationen zu undefiniertem Verhalten

```c
char falsch[] = {'H', 'i'};  // Kein '\0' -> kein gültiger String
```

> `'\0'` ist gleichbedeutend mit dem Ganzzahlwert 0 und belegt 1 Byte.

## 1.5. Ein- und Ausgabe von Strings

**Ausgabe mit printf():**

```c
char name[] = "Lisa";
printf("Name: %s\n", name);  // %s gibt den gesamten String aus
```

**Einlesen mit scanf():**

```c
char eingabe[100];
scanf("%s", eingabe);  // Liest bis zum ersten Leerzeichen
```

> `scanf("%s")` liest nur bis zum ersten Leerzeichen.

**Ganze Zeile lesen mit fgets():**

```c
char zeile[100];
fgets(zeile, 100, stdin);  // Liest auch Leerzeichen mit
```

> **fgets() speichert den Zeilenumbruch \n mit, wenn Platz ist. Eventuell muss dieser entfernt werden.**

## 1.6. Wichtige Stringfunktionen in C (aus `<string.h>`)

Um mit Strings in C zu arbeiten, stellt die Standardbibliothek viele Funktionen bereit.
Diese befinden sich in der Header-Datei: `#include <string.h>`

| **Funktion**               | **Beschreibung**                                    |
| :------------------------- | :-------------------------------------------------- |
| `strlen(s)`                | Gibt die Länge von `s` (ohne `\0`) zurück           |
| `strcpy(ziel, quelle)`     | Kopiert `quelle` nach `ziel`                        |
| `strncpy(ziel, quelle, n)` | Kopiert max. `n` Zeichen                            |
| `strcat(ziel, quelle)`     | Hängt `quelle` an `ziel` an                         |
| `strncat(ziel, quelle, n)` | Hängt max. `n` Zeichen an                           |
| `strcmp(s1, s2)`           | Vergleicht zwei Strings lexikografisch              |
| `strncmp(s1, s2, n)`       | Vergleicht die ersten `n` Zeichen                   |
| `strchr(s, c)`             | Gibt Zeiger auf erstes `c` in `s` zurück            |
| `strstr(s1, s2)`           | Sucht `s2` in `s1`, Rückgabe: Zeiger auf Fundstelle |

## 1.7. Beispiele zu Stringfunktionen

```c
char s[] = "Hallo";
int laenge = strlen(s);  // Ergebnis: 5

char quelle[] = "Beispiel";
char ziel[20];
strcpy(ziel, quelle);

if (strcmp("abc", "abc") == 0) {
    printf("Strings sind gleich!\n");
}

char a[20] = "Hallo ";
char b[] = "Welt";
strcat(a, b);  // a enthält jetzt "Hallo Welt"
```

Viele Standardfunktionen wie `strcpy()` oder `strcat()` sind unsicher, da sie bei zu kleinen Arrays einen Pufferüberlauf (buffer overflow) verursachen können. Bessere Alternativen:

- `strncpy()` statt `strcpy()`
- `strncat()` statt `strcat()`

## 1.8. Zusammenfassung

| **Thema**            | **Wichtigste Punkte**                       |
| :------------------- | :------------------------------------------ |
| **Definition**       | Strings = `char`-Array + `'\0'`             |
| **Deklaration**      | `char s[10];` oder `char s[] = "Text";`     |
| **Initialisierung**  | Mit Stringliteral oder manuell mit `'\0'`   |
| **Termination**      | `'\0'` zwingend notwendig                   |
| **Ein-/Ausgabe**     | `scanf()`, `fgets()`, `printf("%s")`        |
| **Stringfunktionen** | `strlen`, `strcpy`, `strcmp`, `strcat`, ... |
| **Sicherheit**       | `strncpy`/`strncat` vermeiden Überläufe     |

---

# 2. Aufgaben

## 2.1. Zeichenketten Länge

| **Vorgabe**         | **Beschreibung**                                                 |
| :------------------ | :--------------------------------------------------------------- |
| **Lernziele**       | Verstehen wie Strings deklariert und initialisiert werden können |
|                     | Kann Strings von der Konsole einlesen und ausgeben               |
|                     | Kann Stringfunktionen einsetzen                                  |
| **Sozialform**      | Einzelarbeit                                                     |
| **Auftrag**         | siehe unten                                                      |
| **Hilfsmittel**     |                                                                  |
| **Zeitbedarf**      | 20min                                                            |
| **Lösungselemente** | Funktionierendes Programm                                        |

Schreiben Sie ein C-Programm, das Folgendes tut:

- Lese zwei Zeichenkette (max. 100 Zeichen) vom Benutzer ein.
- Gib die längere Zeichenkette inkl. deren Länge (Anzahl Zeichen) in der Konsole aus.

---

## 2.2. Zeichenketten rückwärts

| **Vorgabe**         | **Beschreibung**                                                 |
| :------------------ | :--------------------------------------------------------------- |
| **Lernziele**       | Verstehen wie Strings deklariert und initialisiert werden können |
|                     | Kann Strings von der Konsole einlesen und ausgeben               |
|                     | Kann Stringfunktionen einsetzen                                  |
| **Sozialform**      | Einzelarbeit                                                     |
| **Auftrag**         | siehe unten                                                      |
| **Hilfsmittel**     |                                                                  |
| **Zeitbedarf**      | 30min                                                            |
| **Lösungselemente** | Funktionierendes Programm                                        |

Schreiben Sie ein C-Programm, das Folgendes tut:

- Lese eine Zeichenkette (max. 100 Zeichen) vom Benutzer ein.
- Schreibe zwei Funktionen, welche die Zeichenkette rückwärts aus ausgibt, sowohl durch direkte Übergabe des Arrays als auch durch Übergabe über einen Pointer.
  - `ausgabe_mit_array(char str[]) {}`
  - `ausgabe_mit_pointer(char* ptr) {}`

---

## 2.3. Zeichenketten vergleichen

| **Vorgabe**         | **Beschreibung**                                                 |
| :------------------ | :--------------------------------------------------------------- |
| **Lernziele**       | Verstehen wie Strings deklariert und initialisiert werden können |
|                     | Kann Strings von der Konsole einlesen und ausgeben               |
|                     | Kann Stringfunktionen einsetzen                                  |
| **Sozialform**      | Einzelarbeit                                                     |
| **Auftrag**         | siehe unten                                                      |
| **Hilfsmittel**     |                                                                  |
| **Zeitbedarf**      | 30min                                                            |
| **Lösungselemente** | Funktionierendes Programm                                        |

Schreiben Sie ein C-Programm, das Folgendes tut:

- Lese eine Zeichenkette vom Benutzer ein.
- Kopiere die Zeichenkette in eine andere Zeichenkette.
- Verlgeiche die beiden Zeichenkette, um sicherzustellen, dass die Kopie erfolgreich war.
- Gib das Ergebnis des Verleichs sowie die ursprüngliche und die kopierte Zeichenkette aus.

---

## 2.4. Zeichenketten verarbeiten

| **Vorgabe**         | **Beschreibung**                                                 |
| :------------------ | :--------------------------------------------------------------- |
| **Lernziele**       | Verstehen wie Strings deklariert und initialisiert werden können |
|                     | Kann Strings von der Konsole einlesen und ausgeben               |
|                     | Kann Stringfunktionen einsetzen                                  |
| **Sozialform**      | Einzelarbeit                                                     |
| **Auftrag**         | siehe unten                                                      |
| **Hilfsmittel**     |                                                                  |
| **Zeitbedarf**      | 30min                                                            |
| **Lösungselemente** | Funktionierendes Programm                                        |

Schreiben Sie ein C-Programm, das Folgendes tut:

- Liest zwei Zeichenketten (Strings) vom Benutzer ein.
- Gibt beide Strings auf der Konsole aus.
- Vergleicht die beiden Strings miteinander:
  - Falls sie gleich sind, soll "Die Strings sind gleich." ausgegeben werden.
  - Falls sie unterschiedlich sind, soll "Die Strings sind verschieden." ausgegeben werden.
  - Hängt den zweiten String an den ersten an und gibt das Ergebnis aus.
- Gibt die Länge des neuen (verketteten) Strings aus.

**Zusatzbedingung:**

- Verwenden Sie die Funktionen aus der C-Standardbibliothek: `strcmp`, `strcat`, `strlen`.
- Benutzen Sie `fgets()` zum Einlesen der Strings, um auch Leerzeichen zu unterstützen.
- Entfernen Sie den Zeilenumbruch `\n`, der durch `fgets()` mit eingelesen wird.
