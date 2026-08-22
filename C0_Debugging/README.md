|                             |                          |                               |
| --------------------------- | ------------------------ | ----------------------------- |
| **Elektrotechniker/-in HF** | **Programmiertechnik B** | ![Logo](../x_gitres/logo.png) |

- [1. Fehler in C](#1-fehler-in-c)
  - [1.1. Arten von Fehlern](#11-arten-von-fehlern)
  - [1.2. Compilerfehler verstehen](#12-compilerfehler-verstehen)
    - [Häufige Compilerfehler](#häufige-compilerfehler)
      - [**1. Undefined Reference**](#1-undefined-reference)
      - [**2. Storage Size Not Known**](#2-storage-size-not-known)
      - [**3. Syntax Error**](#3-syntax-error)
  - [1.3. Compilerwarnungen ernst nehmen](#13-compilerwarnungen-ernst-nehmen)
    - [Flag zum Aktivieren von Warnungen](#flag-zum-aktivieren-von-warnungen)
    - [Häufige Warnungen](#häufige-warnungen)
      - [**1. Implicit Function Declaration**](#1-implicit-function-declaration)
      - [**2. Comparison Between Signed and Unsigned Integer**](#2-comparison-between-signed-and-unsigned-integer)
      - [**3. Unused Variable**](#3-unused-variable)
  - [1.4. Runtime-Fehler und undefined Behavior](#14-runtime-fehler-und-undefined-behavior)
    - [Undefined Behavior (Undefiniertes Verhalten)](#undefined-behavior-undefiniertes-verhalten)
  - [1.5. Segmentation Fault (Speicherfehler)](#15-segmentation-fault-speicherfehler)
    - [Häufige Ursachen](#häufige-ursachen)
      - [**1. Nullzeiger dereferenzieren**](#1-nullzeiger-dereferenzieren)
      - [**2. Speicher nach free() verwenden**](#2-speicher-nach-free-verwenden)
      - [**3. Stack-Speicher vergessen**](#3-stack-speicher-vergessen)
  - [1.6. Buffer Overflow (Pufferüberfluss)](#16-buffer-overflow-pufferüberfluss)
    - [Beispiel](#beispiel)
    - [Behebung: Längenbeschränkung verwenden](#behebung-längenbeschränkung-verwenden)
  - [1.7. Null-Pointer Dereference](#17-null-pointer-dereference)
  - [1.8. Speicherlecks (Memory Leaks)](#18-speicherlecks-memory-leaks)
    - [Beispiel Speicherlecks](#beispiel-speicherlecks)
    - [Behebung: Immer free() verwenden](#behebung-immer-free-verwenden)
- [2. Debugging-Techniken](#2-debugging-techniken)
  - [2.1. printf()-Debugging](#21-printf-debugging)
  - [2.2. Der GNU Debugger (GDB)](#22-der-gnu-debugger-gdb)
    - [Kompilieren mit Debug-Informationen](#kompilieren-mit-debug-informationen)
    - [GDB starten](#gdb-starten)
    - [Wichtige GDB-Befehle](#wichtige-gdb-befehle)
    - [Beispiel-Session](#beispiel-session)
  - [2.3. Speicherfehler mit Valgrind finden](#23-speicherfehler-mit-valgrind-finden)
    - [Installation (Linux)](#installation-linux)
    - [Programm mit Valgrind ausführen](#programm-mit-valgrind-ausführen)
    - [Ausgabe-Beispiel (Memory Leak)](#ausgabe-beispiel-memory-leak)
  - [2.4. Compilerflaggen nutzen](#24-compilerflaggen-nutzen)
    - [Sicherste Einstellungen](#sicherste-einstellungen)
    - [Mit Debug und Optimierung](#mit-debug-und-optimierung)
- [3. Best Practices](#3-best-practices)
  - [Immer tun](#immer-tun)
    - [Nie tun](#nie-tun)
- [4. Aufgaben](#4-aufgaben)
  - [4.1. Fehler identifizieren](#41-fehler-identifizieren)
  - [4.2. Mit GDB debuggen](#42-mit-gdb-debuggen)

---

</br>

# 1. Fehler in C

## 1.1. Arten von Fehlern

In C gibt es drei Kategorien von Fehlern:

| **Fehlertyp**         | **Zeitpunkt**        | **Beispiel**                                      |
| --------------------- | -------------------- | ------------------------------------------------- |
| **Compilerfehler**    | Beim Kompilieren     | Undefined reference, Syntax-Fehler                |
| **Compilerwarnungen** | Beim Kompilieren     | Implizite Typ-Konvertierung, ungenutzter Variable |
| **Runtime-Fehler**    | Während Programmlauf | Segmentation Fault, Speicherleck                  |

---

## 1.2. Compilerfehler verstehen

**Compilerfehler verhindern, dass das Programm überhaupt erstellt wird.**

### Häufige Compilerfehler

#### **1. Undefined Reference**

```bash
error: undefined reference to `sqrt'
```

**Ursache:** Funktion ist nicht bekannt – wahrscheinlich Header oder Bibliothek fehlt.

**Lösung:**

```c
#include <math.h>   // Header einbinden
// und beim Kompilieren: gcc programm.c -o programm -lm
```

#### **2. Storage Size Not Known**

```bash
error: storage size of 'x' isn't known
```

**Ursache:** Datentyp ist unvollständig.

```c
// FALSCH:
struct Student s;  // struct Student ist nicht definiert!

// RICHTIG:
struct Student {
    int id;
    char name[50];
};
struct Student s;
```

#### **3. Syntax Error**

```bash
error: expected ';' before '}'
```

**Ursache:** Semikolon oder Klammer vergessen.

```c
// FALSCH:
int x = 5    // Semikolon fehlt!

// RICHTIG:
int x = 5;
```

---

## 1.3. Compilerwarnungen ernst nehmen

**Warnungen sind KEIN Fehler – aber oft ein Zeichen für schlechten Code.**

### Flag zum Aktivieren von Warnungen

```bash
gcc -Wall -Wextra programm.c -o programm
```

- `-Wall` = Warnen vor "unsicherem" Code
- `-Wextra` = Noch mehr Warnungen

### Häufige Warnungen

#### **1. Implicit Function Declaration**

```bash
warning: implicit declaration of function 'printf'
```

**Ursache:** Header nicht eingebunden.

```c
// FALSCH:
main() {
    printf("Hallo");  // stdio.h fehlt!
}

// RICHTIG:
#include <stdio.h>

int main() {
    printf("Hallo");
    return 0;
}
```

#### **2. Comparison Between Signed and Unsigned Integer**

```bash
warning: comparison between signed and unsigned integer expressions
```

**Ursache:** Verschiedene Typen verglichen.

```c
// FALSCH:
int x = -5;
size_t n = 10;
if (x < n) {  // int vs. size_t
    // ...
}

// RICHTIG:
if (x < (int)n) {
    // ...
}
```

#### **3. Unused Variable**

```bash
warning: unused variable 'temp'
```

**Ursache:** Variable wird definiert, aber nie verwendet.

```c
// FALSCH:
int main() {
    int temp = 5;  // nie verwendet
    return 0;
}

// RICHTIG: Variable löschen oder verwenden
int main() {
    printf("Wert: %d\n", 5);
    return 0;
}
```

---

## 1.4. Runtime-Fehler und undefined Behavior

**Runtime-Fehler passieren, während das Programm läuft.**

### Undefined Behavior (Undefiniertes Verhalten)

Das ist der Feind: Der C-Standard sagt "Dieses Verhalten ist nicht definiert" → Das Programm kann **alles** machen.

```c
// Beispiele von Undefined Behavior:
int arr[10];
arr[100] = 5;              // Array-Zugriff außerhalb
int *ptr;
*ptr = 5;                  // Zeiger nicht initialisiert
char s[5];
strcpy(s, "Hallo Welt");   // Buffer Overflow
```

---

## 1.5. Segmentation Fault (Speicherfehler)

**Segmentation Fault (SIGSEGV) = Das Programm versucht auf ungültigen Speicher zuzugreifen.**

### Häufige Ursachen

#### **1. Nullzeiger dereferenzieren**

```c
int *ptr = NULL;
printf("%d", *ptr);  // Fehler! NULL ist keine gültige Adresse
```

**Behebung:**

```c
int *ptr = NULL;
if (ptr != NULL) {
    printf("%d", *ptr);
} else {
    printf("Fehler: Zeiger ist NULL\n");
}
```

#### **2. Speicher nach free() verwenden**

```c
int *ptr = malloc(sizeof(int));
free(ptr);
printf("%d", *ptr);  // Fehler! Speicher ist freigegeben
```

**Behebung:**

```c
int *ptr = malloc(sizeof(int));
// ... verwenden ...
free(ptr);
ptr = NULL;         // Best Practice: Nach free() NULL setzen
```

#### **3. Stack-Speicher vergessen**

```c
int *get_value() {
    int x = 5;
    return &x;      // Fehler! x wird freigegeben, wenn Funktion endet
}

int main() {
    int *ptr = get_value();
    printf("%d", *ptr);  // Undefined Behavior
}
```

**Behebung:** Daten kopieren oder Stack-Variablen verwenden.

---

## 1.6. Buffer Overflow (Pufferüberfluss)

**Buffer Overflow = Zu viele Daten in einen Array schreiben.**

### Beispiel

```c
char name[10];
scanf("%s", name);   // Wenn Benutzer 20 Zeichen eingibt → Fehler!
```

Der Speicher nach `name` wird überschrieben:

```bash
Speicher:   [n][a][m][e][0][?][?][?][?][?][garbage][garbage]...
Index:      0   1   2   3   4   5   6   7   8   9   10       11
```

**Das ist eine **kritische Sicherheitslücke**.**

### Behebung: Längenbeschränkung verwenden

```c
char name[10];
scanf("%9s", name);   // Maximum 9 Zeichen + '\0'

// oder besser:
char name[10];
if (fgets(name, 10, stdin) != NULL) {
    // ...
}
```

---

## 1.7. Null-Pointer Dereference

**Null-Pointer Dereference = Zugriff auf einen NULL-Zeiger.**

```c
// Schlecht:
struct Student *s = NULL;
printf("%s", s->name);  // Segmentation Fault!

// Besser:
struct Student *s = NULL;
if (s != NULL) {
    printf("%s", s->name);
} else {
    printf("Fehler: Student ist NULL\n");
}
```

**Best Practice:** Immer prüfen, ob ein Zeiger NULL ist, bevor man ihn dereferenziert.

---

## 1.8. Speicherlecks (Memory Leaks)

**Memory Leak = Speicher wird reserviert, aber nie freigegeben.**

### Beispiel Speicherlecks

```c
int main() {
    int *arr = malloc(1000 * sizeof(int));
    // ... verwenden ...
    // Aber: free(arr) FEHLT!
    return 0;
}
```

Nach dem Programm ist der Speicher immer noch reserviert (verschwendet).

**Über Zeit:**

- Kleines Programm = Kleines Problem
- Server, der Jahre läuft = **Großes Problem** (irgendwann läuft der Speicher voll)

### Behebung: Immer free() verwenden

```c
int main() {
    int *arr = malloc(1000 * sizeof(int));
    // ... verwenden ...
    free(arr);         // Speicher freigeben
    arr = NULL;        // Best Practice: NULL setzen
    return 0;
}
```

**Pattern:**

```c
// Speichern
TYPE *ptr = malloc(SIZE);
if (ptr == NULL) {
    // Fehler!
    return -1;
}

// Verwenden
...

// Freigeben
free(ptr);
ptr = NULL;
```

---

# 2. Debugging-Techniken

## 2.1. printf()-Debugging

Die einfachste Methode: Werte ausgeben.

```c
int add(int a, int b) {
    printf("DEBUG: add(%d, %d)\n", a, b);
    int result = a + b;
    printf("DEBUG: Ergebnis = %d\n", result);
    return result;
}
```

**Vorteil:** Einfach, überall nutzbar  
**Nachteil:** Umständlich, Code wird hässlich

---

## 2.2. Der GNU Debugger (GDB)

Mit GDB kannst du ein Programm **Schritt für Schritt** durchlaufen.

### Kompilieren mit Debug-Informationen

```bash
gcc -g -Wall programm.c -o programm
```

Flag `-g` speichert Debug-Informationen.

### GDB starten

```bash
gdb ./programm
```

### Wichtige GDB-Befehle

| Befehl       | Effekt                             |
| ------------ | ---------------------------------- |
| `break main` | Haltepunkt bei main setzen         |
| `run`        | Programm starten                   |
| `next`       | Nächste Zeile ausführen            |
| `step`       | In Funktion hineinspringen         |
| `continue`   | Weiter bis zum nächsten Haltepunkt |
| `print x`    | Wert von x anzeigen                |
| `backtrace`  | Stack-Trace zeigen                 |
| `quit`       | GDB verlassen                      |

### Beispiel-Session

```bash
(gdb) break main
Breakpoint 1 at 0x401040
(gdb) run
Starting program: ./programm
Breakpoint 1, main () at programm.c:10
10 int x = 5;
(gdb) next
11 int y = add(x, 10);
(gdb) print x
$1 = 5
(gdb) step
add (a=5, b=10) at programm.c:3
3 int result = a + b;
(gdb) print result
$2 = 0
(gdb) continue
```

---

## 2.3. Speicherfehler mit Valgrind finden

Valgrind ist ein Tool, das automatisch Speicherlecks und Zugriffsfehler erkennt.

### Installation (Linux)

```bash
sudo apt install valgrind
```

### Programm mit Valgrind ausführen

```bash
valgrind --leak-check=full ./programm
```

### Ausgabe-Beispiel (Memory Leak)

```bash
==12345== 40 bytes in 1 blocks are definitely lost in loss record 1 of 1
==12345==    at 0x483B723: malloc (vg_replace_malloc.c:309)
==12345==    by 0x401234: main (programm.c:5)
==12345==
==12345== LEAK SUMMARY:
==12345==    definitely lost: 40 bytes in 1 blocks
```

Das sagt: 40 Bytes wurden mit `malloc()` reserviert (Zeile 5), aber nie freigegeben.

---

## 2.4. Compilerflaggen nutzen

### Sicherste Einstellungen

```bash
gcc -Wall -Wextra -std=c99 -pedantic programm.c -o programm
```

- `-Wall` = Viele Warnungen
- `-Wextra` = Noch mehr Warnungen
- `-std=c99` = Verwende C99 Standard
- `-pedantic` = Strict Standard-Konformität

### Mit Debug und Optimierung

```bash
gcc -g -O0 -Wall -Wextra programm.c -o programm
```

- `-g` = Debug-Symbole
- `-O0` = Keine Optimierung (besser zum Debuggen)

---

# 3. Best Practices

## Immer tun

```c
// 1. Compilerwarnungen aktivieren
gcc -Wall -Wextra programm.c -o programm

// 2. Rückgabewerte prüfen
int *ptr = malloc(sizeof(int));
if (ptr == NULL) {
    printf("Fehler: malloc fehlgeschlagen\n");
    return -1;
}

// 3. Speicher freigeben
free(ptr);
ptr = NULL;

// 4. Zeiger vor Verwendung prüfen
if (ptr != NULL) {
    printf("%d", *ptr);
}

// 5. Mit scanf: Länge begrenzen
char name[50];
scanf("%49s", name);  // Max 49 + '\0'

// 6. Mit Strings: fgets verwenden
char line[100];
if (fgets(line, 100, stdin) != NULL) {
    // ...
}
```

### Nie tun

```c
// ❌ gets() verwenden – immer Buffer Overflow
gets(buffer);

// ❌ strcpy() ohne Längenbeschränkung
strcpy(dest, src);  // Besser: strncpy()

// ❌ Speicher reservieren, aber nicht freigeben
int *ptr = malloc(1000);

// ❌ Zeiger nach free() verwenden
free(ptr);
printf("%d", *ptr);  // Fehler!

// ❌ Adresse lokaler Variablen zurückgeben
int *get_ptr() {
    int x = 5;
    return &x;  // x wird freigegeben!
}
```

---

# 4. Aufgaben

## 4.1. Fehler identifizieren

| **Vorgabe**         | **Beschreibung**                              |
| :------------------ | :-------------------------------------------- |
| **Lernziele**       | Kann Speicherfehler in Code identifizieren    |
|                     | Versteht Buffer Overflow und Null-Pointer     |
|                     | Kann Buffer Overflow und Memory Leaks beheben |
| **Sozialform**      | Partnerarbeit                                 |
| **Auftrag**         | siehe unten                                   |
| **Hilfsmittel**     | Die Fehlerliste oben, Editor                  |
| **Zeitbedarf**      | 20min                                         |
| **Lösungselemente** | Korrigierter Code mit Erklärung               |

Hier sind 5 C-Programme mit Fehlern. Finde jeden Fehler und erkläre, warum es falsch ist:

**Programm 1:**

```c
#include <stdio.h>
int *get_value() {
    int x = 5;
    return &x;
}
int main() {
    int *ptr = get_value();
    printf("%d", *ptr);
}
```

**Programm 2:**

```c
#include <stdio.h>
int main() {
    int *ptr = NULL;
    *ptr = 5;
    printf("%d", *ptr);
}
```

**Programm 3:**

```c
#include <stdio.h>
#include <string.h>
int main() {
    char name[5];
    strcpy(name, "Hallo Welt");  // 11 Zeichen!
    printf("%s", name);
}
```

**Programm 4:**

```c
#include <stdlib.h>
int main() {
    int *arr = malloc(100 * sizeof(int));
    arr[0] = 5;
    // free(arr) FEHLT
    return 0;
}
```

**Programm 5:**

```c
#include <stdio.h>
int main() {
    char line[10];
    scanf("%s", line);  // Keine Längenbegrenzung!
    printf("%s", line);
}
```

---

## 4.2. Mit GDB debuggen

| **Vorgabe**         | **Beschreibung**                                       |
| :------------------ | :----------------------------------------------------- |
| **Lernziele**       | Kann GDB verwenden                                     |
|                     | Kann Haltepunkte setzen und Variablen überprüfen       |
|                     | Kann ein Programm Schritt-für-Schritt durchlaufen      |
| **Sozialform**      | Einzelarbeit                                           |
| **Auftrag**         | siehe unten                                            |
| **Hilfsmittel**     | GDB, ein Editor                                        |
| **Zeitbedarf**      | 30min                                                  |
| **Lösungselemente** | GDB-Session dokumentieren (Screenshots oder Abschrift) |

Schreibe ein Programm mit einem Fehler:

```c
#include <stdio.h>

int multiply(int a, int b) {
    int result = a * b;
    return result;
}

int main() {
    int x = 5;
    int y = 10;
    int z = multiply(x, y);
    printf("Ergebnis: %d\n", z);
    return 0;
}
```

Nutze GDB, um:

1. Ein Haltepunkt bei `main` setzen
2. Das Programm starten
3. Schritt-für-Schritt durch die Funktion `multiply()` gehen
4. Die Werte von `a`, `b`, und `result` ausgeben

Dokumentiere die GDB-Befehle und die Ausgabe.

---

© 2026 Lukas Müller – Licensed under CC BY-NC-ND 4.0
