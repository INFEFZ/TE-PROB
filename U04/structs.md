|                             |                          |                                        |
| --------------------------- | ------------------------ | -------------------------------------- |
| **Elektrotechniker/-in HF** | **Programmiertechnik B** | ![IPSO Logo](./x_gitres/ipso_logo.png) |

- [1. Strukturen (structs)](#1-strukturen-structs)
  - [1.1. E-Book](#11-e-book)
  - [1.2. Was ist eine struct in C?](#12-was-ist-eine-struct-in-c)
  - [1.3. Vorteile und Einsatzbereiche](#13-vorteile-und-einsatzbereiche)
  - [1.4. Einsatzbereiche](#14-einsatzbereiche)
  - [1.5. Definition und Deklaration von Strukturen](#15-definition-und-deklaration-von-strukturen)
  - [1.6. Initialisierung und Zugriff](#16-initialisierung-und-zugriff)
  - [1.7. Zeiger auf Strukturen](#17-zeiger-auf-strukturen)
  - [1.8. Struktur innerhalb einer Struktur (verschachtelte Strukturen)](#18-struktur-innerhalb-einer-struktur-verschachtelte-strukturen)
  - [1.9. Struktur als Funktionsparameter](#19-struktur-als-funktionsparameter)
  - [1.10. typedef zur Vereinfachung](#110-typedef-zur-vereinfachung)
  - [1.11. Beispiel: Einfaches Programm mit struct und Funktion](#111-beispiel-einfaches-programm-mit-struct-und-funktion)
- [2. Aufgaben](#2-aufgaben)
  - [2.1. Aufgabe Strukturelemente untersuchen](#21-aufgabe-strukturelemente-untersuchen)
  - [2.2. Aufgabe Studentenverwaltungssystem](#22-aufgabe-studentenverwaltungssystem)
  - [2.3. Aufgabe Studentenverwaltungssystem mit Verschachtelung](#23-aufgabe-studentenverwaltungssystem-mit-verschachtelung)

---

# 1. Strukturen (structs)

## 1.1. E-Book

![Strukturen, Unionen und Bitfelder](./x_gitres/k13-strukturen-unionen-und-bitfelder.pdf)

## 1.2. Was ist eine struct in C?

In C sind `struct` (Strukturen) eine Möglichkeit, **benutzerdefinierte Datentypen** zu erstellen, die mehrere Werte unterschiedlicher Typen unter einem Namen zusammenfassen.

Strukturen (`struct`) sind ein essenzieller Bestandteil der C-Programmierung:

- Sie ermöglichen den Aufbau komplexer Datentypen.
- Der Zugriff ist flexibel (direkt oder über Zeiger).
- Sie sind Basis für moderne Programmiertechniken wie Datenkapselung und objektähnliches Denken.

```c
struct Person {
    char name[50];
    int alter;
    float gehalt;
};
```

- Diese Struktur fasst **Name**, **Alter** und **Gehalt** einer Person zusammen.
- Sie verhält sich wie ein **Container** für zusammengehörige Daten

## 1.3. Vorteile und Einsatzbereiche

- Strukturierung komplexer Daten (z. B. Person, Auto, Buch, Konto)
- Modularität und Wartbarkeit durch benannte Einheiten
- Unterstützt datenzentrierte Programmierung
- Wichtig für den Einsatz in Algorithmen, Dateien, Zeigern, Schnittstellen

## 1.4. Einsatzbereiche

- Darstellung von Datensätzen (z. B. eine Kundenkartei)
- Verwendung in Verketteten Listen, Bäumen oder Stacks
- Grundlage für Datenstrukturen in größeren Projekten
- Übergabe komplexer Daten an Funktionen
- Paketieren von Informationen, z. B. beim Serialisieren

## 1.5. Definition und Deklaration von Strukturen

**Strukturdefinition:**

```c
struct Buch {
    char titel[100];
    char autor[50];
    int jahr;
};
```

> **Eine Strukturdefinition erstellt einen neuen Datentyp, aber noch keine Variable.**

**Variablendeklaration:**

```c
struct Buch meinBuch;
```

> **Mit meinBuch existiert jetzt eine Instanz der Struktur Buch.**

## 1.6. Initialisierung und Zugriff

**Direkte Initialisierung:**

```c
struct Buch b1 = {"Der C Programmierer", "M. Mustermann", 2020};
```

**Zugriff auf Strukturmitglieder:**

```c
printf("Titel: %s\n", b1.titel);
b1.jahr = 2021;
```

> **Zugriff erfolgt mit Punktoperator .**

## 1.7. Zeiger auf Strukturen

Ein Strukturzeiger zeigt auf eine Strukturinstanz – besonders nützlich beim Funktionsaufruf oder dynamischer Speicherverwaltung.

```c
struct Buch *ptr = &b1;
printf("Autor: %s\n", ptr->autor);  // Zugriff über -> (statt .)
```

> Wichtig:
> **.** Zugriff über Variable
> **->** Zugriff über Zeiger

## 1.8. Struktur innerhalb einer Struktur (verschachtelte Strukturen)

Strukturen können andere Strukturen enthalten:

```c
struct Datum {
    int tag;
    int monat;
    int jahr;
};

struct Person {
    char name[50];
    struct Datum geburtsdatum;  // verschachtelte Struktur
};
```

**Zugriff:**

```c
struct Person p1;
p1.geburtsdatum.tag = 15;
p1.geburtsdatum.monat = 7;
```

## 1.9. Struktur als Funktionsparameter

**Übergabe per Wert (Kopie):**

```c
void druckeBuch(struct Buch b) {
    printf("Titel: %s\n", b.titel);
}
```

**Übergabe per Zeiger (Referenz):**

```c
void aendereJahr(struct Buch *b) {
    b->jahr = 2024;
}
```

> **Vorteil bei Zeiger: Speicher effizienter, Original wird verändert.**

## 1.10. typedef zur Vereinfachung

Mit `typedef` lässt sich der Strukturname kürzer gestalten:

```c
typedef struct {
    char marke[20];
    int baujahr;
} Auto;

Auto a1 = {"BMW", 2022};  // Kein struct nötig
```

## 1.11. Beispiel: Einfaches Programm mit struct und Funktion

```c
#include <stdio.h>
#include <string.h>

struct Student {
    char name[30];
    int matrikel;
};

void printStudent(struct Student s) {
    printf("Name: %s, Matrikelnummer: %d\n", s.name, s.matrikel);
}

int main() {
    struct Student s1;
    strcpy(s1.name, "Anna");
    s1.matrikel = 123456;

    printStudent(s1);
    return 0;
}
```

---

# 2. Aufgaben

## 2.1. Aufgabe Strukturelemente untersuchen

| **Vorgabe**         | **Beschreibung**                                               |
| :------------------ | :------------------------------------------------------------- |
| **Lernziele**       | Einsatzbereich von Strukturen kennen                           |
|                     | Elemente einer Struktur interpretieren                         |
|                     | String Elemente u. Pointer in einer Struktur korrekt einsetzen |
| **Sozialform**      | Partnerarbeit                                                  |
| **Auftrag**         | siehe unten                                                    |
| **Hilfsmittel**     |                                                                |
| **Zeitbedarf**      | 10min                                                          |
| **Lösungselemente** | Funktionierendes Programm                                      |

Studieren Sie das folgende Programm:
a) Welche Codezeilen werden einen Fehler erzeugen? Überprüfen Sie Ihre Annahmen mit Hilfe des Compilers.
b) Korrigieren Sie die Fehler, sodass das Programm lauffähig wird.
c) Was wird nun ausgegeben werden? Überprüfen Sie Ihre Annahmen miteinem Programmdurchlauf.

```c
#include <stdio.h>

struct Person { 
    char vorname[30];
    char* nachname;
};

int main(void) {
    struct Person person1 = {"Kathrin", "Knoll"};
    struct Person person2 = {"Thorsten", "Powlov"};

    person1.vorname = "Maria";
    person1.nachname = "Hanse";
    printf("%s %s\n", person1.vorname, person1.nachname);

    person1.vorname = person2.vorname;
    person1.nachname = person2.nachname;
    printf("%s %s\n", person1.vorname, person1.nachname);

    person1 = person2;
    printf("%s %s\n", person1.vorname, person1.nachname);

    person2.nachname = "Frick";
    printf("%s %s\n", person2.vorname, person2.nachname);

    return 0;
}
```

---

## 2.2. Aufgabe Studentenverwaltungssystem

| **Vorgabe**         | **Beschreibung**                               |
| :------------------ | :--------------------------------------------- |
| **Lernziele**       | Strukturen deklariert und initialisiert werden |
|                     | Kann eine Struktur an eine Funktion übergeben  |
|                     | Kann auf Elemente einer Struktur zugreifen     |
|                     | Kann Strukturen in einem Array verwalten       |
| **Sozialform**      | Einzelarbeit                                   |
| **Auftrag**         | siehe unten                                    |
| **Hilfsmittel**     |                                                |
| **Zeitbedarf**      | 50min                                          |
| **Lösungselemente** | Funktionierendes Programm                      |

**Auftrag:**

- Erstelle ein einfaches Studentenverwaltungssystem, das Informationen über Studenten speichert und ausgibt.
- Jeder Student hat eine Martikelnummer, einen Namen und eine Durchschnittsnote.

**Anforderung:**

- Deklariere eine Struktur `Student`, die die folgenden Felder enthält:
  - `int martikelnummer`
  - `char name[50]`
  - `float durchschnittsnote`
- Schreibe eine Funktion `void printStudent(struct Student s)`, die die Informationen eines Studenten ausgibt
- Schreibe eine Funktion `struct Student createStudent(int martikelnummer, char name[], float durchschnittsnote)`, die einen neuen Studenten erstellt und zurückgibt
- Erstelle im `main()` Programm ein Array von `Student`-Strukturen, um die Informationen von 3 Studenten zu speichern.
- Fülle die Informationen der 3 Studenten aus und gebe diese anschliessend mit der Funktion `printStudent()` aus.

---

## 2.3. Aufgabe Studentenverwaltungssystem mit Verschachtelung

| **Vorgabe**         | **Beschreibung**                               |
| :------------------ | :--------------------------------------------- |
| **Lernziele**       | Strukturen deklariert und initialisiert werden |
|                     | Kann eine Struktur an eine Funktion übergeben  |
|                     | Kann auf Elemente einer Struktur zugreifen     |
|                     | Kann Strukturen in einem Array verwalten       |
|                     | Kann Strukturen verschachteln                  |
| **Sozialform**      | Einzelarbeit                                   |
| **Auftrag**         | siehe unten                                    |
| **Hilfsmittel**     |                                                |
| **Zeitbedarf**      | 30min                                          |
| **Lösungselemente** | Funktionierendes Programm                      |

**Auftrag:**

Erweitere die Aufgabe oben, mit zusätzlichem Feld Geburtstag, das sich wie folgt zusammensetzt:

- `int tag`
- `int monat`
- `int jahr`

Implementiere das Geburtstagfeld auch in den jeweiligen Funktion (`print..`, `create..`).
