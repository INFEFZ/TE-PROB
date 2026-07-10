|                             |                          |                               |
| --------------------------- | ------------------------ | ----------------------------- |
| **Elektrotechniker/-in HF** | **Programmiertechnik B** | ![logo](../x_gitres/logo.png) |

</br>

# Gruppenarbeit Dynamische Speicherverwaltung

| **Vorgabe**         | **Beschreibung**                                                                                                                 |
| :------------------ | :------------------------------------------------------------------------------------------------------------------------------- |
| **Lernziele**       | Kennst die Lebensdauer von Variablen und ihre Speicherklassen                                                                    |
|                     | Kennst die Speichersegmente eines laufenden Programms                                                                            |
|                     | Kannst Speicher mit malloc()/free() sicher verwalten und erkennst typische Fehler wie Memory Leaks, bevor sie zum Problem werden |
|                     | Bestehende Speicherblöcke mit realloc() vergrössern und dabei die NULL-Falle vermeiden                                           |
| **Sozialform**      | Gruppenarbeit: 2-3 Personen                                                                                                      |
| **Auftrag**         | siehe unten                                                                                                                      |
| **Hilfsmittel**     |                                                                                                                                  |
| **Zeitbedarf**      | 60min                                                                                                                            |
| **Lösungselemente** | Abgabe: Alle Dateien (.h und .c) als Gesamtprojekt                                                                               |
|                     | Funktionierendes Programm und Präsentation (Code erklären), ca. 5 min.                                                           |
|                     | Jedes Gruppenmitglied muss Teile des Codes erklären können                                                                       |

> ## Hinweis zum KI-Einsatz
>
> `malloc`/`free`-Code lässt sich leicht generieren – aber Speicherfehler zeigen
> sich oft erst beim genauen Hinsehen, nicht beim ersten Blick auf den Code.
> In der Präsentation wird jedes Mitglied einzeln gefragt:
>
> - *„Zeig mir genau die Stelle, wo dieser Speicherblock wieder freigegeben wird."*
> - *„Was passiert, wenn ich diese Zeile entferne – kompiliert es noch? Läuft es noch? Ist es noch korrekt?"*
> - *„Male den Stack und den Heap für diesen Programmabschnitt auf Papier."*
> - *„Führt euer Programm mit valgrind --leak-check=full aus – was zeigt der Report?"*
> - *„Was wäre hier ein Use-After-Free-Fehler – baut ihn absichtlich ein und zeigt was passiert."*
>
> Ein Programm, das "einfach funktioniert", ist bei diesem Thema kein Beweis für
> Korrektheit – Speicherfehler zeigen sich oft nicht zuverlässig bei jedem Lauf.
> Der Valgrind-Report ist der eigentliche Prüfstein.

---

</br>

## Gruppenarbeit A – «Dynamische Matrix-Bibliothek»

**Szenario:** Ihr entwickelt eine Bibliothek für Matrizen **beliebiger Grösse** (zur Laufzeit bestimmt) – im Gegensatz zur festen `#define N 3`-Lösung aus der Arrays-Lektion. Dafür müsst ihr eine 2D-Struktur komplett dynamisch mit `malloc()` aufbauen.

**Anforderungen:**

```c
typedef struct {
    int zeilen;
    int spalten;
    int **daten;     // Zeiger auf Zeiger - dynamisches 2D-Array!
} Matrix;

// Erzeugt eine Matrix mit dynamisch allokiertem Speicher, alle Werte auf 0
Matrix matrixErstellen(int zeilen, int spalten);

// Gibt den GESAMTEN Speicher einer Matrix korrekt frei
void matrixFreigeben(Matrix *m);

// Setzt/liest einen Wert an Position [zeile][spalte]
void matrixSetzen(Matrix *m, int zeile, int spalte, int wert);
int  matrixLesen(Matrix *m, int zeile, int spalte);

// Gibt die Matrix formatiert aus
void matrixAnzeigen(Matrix *m);

// Addiert zwei gleich grosse Matrizen, gibt eine NEUE (dynamisch allokierte) Matrix zurueck
Matrix matrixAddieren(Matrix *a, Matrix *b);
```

**Wichtiger Hinweis – dynamisches 2D-Array korrekt aufbauen:**

```c
Matrix matrixErstellen(int zeilen, int spalten) {
    Matrix m;
    m.zeilen = zeilen;
    m.spalten = spalten;

    m.daten = malloc(zeilen * sizeof(int*));   // Array von ZEIGERN (eine pro Zeile)

    for (int i = 0; i < zeilen; i++) {
        m.daten[i] = malloc(spalten * sizeof(int));   // jede Zeile EINZELN allokieren

        for (int j = 0; j < spalten; j++) {
            m.daten[i][j] = 0;
        }
    }

    return m;
}
```

> **Die Schwierigkeit dieser Aufgabe:** Da jede Zeile **einzeln** allokiert wurde,
> muss `matrixFreigeben` auch **jede Zeile einzeln** mit `free()` freigeben – **vor**
> dem Freigeben des äusseren Zeiger-Arrays! Die Reihenfolge ist entscheidend.

**Aufgabenstellung:**

**Schritt 1:** Implementiert alle Funktionen.

**Schritt 2:** Testet mit zwei 3×3-Matrizen, addiert sie, gebt das Ergebnis aus.

**Schritt 3 – Pflicht: Valgrind-Test:**

```bash
gcc -g main.c -o matrix
valgrind --leak-check=full ./matrix
```

Dokumentiert den Valgrind-Report. Ein korrektes Programm zeigt:

```console
HEAP SUMMARY:
    in use at exit: 0 bytes in 0 blocks
All heap blocks were freed -- no leaks are possible
```

**Schritt 4 – Fehler absichtlich provozieren (für die Präsentation):**
Erstellt eine **zweite Version** eurer `matrixFreigeben`-Funktion, die **absichtlich**
nur das äussere Array freigibt, nicht die einzelnen Zeilen. Führt Valgrind erneut
aus und vergleicht den Report.

**Pflichtanforderungen:**

- [ ] Korrektes dynamisches 2D-Array (`int**`) mit verschachtelter Allokation
- [ ] `matrixFreigeben` gibt **jede Zeile einzeln** frei, dann das äussere Array
- [ ] `matrixAddieren` erzeugt eine **neue** Matrix (keine Veränderung der Originale)
- [ ] Valgrind-Report zeigt **0 Bytes in 0 Blocks** für die korrekte Version
- [ ] Absichtlich fehlerhafte Version erstellt und deren Valgrind-Report dokumentiert
- [ ] Jeder `malloc`-Aufruf wird auf `NULL` geprüft

**Präsentationsfragen:**

1. Erklärt `int **daten` – was genau bedeutet der doppelte Zeiger hier? Zeichnet die Struktur (Zeiger auf Zeiger auf Werte) am Whiteboard.
2. Warum muss `matrixFreigeben` die Zeilen **vor** dem äusseren Array freigeben? Was würde bei der umgekehrten Reihenfolge passieren?
3. Zeigt den Valgrind-Report der korrekten **und** der absichtlich fehlerhaften Version – was genau zeigt der Unterschied?
4. `matrixAddieren` gibt eine neue Matrix zurück – wer ist dafür verantwortlich, diese später wieder freizugeben? Wo im Code passiert das in eurem `main()`?
5. Was würde passieren, wenn ihr `matrixFreigeben` zweimal auf dieselbe Matrix anwendet? Probiert es (in einer Kopie eures Codes) aus.

---

</br>

## Gruppenarbeit B – «Verkettete Liste als Stapelspeicher»

**Szenario:** Ihr implementiert eine einfache **verkettete Liste** (*Linked List*) als Stapel (*Stack*, LIFO – *Last In, First Out*) – eine fundamentale Datenstruktur, die komplett auf dynamischer
speicherallokation basiert, im Gegensatz zu den festen Arrays, die wir bisher verwendet haben.

**Anforderungen:**

```c
typedef struct Knoten {
    int wert;
    struct Knoten *naechster;   // Zeiger auf den naechsten Knoten - oder NULL
} Knoten;

typedef struct {
    Knoten *kopf;      // zeigt auf das oberste Element des Stapels
    int     anzahl;
} Stapel;

void  stapelInitialisieren(Stapel *s);
void  stapelPush(Stapel *s, int wert);     // legt einen Wert OBEN auf den Stapel
int   stapelPop(Stapel *s, int *erfolg);   // entfernt UND gibt das oberste Element zurueck
int   stapelPeek(Stapel *s, int *erfolg);  // liest das oberste Element OHNE zu entfernen
int   stapelIstLeer(Stapel *s);
void  stapelAnzeigen(Stapel *s);
void  stapelKomplettFreigeben(Stapel *s);  // gibt ALLE Knoten frei
```

**Wichtiger Hinweis – `push` und `pop`:**

```c
void stapelPush(Stapel *s, int wert) {
    Knoten *neu = malloc(sizeof(Knoten));   // EIN Knoten = EIN malloc

    if (neu == NULL) {
        printf("Fehler: Speicher voll!\n");
        return;
    }

    neu->wert = wert;
    neu->naechster = s->kopf;   // neuer Knoten zeigt auf den BISHERIGEN Kopf
    s->kopf = neu;                // der neue Knoten wird der NEUE Kopf
    s->anzahl++;
}

int stapelPop(Stapel *s, int *erfolg) {
    if (stapelIstLeer(s)) {
        *erfolg = 0;
        return -1;
    }

    Knoten *alterKopf = s->kopf;
    int wert = alterKopf->wert;

    s->kopf = alterKopf->naechster;   // Kopf zeigt jetzt auf den naechsten Knoten
    free(alterKopf);                    // der ALTE Kopf wird freigegeben!
    s->anzahl--;

    *erfolg = 1;
    return wert;
}
```

> 💡 **Warum `int *erfolg` als Parameter?** Da `-1` ein gültiger Wert im Stapel
> sein könnte, reicht der Rückgabewert allein nicht aus, um „leer" von „Wert ist
> tatsächlich -1" zu unterscheiden – daher ein zusätzlicher Erfolgsindikator
> über Pointer (Call by Pointer, bekannt aus der Funktionen-Lektion!).

**Aufgabenstellung:**

**Schritt 1:** Implementiert alle Funktionen.

**Schritt 2:** Testet in `main()`:

1. Mehrere Werte pushen (z.B. 10, 20, 30, 40)
2. Anzeigen (muss in umgekehrter Reihenfolge der Eingabe erscheinen: 40, 30, 20, 10)
3. Zweimal `pop()` aufrufen, Ergebnis ausgeben
4. Erneut anzeigen
5. **Alles** poppen, bis der Stapel leer ist (Schleife mit `stapelIstLeer`)
6. Versuchen, aus dem leeren Stapel zu poppen – Fehlerbehandlung über `erfolg` zeigen

**Schritt 3 – Pflicht: Valgrind-Test:**

```bash
gcc -g main.c -o stapel
valgrind --leak-check=full ./stapel
```

**Schritt 4:** Testet **bewusst** den Fall, dass `stapelKomplettFreigeben` **nicht**
aufgerufen wird, bevor das Programm endet (z.B. testweise auskommentiert) – was
zeigt Valgrind dann?

### Erwartete Ausgabe (Beispiel)

```console
Stapel nach 4x push (10,20,30,40): [40, 30, 20, 10]  (Anzahl: 4)
Pop: 40 (Erfolg: 1)
Pop: 30 (Erfolg: 1)
Stapel jetzt: [20, 10]  (Anzahl: 2)

Stapel komplett leeren...
Pop: 20 (Erfolg: 1)
Pop: 10 (Erfolg: 1)
Pop aus leerem Stapel: Erfolg: 0
```

**Pflichtanforderungen:**

- [ ] `push`/`pop` korrekt implementiert (LIFO-Prinzip: zuletzt hinein, zuerst heraus)
- [ ] `pop` aus leerem Stapel verursacht **keinen** Absturz, sondern meldet `erfolg = 0`
- [ ] `stapelKomplettFreigeben` durchläuft **alle** Knoten und gibt jeden einzeln frei
- [ ] Jeder `malloc`-Aufruf wird auf `NULL` geprüft
- [ ] Valgrind-Report zeigt keine Leaks bei korrekter Verwendung
- [ ] Dokumentiert, was Valgrind zeigt, wenn `stapelKomplettFreigeben` **fehlt**

**Präsentationsfragen:**

1. Zeichnet die verkettete Liste nach 3 `push`-Aufrufen am Whiteboard – Pfeile zwischen den Knoten, inklusive `NULL` am Ende.
2. Erklärt Zeile für Zeile, was in `stapelPop` passiert, **bevor** `free(alterKopf)` aufgerufen wird – warum muss der Wert **vorher** ausgelesen werden?
3. Was würde passieren, wenn ihr in `stapelPop` die Reihenfolge ändert – also **erst** `free(alterKopf)` und **danach** versucht, `alterKopf->wert` zu lesen? Probiert es (in einer Kopie) aus.
4. Zeigt den Valgrind-Report mit **und ohne** `stapelKomplettFreigeben` am Ende von `main()` – was genau ist der Unterschied im Report?
5. Warum verwendet ihr `int *erfolg` statt einfach `-1` als „Fehlercode" zurückzugeben?

---

</br>

## Gruppenarbeit C – «Dynamisches Array mit automatischem Wachstum»

**Szenario:** Standard-Arrays in C haben eine feste Grösse. Ihr implementiert ein **dynamisches Array** (ähnlich einem vereinfachten `std::vector` aus C++ oder `ArrayList` aus
Java), das bei Bedarf automatisch wächst – mit `realloc()`.

**Anforderungen:**

```c
typedef struct {
    int *daten;
    int  anzahl;       // wie viele Elemente aktuell GENUTZT werden
    int  kapazitaet;    // wie viel Speicher aktuell RESERVIERT ist
} DynArray;

void  dynArrayInitialisieren(DynArray *arr, int startKapazitaet);
void  dynArrayHinzufuegen(DynArray *arr, int wert);   // fuegt hinzu, waechst bei Bedarf!
int   dynArrayLesen(DynArray *arr, int index);
void  dynArrayEntfernenLetztes(DynArray *arr);
void  dynArrayAnzeigen(DynArray *arr);
void  dynArrayFreigeben(DynArray *arr);
```

**Wichtiger Hinweis – das Wachstumsprinzip mit `realloc`:**

```c
void dynArrayHinzufuegen(DynArray *arr, int wert) {
    if (arr->anzahl == arr->kapazitaet) {
        // Array ist voll - Kapazitaet VERDOPPELN
        int neueKapazitaet = arr->kapazitaet * 2;
        int *neuerSpeicher = realloc(arr->daten, neueKapazitaet * sizeof(int));

        if (neuerSpeicher == NULL) {
            printf("Fehler: Speicher konnte nicht erweitert werden!\n");
            return;
        }

        arr->daten = neuerSpeicher;
        arr->kapazitaet = neueKapazitaet;

        printf("[Kapazitaet erweitert auf %d]\n", neueKapazitaet);  // zur Beobachtung!
    }

    arr->daten[arr->anzahl] = wert;
    arr->anzahl++;
}
```

> **Warum verdoppeln statt um 1 erhöhen?** Würde man die Kapazität bei
> jedem `hinzufuegen` nur um 1 erhöhen, müsste `realloc()` **bei jedem einzelnen
> Element** den gesamten Speicher neu verschieben – das wäre extrem ineffizient.
> Verdoppeln sorgt dafür, dass `realloc()` nur **selten** aufgerufen wird
> (logarithmisch oft statt linear oft).

**Aufgabenstellung:**

**Schritt 1:** Implementiert alle Funktionen. Startet mit einer kleinen
Anfangskapazität (z.B. 2), damit das Wachstum mehrfach sichtbar wird.

**Schritt 2:** Testet, indem ihr **20 Werte** hinzufügt und bei jedem
Kapazitätssprung die Meldung beobachtet.

**Schritt 3 – Wachstumsprotokoll dokumentieren:**

```console
Erwartetes Wachstumsmuster bei Startkapazitaet=2:
[Kapazitaet erweitert auf 4]
[Kapazitaet erweitert auf 8]
[Kapazitaet erweitert auf 16]
[Kapazitaet erweitert auf 32]

Notiert: Wie oft wurde "erweitert" bei 20 hinzugefuegten Werten ausgegeben?
```

**Schritt 4 – Pflicht: Valgrind-Test:**

```bash
gcc -g main.c -o dynarray
valgrind --leak-check=full ./dynarray
```

> **Wichtige Falle bei `realloc`:** Wird der Rückgabewert von `realloc()`
> **derselben** Variable zugewiesen, die man auch als Eingabe übergeben hat
> (`arr->daten = realloc(arr->daten, ...)`), und `realloc()` schlägt fehl
> (gibt `NULL` zurück), geht der **ursprüngliche** Zeiger verloren – ein
> garantierter Memory Leak! Deshalb verwendet der Beispielcode bewusst eine
> **separate** Zwischenvariable (`neuerSpeicher`).

**Pflichtanforderungen:**

- [ ] `dynArrayHinzufuegen` verdoppelt die Kapazität korrekt bei Bedarf
- [ ] `realloc`-Rückgabewert wird in eine **separate** Variable geschrieben, nicht direkt überschrieben (siehe Warnhinweis)
- [ ] `dynArrayLesen` prüft den Index auf Gültigkeit (`0 <= index < anzahl`)
- [ ] `dynArrayEntfernenLetztes` funktioniert korrekt, auch bei leerem Array (keine Unterlauf-Fehler)
- [ ] Wachstumsprotokoll mit 20 Werten dokumentiert
- [ ] Valgrind-Report zeigt keine Leaks

**Präsentationsfragen:**

1. Erklärt, warum die Kapazität **verdoppelt** statt nur **um 1 erhöht** wird – was wäre der Performance-Nachteil bei der zweiten Variante?
2. Zeigt die Stelle im Code, die das `realloc`-Fehlerszenario (`NULL`-Rückgabe) sicher behandelt – warum ist eine separate Variable hier wichtig?
3. Wie oft wurde bei euren 20 Werten tatsächlich neu alloziert? Stimmt das mit eurer Erwartung überein?
4. Was passiert, wenn man versucht, `dynArrayLesen` mit einem Index ausserhalb der gültigen Grenzen aufzurufen? Zeigt die Fehlerbehandlung live.
5. Baut **live** eine Funktion `dynArraySchrumpfen` ein, die die Kapazität mit `realloc` wieder verkleinert, wenn `anzahl` deutlich kleiner als `kapazitaet` ist.

---

</br>

## Gruppenarbeit D – «Speicherfehler-Detektive»

**Szenario:** Ihr erhaltet sechs kleine C-Programme, die jeweils **einen** klassischen Speicherfehler enthalten (Memory Leak, Use-After-Free, Double-Free, Dangling-Pointer, fehlerhafte `sizeof`-Verwendung, fehlende NULL-Prüfung).
Eure Aufgabe: jeden Fehler identifizieren, erklären, korrigieren – und **experimentell mit Valgrind beweisen**, dass der Fehler vorher vorhanden und nachher behoben ist.

**Die sechs Codeschnipsel:**

**Schnipsel 1:**

```c
void funktion1(void) {
    int *p = malloc(100 * sizeof(int));
    p[0] = 42;
    printf("%d\n", p[0]);
}
```

**Schnipsel 2:**

```c
void funktion2(void) {
    int *p = malloc(sizeof(int));
    *p = 10;
    free(p);
    printf("%d\n", *p);
}
```

**Schnipsel 3:**

```c
void funktion3(void) {
    int *p = malloc(sizeof(int));
    *p = 10;
    free(p);
    free(p);
}
```

**Schnipsel 4:**

```c
int *funktion4(void) {
    int lokal = 99;
    return &lokal;
}

void verwende4(void) {
    int *p = funktion4();
    printf("%d\n", *p);
}
```

**Schnipsel 5:**

```c
void funktion5(int anzahl) {
    int *p = malloc(anzahl);   // fehlt: * sizeof(int) !
    for (int i = 0; i < anzahl; i++) {
        p[i] = i;   // schreibt ueber die reservierte Groesse hinaus!
    }
    free(p);
}
```

**Schnipsel 6:**

```c
void funktion6(void) {
    int *p = malloc(1000000000000 * sizeof(int));   // absurd grosse Anforderung
    p[0] = 1;   // p koennte NULL sein - keine Pruefung!
    free(p);
}
```

**Aufgabenstellung:**

**Schritt 1 – Analyse (15 min):**

Füllt für jedes Schnipsel folgende Tabelle:

| #   | Fehlertyp | Was genau ist falsch? | Mögliche Konsequenz |
| --- | --------- | --------------------- | ------------------- |
| 1   |           |                       |                     |
| 2   |           |                       |                     |
| 3   |           |                       |                     |
| 4   |           |                       |                     |
| 5   |           |                       |                     |
| 6   |           |                       |                     |

**Schritt 2 – Korrektur:**

Schreibt für jedes Schnipsel eine **korrigierte Version**.

**Schritt 3 – Experimenteller Beweis mit Valgrind:**

Für **mindestens 3** der 6 Schnipsel:

1. Kompiliert die **fehlerhafte** Version separat (`gcc -g schnipselX.c -o fehlerhaft`)
2. Führt `valgrind --leak-check=full ./fehlerhaft` aus, kopiert die relevante Ausgabe
3. Kompiliert die **korrigierte** Version
4. Führt Valgrind erneut aus, vergleicht die Reports

> **Hinweis:** Nicht jeder Fehler wird von Valgrind gleich deutlich angezeigt
> (z.B. Schnipsel 4 – Dangling Pointer auf Stack-Speicher – zeigt sich oft
> *nicht* als klassischer Valgrind-Fehler, kann aber mit `-fsanitize=address`
> beim Kompilieren sichtbar gemacht werden: `gcc -g -fsanitize=address schnipsel4.c -o schnipsel4`).

**Pflichtanforderungen:**

- [ ] Alle 6 Fehlertypen korrekt identifiziert und in der Tabelle benannt
- [ ] Alle 6 Schnipsel korrigiert (kompilierbar und korrekt)
- [ ] Mindestens 3 Valgrind-Vergleiche (fehlerhaft vs. korrigiert) durchgeführt und dokumentiert
- [ ] Für Schnipsel 4: Erklärung, warum dieser Fehler bei Valgrind eventuell **nicht** auffällt, obwohl er real ist

**Präsentationsfragen:**

1. Präsentiert Schnipsel 2 und 3 nebeneinander – was ist der Unterschied zwischen Use-After-Free und Double-Free? Zeigt jeweils den Valgrind-Report.
2. Schnipsel 5 – was genau passiert, wenn `* sizeof(int)` fehlt? Rechnet konkret nach: wie viele Bytes werden reserviert vs. wie viele tatsächlich benötigt, bei `anzahl = 10`?
3. Schnipsel 6 – warum ist die fehlende `NULL`-Prüfung hier besonders gefährlich? Was passiert beim Ausführen?
4. Schnipsel 4 – erklärt, warum dieser Fehler trotzdem "funktionieren" kann, wenn man Glück hat – und warum man sich darauf niemals verlassen darf.
5. Welcher der sechs Fehler war für euch am schwierigsten zu erkennen? Was hat euch schliesslich auf die richtige Spur gebracht?

---

© 2026 Lukas Müller – Licensed under CC BY-NC-ND 4.0
See [LICENSE](..\license.md) file for details.
