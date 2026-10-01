|                             |                          |                               |
| --------------------------- | ------------------------ | ----------------------------- |
| **Elektrotechniker/-in HF** | **Programmiertechnik B** | ![logo](../x_gitres/logo.png) |

- [1. Gruppenarbeiten Dynamische Speicherverwaltung](#1-gruppenarbeiten-dynamische-speicherverwaltung)
  - [1.1. Ablauf und Rahmenbedingungen](#11-ablauf-und-rahmenbedingungen)
  - [1.2. Gruppe A: `malloc()` und `calloc()` im Vergleich](#12-gruppe-a-malloc-und-calloc-im-vergleich)
    - [1.2.1. Theorieteil](#121-theorieteil)
    - [1.2.2. Praxisteil](#122-praxisteil)
    - [1.2.3. Prüffragen für die Präsentation](#123-prüffragen-für-die-präsentation)
  - [1.3. Gruppe B: Speichersegmente und Lebensdauer](#13-gruppe-b-speichersegmente-und-lebensdauer)
    - [1.3.1. Theorieteil](#131-theorieteil)
    - [1.3.2. Praxisteil](#132-praxisteil)
    - [1.3.3. Prüffragen für die Präsentation](#133-prüffragen-für-die-präsentation)
  - [1.4. Gruppe C: `realloc()` und dynamisch wachsende Arrays](#14-gruppe-c-realloc-und-dynamisch-wachsende-arrays)
    - [1.4.1. Theorieteil](#141-theorieteil)
    - [1.4.2. Praxisteil](#142-praxisteil)
    - [1.4.3. Prüffragen für die Präsentation](#143-prüffragen-für-die-präsentation)
  - [1.5. Gruppe D: Speicherfehler finden und vermeiden](#15-gruppe-d-speicherfehler-finden-und-vermeiden)
    - [1.5.1. Theorieteil](#151-theorieteil)
    - [1.5.2. Praxisteil](#152-praxisteil)
    - [1.5.3. Prüffragen für die Präsentation](#153-prüffragen-für-die-präsentation)

---

</br>

# 1. Gruppenarbeiten Dynamische Speicherverwaltung

## 1.1. Ablauf und Rahmenbedingungen

Jede Gruppe erarbeitet **ein** Thema aus dem Kapitel Dynamische
Speicherverwaltung und stellt es der Klasse vor.

|                      |                                                             |
| -------------------- | ----------------------------------------------------------- |
| **Gruppengrösse**    | 3 – 4 Personen                                              |
| **Bearbeitungszeit** | 60 Minuten                                                  |
| **Präsentation**     | 8 Minuten pro Gruppe + 4 Minuten Fragen                     |
| **Abgabe**           | Zusammenfassung (1–2 A4-Seiten) + lauffähige `.c`-Datei(en) |

**Anforderungen an die Abgabe:**

- Die Zusammenfassung enthält die **wichtigsten Punkte in eigenen Worten**
- Alle Codebeispiele sind **kompiliert und getestet** – geben Sie die
  tatsächliche Ausgabe mit an
- Kompilieren Sie grundsätzlich mit `gcc -Wall -Wextra`

**Anforderungen an die Präsentation:**

- **Jedes Gruppenmitglied** erklärt einen Teil
- Mindestens **ein Codebeispiel wird live vorgeführt**
- Am Schluss beantwortet die Gruppe die **Prüffragen** ihres Auftrags

> **Hinweis zu KI-Werkzeugen:** Sie dürfen alle Hilfsmittel verwenden.
> Bewertet wird aber, ob Sie Ihre Lösung **erklären und live verändern**
> können. Bei der Präsentation stelle ich Rückfragen und bitte um kleine
> Codeänderungen vor der Klasse.

---

</br>

## 1.2. Gruppe A: `malloc()` und `calloc()` im Vergleich

| **Vorgabe**         | **Beschreibung**                                               |
| :------------------ | :------------------------------------------------------------- |
| **Lernziele**       | Kennt die Unterschiede zwischen `malloc()` und `calloc()`      |
|                     | Kann begründen, wann welche Funktion sinnvoll ist              |
|                     | Kann die Rückgabewerte korrekt auf `NULL` prüfen               |
|                     | Kann `sizeof()` bei der Speicherreservierung korrekt einsetzen |
| **Sozialform**      | Gruppenarbeit (3–4 Personen)                                   |
| **Auftrag**         | siehe unten                                                    |
| **Hilfsmittel**     | Skript Kap. 1.5, Lehrbuch Kap. 18.1                            |
| **Zeitbedarf**      | 60min                                                          |
| **Lösungselemente** | Zusammenfassung 1–2 Seiten, lauffähiger Code, Kurzpräsentation |

### 1.2.1. Theorieteil

Erarbeiten Sie die folgenden Punkte und fassen Sie sie zusammen:

1. Syntax und Rückgabewert von `malloc()` und `calloc()`
2. Der entscheidende Unterschied bei der **Initialisierung**
3. Warum liefern beide einen `void*` – und was bedeutet das?
4. Warum wird die Grösse mit `sizeof()` bestimmt und nicht als feste Zahl?
5. Was passiert, wenn kein Speicher mehr verfügbar ist?

### 1.2.2. Praxisteil

**Aufgabe A1 – Den Unterschied sichtbar machen**

Schreiben Sie ein Programm, das den Initialisierungsunterschied belegt:

```c
int *a = malloc(5 * sizeof(int));
for (int i = 0; i < 5; i++) a[i] = 111 + i;   /* Speicher "verschmutzen" */
free(a);

int *m = malloc(5 * sizeof(int));   /* sehr wahrscheinlich derselbe Block */
/* Inhalt von m[0..4] ausgeben  */

int *c = calloc(5, sizeof(int));
/* Inhalt von c[0..4] ausgeben  */
```

> **Wichtiger Hinweis:** Ein frisch gestartetes Programm bekommt vom
> Betriebssystem oft **genullte** Speicherseiten. Ein einfaches
> `malloc()` gleich zu Programmbeginn zeigt darum möglicherweise
> ebenfalls lauter Nullen – der Unterschied wäre dann nicht sichtbar.
> Der Umweg über „verschmutzen und wieder freigeben" macht ihn
> zuverlässig sichtbar.
>
> **Diskutieren Sie in der Gruppe:** Warum darf man sich trotzdem
> **niemals** darauf verlassen, dass `malloc()` genullten Speicher liefert?

**Aufgabe A2 – NULL-Prüfung**

Erweitern Sie beide Reservierungen um eine korrekte Prüfung auf `NULL`.
Zeigen Sie, wie das Programm sich verhält, wenn Sie absichtlich eine
unrealistisch grosse Menge anfordern (z.B. `malloc(SIZE_MAX)`).

**Aufgabe A3 – Personen-Array**

Schreiben Sie ein Programm, das mit `calloc()` Speicher für ein Array aus
`n` Strukturen reserviert:

```c
typedef struct {
    char name[30];
    int  alter;
} Person;
```

Befüllen Sie das Array, geben Sie es aus und geben Sie den Speicher
korrekt frei. Begründen Sie, **wie viele** `free()`-Aufrufe nötig sind.

### 1.2.3. Prüffragen für die Präsentation

1. Wann würden Sie `calloc()` bevorzugen, wann `malloc()`?
2. Warum ist `malloc(40)` schlechter Stil als `malloc(10 * sizeof(int))`?
3. Was liefert `malloc(0)`? Testen Sie es.

---

</br>

## 1.3. Gruppe B: Speichersegmente und Lebensdauer

| **Vorgabe**         | **Beschreibung**                                                |
| :------------------ | :-------------------------------------------------------------- |
| **Lernziele**       | Kann die Speichersegmente eines Programms benennen und zuordnen |
|                     | Kennt den Unterschied zwischen Stack und Heap                   |
|                     | Kann die Lebensdauer von Variablen und Speicherblöcken erklären |
|                     | Erkennt die Gefahr bei der Rückgabe lokaler Adressen            |
| **Sozialform**      | Gruppenarbeit (3–4 Personen)                                    |
| **Auftrag**         | siehe unten                                                     |
| **Hilfsmittel**     | Skript Kap. 1.1–1.3 und 1.6, Lehrbuch Kap. 18 (Einleitung)      |
| **Zeitbedarf**      | 60min                                                           |
| **Lösungselemente** | Zusammenfassung 1–2 Seiten, lauffähiger Code, Kurzpräsentation  |

### 1.3.1. Theorieteil

1. Die vier Segmente: **Code, Daten, Stack, Heap** – was liegt wo?
2. Stack und Heap im direkten Vergleich (Verwaltung, Grösse,
   Geschwindigkeit, Lebensdauer)
3. Lebensdauer von: lokaler Variable, `static`-Variable, globaler
   Variable, dynamischem Speicherblock
4. Warum wird die Lebensdauer eines Heap-Blocks **nicht** durch
   Blockgrenzen `{ }` bestimmt?

### 1.3.2. Praxisteil

**Aufgabe B1 – Segmente sichtbar machen**

Schreiben Sie ein Programm, das die Adressen verschiedener Variablen
ausgibt, und ordnen Sie sie den Segmenten zu:

```c
int global = 1;                    /* Datensegment   */
static int stat = 2;               /* Datensegment   */

int main(void) {
    int lokal = 3;                 /* Stack          */
    int *heap = malloc(sizeof(int));/* Heap          */
    /* Adressen mit %p ausgeben und vergleichen      */
}
```

Erstellen Sie aus den gemessenen Adressen eine **Skizze** des
Speicherlayouts. Welche Adressen liegen nahe beieinander, welche weit
auseinander?

**Aufgabe B2 – Lebensdauer im Vergleich**

Schreiben Sie zwei Funktionen, die beide eine Adresse zurückgeben:

```c
int* falsch(void) {
    int wert = 42;
    return &wert;        /* lokale Variable – gefährlich! */
}

int* richtig(void) {
    int *wert = malloc(sizeof(int));
    *wert = 42;
    return wert;         /* Heap – bleibt gültig */
}
```

- Kompilieren Sie mit `gcc -Wall -Wextra`. **Welche Warnung** erscheint?
  Notieren Sie sie wörtlich.
- Was gibt das Programm bei beiden Varianten aus?
- Wer muss den Speicher von `richtig()` freigeben?

**Aufgabe B3 – `static` demonstrieren**

Zeigen Sie mit einer Zählfunktion den Unterschied zwischen einer
normalen lokalen und einer `static`-Variablen über mehrere Aufrufe.

### 1.3.3. Prüffragen für die Präsentation

1. Warum wächst der Stack automatisch, der Heap aber nicht?
2. Ein Student sagt: „Die Funktion `falsch()` hat bei mir funktioniert,
   also ist sie korrekt." Was antworten Sie?
3. Zeichnen Sie das Speicherlayout Ihres Programms an die Wandtafel.

---

</br>

## 1.4. Gruppe C: `realloc()` und dynamisch wachsende Arrays

| **Vorgabe**         | **Beschreibung**                                                    |
| :------------------ | :------------------------------------------------------------------ |
| **Lernziele**       | Kann `realloc()` korrekt einsetzen                                  |
|                     | Kennt die Gefahr des Datenverlusts bei fehlgeschlagenem `realloc()` |
|                     | Kann ein dynamisch wachsendes Array implementieren                  |
|                     | Versteht, warum ein Speicherblock verschoben werden kann            |
| **Sozialform**      | Gruppenarbeit (3–4 Personen)                                        |
| **Auftrag**         | siehe unten                                                         |
| **Hilfsmittel**     | Skript Kap. 1.5.5, Lehrbuch Kap. 18.1.4 und 18.3                    |
| **Zeitbedarf**      | 60min                                                               |
| **Lösungselemente** | Zusammenfassung 1–2 Seiten, lauffähiger Code, Kurzpräsentation      |

### 1.4.1. Theorieteil

1. Syntax von `realloc()` und Bedeutung beider Parameter
2. Was passiert beim **Vergrössern**, was beim **Verkleinern**?
3. Warum kann `realloc()` „sehr aufwändig" sein?
4. Was bewirkt `realloc(NULL, size)`?
5. Warum bleibt der Inhalt nach einem Verkleinern **nicht** gelöscht?

### 1.4.2. Praxisteil

**Aufgabe C1 – Verschiebung beobachten**

Schreiben Sie ein Programm, das ein Array bei Bedarf verdoppelt und dabei
protokolliert, ob der Block am Ort bleibt oder verschoben wird:

```c
#include <stdint.h>

uintptr_t alt = (uintptr_t)arr;        /* Adresse als ZAHL sichern */
int *neu = realloc(arr, kap * sizeof(int));
if (neu == NULL) { free(arr); return 1; }
arr = neu;
printf("Kapazitaet %d | %s\n", kap,
       (alt == (uintptr_t)arr) ? "am Ort" : "VERSCHOBEN");
```

> **Warum wird die Adresse als Zahl gesichert und nicht als Zeiger?**
> Nach `realloc()` ist der **alte Zeigerwert unbestimmt** – ihn auch nur
> zu lesen ist laut C-Standard nicht erlaubt. `gcc -Wall -Wextra` meldet
> das mit `-Wuse-after-free`. Probieren Sie es aus und zeigen Sie die
> Warnung in der Präsentation.

Lassen Sie das Array von Kapazität 2 auf mindestens 16 wachsen.
**Dokumentieren Sie Ihre Beobachtung**: Bei welchen Schritten wurde
verschoben?

**Aufgabe C2 – Die klassische `realloc()`-Falle**

Diese Zeile ist gefährlich:

```c
arr = realloc(arr, neueGroesse);      /* ⚠️ was passiert bei NULL? */
```

- Erklären Sie, warum bei einem Fehlschlag die **Originaldaten verloren**
  gehen
- Zeigen Sie die korrekte Variante mit Hilfszeiger

**Aufgabe C3 – Eigene Messwertliste**

Implementieren Sie eine kleine Struktur mit Verdopplungsstrategie:

```c
typedef struct {
    double *werte;
    int     anzahl;
    int     kapazitaet;
} Messreihe;

int  reiheInit(Messreihe *r, int startKapazitaet);
int  reiheHinzufuegen(Messreihe *r, double wert);   /* verdoppelt bei Bedarf */
void reiheFreigeben(Messreihe *r);
```

Fügen Sie mindestens 20 Werte ein und geben Sie bei jeder Erweiterung die
neue Kapazität aus.

### 1.4.3. Prüffragen für die Präsentation

1. Warum verdoppelt man die Kapazität, statt sie um 1 zu erhöhen?
2. Was passiert mit dem alten Speicherblock, wenn `realloc()` verschiebt –
   muss man ihn selbst freigeben?
3. Führen Sie live vor, was passiert, wenn Sie den Hilfszeiger in C2
   weglassen.

---

</br>

## 1.5. Gruppe D: Speicherfehler finden und vermeiden

| **Vorgabe**         | **Beschreibung**                                               |
| :------------------ | :------------------------------------------------------------- |
| **Lernziele**       | Kennt die typischen Fehler im Umgang mit dynamischem Speicher  |
|                     | Kann Memory Leaks, Use-After-Free und Double Free erklären     |
|                     | Kann ein Werkzeug zur Speicherprüfung einsetzen                |
|                     | Kann Regeln für sicheren Umgang mit `malloc`/`free` anwenden   |
| **Sozialform**      | Gruppenarbeit (3–4 Personen)                                   |
| **Auftrag**         | siehe unten                                                    |
| **Hilfsmittel**     | Skript Kap. 1.7–1.8, Lehrbuch Kap. 18.2, Dr. Memory            |
| **Zeitbedarf**      | 60min                                                          |
| **Lösungselemente** | Zusammenfassung 1–2 Seiten, lauffähiger Code, Kurzpräsentation |

### 1.5.1. Theorieteil

1. Was ist ein **Memory Leak** und wie entsteht er?
2. **Use-After-Free** – warum ist dieser Fehler so tückisch?
3. **Double Free** – was passiert dabei?
4. Warum kann der Compiler unpaarige `malloc`/`free` **nicht** finden,
   unpaarige Klammern `{ }` aber schon?
5. Die sieben goldenen Regeln aus dem Skript – in eigenen Worten

### 1.5.2. Praxisteil

**Aufgabe D1 – Fehlersuche**

Das folgende Programm enthält **fünf** Fehler im Umgang mit Speicher:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* leseName(void) {
    char puffer[50];
    strcpy(puffer, "Testname");
    return puffer;
}

int main(void) {
    int *werte = malloc(10);
    werte[0] = 1;
    werte[9] = 9;
    free(werte);
    printf("nach free: %d\n", werte[0]);
    free(werte);
    char *n = leseName();
    printf("Name: %s\n", n);
    return 0;
}
```

- Finden Sie alle fünf Fehler und erklären Sie **die jeweilige Auswirkung**
- Schreiben Sie die korrigierte Fassung
- Kompilieren Sie mit `gcc -Wall -Wextra`: **Welche Fehler findet schon der
  Compiler, welche nicht?** Notieren Sie die Warnungen wörtlich.

> Das ist der Kern dieser Aufgabe: Manche dieser Fehler meldet der
> Compiler sofort – andere zeigen sich **erst zur Laufzeit** oder gar
> nicht. Arbeiten Sie diesen Unterschied klar heraus.

**Aufgabe D2 – Werkzeug einsetzen**

Prüfen Sie das fehlerhafte und das korrigierte Programm mit **Dr. Memory**:

```bash
gcc -g -gdwarf-2 -o main.exe main.c
drmemory -- main.exe
```

- Stellen Sie die Ausgabe **vorher/nachher** gegenüber
- Welche Fehler meldet Dr. Memory, die der Compiler übersehen hat?

**Aufgabe D3 – Leak durch Zeigerüberschreibung**

Bauen Sie das Beispiel aus dem Lehrbuch nach, bei dem ein Leak dadurch
entsteht, dass ein Zeiger **wiederverwendet** wird, ohne den alten
Speicher freizugeben. Zeigen Sie die Dr.-Memory-Meldung dazu.

### 1.5.3. Prüffragen für die Präsentation

1. Warum ist `free(p); p = NULL;` eine gute Angewohnheit? Was schützt das
   konkret?
2. Ein Leak „verschwindet" beim Programmende von selbst. Warum ist er
   trotzdem ein Problem – besonders bei einer Robotersteuerung?
3. Zeigen Sie live: Was meldet Dr. Memory, wenn Sie in Ihrem korrigierten
   Programm **ein** `free()` wieder entfernen?

---

© 2026 Lukas Müller – Licensed under CC BY-NC-ND 4.0
See [LICENSE](../license.md) file for details.
