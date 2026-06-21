|                             |                          |                               |
| --------------------------- | ------------------------ | ----------------------------- |
| **Elektrotechniker/-in HF** | **Programmiertechnik B** | ![logo](../x_gitres/logo.png) |

- [1. Objektorientierte Programmierung OOP](#1-objektorientierte-programmierung-oop)
  - [1. Einführung in die OOP – ein neuer Blick auf Programme](#1-einführung-in-die-oop--ein-neuer-blick-auf-programme)
    - [1.1 Wie wir bisher programmiert haben](#11-wie-wir-bisher-programmiert-haben)
    - [1.2 Die Idee der objektorientierten Programmierung (OOP)](#12-die-idee-der-objektorientierten-programmierung-oop)
  - [2. Sinn und Zweck von OOP](#2-sinn-und-zweck-von-oop)
    - [2.1 Welche Probleme löst OOP?](#21-welche-probleme-löst-oop)
    - [2.2 Die vier Grundpfeiler im Überblick (Vorschau)](#22-die-vier-grundpfeiler-im-überblick-vorschau)
    - [2.3 Eine Analogie zum Einstieg](#23-eine-analogie-zum-einstieg)
  - [3. Grundbegriffe der OOP](#3-grundbegriffe-der-oop)
    - [3.1 Begriffsübersicht](#31-begriffsübersicht)
    - [3.2 Die Bauplan-Analogie](#32-die-bauplan-analogie)
  - [4. Klassen und Objekte](#4-klassen-und-objekte)
    - [4.1 Eine erste Klasse definieren](#41-eine-erste-klasse-definieren)
    - [4.2 Objekte erzeugen und verwenden](#42-objekte-erzeugen-und-verwenden)
    - [4.3 Der Punkt-Operator (`.`)](#43-der-punkt-operator-)
  - [5. Die Grundpfeiler der OOP: Abstraktion, Kapselung, Vererbung](#5-die-grundpfeiler-der-oop-abstraktion-kapselung-vererbung)
    - [5.1 Abstraktion – das Wesentliche zeigen, Details verbergen](#51-abstraktion--das-wesentliche-zeigen-details-verbergen)
    - [5.2 Kapselung – Daten gezielt schützen](#52-kapselung--daten-gezielt-schützen)
    - [5.3 Vererbung – Gemeinsamkeiten wiederverwenden](#53-vererbung--gemeinsamkeiten-wiederverwenden)
    - [5.4 Zusammenfassung der drei Grundpfeiler](#54-zusammenfassung-der-drei-grundpfeiler)
  - [6. Konstruktoren](#6-konstruktoren)
    - [6.1 Das Problem ohne Konstruktor](#61-das-problem-ohne-konstruktor)
    - [6.2 Was ist ein Konstruktor?](#62-was-ist-ein-konstruktor)
    - [6.3 Mehrere Konstruktoren (Überladung)](#63-mehrere-konstruktoren-überladung)
    - [6.4 Konstruktor mit Kapselung kombiniert (Praxisbeispiel)](#64-konstruktor-mit-kapselung-kombiniert-praxisbeispiel)
  - [7. Instanzerstellung im Detail](#7-instanzerstellung-im-detail)
    - [7.1 Drei Arten, ein Objekt zu erzeugen](#71-drei-arten-ein-objekt-zu-erzeugen)
    - [7.2 Zugriff auf Objekte über Zeiger](#72-zugriff-auf-objekte-über-zeiger)
    - [7.3 Vollständiges Beispiel – mehrere Objekte verwalten](#73-vollständiges-beispiel--mehrere-objekte-verwalten)
  - [8. Trennung von Header- (`.h`) und Implementierungsdateien (`.cpp`)](#8-trennung-von-header--h-und-implementierungsdateien-cpp)
    - [8.1 Die Idee ist bekannt – jetzt auf Klassenebene](#81-die-idee-ist-bekannt--jetzt-auf-klassenebene)
    - [8.2 `Person.h` – die Klassendeklaration](#82-personh--die-klassendeklaration)
    - [8.3 `Person.cpp` – die Implementierung](#83-personcpp--die-implementierung)
    - [8.4 `main.cpp` – Verwendung der Klasse](#84-maincpp--verwendung-der-klasse)
    - [8.5 Kompilieren mehrerer Dateien](#85-kompilieren-mehrerer-dateien)
    - [8.6 Warum diese Trennung auch bei Klassen sinnvoll ist](#86-warum-diese-trennung-auch-bei-klassen-sinnvoll-ist)
  - [9. Zusammenfassung](#9-zusammenfassung)
    - [Die goldene Regel](#die-goldene-regel)
- [2. Aufgaben](#2-aufgaben)
  - [2.1. Rechteck](#21-rechteck)

---

</br>

# 1. Objektorientierte Programmierung OOP

## 1. Einführung in die OOP – ein neuer Blick auf Programme

### 1.1 Wie wir bisher programmiert haben

In C haben wir **Daten** und **Funktionen, die mit diesen Daten arbeiten**, immer **getrennt** behandelt:

```c
typedef struct {
    char name[30];
    int  bestand;
    double preis;
} Artikel;

// Die Funktionen sind GETRENNT von der Datenstruktur:
void artikelAnzeigen(Artikel *a) {
    printf("%s: %d Stück à %.2f\n", a->name, a->bestand, a->preis);
}

double artikelGesamtwert(Artikel *a) {
    return a->bestand * a->preis;
}
```

> Dieser Ansatz heisst **prozedurale Programmierung**: Daten (`struct`) und Verhalten (Funktionen) existieren als zwei getrennte Dinge, die man manuell zusammenbringen muss – die Funktion muss als Parameter immer mitgegeben bekommen, mit welchen Daten sie arbeiten soll.

### 1.2 Die Idee der objektorientierten Programmierung (OOP)

> **Objektorientierte Programmierung** fasst **Daten** und die **Funktionen, die zu diesen Daten gehören**, in einer einzigen Einheit zusammen – einer **Klasse**. Ein **Objekt** ist eine konkrete Instanz dieser Klasse, die ihre eigenen Daten **und** das zugehörige Verhalten in sich trägt.

```cpp
class Artikel {
public:
    std::string name;
    int bestand;
    double preis;

    void anzeigen() {                       // Funktion ist jetzt TEIL der Klasse!
        std::cout << name << ": " << bestand << " Stück à " << preis << "\n";
    }

    double gesamtwert() {
        return bestand * preis;
    }
};
```

```console
┌──────────────────────────────────────┐     ┌─────────────────────────────────────┐
│  Prozedural (C)                      │     │  Objektorientiert (C++)             │     
│                                      │     │                                     │
│  Artikel (nur Daten)                 │     │  Artikel (Daten UND Funktionen      │
│      ↓ wird übergeben an             │     │  zusammen in EINER Einheit)         │
│  artikelAnzeigen(Artikel *a)         │     │                                     │
│  artikelGesamtwert(Artikel *a)       │     │  artikel.anzeigen()                 │
│                                      │     │  artikel.gesamtwert()               │
└──────────────────────────────────────┘     └─────────────────────────────────────┘
```

> **Wichtig:** OOP ist kein Ersatz für alles, was wir in C gelernt haben – Variablen, Schleifen, Funktionen, Pointer existieren in C++ weiterhin genauso. OOP ist eine **zusätzliche Organisationsform**, mit der wir zusammengehörige Daten und Verhalten bündeln.

---

## 2. Sinn und Zweck von OOP

### 2.1 Welche Probleme löst OOP?

| **Problem in der prozeduralen Welt**                                                          | **Lösung durch OOP **                                               |
| --------------------------------------------------------------------------------------------- | ------------------------------------------------------------------- |
| Funktion und Daten sind getrennt – leicht, eine Funktion mit der falschen `struct` aufzurufen | Methoden gehören fest zur Klasse – kein Vertauschen möglich         |
| Jeder kann auf jedes Feld einer `struct` zugreifen und es beliebig verändern                  | **Kapselung**: Zugriff kann gezielt eingeschränkt werden            |
| Ähnliche Datentypen (z.B. `Auto`, `Motorrad`) führen zu doppeltem Code                        | **Vererbung**: gemeinsame Eigenschaften werden nur einmal definiert |
| Code wird unübersichtlich, je grösser das Projekt wird                                        | Klassen bilden natürliche, in sich geschlossene Bausteine           |

### 2.2 Die vier Grundpfeiler im Überblick (Vorschau)

```console
┌────────────────────────────────────────────────────────────────────┐
│              Die vier Grundpfeiler der OOP                         │
├──────────────────┬─────────────────────────────────────────────────┤
│ Abstraktion      │ Nur das Wesentliche nach aussen zeigen          │
│ Kapselung        │ Daten vor unkontrolliertem Zugriff schützen     │
│ Vererbung        │ Gemeinsamkeiten zwischen Klassen wiederverwenden│
│ Polymorphie      │ (in dieser Einführungslektion nicht behandelt)  │
└──────────────────┴─────────────────────────────────────────────────┘
```

> Diese Lektion behandelt **Abstraktion, Kapselung und Vererbung** im Detail – Polymorphie folgt in einer späteren, vertiefenden Lektion.

### 2.3 Eine Analogie zum Einstieg

> Stell dir ein **Bankkonto** vor. Als Kunde interessiert dich nur: *„Wie viel Geld ist auf dem Konto?"* und *„Wie kann ich einzahlen/abheben?"* – nicht, **wie genau** die Bank intern die Kontostände in einer Datenbank verwaltet, welche Prüfsummen sie berechnet oder wie die Transaktion technisch abläuft.

```console
Aussensicht (was ein Kunde sieht):            Innensicht (wie es WIRKLICH funktioniert):
┌──────────────────────┐                      ┌──────────────────────────────────┐
│  Konto               │                      │  - interne Datenbankabfragen     │
│  + einzahlen()       │   ◄── Abstraktion    │  - Verschlüsselung               │
│  + abheben()         │       verbirgt das   │  - Transaktionsprotokolle        │
│  + kontostandZeigen()│     Innenleben       │  - Validierungslogik             │
└──────────────────────┘                      └──────────────────────────────────┘
```

Genau das ist die Grundidee von **Abstraktion** in der OOP – wir zeigen anderen Teilen des Programms nur das, was sie wirklich brauchen, und verbergen die komplizierten Details dahinter.

---

## 3. Grundbegriffe der OOP

### 3.1 Begriffsübersicht

| **Begriff**                      | **Bedeutung**                                               | **Vergleich zu C**                              |
| -------------------------------- | ----------------------------------------------------------- | ----------------------------------------------- |
| **Klasse**                       | Bauplan/Vorlage für Objekte                                 | ähnlich `typedef struct`, aber mit Funktionen   |
| **Objekt** (*Instanz*)           | Ein konkretes Exemplar einer Klasse                         | ähnlich einer Variable vom `struct`-Typ         |
| **Attribut** (*Member-Variable*) | Eine Dateneigenschaft einer Klasse                          | entspricht einem `struct`-Feld                  |
| **Methode** (*Member-Funktion*)  | Eine Funktion, die zur Klasse gehört                        | wie eine C-Funktion, aber Teil der Klasse       |
| **Konstruktor**                  | Spezielle Methode zur Initialisierung eines Objekts         | vergleichbar mit einer Initialisierungsfunktion |
| **Zugriffsmodifizierer**         | Legt fest, wer auf ein Attribut/eine Methode zugreifen darf | `public`, `private`, `protected`                |

### 3.2 Die Bauplan-Analogie

> Eine **Klasse** ist wie der **Bauplan eines Hauses**. Ein **Objekt** ist ein **konkret gebautes Haus** nach diesem Plan. Man kann beliebig viele Häuser (Objekte) nach demselben Bauplan (Klasse) bauen – jedes Haus hat seine eigene Adresse, seine eigene Farbe, seine eigenen Bewohner, obwohl alle nach demselben Plan gebaut wurden.

```console
Klasse "Haus" (Bauplan)              Objekte (konkrete Häuser)
┌─────────────────────┐              ┌──────────────┐  ┌──────────────┐
│ - Adresse           │   ──baut──►  │ Haus 1       │  │ Haus 2       │
│ - Farbe             │              │ Bahnhofstr. 5│  │ Seestr. 12   │
│ - Anzahl Zimmer     │              │ rot, 4 Zimmer│  │ blau, 6 Zimmer│
│ + tuerOeffnen()     │              └──────────────┘  └──────────────┘
└─────────────────────┘
```

---

## 4. Klassen und Objekte

### 4.1 Eine erste Klasse definieren

```cpp
#include <iostream>
#include <string>

class Person {
public:
    std::string name;
    int alter;

    void vorstellen() {
        std::cout << "Hallo, ich bin " << name
                   << " und " << alter << " Jahre alt." << std::endl;
    }
};
```

| **Bestandteil** | **Erklärung**                                                         |
| --------------- | --------------------------------------------------------------------- |
| `class Person`  | Definiert eine neue Klasse mit dem Namen `Person`                     |
| `public:`       | Alles danach ist **öffentlich** zugreifbar (mehr dazu in Abschnitt 5) |
| `name`, `alter` | **Attribute** (Member-Variablen) der Klasse                           |
| `vorstellen()`  | Eine **Methode** (Member-Funktion) der Klasse                         |

### 4.2 Objekte erzeugen und verwenden

```cpp
int main() {
    Person p1;            // Objekt "p1" wird erzeugt (instanziiert)
    p1.name = "Anna";      // Zugriff auf Attribut mit dem Punkt-Operator
    p1.alter = 28;

    Person p2;
    p2.name = "Ben";
    p2.alter = 34;

    p1.vorstellen();        // "Hallo, ich bin Anna und 28 Jahre alt."
    p2.vorstellen();        // "Hallo, ich bin Ben und 34 Jahre alt."

    return 0;
}
```

> **Wichtige Beobachtung:** `p1` und `p2` sind **zwei unabhängige Objekte** derselben Klasse `Person`. Jedes Objekt hat seine **eigenen** Werte für `name` und `alter` – aber **dieselbe** Methode `vorstellen()`, die mit den jeweiligen eigenen Daten arbeitet.

### 4.3 Der Punkt-Operator (`.`)

```cpp
p1.name        // Zugriff auf das Attribut "name" von Objekt p1
p1.vorstellen() // Aufruf der Methode "vorstellen" von Objekt p1
```

> **Vergleich zu C:** Das ist sehr ähnlich zum Zugriff auf `struct`-Felder (`person.name`), nur dass wir jetzt auch **Funktionen** mit demselben Punkt-Operator aufrufen können, weil sie Teil der Klasse sind.

---

## 5. Die Grundpfeiler der OOP: Abstraktion, Kapselung, Vererbung

### 5.1 Abstraktion – das Wesentliche zeigen, Details verbergen

> **Abstraktion** bedeutet, eine komplexe Realität auf das **Wesentliche** zu reduzieren und unnötige Details nach aussen zu verbergen. Eine Klasse zeigt nach aussen eine einfache Schnittstelle (öffentliche Methoden), während die komplizierte interne Umsetzung verborgen bleibt.

```cpp
class Kreis {
public:
    double radius;

    double flaeche() {
        // Der Nutzer dieser Klasse muss die Formel nicht kennen -
        // er ruft einfach flaeche() auf!
        return 3.14159265 * radius * radius;
    }

    double umfang() {
        return 2.0 * 3.14159265 * radius;
    }
};
```

```cpp
Kreis k;
k.radius = 5.0;
std::cout << k.flaeche() << std::endl;   // Nutzung OHNE die Formel kennen zu müssen
```

> **Bezug zur Modularisierungslektion:** Das ist konzeptionell **dasselbe Prinzip** wie die Trennung von Header (Schnittstelle, "was") und Implementierung (Umsetzung, "wie") in C – nur jetzt auf Klassenebene statt auf Dateiebene.

### 5.2 Kapselung – Daten gezielt schützen

> **Kapselung** (*Encapsulation*) bedeutet, den direkten Zugriff auf interne Daten einer Klasse einzuschränken und stattdessen kontrollierten Zugriff über Methoden anzubieten. Damit wird verhindert, dass Daten in einen **ungültigen Zustand** geraten.

**Das Problem ohne Kapselung:**

```cpp
class Konto {
public:
    double saldo;   // öffentlich - JEDER kann das direkt verändern!
};

Konto k;
k.saldo = -50000;   // unsinniger Wert, aber technisch jederzeit möglich!
```

**Die Lösung mit Kapselung:**

```cpp
class Konto {
private:
    double saldo;   // PRIVAT - kein direkter Zugriff von aussen möglich!

public:
    void einzahlen(double betrag) {
        if (betrag > 0) {              // kontrollierte Prüfung!
            saldo += betrag;
        }
    }

    bool abheben(double betrag) {
        if (betrag > 0 && betrag <= saldo) {   // verhindert negativen Saldo
            saldo -= betrag;
            return true;
        }
        return false;   // Abhebung abgelehnt
    }

    double kontostandAbfragen() {
        return saldo;   // kontrollierter LESE-Zugriff
    }
};
```

```cpp
Konto k;
// k.saldo = -50000;        // FEHLER! "saldo" ist private - Compiler verweigert das!
k.einzahlen(1000);          // einziger erlaubter Weg, den Saldo zu verändern
k.abheben(50000);           // wird intern abgelehnt (return false), kein ungültiger Zustand!
std::cout << k.kontostandAbfragen() << std::endl;   // 1000
```

> **Zugriffsmodifizierer im Überblick:**

| **Modifizierer** | **Zugriff von aussen** (z.B. `main()`) | **Zugriff innerhalb der Klasse**                   |
| ---------------- | -------------------------------------- | -------------------------------------------------- |
| `public`         | erlaubt                                | erlaubt                                            |
| `private`        | verweigert                             | erlaubt                                            |
| `protected`      | verweigert                             | erlaubt (auch von abgeleiteten Klassen, siehe 5.3) |

> **Bewährte Praxis:** Attribute werden fast immer `private` deklariert, der Zugriff erfolgt über öffentliche Methoden (sogenannte **Getter** zum Lesen, **Setter** zum Schreiben) – genau wie `kontostandAbfragen()` im Beispiel oben.

### 5.3 Vererbung – Gemeinsamkeiten wiederverwenden

> **Vererbung** (*Inheritance*) ermöglicht es, eine neue Klasse auf Basis einer bereits existierenden Klasse zu erstellen. Die neue Klasse (**abgeleitete Klasse**, *Subklasse*) erhält automatisch alle Attribute und Methoden der **Basisklasse** (*Oberklasse*) und kann zusätzlich eigene ergänzen.

**Das Problem ohne Vererbung – doppelter Code:**

```cpp
class Auto {
public:
    std::string marke;
    int baujahr;
    void hupen() { std::cout << "Hup hup!" << std::endl; }
};

class Motorrad {
public:
    std::string marke;       // identisch zu Auto!
    int baujahr;             // identisch zu Auto!
    void hupen() { std::cout << "Hup hup!" << std::endl; }  // identisch!
    void wheelie() { std::cout << "Vorderrad hoch!" << std::endl; }
};
```

**Die Lösung mit Vererbung:**

```cpp
class Fahrzeug {           // Basisklasse - enthält das GEMEINSAME
public:
    std::string marke;
    int baujahr;

    void hupen() {
        std::cout << "Hup hup!" << std::endl;
    }
};

class Auto : public Fahrzeug {     // Auto ERBT von Fahrzeug
public:
    int anzahlTueren;

    void kofferraumOeffnen() {
        std::cout << "Kofferraum wird geöffnet." << std::endl;
    }
};

class Motorrad : public Fahrzeug {  // Motorrad ERBT ebenfalls von Fahrzeug
public:
    void wheelie() {
        std::cout << "Vorderrad hoch!" << std::endl;
    }
};
```

```cpp
Auto a;
a.marke = "Toyota";        // von Fahrzeug GEERBT
a.baujahr = 2022;            // von Fahrzeug GEERBT
a.anzahlTueren = 5;          // EIGENES Attribut von Auto
a.hupen();                    // von Fahrzeug GEERBTE Methode
a.kofferraumOeffnen();        // EIGENE Methode von Auto

Motorrad m;
m.marke = "Honda";          // ebenfalls von Fahrzeug GEERBT
m.hupen();                    // dieselbe geerbte Methode wie bei Auto!
m.wheelie();                  // EIGENE Methode von Motorrad
```

> **Syntax `class Auto : public Fahrzeug`:** Der Doppelpunkt mit `public` zeigt an, dass `Auto` von `Fahrzeug` erbt. `marke`, `baujahr` und `hupen()` müssen in `Auto` **nicht** erneut geschrieben werden – sie sind automatisch vorhanden.

### 5.4 Zusammenfassung der drei Grundpfeiler

```console
┌────────────────────────────────────────────────────────────────────┐
│ Abstraktion:  öffentliche Methoden zeigen, Formel/Logik verbergen  │
│ Kapselung:    private Attribute, kontrollierter Zugriff über       │
│               öffentliche Methoden (Getter/Setter)                 │
│ Vererbung:    gemeinsame Eigenschaften EINMAL in Basisklasse,      │
│               spezifische Eigenschaften in abgeleiteten Klasse n   │
└────────────────────────────────────────────────────────────────────┘
```

---

## 6. Konstruktoren

### 6.1 Das Problem ohne Konstruktor

```cpp
Person p1;          // Objekt erzeugt, aber name/alter sind UNINITIALISIERT!
p1.vorstellen();     // gibt zufälligen/unsinnigen Inhalt aus - GEFÄHRLICH!

p1.name = "Anna";    // muss man sich IMMER merken, separat zu setzen
p1.alter = 28;
```

> Genauso wie eine uninitialisierte lokale Variable in C zufälligen Speicherinhalt zeigt, sind die Attribute eines frisch erzeugten Objekts ohne Konstruktor **nicht garantiert sinnvoll initialisiert**.

### 6.2 Was ist ein Konstruktor?

> Ein **Konstruktor** ist eine spezielle Methode, die **automatisch** beim Erzeugen eines Objekts aufgerufen wird. Er sorgt dafür, dass ein Objekt von Anfang an in einem **gültigen, sinnvollen Zustand** ist.

**Erkennungsmerkmale eines Konstruktors:**

- Trägt **denselben Namen wie die Klasse**
- Hat **keinen Rückgabetyp** (auch nicht `void`!)
- Wird **automatisch** beim Erzeugen eines Objekts aufgerufen

```cpp
class Person {
public:
    std::string name;
    int alter;

    // Konstruktor - gleicher Name wie die Klasse, kein Rückgabetyp!
    Person(std::string n, int a) {
        name = n;
        alter = a;
    }

    void vorstellen() {
        std::cout << "Hallo, ich bin " << name
                   << " und " << alter << " Jahre alt." << std::endl;
    }
};
```

```cpp
int main() {
    Person p1("Anna", 28);   // Konstruktor wird AUTOMATISCH aufgerufen!
    Person p2("Ben", 34);

    p1.vorstellen();           // "Hallo, ich bin Anna und 28 Jahre alt."
    p2.vorstellen();           // "Hallo, ich bin Ben und 34 Jahre alt."

    return 0;
}
```

> **Wichtiger Vorteil:** Es ist jetzt **unmöglich**, ein `Person`-Objekt zu erzeugen, ohne `name` und `alter` anzugeben – der Konstruktor **verlangt** diese Werte als Parameter. Das schützt vor uninitialisierten Objekten.

### 6.3 Mehrere Konstruktoren (Überladung)

```cpp
class Person {
public:
    std::string name;
    int alter;

    Person(std::string n, int a) {   // Konstruktor mit zwei Parametern
        name = n;
        alter = a;
    }

    Person() {                          // Standardkonstruktor (keine Parameter)
        name = "Unbekannt";
        alter = 0;
    }
};
```

```cpp
Person p1("Anna", 28);   // verwendet den Konstruktor MIT Parametern
Person p2;                  // verwendet den STANDARDKONSTRUKTOR (ohne Parameter)
```

> Eine Klasse kann **mehrere** Konstruktoren mit unterschiedlichen Parameterlisten haben – das nennt man **Überladung** (*Overloading*). Der Compiler wählt automatisch den passenden Konstruktor anhand der übergebenen Argumente.

### 6.4 Konstruktor mit Kapselung kombiniert (Praxisbeispiel)

```cpp
class Konto {
private:
    std::string besitzer;
    double saldo;

public:
    Konto(std::string name, double startSaldo) {
        besitzer = name;
        saldo = (startSaldo >= 0) ? startSaldo : 0;   // verhindert negativen Start-Saldo!
    }

    double kontostandAbfragen() {
        return saldo;
    }

    std::string besitzerAbfragen() {
        return besitzer;
    }
};
```

```cpp
Konto meinKonto("Anna Müller", 500.0);
std::cout << meinKonto.besitzerAbfragen() << ": "
          << meinKonto.kontostandAbfragen() << " CHF" << std::endl;
```

---

## 7. Instanzerstellung im Detail

### 7.1 Drei Arten, ein Objekt zu erzeugen

```cpp
// 1. Auf dem Stack (häufigste Variante) - automatische Lebensdauer
Person p1("Anna", 28);
// p1 wird automatisch zerstört, wenn der umgebende Block endet

// 2. Auf dem Heap mit "new" - manuelle Lebensdauer (ähnlich malloc in C!)
Person *p2 = new Person("Ben", 34);
// ...
delete p2;   // muss MANUELL freigegeben werden - wie free() in C!

// 3. Als Array von Objekten
Person gruppe[3] = {
    Person("Anna", 28),
    Person("Ben", 34),
    Person("Clara", 22)
};
```

> **Bezug zur Speicherverwaltungslektion:** `new` und `delete` in C++ entsprechen konzeptionell `malloc()` und `free()` in C – mit demselben Grundproblem: **jedes `new` braucht ein passendes `delete`**, sonst entsteht ein Memory Leak, genau wie wir es bei `malloc`/`free` gelernt haben.

### 7.2 Zugriff auf Objekte über Zeiger

```cpp
Person *p = new Person("Anna", 28);

p->vorstellen();        // Pfeil-Operator bei Zeigern auf Objekte!
// ODER äquivalent:
(*p).vorstellen();       // erst dereferenzieren, dann Punkt - seltener verwendet

delete p;                 // Speicher freigeben
```

> **Vergleich zu C:** Der `->`-Operator ist exakt derselbe, den wir bereits beim Zugriff auf `struct`-Felder über Pointer in C verwendet haben (`zeiger->feld` statt `(*zeiger).feld`).

### 7.3 Vollständiges Beispiel – mehrere Objekte verwalten

```cpp
#include <iostream>
#include <string>
#include <vector>

class Person {
public:
    std::string name;
    int alter;

    Person(std::string n, int a) {
        name = n;
        alter = a;
    }

    void vorstellen() {
        std::cout << name << " (" << alter << " Jahre)" << std::endl;
    }
};

int main() {
    std::vector<Person> personen;   // dynamische Liste von Objekten

    personen.push_back(Person("Anna", 28));
    personen.push_back(Person("Ben", 34));
    personen.push_back(Person("Clara", 22));

    for (Person &p : personen) {     // Schleife über alle Objekte
        p.vorstellen();
    }

    return 0;
}
```

```console
Ausgabe:
Anna (28 Jahre)
Ben (34 Jahre)
Clara (22 Jahre)
```

---

## 8. Trennung von Header- (`.h`) und Implementierungsdateien (`.cpp`)

### 8.1 Die Idee ist bekannt – jetzt auf Klassenebene

Wir kennen die Trennung von Schnittstelle und Implementierung bereits aus der Modularisierungslektion in C. In C++ wird dieses Prinzip auf **Klassen** angewendet:

```console
┌───────────────────────────────────────────────────────────┐
│                    Eine C++-Klasse                        │
├──────────────────────────┬────────────────────────────────┤
│   Person.h               │   Person.cpp                   │
│   (Klassendefinition,    │   (Implementierung der         │
│    Deklaration)          │    Methoden)                   │
│                          │                                │
│   • Attribute            │   • Methodenrümpfe (Code)      │
│   • Methodenprototypen   │                                │
└──────────────────────────┴────────────────────────────────┘
```

### 8.2 `Person.h` – die Klassendeklaration

```cpp
// Person.h

#ifndef PERSON_H     // Include-Guard - genau wie in C!
#define PERSON_H

#include <string>

class Person {
private:
    std::string name;
    int alter;

public:
    Person(std::string n, int a);   // nur der PROTOTYP des Konstruktors
    void vorstellen();                // nur der PROTOTYP der Methode
    std::string nameAbfragen();
};

#endif
```

> **Wichtig:** Im Header stehen nur die **Signaturen** (Name, Parameter, Rückgabetyp) – keine geschweiften Klammern mit Code! Genau wie bei Funktionsprototypen in C.

### 8.3 `Person.cpp` – die Implementierung

```cpp
// Person.cpp

#include "Person.h"     // eigene Header-Datei einbinden
#include <iostream>

// Konstruktor-Implementierung - beachte den "::" Scope-Operator!
Person::Person(std::string n, int a) {
    name = n;
    alter = a;
}

void Person::vorstellen() {
    std::cout << "Hallo, ich bin " << name
               << " und " << alter << " Jahre alt." << std::endl;
}

std::string Person::nameAbfragen() {
    return name;
}
```

> **Der Scope-Operator `::`:** `Person::vorstellen()` bedeutet *„die Methode `vorstellen`, die zur Klasse `Person` gehört"*. Ohne dieses Präfix wüsste der Compiler nicht, zu welcher Klasse die Implementierung gehört.

### 8.4 `main.cpp` – Verwendung der Klasse

```cpp
// main.cpp

#include "Person.h"   // NUR die Header-Datei einbinden, NIEMALS die .cpp!

int main() {
    Person p1("Anna", 28);
    p1.vorstellen();

    return 0;
}
```

### 8.5 Kompilieren mehrerer Dateien

```bash
g++ main.cpp Person.cpp -o programm
```

> **Bezug zur Makefile-Lektion:** Genau wie bei mehreren `.c`-Dateien lässt sich auch dieses Mehrdateiprojekt mit einem **Makefile** automatisieren – die Prinzipien (Objektdateien, Abhängigkeiten, `.PHONY`) übertragen sich direkt von C auf C++ (Compiler heisst nur `g++` statt `gcc`).

### 8.6 Warum diese Trennung auch bei Klassen sinnvoll ist

| **Vorteil**             | **Erklärung**                                                                     |
| ----------------------- | --------------------------------------------------------------------------------- |
| Schnellere Kompilierung | Bei Änderungen an der Implementierung muss nur `Person.cpp` neu kompiliert werden |
| Information Hiding      | Nutzer der Klasse sehen nur die öffentliche Schnittstelle im Header               |
| Wiederverwendbarkeit    | `Person.h`/`Person.cpp` können in mehreren Projekten eingebunden werden           |
| Übersichtlichkeit       | Bei grossen Klassen bleibt der Header kurz und gibt einen schnellen Überblick     |

---

## 9. Zusammenfassung

```console
┌──────────────────────────────────────────────────────────────────────┐
│           Objektorientierte Programmierung – Übersicht               │
├────────────────────────┬─────────────────────────────────────────────┤
│ Klasse                 │ Bauplan: class Name { ... };                │
│ Objekt                 │ konkrete Instanz: Name objekt(...);         │
│ Attribut               │ Dateneigenschaft innerhalb der Klasse       │
│ Methode                │ Funktion innerhalb der Klasse               │
│ Zugriff                │ objekt.attribut / objekt.methode()          │
│ Zugriff über Zeiger    │ zeiger->attribut / zeiger->methode()        │
│ Abstraktion            │ öffentliche Schnittstelle, Details verborgen│
│ Kapselung              │ private Attribute + öffentliche Methoden    │
│ Vererbung              │ class Sub : public Basis { ... };           │
│ Konstruktor            │ gleicher Name wie Klasse, kein Rückgabetyp  │
│ Objekt auf Heap        │ new Klasse(...);  ...  delete zeiger;       │
│ Header (.h)            │ Klassendeklaration, Prototypen              │
│ Implementierung (.cpp) │ Methodenrümpfe, mit Klasse::methode()       │
└────────────────────────┴─────────────────────────────────────────────┘
```

### Die goldene Regel

> **Eine gute Klasse zeigt nach aussen nur, was wirklich gebraucht wird, und schützt ihre Daten vor unkontrolliertem Zugriff.** Abstraktion, Kapselung und Vererbung sind keine akademischen Konzepte – sie sind dieselben Prinzipien der Schnittstellen-Trennung und des Information Hiding, die wir bereits in C kennengelernt haben, jetzt konsequent auf die Ebene einzelner Klassen angewendet.

---

# 2. Aufgaben

## 2.1. Rechteck

| **Vorgabe**         | **Beschreibung**                                                      |
| :------------------ | :-------------------------------------------------------------------- |
| **Lernziele**       | Kann eine Klasse in C++ mit Eigenschaften und Methoden implementieren |
|                     | Kann eine Objekt instanziieren                                        |
|                     | Kann eine Objekt instanziieren                                        |
|                     | Kann Eigenschaften eines Objekts lesen und setzen                     |
|                     | Kann Metoden eines Objekts aufrufen                                   |
| **Sozialform**      | Einzelarbeit                                                          |
| **Auftrag**         | siehe unten                                                           |
| **Hilfsmittel**     |                                                                       |
| **Zeitbedarf**      | 50min                                                                 |
| **Lösungselemente** |                                                                       |

Erstelle eine Klasse **Rechteck**, die die Eigenschaften und Methoden eines Rechtecks beschreibt.  

**Anforderungen:**

1. **Attribute**:
   - `breite` (int)  
   - `hoehe` (int)  

2. **Konstruktor**:
   - Initialisiert die Breite und Höhe beim Erzeugen des Objekts.  

3. **Methoden**:
   - `int berechneFlaeche()` → liefert die Fläche zurück  
   - `int berechneUmfang()` → liefert den Umfang zurück  
   - `void ausgeben()` → gibt Breite, Höhe, Fläche und Umfang auf der Konsole aus  

4. **Zusatzaufgabe (für Fortgeschrittene)**:  
   Erstelle eine weitere Klasse **Quadrat**, die von `Rechteck` **erbt**, aber immer gleiche Breite und Höhe setzt.  
