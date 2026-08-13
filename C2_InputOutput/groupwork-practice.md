|                             |                          |                               |
| --------------------------- | ------------------------ | ----------------------------- |
| **Elektrotechniker/-in HF** | **Programmiertechnik B** | ![logo](../x_gitres/logo.png) |

</br>

# Gruppenarbeit Input und Output mit Dateien

| **Vorgabe**         | **Beschreibung**                                                                         |
| :------------------ | :--------------------------------------------------------------------------------------- |
| **Lernziele**       | Das EVA-Prinzip im Kontext von Dateioperationen erläutern                                |
|                     | Dateien mit fopen() korrekt öffnen (geeigneten Modus wählen) und mit fclose() schliessen |
|                     | Den Rückgabewert NULL nach fopen() prüfen und Fehler behandeln                           |
|                     | Strukturen mit fwrite und fread binär speichern und laden                                |
|                     | Verstehst den Unterschied zwischen Text- und Binärmodus                                  |
|                     | Kannst formatiert mit Dateien arbeiten und Datenstrukturen direkt binär persistieren     |
| **Sozialform**      | Gruppenarbeit: 2-3 Personen                                                              |
| **Auftrag**         | siehe unten                                                                              |
| **Hilfsmittel**     |                                                                                          |
| **Zeitbedarf**      | 60min                                                                                    |
| **Lösungselemente** | Abgabe: Alle Dateien (.h und .c) als Gesamtprojekt                                       |
|                     | Funktionierendes Programm und Präsentation (Code erklären), ca. 5 min.                   |
|                     | Jedes Gruppenmitglied muss Teile des Codes erklären können                               |

> ## Hinweis zum KI-Einsatz
>
> Dateioperationen lassen sich leicht generieren – aber nur, wer den Ablauf
> wirklich verstanden hat, kann live damit umgehen. In der Präsentation wird
> jedes Mitglied einzeln gefragt:
>
> - *„Öffne die erzeugte Datei in einem Texteditor – sieht der Inhalt so aus, wie du erwartest?"*
> - *„Was passiert, wenn du das Programm zweimal hintereinander ausführst – wird die Datei überschrieben oder ergänzt? Warum?"*
> - *„Lösche eine Zeile mitten in der Datenstruktur, dann starte das Programm neu – was passiert? Warum?"*
> - *„Was gibt `fopen` zurück, wenn die Datei nicht existiert? Zeig mir die Stelle in deinem Code, die das behandelt."*
> - *„Warum genau diese Modus-Angabe (`r`, `w`, `rb`, ...) und keine andere?"*
>
> Das Terminal und der erzeugte Dateiinhalt sind der Beweis – nicht nur der Code selbst.

---

</br>

## Gruppenarbeit A – «Kontaktverwaltung mit Textdatei»

**Szenario:**

- Sie entwickeln ein kleines Kontaktverwaltungsprogramm, das Kontakte dauerhaft in einer Textdatei speichert.
- Das Programm soll Kontakte hinzufügen, alle anzeigen und nach Namen suchen können – jeweils mit der Datei als Speicherort, nicht nur im Arbeitsspeicher.

**Anforderungen:**

```c
typedef struct {
    char name[40];
    char telefon[20];
    int  alter;
} Kontakt;

// Schreibt einen NEUEN Kontakt ans Ende der Datei (Anhängen, nicht überschreiben!)
void kontaktAnhaengen(char *dateiname, Kontakt k);

// Liest ALLE Kontakte aus der Datei und gibt sie aus
void kontakteAlleAnzeigen(char *dateiname);

// Durchsucht die Datei nach einem Namen, gibt 1 zurück wenn gefunden (und druckt ihn)
int kontaktSuchen(char *dateiname, char *gesuchterName);

// Zählt, wie viele Kontakte aktuell in der Datei gespeichert sind
int kontaktAnzahl(char *dateiname);
```

**Dateiformat (Textdatei, ein Kontakt pro Zeile, durch `;` getrennt):**

```console
Müller Anna;079 123 45 67;28
Berger Klaus;044 987 65 43;42
Schmid Sophie;078 555 12 34;35
```

**Aufgabenstellung:**

**Schritt 1:** Implementiert alle vier Funktionen.

**Schritt 2:** Schreibt ein `main()`, das:

1. Drei Kontakte über `kontaktAnhaengen` speichert
2. Alle Kontakte anzeigt
3. Nach einem existierenden und einem nicht-existierenden Namen sucht
4. Die Anzahl ausgibt

**Schritt 3 – Wichtiger Test:** Führt euer Programm **zweimal hintereinander**
aus, ohne die Datei zu löschen. Beobachtet und dokumentiert das Ergebnis.

```bash
gcc main.c -o kontakte
./kontakte
./kontakte    # nochmal – was passiert mit der Datei?
```

### Erwartete Ausgabe (Beispiel, nach EINMALIGEM Programmlauf)

```console
=== Alle Kontakte ===
Müller Anna      | 079 123 45 67 | 28 Jahre
Berger Klaus     | 044 987 65 43 | 42 Jahre
Schmid Sophie    | 078 555 12 34 | 35 Jahre

Suche "Berger Klaus": GEFUNDEN -> 044 987 65 43, 42 Jahre
Suche "Meier Tom": NICHT GEFUNDEN

Anzahl Kontakte: 3
```

**Pflichtanforderungen:**

- [ ] `kontaktAnhaengen` öffnet die Datei im **Append**-Modus (`"a"`), nicht `"w"`
- [ ] `kontakteAlleAnzeigen`, `kontaktSuchen`, `kontaktAnzahl` öffnen die Datei jeweils im **Lese**-Modus
- [ ] Jede Funktion prüft `fopen()` auf `NULL` und behandelt den Fehlerfall sinnvoll
- [ ] Jede Funktion schliesst die Datei korrekt, auch im Fehlerfall
- [ ] `kontaktSuchen` durchsucht **zeilenweise** mit `fgets` + Parsing (nicht mit `fscanf` direkt – Begründung in der Präsentation)
- [ ] Beobachtung aus Schritt 3 schriftlich dokumentiert

**Präsentationsfragen:**

1. Führt das Programm jetzt live zweimal nacheinander aus – was seht ihr in der Datei danach? Was wäre passiert, wenn `kontaktAnhaengen` stattdessen `"w"` verwendet hätte?
2. Öffnet `kontakte.txt` in einem Texteditor – entspricht der Inhalt exakt eurem erwarteten Format?
3. Was passiert in eurem Code, wenn die Datei beim ersten `kontakteAlleAnzeigen()`-Aufruf noch gar nicht existiert? Zeigt die Fehlerbehandlung.
4. Warum verwendet ihr `fgets` statt `fscanf`, um die Kontakte zu durchsuchen? Was wäre der Nachteil von `fscanf` hier (Namen mit Leerzeichen)?
5. Was müsstet ihr ändern, damit man einen Kontakt auch **löschen** kann? (Hinweis: Textdateien lassen sich nicht "mittendrin" löschen – wie würdet ihr das lösen?)

---

</br>

## Gruppenarbeit B – «Notenverwaltung: CSV-Export und Import»

**Szenario:**
Ein Dozent erfasst Prüfungsnoten im Programm und möchte sie als CSV-Datei exportieren (z.B. für Excel) – und später wieder importieren können, um mit den Daten weiterzuarbeiten.

**Anforderungen:**

```c
typedef struct {
    char name[40];
    double mathe;
    double deutsch;
    double englisch;
} Notenblatt;

// Exportiert ein Array von Notenblättern als CSV mit Kopfzeile
void notenExportieren(Notenblatt blaetter[], int anzahl, char *dateiname);

// Importiert CSV-Daten zurück in ein Array, gibt die Anzahl gelesener Datensätze zurück
int notenImportieren(Notenblatt blaetter[], int maxAnzahl, char *dateiname);

// Berechnet den Durchschnitt EINES Notenblatts über alle drei Fächer
double notenDurchschnitt(Notenblatt n);

// Gibt eine Zusammenfassung aller importierten Noten aus (inkl. Durchschnitt je Person)
void notenZusammenfassung(Notenblatt blaetter[], int anzahl);
```

**Erwartetes CSV-Format (mit Kopfzeile!):**

```console
Name,Mathe,Deutsch,Englisch
Anna Keller,5.5,4.8,5.2
Ben Huber,4.0,4.5,3.8
Clara Wyss,5.8,5.5,6.0
```

> **Wichtiger Hinweis:** Die erste Zeile ist eine Kopfzeile (Header) und muss beim Import **übersprungen** werden – sie enthält keine Daten!

**Aufgabenstellung:**

**Schritt 1:** Implementiert alle vier Funktionen.

**Schritt 2:** Testdaten in `main()` anlegen, exportieren, **danach das Array komplett leeren/überschreiben**, und aus der Datei wieder importieren – als Beweis, dass der Import wirklich funktioniert und nicht nur die alten Werte im Speicher zeigt.

```c
// Test-Idee für Schritt 2:
Notenblatt original[3] = { /* ... */ };
notenExportieren(original, 3, "noten.csv");

Notenblatt importiert[10];
for (int i = 0; i < 10; i++) importiert[i] = (Notenblatt){0};  // bewusst leeren!

int anzahl = notenImportieren(importiert, 10, "noten.csv");
notenZusammenfassung(importiert, anzahl);   // muss trotzdem korrekt funktionieren!
```

**Schritt 3:** Öffnet die erzeugte CSV-Datei in einem Texteditor (oder Excel/LibreOffice, falls verfügbar) und prüft, ob sie korrekt interpretierbar ist.

### Erwartete Ausgabe

```console
=== Notenzusammenfassung (importiert aus Datei) ===
Anna Keller      | Mathe: 5.50 | Deutsch: 4.80 | Englisch: 5.20 | Ø 5.17
Ben Huber        | Mathe: 4.00 | Deutsch: 4.50 | Englisch: 3.80 | Ø 4.10
Clara Wyss       | Mathe: 5.80 | Deutsch: 5.50 | Englisch: 6.00 | Ø 5.77

Anzahl importierter Datensätze: 3
```

**Pflichtanforderungen:**

- [ ] Export schreibt Kopfzeile **und** Daten korrekt formatiert (`fprintf`)
- [ ] Import überspringt die Kopfzeile korrekt (z.B. mit einem zusätzlichen `fgets`-Aufruf vor der Schleife)
- [ ] Import nutzt `fscanf` **oder** `fgets`+Parsing – Wahl muss begründet werden können
- [ ] Beweis erbracht, dass Import unabhängig vom Originalarray funktioniert (Array vorher geleert)
- [ ] `notenDurchschnitt` korrekt für jede importierte Person berechnet

**Präsentationsfragen:**

1. Zeigt die erzeugte CSV-Datei im Texteditor – entspricht sie exakt dem geforderten Format inkl. Kopfzeile?
2. Wie genau überspringt euer Code die Kopfzeile beim Import? Was würde passieren, wenn ihr das vergessen hättet?
3. Beweist live: Leert das `importiert`-Array nochmals explizit, führt den Import erneut aus – funktioniert die Zusammenfassung trotzdem korrekt?
4. Was passiert, wenn die CSV-Datei eine zusätzliche leere Zeile am Ende hat? Testet das live, falls eure Funktion das nicht abfängt – was passiert?
5. Welche Formatangabe (`%lf`, `%s`, Trennzeichen) verwendet ihr in `fscanf`/`sscanf`? Erklärt die genaue Formatstring-Syntax.

---

</br>

## Gruppenarbeit C – «Binäre Datenbank für ein Inventarsystem»

**Szenario:**

- Ein kleines Inventarsystem soll Artikel **binär** speichern – schneller und platzsparender als Text.
- Ihr implementiert das komplette Speichern/Laden mit `fwrite`/`fread` und vergleicht es mit der Textvariante.

**Anforderungen:**

```c
typedef struct {
    int    artikelnummer;
    char   bezeichnung[40];
    int    bestand;
    double preis;
} Artikel;

// Speichert ein komplettes Array von Artikeln binär (EIN fwrite-Aufruf für alle!)
void inventarBinSpeichern(Artikel artikel[], int anzahl, char *dateiname);

// Lädt Artikel aus einer Binärdatei, gibt Anzahl geladener Artikel zurück
int inventarBinLaden(Artikel artikel[], int maxAnzahl, char *dateiname);

// Ändert den Bestand EINES Artikels direkt in der Datei (ohne alles neu zu laden!)
// Hinweis: fseek() verwenden, um zur richtigen Position zu springen
int bestandAktualisieren(char *dateiname, int artikelnummer, int neuerBestand);

// Gibt die Dateigrösse in Bytes aus (mit fseek/ftell)
long dateigroesseErmitteln(char *dateiname);
```

**Für `bestandAktualisieren` – die Kernidee:**

```c
// Da alle Artikel exakt gleich gross sind (sizeof(Artikel)), kann man die
// Position des n-ten Artikels berechnen und GEZIELT überschreiben,
// ohne die ganze Datei neu zu schreiben:

FILE *datei = fopen(dateiname, "r+b");   // r+b: lesen UND schreiben, binär!
// ... Artikel suchen (Index i bekannt) ...
fseek(datei, i * sizeof(Artikel), SEEK_SET);   // an die Position des i-ten Artikels springen
fwrite(&aktualisiertesArtikel, sizeof(Artikel), 1, datei);  // NUR diesen einen überschreiben
```

**Aufgabenstellung:**

**Schritt 1:** Implementiert alle vier Funktionen.

**Schritt 2:** Testet in `main()`:

1. Mindestens 5 Artikel binär speichern
2. Wieder laden und anzeigen
3. Den Bestand eines Artikels gezielt ändern (über `bestandAktualisieren`)
4. Erneut laden und beweisen, dass nur dieser eine Wert geändert wurde
5. Dateigrösse ausgeben und mit `anzahl * sizeof(Artikel)` vergleichen

**Schritt 3 – Vergleich dokumentieren:**
Speichert dieselben Artikel zusätzlich als Textdatei (mit `fprintf`, ähnlich wie in der Theorie) und vergleicht die Dateigrössen:

```console
Vergleich:
  Binärdatei: ___ Bytes
  Textdatei:  ___ Bytes
```

**Erwartete Ausgabe (Beispiel):**

```console
=== Inventar (aus Binärdatei geladen) ===
1001 | Schrauben M6     |   500 |    0.05 CHF
1002 | Muttern M6       |   320 |    0.03 CHF
1003 | Bohrer 5mm       |    48 |    4.90 CHF

Bestand von Artikel 1003 aktualisiert: 48 -> 35

=== Inventar (nach Aktualisierung neu geladen) ===
1001 | Schrauben M6     |   500 |    0.05 CHF
1002 | Muttern M6       |   320 |    0.03 CHF
1003 | Bohrer 5mm       |    35 |    4.90 CHF   ← nur dieser Wert geändert!

Dateigrösse: 156 Bytes (= 3 Artikel * 52 Bytes)

Vergleich:
  Binärdatei: 156 Bytes
  Textdatei:  98 Bytes
```

**Pflichtanforderungen:**

- [ ] `inventarBinSpeichern` nutzt **einen** `fwrite`-Aufruf für das **gesamte** Array
- [ ] `bestandAktualisieren` nutzt `fseek` und überschreibt **gezielt nur einen** Artikel (nicht die ganze Datei neu schreiben!)
- [ ] Modus `"r+b"` korrekt für das gezielte Update verwendet
- [ ] Beweis erbracht: nach dem Update sind alle anderen Artikel unverändert
- [ ] Dateigrössenvergleich Binär vs. Text durchgeführt und dokumentiert

**Präsentationsfragen:**

1. Erklärt die `fseek`-Berechnung in `bestandAktualisieren` – warum `i * sizeof(Artikel)`?
2. Was passiert, wenn ihr `"wb"` statt `"r+b"` für das gezielte Update verwenden würdet? Probiert es notfalls live aus – was geht schief?
3. Warum ist die Binärdatei in eurem Test grösser als die Textdatei, obwohl Binärdaten theoretisch kompakter sein sollten? (Hinweis: feste Feldgrössen wie `char bezeichnung[40]`)
4. Öffnet die Binärdatei in einem Texteditor (oder mit `cat` im Terminal) – was seht ihr? Warum ist das so?
5. Was würde passieren, wenn ihr die binäre Inventardatei auf einem komplett anderen Computer/Betriebssystem einlesen würdet? Welches Risiko besteht laut Theorie?

---

</br>

## Gruppenarbeit D – «Datei-Konverter: Text ↔ Binär»

**Szenario:**

Ihr entwickelt ein Konvertierungstool, das Messdaten zwischen einem menschenlesbaren Textformat und einem platzsparenden Binärformat hin- und herwandeln kann – ein typischer Anwendungsfall in der Praxis (z.B. Sensordaten exportieren für Menschen, intern aber binär verarbeiten).

**Anforderungen:**

```c
typedef struct {
    int    sensorId;
    double temperatur;
    double luftfeuchtigkeit;
    long   zeitstempel;   // einfacher Zähler statt echtem Datum, z.B. Sekunden seit Start
} Messwert;

// Liest Messdaten aus einer TEXT-Datei (Format unten) in ein Array
int textLaden(Messwert werte[], int maxAnzahl, char *dateiname);

// Schreibt ein Array von Messwerten als TEXT-Datei
void textSpeichern(Messwert werte[], int anzahl, char *dateiname);

// Konvertiert: liest Textdatei, schreibt das Ergebnis als Binärdatei
int konvertiereTextZuBinaer(char *textDatei, char *binDatei);

// Konvertiert: liest Binärdatei, schreibt das Ergebnis als Textdatei
int konvertiereBinaerZuText(char *binDatei, char *textDatei);

// Vergleicht zwei Messwert-Arrays auf Inhaltsgleichheit (zur Verifikation!)
int sindGleich(Messwert a[], Messwert b[], int anzahl);
```

**Textformat (`messwerte.txt`):**

```console
1001 23.50 45.20 100
1002 23.70 44.80 160
1003 22.90 46.10 220
1004 24.10 43.50 280
```

**Aufgabenstellung:**

**Schritt 1:** Implementiert alle Funktionen. `textLaden`/`textSpeichern` arbeiten mit `fscanf`/`fprintf`, die Konvertierungsfunktionen kombinieren Text- und Binärfunktionen aus der Theorie (inkl. `fwrite`/`fread`).

**Schritt 2 – Der entscheidende Beweis (Rundreise-Test):**

Führt eine komplette Konvertierungskette aus und beweist, dass **keine Daten verloren gehen**:

```console
Text-Original → Binär → Text (neu) → vergleiche mit Original
```

```c
// Testablauf in main():
Messwert original[10];
int n = textLaden(original, 10, "messwerte.txt");

konvertiereTextZuBinaer("messwerte.txt", "messwerte.bin");
konvertiereBinaerZuText("messwerte.bin", "messwerte_zurueck.txt");

Messwert zurueck[10];
int n2 = textLaden(zurueck, 10, "messwerte_zurueck.txt");

if (n == n2 && sindGleich(original, zurueck, n)) {
    printf("ERFOLG: Rundreise verlustfrei!\n");
} else {
    printf("FEHLER: Daten unterscheiden sich!\n");
}
```

**Schritt 3:** Zeigt die Dateigrössen aller drei Dateien (`messwerte.txt`, `messwerte.bin`, `messwerte_zurueck.txt`) mit `ls -l` im Terminal.

 **Erwartete Ausgabe:**

```console
Geladen: 4 Messwerte aus messwerte.txt
Konvertiert zu messwerte.bin
Zurückkonvertiert zu messwerte_zurueck.txt

Vergleich Original vs. Rundreise:
  Sensor 1001: 23.50 / 45.20 -> identisch
  Sensor 1002: 23.70 / 44.80 -> identisch
  Sensor 1003: 22.90 / 46.10 -> identisch
  Sensor 1004: 24.10 / 43.50 -> identisch

ERFOLG: Rundreise verlustfrei!

Dateigrössen:
  messwerte.txt:          78 Bytes
  messwerte.bin:          96 Bytes
  messwerte_zurueck.txt:  78 Bytes
```

**Pflichtanforderungen:**

- [ ] Vollständige Konvertierungskette funktioniert in beide Richtungen
- [ ] `sindGleich` vergleicht **jedes Feld** jedes Messwerts (nicht nur grob)
- [ ] Rundreise-Test ist im Code enthalten und das Ergebnis wird sichtbar ausgegeben
- [ ] Alle Dateien werden korrekt geöffnet, geprüft (`NULL`) und geschlossen
- [ ] Dateigrössenvergleich über `ls -l` oder eine eigene Funktion gezeigt

**Präsentationsfragen:**

1. Führt den Rundreise-Test live vor – funktioniert er? Verändert ihr testweise einen Wert in `messwerte.bin` mit einem Hex-Editor oder direkt im Code – schlägt der Vergleich danach korrekt fehl?
2. Warum ist `messwerte.bin` grösser als `messwerte.txt`, obwohl Binärdaten "kompakter" sein sollten? Was genau braucht in der `Messwert`-Struktur wie viele Bytes?
3. Zeigt den Code-Abschnitt, der die Konvertierung Text→Binär durchführt – welche Funktionen aus welchem Modul (Text-I/O oder Binär-I/O) werden dort kombiniert?
4. Was würde passieren, wenn die Textdatei eine fehlerhafte Zeile enthält (z.B. ein fehlender Wert)? Testet das live – bricht euer `textLaden` sauber ab oder produziert es falsche Daten?
5. Welchen praktischen Vorteil hat ein solches Konvertierungstool in einem echten Sensor-Projekt?

---

© 2026 Lukas Müller – Licensed under CC BY-NC-ND 4.0
See [LICENSE](../license.md) file for details.
