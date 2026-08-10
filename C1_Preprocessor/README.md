|                             |                          |                               |
| --------------------------- | ------------------------ | ----------------------------- |
| **Elektrotechniker/-in HF** | **Programmiertechnik B** | ![Logo](../x_gitres/logo.png) |

- [1. Präprozessor](#1-präprozessor)
  - [1.1. Was macht der Präprozessor?](#11-was-macht-der-präprozessor)
  - [1.2. Der Übersetzungsvorgang im Überblick](#12-der-übersetzungsvorgang-im-überblick)
  - [1.3. `#include` – Dateien einbinden](#13-include--dateien-einbinden)
  - [1.4. `#define` – symbolische Konstanten](#14-define--symbolische-konstanten)
  - [1.5. `#define` – Makros mit Parametern](#15-define--makros-mit-parametern)
  - [1.6. Die Klammerfalle bei Makros](#16-die-klammerfalle-bei-makros)
  - [1.7. Bedingte Kompilierung `#ifdef` / `#ifndef`](#17-bedingte-kompilierung-ifdef--ifndef)
  - [1.8. Include-Guards](#18-include-guards)
  - [1.9. Vordefinierte Makros](#19-vordefinierte-makros)
  - [1.10. Präprozessor-Ausgabe sichtbar machen](#110-präprozessor-ausgabe-sichtbar-machen)
- [2. Das Schlüsselwort `const`](#2-das-schlüsselwort-const)
  - [2.1. Sinn und Zweck](#21-sinn-und-zweck)
  - [2.2. Konstante Variablen](#22-konstante-variablen)
  - [2.3. `const` bei Funktionsparametern](#23-const-bei-funktionsparametern)
  - [2.4. `const` und Pointer – die drei Varianten](#24-const-und-pointer--die-drei-varianten)
  - [2.5. `const` vs. `#define`](#25-const-vs-define)
- [3. Zusammenfassung](#3-zusammenfassung)
- [4. Aufgaben](#4-aufgaben)
  - [4.1. Aufgabe Präprozessor-Ausgabe analysieren](#41-aufgabe-präprozessor-ausgabe-analysieren)
  - [4.2. Aufgabe Makros mit Parametern](#42-aufgabe-makros-mit-parametern)
  - [4.3. Aufgabe Debug-Schalter mit bedingter Kompilierung](#43-aufgabe-debug-schalter-mit-bedingter-kompilierung)
  - [4.4. Aufgabe const korrekt einsetzen](#44-aufgabe-const-korrekt-einsetzen)

---

</br>

# 1. Präprozessor

## 1.1. Was macht der Präprozessor?

Wir haben bereits mit `#include` und `#define` gearbeitet – aber was passiert dabei eigentlich?

> Der **Präprozessor** ist ein Programm, das **vor** dem eigentlichen Compiler läuft. Er bearbeitet den Quelltext rein **textuell**: Er sucht nach Zeilen, die mit `#` beginnen, und ersetzt sie nach festen Regeln.

**Wichtig:** Der Präprozessor kennt **kein C**. Er versteht keine Variablen, keine Typen, keine Funktionen. Er sucht und ersetzt nur Text – wie „Suchen und Ersetzen" in einem Texteditor.

Alle Präprozessor-Anweisungen beginnen mit `#` und stehen jeweils auf einer **eigenen Zeile** ohne Semikolon:

```c
#include <stdio.h>
#define MAX 100
#ifdef DEBUG
```

## 1.2. Der Übersetzungsvorgang im Überblick

```bash
   quelltext.c
        │
        ▼
┌─────────────────┐
│  PRÄPROZESSOR   │  → #include ersetzen, #define einsetzen,
└─────────────────┘     #ifdef auswerten, Kommentare entfernen
        │
        ▼
   reiner C-Code (keine # Zeilen mehr!)
        │
        ▼
┌─────────────────┐
│    COMPILER     │  → C-Code in Maschinencode übersetzen
└─────────────────┘     Syntaxprüfung
        │
        ▼
   Objektdatei (.o)
        │
        ▼
┌─────────────────┐
│     LINKER      │  → .o Dateien und Bibliotheken verbinden
└─────────────────┘
        │
        ▼
   ausführbares Programm
```

> **Bezug zur Modularisierung:** Die Aufgabenteilung Compiler/Linker kennen wir bereits. Der Präprozessor ist die Stufe **davor** – er bereitet den Quelltext auf, bevor der Compiler ihn überhaupt zu sehen bekommt.

## 1.3. `#include` – Dateien einbinden

`#include` fügt den **kompletten Inhalt** der angegebenen Datei an dieser Stelle ein.

```c
#include <stdio.h>     // Systempfade durchsuchen (Standardbibliotheken)
#include "modul.h"     // zuerst aktuelles Verzeichnis (eigene Header)
```

**Was der Präprozessor daraus macht:**

```bash
VORHER (quelltext.c):              NACHHER (nach Präprozessor):
──────────────────────             ────────────────────────────
#include <stdio.h>          →      int printf(const char*, ...);
                                   int scanf(const char*, ...);
                                   // ... ca. 800 weitere Zeilen ...

int main(void) {                   int main(void) {
    printf("Hallo\n");                 printf("Hallo\n");
    return 0;                          return 0;
}                                  }
```

> Aus einer Zeile `#include <stdio.h>` werden mehrere hundert Zeilen Deklarationen. Deshalb dauert das Kompilieren länger, je mehr Header eingebunden werden.

## 1.4. `#define` – symbolische Konstanten

```c
#define NAME    Ersatztext
```

Der Präprozessor ersetzt **jedes Vorkommen** von `NAME` durch `Ersatztext`:

```c
#include <stdio.h>

#define MAX_SCHUELER  30
#define PI            3.14159265
#define PROGRAMMNAME  "Notenverwaltung"

int main(void) {
    int noten[MAX_SCHUELER];              // wird zu: int noten[30];
    double flaeche = PI * 5 * 5;          // wird zu: 3.14159265 * 5 * 5
    printf("%s gestartet\n", PROGRAMMNAME);
    return 0;
}
```

**Vorteile:**

| Vorteil             | Erklärung                           |
| ------------------- | ----------------------------------- |
| Lesbarkeit          | `MAX_SCHUELER` sagt mehr als `30`   |
| Wartbarkeit         | Wert nur an **einer** Stelle ändern |
| Keine Magic Numbers | Bedeutung ist im Namen sichtbar     |

> ⚠️ **Kein Semikolon am Ende!**
>
> ```c
> #define MAX 100;     // FALSCH!
> int arr[MAX];        // wird zu: int arr[100;];  → Syntaxfehler
> ```

**Konvention:** `#define`-Namen werden in **GROSSBUCHSTABEN** geschrieben. So erkennt man beim Lesen sofort, dass es sich um eine Präprozessor-Ersetzung handelt und nicht um eine Variable.

## 1.5. `#define` – Makros mit Parametern

Ein `#define` kann auch **Parameter** entgegennehmen – man spricht dann von einem **Makro**:

```c
#define QUADRAT(x)     ((x) * (x))
#define MAX(a, b)      ((a) > (b) ? (a) : (b))
#define MIN(a, b)      ((a) < (b) ? (a) : (b))
```

```c
#include <stdio.h>

#define QUADRAT(x)  ((x) * (x))
#define MAX(a, b)   ((a) > (b) ? (a) : (b))

int main(void) {
    printf("%d\n", QUADRAT(5));      // wird zu: ((5) * (5))     → 25
    printf("%d\n", MAX(3, 7));       // wird zu: ((3)>(7)?(3):(7)) → 7
    return 0;
}
```

**Makro vs. Funktion:**

|                  | Makro                                 | Funktion                            |
| ---------------- | ------------------------------------- | ----------------------------------- |
| Verarbeitung     | Textersetzung vor Kompilierung        | Echter Funktionsaufruf zur Laufzeit |
| Typprüfung       | keine                                 | Compiler prüft Typen                |
| Geschwindigkeit  | Kein Aufruf-Overhead                  | Minimaler Overhead                  |
| Debugging        | Schwierig (Code ist ersetzt)          | Einfach (Breakpoint möglich)        |
| Typ-Flexibilität | Funktioniert mit `int`, `double`, ... | Ein Typ pro Funktion                |

> *Faustregel:** Für alles ausser sehr kurzen Ausdrücken sind **Funktionen die bessere Wahl** – sie sind typsicher und debuggbar. Makros mit Parametern sind in modernem C eher selten.

## 1.6. Die Klammerfalle bei Makros

Dies ist der **häufigste Fehler** beim Arbeiten mit Makros.

**Beispiel ohne Klammern:**

```c
#define QUADRAT(x)  x * x        // gefährlich!

int ergebnis = QUADRAT(2 + 3);
```

Der Präprozessor ersetzt **rein textuell**:

```c
int ergebnis = 2 + 3 * 2 + 3;    // = 2 + 6 + 3 = 11  ← FALSCH!
                                  // erwartet wäre: 25
```

**Korrekt – mit Klammern um jeden Parameter und um den Gesamtausdruck:**

```c
#define QUADRAT(x)  ((x) * (x))

int ergebnis = QUADRAT(2 + 3);
// wird zu:  (((2 + 3)) * ((2 + 3)))  = 5 * 5 = 25  ← RICHTIG
```

> **Regel:** In einem Makro wird **jeder Parameter** geklammert **und** der **gesamte Ausdruck** noch einmal:
>
> ```c
> #define MAKRO(a, b)  ((a) OPERATOR (b))
> //                   ↑ ↑   ↑        ↑ ↑↑
> //                   │ └───┴────────┴─┘│  jeder Parameter
> //                   └──────────────────┘  ganzer Ausdruck
> ```

**Zweite Falle – Seiteneffekte:**

```c
#define QUADRAT(x)  ((x) * (x))

int i = 5;
int r = QUADRAT(i++);       // wird zu: ((i++) * (i++))
                             // i wird ZWEIMAL erhöht! Ergebnis undefiniert.
```

> Bei einer **Funktion** würde `i++` genau einmal ausgewertet. Das ist einer der Hauptgründe, warum Funktionen den Makros vorzuziehen sind.

## 1.7. Bedingte Kompilierung `#ifdef` / `#ifndef`

Mit bedingter Kompilierung lassen sich Codeteile **je nach Bedingung ein- oder ausschliessen** – bereits vor dem Kompilieren.

```c
#ifdef  NAME      // falls NAME definiert ist
#ifndef NAME      // falls NAME NICHT definiert ist
#else             // Gegenfall
#endif            // Ende des Blocks (zwingend!)
```

**Beispiel – Debug-Ausgaben ein-/ausschalten:**

```c
#include <stdio.h>

#define DEBUG          // diese Zeile auskommentieren = Debug aus

int berechne(int a, int b) {
#ifdef DEBUG
    printf("[DEBUG] berechne() aufgerufen mit a=%d, b=%d\n", a, b);
#endif
    return a + b;
}

int main(void) {
    int ergebnis = berechne(3, 4);
    printf("Ergebnis: %d\n", ergebnis);
    return 0;
}
```

**Mit `#define DEBUG`:**

```bash
[DEBUG] berechne() aufgerufen mit a=3, b=4
Ergebnis: 7
```

**Ohne `#define DEBUG`** (Zeile auskommentiert):

```bash
Ergebnis: 7
```

> **Entscheidender Unterschied zu `if`:** Bei `#ifdef` verschwindet der Code **vollständig** aus dem Programm – er wird gar nicht erst kompiliert. Ein normales `if (debug)` würde den Code immer mitkompilieren und zur Laufzeit prüfen.

**Symbol über den Compiler definieren (statt im Code):**

```bash
gcc -DDEBUG programm.c -o programm     # DEBUG ist definiert
gcc programm.c -o programm             # DEBUG ist nicht definiert
```

> **Bezug zum Makefile:** Genau so funktioniert der Debug-Build im Makefile:
>
> ```makefile
> debug: CFLAGS += -g -DDEBUG
> ```

**Praktisches Muster – ein LOG-Makro:**

```c
#ifdef DEBUG
    #define LOG(text)  printf("[DEBUG] %s\n", text)
#else
    #define LOG(text)              // wird zu NICHTS - verschwindet komplett
#endif

int main(void) {
    LOG("Programm gestartet");     // nur sichtbar wenn DEBUG definiert
    return 0;
}
```

## 1.8. Include-Guards

Include-Guards kennen wir bereits aus der Modularisierung – hier die Einordnung im Präprozessor-Kontext:

```c
#ifndef MODUL_H        // falls MODUL_H noch NICHT definiert...
#define MODUL_H        // ...dann definiere es jetzt

// Inhalt der Header-Datei

#endif                 // Ende
```

**Ablauf bei doppelter Einbindung:**

```bash
1. #include "modul.h"  → MODUL_H nicht definiert → Inhalt wird eingefügt
                          und MODUL_H wird definiert
2. #include "modul.h"  → MODUL_H IST definiert   → Inhalt wird übersprungen
```

Ohne Guard würden alle Deklarationen doppelt eingefügt → Compilerfehler.

## 1.9. Vordefinierte Makros

Der Präprozessor stellt einige Makros automatisch bereit:

| Makro      | Bedeutung               | Beispielwert    |
| ---------- | ----------------------- | --------------- |
| `__FILE__` | Aktueller Dateiname     | `"main.c"`      |
| `__LINE__` | Aktuelle Zeilennummer   | `42`            |
| `__DATE__` | Kompilierdatum          | `"Aug 10 2026"` |
| `__TIME__` | Kompilierzeit           | `"14:23:05"`    |
| `__func__` | Aktueller Funktionsname | `"main"`        |

**Praktische Anwendung – Fehlermeldung mit Ortsangabe:**

```c
#include <stdio.h>

#define FEHLER(text)  printf("[FEHLER] %s (%s, Zeile %d)\n", \
                             text, __FILE__, __LINE__)

int main(void) {
    FEHLER("Datei konnte nicht geöffnet werden");
    return 0;
}
```

```bash
Ausgabe:
[FEHLER] Datei konnte nicht geöffnet werden (main.c, Zeile 8)
```

> Der Backslash `\` am Zeilenende setzt ein Makro über mehrere Zeilen fort.

## 1.10. Präprozessor-Ausgabe sichtbar machen

Mit `gcc -E` lässt sich anzeigen, was der Präprozessor tatsächlich produziert:

```bash
gcc -E programm.c              # gibt das Ergebnis aus (sehr lang!)
gcc -E programm.c > vorher.txt # in Datei umleiten
```

> **Tipp für die Übung:** Ein Programm **ohne** `#include` schreiben, nur mit `#define`, dann `gcc -E` ausführen. So sieht man die Ersetzungen deutlich, ohne von den 800 Zeilen aus `stdio.h` erschlagen zu werden.

---

</br>

# 2. Das Schlüsselwort `const`

## 2.1. Sinn und Zweck

> `const` markiert eine Variable als **nicht veränderbar**. Der Compiler verweigert jeden Schreibzugriff und meldet einen Fehler.

**Warum ist das nützlich?**

| Grund                 | Erklärung                                                      |
| --------------------- | -------------------------------------------------------------- |
| Fehler früh erkennen  | Versehentliche Änderung → Compilerfehler statt Laufzeitfehler  |
| Absicht dokumentieren | „Dieser Wert soll sich nicht ändern" steht direkt im Code      |
| Schnittstelle klären  | Eine Funktion zeigt, ob sie die Daten verändert oder nur liest |
| Optimierung           | Der Compiler kann besser optimieren                            |

## 2.2. Konstante Variablen

```c
const double MEHRWERTSTEUER = 0.081;
const int    MAX_VERSUCHE   = 3;

MEHRWERTSTEUER = 0.1;    // Compilerfehler: assignment of read-only variable
```

> Eine `const`-Variable **muss** bei der Deklaration initialisiert werden – später ist keine Zuweisung mehr möglich.

```c
const int x;       // sinnlos: x hat einen zufälligen Wert, der nie änderbar ist
const int y = 5;   // korrekt
```

## 2.3. `const` bei Funktionsparametern

Das ist der **wichtigste Einsatzbereich** von `const` in der Praxis.

**Ohne `const` – die Funktion könnte alles verändern:**

```c
void anzeigen(char *text) {
    printf("%s\n", text);
    text[0] = 'X';        // erlaubt! Verändert den Original-String
}
```

**Mit `const` – die Funktion garantiert, nichts zu verändern:**

```c
void anzeigen(const char *text) {
    printf("%s\n", text);
    text[0] = 'X';        // Compilerfehler – genau das wollten wir!
}
```

> **Bezug zu Strukturen:** Genau deshalb haben wir bei Anzeigefunktionen geschrieben:
>
> ```c
> void buchAnzeigen(const struct Buch *b);
> ```
>
> Der Zeiger vermeidet das Kopieren der ganzen Struktur, `const` verhindert versehentliches Ändern. Beides zusammen ist die saubere Lösung für eine reine Lesefunktion.

**Faustregel für Funktionsparameter:**

```c
void nurLesen(const Typ *daten);    // Funktion liest nur
void veraendern(Typ *daten);        // Funktion darf verändern
```

Wer die Signatur liest, weiss sofort, was die Funktion mit den Daten tut – ohne den Code anzuschauen.

## 2.4. `const` und Pointer – die drei Varianten

Bei Pointern kann `const` an **zwei Stellen** stehen – mit unterschiedlicher Bedeutung:

```c
int wert1 = 10;
int wert2 = 20;
```

**Variante 1 – Der Zeiger zeigt auf konstante Daten:**

```c
const int *p = &wert1;

*p = 99;        // Fehler: Daten sind const
p  = &wert2;    // erlaubt: Zeiger darf umgehängt werden
```

> *„Zeiger auf eine Konstante"* – der häufigste Fall, z.B. bei Funktionsparametern.

**Variante 2 – Der Zeiger selbst ist konstant:**

```c
int * const p = &wert1;

*p = 99;        // erlaubt: Daten dürfen geändert werden
p  = &wert2;    // Fehler: Zeiger darf nicht umgehängt werden
```

> *„Konstanter Zeiger"* – selten gebraucht.

**Variante 3 – Beides konstant:**

```c
const int * const p = &wert1;

*p = 99;        // Fehler
p  = &wert2;    // Fehler
```

**Merkhilfe – von rechts nach links lesen:**

```c
const int *p            →  p ist ein Zeiger auf ein const int
int * const p           →  p ist ein const Zeiger auf ein int
const int * const p     →  p ist ein const Zeiger auf ein const int
```

| Schreibweise          | Daten änderbar? | Zeiger umhängbar? |
| --------------------- | --------------- | ----------------- |
| `int *p`              | ja              | ja                |
| `const int *p`        | nein            | ja                |
| `int * const p`       | ja              | nein              |
| `const int * const p` | nein            | nein              |

## 2.5. `const` vs. `#define`

Beide erzeugen „Konstanten" – aber auf ganz unterschiedliche Weise:

```c
#define MAX_A  100        // Präprozessor: Textersetzung
const int MAX_B = 100;    // Compiler: echte Variable im Speicher
```

| Kriterium                | `#define`                            | `const`                      |
| ------------------------ | ------------------------------------ | ---------------------------- |
| Bearbeitet von           | Präprozessor                         | Compiler                     |
| Typprüfung               | keine                                | ja                           |
| Im Debugger sichtbar     | nein                                 | ja                           |
| Speicherplatz            | keiner (nur Text)                    | belegt Speicher              |
| Gültigkeitsbereich       | ab `#define` bis Dateiende           | normaler Scope (Block/Datei) |
| Als Array-Grösse nutzbar | ja                                   | nur ab C99 (VLA)             |
| Typischer Einsatz        | Array-Grössen, bedingte Kompilierung | Werte, Funktionsparameter    |

> **Empfehlung:** Für **Werte** ist `const` meist die bessere Wahl (typsicher, debuggbar). `#define` bleibt sinnvoll für Array-Grössen, bedingte Kompilierung und Makros.

---

</br>

# 3. Zusammenfassung

```bash
┌──────────────────────────────────────────────────────────────────┐
│              Präprozessor und const – Übersicht                  │
├────────────────────────┬─────────────────────────────────────────┤
│ Präprozessor           │ läuft VOR dem Compiler, rein textuell   │
│ #include <datei>       │ Systempfade (Standardbibliothek)        │
│ #include "datei"       │ eigenes Verzeichnis zuerst              │
│ #define NAME wert      │ symbolische Konstante (kein Semikolon!) │
│ #define MAKRO(x) ((x)) │ Makro – JEDEN Parameter klammern!       │
│ #ifdef / #ifndef       │ bedingte Kompilierung                    │
│ #endif                 │ Blockende (zwingend)                     │
│ -DNAME                 │ Symbol beim Kompilieren definieren      │
│ gcc -E datei.c         │ Präprozessor-Ergebnis anzeigen          │
│ __FILE__, __LINE__     │ vordefinierte Makros                     │
├────────────────────────┼─────────────────────────────────────────┤
│ const int x = 5;       │ Wert nicht änderbar                      │
│ const Typ *p           │ Daten nicht änderbar (Standardfall!)    │
│ Typ * const p          │ Zeiger nicht umhängbar                   │
│ void f(const T *daten) │ Funktion liest nur – Schnittstelle klar  │
└────────────────────────┴─────────────────────────────────────────┘
```

**Die goldene Regel:**

> **Der Präprozessor ersetzt Text, `const` schützt Werte.**
> Wer Konstanten braucht, nimmt `const` – wer Array-Grössen oder
> bedingte Kompilierung braucht, nimmt `#define`.
> Und in jedem Makro wird geklammert, bis es weh tut.

---

</br>

# 4. Aufgaben

## 4.1. Aufgabe Präprozessor-Ausgabe analysieren

| **Vorgabe**         | **Beschreibung**                                           |
| :------------------ | :--------------------------------------------------------- |
| **Lernziele**       | Versteht, dass der Präprozessor rein textuell arbeitet     |
|                     | Kann die Präprozessor-Ausgabe mit `gcc -E` sichtbar machen |
|                     | Erkennt die Klammerfalle bei Makros                        |
| **Sozialform**      | Partnerarbeit                                              |
| **Auftrag**         | siehe unten                                                |
| **Hilfsmittel**     | Compiler mit Option `-E`                                   |
| **Zeitbedarf**      | 20min                                                      |
| **Lösungselemente** | Analyse schriftlich + Programmdurchlauf                    |

Studiere das folgende Programm:

```c
#include <stdio.h>

#define ZAHL      5
#define DOPPELT   ZAHL * 2
#define QUADRAT_A(x)  x * x
#define QUADRAT_B(x)  ((x) * (x))

int main(void) {
    printf("%d\n", DOPPELT);
    printf("%d\n", 10 / DOPPELT);
    printf("%d\n", QUADRAT_A(3));
    printf("%d\n", QUADRAT_A(2 + 1));
    printf("%d\n", QUADRAT_B(2 + 1));
    return 0;
}
```

- Welche Werte werden ausgegeben? Schreibe deine Annahme **zuerst auf Papier** auf.
- Ersetze dazu jede Zeile von Hand so, wie es der Präprozessor tun würde.
- Überprüfe deine Annahmen anschliessend mit einem Programmdurchlauf.
- Führe zusätzlich `gcc -E` aus und suche im Ergebnis die ersetzten Zeilen.
- Erkläre, warum `10 / DOPPELT` **nicht** 1 ergibt.
- Korrigiere alle fehlerhaften `#define`, sodass sie in jeder Situation korrekt rechnen.

---

## 4.2. Aufgabe Makros mit Parametern

| **Vorgabe**         | **Beschreibung**                                  |
| :------------------ | :------------------------------------------------ |
| **Lernziele**       | Kann eigene Makros mit Parametern schreiben       |
|                     | Setzt Klammern in Makros korrekt                  |
|                     | Kennt den Unterschied zwischen Makro und Funktion |
| **Sozialform**      | Einzelarbeit                                      |
| **Auftrag**         | siehe unten                                       |
| **Hilfsmittel**     |                                                   |
| **Zeitbedarf**      | 25min                                             |
| **Lösungselemente** | Funktionierendes Programm                         |

**Auftrag:**

Schreibe ein Programm mit folgenden Makros – alle **korrekt geklammert**:

| Makro             | Aufgabe                                    |
| ----------------- | ------------------------------------------ |
| `MAX(a, b)`       | gibt den grösseren von zwei Werten zurück  |
| `MIN(a, b)`       | gibt den kleineren von zwei Werten zurück  |
| `BETRAG(x)`       | gibt den Absolutbetrag zurück              |
| `IST_GERADE(n)`   | gibt 1 zurück wenn `n` gerade ist, sonst 0 |
| `CELSIUS_ZU_F(c)` | rechnet Celsius in Fahrenheit um           |

**Teste jedes Makro mit mindestens zwei Werten**, darunter zwingend auch ein **zusammengesetzter Ausdruck** (z.B. `MAX(2+3, 4*1)`), um die Klammerung zu prüfen.

**Erweiterung:**

Schreibe zusätzlich `MAX` als **Funktion** und vergleiche:

- Was passiert bei `MAX(i++, 5)` als Makro? Und als Funktion?
- Welche Variante funktioniert mit `double` **und** `int`?

---

## 4.3. Aufgabe Debug-Schalter mit bedingter Kompilierung

| **Vorgabe**         | **Beschreibung**                                      |
| :------------------ | :---------------------------------------------------- |
| **Lernziele**       | Kann bedingte Kompilierung mit `#ifdef` anwenden      |
|                     | Kennt die Compiler-Option `-D`                        |
|                     | Versteht den Unterschied zwischen `#ifdef` und `if`   |
| **Sozialform**      | Partnerarbeit                                         |
| **Auftrag**         | siehe unten                                           |
| **Hilfsmittel**     | Compiler mit Option `-D`                              |
| **Zeitbedarf**      | 25min                                                 |
| **Lösungselemente** | Funktionierendes Programm, beide Varianten vorgeführt |

**Auftrag:**

Schreibe ein Programm zur Berechnung des Notendurchschnitts mit einem **Debug-Modus**:

- Definiere ein Makro `LOG(text)`, das nur bei aktivem `DEBUG` etwas ausgibt
- Das Makro soll zusätzlich Dateiname und Zeilennummer ausgeben (`__FILE__`, `__LINE__`)
- Ohne `DEBUG` soll das Makro zu **nichts** werden (leerer Ersatztext)
- Baue mindestens 4 `LOG()`-Aufrufe an sinnvollen Stellen ein

**Testet beide Varianten:**

```bash
gcc programm.c -o normal           # ohne Debug
gcc -DDEBUG programm.c -o debug     # mit Debug
```

**Beweis führen – der Debug-Code ist wirklich verschwunden:**

Prüft mit `strings`, ob die Debug-Texte überhaupt im fertigen Programm enthalten sind:

```bash
strings normal | grep DEBUG        # → keine Treffer!
strings debug  | grep DEBUG        # → Treffer
```

Vergleicht zusätzlich die Präprozessor-Ausgabe:

```bash
gcc -E programm.c        | grep -c printf     # Anzahl printf-Zeilen ohne Debug
gcc -E -DDEBUG programm.c | grep -c printf     # Anzahl printf-Zeilen mit Debug
```

**Fragen zur Beantwortung:**

- Warum findet `strings normal` den Text „DEBUG" **überhaupt nicht**, obwohl er im
  Quelltext steht? Was sagt das über den Zeitpunkt der Entfernung aus?
- Wie unterscheidet sich die Anzahl der `printf`-Zeilen in der Präprozessor-Ausgabe?
- Was wäre der Unterschied, wenn man statt `#ifdef DEBUG` eine normale Variable
  `int debug = 1;` mit `if (debug)` verwenden würde? Nenne zwei Unterschiede
  (Tipp: einer davon wäre mit `strings` sichtbar).

---

## 4.4. Aufgabe const korrekt einsetzen

| **Vorgabe**         | **Beschreibung**                                          |
| :------------------ | :-------------------------------------------------------- |
| **Lernziele**       | Kann `const` bei Variablen und Parametern einsetzen       |
|                     | Kennt die Bedeutung von `const` bei Pointern              |
|                     | Kann Compilerfehler bei `const`-Verletzung interpretieren |
| **Sozialform**      | Einzelarbeit                                              |
| **Auftrag**         | siehe unten                                               |
| **Hilfsmittel**     |                                                           |
| **Zeitbedarf**      | 30min                                                     |
| **Lösungselemente** | Funktionierendes Programm + schriftliche Analyse          |

**Teil A – Fehler vorhersagen:**

Welche der folgenden Zeilen erzeugen einen Compilerfehler? Notiere deine Annahme **vor** dem Test.

```c
#include <stdio.h>

int main(void) {
    int a = 10;
    int b = 20;

    const int c = 30;
    const int *p1 = &a;
    int * const p2 = &a;
    const int * const p3 = &a;

    c  = 40;          // Zeile 1
    *p1 = 50;         // Zeile 2
    p1 = &b;          // Zeile 3
    *p2 = 60;         // Zeile 4
    p2 = &b;          // Zeile 5
    *p3 = 70;         // Zeile 6
    p3 = &b;          // Zeile 7

    return 0;
}
```

Kompiliere anschliessend und vergleiche mit deinen Annahmen.
Erkläre für jede fehlerhafte Zeile in einem Satz, **warum** sie nicht erlaubt ist.

**Teil B – const sinnvoll anwenden:**

Schreibe ein Programm zur Verwaltung von Messwerten:

```c
struct Messreihe {
    char   bezeichnung[50];
    double werte[10];
    int    anzahl;
};
```

Implementiere folgende Funktionen und setze `const` **überall dort ein, wo es sinnvoll ist**:

| Funktion                             | Verändert die Daten? |
| ------------------------------------ | -------------------- |
| `void messreiheAnzeigen(...)`        | nein                 |
| `double messreiheDurchschnitt(...)`  | nein                 |
| `double messreiheMaximum(...)`       | nein                 |
| `void messreiheWertHinzufuegen(...)` | ja                   |
| `void messreiheZuruecksetzen(...)`   | ja                   |

**Begründe schriftlich** für jede Funktion, warum du `const` gesetzt oder weggelassen hast.

---

© 2026 Lukas Müller – Licensed under CC BY-NC-ND 4.0
See [LICENSE](../license.md) file for details.
