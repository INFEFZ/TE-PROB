|                             |                          |                               |
| --------------------------- | ------------------------ | ----------------------------- |
| **Elektrotechniker/-in HF** | **Programmiertechnik B** | ![logo](../x_gitres/logo.png) |

- [1. Aufzählungstypen (enum)](#1-aufzählungstypen-enum)
  - [1.2. Was ist ein `enum`?](#12-was-ist-ein-enum)
  - [1.3. Konvertierung zu `int`](#13-konvertierung-zu-int)
  - [1.4. Beispiel Menüsystem mit `enum`](#14-beispiel-menüsystem-mit-enum)
  - [1.5. Zusammenfassung](#15-zusammenfassung)
- [2. Aufgaben](#2-aufgaben)
  - [2.1. Aufgabe Programmsteuerung](#21-aufgabe-programmsteuerung)
  - [2.2. Aufgabe Ampelsteuerung](#22-aufgabe-ampelsteuerung)

---

</br>

# 1. Aufzählungstypen (enum)

> **Lernziele:** Nach dieser Lektion kannst du eigene Enumerationen definieren und einsetzen, erkennst wann ein `enum` die richtige Wahl gegenüber `#define` oder `int` ist, kannst zwischen `enum` und `int` korrekt konvertieren und schreibst dadurch lesbareren, sichereren Code.

---

## 1. Sinn und Zweck von Enums

### Das Problem ohne Enum

Stell dir folgenden Code vor, der einen Wochentag verarbeitet:

```c
int tag = 3;
 
if (tag == 0) {
    printf("Montag\n");
} else if (tag == 1) {
    printf("Dienstag\n");
}
// ...
```

**Fragen, die sofort entstehen:**

- Was bedeutet `3`? Welcher Tag ist das?
- Beginnt die Zählung bei `0` oder bei `1`?
- Was passiert, wenn jemand `tag = 9` setzt? Der Compiler sagt nichts dazu.
- In drei Monaten – weisst du noch, was `tag = 5` bedeutet?

> Dieses Problem nennt man **„Magic Numbers"** – Zahlen im Code, deren Bedeutung nicht aus sich selbst heraus erkennbar ist.

### Die Lösung: `enum`

```c
typedef enum {
    MONTAG, DIENSTAG, MITTWOCH, DONNERSTAG, FREITAG, SAMSTAG, SONNTAG
} Wochentag;
 
Wochentag tag = MITTWOCH;
 
if (tag == MONTAG) {
    printf("Wochenstart!\n");
}
```

Jetzt ist sofort klar, was gemeint ist – **ohne** einen Kommentar zu brauchen.

### Definition

> Ein **enum** (Enumeration, „Aufzählungstyp") ist ein **benutzerdefinierter Datentyp**, der aus einer **benannten Menge von Konstanten** besteht. Intern sind es ganze Zahlen (`int`), aber im Code erscheinen sie als sprechende Namen.

### Vorteile im Überblick

| Vorteil                   | Erklärung                                                      |
| ------------------------- | -------------------------------------------------------------- |
| **Lesbarkeit**            | `MONTAG` statt `0` – sofort verständlich                       |
| **Wartbarkeit**           | Werte an einer Stelle definiert, überall gleich benannt        |
| **Weniger Fehler**        | Tippfehler bei Namen erzeugt Compiler-Fehler, bei Zahlen nicht |
| **Dokumentation im Code** | Die Menge gültiger Werte ist direkt sichtbar                   |
| **IDE-Unterstützung**     | Autovervollständigung schlägt gültige Werte vor                |

---

## 2. Enum vs. die Alternativen – wo sollen Enums eingesetzt werden?

### 2.1 Vergleich: `enum` vs. `#define` vs. `int`

```c
// Variante 1: reine int-Konstanten mit #define
#define MONTAG    0
#define DIENSTAG  1
#define MITTWOCH  2
// ... unübersichtlich, kein Typsicherheit, kein Gruppierung
 
// Variante 2: enum (empfohlen für diesen Anwendungsfall!)
typedef enum { MONTAG, DIENSTAG, MITTWOCH, DONNERSTAG, FREITAG, SAMSTAG, SONNTAG } Wochentag;
 
// Variante 3: einfacher int
int tag = 2;  // keine Information, was 2 bedeutet
```

| **Kriterium**                                  | `#define` | `enum`     | `int` |
| ---------------------------------------------- | --------- | ---------- | ----- |
| Lesbare Namen                                  | Ja        | Ja         | Nein  |
| Gruppierung zusammengehöriger Werte            | Nein      | Ja         | Nein  |
| Eigener Datentyp (Typsicherheit beim Compiler) | Nein      | Teilweise  | Nein  |
| Im Debugger sichtbar als Name                  | Nein      | Ja (meist) | Nein  |
| Automatische Werte-Vergabe                     | Nein      | Ja         | Nein  |

### 2.2 Faustregel: Wann ein Enum verwenden?

Verwende ein `enum`, wenn du eine **feste, begrenzte Menge** von benannten Zuständen oder Kategorien hast:

**Gute Anwendungsfälle für enum:**

- Wochentage, Monate
- Zustände einer Ampel (ROT, GELB, GRUEN)
- Status eines Vorgangs (WARTEND, AKTIV, ABGESCHLOSSEN, FEHLER)
- Himmelsrichtungen (NORD, OST, SUED, WEST)
- Spielkartenfarben (HERZ, KARO, PIK, KREUZ)
- Fehlercodes (FEHLER_KEINER, FEHLER_DATEI, FEHLER_SPEICHER)
- Menüoptionen, Befehle, Modi

**Kein guter Anwendungsfall für enum:**

- Werte, die sich zur Laufzeit beliebig ändern (z.B. Messwerte)
- Werte mit echter mathematischer Bedeutung (z.B. Preise, Koordinaten)
- Werte, die aus einer Datei/Datenbank mit unbekanntem Wertebereich kommen

> **Merksatz:** Wenn du im Kopf eine Liste von Wörtern aufzählen kannst (*„entweder ROT oder GELB oder GRÜN"*), ist das ein Kandidat für `enum`.

---

## 3. Deklaration und Initialisierung

### 3.1 Grundsyntax

```c
enum Name {
    WERT1,
    WERT2,
    WERT3
};
```

```c
enum Ampelfarbe {
    ROT,
    GELB,
    GRUEN
};
 
enum Ampelfarbe aktuelleFarbe = ROT;
```

### 3.2 Mit `typedef` – die übliche Praxis in C

Ohne `typedef` muss man immer `enum Ampelfarbe` schreiben. Mit `typedef` reicht der kurze Name:

```c
// Ohne typedef:
enum Ampelfarbe { ROT, GELB, GRUEN };
enum Ampelfarbe farbe = ROT;          // "enum" muss immer dabei stehen
 
// Mit typedef – kürzer und üblicher:
typedef enum {
    ROT,
    GELB,
    GRUEN
} Ampelfarbe;
 
Ampelfarbe farbe = ROT;               // kein "enum" mehr nötig
```

> **Konvention:** In modernem C-Code wird praktisch immer `typedef enum { ... } Name;` verwendet.

### 3.3 Automatische Wertevergabe

Enum-Konstanten erhalten automatisch aufsteigende `int`-Werte, beginnend bei `0`:

```c
typedef enum {
    MONTAG,     // = 0
    DIENSTAG,   // = 1
    MITTWOCH,   // = 2
    DONNERSTAG, // = 3
    FREITAG,    // = 4
    SAMSTAG,    // = 5
    SONNTAG     // = 6
} Wochentag;
```

### 3.4 Eigene Startwerte und Sprünge

Man kann den Startwert und einzelne Werte explizit festlegen – die folgenden Werte zählen automatisch weiter:

```c
typedef enum {
    HTTP_OK            = 200,
    HTTP_NOT_FOUND     = 404,
    HTTP_SERVER_ERROR  = 500,
    HTTP_SERVER_ERROR2 = 501   // automatisch 501, da nach 500
} HttpStatus;
 
typedef enum {
    JANUAR = 1,   // beginnt bei 1, nicht bei 0
    FEBRUAR,      // = 2
    MAERZ,        // = 3
    // ...
    DEZEMBER      // = 12
} Monat;
```

> Wenn Monate als `1..12` natürlicher sind (wie im echten Kalender), startet man bewusst bei `1` statt beim Standard `0`.

### 3.5 Mehrere Enum-Werte mit gleichem Zahlenwert

```c
typedef enum {
    FEHLER_OK = 0,
    FEHLER_KEINER = 0,    // gleicher Wert wie FEHLER_OK – beide gültig
    FEHLER_DATEI = 1,
    FEHLER_SPEICHER = 2
} Fehlercode;
```

---

## 4. Zugriff und Verwendung

### 4.1 Enum als Funktionsparameter und Rückgabewert

```c
typedef enum { ROT, GELB, GRUEN } Ampelfarbe;
 
// Enum als Parameter
void zeigeFarbe(Ampelfarbe farbe) {
    switch (farbe) {
        case ROT:   printf("STOP\n");      break;
        case GELB:  printf("ACHTUNG\n");   break;
        case GRUEN: printf("FAHREN\n");    break;
    }
}
 
// Enum als Rückgabewert
Ampelfarbe naechsteFarbe(Ampelfarbe aktuell) {
    switch (aktuell) {
        case ROT:   return GRUEN;
        case GELB:  return ROT;
        case GRUEN: return GELB;
    }
    return ROT;  // Fallback
}
 
int main(void) {
    Ampelfarbe farbe = ROT;
    zeigeFarbe(farbe);             // STOP
    farbe = naechsteFarbe(farbe);
    zeigeFarbe(farbe);             // FAHREN
    return 0;
}
```

### 4.2 Enum in `switch`-Anweisungen

`enum` und `switch` ergänzen sich besonders gut – der Compiler kann sogar warnen, wenn ein Fall vergessen wurde (mit `-Wswitch`):

```c
typedef enum { MONTAG, DIENSTAG, MITTWOCH, DONNERSTAG, FREITAG, SAMSTAG, SONNTAG } Wochentag;
 
void zeigeTagTyp(Wochentag tag) {
    switch (tag) {
        case SAMSTAG:
        case SONNTAG:
            printf("Wochenende!\n");
            break;
        default:
            printf("Werktag\n");
            break;
    }
}
```

```bash
# Mit -Wswitch warnt gcc, wenn ein enum-Wert im switch fehlt:
gcc -Wall -Wswitch programm.c
```

---

## 5. Praktische Beispiele zur Förderung der Lesbarkeit

### Beispiel 1 – Zustandsmaschine (State Machine)

```c
typedef enum {
    ZUSTAND_WARTEND,
    ZUSTAND_LAEUFT,
    ZUSTAND_PAUSIERT,
    ZUSTAND_BEENDET,
    ZUSTAND_FEHLER
} Prozesszustand;
 
void verarbeiteZustand(Prozesszustand zustand) {
    switch (zustand) {
        case ZUSTAND_WARTEND:
            printf("Warte auf Start...\n");
            break;
        case ZUSTAND_LAEUFT:
            printf("Prozess läuft.\n");
            break;
        case ZUSTAND_PAUSIERT:
            printf("Pausiert – warte auf Fortsetzung.\n");
            break;
        case ZUSTAND_BEENDET:
            printf("Erfolgreich beendet.\n");
            break;
        case ZUSTAND_FEHLER:
            printf("Fehler aufgetreten!\n");
            break;
    }
}
```

**Vergleich ohne enum (deutlich schlechter lesbar):**

```c
void verarbeiteZustand(int zustand) {
    if (zustand == 0) printf("Warte auf Start...\n");
    else if (zustand == 1) printf("Prozess läuft.\n");
    // Welche Zahl bedeutet jetzt "Fehler"? Man muss nachschlagen.
}
```

### Beispiel 2 – Fehlercodes statt Zahlen

```c
typedef enum {
    DATEI_OK,
    DATEI_NICHT_GEFUNDEN,
    DATEI_KEIN_ZUGRIFF,
    DATEI_FORMAT_UNGUELTIG
} DateiFehler;
 
DateiFehler oeffneDatei(char *pfad) {
    // ... Logik zum Öffnen
    if (/* Datei existiert nicht */ 0) {
        return DATEI_NICHT_GEFUNDEN;
    }
    return DATEI_OK;
}
 
int main(void) {
    DateiFehler ergebnis = oeffneDatei("daten.txt");
 
    if (ergebnis != DATEI_OK) {
        printf("Fehler beim Öffnen der Datei!\n");
    }
    return 0;
}
```

### Beispiel 3 – Spielkarten / Himmelsrichtungen (Kombination zweier Enums)

```c
typedef enum { HERZ, KARO, PIK, KREUZ } Farbe;
typedef enum { ZWEI, DREI, VIER, FUENF, SECHS, SIEBEN, ACHT, NEUN, ZEHN,
               BUBE, DAME, KOENIG, ASS } Wert;
 
typedef struct {
    Farbe farbe;
    Wert  wert;
} Spielkarte;
 
void zeigeKarte(Spielkarte karte) {
    char *farbnamen[] = {"Herz", "Karo", "Pik", "Kreuz"};
    char *wertnamen[] = {"2","3","4","5","6","7","8","9","10","Bube","Dame","König","Ass"};
 
    printf("%s %s\n", wertnamen[karte.wert], farbnamen[karte.farbe]);
}
 
int main(void) {
    Spielkarte meineKarte = { HERZ, KOENIG };
    zeigeKarte(meineKarte);   // "König Herz"
    return 0;
}
```

> Dieses Beispiel zeigt, wie ein `enum`-Wert als **Index** in ein String-Array genutzt werden kann, um den enum-Wert lesbar auszugeben (siehe Abschnitt 6.3).

---

## 6. Konvertierungen

### 6.1 `enum` → `int` (implizit erlaubt)

Da ein `enum`-Wert intern ein `int` ist, funktioniert die Umwandlung automatisch:

```c
typedef enum { ROT, GELB, GRUEN } Ampelfarbe;
 
Ampelfarbe farbe = GELB;
int zahl = farbe;          // funktioniert automatisch: zahl = 1
 
printf("%d\n", farbe);     // funktioniert direkt: gibt "1" aus
```

### 6.2 `int` → `enum` (explizites Casting empfohlen)

Die Umwandlung in die andere Richtung ist **nicht automatisch typsicher** – C prüft nicht, ob der Wert gültig ist:

```c
typedef enum { ROT, GELB, GRUEN } Ampelfarbe;
 
int wert = 1;
Ampelfarbe farbe = (Ampelfarbe)wert;   // explizites Cast empfohlen
 
int ungueltig = 99;
Ampelfarbe kaputt = (Ampelfarbe)ungueltig;  // compiliert! Aber 99 ist kein gültiger Wert!
```

> **Wichtige Einschränkung:** C **prüft zur Laufzeit nicht**, ob ein `int`-Wert tatsächlich einem gültigen `enum`-Wert entspricht. Das ist die Verantwortung der Entwicklerin/des Entwicklers – z.B. durch eine Validierungsfunktion.

### 6.3 `enum` → `string` (für lesbare Ausgabe)

C bietet **keine eingebaute Funktion**, um einen `enum`-Wert automatisch in einen Namen umzuwandeln (anders als z.B. in Java oder C#). Das muss man selbst implementieren – typischerweise mit einem String-Array oder `switch`:

**Methode 1 – String-Array (Index = enum-Wert):**

```c
typedef enum { MONTAG, DIENSTAG, MITTWOCH, DONNERSTAG, FREITAG, SAMSTAG, SONNTAG } Wochentag;
 
const char *wochentagName(Wochentag tag) {
    const char *namen[] = {
        "Montag", "Dienstag", "Mittwoch", "Donnerstag",
        "Freitag", "Samstag", "Sonntag"
    };
    return namen[tag];   // enum-Wert als Array-Index nutzen!
}
 
int main(void) {
    Wochentag heute = MITTWOCH;
    printf("Heute ist %s\n", wochentagName(heute));  // "Heute ist Mittwoch"
    return 0;
}
```

> **Voraussetzung:** Diese Methode funktioniert nur, wenn die enum-Werte **lückenlos ab 0** durchnummeriert sind. Bei Sprüngen (z.B. `HTTP_OK = 200`) funktioniert das nicht direkt.

**Methode 2 – `switch`-Anweisung (funktioniert auch bei Sprüngen):**

```c
typedef enum { HTTP_OK = 200, HTTP_NOT_FOUND = 404, HTTP_SERVER_ERROR = 500 } HttpStatus;
 
const char *statusName(HttpStatus status) {
    switch (status) {
        case HTTP_OK:           return "OK";
        case HTTP_NOT_FOUND:    return "Not Found";
        case HTTP_SERVER_ERROR: return "Server Error";
        default:                return "Unbekannt";
    }
}
```

### 6.4 `string` → `enum` (Eingabe verarbeiten)

Auch hier gibt es keine automatische Konvertierung – man vergleicht Strings manuell:

```c
#include <string.h>
 
typedef enum { ROT, GELB, GRUEN, UNGUELTIG } Ampelfarbe;
 
Ampelfarbe parseFarbe(char *text) {
    if (strcmp(text, "rot") == 0)   return ROT;
    if (strcmp(text, "gelb") == 0)  return GELB;
    if (strcmp(text, "gruen") == 0) return GRUEN;
    return UNGUELTIG;   // Fehlerfall explizit als enum-Wert abbilden
}
```

> **Guter Stil:** Einen eigenen `UNGUELTIG`/`UNKNOWN`-Wert im `enum` vorzusehen, ist eine bewährte Praxis für Fehlerfälle bei Konvertierungen.

### 6.5 Zusammenfassung Konvertierungen

| **Richtung**      | **Automatisch?**            | **Risiko**                    |
| ----------------- | --------------------------- | ----------------------------- |
| `enum` → `int`    | Ja, implizit                | Keines                        |
| `int` → `enum`    | Compiliert, aber ungeprüft  | Ungültige Werte möglich       |
| `enum` → `string` | Nein, selbst implementieren | Array-Index oder switch nötig |
| `string` → `enum` | Nein, selbst implementieren | Tippfehler im Eingabestring   |

---

## 7. Zusammenfassung

```console
┌──────────────────────────────────────────────────────────────────┐
│                    Enum in C – Übersicht                         │
├────────────────────────┬─────────────────────────────────────────┤
│ Zweck                  │ Lesbare Namen statt Magic Numbers       │
│ Deklaration            │ typedef enum { A, B, C } Name;          │
│ Automatische Werte     │ Start bei 0, dann +1 pro Eintrag        │
│ Eigene Werte           │ enum { A = 5, B, C }  → B=6, C=7        │
│ enum → int             │ automatisch (implizit)                  │
│ int → enum             │ Cast nötig, NICHT geprüft!               │
│ enum → String          │ Array-Index oder switch (manuell)       │
│ String → enum          │ strcmp-Vergleiche (manuell)             │
│ Einsatzgebiet          │ Feste Menge benannter Zustände/Kategorien│
│ Kein Einsatzgebiet     │ Laufzeitwerte, Messdaten, freie Zahlen  │
└────────────────────────┴─────────────────────────────────────────┘
```

### Die goldene Regel

> **Wenn eine feste Liste von benannten Möglichkeiten benötigt wird, ist `enum` fast immer die richtige Wahl.** Es macht aus rätselhaften Zahlen sprechende Namen – und damit den Code für dich und andere sofort verständlicher.

---

# Aufgaben

## Aufgabe Erste eigene Enum

| **Vorgabe**         | **Beschreibung**                                            |
| :------------------ | :---------------------------------------------------------- |
| **Lernziele**       | Verstehen wie enum's deklariert und initialisiert werden    |
|                     | Kann Aufzählungsvariablen zur besseren Lesbarkeit einsetzen |
|                     | Kann Konvertierungen von und zu Aufzählungstypen umsetzten  |
| **Sozialform**      | Einzelarbeit                                                |
| **Auftrag**         | siehe unten                                                 |
| **Hilfsmittel**     |                                                             |
| **Zeitbedarf**      | 30min                                                       |
| **Lösungselemente** | Funktionierendes Programm                                   |

Erstelle ein `enum Jahreszeit` mit den Werten `FRUEHLING`, `SOMMER`, `HERBST`, `WINTER`.

Schreibe eine Funktion `void beschreibeJahreszeit(Jahreszeit j)`, die je nach Jahreszeit eine passende Aktivität ausgibt (z.B. "Frühling: Blumen pflanzen").

Teste die Funktion mit allen vier Werten in `main()`.

**Erwartete Ausgabe (Beispiel):**

```console
Frühling: Blumen pflanzen
Sommer: Schwimmen gehen
Herbst: Blätter sammeln
Winter: Schlitten fahren
```

---

## Aufgabe 2 – Ampelsteuerung mit Zustandswechsel

| **Vorgabe**         | **Beschreibung**                                            |
| :------------------ | :---------------------------------------------------------- |
| **Lernziele**       | Verstehen wie enum's deklariert und initialisiert werden    |
|                     | Kann Aufzählungsvariablen zur besseren Lesbarkeit einsetzen |
|                     | Kann Konvertierungen von und zu Aufzählungstypen umsetzten  |
| **Sozialform**      | Einzelarbeit                                                |
| **Auftrag**         | siehe unten                                                 |
| **Hilfsmittel**     |                                                             |
| **Zeitbedarf**      | 30min                                                       |
| **Lösungselemente** | Funktionierendes Programm                                   |

Verwende das `Ampelfarbe`-Enum (`ROT`, `GELB`, `GRUEN`).

Implementiere:

1. `Ampelfarbe naechsteFarbe(Ampelfarbe aktuell)` – gibt die nächste Farbe im Zyklus zurück (`ROT → GRUEN → GELB → ROT`)
2. `const char *farbname(Ampelfarbe f)` – gibt den Namen als String zurück
3. Eine Simulation in `main()`, die 8 Schritte lang die Ampel durchschaltet

### Erwartete Ausgabe

```console
Schritt 1: ROT
Schritt 2: GRUEN
Schritt 3: GELB
Schritt 4: ROT
Schritt 5: GRUEN
Schritt 6: GELB
Schritt 7: ROT
Schritt 8: GRUEN
```
