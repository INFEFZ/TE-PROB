|                             |                          |                               |
| --------------------------- | ------------------------ | ----------------------------- |
| **Elektrotechniker/-in HF** | **Programmiertechnik B** | ![Logo](../x_gitres/logo.png) |

- [1. Das Kursprojekt «Messwerterfassung»](#1-das-kursprojekt-messwerterfassung)
  - [1.1. Idee und Zweck](#11-idee-und-zweck)
  - [1.2. Wie das Projekt eingesetzt wird](#12-wie-das-projekt-eingesetzt-wird)
  - [1.3. Projektübersicht über alle Tage](#13-projektübersicht-über-alle-tage)
- [2. Die Ausbaustufen](#2-die-ausbaustufen)
  - [2.1. Tag 1 – Blöcke und Gültigkeitsbereiche](#21-tag-1--blöcke-und-gültigkeitsbereiche)
  - [2.2. Tag 2 – Funktionen und Übergabemechanismen](#22-tag-2--funktionen-und-übergabemechanismen)
  - [2.3. Tag 3 – Arrays und Pointer](#23-tag-3--arrays-und-pointer)
  - [2.4. Tag 4 – Modularisierung und Makefile](#24-tag-4--modularisierung-und-makefile)
  - [2.5. Tag 5 – Rekursion und Strings](#25-tag-5--rekursion-und-strings)
  - [2.6. Tag 6 – Strukturen und Enums](#26-tag-6--strukturen-und-enums)
  - [2.7. Tag 7 – Verkettete Liste](#27-tag-7--verkettete-liste)
  - [2.8. Tag 8 – Sortieren und Suchen](#28-tag-8--sortieren-und-suchen)
  - [2.9. Tag 9 – Bitfelder, Datei-I/O und dynamischer Speicher](#29-tag-9--bitfelder-datei-io-und-dynamischer-speicher)
  - [2.10. Tag 10 – Grafische Oberfläche mit WPF](#210-tag-10--grafische-oberfläche-mit-wpf)
  - [2.11. Tag 11 – Objektorientierung in C++](#211-tag-11--objektorientierung-in-c)
- [3. Einsatz im Unterricht](#3-einsatz-im-unterricht)
  - [Ablauf pro Tag (Variante «Standard»)](#ablauf-pro-tag-variante-standard)
  - [Verknüpfung mit der Praxisarbeit (Tag 7)](#verknüpfung-mit-der-praxisarbeit-tag-7)
  - [Mögliche Erweiterungen für schnelle Gruppen](#mögliche-erweiterungen-für-schnelle-gruppen)

---

</br>

# 1. Das Kursprojekt «Messwerterfassung»

## 1.1. Idee und Zweck

Alle Module dieses Kurses arbeiten mit eigenen, isolierten Beispielen. Das
Kursprojekt ergänzt diese um einen **durchgehenden roten Faden**: **eine einzige
Anwendung**, die von Tag 1 bis Tag 11 mitwächst und bei jedem neuen Thema ein
konkretes Problem löst, das am Vortag noch bestand.

```bash
Tag 3:  "Ich kann 24 Messwerte speichern – aber nur genau 24."
        ↓
Tag 7:  Verkettete Liste → beliebig viele Messwerte

Tag 3:  "Zeit, Wert und Sensorname liegen in drei getrennten Arrays."
        ↓
Tag 6:  struct → alles gehört zusammen an einem Ort

Tag 6:  "Beim Programmende sind alle Daten weg."
        ↓
Tag 9:  Datei-I/O → Messwerte überleben den Programmlauf
```

> **Didaktisches Prinzip:** Nicht *„heute lernen wir Strukturen"*, sondern
> *„unsere Messwerterfassung hat ein Problem – Strukturen lösen es"*.
> Die Studierenden erleben jedes Konzept als **Antwort auf einen selbst erlebten
> Schmerzpunkt**, nicht als abstrakten Stoff.

**Was das Projekt zusätzlich leistet:**

| **Nutzen**           | **Erklärung**                                                        |
| -------------------- | -------------------------------------------------------------------- |
| Motivation           | Sichtbarer Fortschritt an einer «echten» Anwendung                   |
| Wiederholung         | Jeder Tag greift den Code des Vortags auf – automatische Repetition  |
| Transferkompetenz    | Bestehenden Code erweitern statt jedes Mal bei null beginnen         |
| Prüfungsvorbereitung | Am Ende existiert ein durchgehendes Referenzbeispiel für alle Themen |
| Praxisarbeit         | Ideale Vorlage für den Kickoff an Tag 7                              |

## 1.2. Wie das Projekt eingesetzt wird

Das Projekt ist **kein zusätzlicher Stoff**, sondern ein Gefäss für den
bestehenden. Es lässt sich flexibel dosieren:

| **Variante** | **Zeitbedarf** | **Vorgehen**                                           |
| ------------ | -------------- | ------------------------------------------------------ |
| **Minimal**  | 5 min/Tag      | Nur die Ausbaustufe als Demo zeigen und besprechen     |
| **Standard** | 15–20 min/Tag  | Studierende erweitern die Vorlage selbst um einen Teil |
| **Intensiv** | 30 min/Tag     | Ausbaustufe ersetzt eine bestehende Übungsaufgabe      |

> 💡 **Empfehlung:** Variante *Standard* – die Studierenden bekommen zu Beginn
> jedes Tages den Stand des Vortags als Vorlage und erweitern ihn. Wer den
> Vortag verpasst hat, kann trotzdem einsteigen.

## 1.3. Projektübersicht über alle Tage

```bash
┌──────┬────────────────────────┬───────────────────────────────────────────┐
│ Tag  │ Thema                  │ Was das Projekt dazugewinnt               │
├──────┼────────────────────────┼───────────────────────────────────────────┤
│  1   │ Blöcke, Scope          │ Grundgerüst, globaler Messungszähler      │
│  2   │ Funktionen             │ Umrechnung °C/°F/K, Min/Max via Pointer   │
│  3   │ Arrays, Pointer        │ 24 Stundenwerte, Statistik, Kalibrierung  │
│  4   │ Modularisierung        │ Aufteilung in Module + Makefile           │
│  5   │ Rekursion, Strings     │ Rekursive Auswertung, Sensornamen         │
│  6   │ Structs, Enums         │ Messpunkt-Struktur, Sensortyp, Status     │
│  7   │ Datenstrukturen        │ Verkettete Liste – unbegrenzt viele Werte │
│  8   │ Sortieren, Suchen      │ Sortierung nach Zeit/Wert/Name, Suche     │
│  9   │ Bitfelder, I/O, malloc │ Statusflags, Speichern/Laden, dynamisch   │
│ 10   │ WPF / C#               │ Grafische Oberfläche für dieselben Daten  │
│ 11   │ OOP / C++              │ Klasse Messreihe – Kapselung, Vererbung   │
└──────┴────────────────────────┴───────────────────────────────────────────┘
```

---

</br>

# 2. Die Ausbaustufen

> Der vollständige, lauffähige Code jeder Stufe liegt im Ordner
> `x_projekt/tagXX/`. Alle Stufen wurden kompiliert und getestet.

## 2.1. Tag 1 – Blöcke und Gültigkeitsbereiche

**Problem:** Ein Sensor liefert Messwerte. Wir wollen mitzählen, wie viele
Messungen erfasst wurden – und verstehen, wo welche Variable lebt.

**Neue Konzepte:** globale Variable, `static`, lokale Variable, Blockgültigkeit

```c
int anzahlMessungen = 0;        /* global: Data-Segment, ganzes Programm */

void messungErfassen(double wert) {
    static int aufrufe = 0;      /* static: behält Wert zwischen Aufrufen */
    int lokal = 0;               /* auto: Stack, nur in dieser Funktion    */
    aufrufe++;
    lokal = aufrufe * 10;
    anzahlMessungen++;
    printf("  Messung %d: %.1f C  (aufrufe=%d, lokal=%d)\n",
           anzahlMessungen, wert, aufrufe, lokal);
}
```

```bash
Ausgabe:
  Messung 1: 18.5 C  (aufrufe=1, lokal=10)
  Messung 2: 21.2 C  (aufrufe=2, lokal=20)
  Messung 3: 19.8 C  (aufrufe=3, lokal=30)

Global sichtbar: anzahlMessungen = 3
```

**Leitfrage für die Klasse:** *Warum zählt `aufrufe` hoch, `lokal` aber nicht?*

---

## 2.2. Tag 2 – Funktionen und Übergabemechanismen

**Problem vom Vortag:** Alles steht in `main()`. Die Umrechnung Celsius→Fahrenheit
müssten wir für jeden Messwert erneut hinschreiben.

**Neue Konzepte:** Funktionen, Rückgabewerte, Call by Value vs. Call by Pointer

```c
double celsiusZuFahrenheit(double c) { return c * 1.8 + 32.0; }
double celsiusZuKelvin(double c)     { return c + 273.15; }

/* Call by Pointer: zwei Rückgabewerte gleichzeitig */
void grenzwerte(double a, double b, double c, double *min, double *max) {
    *min = (a < b) ? a : b;  if (c < *min) *min = c;
    *max = (a > b) ? a : b;  if (c > *max) *max = c;
}

void kalibrierenFalsch(double messwert)   { messwert  += 0.5; }  /* wirkungslos */
void kalibrierenRichtig(double *messwert) { *messwert += 0.5; }  /* wirkt       */
```

```bash
Ausgabe:
Messwert 1: 21.5 C = 70.7 F = 294.65 K
Minimum: 19.2 C | Maximum: 23.8 C

Nach kalibrierenFalsch:  20.0  (unverändert!)
Nach kalibrierenRichtig: 20.5  (korrigiert)
```

**Leitfrage:** *Warum braucht die Sensorkalibrierung zwingend einen Pointer?*

---

## 2.3. Tag 3 – Arrays und Pointer

**Problem vom Vortag:** Drei Messwerte brauchen drei Variablen. Für einen
ganzen Tag (24 Werte) wären das 24 Variablen.

**Neue Konzepte:** Array, Array als Funktionsparameter, Pointer-Arithmetik

```c
#define STUNDEN 24

double schnitt(double w[], int n) {
    double s = 0.0;
    for (int i = 0; i < n; i++) s += w[i];
    return s / n;
}

/* Dasselbe mit Pointer-Arithmetik statt Index */
double schnittMitPointer(double *w, int n) {
    double s = 0.0;
    for (double *p = w; p < w + n; p++) s += *p;
    return s / n;
}

/* Arrays werden IMMER per Pointer übergeben – Original wird verändert! */
void kalibriereAlle(double w[], int n, double offset) {
    for (int i = 0; i < n; i++) w[i] += offset;
}
```

```bash
Ausgabe:
Durchschnitt:      16.63 C
Durchschnitt (Ptr):16.63 C  <- identisch
Minimum / Maximum: 10.5 / 23.4 C
Wärmste Stunde:   14 Uhr (23.4 C)

Sensor-Offset +0.3 anwenden...
Neuer Durchschnitt: 16.93 C  <- Original wurde verändert!
```

**Leitfrage:** *`kalibriereAlle` hat keinen `*` im Parameter – warum wirkt die
Änderung trotzdem auf das Original?*

---

## 2.4. Tag 4 – Modularisierung und Makefile

**Problem vom Vortag:** `main.c` wird unübersichtlich. Berechnung und Ausgabe
sind vermischt.

**Neue Konzepte:** `.h`/`.c`-Trennung, Include-Guards, `static`, `extern`, Makefile

**Neue Projektstruktur:**

```bash
tag04/
├── Makefile
├── main.c          ← nur Ablaufsteuerung
├── messwerte.h     ← Schnittstelle Berechnung
├── messwerte.c     ← Implementierung (mit privater Hilfsfunktion)
├── ausgabe.h       ← Schnittstelle Darstellung
└── ausgabe.c       ← Implementierung
```

```c
/* messwerte.c – die Hilfsfunktion bleibt privat */
static double summe(double w[], int n) {      /* nur in dieser Datei sichtbar */
    double s = 0.0;
    for (int i = 0; i < n; i++) s += w[i];
    return s;
}
double messwerteSchnitt(double w[], int n) { return summe(w, n) / n; }
```

```makefile
CC       = gcc
CFLAGS   = -Wall -Wextra -std=c11 -g
TARGET   = main
BUILDDIR = build
SRCS = main.c messwerte.c ausgabe.c
OBJS = $(SRCS:%.c=$(BUILDDIR)/%.o)

all: $(BUILDDIR)/$(TARGET)

$(BUILDDIR)/$(TARGET): $(OBJS)
	$(CC) $^ -o $@

$(BUILDDIR)/%.o: %.c messwerte.h ausgabe.h | $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

run: $(BUILDDIR)/$(TARGET)
	@./$(BUILDDIR)/$(TARGET)

clean:
	rm -rf $(BUILDDIR)

.PHONY: all run clean
```

**Leitfrage:** *Ändere `ausgabe.h` und führe `make` aus – welche `.o`-Dateien
werden neu gebaut? Sage es voraus, bevor du `make` startest.*

---

## 2.5. Tag 5 – Rekursion und Strings

**Problem:** Sensornamen wie `"aussen-01"` sind uneinheitlich geschrieben, und
manche Auswertungen lassen sich rekursiv eleganter formulieren.

**Neue Konzepte:** Rekursion, `strlen`, `strchr`, `strncpy`, `toupper`

```c
/* Rekursiv: Maximum einer Messreihe */
double maxRekursiv(double w[], int n) {
    if (n == 1) return w[0];                        /* Basisfall */
    double restMax = maxRekursiv(w, n - 1);
    return (w[n-1] > restMax) ? w[n-1] : restMax;
}

/* Sensorname "aussen-01" → Standort "aussen" extrahieren */
void standortExtrahieren(const char *sensorname, char *ziel, size_t groesse) {
    const char *strich = strchr(sensorname, '-');
    size_t len = (strich) ? (size_t)(strich - sensorname) : strlen(sensorname);
    if (len >= groesse) len = groesse - 1;
    strncpy(ziel, sensorname, len);
    ziel[len] = '\0';
}
```

```bash
Ausgabe:
Maximum (rekursiv):      22.40 C
Durchschnitt (rekursiv): 16.93 C
Binäre Suche (rekursiv) nach 16.3: Index 4

Sensornamen prüfen und normalisieren:
  'aussen-01' -> AUSSEN-01    | Standort: aussen
  'dach-02'   -> DACH-02      | Standort: dach
  'xy'        -> UNGÜLTIG
```

**Leitfrage:** *Zeichne den Aufruf-Stack von `maxRekursiv` für 4 Messwerte auf
Papier – wie viele Aufrufe stehen gleichzeitig auf dem Stack?*

---

## 2.6. Tag 6 – Strukturen und Enums

**Problem vom Vortag:** Zeit, Wert und Sensorname liegen in **getrennten Arrays**.
Ein Sortiervorgang müsste alle drei parallel umsortieren – fehleranfällig.

**Neue Konzepte:** `struct`, verschachtelte Struktur, `typedef`, `enum`

```c
typedef enum { SENSOR_TEMPERATUR, SENSOR_FEUCHTE, SENSOR_DRUCK } Sensortyp;
typedef enum { STATUS_OK, STATUS_WARNUNG, STATUS_FEHLER }        Messstatus;

typedef struct { int stunde; int minute; } Zeit;

typedef struct {
    Zeit       zeit;              /* verschachtelte Struktur */
    double     wert;
    Sensortyp  typ;
    Messstatus status;
    char       sensorname[20];
} Messpunkt;

/* Status wird bei der Erfassung automatisch bestimmt */
Messpunkt messpunktErstellen(int h, int m, double wert, Sensortyp typ, const char *name) {
    Messpunkt p;
    p.zeit.stunde = h;  p.zeit.minute = m;
    p.wert = wert;      p.typ = typ;
    strncpy(p.sensorname, name, sizeof(p.sensorname) - 1);
    p.sensorname[sizeof(p.sensorname) - 1] = '\0';
    if      (typ == SENSOR_TEMPERATUR && (wert < -20 || wert > 50)) p.status = STATUS_FEHLER;
    else if (typ == SENSOR_TEMPERATUR &&  wert > 30)                p.status = STATUS_WARNUNG;
    else                                                             p.status = STATUS_OK;
    return p;
}
```

```bash
Ausgabe:
  Zeit  | Sensortyp    |     Wert      | Status   | Name
  -------------------------------------------------------------
  08:00 | Temperatur   |    18.50 C    | OK       | Aussen-01
  12:00 | Temperatur   |    34.80 C    | WARNUNG  | Aussen-01
  12:30 | Feuchte      |    65.00 %    | OK       | Feucht-01
  13:00 | Temperatur   |    99.90 C    | FEHLER   | Defekt-01
  13:30 | Druck        |  1013.20 hPa  | OK       | Baro-01

  Status-Übersicht:  OK: 4 | WARNUNG: 1 | FEHLER: 1
```

**Leitfrage:** *Wie viele Arrays bräuchten wir ohne `struct` für dieselbe
Information? Was passiert beim Sortieren?*

---

## 2.7. Tag 7 – Verkettete Liste

**Problem vom Vortag:** `Messpunkt reihe[50]` – die Obergrenze steht fest im Code.
Bei 51 Messungen ist Schluss, bei 5 verschwenden wir Speicher.

**Neue Konzepte:** selbstreferenzierende Struktur, `malloc`/`free`, Listen-Traversierung

```c
typedef struct Knoten {
    Zeit   zeit;
    double wert;
    char   sensorname[20];
    struct Knoten *naechster;      /* zeigt auf sich selbst-Typ! */
} Knoten;

typedef struct { Knoten *kopf; int anzahl; } Messreihe;

int reiheAnhaengen(Messreihe *r, int h, int m, double wert, const char *name) {
    Knoten *neu = malloc(sizeof(Knoten));
    if (neu == NULL) return 0;
    /* ... Felder füllen ... */
    neu->naechster = NULL;
    if (r->kopf == NULL) r->kopf = neu;
    else { Knoten *p = r->kopf; while (p->naechster) p = p->naechster; p->naechster = neu; }
    r->anzahl++;
    return 1;
}

void reiheFreigeben(Messreihe *r) {
    Knoten *p = r->kopf;
    while (p) { Knoten *w = p->naechster; free(p); p = w; }
    r->kopf = NULL; r->anzahl = 0;
}
```

```bash
Ausgabe:
Messreihe (5 Einträge, KEINE feste Obergrenze!):
  08:00 |    18.50 C | Aussen-01
  ...
  Durchschnitt: 21.54 C
  Speicher freigegeben. Einträge: 0
```

> Mit AddressSanitizer geprüft: keine Speicherlecks.

**Leitfrage:** *Warum wird in `reiheFreigeben` der Nachfolger **vor** `free(p)`
zwischengespeichert?*

---

## 2.8. Tag 8 – Sortieren und Suchen

**Problem:** Die Messreihe liegt in Erfassungsreihenfolge vor. Für Auswertungen
brauchen wir sie nach Zeit, Wert oder Sensorname sortiert.

**Neue Konzepte:** `qsort`, Funktionszeiger, binäre Suche

```c
int cmpZeit(const void *a, const void *b) {
    return ((const Messpunkt*)a)->stunde - ((const Messpunkt*)b)->stunde;
}
int cmpWertAb(const void *a, const void *b) {
    const Messpunkt *x = a, *y = b;
    return (y->wert > x->wert) - (y->wert < x->wert);
}
int cmpName(const void *a, const void *b) {
    return strcmp(((const Messpunkt*)a)->sensorname,
                  ((const Messpunkt*)b)->sensorname);
}

/* EIN Sortierer – drei Reihenfolgen */
qsort(reihe, n, sizeof(Messpunkt), cmpZeit);
qsort(reihe, n, sizeof(Messpunkt), cmpWertAb);
qsort(reihe, n, sizeof(Messpunkt), cmpName);
```

```bash
Ausgabe (Auszug):
  Nach Zeit sortiert:        06:00 | 15.20 C | Keller-01  ...
  Binäre Suche nach 12:00 -> Index 3 (24.9 C)
  Nach Wert absteigend:      15:00 | 26.30 C | Dach-01    ...
  Nach Sensorname:           12:00 | 24.90 C | Aussen-01  ...
```

**Leitfrage:** *Wie viele Sortieralgorithmen mussten wir schreiben, um drei
Reihenfolgen zu erhalten?*

---

## 2.9. Tag 9 – Bitfelder, Datei-I/O und dynamischer Speicher

**Problem:** Beim Programmende sind alle Messwerte weg. Zudem verbrauchen die
Statusflags unnötig viel Speicher, und die Kapazität ist noch immer fest.

**Neue Konzepte:** Bitfelder, `malloc`/`realloc`, `fwrite`/`fread`, CSV-Export

```c
/* 8 Flags in 4 Byte statt 8 int (32 Byte) */
typedef struct {
    unsigned int kalibriert      : 1;
    unsigned int grenzwert       : 1;
    unsigned int sensorfehler    : 1;
    unsigned int batterieSchwach : 1;
    unsigned int reserve         : 4;
} Statusflags;

/* Dynamisches Array mit Verdopplungsstrategie */
int reiheHinzufuegen(Messreihe *r, int h, double wert, const char *name) {
    if (r->anzahl == r->kapazitaet) {
        int neueKap = r->kapazitaet * 2;
        Messpunkt *neu = realloc(r->daten, neueKap * sizeof(Messpunkt));
        if (neu == NULL) return 0;        /* Original bleibt gültig! */
        r->daten = neu; r->kapazitaet = neueKap;
    }
    /* ... */
}
```

```bash
Ausgabe:
sizeof(Statusflags) = 4 Byte (8 einzelne int wären 32 Byte)

Messwerte erfassen (Start-Kapazität 2):
  [Kapazität erweitert auf 4]
  [Kapazität erweitert auf 8]
  -> 5 Messwerte, Kapazität 8

Binär speichern...  5 Datensätze
CSV exportieren...   5 Datensätze

Array leeren (Beweis: Daten kommen aus Datei)...
  -> 0 Messwerte im Speicher
Aus Binärdatei laden... 5 Datensätze     ← alle Werte wieder da!
```

> ✅ Mit AddressSanitizer geprüft: keine Speicherlecks.

**Leitfrage:** *Warum wird das Array vor dem Laden absichtlich geleert?*

---

## 2.10. Tag 10 – Grafische Oberfläche mit WPF

**Problem:** Die Konsolenausgabe ist für Anwender unhandlich.

**Neue Konzepte:** XAML, Code-Behind, Eventhandler, `ListBox`, Datenbindung

**Vorschlag für die Oberfläche:**

```xml
<Grid Margin="20">
    <Grid.RowDefinitions>
        <RowDefinition Height="Auto"/>
        <RowDefinition Height="*"/>
        <RowDefinition Height="Auto"/>
    </Grid.RowDefinitions>

    <StackPanel Grid.Row="0" Orientation="Horizontal">
        <Label Content="Sensor:"/>
        <TextBox x:Name="SensorTextBox" Width="120"/>
        <Label Content="Wert (°C):"/>
        <TextBox x:Name="WertTextBox" Width="80"/>
        <Button x:Name="ErfassenButton" Content="Erfassen"
                Click="ErfassenButton_Click" Margin="10,0,0,0"/>
    </StackPanel>

    <ListBox Grid.Row="1" x:Name="MesswerteListBox" Margin="0,10,0,10"/>

    <StackPanel Grid.Row="2">
        <Label x:Name="StatistikLabel" FontWeight="Bold"/>
        <Button x:Name="SortierenButton" Content="Nach Wert sortieren"
                Click="SortierenButton_Click" Width="160" HorizontalAlignment="Left"/>
    </StackPanel>
</Grid>
```

```csharp
private List<Messpunkt> messreihe = new List<Messpunkt>();

private void ErfassenButton_Click(object sender, RoutedEventArgs e)
{
    if (!double.TryParse(WertTextBox.Text, out double wert))
    {
        StatistikLabel.Content = "Ungültiger Messwert!";
        return;
    }
    messreihe.Add(new Messpunkt(SensorTextBox.Text, wert));
    MesswerteListBox.Items.Add($"{SensorTextBox.Text}: {wert:F1} °C");
    StatistikAktualisieren();
}
```

**Leitfrage:** *Die Logik ist identisch zu Tag 6 – was hat sich wirklich
geändert, und was nicht?*

---

## 2.11. Tag 11 – Objektorientierung in C++

**Problem:** Die Daten (`Messpunkt`) und die Funktionen, die damit arbeiten,
liegen getrennt. Jeder kann `wert` direkt verändern – auch mit unsinnigen Werten.

**Neue Konzepte:** Klasse, Kapselung, Konstruktor, Vererbung

```cpp
// Messpunkt.h
#ifndef MESSPUNKT_H
#define MESSPUNKT_H
#include <string>

class Messpunkt {
private:
    std::string sensorname;    // privat: kein direkter Zugriff mehr!
    double      wert;
    int         stunde;

public:
    Messpunkt(std::string name, double w, int h);

    double      wertAbfragen() const;
    std::string nameAbfragen() const;
    bool        istGrenzwertUeberschritten() const;
    void        anzeigen() const;
};
#endif
```

```cpp
// Messpunkt.cpp – Konstruktor validiert die Eingabe
Messpunkt::Messpunkt(std::string name, double w, int h) {
    sensorname = name;
    wert       = (w > -50.0 && w < 100.0) ? w : 0.0;   // ungültige Werte abgefangen
    stunde     = (h >= 0 && h <= 23) ? h : 0;
}
```

**Vererbungsvorschlag:**

```bash
      Messpunkt (Basisklasse)
      ├── TemperaturMesspunkt   (Grenzwert 30 °C, Einheit °C)
      ├── FeuchteMesspunkt      (Grenzwert 80 %,  Einheit %)
      └── DruckMesspunkt        (Grenzwert 1030 hPa, Einheit hPa)
```

**Leitfrage:** *Vergleiche `Messpunkt` in C (Tag 6) und C++ (Tag 11) –
welches Problem löst `private`, das in C offen blieb?*

---

</br>

# 3. Einsatz im Unterricht

## Ablauf pro Tag (Variante «Standard»)

```bash
1. Rückblick (3 min)
   "Wo standen wir gestern? Welches Problem ist offen geblieben?"

2. Theorieblock wie bisher (unverändert)

3. Projekt-Ausbaustufe (15–20 min)
   Studierende erhalten den Stand vom Vortag und erweitern ihn
   → Vorlage in x_projekt/tagXX/

4. Kurze Auswertung (5 min)
   Leitfrage der Stufe gemeinsam beantworten
```

## Verknüpfung mit der Praxisarbeit (Tag 7)

Der Projektstand von Tag 7 (verkettete Liste, Struktur, Modularisierung) eignet
sich unmittelbar als **Ausgangspunkt für die Praxisarbeit**: Die Studierenden
kennen den Code bereits, haben ihn selbst mitentwickelt und können ihn in eine
eigene Richtung weiterführen (anderer Sensortyp, andere Auswertung, andere
Ausgabeform).

## Mögliche Erweiterungen für schnelle Gruppen

| **Tag** | **Zusatzaufgabe**                                               |
| ------- | --------------------------------------------------------------- |
| 3       | Gleitender Durchschnitt über 3 Stunden berechnen                |
| 5       | Sensornamen rekursiv umkehren (in-place)                        |
| 6       | Weiteren Sensortyp (`SENSOR_WIND`) mit eigener Einheit ergänzen |
| 7       | Messpunkt aus der Liste **löschen** (Lücke schliessen!)         |
| 8       | Median berechnen (setzt Sortierung voraus)                      |
| 9       | Prüfsumme über alle Werte in der Binärdatei ablegen             |
| 10      | Messwerte in der GUI als einfaches Balkendiagramm anzeigen      |

---

© 2026 Lukas Müller – Licensed under CC BY-NC-ND 4.0
See [LICENSE](../license.md) file for details.
