|                             |                          |                               |
| --------------------------- | ------------------------ | ----------------------------- |
| **Elektrotechniker/-in HF** | **Programmiertechnik B** | ![logo](../x_gitres/logo.png) |

</br>

# 1. Gruppenarbeit Such- und Sortieralgorithmen

| **Vorgabe**         | **Beschreibung**                                                                                       |
| :------------------ | :----------------------------------------------------------------------------------------------------- |
| **Lernziele**       | Die Funktionsweise von Bubblesort, Selectionsort und Insertionsort erklären und implementieren         |
|                     | Die Funktionsweise von Mergesort, Quicksort und Heapsort erklären und implementieren                   |
|                     | Die Zeitkomplexität (O-Notation) der behandelten Algorithmen benennen und vergleichen                  |
|                     | Den Begriff „Stabilität" eines Sortieralgorithmus erklären und für die behandelten Algorithmen angeben |
| **Sozialform**      | Gruppenarbeit: 2-3 Personen                                                                            |
| **Auftrag**         | siehe unten                                                                                            |
| **Hilfsmittel**     |                                                                                                        |
| **Zeitbedarf**      | 60min                                                                                                  |
| **Lösungselemente** | Abgabe: Alle Dateien (.h und .c) als Gesamtprojekt                                                     |
|                     | Funktionierendes Programm und Präsentation (Code erklären), ca. 5 min.                                 |
|                     | Jedes Gruppenmitglied muss Teile des Codes erklären können                                             |

> **Hinweis zum KI-Einsatz**
> Sortieralgorithmen lassen sich von KI in Sekunden erzeugen – das macht diese Aufgaben **nicht** überflüssig, sondern wichtiger.
> In der Präsentation wird jedes Mitglied einzeln gefragt:
>
> - *„Zeigen Sie an diesem Array von Hand, was im ersten Durchlauf passiert."*
> - *„Warum steht hier `<=` und nicht `<`? Was würde sich ändern?"*
> - *„Wie viele Vergleiche braucht dein Algorithmus bei diesem Array ungefähr?"*
> - *„Was passiert, wenn das Array bereits sortiert ist – läuft dein Code schneller?"*
> - *„Baue das Array `[X]` von Hand nach – zeig mir Schritt 2."*
>
> Wer den Algorithmus nicht **mit der Hand auf Papier** durchspielen kann, hat ihn nicht verstanden – egal wie korrekt der Code ist.

---

## Gruppenarbeit A – «Sortier-Wettkampf: Drei Algorithmen im Vergleich»

**Szenario:**

- Ihr seid ein Algorithmen-Testteam.
- Eure Aufgabe: Bubblesort, Selectionsort und Insertionsort implementieren, ihre Effizienz **messen** und die Ergebnisse interpretieren.

**Anforderungen:**

**Zu implementierende Funktionen:**

```c
void bubblesort(int arr[], int n);
void selectionsort(int arr[], int n);
void insertionsort(int arr[], int n);

// Hilfsfunktionen
void arrayKopieren(int quelle[], int ziel[], int n);
int  istSortiert(int arr[], int n);
void zeigeArray(int arr[], int n);

// Für die Messung
int zaehleVergleicheBubblesort(int arr[], int n);     // zählt nur, sortiert nicht!
int zaehleVergleicheSelectionsort(int arr[], int n);
int zaehleVergleicheInsertionsort(int arr[], int n);
```

**Testdaten – drei verschiedene Szenarien:**

```c
int zufaelligesArray[15] = {23, 4, 67, 12, 89, 5, 34, 78, 1, 56, 90, 21, 8, 45, 33};
int sortiertesArray[15]  = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
int umgekehrtesArray[15] = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
```

**Aufgabenstellung:**

**Schritt 1 – Implementierung (20 min):**
Implementiert alle drei Sortieralgorithmen sowie Zählvarianten, die **nicht sortieren**, sondern nur die Anzahl Vergleiche zurückgeben (Array muss dafür kopiert werden, damit das Original für die anderen Tests unverändert bleibt!).

**Schritt 2 – Messung (15 min):**
Führt für jedes der drei Arrays (zufällig, sortiert, umgekehrt) alle drei Algorithmen aus und zählt die Vergleiche. Füllt folgende Tabelle:

**Vergleichsanzahl:**

```console
| Bubblesort         | Selectionsort | Insertionsort |
| ------------------ | ------------- | ------------- |
| Zufällig           |               |               |
| Bereits sortiert   |               |               |
| Umgekehrt sortiert |               |               |
```

**Schritt 3 – Interpretation (10 min, schriftlich festhalten):**

- Welcher Algorithmus profitiert am meisten von einem bereits sortierten Array? Warum?
- Welcher Algorithmus zeigt bei allen drei Szenarien etwa gleich viele Vergleiche? Warum?
- Bestätigen eure Messwerte die theoretische Komplexität `O(n²)`?

**Erwartete Ausgabe (Beispiel):**

```console
=== Sortier-Wettkampf (n=15) ===

Array: Zufällig
  Bubblesort:    98 Vergleiche
  Selectionsort: 105 Vergleiche
  Insertionsort: 76 Vergleiche

Array: Bereits sortiert
  Bubblesort:    14 Vergleiche   ← deutlich weniger!
  Selectionsort: 105 Vergleiche  ← unverändert!
  Insertionsort: 14 Vergleiche   ← deutlich weniger!

Array: Umgekehrt sortiert
  Bubblesort:    105 Vergleiche
  Selectionsort: 105 Vergleiche
  Insertionsort: 105 Vergleiche
```

**Pflichtanforderungen:**

- [ ] Alle drei Sortieralgorithmen korrekt implementiert
- [ ] Zählvarianten verändern das Original-Array **nicht** (Kopie verwenden!)
- [ ] Alle 9 Messwerte (3 Arrays × 3 Algorithmen) korrekt erfasst
- [ ] Schriftliche Interpretation der Ergebnisse
- [ ] `istSortiert()` nutzen, um die Korrektheit der Sortierfunktionen zu verifizieren

**Präsentationsfragen:**

1. Führt `bubblesort` von Hand für die ersten zwei Durchläufe an `umgekehrtesArray` (nur die ersten 5 Elemente) vor – auf Papier oder am Whiteboard.
2. Warum bleibt die Vergleichsanzahl von Selectionsort bei allen drei Szenarien (fast) identisch? Erklärt das anhand des Codes.
3. Zeigt die Zeile in eurem Code, die bei Insertionsort für den Geschwindigkeitsvorteil bei sortierten Arrays sorgt.
4. Was müsstet ihr ändern, wenn ihr auch Mergesort in den Vergleich aufnehmen wolltet? Wäre eine reine Vergleichszählung dort genauso sinnvoll?

---

</br>

## Gruppenarbeit B – «Mergesort für Studierendendaten»

**Szenario:**

- Eine Hochschule möchte Studierendendaten nach verschiedenen Kriterien sortieren.
- Ihr implementiert Mergesort für ein Array von Structs – nicht nur für einfache Zahlen.

**Vorgegebene Datenstruktur:**

```c
typedef struct {
    char name[30];
    int  matrikelnummer;
    double durchschnittsnote;
} Student;

Student studenten[8] = {
    {"Meier Anna",    1023, 5.2},
    {"Huber Tom",     1045, 4.1},
    {"Keller Sara",   1012, 5.8},
    {"Weber Max",     1067, 3.9},
    {"Fischer Lea",   1034, 4.7},
    {"Brunner Jan",   1089, 5.0},
    {"Steiner Mia",   1056, 4.4},
    {"Wyss Noah",     1003, 5.5}
};
```

**Anforderungen:**

```c
// Mergesort, sortiert NACH DURCHSCHNITTSNOTE (absteigend, beste zuerst)
void mergesortNoten(Student arr[], int links, int rechts);
void mergeNoten(Student arr[], int links, int mitte, int rechts);

// Mergesort, sortiert NACH NAME (alphabetisch) – zweite Variante!
void mergesortName(Student arr[], int links, int rechts);
void mergeName(Student arr[], int links, int mitte, int rechts);

// Ausgabe
void zeigeStudenten(Student arr[], int n);
```

**Wichtiger Hinweis:** Beim Sortieren von Strings (`name`) wird statt `<` der Vergleich mit `strcmp()` benötigt:

```c
if (strcmp(linksArr[i].name, rechtsArr[j].name) <= 0) {
    // linksArr[i] kommt alphabetisch vor oder ist gleich
}
```

**Erwartete Ausgabe:**

```console
=== Nach Durchschnittsnote sortiert (beste zuerst) ===
Keller Sara      | 1012 | 5.80
Wyss Noah        | 1003 | 5.50
Meier Anna       | 1023 | 5.20
Brunner Jan      | 1089 | 5.00
Fischer Lea      | 1034 | 4.70
Steiner Mia      | 1056 | 4.40
Huber Tom        | 1045 | 4.10
Weber Max        | 1067 | 3.90

=== Alphabetisch nach Name sortiert ===
Brunner Jan      | 1089 | 5.00
Fischer Lea      | 1034 | 4.70
Huber Tom        | 1045 | 4.10
Keller Sara      | 1012 | 5.80
Meier Anna       | 1023 | 5.20
Steiner Mia      | 1056 | 4.40
Weber Max        | 1067 | 3.90
Wyss Noah        | 1003 | 5.50
```

**Pflichtanforderungen:**

- [ ] Beide Mergesort-Varianten funktionieren korrekt (gleiche Struktur des Algorithmus, unterschiedliches Vergleichskriterium)
- [ ] Temporäre Arrays für `Student`-Structs korrekt mit `malloc`/`free` verwaltet
- [ ] `strcmp()` korrekt für die alphabetische Sortierung verwendet
- [ ] Sortierung nach Note ist **absteigend** (beste Note zuerst) – Vergleichsoperator entsprechend angepasst
- [ ] Originalarray bleibt bis zum jeweiligen Sortieraufruf unverändert (mit Kopie arbeiten, falls beide Sortierungen im gleichen Programmlauf gezeigt werden sollen)

**Präsentationsfragen:**

1. Was musstet ihr im Vergleich zum einfachen `int`-Mergesort aus der Theorie ändern, um mit `Student`-Structs zu arbeiten?
2. Zeigt die Zeile, die für die **absteigende** Sortierung nach Note sorgt – was wäre anders bei aufsteigender Sortierung?
3. Warum wird `strcmp()` statt `<` oder `>` für den Namensvergleich verwendet? Was gibt `strcmp()` zurück?
4. Führt den Merge-Schritt für zwei kleine Teilarrays (z.B. die ersten 2 vs. nächsten 2 Studierenden) von Hand vor.
5. Ist eure Mergesort-Implementierung stabil? Was würde das für zwei Studierende mit exakt gleicher Note bedeuten?

---

</br>

## Gruppenarbeit C – «Quicksort mit Pivot-Strategien vergleichen»

**Szenario:**

Die Wahl des Pivot-Elements beeinflusst die Performance von Quicksort entscheidend.
Ihr implementiert **zwei verschiedene Pivot-Strategien** und untersucht, wie sie sich bei unterschiedlich vorsortierten Daten verhalten.

**Anforderungen:**

**Variante 1 – Pivot = letztes Element (wie in der Theorie):**

```c
int partitionLetztes(int arr[], int low, int high);
void quicksortLetztes(int arr[], int low, int high);
```

**Variante 2 – Pivot = mittleres Element:**

```c
int partitionMitte(int arr[], int low, int high);
void quicksortMitte(int arr[], int low, int high);
```

**Hinweis für Variante 2:** Das mittlere Element muss zuerst ans Ende getauscht werden, dann funktioniert die restliche Partitionslogik wie gewohnt:

```c
int partitionMitte(int arr[], int low, int high) {
    int mitte = low + (high - low) / 2;
    tausche(&arr[mitte], &arr[high]);   // mittleres Element ans Ende bringen
    return partitionLetztes(arr, low, high);  // danach normale Logik wiederverwenden
}
```

**Zählfunktion für rekursive Aufrufe (Vergleichstiefe messen):**

```c
int zaehleRekursionstiefe(int arr[], int low, int high, int aktuelleTiefe);
```

### Testdaten – kritischer Fall für Pivot=letztes

```c
int bereitsSortiert[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};   // Worst Case für Pivot=letztes!
int zufaelligesArray[10] = {7, 2, 9, 1, 5, 3, 8, 6, 4, 10};
```

**Aufgabenstellung:**

- **Schritt 1:** Implementiert beide Varianten.
- **Schritt 2:** Testet beide Varianten mit beiden Arrays und zählt die maximale Rekursionstiefe.
- **Schritt 3 – Beobachtung dokumentieren:**

```console
Maximale Rekursionstiefe:
 |                  | Pivot=Letztes | Pivot=Mitte |
 | ---------------- | ------------- | ----------- |
 | Bereits sortiert |               |             |
 | Zufällig         |               |             |
```

> Bei `Pivot=Letztes` und einem **bereits sortierten** Array entsteht der **Worst Case**: Jede Partition trennt nur ein einziges Element ab – die Rekursionstiefe nähert sich `n` (statt `log n`)!

Erwartete Beobachtung (zur Diskussion):

```console
Maximale Rekursionstiefe:
|                  | Pivot=Letztes | Pivot=Mitte |
| ---------------- | :-----------: | :---------: |
| Bereits sortiert |      10       |      4      |
| Zufällig         |       5       |      4      |
```

**Pflichtanforderungen:**

- [ ] Beide Pivot-Varianten korrekt implementiert und liefern korrekt sortierte Arrays
- [ ] Rekursionstiefe wird korrekt gemessen (z.B. über einen globalen oder per Pointer übergebenen Zähler)
- [ ] Tabelle mit allen 4 Messwerten ausgefüllt
- [ ] Schriftliche Erklärung, warum Pivot=Letztes beim sortierten Array zum Worst Case führt

**Präsentationsfragen:**

1. Führt die Partitionierung von `partitionLetztes` für `bereitsSortiert` (erste 5 Elemente) von Hand vor – wie viele Elemente werden in jedem Schritt abgetrennt?
2. Warum führt ein bereits sortiertes Array bei Pivot=Letztes zum schlechtesten Fall? Erklärt es mit eigenen Worten anhand eures Codes.
3. Was genau bewirkt die Zeile `tausche(&arr[mitte], &arr[high])` in `partitionMitte`?
4. Wenn ihr eine dritte Pivot-Strategie implementieren würdet (z.B. zufälliges Element) – was müsstet ihr in eurem Code ändern?
5. Ist eure Quicksort-Implementierung in-place? Wie viel zusätzlicher Speicher wird (ausser für die Rekursion) benötigt?

---

</br>

## Gruppenarbeit D – «Heapsort visualisieren und Schritt für Schritt nachvollziehen»

**Szenario:**

- Heapsort ist der am wenigsten intuitive Algorithmus dieser Lektion.
- Eure Aufgabe: implementiert Heapsort **mit Zwischenausgaben**, sodass man den Heap-Aufbau und die Sortierphase live im Terminal mitverfolgen kann – als Lernwerkzeug für andere Studierende.

**Anforderungen:**

```c
void tausche(int *a, int *b);
void heapify(int arr[], int n, int i);
void heapsort(int arr[], int n);

// Visualisierungsfunktionen – NEU in dieser Aufgabe:
void zeigeArrayAlsBaum(int arr[], int n);    // gibt den Heap als Baumstruktur aus
void zeigeArray(int arr[], int n);            // einfache Array-Ausgabe mit Markierung
int  istMaxHeap(int arr[], int n);            // prüft ob die Max-Heap-Eigenschaft gilt
```

**`zeigeArrayAlsBaum` – Beispielausgabe für `[9, 6, 5, 2, 1, 3]`:**

```console
            9
          /   \
         6     5
        / \   /
       2   1 3
```

> *(Eine einfache zeilenweise Ausgabe nach Baumebenen reicht – exakte grafische Ausrichtung ist nicht erforderlich, aber die Eltern-Kind-Beziehung muss erkennbar sein, z.B. durch Einrückung pro Ebene.)*

**`istMaxHeap` – Prüflogik:**

```c
// Für jeden Knoten i: arr[i] muss >= arr[2i+1] und >= arr[2i+2] sein (falls vorhanden)
// Gibt 1 zurück wenn die Eigenschaft für ALLE Knoten gilt, sonst 0
```

**Heapsort mit Zwischenausgaben:**

Ruft nach jedem `heapify`-Aufruf in der Aufbauphase und nach jedem Tausch in der
Sortierphase `zeigeArray()` auf, sodass der komplette Ablauf sichtbar wird.

**Erwartete Ausgabe (Auszug):**

```console
=== Phase 1: Max-Heap aufbauen ===
Start:           [5, 2, 9, 1, 6, 3]
Nach heapify(2): [5, 2, 9, 1, 6, 3]
Nach heapify(1): [5, 6, 9, 1, 2, 3]
Nach heapify(0): [9, 6, 5, 1, 2, 3]
Heap-Eigenschaft erfüllt: JA

=== Phase 2: Sortieren ===
Tausch [0]<->[5]: [3, 6, 5, 1, 2, 9]  → 9 ist jetzt sortiert
Nach heapify:     [6, 3, 5, 1, 2, 9]
Tausch [0]<->[4]: [2, 3, 5, 1, 6, 9]  → 6, 9 sind jetzt sortiert
Nach heapify:     [5, 3, 2, 1, 6, 9]
...

Endergebnis: [1, 2, 3, 5, 6, 9]
```

**Pflichtanforderungen:**

- [ ] `heapify` und `heapsort` korrekt implementiert (gemäss Theorie)
- [ ] `istMaxHeap` korrekt – erkennt sowohl gültige als auch ungültige Heaps
- [ ] Zwischenausgaben zeigen den Ablauf nachvollziehbar Schritt für Schritt
- [ ] `zeigeArrayAlsBaum` stellt die Baumstruktur erkennbar dar (Einrückung nach Ebene reicht)
- [ ] Test mit `istMaxHeap` **vor** und **nach** Phase 1, um zu beweisen, dass der Heap korrekt aufgebaut wurde

**Präsentationsfragen:**

1. Zeigt `istMaxHeap` an einem **bewusst kaputten** Beispiel (z.B. `[3, 9, 5]`) – warum gibt die Funktion `0` zurück?
2. Erklärt die Indexformeln `2*i+1` und `2*i+2` an eurem `zeigeArrayAlsBaum`-Beispiel – warum funktionieren sie?
3. Warum wird in Phase 1 von `i = n/2 - 1` abwärts bis `0` iteriert – warum nicht von `0` aufwärts?
4. Was ist der Unterschied zwischen dem `n` in `heapify(arr, n, i)` während Phase 1 und während Phase 2? Warum wird es in Phase 2 kleiner?
5. Demonstriert live: Was zeigt euer Programm an, wenn ihr ein bereits sortiertes Array `[1,2,3,4,5,6]` durch `heapsort` schickt? Bleibt die Anzahl Tauschvorgänge trotzdem gleich hoch?

---

© 2026 Lukas Müller – Licensed under CC BY-NC-ND 4.0
See [LICENSE](../license.md) file for details.
