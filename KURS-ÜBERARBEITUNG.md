# Programmiertechnik B – Überarbeitete Kursstruktur

## Übersicht: Verbesserte Kursorganisation

Diese Überarbeitung richtet sich nach den Lernzielen für HF-Elektrotechniker/-innen und folgt einer didaktisch besseren Reihenfolge: von konkreten Speicherkonzepten über praktische Programmierung zu erweiterten Datenstrukturen.

---

## 1. Empfohlene neue Kursstruktur

### **Phase 1: Grundlagen der C-Speicherlogik (Wochen 1–3)**
- **C0_Speicher** (NEU): Wie funktioniert der Speicher in C? Adressen, Bytes, Variablen, Zugriff
- **C1_BlocksFunctions**: Blöcke, Funktionen, Scopes
- **C1_Arrays**: Arrays als zusammenhängende Speicherbereiche

### **Phase 2: Zeiger und Strings (Wochen 4–6)**
- **C1_Pointers (überarbeitet)**: Zeiger als Speicheradressen, Dereferenzierung, Call-by-Reference
- **C1_Strings (überarbeitet)**: Strings als char-Arrays, Nullzeichen, Speichersicherheit
- **C1_Preprocessor**: #include, #define, Makros

### **Phase 3: Datenorganisation (Wochen 7–10)**
- **C1_Structs**: Strukturen als Datencontainer
- **C1_Enums**: Enumerationen und Bitmasks
- **C1_Moduls**: Header-Dateien, Projektstruktur, Make
- **C2_InputOutput** (NEU/überarbeitet): Datei-I/O, sicher programmieren

### **Phase 4: Speicher und Algorithmen (Wochen 11–14)**
- **C2_MemAlloc** (überarbeitet): malloc, free, Speicherlecks, Fehlerbehandlung
- **C2_DataStructures**: Listen, Stacks, Queues, Bäume
- **C2_FindSort**: Sortieralgorithmen, Suchverfahren

### **Phase 5: Fehlersuche und Projekte (Wochen 15–18)**
- **C0_Debugging** (NEU): Fehlersuche, Debugger, Speicherfehler erkennen
- **C3_OOP** (als Repetition und Vertiefung)
- **Projektarbeit**: Kleine Teamaufgaben mit echten Problemstellungen

---

## 2. Neue/überarbeitete Module im Detail

### **C0_Speicher (NEU)**
**Ziel:** Verstehen, wie C mit Speicher arbeitet – die zentrale Unterscheidung zu modernen Sprachen.

**Inhalte:**
- Speicher als lineares Byte-Array
- Wie Variablen im Speicher liegen
- Speicheradressen und Hexadezimalzahlen
- Endianness (Little/Big Endian)
- Stack vs. Heap (grobe Einführung)
- Warum C keine Strings als Grundtyp hat
- Visualisierung: Speicher mit Adressen und Werten

**Beispiel-Aufbau:**
```
Variable x = 5 liegt bei Adresse 0x7FFC, speichert Wert 5
Variable y = 10 liegt bei Adresse 0x7FF8, speichert Wert 10
Der Name ist nur für den Programmierer; intern arbeitet C mit Adressen.
```

**Aufgaben:**
- Speicherlayout eines Programms visualisieren
- Adressen mit &x abfragen
- Unterschied Adresse ↔ Wert verstehen

---

### **C1_Pointers (überarbeitet)**
**Wichtiger Fokus:** Zeiger nicht isoliert, sondern als direktes Ergebnis des Speichermodells verstehen.

**Neue Gliederung:**
1. Was ist ein Zeiger? (Speicheradresse, visualisiert)
2. Dereferenzierung: `*ptr` vs. `ptr`
3. Zeiger-Arithmetik: `ptr++`
4. Zeiger auf Arrays
5. Call-by-Reference und warum es nötig ist
6. Häufige Fehler: NULL-Pointer, Garbage-Pointer, Zugriff auf freien Speicher

**Häufige Fehler (sichtbar machen):**
```c
// Fehler 1: Zeiger nicht initialisiert
int *ptr;  // Zeigt auf unbekannte Speicheradresse!
*ptr = 5;  // Undefined Behavior

// Fehler 2: Array mit Zeiger verwechselt
char s[10];       // Array, speichert Daten
char *p = "Hallo"; // Zeiger, verweist auf Stringliteral

// Fehler 3: Speicher freigeben und dann zugreifen
int *ptr = malloc(sizeof(int));
free(ptr);
*ptr = 5;  // Fehler! Speicher ist freigegeben
```

---

### **C1_Strings (überarbeitet)**
**Zentrale Botschaft:** Strings = Arrays + Sicherheit. Das Nullzeichen ist nicht nur Konvention, sondern essentiell.

**Neue Gliederung:**
1. **Das Kernproblem:** Wie merkt C, wann ein Text zu Ende ist?
   - Andere Sprachen: Länge speichern
   - C: Nullzeichen speichern
   
2. **Strings als char-Arrays mit Terminierung**
   - `"Hallo"` = `{'H', 'a', 'l', 'l', 'o', '\0'}` (6 Bytes!)
   
3. **Häufige Fehler und ihre Folgen:**
   - Array zu klein → Pufferüberfluss
   - Nullzeichen vergessen → Speicher wird überlesen
   - `gets()` verwenden → Buffer Overflow
   
4. **Sichere Alternativen:**
   - `fgets()` statt `scanf()`
   - `strncpy()` statt `strcpy()`
   - Länge prüfen vor Operationen
   
5. **Speicherlayout visualisiert:**
```
char name[10] = "Anna";

Speicher:   [A][n][n][a][\0][?][?][?][?][?]
Index:      0   1   2   3   4   5   6   7   8   9

Wenn fgets() 20 Zeichen liest → Speicher ab Index 5 wird überschrieben!
Das ist ein kritischer Fehler.
```

---

### **C2_InputOutput (NEU/überarbeitet)**
**Ziel:** Sichere Ein-/Ausgabe, Dateibearbeitung, praktische Fehlerbehandlung.

**Inhalte:**
1. **Konsolen-I/O sicher:**
   - `printf()`, `scanf()` und ihre Gefahren
   - `fgets()` / `fputs()` sicherer
   - Rückgabewerte prüfen
   
2. **Datei-I/O:**
   - Dateien öffnen/schließen
   - Lesen/Schreiben
   - Fehlerbehandlung (Datei nicht vorhanden?)
   
3. **Praktische Aufgaben:**
   - Messwerte in eine Datei schreiben
   - Datei lesen und verarbeiten
   - CSV-Import/Export

---

### **C2_MemAlloc (überarbeitet)**
**Fokus:** Dynamischer Speicher verstehen, Speicherlecks vermeiden, reale Fehlerbehandlung.

**Problematische Stellen deutlich machen:**
```c
// Fehler 1: Speicher nicht freigegeben
int *arr = malloc(1000 * sizeof(int));
// Programm endet ohne free() → Speicherleck

// Fehler 2: Doppelt freigeben
int *ptr = malloc(sizeof(int));
free(ptr);
free(ptr);  // Double Free – Fehler!

// Fehler 3: Zu wenig Speicher reserviert
struct Student {
  int id;
  char name[50];
};
struct Student *s = malloc(sizeof(int)); // Viel zu klein!
```

**Gutes Muster:**
```c
int *arr = (int *)malloc(n * sizeof(int));
if (arr == NULL) {
    printf("Fehler: Speicher konnte nicht reserviert werden\n");
    return -1;
}
// Verwenden...
free(arr);
arr = NULL;  // Best Practice: Nach free() NULL setzen
```

---

### **C0_Debugging (NEU)**
**Ziel:** Systematisch Fehler finden und beheben.

**Inhalte:**
1. **Compilerfehler lesen:**
   - Was bedeutet "undefined reference"?
   - Was bedeutet "storage size not known"?
   
2. **Warnungen ernstnehmen:**
   - `-Wall -Wextra` beim Compilieren
   - Implizite int-Konvertierung
   - Vergessene Return-Statements
   
3. **Runtime-Fehler finden:**
   - printf-Debugging
   - GDB (Gnu Debugger) - Breakpoints, Step-Through
   - Speicherfehler mit Valgrind
   
4. **Häufige Fehler systematisch:**
   - Segmentation Fault (Speicher-Zugriffsfehler)
   - Null-Pointer Dereference
   - Off-by-One Fehler in Schleifen
   - Undefiniertes Verhalten
   
5. **Best Practice Checkliste:**
   - Alle Funktionsaufrufe überprüfen (scanf() Rückgabewert?)
   - Speicher immer freigeben
   - Arrays nie überlesen
   - Stringfunktionen mit Längenbegrenzung

---

## 3. Konkrete Verbesserungen an bestehenden Modulen

### **C1_Strings/README.md – Zu ergänzen:**

Am Anfang ein starker "Einstieg mit Problem":

```markdown
## Warum Strings in C anders sind

### Das zentrale Problem
In vielen Sprachen (Python, Java, C#) ist ein String ein eigenes Datentyp-Konzept:
- Die Länge wird automatisch gespeichert
- Das Ende ist implizit klar
- Manipulation ist sicher

In C gibt es KEINEN String-Typ. Ein String ist nur ein Array aus char.

### Aber wie merkt C, wann ein String zu Ende ist?

Antwort: Mit einem Endezeichen – dem Nullzeichen '\0'.

Dies ist die ZENTRALE IDEE, die alles erklärt:
- String = char-Array + Nullzeichen
- Funktionen wie strlen(), printf(), strcpy() verlassen sich darauf
- Ohne Nullzeichen → undefiniertes Verhalten
- Zu kleines Array → Pufferüberfluss
```

---

### **C1_Pointers/README.md – Neu anlegen mit klarer Struktur:**

Startpunkt: "Wo lebt die Variable?"

```markdown
## Was ist ein Zeiger?

Ein Zeiger ist nichts Mystisches – es ist einfach die Speicheradresse einer Variablen.

### Beispiel:
```c
int x = 5;
```

Im Speicher könnte das so aussehen:
```
Speicheradresse: 0x7FFC
Wert:             5
```

Ein Zeiger speichert diese Adresse:
```c
int *ptr = &x;  // ptr speichert die Adresse 0x7FFC
```

Mit `*ptr` (Dereferenzierung) kommen wir an den Wert heran:
```c
printf("%d", *ptr);  // Gibt 5 aus
*ptr = 10;           // Ändert x zu 10
```
```

---

## 4. Neue Aufgaben nach Kompetenzleveln

### **Stufe 1: Verstehen (Wissen)**
- Speicherlayout zeichnen
- Fehler in Code identifizieren (Multiple Choice)
- Fragen beantworten ("Was ist ein Nullzeichen?")

### **Stufe 2: Anwenden (Routine)**
- Funktion schreiben, die einen sicheren String liest
- Speicher korrekt reservieren und freigeben
- Datei korrekt einlesen

### **Stufe 3: Analysieren (Tiefer Blick)**
- Warum funktioniert dieser Code nicht?
- Speicherlecks mit Valgrind finden
- Performance-Unterschied Array vs. verkettete Liste erklären

### **Stufe 4: Projekt**
- Studentenverwaltung: Structs + Datei-I/O + dynamischer Speicher
- Messwert-Logger: Arrays, Dateibearbeitung, Sicherheit
- CLI-Werkzeug: Strings, Parsing, Fehlerbehandlung

---

## 5. Didaktische Verbesserungen – pro Modul

| Modul          | Verbesserung                                | Beispiel                                  |
| -------------- | ------------------------------------------- | ----------------------------------------- |
| **Alle**       | Fehlerbeispiele einbauen                    | "Welcher Code ist falsch und warum?"      |
| **Strings**    | Mit Speicherlayout starten                  | Visualisierung des Buffers                |
| **Pointers**   | Nicht isoliert, sondern im Speicher-Kontext | Verbindung zu C0_Speicher deutlich machen |
| **Structs**    | Mit realen Daten-Modellen                   | Student, Sensor, Gerät                    |
| **Funktionen** | Call-by-Value vs. Pointer deutlich machen   | Praktisches Beispiel: Swap, Rückgabewerte |
| **Dateien**    | Mit Fehlerbehandlung lehren                 | if (fopen() == NULL)                      |

---

## 6. Empfohlene Materialien-Ordnerstruktur

```
docs/
├── C0_Speicher/          (NEU)
│   ├── README.md
│   ├── groupwork-practice.md
│   └── x_gitres/
│
├── C0_Debugging/          (NEU)
│   ├── README.md
│   ├── groupwork-practice.md
│   └── x_gitres/
│
├── C1_BlocksFunctions/    (bestehend, ggf. erweitern)
│   └── ...
│
├── C1_Pointers/           (überarbeitet)
│   ├── README.md          (neu geschrieben mit Speicher-Fokus)
│   ├── groupwork-practice.md
│   └── x_gitres/
│
├── C1_Strings/            (überarbeitet)
│   ├── README.md          (neu strukturiert mit Fehler-Fokus)
│   ├── groupwork-practice.md
│   └── x_gitres/
│
├── C2_InputOutput/        (NEU)
│   ├── README.md
│   ├── groupwork-practice.md
│   └── x_gitres/
│
├── C2_MemAlloc/           (überarbeitet)
│   ├── README.md
│   ├── groupwork-practice.md
│   └── x_gitres/
│
└── ... (weitere wie bisher)
```

---

## 7. Empfohlene Umsetzungs-Prioritäten

### **Sofort umsetzen (Maximum Lerneffekt):**
1. **C1_Strings/README.md** überarbeiten: Problem zuerst, dann Lösung
2. **C0_Speicher/README.md** anlegen: Fundament für alles
3. **C0_Debugging/README.md** anlegen: Praktische Fehlersuche

### **In den nächsten 2–3 Wochen:**
4. C1_Pointers/README.md mit Speicher-Logik umschreiben
5. C2_MemAlloc/README.md verbessern
6. C2_InputOutput/README.md erstellen

### **Längerfristig:**
7. Praxisprojekte einbauen (Messwert-Logger, CSV-Verarbeitung)
8. Kompetenzbasierte Aufgaben nach Levels strukturieren
9. Speicher-Visualisierung mit Diagrams (Excalidraw/Draw.io) ergänzen

---

## 8. Kurz-Beispiel: Überarbeitete Lerneinheit "Strings"

**Alte Struktur:** Definition → Deklaration → Funktionen → Aufgaben

**Neue Struktur:**
1. **Problem erkannt:** "Wie merkt C, dass das String zu Ende ist?"
2. **Speicher-Visualisierung:** String = Array + Nullzeichen
3. **Zentrale Fehler:** Zu kleines Array, Nullzeichen vergessen
4. **Sichere Patterns:** fgets statt scanf
5. **Fehler debuggen:** Valgrind, Speicherlayout-Analyse
6. **Aufgaben:** Von einfach bis Projekt-Level

Dieser Aufbau erzeugt tieferes Verständnis, weil die zentrale Logik transparent wird.

---

## Fazit

Die Überarbeitung folgt dem Prinzip:

> **Nicht "Wie funktioniert das?", sondern "Warum funktioniert das so? Und was kann schiefgehen?"**

Das macht den Kurs nicht nur verständlicher, sondern auch weniger fehleranfällig für die Studierenden.

---

© 2026 Lukas Müller – Licensed under CC BY-NC-ND 4.0
