|                             |                          |                                        |
| --------------------------- | ------------------------ | -------------------------------------- |
| **Elektrotechniker/-in HF** | **Programmiertechnik B** | ![IPSO Logo](./x_gitres/ipso_logo.png) |

</br>

# Gruppenarbeit String's

## Ziel der Gruppenarbeit

In dieser Gruppenarbeit sollt ihr die Grundlagen und weiterführende Aspekte der **Zeichenkettenverarbeitung** (Strings) in C kennenlernen. Dazu gehören die Deklaration, Verarbeitung, typische Funktionen sowie der Umgang mit Strings bei der Funktionsübergabe. Die Arbeit ist praktisch orientiert und soll in Form einer **Präsentation (PowerPoint oder Markdown)** abschliessend vorgestellt werden.

## Gruppe 1: Grundlagen von Strings in C

**Themen:**

- Erklärt, wie Strings in C funktionieren und was sie von anderen Sprachen unterscheidet.
- Erarbeitet das grundlegende Konzept: Strings als char-Arrays mit `'\0'`-Terminierung.
- Zeigt die Deklaration und Initialisierung von Strings auf verschiedene Arten.
- Erklärt die Bedeutung und Rolle von String-Terminierung (`'\0'`).

**Codebeispiele:**

- Initialisierung eines Strings mit und ohne `'\0`'
- Falsche Terminierung und ihre Folgen (z. B. fehlerhafte Ausgabe)

**Fragen:**

- Was passiert bei einem fehlenden `'\0'`?
- Wie unterscheiden sich Stringliterale von selbst gesetzten Arrays?

> **Ergebnis: Kurze Erklärung (max. 5 Minuten), inklusive einfachem Beispiel und ggf. Skizze.**

---

</br>

## Gruppe 2: Ein- und Ausgabe von Strings

**Themen:**

- Untersucht verschiedene Arten, wie man Strings vom Benutzer einlesen und ausgeben kann.
- Vergleicht `scanf()` mit `fgets()` – was sind die Vor- und Nachteile?
- Zeigt den sicheren Umgang mit Zeichenketten bei der Ein- und Ausgabe.

**Codebeispiele:**

- Einlesen eines Strings mit `scanf()` und Vergleich mit `fgets()`
- Entfernen des `\n` bei `fgets()` und Erklärungen dazu

**Fragen:**

- Warum ist `fgets()` oft sicherer als `scanf()`?
- Wie geht man mit Leerzeichen und Zeilenumbrüchen bei der Eingabe um?

> **Ergebnis: Kurze Erklärung (max. 5 Minuten) mit Beispielcode und Erläuterung.**

---

</br>

### Gruppe 3: Arbeiten mit Stringfunktionen & Übergabe an Funktionen

**Themen:**

- Stellt die wichtigsten Funktionen aus `<string.h>` vor:
  - `strlen()`, `strcpy()`, `strcmp()`, `strcat()`, `strchr()`, `strstr()`, ...
- Zeigt Beispiele, wie man Strings an Funktionen übergibt und verändert.
- Achtet auf Speichergrenzen und sichere Varianten wie `strncpy()`.

**Codebeispiele:**

- Vergleich zweier Strings mit `strcmp()` + Auswertung
- Kopieren/Anhängen von Strings mit `strcpy()` und `strcat()`
- Übergabe eines Strings an eine eigene Funktion (z.B. zur Grossschreibung)

**Fragen:**

- Welche Fehler passieren beim Einsatz von `strcpy()` und wie vermeidet man sie?
- Was bedeutet "**Call by Reference**" bei Strings?

> **Ergebnis: Kurze Erklärung (max. 5 Minuten) mit jeweils einem Beispiel pro Mechanismus.**

---

## Arbeitszeit

- 45 Minuten Gruppenarbeit + 3 × 1 Minuten Präsentation + kurze Nachbesprechung
