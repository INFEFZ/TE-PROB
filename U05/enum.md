|                             |                          |                                        |
| --------------------------- | ------------------------ | -------------------------------------- |
| **Elektrotechniker/-in HF** | **Programmiertechnik B** | ![IPSO Logo](./x_gitres/ipso_logo.png) |

- [1. Aufzählungstypen (enum)](#1-aufzählungstypen-enum)
  - [1.1. Was ist ein `enum`?](#11-was-ist-ein-enum)
  - [1.2. Konvertierung zu `int`](#12-konvertierung-zu-int)
  - [1.3. Beispiel Menüsystem mit `enum`](#13-beispiel-menüsystem-mit-enum)
  - [1.4. Zusammenfassung](#14-zusammenfassung)
- [2. Aufgaben](#2-aufgaben)
  - [2.1. Aufgabe Programmsteuerung](#21-aufgabe-programmsteuerung)
  - [2.2. Aufgabe Ampelsteuerung](#22-aufgabe-ampelsteuerung)

---

# 1. Aufzählungstypen (enum)

## 1.1. Was ist ein `enum`?

- Der Schlüsselwort `enum` (kurz für "enumeration", dt. Aufzählung) ermöglicht es in C, benannte ganzzahlige Konstanten zu definieren.
- Es handelt sich dabei um eine **benutzerdefinierte Datendefinition**, die **lesbare Namen** für ganzzahlige Werte zur Verfügung stellt.

**Beispiel:**

```c
enum Wochentag { MONTAG, DIENSTAG, MITTWOCH, DONNERSTAG, FREITAG };
```

**Dabei erhält:**

- MONTAG den Wert 0
- DIENSTAG den Wert 1
- ...
- FREITAG den Wert 4

> **Standardmässig beginnt die Zählung bei 0, kann aber auch manuell festgelegt werden.**

</br>

**Sinn und Zweck:**

| **Vorteil**          | **Beschreibung**                                             |
| :------------------- | :----------------------------------------------------------- |
| **Lesbarkeit**       | Ersetzt kryptische Zahlen durch sprechende Namen             |
| **Wartbarkeit**      | Änderungen an den Werten müssen nur an einer Stelle erfolgen |
| **Typprüfung**       | Compiler kann eingeschränkte Werte prüfen                    |
| **Fehlervermeidung** | Keine "**magic numbers**" im Code                            |

**Bad:**

```c
int tag = 2;
if (tag == 2) { printf("Heute ist Mittwoch.\n"); }
```

**Good:**

```c
enum Wochentag tag = MITTWOCH;
if (tag == MITTWOCH) { printf("Heute ist Mittwoch.\n"); }
```

## 1.2. Konvertierung zu `int`

Ein enum-Wert ist intern ein `int`. Man kann ihn direkt als Zahl behandeln:

```c
printf("Zahlenwert von FEHLER: %d\n", FEHLER);  // Ausgabe: 10

int code = zustand;  // implizite Konvertierung enum → int
```

## 1.3. Beispiel Menüsystem mit `enum`

```c
#include <stdio.h>

enum MenueOption {
    NEU = 1,
    LADEN,
    SPEICHERN,
    BEENDEN
};

int main() {
    enum MenueOption auswahl;

    printf("Menü:\n");
    printf("1 = Neu\n2 = Laden\n3 = Speichern\n4 = Beenden\n");
    printf("Bitte wählen: ");
    scanf("%d", (int*)&auswahl);  // expliziter cast notwendig

    switch (auswahl) {
        case NEU:
            printf("Neues Spiel wird gestartet.\n");
            break;
        case LADEN:
            printf("Spielstand wird geladen.\n");
            break;
        case SPEICHERN:
            printf("Spielstand wird gespeichert.\n");
            break;
        case BEENDEN:
            printf("Programm wird beendet.\n");
            break;
        default:
            printf("Ungültige Auswahl.\n");
    }

    return 0;
}
```

## 1.4. Zusammenfassung

| **Aspekt**            | **Beschreibung**                                 |
| :-------------------- | :----------------------------------------------- |
| **Was ist enum?**     | Benannte ganzzahlige Werte (**Aufzählungen**)    |
| **Vorteile**          | Lesbarkeit, Wartbarkeit, Fehlervermeidung        |
| **Deklaration**       | `enum Farbe { ROT, GRUEN, BLAU };`               |
| **Initialisierung**   | `enum Farbe f = ROT;`                            |
| **Zugriff**           | Vergleich, Zuweisung wie bei `int`               |
| **Konvertierung**     | Automatisch zu `int`, umgekehrt nur mit Vorsicht |
| **Typischer Einsatz** | Statuswerte, Zustände, Menüoptionen, etc.        |

---

</br>

# 2. Aufgaben

## 2.1. Aufgabe Programmsteuerung

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

Schreibe ein C-Programm, das mithilfe eines `enum`-Typs ein einfaches Programm zur Verwaltung eines Gerätestatus erstellt.
Definiere einen `enum`-Typ GeraeteStatus mit folgenden Zuständen:

- `AUS (0)`
- `STANDBY (1)`
- `AKTIV (2)`
- `FEHLER (3)`

- Deklariere eine Variable `status` vom Typ GeraeteStatus und initialisiere sie mit `STANDBY`.
- Frage den Benutzer (über `scanf`), welchen Status er setzen möchte (durch Eingabe einer Ganzzahl 0–3).
- Wandle die eingegebene Ganzzahl in einen `enum`-Wert um und speichere ihn in `status`.
- Verwende eine `switch`-Anweisung, um abhängig vom aktuellen Status eine passende Meldung auszugeben:
  - Bei `AUS`: "Gerät ist ausgeschaltet."
  - Bei `STANDBY`: "Gerät ist im Standby."
  - Bei `AKTIV`: "Gerät läuft."
  - Bei `FEHLER`: "Gerät hat einen Fehler!"
- Optional: Gebe den zugehörigen Ganzzahlwert des Status mit aus.

---

## 2.2. Aufgabe Ampelsteuerung

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

Erstelle ein C-Programm zur Simulation einer einfachen **Ampelsteuerung** mit Hilfe eines `enum`-Typs.

 **Definition eines enum-Typs:**

- Definiere einen enum-Typ AmpelPhase mit folgenden Phasen:
  - `ROT`
  - `ROT_GELB`
  - `GRUEN`
  - `GELB`

**Steuerlogik:**

- Implementiere eine Funktion `naechstePhase(enum AmpelPhase aktuelle)`, die die nächste Phase der Ampel zurückgibt (als `enum`-Wert).
- Der Ablauf soll wie folgt sein:
  - **ROT → ROT_GELB → GRUEN → GELB → ROT → ...**

**Hauptprogramm:**

- Initialisiere die Ampel mit dem Status ROT.
- Frage den Benutzer, wie viele Phasenwechsel er simulieren möchte.
- Führe entsprechend viele Wechsel durch und gebe dabei jeweils die aktuelle Phase als Text und Zahl aus.

```console
Anzahl der Phasenwechsel: 6

Phase: ROT (0)
Phase: ROT_GELB (1)
Phase: GRUEN (2)
Phase: GELB (3)
Phase: ROT (0)
Phase: ROT_GELB (1)
```
