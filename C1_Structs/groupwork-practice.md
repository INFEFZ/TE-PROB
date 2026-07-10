|                             |                          |                               |
| --------------------------- | ------------------------ | ----------------------------- |
| **Elektrotechniker/-in HF** | **Programmiertechnik B** | ![logo](../x_gitres/logo.png) |

- [1. Gruppenarbeit Strukturen (struct)](#1-gruppenarbeit-strukturen-struct)
  - [Gruppenarbeit A – «Bibliotheksverwaltung mit Zeigern und Array»](#gruppenarbeit-a--bibliotheksverwaltung-mit-zeigern-und-array)
  - [Gruppenarbeit B – «Lagerbestand mit Suchfunktionen und Statistik»](#gruppenarbeit-b--lagerbestand-mit-suchfunktionen-und-statistik)
  - [Gruppenarbeit C – «Schulnotenverwaltung mit Sortierung und Statistik»](#gruppenarbeit-c--schulnotenverwaltung-mit-sortierung-und-statistik)
    - [Szenario](#szenario)
  - [Gruppenarbeit D – «Kontaktverwaltung mit Datei-Persistenz»](#gruppenarbeit-d--kontaktverwaltung-mit-datei-persistenz)

---

</br>

# 1. Gruppenarbeit Strukturen (struct)

| **Vorgabe**         | **Beschreibung**                                                                                  |
| :------------------ | :------------------------------------------------------------------------------------------------ |
| **Lernziele**       | Eine struct als benutzerdefinierte Datenstruktur definieren und instanziieren                     |
|                     | Auf Felder einer struct mit Punkt-Operator (.) und über Zeiger mit Pfeil-Operator (->) zugreifen  |
|                     | Strukturen als Funktionsparameter per Wert und per Zeiger übergeben und den Unterschied begründen |
|                     | Verschachtelte Strukturen (struct in struct) definieren und verwenden                             |
|                     | typedef zur Vereinfachung der Strukturbenennung einsetzen                                         |
| **Sozialform**      | Gruppenarbeit: 2-3 Personen                                                                       |
| **Auftrag**         | siehe unten                                                                                       |
| **Hilfsmittel**     |                                                                                                   |
| **Zeitbedarf**      | 60min                                                                                             |
| **Lösungselemente** | Abgabe: Alle Dateien (.h und .c) als Gesamtprojekt                                                |
|                     | Funktionierendes Programm und Präsentation (Code erklären), ca. 5 min.                            |
|                     | Jedes Gruppenmitglied muss Teile des Codes erklären können                                        |

</br>

> Hinweis zum KI-Einsatz
> Eine `struct`-Definition mit ein paar Funktionen ist für KI-Tools in Sekunden erledigt. In der Präsentation wird deshalb jedes Mitglied einzeln gefragt:
> Ihr dürft KI-Tools verwenden – aber: Ihr werdet den Code in der Präsentation erklären müssen.
>
> Bei diesen Aufgaben geht es nicht nur darum, dass das Programm läuft – sondern darum, dass ihr die Struktur versteht und begründen könnt.
> In der Präsentation wird jedes Mitglied einzeln gefragt:
>
> - *„Warum habt ihr diese Felder so gewählt – was wäre ein Gegenbeispiel?"*
> - *„Zeig mir, was der Unterschied ist, wenn du die Struktur per Wert statt per Zeiger übergibst."*
> - *„Ändere live den Inhalt eines Feldes über einen Zeiger – was ändert sich im Original?"*
> - *„Was passiert, wenn man `strcpy` weglässt und stattdessen direkt `=` verwendet?"*
> - *„Zeichne die Speicherstruktur dieser `struct` auf Papier – welches Feld liegt wo?"*
>
> Das bedeutet:
>
> - Jede Zeile, die ihr abgebt, müsst ihr verstehen und erklären können
> - Empfehlung: Nutzt KI als Lernhilfe, nicht als Schreibmaschine. Schreibt Teile selbst, lasst andere erklären, diskutiert als Gruppe.
> - Eine Lösung, bei der die Gruppe die Strukturentscheidungen nicht erklären kann, gilt als nicht bestanden – unabhängig davon, ob der Code läuft.

---

## Gruppenarbeit A – «Bibliotheksverwaltung mit Zeigern und Array»

**Szenario:**

Eine Bibliothek verwaltet ihren Buchbestand. Ihr entwickelt die Datenstruktur und alle Verwaltungsfunktionen – dabei steht der
korrekte Umgang mit Zeigern auf Strukturen im Mittelpunkt.

**Aufgabenstellung:**

**Definiert folgende Strukturen:**

```c
struct Datum {
    int tag;
    int monat;
    int jahr;
};

struct Buch {
    char titel[100];
    char autor[50];
    int isbn;
    struct Datum erscheinungsjahr;   // verschachtelte Struktur!
    int verfuegbar;                  // 1 = ja, 0 = nein (ausgeliehen)
};
```

**Implementiert folgende Funktionen – Achtung auf die Signaturen:**

```c
// Gibt alle Informationen eines Buches aus
void buchAnzeigen(const struct Buch *b);         // per ZEIGER, nicht per Wert!

// Setzt verfuegbar auf 0, gibt 0 zurueck falls bereits ausgeliehen
int buchAusleihen(struct Buch *b);

// Setzt verfuegbar auf 1
void buchZurueckgeben(struct Buch *b);

// Sucht ein Buch nach ISBN, gibt ZEIGER auf das Buch zurueck (oder NULL)
struct Buch *buchSuchen(struct Buch bibliothek[], int anzahl, int isbn);

// Gibt aus, wie viele Buecher gerade verfuegbar sind
int anzahlVerfuegbar(struct Buch bibliothek[], int anzahl);
```

**Testet in `main()` mit einem Array von 5 Büchern:**

1. Alle Bücher anzeigen
2. Zwei Bücher ausleihen
3. Eines zurückgeben
4. Nach einer ISBN suchen (einmal mit Treffer, einmal ohne)
5. Anzahl der verfügbaren Bücher ausgeben

**Pflichtanforderungen:**

- [ ] `buchAnzeigen` erhält die Struktur als `const struct Buch *` (Zeiger, nicht Kopie) – und kann trotzdem nichts verändern (Warum? → Präsentation)
- [ ] `buchSuchen` gibt einen Zeiger zurück oder `NULL` – der `NULL`-Fall muss in `main()` abgefangen werden
- [ ] Verschachtelte Struktur `Datum` korrekt initialisiert und ausgegeben
- [ ] Versuch, ein bereits ausgeliehenes Buch erneut auszuleihen – Code behandelt diesen Fall

**Präsentationsfragen:**

1. Warum nimmt `buchAnzeigen` einen `const struct Buch *` statt direkt `struct Buch`? Was wäre der Unterschied bei 1000 Büchern?
2. Was gibt `buchSuchen` zurück, wenn das Buch nicht gefunden wird? Zeigt die Stelle in `main()`, die das korrekt behandelt.
3. Zeichnet auf Papier, wie `struct Buch` im Speicher aufgebaut ist – welches Feld liegt direkt nach welchem?
4. Was würde passieren, wenn man `buchAusleihen` mit Wertübergabe schreiben würde (`struct Buch b` statt `struct Buch *b`)? Demonstriert den Unterschied live.
5. Fügt **live** eine Funktion `void alleBuecherVonAutor(...)` hinzu, die alle Bücher eines bestimmten Autors ausgibt.

---

</br>

## Gruppenarbeit B – «Lagerbestand mit Suchfunktionen und Statistik»

**Szenario:**

Ein Kleinbetrieb verwaltet seinen Lagerbestand. Ihr entwickelt eine vollständige Lagerverwaltung mit Strukturen, Suchfunktionen und statistischen Auswertungen.

**Aufgabenstellung:**

**Definiert die Struktur:**

```c
#define MAX_ARTIKEL 20
#define MAX_NAME    50

struct Artikel {
    int    artikelnummer;
    char   bezeichnung[MAX_NAME];
    int    bestand;
    double preis;
    char   kategorie[20];    // z.B. "Elektronik", "Werkzeug", "Buero"
};
```

**Implementiert folgende Funktionen:**

```c
// Erstellt und gibt einen Artikel zurueck (alle Felder als Parameter)
struct Artikel artikelErstellen(int nr, char bez[], int bestand,
                                double preis, char kat[]);

// Gibt einen einzelnen Artikel formatiert aus
void artikelAnzeigen(const struct Artikel *a);

// Gibt alle Artikel einer bestimmten Kategorie aus
void kategorieAnzeigen(struct Artikel lager[], int anzahl, char kategorie[]);

// Berechnet den Gesamtwert des Lagers (Summe aller bestand * preis)
double gesamtwertBerechnen(struct Artikel lager[], int anzahl);

// Findet den teuersten Artikel, gibt Zeiger zurueck
struct Artikel *teuersterArtikel(struct Artikel lager[], int anzahl);

// Erhoeht/vermindert den Bestand eines Artikels (per Artikelnummer suchen!)
// Gibt 0 zurueck falls Artikelnummer nicht gefunden
int bestandAktualisieren(struct Artikel lager[], int anzahl,
                         int artikelnummer, int menge);
```

**Testdaten für `main()` – mindestens 8 Artikel aus 3 Kategorien:**

```c
struct Artikel lager[MAX_ARTIKEL];
lager[0] = artikelErstellen(1001, "Hammer",         15, 12.90, "Werkzeug");
lager[1] = artikelErstellen(1002, "Bohrer 5mm",     30,  4.50, "Werkzeug");
lager[2] = artikelErstellen(1003, "USB-Kabel",      50,  8.90, "Elektronik");
lager[3] = artikelErstellen(1004, "Laptop-Staender", 8, 45.00, "Elektronik");
lager[4] = artikelErstellen(1005, "Kugelschreiber", 100, 0.80, "Buero");
lager[5] = artikelErstellen(1006, "Notizblock",     60,  2.50, "Buero");
lager[6] = artikelErstellen(1007, "Zange",          12, 18.90, "Werkzeug");
lager[7] = artikelErstellen(1008, "USB-Hub",        20, 29.90, "Elektronik");
int anzahl = 8;
```

**Testet:**

1. Alle Artikel der Kategorie „Werkzeug" anzeigen
2. Gesamtlagerwert ausgeben
3. Teuersten Artikel ausgeben
4. Bestand von Artikel 1003 um 10 erhöhen, dann erneut anzeigen
5. Versuch, einen nicht-existierenden Artikel zu aktualisieren

**Pflichtanforderungen:**

- [ ] `artikelErstellen` verwendet `strcpy` für String-Felder (kein direktes `=`)
- [ ] `teuersterArtikel` gibt einen Zeiger zurück (nicht eine Kopie der Struktur)
- [ ] `bestandAktualisieren` sucht intern per Artikelnummer (kein direkter Array-Index von aussen)
- [ ] Alle Ausgaben sauber formatiert (Spalten ausgerichtet mit `%-15s`, `%8.2f` etc.)

**Präsentationsfragen:**

1. In `artikelErstellen` – warum muss `strcpy(a.bezeichnung, bez)` verwendet werden und nicht einfach `a.bezeichnung = bez`?
2. `teuersterArtikel` gibt `struct Artikel *` zurück – was genau ist der Unterschied zu `struct Artikel`? Was passiert im Speicher jeweils?
3. Zeigt `bestandAktualisieren` – wie sucht die Funktion intern nach der Artikelnummer, und warum ist das robuster als einen direkten Index zu übergeben?
4. Was passiert, wenn `anzahl = 0` übergeben wird – stürzt das Programm ab? Zeigt, welche eurer Funktionen diesen Fall korrekt behandeln.
5. Fügt **live** eine Funktion `void artikelUnterBestand(...)` hinzu, die alle Artikel ausgibt, deren Bestand unter einem bestimmten Schwellwert liegt.

---

</br>

## Gruppenarbeit C – «Schulnotenverwaltung mit Sortierung und Statistik»

### Szenario

Ein Lehrer verwaltet die Noten seiner Klasse. Ihr entwickelt die Datenstruktur, Statistikfunktionen – und implementiert einen
Sortieralgorithmus (Bubblesort aus der Sortierlektion) direkt auf einem Array von Strukturen.

**Aufgabenstellung:**

**Definiert:**

```c
#define MAX_SCHUELER 30
#define MAX_FAECHER   5

typedef struct {
    char vorname[30];
    char nachname[30];
    int  matrikelnummer;
    float noten[MAX_FAECHER];       // Array von Noten innerhalb der Struktur!
    char  faecher[MAX_FAECHER][20]; // Fächernamen (z.B. "Mathe", "Physik")
    int   anzahlFaecher;
} Schueler;
```

> **Beachte:** `noten[MAX_FAECHER]` ist ein Array **innerhalb** der Struktur –
> der Zugriff lautet `schueler.noten[i]`, nicht einfach `schueler.noten`.

**Implementiert:**

```c
// Berechnet den Notendurchschnitt eines Schülers
float durchschnittBerechnen(const Schueler *s);

// Gibt alle Daten eines Schülers inkl. Noten aus
void schuelerAnzeigen(const Schueler *s);

// Gibt alle Schüler der Klasse aus
void klasseAnzeigen(Schueler klasse[], int anzahl);

// Sortiert die Klasse aufsteigend nach Durchschnittsnote (Bubblesort!)
void klasseNachNoteSort(Schueler klasse[], int anzahl);

// Gibt den besten und schlechtesten Schüler aus (beide per Zeiger)
void besteSchlechteste(Schueler klasse[], int anzahl,
                       Schueler **bester, Schueler **schlechtester);

// Gibt die Klassendurchschnittsnote aus
float klassendurchschnitt(Schueler klasse[], int anzahl);
```

**Testdaten für `main()` mit mindestens 6 Schülern, je 3 Fächern:**

```c
Schueler klasse[MAX_SCHUELER];
// Beispiel (ihr füllt alle 6 Schüler entsprechend aus):
strcpy(klasse[0].vorname, "Anna");
strcpy(klasse[0].nachname, "Keller");
klasse[0].matrikelnummer = 1001;
klasse[0].anzahlFaecher  = 3;
klasse[0].noten[0] = 5.5f;
klasse[0].noten[1] = 4.8f;
klasse[0].noten[2] = 5.2f;
strcpy(klasse[0].faecher[0], "Mathe");
strcpy(klasse[0].faecher[1], "Physik");
strcpy(klasse[0].faecher[2], "Informatik");
// ...
```

**Testet in `main()`:**

1. Klasse unsortiert anzeigen (mit Durchschnitt je Schüler)
2. Klassendurchschnitt ausgeben
3. Besten und schlechtesten Schüler ausgeben
4. Klasse nach Note sortieren
5. Klasse erneut sortiert anzeigen – Reihenfolge muss sich geändert haben

**Pflichtanforderungen:**

- [ ] `noten[]` als Array **innerhalb** der Struktur (nicht als separates globales Array)
- [ ] `klasseNachNoteSort` ist **Bubblesort** – beim Tauschen wird die **gesamte** `Schueler`-Struktur getauscht (nicht nur ein Feld)
- [ ] `besteSchlechteste` gibt beide Werte über **Zeiger auf Zeiger** (`Schueler **`) zurück
- [ ] `durchschnittBerechnen` nutzt `s->anzahlFaecher` (nicht die Konstante `MAX_FAECHER`) um nur eingetragene Noten einzubeziehen

**Präsentationsfragen:**

1. In `klasseNachNoteSort`: Was genau wird beim Tausch ausgetauscht – ein einzelnes Feld oder die ganze Struktur? Zeigt den Tauschcode.
2. `besteSchlechteste` hat `Schueler **bester` als Parameter – warum der doppelte Zeiger? Was bedeutet `*bester = &klasse[i]`?
3. Warum verwendet `durchschnittBerechnen` `s->anzahlFaecher` statt `MAX_FAECHER`? Was wäre der Fehler, wenn man immer `MAX_FAECHER` verwenden würde?
4. Zeichnet auf Papier, wie `Schueler klasse[3]` im Speicher aufgebaut ist – was liegt direkt nebeneinander?
5. Fügt **live** eine Funktion `void schuelerMitNote(Schueler klasse[], int anzahl, float minNote)` hinzu, die alle Schüler ausgibt, deren Durchschnitt über einer bestimmten Note liegt.

---

</br>

## Gruppenarbeit D – «Kontaktverwaltung mit Datei-Persistenz»

**Szenario:**

Diese Aufgabe verbindet zwei Lektionen: **Strukturen** und **Datei-I/O**.
Ihr entwickelt eine Kontaktverwaltung, die Daten nicht nur im Speicher hält, sondern **binär in eine Datei schreibt und wieder einliest** – sodass die
Kontakte nach einem Programmneustart noch vorhanden sind.

**Aufgabenstellung:**

**Definiert:**

```c
#define MAX_KONTAKTE 50

typedef struct {
    char   vorname[30];
    char   nachname[30];
    char   telefon[20];
    char   email[50];
    int    geburtsjahr;
} Kontakt;
```

**Implementiert folgende Funktionen:**

```c
// Erstellt einen neuen Kontakt und gibt ihn zurueck
Kontakt kontaktErstellen(char vn[], char nn[], char tel[],
                         char mail[], int jahr);

// Gibt einen Kontakt formatiert aus
void kontaktAnzeigen(const Kontakt *k);

// Gibt alle Kontakte aus
void alleKontakteAnzeigen(Kontakt kontakte[], int anzahl);

// Sucht nach Nachname (Teilstring-Suche mit strstr!)
// Gibt Zeiger auf den ersten Treffer zurueck, oder NULL
Kontakt *kontaktSuchen(Kontakt kontakte[], int anzahl, char suchname[]);

// Speichert das gesamte Array BINAER in eine Datei
// Gibt Anzahl gespeicherter Kontakte zurueck (0 bei Fehler)
int kontakteSpeichern(Kontakt kontakte[], int anzahl, char dateiname[]);

// Laedt Kontakte aus Binaerdatei in das Array
// Gibt Anzahl geladener Kontakte zurueck (0 bei Fehler)
int kontakteLaden(Kontakt kontakte[], int maxAnzahl, char dateiname[]);
```

**Testablauf in `main()` – in dieser Reihenfolge:**

```console
1. 5 Kontakte erstellen und anzeigen
2. Alle Kontakte in "kontakte.bin" speichern
3. Array vollstaendig leeren (memset oder Schleife)
4. Kontakte aus Datei wieder laden
5. Geladene Kontakte anzeigen – muss identisch mit Schritt 1 sein!
6. Nach einem Namen suchen (einmal mit Treffer, einmal ohne)
```

> **Der entscheidende Beweis (Schritt 3–5):** Das Array wird nach
> dem Speichern **absichtlich geleert**, bevor geladen wird. Nur so
> beweist man, dass die Daten wirklich aus der Datei kommen – und
> nicht noch im Speicher stehen.

**Pflichtanforderungen:**

- [ ] `kontakteSpeichern` nutzt `fwrite` im **Binärmodus** (`"wb"`) mit `sizeof(Kontakt)`
- [ ] `kontakteLaden` nutzt `fread` im **Binärmodus** (`"rb"`)
- [ ] Array wird zwischen Speichern und Laden **nachweislich geleert** (und das in der Ausgabe sichtbar)
- [ ] `kontaktSuchen` verwendet `strstr()` (Teilstring, nicht exakter Vergleich)
- [ ] `NULL`-Rückgabe bei nicht-gefundenem Kontakt wird in `main()` behandelt

**Präsentationsfragen:**

1. Zeigt `kontakteSpeichern` – wie viele `fwrite`-Aufrufe gibt es? Warum reicht **ein einziger** für das gesamte Array?
2. Öffnet `kontakte.bin` nach dem Programmstart in einem Texteditor – was seht ihr? Warum ist das so?
3. Was ist der Unterschied zwischen `strcmp` und `strstr` bei der Suche? Demonstriert live: Was findet `strstr("Müller", "üll")`?
4. Warum ist `sizeof(Kontakt)` in `fwrite`/`fread` entscheidend – was würde passieren, wenn man eine falsche Grösse angibt?
5. Führt das Programm **zweimal** aus (ohne Dateipfad zu ändern) – werden beim zweiten Lauf die alten Kontakte überschrieben oder ergänzt? Warum? Wie müsste man `fopen` ändern, um anzuhängen?

---

© 2026 Lukas Müller – Licensed under CC BY-NC-ND 4.0
See [LICENSE](..\license.md) file for details.
