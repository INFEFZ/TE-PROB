|                             |                          |                               |
| --------------------------- | ------------------------ | ----------------------------- |
| **Elektrotechniker/-in HF** | **Programmiertechnik B** | ![logo](../x_gitres/logo.png) |

- [1. Gruppenarbeit Funktionen](#1-gruppenarbeit-funktionen)
  - [1.1. Ziel der Gruppenarbeit](#11-ziel-der-gruppenarbeit)
  - [1.2. Gruppeneinteilung und Aufträge](#12-gruppeneinteilung-und-aufträge)
    - [1.2.1. Gruppe 1: Zinsrechner-Bibliothek](#121-gruppe-1-zinsrechner-bibliothek)
    - [1.2.2. Gruppe 2: Statistik-Toolkit](#122-gruppe-2-statistik-toolkit)
    - [1.2.3. Gruppe 3: Textanalyse-Tool](#123-gruppe-3-textanalyse-tool)
    - [1.2.4. Gruppe 4: Kleines Kassensystem](#124-gruppe-4-kleines-kassensystem)

---

</br>

# 1. Gruppenarbeit Funktionen

| **Vorgabe**         | **Beschreibung**                                                        |
| :------------------ | :---------------------------------------------------------------------- |
| **Lernziele**       | Kennt die Möglichkeiten zur Modularisierung und Strukturierung von Code |
|                     | Kann Funktionen mit und ohne Parameter implementieren                   |
|                     | Kann Funktionen korrekt aufrufen                                        |
| **Sozialform**      | Gruppenarbeit: 2-3 Personen                                             |
| **Auftrag**         | siehe unten                                                             |
| **Hilfsmittel**     |                                                                         |
| **Zeitbedarf**      | 60min                                                                   |
| **Lösungselemente** | Funktionierendes Programm und Präsentation (Code erklären), ca. 5 min.  |
|                     | Jedes Gruppenmitglied muss Teile des Codes erklären können              |

> Hinweis zum KI-Einsatz
> Ihr dürft KI-Tools verwenden – aber: Ihr werdet den Code in der Präsentation erklären müssen.
> Das bedeutet:
>
> - Jede Zeile, die ihr abgebt, müsst ihr verstehen und erklären können
> - Ihr werdet gefragt: „Was passiert hier genau?", „Warum habt ihr das so gelöst?", „Was gibt diese Funktion zurück?"
> - Eine Lösung, die ihr nicht erklären könnt, gilt als nicht bestanden
> - Empfehlung: Nutzt KI als Lernhilfe, nicht als Schreibmaschine. Schreibt Teile selbst, lasst andere erklären, diskutiert als Gruppe.

## 1.1. Ziel der Gruppenarbeit

Die Lernenden sollen verstehen, wie der Speicher in C verwaltet wird, welche Gefahren es bei unsachgemässer Verwendung gibt, und wie Werte an Funktionen übergeben werden können.

## 1.2. Gruppeneinteilung und Aufträge

### 1.2.1. Gruppe 1: Zinsrechner-Bibliothek

**Szenario:**

- Eine Finanzapp benötigt eine kleine Berechnungsbibliothek für Zinsrechnungen. Ihr seid das Entwicklungsteam und sollt eine sauber strukturierte C-Lösung erstellen.

**Anforderungen:**

- Zu implementierende Funktionen (alle mit Prototypen am Anfang der Datei):

```c
// Berechnet Endkapital nach einfacher Verzinsung
double zinsEinfach(double kapital, double zinssatz, int jahre);

// Berechnet Endkapital nach Zinseszins
double zinseszins(double kapital, double zinssatz, int jahre);

// Berechnet benötigte Jahre bis Zielkapital erreicht (Zinseszins)
int jahreZumZiel(double startkapital, double zielkapital, double zinssatz);

// Gibt eine formatierte Vergleichstabelle aus (void!)
void zeigeVergleichstabelle(double kapital, double zinssatz, int maxJahre);
```

**Formeln:**

- Einfache Verzinsung: `K_n = K_0 × (1 + n × p/100)`
- Zinseszins: `K_n = K_0 × (1 + p/100)^n`
- Potenz ohne `<math.h>` selbst mit Schleife berechnen

Ausgabebeispiel für `zeigeVergleichstabelle(1000.0, 3.5, 5)`:

```console
Kapital: 1000.00 CHF | Zinssatz: 3.50%
| Jahr | Einfach (CHF) | Zinseszins (CHF) | Differenz (CHF) |
| ---- | ------------- | ---------------- | --------------- |
| 1    | 1035.00       | 1035.00          | 0.00            |
| 2    | 1070.00       | 1071.23          | 1.23            |
| 3    | 1105.00       | 1108.72          | 3.72            |
| 4    | 1140.00       | 1147.52          | 7.52            |
| 5    | 1175.00       | 1187.69          | 12.69           |
```

**Pflichtanforderungen:**

- [ ] Alle 4 Funktionen implementiert und funktionsfähig
- [ ] Prototypen korrekt deklariert
- [ ] `main()` testet alle Funktionen mit sinnvollen Werten
- [ ] Keine globalen Variablen
- [ ] Sinnvolle Variablennamen (kein a, b, x)

**Präsentationsfragen (werden gestellt – vorbereiten!):**

1. Zeig die Funktion jahreZumZiel und erkläre, wie die Schleife funktioniert.
2. Warum habt ihr für die Potenzberechnung eine eigene Funktion/Schleife geschrieben statt pow() aus <math.h>?
3. Was ist der Unterschied zwischen dem Parameter zinssatz in eurer Funktion und dem zinssatz in main()? (Scope!)
4. Was würde passieren, wenn jemand zinssatz = 0 übergibt? Wie könnte man das absichern?

---

</br>

### 1.2.2. Gruppe 2: Statistik-Toolkit

**Szenario:**

- Ein Dozent möchte ein kleines Kommandozeilentool, das Prüfungsnoten analysiert.
- Die Noten sind als Array im Code gespeichert. Ihr entwickelt die Analysefunktionen.

**Anforderungen:**

Zu implementierende Funktionen:

```c
// Berechnet den Durchschnitt eines int-Arrays
double berechneSchnitt(int noten[], int anzahl);

// Findet die beste Note (Pointer-Rückgabe für Min UND Max gleichzeitig)
void berechneMinMax(int noten[], int anzahl, int *min, int *max);

// Zählt, wie viele Noten >= grenze sind (bestanden)
int zaehleBestandene(int noten[], int anzahl, int grenze);

// Berechnet die Standardabweichung (Streuung der Noten)
double berechneStdAbw(int noten[], int anzahl);

// Gibt ein Histogramm der Notenverteilung aus (void)
void zeigeHistogramm(int noten[], int anzahl);
```

**Formel Standardabweichung:**

`σ = sqrt( Σ(xi - x̄)² / n )`

Hier darf `sqrt` aus `<math.h>` verwendet werden.

**Testdaten für main():**

```c
int noten[] = {4, 5, 6, 3, 5, 6, 4, 2, 5, 6, 4, 5, 3, 6, 5};
int anzahl = 15;
```

**Erwartete Ausgabe (Histogramm):**

```console
Note 2: ##  (2)
Note 3: ##  (2)
Note 4: ###  (3)
Note 5: #####  (5)
Note 6: ####  (4)
```

> (Anzahl `#` entspricht Häufigkeit)

**Ausgabe Gesamtbericht:**

```console
===== NOTENAUSWERTUNG =====
Anzahl Noten:    15
Durchschnitt:    4.53
Beste Note:      6
Schlechteste:    2
Standardabw.:    1.06
Bestanden (>=4): 12 von 15 (80.0%)
==========================
```

**Pflichtanforderungen:**

- [ ] `berechneMinMax` nutzt zwingend Call by Pointer
- [ ] `berechneSchnitt` und `berechneStdAbw` geben double zurück
- [ ] Histogramm mit #-Zeichen pro Notenpunkt
- [ ] Alle Funktionen mit Prototypen deklariert
- [ ] Keine hartcodierten Arraygrössen in den Funktionen (Parameter anzahl verwenden!)

**Präsentationsfragen:**

1. Erkläre die Signatur`void berechneMinMax(int noten[], int anzahl, int *min, int *max)` – warum sind `min` und `max` Pointer?
2. Was bedeutet `noten[]` als Parameter? Ist das Call by Value oder Call by Pointer?
3. Zeig die Schleife in `berechneStdAbw` und erkläre jeden Schritt.
4. Was passiert, wenn `anzahl = 0` übergeben wird? Welche Funktionen würden abstürzen?

---

</br>

### 1.2.3. Gruppe 3: Textanalyse-Tool

**Szenario:**

- Ein einfaches Tool soll Texte analysieren: Wörter zählen, Grossbuchstaben umwandeln, Häufigkeit bestimmter Zeichen ermitteln.
- Ihr nutzt intensiv `<string.h>` und `<ctype.h>`.

**Anforderungen:**

```c
// Zählt Anzahl Vokale (a,e,i,o,u – gross und klein) im String
int zaehleVokale(char *text);

// Zählt Anzahl Wörter (Trennzeichen: Leerzeichen)
int zaehleWoerter(char *text);

// Wandelt alle Kleinbuchstaben in Grossbuchstaben um (in-place via Pointer!)
void zuGrossschrift(char *text);

// Prüft ob ein String ein Palindrom ist (z.B. "racecar", "level")
int istPalindrom(char *text);    // gibt 1 (ja) oder 0 (nein) zurück

// Gibt Analyse-Bericht aus
void zeigeAnalyse(char *originalText);
```

**Teststrings für`main()`:**

```c
char text1[] = "Hallo Welt wie geht es dir heute";
char text2[] = "racecar";
char text3[] = "Ein Ingenieur geht nicht einfach";
```

Erwartete Ausgabe für `zeigeAnalyse("Hallo Welt")`:

```console
===== TEXTANALYSE =====
Original:    Hallo Welt
Grossschrift: HALLO WELT
Länge:       10 Zeichen
Wörter:      2
Vokale:      3
Palindrom:   Nein
=======================
```

**Wichtige Hinweise:**

- `strlen()` aus `<string.h>` für die Länge
- `toupper()` / `tolower()` aus `<ctype.h>` für Zeichenumwandlung
- Für Palindrom: ersten und letzten Buchstaben vergleichen, dann von innen weiter
- `zuGrossschrift` verändert den Original-String direkt (Call by Pointer!)

**Pflichtanforderungen:**

- [ ] `zuGrossschrift` modifiziert den String über den Pointer (kein Rückgabewert)
- [ ] `istPalindrom` funktioniert mit gerader und ungerader Länge
- [ ] Kein zweites Char-Array anlegen – Palindrom-Prüfung direkt im Original
- [ ] `zeigeAnalyse` ruft alle anderen Funktionen auf (Funktionskomposition)

**Präsentationsfragen:**

- Warum ist `char *text` ein Pointer? Ist das Call by Value oder Call by Pointer? Was könnte man verändern?
- Erkläre deine Palindrom-Logik – wie läuft die Schleife ab?
- Was macht `toupper()` genau? Aus welcher Bibliothek kommt es?
- Wenn `zuGrossschrift(text1)` aufgerufen wird – was passiert mit text1 danach? Zeig es in `main()`.

---

</br>

### 1.2.4. Gruppe 4: Kleines Kassensystem

**Szenario:**

- Ein kleiner Kiosk braucht ein simples Kassenprogramm. Preise und Mengen sind als Arrays gespeichert.
- Das System soll Quittungen ausgeben und Rabatte berechnen.

**Anforderungen:**

````c
// Berechnet Gesamtpreis eines Artikels (preis * menge)
double berechnePosten(double preis, int menge);

// Berechnet Summe aller Posten im Warenkorb
double berechneGesamtpreis(double preise[], int mengen[], int anzahlArtikel);

// Berechnet Rabatt: ab 50 CHF → 5%, ab 100 CHF → 10%, ab 200 CHF → 15%
double berechneRabatt(double gesamtpreis);

// Gibt formatierte Quittung aus (void)
void druckeQuittung(char *artikelNamen[], double preise[],
                    int mengen[], int anzahlArtikel);

// Prüft ob Betrag für Schein passt (Rückgeld berechnen)
void berechneRueckgeld(double betrag, double gegeben, double *rueckgeld, int *passt);
````

**Testdaten:**

```c
char *artikel[] = {"Kaffee", "Gipfeli", "Wasser", "Zeitung"};
double preise[] = {4.50, 1.80, 2.00, 3.20};
int mengen[]    = {2, 3, 1, 1};
```

**Erwartete Ausgabe:**

```console
========== QUITTUNG ==========
Kaffee        2x  4.50 =   9.00
Gipfeli       3x  1.80 =   5.40
Wasser        1x  2.00 =   2.00
Zeitung       1x  3.20 =   3.20
-----------------------------
Zwischensumme:            19.60
Rabatt (0%):               0.00
Gesamtbetrag:             19.60
-----------------------------
Gegeben:                  20.00
Rückgeld:                  0.40
==============================
```

**Pflichtanforderungen:**

- [ ] Rabattstufen korrekt implementiert (if-else Kaskade)
- [ ] `berechneRueckgeld` gibt Rückgeld UND eine Passt-Flag via Pointer zurück
- [ ] `druckeQuittung` ruft `berechnePosten`, `berechneGesamtpreis` und `berechneRabatt` intern auf
- [ ] Quittungsformat sauber ausgerichtet (mit `%-15s`, `%5.2f` etc.)

**Präsentationsfragen:**

1. Erkläre die Rabattstufenlogik – warum habt ihr `if-else if` statt mehrerer if verwendet?
2. Was bedeutet `char *artikelNamen[]` als Parameter? Was ist das für ein Datentyp?
3. Zeig `berechneRueckgeld` – warum sind `rueckgeld` und `passt` Pointer?
4. Angenommen, ein vierter Rabattsatz soll ergänzt werden. Wo im Code müsst ihr was ändern?
