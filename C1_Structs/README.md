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
- [2. Unions – mehrere Typen im selben Speicher](#2-unions--mehrere-typen-im-selben-speicher)
  - [2.1. Was ist eine Union?](#21-was-ist-eine-union)
  - [2.2. Der entscheidende Unterschied zur struct](#22-der-entscheidende-unterschied-zur-struct)
  - [2.3. Zugriff und die wichtigste Gefahr](#23-zugriff-und-die-wichtigste-gefahr)
    - [2.3.1. Einsatzbereich 1: Daten byteweise interpretieren](#231-einsatzbereich-1-daten-byteweise-interpretieren)
    - [2.3.2. Einsatzbereich 2: Speicher sparen bei alternativen Daten](#232-einsatzbereich-2-speicher-sparen-bei-alternativen-daten)
  - [2.4. Das Tagged-Union-Muster (Best Practice)](#24-das-tagged-union-muster-best-practice)
  - [2.5. Union vs. struct – Vergleichstabelle](#25-union-vs-struct--vergleichstabelle)
    - [2.5.1. Zusammenfassung Unions](#251-zusammenfassung-unions)
- [3. Aufgaben](#3-aufgaben)
  - [3.1. Sololearn Funktionen und Zeiger](#31-sololearn-funktionen-und-zeiger)
  - [3.2. Aufgabe Strukturelemente untersuchen](#32-aufgabe-strukturelemente-untersuchen)
  - [3.3. Aufgabe Studentenverwaltungssystem](#33-aufgabe-studentenverwaltungssystem)
  - [3.4. Aufgabe Studentenverwaltungssystem mit Verschachtelung](#34-aufgabe-studentenverwaltungssystem-mit-verschachtelung)
  - [3.5. Aufgabe Union analysieren und anwenden](#35-aufgabe-union-analysieren-und-anwenden)

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

# 2. Unions – mehrere Typen im selben Speicher

## 2.1. Was ist eine Union?

> Eine **Union** sieht auf den ersten Blick aus wie eine `struct` – mit einem entscheidenden Unterschied: Alle Felder einer Union teilen sich **denselben Speicherbereich**. Es kann daher immer nur **ein einziges** Feld gleichzeitig einen gültigen Wert enthalten.

```c
union Messwert {
    int   ganzzahl;
    float kommazahl;
    char  zeichen;
};
```

## 2.2. Der entscheidende Unterschied zur struct

```c
struct S_Messwert {          union U_Messwert {
    int   ganzzahl;              int   ganzzahl;
    float kommazahl;             float kommazahl;
    char  zeichen;               char  zeichen;
};                           };
```

**Speicherbelegung im Vergleich:**

```bash
struct (12 Bytes – jedes Feld hat eigenen Platz):
┌────────────┬────────────┬──────┬─────────┐
│  ganzzahl  │ kommazahl  │zeich.│ Padding │
│  4 Byte    │  4 Byte    │1 Byte│ 3 Byte  │
└────────────┴────────────┴──────┴─────────┘
 ← alle drei Werte gleichzeitig nutzbar →

union (4 Bytes – alle Felder am SELBEN Ort):
┌────────────┐
│  ganzzahl  │  ← alle drei Felder beginnen
│  kommazahl │     an derselben Adresse!
│  zeichen   │
└────────────┘
 ← nur EIN Wert gleichzeitig gültig →
```

**Nachweis mit `sizeof`:**

```c
#include <stdio.h>

struct S_Messwert { int ganzzahl; float kommazahl; char zeichen; };
union  U_Messwert { int ganzzahl; float kommazahl; char zeichen; };

int main(void) {
    printf("sizeof(struct) = %zu Bytes\n", sizeof(struct S_Messwert));
    printf("sizeof(union)  = %zu Bytes\n", sizeof(union  U_Messwert));
    return 0;
}
```

```bash
Ausgabe:
sizeof(struct) = 12 Bytes
sizeof(union)  = 4 Bytes
```

> **Merksatz:**
> `sizeof(struct)` = Summe aller Felder (plus Padding)
> `sizeof(union)` = Grösse des **grössten** Feldes

## 2.3. Zugriff und die wichtigste Gefahr

Der Zugriff erfolgt syntaktisch **genau wie bei einer struct** – mit `.` bzw. `->`:

```c
union Messwert w;
w.ganzzahl = 42;
printf("%d\n", w.ganzzahl);
```

**Die zentrale Gefahr:** Schreibt man ein Feld, werden **alle anderen ungültig**:

```c
#include <stdio.h>

union Wert { int ganzzahl; float kommazahl; };

int main(void) {
    union Wert w;

    w.ganzzahl = 42;
    printf("w.ganzzahl  = %d\n", w.ganzzahl);
    printf("w.kommazahl = %f   <- unsinnig!\n", w.kommazahl);

    w.kommazahl = 3.14f;                    // überschreibt denselben Speicher!
    printf("w.kommazahl = %f\n", w.kommazahl);
    printf("w.ganzzahl  = %d   <- zerstört!\n", w.ganzzahl);

    return 0;
}
```

```bash
Ausgabe:
w.ganzzahl  = 42
w.kommazahl = 0.000000   <- unsinnig!
w.kommazahl = 3.140000
w.ganzzahl  = 1078523331 <- zerstört!
```

> Der Compiler **warnt nicht** davor. Es liegt vollständig in der Verantwortung
> der Programmiererin/des Programmierers, sich zu merken, welches Feld gerade gültig ist.

### 2.3.1. Einsatzbereich 1: Daten byteweise interpretieren

Der klassische Anwendungsfall in der Elektrotechnik: Ein Sensor liefert 4 Bytes über einen Bus, die als `float` interpretiert werden sollen – oder umgekehrt.

```c
#include <stdio.h>

union Sensordaten {
    float         messwert;
    unsigned char bytes[4];
};

int main(void) {
    union Sensordaten s;
    s.messwert = 23.5f;

    printf("float 23.5 besteht aus den Bytes: ");
    for (int i = 0; i < 4; i++) {
        printf("0x%02X ", s.bytes[i]);
    }
    printf("\n");
    return 0;
}
```

```bash
Ausgabe:
float 23.5 besteht aus den Bytes: 0x00 0x00 0xBC 0x41
```

> So lassen sich empfangene Bytes direkt als Zahl lesen, ohne manuelle
> Bit-Schieberei – die Union übernimmt die Umdeutung des Speicherinhalts.
>
> **Achtung Plattformabhängigkeit:** Die Reihenfolge der Bytes hängt von der
> **Byte-Reihenfolge** (*Endianness*) des Systems ab. Auf einem Big-Endian-System
> wäre die Ausgabe umgekehrt. Beim Datenaustausch zwischen verschiedenen Systemen
> muss das berücksichtigt werden.

### 2.3.2. Einsatzbereich 2: Speicher sparen bei alternativen Daten

Wenn ein Datensatz **entweder** das eine **oder** das andere enthält – nie beides – spart eine Union Speicher:

```c
// Ohne Union: 3 Felder = immer alle 3 belegt (Verschwendung)
struct KontaktA {
    char name[30];
    char telefon[20];       // entweder Telefon...
    char email[50];         // ...oder E-Mail – nie beides
};                          // → 100 Bytes

// Mit Union: nur das grössere Feld wird reserviert
struct KontaktB {
    char name[30];
    union {
        char telefon[20];
        char email[50];
    } kontaktweg;           // → nur 50 Bytes statt 70
};
```

## 2.4. Das Tagged-Union-Muster (Best Practice)

Da eine Union **nicht weiss**, welches Feld gerade gültig ist, kombiniert man sie in der Praxis mit einem `enum`, das den aktuellen Typ festhält:

```c
#include <stdio.h>

typedef enum {
    TYP_GANZZAHL,
    TYP_KOMMAZAHL,
    TYP_ZEICHEN
} Werttyp;

typedef struct {
    Werttyp typ;                   // WELCHES Feld ist gültig?
    union {
        int   i;
        float f;
        char  c;
    } wert;                        // DER eigentliche Wert
} Messwert;

void anzeigen(const Messwert *m) {
    switch (m->typ) {
        case TYP_GANZZAHL:  printf("  Ganzzahl:  %d\n",   m->wert.i); break;
        case TYP_KOMMAZAHL: printf("  Kommazahl: %.2f\n", m->wert.f); break;
        case TYP_ZEICHEN:   printf("  Zeichen:   %c\n",   m->wert.c); break;
    }
}

int main(void) {
    Messwert liste[3];

    liste[0].typ = TYP_GANZZAHL;   liste[0].wert.i = 42;
    liste[1].typ = TYP_KOMMAZAHL;  liste[1].wert.f = 3.14f;
    liste[2].typ = TYP_ZEICHEN;    liste[2].wert.c = 'A';

    for (int i = 0; i < 3; i++) {
        anzeigen(&liste[i]);
    }

    printf("\nsizeof(Messwert) = %zu Bytes\n", sizeof(Messwert));
    return 0;
}
```

```bash
Ausgabe:
  Ganzzahl:  42
  Kommazahl: 3.14
  Zeichen:   A

sizeof(Messwert) = 8 Bytes
```

> **Warum 8 Bytes?** 4 Bytes für das `enum` (`typ`) + 4 Bytes für die Union
> (grösstes Feld). Ein Array aus 3 solchen Elementen kann Werte **unterschiedlichen
> Typs** aufnehmen – etwas, das mit einem normalen Array nicht möglich wäre.

## 2.5. Union vs. struct – Vergleichstabelle

| **Kriterium**       | `struct`               | `union`                                |
| ------------------- | ---------------------- | -------------------------------------- |
| Speicherbelegung    | Summe aller Felder     | Grösse des grössten Feldes             |
| Gleichzeitig gültig | **alle** Felder        | nur **ein** Feld                       |
| Zugriffssyntax      | `.` bzw. `->`          | `.` bzw. `->` (identisch)              |
| Typischer Einsatz   | Zusammengehörige Daten | Alternative Daten, Byte-Umdeutung      |
| Compiler-Schutz     | –                      | keine Prüfung, welches Feld gültig ist |

### 2.5.1. Zusammenfassung Unions

```bash
┌────────────────────────────────────────────────────────────────┐
│ Definition       │ union Name { typ1 feld1; typ2 feld2; };     │
│ Speicher         │ alle Felder an DERSELBEN Adresse            │
│ Grösse           │ = grösstes Feld (nicht Summe!)              │
│ Gültig           │ immer nur EIN Feld gleichzeitig             │
│ Zugriff          │ union.feld  /  zeiger->feld                 │
│ Einsatz          │ Byte-Umdeutung, alternative Daten           │
│ Best Practice    │ Tagged Union: enum + union in einer struct  │
└────────────────────────────────────────────────────────────────┘
```

> **Goldene Regel:** Eine Union spart Speicher, indem sie Felder überlagert –
> aber sie merkt sich **nicht**, welches Feld gerade gültig ist. Diese Verantwortung
> liegt bei dir. Im Zweifelsfall: Tagged Union mit `enum` verwenden.

---

</br>

# 3. Aufgaben

## 3.1. Sololearn Funktionen und Zeiger

| **Vorgabe**         | **Beschreibung**                                 |
| :------------------ | :----------------------------------------------- |
| **Lernziele**       | Einsatzbereich von Strukturen und Union's kennen |
|                     | Elemente einer Struktur interpretieren           |
|                     | Elemente einer Union interpretieren              |
| **Sozialform**      | Einzelarbeit                                     |
| **Auftrag**         | siehe unten                                      |
| **Hilfsmittel**     |                                                  |
| **Zeitbedarf**      | 15min                                            |
| **Lösungselemente** | Sololearn Kapitel erfolgreich abgeschlossen      |

Starte auf Sololearn den Kurs [**C Mittelstufe**](https://www.sololearn.com/de/learn/courses/c-intermediate?location=2) und arbeite die Lektion **Strukturen & Gewerkschaften** durch.

---

## 3.2. Aufgabe Strukturelemente untersuchen

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

## 3.3. Aufgabe Studentenverwaltungssystem

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
- Jeder Student hat eine **Matikelnummer**, einen **Namen** und eine **Durchschnittsnote**.

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

## 3.4. Aufgabe Studentenverwaltungssystem mit Verschachtelung

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

## 3.5. Aufgabe Union analysieren und anwenden

| **Vorgabe**         | **Beschreibung**                                  |
| :------------------ | :------------------------------------------------ |
| **Lernziele**       | Kennt den Unterschied zwischen struct und union   |
|                     | Kann den Speicherbedarf einer Union bestimmen     |
|                     | Kann eine Union zur Byte-Interpretation einsetzen |
|                     | Kann das Tagged-Union-Muster anwenden             |
| **Sozialform**      | Partnerarbeit                                     |
| **Auftrag**         | siehe unten                                       |
| **Hilfsmittel**     |                                                   |
| **Zeitbedarf**      | 25min                                             |
| **Lösungselemente** | Funktionierendes Programm + schriftliche Analyse  |

**Teil A – Vorhersagen und prüfen:**

Studiere das folgende Programm:

```c
#include <stdio.h>

union Daten {
    int   zahl;
    char  text[8];
    double kommazahl;
};

int main(void) {
    union Daten d;

    printf("Groesse: %zu\n", sizeof(union Daten));

    d.zahl = 100;
    printf("1: %d\n", d.zahl);

    d.kommazahl = 2.5;
    printf("2: %d\n", d.zahl);
    printf("3: %f\n", d.kommazahl);

    return 0;
}
```

- Wie gross ist `sizeof(union Daten)`? Schreibe deine Annahme **zuerst auf Papier**.
- Welche Werte geben die Zeilen 1, 2 und 3 aus? Begründe jede Annahme.
- Überprüfe deine Annahmen mit einem Programmdurchlauf.
- Erkläre schriftlich, warum Zeile 2 einen unerwarteten Wert liefert.

**Teil B – Praxisanwendung:**

Ein Temperatursensor sendet seinen Messwert als 4 Bytes über eine serielle Schnittstelle.
Schreibe ein Programm, das:

1. eine Union definiert, die `float` und `unsigned char bytes[4]` überlagert
2. einen Messwert (z.B. `18.75f`) setzt und die vier Bytes hexadezimal ausgibt
3. den umgekehrten Weg zeigt: die vier Bytes einzeln setzen und den `float` auslesen

**Teil C – Tagged Union:**

Erweitere das Studentenverwaltungssystem aus Aufgabe 2.3 um ein Feld `zusatzinfo`,
das **entweder** eine Telefonnummer (`char[20]`) **oder** eine Matrikelnummer (`int`)
enthalten kann – gesteuert über ein `enum`.

Implementiere eine Funktion `void zeigeZusatzinfo(const struct Student *s)`,
die je nach Typ die passende Information ausgibt.

---

© 2026 Lukas Müller – Licensed under CC BY-NC-ND 4.0
See [LICENSE](../license.md) file for details.
