|                             |                          |                               |
| --------------------------- | ------------------------ | ----------------------------- |
| **Elektrotechniker/-in HF** | **Programmiertechnik B** | ![logo](../x_gitres/logo.png) |

</br>

# Gruppenarbeit Objektorientierte Programmierung

| **Vorgabe**         | **Beschreibung**                                                                                              |
| :------------------ | :------------------------------------------------------------------------------------------------------------ |
| **Lernziele**       | Den Unterschied zwischen prozeduraler und objektorientierter Programmierung erklären                          |
|                     | Verstehst die Grundidee der objektorientierten Programmierung                                                 |
|                     | Die Begriffe Klasse, Objekt, Attribut, Methode und Konstruktor definieren und anhand von Beispielen erläutern |
|                     | Eigene Klassen mit Attributen, Methoden und Konstruktoren in C++ implementieren                               |
|                     | Die drei Grundpfeiler Abstraktion, Kapselung und Vererbung erklären und in eigenen Klassen anwenden           |
|                     | Klassen in Header- (.h) und Implementierungsdateien (.cpp) aufteilen und den Scope-Operator :: verwenden      |
| **Sozialform**      | Gruppenarbeit: 2-3 Personen                                                                                   |
| **Auftrag**         | siehe unten                                                                                                   |
| **Hilfsmittel**     |                                                                                                               |
| **Zeitbedarf**      | 60min                                                                                                         |
| **Lösungselemente** | Abgabe: Alle Dateien (.h und .c) als Gesamtprojekt                                                            |
|                     | Funktionierendes Programm und Präsentation (Code erklären), ca. 5 min.                                        |
|                     | Jedes Gruppenmitglied muss Teile des Codes erklären können                                                    |

> ## Hinweis zum KI-Einsatz
>
> Eine Klasse mit Konstruktor und ein paar Methoden ist für KI-Tools eine
> triviale Aufgabe. Bei dieser Präsentation zählt deshalb, ob ihr die
> **Designentscheidungen** erklären könnt – nicht nur, ob der Code läuft.
> Jedes Mitglied wird einzeln gefragt:
>
> - *„Warum ist dieses Attribut private und nicht public? Was würde ohne diese Einschränkung schiefgehen?"*
> - *„Zeig mir, wie der Konstruktor verhindert, dass ein ungültiges Objekt entsteht."*
> - *„Was genau erbt diese Klasse von der Basisklasse – und was ist eigen?"*
> - *„Lösche das delete an dieser Stelle – was passiert? Würde der Compiler das melden?"*
> - *„Erkläre den Unterschied zwischen objekt.methode() und zeiger->methode() an eurem eigenen Code."*
>
> Wer die eigenen Klassenentscheidungen nicht begründen kann, hat das Konzept
> nicht verstanden – unabhängig davon, ob das Programm fehlerfrei läuft.

---

## Gruppenarbeit A – «Bibliothekssystem mit Kapselung»

**Szenario:** Ihr entwickelt eine Klasse `Buch`, die den Ausleihzustand korrekt verwaltet –
mit konsequenter Kapselung, sodass der Zustand niemals von aussen in einen
ungültigen Stand gebracht werden kann.

**Anforderungen:**

Dateistruktur:

```console
projekt_a/
├── Buch.h
├── Buch.cpp
└── main.cpp
```

**`Buch.h` – Vorgabe der Schnittstelle:**

```cpp
#ifndef BUCH_H
#define BUCH_H

#include <string>

class Buch {
private:
    std::string titel;
    std::string autor;
    bool ausgeliehen;
    std::string ausgeliehenAn;   // leer, wenn nicht ausgeliehen

public:
    Buch(std::string t, std::string a);   // Konstruktor

    bool ausleihen(std::string name);      // gibt false zurueck, wenn bereits ausgeliehen
    bool zurueckgeben();                    // gibt false zurueck, wenn gar nicht ausgeliehen

    std::string titelAbfragen();
    std::string autorAbfragen();
    bool istAusgeliehen();
    std::string ausgeliehenAnAbfragen();   // leer, wenn nicht ausgeliehen

    void anzeigen();
};

#endif
```

**Aufgabenstellung:**

**Schritt 1:** Implementiert `Buch.cpp` vollständig. Wichtige Designentscheidung:
`ausleihen()` darf **nur** funktionieren, wenn das Buch aktuell **nicht**
ausgeliehen ist. `zurueckgeben()` darf **nur** funktionieren, wenn es aktuell
**ausgeliehen** ist. Beide geben `bool` zurück, um Erfolg/Misserfolg zu signalisieren.

**Schritt 2:** Erstellt eine Klasse `Bibliothek`, die mehrere `Buch`-Objekte verwaltet:

```cpp
class Bibliothek {
private:
    std::vector<Buch> buecher;

public:
    void buchHinzufuegen(std::string titel, std::string autor);
    bool buchAusleihen(std::string titel, std::string name);
    bool buchZurueckgeben(std::string titel);
    void alleAnzeigen();
    void verfuegbareAnzeigen();   // nur NICHT ausgeliehene Bücher
};
```

**Schritt 3:** Testet in `main()`:

1. Mindestens 4 Bücher hinzufügen
2. Zwei Bücher ausleihen (an unterschiedliche Personen)
3. Versuchen, ein bereits ausgeliehenes Buch **erneut** auszuleihen – muss fehlschlagen
4. Ein Buch zurückgeben
5. Versuchen, ein **nicht ausgeliehenes** Buch zurückzugeben – muss fehlschlagen
6. Verfügbare Bücher anzeigen

### Erwartete Ausgabe (Beispiel)

```console
=== Alle Bücher ===
"Der Pragmatische Programmierer" von Hunt/Thomas - Verfügbar
"Clean Code" von Robert Martin - Ausgeliehen an Anna
"Effective C++" von Scott Meyers - Ausgeliehen an Ben
"Design Patterns" von GoF - Verfügbar

Versuch: "Clean Code" erneut ausleihen -> FEHLGESCHLAGEN (bereits ausgeliehen)
"Effective C++" zurückgegeben -> ERFOLG

Versuch: "Design Patterns" zurückgeben -> FEHLGESCHLAGEN (war nicht ausgeliehen)

=== Verfügbare Bücher ===
"Der Pragmatische Programmierer" von Hunt/Thomas
"Effective C++" von Scott Meyers
"Design Patterns" von GoF
```

**Pflichtanforderungen:**

- [ ] Alle Attribute der Klasse `Buch` sind `private`
- [ ] `ausleihen()`/`zurueckgeben()` verhindern zuverlässig ungültige Zustände
- [ ] Korrekte Trennung `Buch.h`/`Buch.cpp` mit Include-Guard
- [ ] `Bibliothek`-Klasse verwaltet die `Buch`-Objekte über einen `std::vector`
- [ ] Alle geforderten Testfälle (inkl. der beiden absichtlichen Fehlschläge) werden ausgeführt und ihr Ergebnis ausgegeben

**Präsentationsfragen:**

1. Warum ist `ausgeliehen` (bool) `private`? Was könnte passieren, wenn man es `public` machen würde und direkt von aussen auf `true`/`false` setzen könnte?
2. Zeigt die Stelle in `ausleihen()`, die ein bereits ausgeliehenes Buch korrekt ablehnt – was genau wird geprüft?
3. Was passiert, wenn der Konstruktor `Buch(std::string t, std::string a)` aufgerufen wird – welchen Wert hat `ausgeliehen` direkt danach? Wo wird das festgelegt?
4. Erklärt den Unterschied zwischen `buchAusleihen` in `Bibliothek` und `ausleihen` in `Buch` – warum gibt es beide Methoden?
5. Fügt **live** eine Methode `buecherVonAutor(std::string autor)` hinzu, die alle Bücher eines bestimmten Autors zurückgibt.

---

## Gruppenarbeit B – «Tierarten mit Vererbung»

**Szenario:** Ein Zoo-Verwaltungssystem soll verschiedene Tierarten abbilden. Ihr nutzt
Vererbung, um gemeinsame Eigenschaften (Name, Gewicht, Fütterung) einmal in
einer Basisklasse zu definieren und tierartspezifisches Verhalten in
abgeleiteten Klassen zu ergänzen.

**Anforderungen:**

Dateistruktur:

```console
projekt_b/
├── Tier.h
├── Tier.cpp
├── Loewe.h
├── Loewe.cpp
├── Papagei.h
├── Papagei.cpp
└── main.cpp
```

**`Tier.h` – Basisklasse:**

```cpp
#ifndef TIER_H
#define TIER_H

#include <string>

class Tier {
protected:                       // "protected" statt "private" - WARUM? (Präsentationsfrage!)
    std::string name;
    double gewichtKg;
    bool gefuettert;

public:
    Tier(std::string n, double gewicht);

    void fuettern();
    bool istGefuettert();
    std::string nameAbfragen();
    double gewichtAbfragen();

    virtual void laut();          // wird "virtual" - dazu mehr in der Vorlesung
};

#endif
```

**`Loewe.h` – abgeleitete Klasse:**

```cpp
#ifndef LOEWE_H
#define LOEWE_H

#include "Tier.h"

class Loewe : public Tier {
private:
    bool maennlich;

public:
    Loewe(std::string n, double gewicht, bool m);

    void laut();        // überschreibt die Methode aus Tier
    void jagen();         // EIGENE, neue Methode - nur bei Loewe vorhanden
};

#endif
```

**`Papagei.h` – zweite abgeleitete Klasse:**

```cpp
#ifndef PAPAGEI_H
#define PAPAGEI_H

#include "Tier.h"

class Papagei : public Tier {
private:
    std::string lieblingswort;

public:
    Papagei(std::string n, double gewicht, std::string wort);

    void laut();          // überschreibt die Methode aus Tier
    void sprechen();       // EIGENE, neue Methode - nur bei Papagei vorhanden
};

#endif
```

**Aufgabenstellung:**

**Schritt 1:** Implementiert alle `.cpp`-Dateien. `laut()` soll bei jeder
abgeleiteten Klasse unterschiedlich ausgeben (z.B. Löwe: "Brüllt laut!",
Papagei: gibt `lieblingswort` aus).

**Schritt 2:** Testet in `main()`:

1. Ein `Loewe`-Objekt und ein `Papagei`-Objekt erzeugen
2. Beide füttern (geerbte Methode `fuettern()`)
3. `laut()` für beide aufrufen (unterschiedliches Verhalten!)
4. `jagen()` beim Löwen und `sprechen()` beim Papagei aufrufen (Methoden, die NUR bei der jeweiligen Klasse existieren)

**Schritt 3 – wichtige Designfrage zum Reflektieren:**
Versucht testweise, `jagen()` auf das `Papagei`-Objekt anzuwenden:

```cpp
Papagei p("Polly", 0.4, "Schnitzel");
p.jagen();   // was passiert hier? Kompiliert das?
```

**Erwartete Ausgabe (Beispiel):**

```console
=== Löwe "Simba" ===
Simba wird gefüttert.
Simba: Brüllt laut!
Simba jagt durch die Savanne!

=== Papagei "Polly" ===
Polly wird gefüttert.
Polly sagt: Schnitzel
Polly spricht: "Schnitzel"
```

**Pflichtanforderungen:**

- [ ] `Tier` als Basisklasse mit `protected`-Attributen (nicht `private`!)
- [ ] `Loewe` und `Papagei` erben korrekt mit `: public Tier`
- [ ] `fuettern()` wird **nicht erneut implementiert** – beide nutzen die geerbte Version
- [ ] `laut()` zeigt für jede Tierart **unterschiedliches** Verhalten
- [ ] `jagen()` existiert **nur** bei `Loewe`, `sprechen()` **nur** bei `Papagei`
- [ ] Korrekte Header/Implementierungs-Trennung für alle drei Klassen

**Präsentationsfragen:**

1. Warum sind die Attribute in `Tier` als `protected` und nicht `private` deklariert? Was wäre der Unterschied, wenn sie `private` wären – probiert es testweise aus (in einer Kopie des Codes), was meldet der Compiler?
2. Zeigt, wie `Loewe` und `Papagei` die geerbte Methode `fuettern()` nutzen, **ohne** sie selbst zu implementieren.
3. Was passiert beim Versuch, `jagen()` auf ein `Papagei`-Objekt anzuwenden? Was sagt der Compiler dazu, und warum macht das Sinn?
4. Erklärt den Konstruktoraufruf in `Loewe::Loewe(...)` – wie wird sichergestellt, dass auch der `Tier`-Teil des Objekts korrekt initialisiert wird? (Stichwort: Initialisierungsliste, ggf. recherchiert/ergänzt)
5. Fügt **live** eine dritte Tierart hinzu (z.B. `Schildkroete`) – wie viele Zeilen Code braucht ihr dank Vererbung wirklich neu?

---

## Gruppenarbeit C – «Geometrische Formen mit Konstruktor-Überladung»

**Szenario:** Ihr entwickelt eine kleine Bibliothek geometrischer Formen. Jede Form soll
Fläche und Umfang berechnen können – mit besonderem Augenmerk auf saubere
Konstruktoren, die ungültige Masse von Anfang an verhindern.

**Anforderungen:**

Dateistruktur:

```console
projekt_c/
├── Rechteck.h
├── Rechteck.cpp
├── Kreis.h
├── Kreis.cpp
└── main.cpp
```

**`Rechteck.h`:**

```cpp
#ifndef RECHTECK_H
#define RECHTECK_H

class Rechteck {
private:
    double breite;
    double hoehe;

public:
    Rechteck(double b, double h);   // normaler Konstruktor
    Rechteck(double seite);          // ÜBERLADENER Konstruktor - erzeugt ein QUADRAT!

    double flaeche();
    double umfang();
    bool istQuadrat();
    void anzeigen();
};

#endif
```

**Wichtige Designanforderung:** Der Konstruktor muss **negative oder Null-Werte**
für Breite/Höhe verhindern – z.B. indem er auf einen Minimalwert (z.B. `0.1`)
zurückfällt und eine Warnung ausgibt:

```cpp
Rechteck::Rechteck(double b, double h) {
    if (b <= 0 || h <= 0) {
        std::cout << "Warnung: Ungültige Masse, verwende Standardwerte!" << std::endl;
        breite = 1.0;
        hoehe = 1.0;
    } else {
        breite = b;
        hoehe = h;
    }
}
```

**`Kreis.h`:**

```cpp
#ifndef KREIS_H
#define KREIS_H

class Kreis {
private:
    double radius;

public:
    Kreis(double r);

    double flaeche();
    double umfang();
    void anzeigen();

    bool groesserAls(Kreis andererKreis);   // vergleicht zwei Kreise nach Flaeche!
};

#endif
```

**Aufgabenstellung:**

**Schritt 1:** Implementiert beide Klassen vollständig, inklusive der
Validierung in den Konstruktoren.

**Schritt 2:** Testet in `main()`:

1. Ein `Rechteck` mit `(5, 3)` erzeugen
2. Ein `Rechteck` mit **nur einem** Parameter `(4)` erzeugen → muss ein Quadrat 4×4 ergeben (überladener Konstruktor!)
3. Ein `Rechteck` mit **negativem** Wert `(-5, 3)` erzeugen → Warnung + Standardwerte
4. Zwei `Kreis`-Objekte erzeugen und mit `groesserAls()` vergleichen
5. Alle Flächen/Umfänge ausgeben

**Erwartete Ausgabe (Beispiel):**

```console
Rechteck 5x3: Fläche=15.00, Umfang=16.00, Quadrat? Nein
Rechteck (Konstruktor mit 1 Param, Seite=4): Fläche=16.00, Umfang=16.00, Quadrat? Ja

Warnung: Ungültige Masse, verwende Standardwerte!
Rechteck (-5, 3): Fläche=1.00, Umfang=4.00, Quadrat? Ja

Kreis 1 (r=5): Fläche=78.54
Kreis 2 (r=3): Fläche=28.27
Ist Kreis 1 größer als Kreis 2? Ja
```

**Pflichtanforderungen:**

- [ ] Zwei **überladene** Konstruktoren bei `Rechteck` (mit 1 und mit 2 Parametern)
- [ ] Konstruktor verhindert ungültige (negative/Null-) Masse mit sinnvollem Fallback
- [ ] `istQuadrat()` prüft korrekt, ob `breite == hoehe`
- [ ] `groesserAls()` bei `Kreis` vergleicht zwei Objekte korrekt über deren Fläche
- [ ] Korrekte Header/Implementierungs-Trennung für beide Klassen

**Präsentationsfragen:**

1. Erklärt, wie der Compiler entscheidet, **welcher** der beiden `Rechteck`-Konstruktoren bei `Rechteck r(4);` verwendet wird.
2. Zeigt die Validierungslogik im Konstruktor – was passiert bei `Rechteck(-5, 3)` Schritt für Schritt?
3. `groesserAls(Kreis andererKreis)` nimmt den Parameter **nicht** als Zeiger oder Referenz – was bedeutet das für die Übergabe (Stichwort: Kopie)? Erinnert das an etwas aus der C-Funktionenlektion (Call by Value)?
4. Was wäre der Unterschied, wenn `breite`/`hoehe` `public` statt `private` wären – könnte man dann die Validierungslogik im Konstruktor umgehen? Zeigt ein Beispiel.
5. Fügt **live** einen dritten überladenen Konstruktor zu `Rechteck` hinzu, der **gar keine** Parameter nimmt und ein Standard-Rechteck (z.B. 1×1) erzeugt.

---

## Gruppenarbeit D – «Mitarbeiterverwaltung mit Vererbung und Kapselung kombiniert» 💼

**Szenario:** Ihr entwickelt ein kleines Mitarbeiterverwaltungssystem für ein Unternehmen.
Es gibt verschiedene Mitarbeitertypen (Festangestellte, Praktikanten) mit
unterschiedlicher Lohnberechnung – aber gemeinsamen Basisdaten. Diese Aufgabe
kombiniert **alle drei Grundpfeiler** aus der Theorie.

**Anforderungen:**

**Dateistruktur:**

```console
projekt_d/
├── Mitarbeiter.h
├── Mitarbeiter.cpp
├── Festangestellter.h
├── Festangestellter.cpp
├── Praktikant.h
├── Praktikant.cpp
└── main.cpp
```

**`Mitarbeiter.h` – Basisklasse:**

```cpp
#ifndef MITARBEITER_H
#define MITARBEITER_H

#include <string>

class Mitarbeiter {
protected:
    std::string name;
    int personalnummer;

private:
    static int naechstePersonalnummer;   // STATISCHES Attribut - gehört zur KLASSE, nicht zum Objekt!

public:
    Mitarbeiter(std::string n);    // Personalnummer wird AUTOMATISCH vergeben!

    std::string nameAbfragen();
    int personalnummerAbfragen();

    virtual double monatslohnBerechnen() = 0;   // rein virtuell - mehr dazu in Vorlesung
    void infoAnzeigen();
};

#endif
```

> **Hinweis zu `static int naechstePersonalnummer`:** Diese Variable gehört
> **zur Klasse**, nicht zu einem einzelnen Objekt – sie wird zwischen **allen**
> `Mitarbeiter`-Objekten **geteilt**. Jeder neue Mitarbeiter erhält automatisch
> die nächste freie Nummer, ähnlich wie eine `static`-Variable in einer
> C-Funktion ihren Wert über mehrere Aufrufe hinweg behält – nur jetzt auf
> Klassenebene statt auf Funktionsebene.

**`Festangestellter.h`:**

```cpp
#ifndef FESTANGESTELLTER_H
#define FESTANGESTELLTER_H

#include "Mitarbeiter.h"

class Festangestellter : public Mitarbeiter {
private:
    double grundgehalt;
    double bonus;

public:
    Festangestellter(std::string n, double gehalt, double bonusBetrag);

    double monatslohnBerechnen();   // ÜBERSCHREIBT die Basisklassen-Methode
};

#endif
```

**`Praktikant.h`:**

```cpp
#ifndef PRAKTIKANT_H
#define PRAKTIKANT_H

#include "Mitarbeiter.h"

class Praktikant : public Mitarbeiter {
private:
    double stundenlohn;
    int    arbeitsstundenProMonat;

public:
    Praktikant(std::string n, double lohn, int stunden);

    double monatslohnBerechnen();   // ÜBERSCHREIBT die Basisklassen-Methode ANDERS
};

#endif
```

**Aufgabenstellung:**

**Schritt 1:** Implementiert alle Klassen. Beachtet: `Mitarbeiter` selbst kann
**nicht** direkt instanziiert werden (wegen der rein virtuellen Methode
`monatslohnBerechnen() = 0`) – das ist beabsichtigt und wird in der Theorie
zur Vererbung vertieft. Nur `Festangestellter` und `Praktikant` können erzeugt werden.

**Schritt 2:** Implementiert die statische Personalnummer-Vergabe:

```cpp
// In Mitarbeiter.cpp:
int Mitarbeiter::naechstePersonalnummer = 1000;   // Startwert, EINMAL ausserhalb der Klasse definiert

Mitarbeiter::Mitarbeiter(std::string n) {
    name = n;
    personalnummer = naechstePersonalnummer;
    naechstePersonalnummer++;   // beim NÄCHSTEN Mitarbeiter wird die Nummer höher sein
}
```

**Schritt 3:** Testet in `main()`:

1. Zwei `Festangestellter`-Objekte und zwei `Praktikant`-Objekte erzeugen
2. Personalnummern ausgeben – sie müssen **automatisch aufsteigend** sein (1000, 1001, 1002, 1003), unabhängig vom Mitarbeitertyp!
3. Monatslohn für alle vier berechnen und ausgeben
4. Gesamtlohnsumme aller vier berechnen

**Erwartete Ausgabe (Beispiel):**

```console
Mitarbeiter Nr. 1000: Anna Keller (Festangestellt) - Lohn: 6500.00 CHF
Mitarbeiter Nr. 1001: Tim Berger (Praktikant) - Lohn: 2400.00 CHF
Mitarbeiter Nr. 1002: Sara Wyss (Festangestellt) - Lohn: 7200.00 CHF
Mitarbeiter Nr. 1003: Noah Frei (Praktikant) - Lohn: 2000.00 CHF

Gesamtlohnsumme: 18100.00 CHF
```

**Pflichtanforderungen:**

- [ ] `naechstePersonalnummer` ist `static` und wird korrekt zwischen allen Objekten geteilt
- [ ] Jedes neue Objekt erhält automatisch eine **eindeutige, aufsteigende** Personalnummer
- [ ] `monatslohnBerechnen()` ist bei `Festangestellter` und `Praktikant` **unterschiedlich** implementiert
- [ ] Es wird **kein** reines `Mitarbeiter`-Objekt erzeugt (nur die abgeleiteten Klassen)
- [ ] Korrekte Header/Implementierungs-Trennung für alle drei Klassen

**Präsentationsfragen:**

1. Erklärt `static int naechstePersonalnummer` – warum gehört diese Variable zur **Klasse** und nicht zu jedem einzelnen Objekt? Was wäre der Unterschied, wenn es kein `static` wäre?
2. Erzeugt **live** ein fünftes Mitarbeiterobjekt – welche Personalnummer erhält es automatisch, und warum genau diese?
3. Warum kann man **kein** reines `Mitarbeiter`-Objekt erzeugen (`Mitarbeiter m("Test");` würde einen Compilerfehler verursachen)? Probiert es testweise aus.
4. Zeigt, wie `monatslohnBerechnen()` bei `Festangestellter` und `Praktikant` jeweils **unterschiedlich** implementiert ist – welche Attribute fliessen jeweils ein?
5. Was haben `name` und `personalnummer` (in `Mitarbeiter`) mit `protected` zu tun – warum reicht `private` hier nicht aus, wenn die abgeleiteten Klassen darauf zugreifen sollen?

---

© 2026 Lukas Müller – Licensed under CC BY-NC-ND 4.0
See [LICENSE](..\license.md) file for details.
