|                             |                          |                               |
| --------------------------- | ------------------------ | ----------------------------- |
| **Elektrotechniker/-in HF** | **Programmiertechnik B** | ![Logo](../x_gitres/logo.png) |

- [1. Strings in C – Das zentrale Konzept](#1-strings-in-c--das-zentrale-konzept)
  - [1.1. Das Problem: Wie merkt C, wo ein String endet?](#11-das-problem-wie-merkt-c-wo-ein-string-endet)
  - [1.2. Die Lösung: Nullzeichen `'\0'`](#12-die-lösung-nullzeichen-0)
  - [1.3. String im Speicher visualisiert](#13-string-im-speicher-visualisiert)
    - [Beispiel 1: Korrekter String](#beispiel-1-korrekter-string)
    - [Beispiel 2: Zu kleiner Buffer – Buffer Overflow](#beispiel-2-zu-kleiner-buffer--buffer-overflow)
  - [1.4. Deklaration und Initialisierung](#14-deklaration-und-initialisierung)
    - [Leeres Array (nicht initialisiert)](#leeres-array-nicht-initialisiert)
    - [Mit Stringliteral (empfohlen)](#mit-stringliteral-empfohlen)
    - [Manuelle Initialisierung mit Zeichen-Array](#manuelle-initialisierung-mit-zeichen-array)
  - [1.5. Ein- und Ausgabe von Strings](#15-ein--und-ausgabe-von-strings)
    - [Ausgabe mit printf()](#ausgabe-mit-printf)
    - [Unsicher: Einlesen mit scanf()](#unsicher-einlesen-mit-scanf)
    - [Sicher: Einlesen mit fgets()](#sicher-einlesen-mit-fgets)
  - [1.6. String-Funktionen und ihre Gefahren](#16-string-funktionen-und-ihre-gefahren)
    - [Standard-Funktionen aus `<string.h>`](#standard-funktionen-aus-stringh)
    - [Beispiele – FALSCH vs. RICHTIG](#beispiele--falsch-vs-richtig)
      - [strlen()](#strlen)
      - [strcpy() – Buffer Overflow](#strcpy--buffer-overflow)
      - [strcat() – Buffer Overflow](#strcat--buffer-overflow)
  - [1.7. Häufige Fehler und ihre Folgen](#17-häufige-fehler-und-ihre-folgen)
    - [Fehler 1: Nullzeichen vergessen](#fehler-1-nullzeichen-vergessen)
    - [Fehler 2: Array zu klein](#fehler-2-array-zu-klein)
    - [Fehler 3: Ungebremste Input-Funktionen](#fehler-3-ungebremste-input-funktionen)
    - [Fehler 4: Zu grosse Operationen ohne Grössenprüfung](#fehler-4-zu-grosse-operationen-ohne-grössenprüfung)
  - [1.8. Sichere String-Patterns](#18-sichere-string-patterns)
    - [Pattern 1: Sichere String-Eingabe](#pattern-1-sichere-string-eingabe)
    - [Pattern 2: Sichere String-Kopie](#pattern-2-sichere-string-kopie)
    - [Pattern 3: Sichere String-Verkettung](#pattern-3-sichere-string-verkettung)
    - [Pattern 4: String-Länge prüfen](#pattern-4-string-länge-prüfen)
  - [1.9. Zusammenfassung](#19-zusammenfassung)
- [2. Aufgaben](#2-aufgaben)
  - [2.1. String-Speicher visualisieren](#21-string-speicher-visualisieren)
  - [2.2. Sichere String-Eingabe](#22-sichere-string-eingabe)
  - [2.3. String-Funktionen sicher verwenden](#23-string-funktionen-sicher-verwenden)
  - [2.4. String-Verarbeitung mit Sicherheitsprüfungen](#24-string-verarbeitung-mit-sicherheitsprüfungen)

---

</br>

# 1. Strings in C – Das zentrale Konzept

## 1.1. Das Problem: Wie merkt C, wo ein String endet?

**In modernen Sprachen (Java, Python, C#):** Ein String ist ein eigener Datentyp mit eingebauter Länge:

```java
// Java
String name = "Anna";  // Java speichert automatisch: Länge = 4
```

**In C:** Es gibt keinen String-Datentyp. Ein String ist nur ein Array aus Zeichen:

```c
// C
char name[] = "Anna";  // Aber wie merkt C, dass das Wort "Anna" ist?
```

**Das zentrale Problem:**

Wenn du ein Text-Array speicherst, wie weiss C, wo der Text endet? Das Array selbst kennt nur seine maximale Grösse, nicht die tatsächliche Länge der Daten.

```c
char buffer[100];
scanf("%s", buffer);  // Benutzer tippt "Hallo"
// Aber: Wie merkt printf() bei Ausgabe, dass es nach 'o' endet?
```

> **Diese Frage ist das Fundament für das Verständnis von C-Strings.**

---

## 1.2. Die Lösung: Nullzeichen `'\0'`

**C-Lösung:** Am Ende jedes Strings steht das **Nullzeichen** `'\0'`.

Das ist nicht das Zeichen "0" – es ist das Byte mit dem Wert 0 (ASCII-Null).

```c
char name[] = "Anna";
```

Im Speicher sieht das so aus:

```bash
Index:    0     1     2     3     4
Speicher: ['A']['n']['n']['a']['\0']
```

Das Nullzeichen ist **Teil des Strings**, aber es ist nicht sichtbar.

**Wichtig:** Der Array muss mindestens **Stringlänge + 1** sein für das Nullzeichen:

```c
char name[5];  // Platz für 4 Zeichen + '\0'
strcpy(name, "Anna");  // Passt: A, n, n, a, \0
```

**Alle String-Funktionen verlassen sich darauf:**

```c
strlen("Anna");         // Zählt: A, n, n, a, dann '\0' → Länge = 4
printf("%s", name);     // Gibt aus: A, n, n, a, dann '\0' → STOP
strcpy(ziel, name);     // Kopiert: A, n, n, a, dann '\0' → STOP
```

> **Das Nullzeichen ist kein "Feature" – es ist eine Notwendigkeit.** Ohne es würde C nie wissen, wo ein String endet.

---

## 1.3. String im Speicher visualisiert

### Beispiel 1: Korrekter String

```c
char vorname[10] = "Lisa";
char nachname[10] = "Müller";
```

Speicherlayout:

```bash
vorname:   ['L']['i']['s']['a']['\0'][?][?][?][?][?]
Index:      0    1    2    3    4    5   6   7   8   9

nachname:  ['M']['ü']['l']['l']['e']['r']['\0'][?][?][?]
Index:      0    1    2    3    4    5    6   7   8   9
```

Die `?` sind uninitialisierte Speicherstellen – spielen aber keine Rolle, weil `'\0'` das Ende markiert.

### Beispiel 2: Zu kleiner Buffer – Buffer Overflow

```c
char name[5];
scanf("%s", name);
// Benutzer gibt "Christopher" (11 Zeichen) ein
```

Speicherlayout während des Schreibens:

```bash
name:      ['C']['h']['r']['i']['s']['t']['o']['p']['h']['e']['r']['\0']
Index:      0    1    2    3    4    5    6    7    8    9    10   11
           ←────────────── Array-Grösse: 5 ──────────→
```

**Das ist ein KRITISCHER FEHLER!** Die Daten überschreiben den Nachbar-Speicher:

```bash
name[0-4]:     ['C']['h']['r']['i']['s']  ← Unser Array
(Nachbar):     ['t']['o']['p']['h']['e']['r']['\0']  ← Speicher danach wird kaputt!
```

**Konsequenzen:**

- Programmabsturz (Segmentation Fault)
- Sicherheitslücke (Hacker können Code ausführen)
- Unvorhersehbares Verhalten (Memory Corruption)

---

## 1.4. Deklaration und Initialisierung

### Leeres Array (nicht initialisiert)

```c
char wort[10];  // Speicherplatz für 9 Zeichen + '\0'
// Warnung: Der Inhalt ist undefiniert, bis wir Daten schreiben
```

### Mit Stringliteral (empfohlen)

```c
char text[] = "Hallo";  // Compiler bestimmt Grösse: 6 (5 Zeichen + '\0')
char text[6] = "Hallo"; // Explizite Grösse (muss ≥ Stringlänge + 1 sein)
```

> **Das Nullzeichen wird automatisch vom Compiler hinzugefügt.**

### Manuelle Initialisierung mit Zeichen-Array

```c
char text[] = {'H', 'a', 'l', 'l', 'o', '\0'};  // KORREKT: Nullzeichen explizit
char text[] = {'H', 'a', 'l', 'l', 'o'};        // FALSCH: Kein Nullzeichen!
```

Wenn das Nullzeichen fehlt:

```c
char falsch[] = {'H', 'i'};
printf("%s", falsch);  // Undefined Behavior! 
// printf() sucht nach '\0', findet es aber nicht und liest Speicher dahinter
```

---

## 1.5. Ein- und Ausgabe von Strings

### Ausgabe mit printf()

```c
char name[] = "Lisa";
printf("Name: %s\n", name);  // %s gibt den String aus, stoppt bei '\0'
```

### Unsicher: Einlesen mit scanf()

```c
char eingabe[100];
scanf("%s", eingabe);  // GEFÄHRLICH: Keine Längenbegrenzung!
```

**Problem:** Wenn der Benutzer länger tippt, überschreitet er die Array-Grösse → Buffer Overflow.

```c
scanf("%99s", eingabe);  // Besser: Max. 99 Zeichen + '\0' = 100 Total
```

### Sicher: Einlesen mit fgets()

```c
char zeile[100];
if (fgets(zeile, 100, stdin) != NULL) {
    // fgets() liest max. 99 Zeichen + '\0'
    // Achtung: Enthält auch '\n', falls Platz ist
    
    // Zeilenumbruch entfernen (optional)
    size_t len = strlen(zeile);
    if (len > 0 && zeile[len-1] == '\n') {
        zeile[len-1] = '\0';
    }
} else {
    printf("Fehler beim Lesen\n");
}
```

> **fgets() ist die sichere Wahl**, weil sie eine Längenbegrenzung erzwingt.

---

## 1.6. String-Funktionen und ihre Gefahren

### Standard-Funktionen aus `<string.h>`

| **Funktion**               | **Beschreibung**               | **Sicher?**                |
| -------------------------- | ------------------------------ | -------------------------- |
| `strlen(s)`                | Länge des Strings (ohne `\0`)  | Ja                         |
| `strcpy(ziel, quelle)`     | Kopieren ohne Längenbegrenzung | **Nein** – Buffer Overflow |
| `strncpy(ziel, quelle, n)` | Kopieren mit Limit             | Besser                     |
| `strcat(ziel, quelle)`     | Anhängen ohne Längenbegrenzung | **Nein** – Buffer Overflow |
| `strncat(ziel, quelle, n)` | Anhängen mit Limit             | Besser                     |
| `strcmp(s1, s2)`           | Vergleich                      | Ja                         |
| `strncmp(s1, s2, n)`       | Vergleich erste n Zeichen      | Ja                         |
| `strchr(s, c)`             | Erste Stelle von c             | Ja                         |
| `strstr(s1, s2)`           | Substring suchen               | Ja                         |

### Beispiele – FALSCH vs. RICHTIG

#### strlen()

```c
// RICHTIG
char name[] = "Anna";
int len = strlen(name);  // len = 4
printf("Länge: %d\n", len);

// FALSCH
char falsch[] = {'H', 'i'};  // Kein '\0'!
int len = strlen(falsch);    // Undefined Behavior – liest über Array hinaus
```

#### strcpy() – Buffer Overflow

```c
// FALSCH
char dest[10];
strcpy(dest, "Dies ist ein sehr langer String");  // Buffer Overflow!

// RICHTIG
char dest[10];
strncpy(dest, "Dies ist ein sehr langer String", 9);  // Max 9 Zeichen
dest[9] = '\0';  // Sicherstellen, dass Nullzeichen am Ende ist
```

#### strcat() – Buffer Overflow

```c
// FALSCH
char full[20] = "Hallo ";
strcat(full, "das ist ein sehr langer Text");  // Zu viele Zeichen!

// RICHTIG
char full[20] = "Hallo ";
strncat(full, "das ist ...", 20 - strlen(full) - 1);  // Berechne verfügbaren Platz
```

---

## 1.7. Häufige Fehler und ihre Folgen

### Fehler 1: Nullzeichen vergessen

```c
// FALSCH
char s[5] = {'H', 'a', 'l', 'l', 'o'};  // Kein '\0'
strlen(s);   // Undefined Behavior
printf("%s", s);  // Undefined Behavior – liest über Array hinaus
```

**Folge:** Speicher wird überlesen, Programme stürzen ab oder zeigen Garbage.

---

### Fehler 2: Array zu klein

```c
// FALSCH
char name[5] = "Hello";  // "Hello" = 5 Zeichen + '\0' = 6 Bytes nötig
// Der String passt nicht! Nullzeichen wird ausserhalb geschrieben.

// RICHTIG
char name[6] = "Hello";  // 5 + '\0' = 6
```

---

### Fehler 3: Ungebremste Input-Funktionen

```c
// FALSCH
char buffer[100];
scanf("%s", buffer);  // Benutzer könnte 1000 Zeichen eingeben

gets(buffer);  // ULTRA-GEFÄHRLICH – Immer Buffer Overflow

// RICHTIG
scanf("%99s", buffer);    // Max 99 + '\0'

fgets(buffer, 100, stdin);  // Max 99 + '\0'
```

---

### Fehler 4: Zu grosse Operationen ohne Grössenprüfung

```c
// FALSCH
char a[10] = "Hallo";
char b[10] = "Welt";
strcat(a, b);  // a hat nur 10 Bytes, "HalloWelt" braucht 10 + '\0' = 11!

// RICHTIG
char a[20] = "Hallo";  // Genug Platz für "Hallo" + "Welt" + '\0'
strncat(a, b, 20 - strlen(a) - 1);
```

---

## 1.8. Sichere String-Patterns

### Pattern 1: Sichere String-Eingabe

```c
#define MAX_LEN 100

char buffer[MAX_LEN];

// Sichere Eingabe mit fgets()
if (fgets(buffer, MAX_LEN, stdin) != NULL) {
    // Zeilenumbruch entfernen
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len-1] == '\n') {
        buffer[len-1] = '\0';
    }
    printf("Du hast eingegeben: %s\n", buffer);
} else {
    printf("Fehler beim Lesen\n");
    return -1;
}
```

### Pattern 2: Sichere String-Kopie

```c
// Alte Weise (unsicher)
strcpy(dest, src);

// Neue Weise (sicher)
strncpy(dest, src, sizeof(dest) - 1);
dest[sizeof(dest) - 1] = '\0';
```

### Pattern 3: Sichere String-Verkettung

```c
char full[100] = "Hallo ";
char addon[] = "Welt";

// Berechne verfügbaren Platz
size_t available = sizeof(full) - strlen(full) - 1;
strncat(full, addon, available);

// oder noch sicherer: prüfe vorher
if (strlen(full) + strlen(addon) < sizeof(full)) {
    strcat(full, addon);
} else {
    printf("Warnung: String würde zu lang\n");
}
```

### Pattern 4: String-Länge prüfen

```c
#define MIN_LEN 3
#define MAX_LEN 50

char password[MAX_LEN];
fgets(password, MAX_LEN, stdin);

size_t len = strlen(password);
if (len < MIN_LEN) {
    printf("Zu kurz: min. %d Zeichen\n", MIN_LEN);
    return -1;
} else if (len > MAX_LEN - 1) {
    printf("Zu lang: max. %d Zeichen\n", MAX_LEN - 1);
    return -1;
}
```

---

## 1.9. Zusammenfassung

| **Konzept**                 | **Wichtigste Punkte**                                               |
| --------------------------- | ------------------------------------------------------------------- |
| **Was ist ein String?**     | Array aus `char` mit `'\0'` am Ende                                 |
| **Warum Nullzeichen?**      | C braucht ein Endezeichen, weil es keine eingebaute Länge speichert |
| **Array-Grösse**            | Mindestens `Stringlänge + 1` für `'\0'`                             |
| **Gefahr: Buffer Overflow** | Zu viele Daten in Array schreiben → Speicher-Corruption             |
| **Sichere Eingabe**         | `fgets()` statt `scanf()` oder `gets()`                             |
| **Sichere Funktionen**      | `strncpy()`, `strncat()` statt `strcpy()`, `strcat()`               |
| **Immer prüfen**            | Zeilenumbruch entfernen, Längenbegrenzung nutzen                    |

---

# 2. Aufgaben

## 2.1. String-Speicher visualisieren

| **Vorgabe**         | **Beschreibung**                                          |
| :------------------ | :-------------------------------------------------------- |
| **Lernziele**       | Kann beschreiben, wie Strings im Speicher angeordnet sind |
|                     | Versteht die Rolle des Nullzeichens                       |
|                     | Kann Buffer-Grössen richtig berechnen                     |
| **Sozialform**      | Einzelarbeit                                              |
| **Auftrag**         | siehe unten                                               |
| **Hilfsmittel**     | Papier/Zeichenprogramm, Editor                            |
| **Zeitbedarf**      | 25min                                                     |
| **Lösungselemente** | Speicher-Visualisierung mit Adressen und Werten           |

Schreibe ein C-Programm:

```c
#include <stdio.h>
#include <string.h>

int main() {
    char vorname[10] = "Anna";
    char nachname[10] = "Müller";
    char platz[20];
    
    printf("Länge von vorname: %d\n", (int)strlen(vorname));
    printf("Länge von nachname: %d\n", (int)strlen(nachname));
    
    printf("Adresse von vorname: %p\n", (void *)vorname);
    printf("Adresse von nachname: %p\n", (void *)nachname);
    
    return 0;
}
```

Führe das Programm aus und dokumentiere:

1. Speicher-Layout aller drei Arrays (Index 0–19, mit Inhalt und `\0`)
2. Berechne für jede Variable: Wie viel Platz ist noch frei?
3. Erkläre: Warum braucht "Anna" (4 Zeichen) ein Array der Grösse 5?

---

## 2.2. Sichere String-Eingabe

| **Vorgabe**         | **Beschreibung**                                      |
| :------------------ | :---------------------------------------------------- |
| **Lernziele**       | Kann sichere String-Eingabe mit fgets() nutzen        |
|                     | Versteht die Gefahr von scanf() ohne Längenbegrenzung |
|                     | Kann Zeilenumbrüche entfernen                         |
| **Sozialform**      | Einzelarbeit                                          |
| **Auftrag**         | siehe unten                                           |
| **Hilfsmittel**     | Editor, Compiler                                      |
| **Zeitbedarf**      | 20min                                                 |
| **Lösungselemente** | Funktionierendes Programm, das sichere Eingabe zeigt  |

Schreibe zwei Versionen eines Eingabe-Programms:

**Version 1 (unsicher):**

```c
char buffer[10];
scanf("%s", buffer);  // Keine Längenbegrenzung – warum ist das falsch?
printf("Du hast eingegeben: %s\n", buffer);
```

**Version 2 (sicher):**

```c
char buffer[10];
if (fgets(buffer, 10, stdin) != NULL) {
    // Entferne Zeilenumbruch
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len-1] == '\n') {
        buffer[len-1] = '\0';
    }
    printf("Du hast eingegeben: %s\n", buffer);
}
```

Teste beide:

- Normale Eingabe ("Hallo")
- Lange Eingabe ("Das ist ein sehr langer Text")

Beobachte und dokumentiere: Was passiert bei der unsicheren Version?

---

## 2.3. String-Funktionen sicher verwenden

| **Vorgabe**         | **Beschreibung**                            |
| :------------------ | :------------------------------------------ |
| **Lernziele**       | Kann strcpy() vs. strncpy() unterscheiden   |
|                     | Kann Längenbegrenzungen richtig anwenden    |
|                     | Versteht Buffer Overflow und seine Folgen   |
| **Sozialform**      | Partnerarbeit                               |
| **Auftrag**         | siehe unten                                 |
| **Hilfsmittel**     | Editor, Compiler, die Fehler-Beispiele oben |
| **Zeitbedarf**      | 30min                                       |
| **Lösungselemente** | Korrigiertes Programm mit Erklärung         |

Hier ist Code mit 3 Buffer-Overflow-Fehlern. Finde und behebe sie:

```c
#include <stdio.h>
#include <string.h>

int main() {
    // Fehler 1: Zu kleine Array
    char name[5];
    strcpy(name, "Christopher");  // 12 Zeichen in 5 Bytes – Overflow!
    
    // Fehler 2: strcat ohne Längenbegrenzung
    char full[20] = "Hallo ";
    char addon[] = "das ist ein Text";
    strcat(full, addon);  // Passt nicht!
    
    // Fehler 3: scanf ohne Limit
    char input[10];
    scanf("%s", input);  // Benutzer könnte 100 Zeichen eingeben
    
    printf("%s\n", full);
    return 0;
}
```

Schreibe die sichere Version mit `strncpy()`, `strncat()`, und `fgets()`.

---

## 2.4. String-Verarbeitung mit Sicherheitsprüfungen

| **Vorgabe**         | **Beschreibung**                                        |
| :------------------ | :------------------------------------------------------ |
| **Lernziele**       | Kann komplette String-Operationen sicher implementieren |
|                     | Kann Längen vorab prüfen                                |
|                     | Versteht sichere String-Verkettung                      |
| **Sozialform**      | Einzelarbeit                                            |
| **Auftrag**         | siehe unten                                             |
| **Hilfsmittel**     | Editor, die Pattern oben                                |
| **Zeitbedarf**      | 30min                                                   |
| **Lösungselemente** | Funktionierendes Programm mit Sicherheitsprüfungen      |

Schreibe ein Programm, das folgendes tut:

1. Lese zwei Strings sichere (max. 50 Zeichen je)
2. Gib beide aus
3. Vergleiche mit `strcmp()`
4. Verkettet beide mit `strcat()` – ABER: Prüfe vorher, ob genug Platz ist
5. Wenn nicht genug Platz: Fehlermeldung statt Crash

**Zusatz-Anforderung:**

- Verwende `fgets()` für Eingabe (nicht `scanf()`)
- Entferne Zeilenumbrüche
- Nutze `strlen()` zum Platz-Berechnen

---

© 2026 Lukas Müller – Licensed under CC BY-NC-ND 4.0
See [LICENSE](../license.md) file for details.
