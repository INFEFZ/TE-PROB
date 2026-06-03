|                             |                          |                               |
| --------------------------- | ------------------------ | ----------------------------- |
| **Elektrotechniker/-in HF** | **Programmiertechnik B** | ![Logo](../x_gitres/logo.png) |

- [1. Strukturen (struct's)](#1-strukturen-structs)
  - [1.1. Was ist eine struct in C?](#11-was-ist-eine-struct-in-c)
  - [1.2. Vorteile und Einsatzbereiche](#12-vorteile-und-einsatzbereiche)
  - [1.3. Einsatzbereiche](#13-einsatzbereiche)
  - [1.4. Definition und Deklaration von Strukturen](#14-definition-und-deklaration-von-strukturen)
    - [1.4.1. Beispiel struct Point](#141-beispiel-struct-point)
  - [1.5. Initialisierung und Zugriff](#15-initialisierung-und-zugriff)
  - [1.6. Zeiger auf Strukturen](#16-zeiger-auf-strukturen)
  - [1.7. Struktur innerhalb einer Struktur (verschachtelte Strukturen)](#17-struktur-innerhalb-einer-struktur-verschachtelte-strukturen)
  - [1.8. Struktur als Funktionsparameter](#18-struktur-als-funktionsparameter)
  - [1.9. typedef zur Vereinfachung](#19-typedef-zur-vereinfachung)
  - [1.10. Beispiel: Einfaches Programm mit struct und Funktion](#110-beispiel-einfaches-programm-mit-struct-und-funktion)
- [2. Bitfelder](#2-bitfelder)
  - [2.1. Was sind Bitfelder (Bitfields)?](#21-was-sind-bitfelder-bitfields)
  - [2.2. Einsatzbereiche von Bitfeldern](#22-einsatzbereiche-von-bitfeldern)
  - [2.3. Vorteile von Bitfeldern](#23-vorteile-von-bitfeldern)
  - [2.4. Definition \& Deklaration von Bitfeldern](#24-definition--deklaration-von-bitfeldern)
  - [2.5. Initialisierung von Bitfeldern](#25-initialisierung-von-bitfeldern)
  - [2.6. Zugriff auf Bitfelder](#26-zugriff-auf-bitfelder)
  - [2.7. Beispiel: Flags für Systemstatus](#27-beispiel-flags-für-systemstatus)
  - [2.8. Bitfelder und Platzersparnis – Beispielvergleich](#28-bitfelder-und-platzersparnis--beispielvergleich)
  - [2.9. Einschränkungen und Hinweise](#29-einschränkungen-und-hinweise)
- [3. Aufgaben](#3-aufgaben)
  - [3.1. Aufgabe Strukturelemente untersuchen](#31-aufgabe-strukturelemente-untersuchen)
  - [3.2. Aufgabe Studentenverwaltungssystem](#32-aufgabe-studentenverwaltungssystem)
  - [3.3. Aufgabe Studentenverwaltungssystem mit Verschachtelung](#33-aufgabe-studentenverwaltungssystem-mit-verschachtelung)
  - [3.4. Aufgabe SmartLight](#34-aufgabe-smartlight)

---

</br>

# 1. Strukturen (struct's)

## 1.1. Was ist eine struct in C?

In C sind `struct` (Strukturen) eine Möglichkeit, **benutzerdefinierte Datentypen** zu erstellen, die mehrere Werte unterschiedlicher Typen unter einem Namen zusammenfassen.

Strukturen (`struct`) sind ein **essenzieller Bestandteil** der C-Programmierung:

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

## 1.2. Vorteile und Einsatzbereiche

- Strukturierung komplexer Daten (z. B. Person, Auto, Buch, Konto)
- Modularität und Wartbarkeit durch benannte Einheiten
- Unterstützt datenzentrierte Programmierung
- Wichtig für den Einsatz in Algorithmen, Dateien, Zeigern, Schnittstellen

## 1.3. Einsatzbereiche

- Darstellung von Datensätzen (z. B. eine Kundenkartei)
- Verwendung in Verketteten Listen, Bäumen oder Stacks
- Grundlage für Datenstrukturen in grösseren Projekten
- Übergabe komplexer Daten an Funktionen
- Paketieren von Informationen, z. B. beim Serialisieren

## 1.4. Definition und Deklaration von Strukturen

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

### 1.4.1. Beispiel struct Point

```c
#include <stdio.h>

// Definition der struct für einen Punkt im 2D-Raum
struct Point 
{
    int x;
    int y;
};

// Funktion zur Ausgabe der Koordinaten eines Punktes
void printPoint(struct Point p) 
{
    printf("Punktkoordinaten: (%d, %d)\n", p.x, p.y);
}

void main() 
{
    // Deklaration und Initialisierung eines Punktes
    struct Point point1;
    point1.x = 5;
    point1.y = 10;

    // Ausgabe der Koordinaten des Punktes
    printPoint(point1);
}
```

## 1.5. Initialisierung und Zugriff

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

## 1.6. Zeiger auf Strukturen

Ein Strukturzeiger zeigt auf eine Strukturinstanz – besonders nützlich beim Funktionsaufruf oder dynamischer Speicherverwaltung.

```c
struct Buch *ptr = &b1;
printf("Autor: %s\n", ptr->autor);  // Zugriff über -> (statt .)
```

> Wichtig:
> **.** Zugriff über Variable
> **->** Zugriff über Zeiger

## 1.7. Struktur innerhalb einer Struktur (verschachtelte Strukturen)

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

## 1.8. Struktur als Funktionsparameter

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

## 1.9. typedef zur Vereinfachung

Mit `typedef` lässt sich der Strukturname kürzer gestalten:

```c
typedef struct {
    char marke[20];
    int baujahr;
} Auto;

Auto a1 = {"BMW", 2022};  // Kein struct nötig
```

## 1.10. Beispiel: Einfaches Programm mit struct und Funktion

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

</br>

# 2. Bitfelder

## 2.1. Was sind Bitfelder (Bitfields)?

- Ein **Bitfeld** in C ist eine Möglichkeit, mehrere Werte (normalerweise Flags oder kleine Ganzzahlen) in einer Struktur platzsparend auf Bit-Ebene zu speichern.
- Statt jedem Wert ein ganzes Byte oder Word zuzuweisen, kann man z.B. sagen: "Dieser Wert braucht nur 1 Bit."
- Ein **Bitfeld** ist also eine strukturierte Variable, bei der einzelne Mitglieder eine bestimmte Anzahl von Bits belegen.

![Bitfelder](./x_gitres/bitfelder.png)

## 2.2. Einsatzbereiche von Bitfeldern

**Bitfelder** werden häufig eingesetzt, wenn:

- Speicher gespart werden soll (z. B. in eingebetteten Systemen).
- Flags oder Schalter effizient gespeichert werden sollen.
- Daten mit fester Bitstruktur (z. B. Hardware-Register, Netzwerkprotokolle) verarbeitet werden.
- Bits für Zugriffsrechte, Statusinformationen, Zustände usw. verwaltet werden.

## 2.3. Vorteile von Bitfeldern

| **Vorteil**                             | **Erklärung**                              |
| :-------------------------------------- | :----------------------------------------- |
| **Speicherersparnis**                   | Statt ganzer Bytes/Ints nur benötigte Bits |
| **Lesbarer und strukturierter Code**    | Besser als manuelle Bitmasken              |
| **Ideal für Zustände, Flags, Hardware** | Genau abgestimmte Bitrepräsentation        |
| **Einfacher Zugriff über Feldnamen**    | Kein manuelles Bitshifting notwendig       |

## 2.4. Definition & Deklaration von Bitfeldern

**Bitfelder** werden innerhalb einer `struct` deklariert. Die Syntax lautet:

```c
struct name {
    typ feldname : anzahl_bits;
};
```

```c
struct Status {
    unsigned int fehler : 1;
    unsigned int bereit : 1;
    unsigned int aktiv  : 1;
};
```

Hier werden 3 Flags (fehler, bereit, aktiv) definiert, jeweils mit nur 1 Bit.
> **Typischerweise wird unsigned int oder unsigned verwendet, um unerwünschte Vorzeichenverhalten zu vermeiden.**

## 2.5. Initialisierung von Bitfeldern

**Bitfelder** können beim Anlegen eines Objekts initialisiert werden – ähnlich wie bei normalen Strukturen:

```c
struct Status {
    unsigned int fehler : 1;
    unsigned int bereit : 1;
    unsigned int aktiv  : 1;
};

struct Status systemStatus = {1, 0, 1};  // fehler=1, bereit=0, aktiv=1
```

## 2.6. Zugriff auf Bitfelder

Der Zugriff erfolgt wie bei normalen Strukturelementen:

```c
if (systemStatus.fehler) {
    printf("Fehler erkannt!\n");
}

systemStatus.bereit = 1;
```

> **Man kann Bitfelder lesen und schreiben wie normale Variablen. Werte ausserhalb der Bitgrösse werden automatisch abgeschnitten.**

## 2.7. Beispiel: Flags für Systemstatus

```c
#include <stdio.h>

struct Status {
    unsigned int fehler : 1;
    unsigned int bereit : 1;
    unsigned int aktiv  : 1;
    unsigned int reserviert : 5;  // z.B. Platz für Erweiterung
};

int main() {
    struct Status status = {0, 1, 1, 0};

    printf("System bereit: %d\n", status.bereit);
    printf("System aktiv: %d\n", status.aktiv);

    status.fehler = 1;

    if (status.fehler) {
        printf("Achtung: Fehler erkannt!\n");
    }

    return 0;
}
```

```console
System bereit: 1
System aktiv: 1
Achtung: Fehler erkannt!
```

## 2.8. Bitfelder und Platzersparnis – Beispielvergleich

```c
struct FlagsNormal {
    unsigned char fehler;
    unsigned char bereit;
    unsigned char aktiv;
};  // benötigt 3 Bytes

struct FlagsBitfield {
    unsigned char fehler : 1;
    unsigned char bereit : 1;
    unsigned char aktiv  : 1;
};  // benötigt in der Praxis oft nur 1 Byte
```

## 2.9. Einschränkungen und Hinweise

| **Einschränkung**             | **Beschreibung**                                                                                               |
| :---------------------------- | :------------------------------------------------------------------------------------------------------------- |
| **Plattformabhängigkeit**     | Bitreihenfolge (MSB/LSB) ist **nicht standardisiert** – Vorsicht bei Datenübertragung oder Speicherabbildungen |
| **Kein Zeiger auf Bitfelder** | Man kann **keine Adresse** eines Bitfelds nehmen (`&struct.bf` ist nicht erlaubt)                              |
| **Nur ganze Typen**           | Nur `int`, `unsigned int`, `signed int` (und Varianten wie `short`, `char`) erlaubt                            |
| **Kein Array von Bitfeldern** | Bitfelder können **nicht direkt** als Arrays verwendet werden                                                  |

---

</br>

# 3. Aufgaben

## 3.1. Aufgabe Strukturelemente untersuchen

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

Studiere das folgende Programm:

- Welche Codezeilen werden einen Fehler erzeugen? Überprüfe Ihre Annahmen mit Hilfe des Compilers.
- Korrigiere die Fehler, sodass das Programm lauffähig wird.
- Was wird nun ausgegeben werden? Überprüfe Ihre Annahmen miteinem Programmdurchlauf.

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

## 3.2. Aufgabe Studentenverwaltungssystem

| **Vorgabe**         | **Beschreibung**                               |
| :------------------ | :--------------------------------------------- |
| **Lernziele**       | Strukturen deklariert und initialisiert werden |
|                     | Kann eine Struktur an eine Funktion übergeben  |
|                     | Kann auf Elemente einer Struktur zugreifen     |
|                     | Kann Strukturen in einem Array verwalten       |
| **Sozialform**      | Einzelarbeit                                   |
| **Auftrag**         | siehe unten                                    |
| **Hilfsmittel**     |                                                |
| **Zeitbedarf**      | 40min                                          |
| **Lösungselemente** | Funktionierendes Programm                      |

**Auftrag:**

- Erstelle ein einfaches Studentenverwaltungssystem, das Informationen über Studenten speichert und ausgibt.
- Jeder Student hat eine **Martikelnummer**, einen **Namen** und eine **Durchschnittsnote**.

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

## 3.3. Aufgabe Studentenverwaltungssystem mit Verschachtelung

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
| **Zeitbedarf**      | 20min                                          |
| **Lösungselemente** | Funktionierendes Programm                      |

**Auftrag:**

Erweitere die Aufgabe oben, mit zusätzlichem Feld Geburtstag, das sich wie folgt zusammensetzt:

- `int tag`
- `int monat`
- `int jahr`

Implementiere das Geburtstagfeld auch in den jeweiligen Funktion (`print..`, `create..`).

---

## 3.4. Aufgabe SmartLight

| **Vorgabe**         | **Beschreibung**                              |
| :------------------ | :-------------------------------------------- |
| **Lernziele**       | Bitfelder deklariert und initialisiert werden |
|                     | Kann eine Struktur an eine Funktion übergeben |
|                     | Kann auf Bitfelder zugreifen                  |
| **Sozialform**      | Einzelarbeit                                  |
| **Auftrag**         | siehe unten                                   |
| **Hilfsmittel**     |                                               |
| **Zeitbedarf**      | 50min                                         |
| **Lösungselemente** | Funktionierendes Programm                     |

**Auftrag:**

- Erstelle ein Steuerungssystem für smarte Beleuchtungen.
- Jede Leuchte hat verschiedene Attribute, die gespeichert und verwaltet werden müssen.
- Jedes Attribut wird durch ein **Bitfeld** dargestellt, um Speicherplatz zu sparen.

**Anforderungen:**

- Definiere eine Struktur `SmartLight`, die die folgenden Felder enthält:
  - `unsigned int brightness: 4` (Helligkeit 0-15)
  - `unsigned int color : 3` (Farbe, Wertebereich 0-7, wobei jede Zahl eine bestimmte Farbe repräsentiert)
  - `unsigned int isOn: 1` (Status, an oder aus)
  - `unsigned int mode : 2` (Modus, Wertebereich 0-3 z.B. 0 = Normal, 1 = Nachtmodus, 2 = Party-Modus, 3 = Lesemodus)
- Schreibe eine Funktion void `printLightStatus(struct SmartLight light)`, die den Status einer Leuchte ausgibt
- Schreibe eine Funktion `struct SmartLight createLight(unsigned in brightness, unsigned in color, unsigned in isOn, unsigned int mode)`, die eine neue Leuchte erstellt und zurückgibt.
- Erstelle im `main`-Programm ein Array von SmartLight-Strukturen, um die Information von 5 Leuchten zu speichern
- Fülle die Informationen der 5 Leuchten aus und gebe diese anschliessend mit der Funktion `printLightStatus()` aus.
