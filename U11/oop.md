|                             |                          |                                        |
| --------------------------- | ------------------------ | -------------------------------------- |
| **Elektrotechniker/-in HF** | **Programmiertechnik B** | ![IPSO Logo](./x_gitres/ipso_logo.png) |

- [1. Objektorientierte Programmierung](#1-objektorientierte-programmierung)
  - [1.1. Einführung](#11-einführung)
  - [1.2. Grundbegriffe](#12-grundbegriffe)
    - [1.2.1. Klassen](#121-klassen)
    - [1.2.2. Objekte](#122-objekte)
    - [1.2.3. Kapselung](#123-kapselung)
    - [1.2.4. Konstruktor und Destruktor](#124-konstruktor-und-destruktor)
  - [1.3. Die vier Grundpfeiler der OOP](#13-die-vier-grundpfeiler-der-oop)
    - [1.3.1. Abstraktion](#131-abstraktion)
    - [1.3.2. Kapselung](#132-kapselung)
    - [1.3.3. Vererbung](#133-vererbung)
  - [1.4. Beispielprojekt: Bankkonto mit Vererbung](#14-beispielprojekt-bankkonto-mit-vererbung)
  - [1.5. Trennung von Header- und Implementierungsdateien in C++](#15-trennung-von-header--und-implementierungsdateien-in-c)
    - [1.5.1. Beispiel: Fahrzeug-Verwaltung in C++](#151-beispiel-fahrzeug-verwaltung-in-c)
- [2. Aufgaben](#2-aufgaben)
  - [2.1. Rechteck](#21-rechteck)

---

</br>

# 1. Objektorientierte Programmierung

## 1.1. Einführung

Die **objektorientierte Programmierung (OOP)** ist ein Programmierparadigma, das darauf abzielt, Programme durch die Modellierung realer oder abstrakter Objekte besser zu strukturieren.
Anstatt nur Funktionen und Daten getrennt zu betrachten (wie in der prozeduralen Programmierung), verbindet OOP **Daten (Attribute)** und **Verhalten (Methoden)** in **Klassen** und **Objekten**.

**Vorteile der OOP:**

- Bessere Strukturierung grosser Programme
- Wiederverwendbarkeit von Code
- Wartbarkeit und Erweiterbarkeit
- Abstraktion komplexer Systeme
- Natürlichere Modellierung der realen Welt

**Nachteile der OOP:**

- Höhere Komplexität
- Gefahr von zu tiefen Vererbungshierarchien
- Speicher- und Performance-Overhead gegenüber rein prozeduraler Programmierung

## 1.2. Grundbegriffe

### 1.2.1. Klassen

Eine Klasse ist ein **Bauplan** für Objekte.
Sie definiert:

- **Attribute** (Daten/Member-Variablen)
- **Methoden** (Funktionen, die auf diesen Daten arbeiten)

```c++
class Auto 
{
  public:
      string farbe;
      int geschwindigkeit;

      void starten() { cout << "Auto startet\n"; }
      void bremsen() { geschwindigkeit = 0; }
};

```

### 1.2.2. Objekte

- Ein Objekt ist eine **Instanz** einer Klasse.

```c++
// Objekt erstellt
Auto audi;

// Eigenschaft (farbe) zuweisen
audi.farbe = "rot";

// Methode aufrufen
audi.starten();

// Objekt erstellen
Auto ferrari;

// Eigenschaft setzen
ferrari.farbe = "rot";

// Methoden aufrufen
ferrari.starten();
ferrari.bremsen();

// Eigenschaft auslesen
printf("Die Farbe ist: %s", ferrari.farbe);
```

### 1.2.3. Kapselung

- Die Daten einer Klasse können durch **Sichtbarkeitsmodifikatoren** geschützt werden:

- `public`: von aussen zugänglich
- `private`: nur innerhalb der Klasse sichtbar
- `protected`: innerhalb der Klasse und abgeleiteten Klassen sichtbar

```c++
class Konto 
{
  private:
      double saldo; // von aussen nicht direkt zugänglich

  public:
      Konto() : saldo(0) 
      {
      }

      void einzahlen(double betrag) 
      { 
        saldo += betrag; 
      }

      double getSaldo() 
      { 
        return saldo; 
      }
};
```

### 1.2.4. Konstruktor und Destruktor

- **Konstruktor**: spezielle Methode zum Initialisieren eines Objekts
- **Destruktor**: wird beim Löschen des Objekts aufgerufen

```c++
class Person 
{
  public:
      string name;

      // Konstruktor
      Person(string n) 
        : name(n) 
      {

      }

      // Destruktor
      ~Person() 
      { 
        cout << name << " gelöscht\n"; 
      } 
};
```

## 1.3. Die vier Grundpfeiler der OOP

### 1.3.1. Abstraktion

- Reduktion auf das Wesentliche.
- Eine Klasse stellt nur die relevanten Eigenschaften und Methoden zur Verfügung.

### 1.3.2. Kapselung

- Daten werden vor ungewolltem Zugriff **geschützt** (Zugriff nur über Methoden).
- Beispiel: ein Konto erlaubt nicht das direkte Manipulieren des Saldos, sondern nur über `einzahlen()` oder `abheben()`.

### 1.3.3. Vererbung

- Eine Klasse kann Eigenschaften und Methoden einer anderen Klasse **übernehmen**.

- Basisklasse (Superklasse)
- Abgeleitete Klasse (Subklasse)

```c++
class Tier 
{
  public:
      void essen() 
      { 
        cout << "Tier isst\n"; 
      }
};

class Hund : public Tier 
{
  public:
      void bellen() 
      { 
        cout << "Wuff!\n"; 
      }
};
```

```c++
Hund h;

h.essen();  // geerbt von Tier

h.bellen(); // eigene Methode
```

## 1.4. Beispielprojekt: Bankkonto mit Vererbung

```c++
#include <iostream>
using namespace std;

class Konto 
{
  protected:
      double saldo;

  public:
      Konto() 
        : saldo(0) 
      {
      }

      void einzahlen(double betrag) 
      { 
        saldo += betrag; 
      }

      virtual void abheben(double betrag) 
      { 
        saldo -= betrag; 
      }

      double getSaldo() 
      { 
        return saldo; 
      }

      virtual ~Konto() 
      {
      }
};

class Sparkonto : public Konto 
{
  public:
    void abheben(double betrag) override 
    {
        if (saldo - betrag < 0) 
        {
            cout << "Nicht genug Guthaben!\n";
        } else 
        {
            saldo -= betrag;
        }
    }
};
```

```c++
int main() 
{
    Sparkonto sk;

    sk.einzahlen(100);
    sk.abheben(50);

    cout << "Saldo: " << sk.getSaldo() << endl;

    sk.abheben(100); // Fehlermeldung
}
```

## 1.5. Trennung von Header- und Implementierungsdateien in C++

In C++ ist es üblich, Klassen in **zwei Dateien** aufzuteilen:

- **Header-Datei (`.h`)** → enthält die **Deklaration** (was es gibt)
- **Implementierungsdatei (`.cpp`)** → enthält die **Definition** (wie es funktioniert)

Das sorgt für:

- bessere Übersicht  
- saubere Trennung von Schnittstelle und Implementierung  
- Wiederverwendbarkeit in mehreren Projekten  

---

### 1.5.1. Beispiel: Fahrzeug-Verwaltung in C++

Wir modellieren verschiedene Fahrzeuge:  

- **Basisklasse**: `Fahrzeug`  
- **Abgeleitete Klassen**: `Auto` und `Fahrrad`  

Jedes Fahrzeug hat:  

- einen Namen  
- eine Geschwindigkeit  
- Methoden zur Ausgabe und Bewegung  

---

**`Fahrzeug.h`**

```c++
#ifndef FAHRZEUG_H
#define FAHRZEUG_H

#include <string>
using namespace std;

class Fahrzeug 
{
  protected:
      string name;
      int geschwindigkeit;
  public:
      Fahrzeug(string n, int g);
      virtual void bewegen();   // virtuelle Methode -> Überschreiben erlaubt
      virtual void ausgeben();  // virtuelle Methode -> dynamischer Polymorphismus
      virtual ~Fahrzeug();      // virtueller Destruktor
};

#endif
```

**`Fahrzeug.cpp`**

```c++
#include <iostream>
#include "Fahrzeug.h"
using namespace std;

Fahrzeug::Fahrzeug(string n, int g) : name(n), geschwindigkeit(g) {}

void Fahrzeug::bewegen() 
{
    cout << name << " bewegt sich mit " << geschwindigkeit << " km/h." << endl;
}

void Fahrzeug::ausgeben() 
{
    cout << "Fahrzeug: " << name << ", Geschwindigkeit: " << geschwindigkeit << " km/h" << endl;
}

Fahrzeug::~Fahrzeug() {}
```

**`main.cpp`**

```c++
#include "Fahrzeug.h"

int main() 
{
    Fahrzeug f("Motorrad", 80);

    f.ausgeben();
    f.bewegen();

    return 0;
}
```

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
