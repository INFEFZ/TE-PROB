|                             |                          |                               |
| --------------------------- | ------------------------ | ----------------------------- |
| **Elektrotechniker/-in HF** | **Programmiertechnik B** | ![logo](../x_gitres/logo.png) |

- [1. Gruppenarbeit Rekursion](#1-gruppenarbeit-rekursion)
  - [1.1. Gruppenarbeit A – «Palindrom und Zeichenketten-Rekursion»](#11-gruppenarbeit-a--palindrom-und-zeichenketten-rekursion)
  - [1.2. Gruppenarbeit B – «Binärsuche rekursiv»](#12-gruppenarbeit-b--binärsuche-rekursiv)
  - [1.3. Gruppenarbeit C – «Türme von Hanoi»](#13-gruppenarbeit-c--türme-von-hanoi)
  - [1.4. Gruppenarbeit D – «Fibonacci: Rekursion, Memoization und Stack-Analyse»](#14-gruppenarbeit-d--fibonacci-rekursion-memoization-und-stack-analyse)

---

</br>

# 1. Gruppenarbeit Rekursion

| **Vorgabe**         | **Beschreibung**                                                                             |
| :------------------ | :------------------------------------------------------------------------------------------- |
| **Lernziele**       | Das Prinzip der Rekursion (Basisfall + rekursiver Schritt) erklären                          |
|                     | Den Aufruf-Stack einer rekursiven Funktion für einen konkreten Eingabewert von Hand zeichnen |
|                     | Einfache Probleme (Fakultät, Summe, Potenz) sowohl iterativ als auch rekursiv implementieren |
|                     | Die Gefahr des Stack Overflows bei zu tiefer Rekursion erklären                              |
| **Sozialform**      | Gruppenarbeit: 2-3 Personen                                                                  |
| **Auftrag**         | siehe unten                                                                                  |
| **Hilfsmittel**     |                                                                                              |
| **Zeitbedarf**      | 60min                                                                                        |
| **Lösungselemente** | Abgabe: Alle Dateien (.h und .c) als Gesamtprojekt                                           |
|                     | Funktionierendes Programm und Präsentation (Code erklären), ca. 5 min.                       |
|                     | Jedes Gruppenmitglied muss Teile des Codes erklären können                                   |

</br>

> Hinweis zum KI-Einsatz
> Rekursive Funktionen lassen sich von KI in Sekunden generieren.
> In der Präsentation wird deshalb jedes Mitglied einzeln gefragt:
>
> - *„Zeichne den Aufruf-Stack für den Eingabewert 4 von Hand auf Papier."*
> - *„Was ist der Basisfall eurer Funktion? Was passiert, wenn er fehlt?"*
> - *„Wie viele rekursive Aufrufe braucht euer Algorithmus für n=5? Für n=10?"*
> - *„Baue den Basisfall absichtlich falsch ein – was passiert dann?"*
> - *„Erkläre Zeile für Zeile, was beim Rückweg der Rekursion passiert."*
>
> Wer den Aufruf-Stack nicht von Hand zeichnen kann, hat die Rekursion
> nicht verstanden – egal wie korrekt der Code aussieht.

---

## 1.1. Gruppenarbeit A – «Palindrom und Zeichenketten-Rekursion»

**Szenario:**

Rekursion eignet sich besonders gut für Probleme, die sich natürlich auf kleinere Teilprobleme reduzieren lassen – wie das Prüfen und
Verarbeiten von Zeichenketten zeichenweise.

**Aufgabenstellung:**

Implementiert **beide** folgenden Funktionen rekursiv:

**Funktion 1 - Palindrom-Prüfung:**

Ein Palindrom ist ein Wort, das vorwärts und rückwärts gleich geschrieben wird (z.B. „racecar", „level", „madam").

```c
// Gibt 1 zurück wenn text ein Palindrom ist, sonst 0
// Rekursive Idee: erster und letzter Buchstabe gleich?
//                → dann das Innere rekursiv prüfen
int istPalindrom(char text[], int links, int rechts);
```

Aufruf in `main()`:

```c
istPalindrom(text, 0, strlen(text) - 1);
```

**Funktion 2 - Ziffernquersumme:**

```c
// Berechnet die Quersumme einer positiven ganzen Zahl
// Beispiel: quersumme(1234) = 1 + 2 + 3 + 4 = 10
// Rekursive Idee: letzte Ziffer (n % 10) + Quersumme des Rests (n / 10)
int quersumme(int n);
```

**Testet mit folgenden Werten:**

| **Funktion**   | **Eingabe** | **Erwartetes Ergebnis** |
| -------------- | ----------- | ----------------------- |
| `istPalindrom` | `"racecar"` | 1 (Ja)                  |
| `istPalindrom` | `"level"`   | 1 (Ja)                  |
| `istPalindrom` | `"hello"`   | 0 (Nein)                |
| `istPalindrom` | `"a"`       | 1 (Ja – Basisfall!)     |
| `quersumme`    | `1234`      | 10                      |
| `quersumme`    | `9999`      | 36                      |
| `quersumme`    | `0`         | 0 (Basisfall!)          |

**Pflichtschritt – Aufruf-Stack auf Papier:**
Zeichnet den kompletten Aufruf-Stack für `istPalindrom("racecar", 0, 6)` – alle Aufrufe hinunter und den Rückweg mit Rückgabewerten.

**Pflichtanforderungen:**

- [ ] `istPalindrom` ist **rekursiv** (keine Schleife!)
- [ ] `quersumme` ist **rekursiv** (keine Schleife!)
- [ ] Basisfälle korrekt definiert (mind. je einer pro Funktion)
- [ ] Alle Testwerte aus der Tabelle ausgegeben und Ergebnisse stimmen
- [ ] Aufruf-Stack für `istPalindrom("racecar", 0, 6)` auf Papier gezeichnet

**Präsentationsfragen:**

1. Was sind die **Basisfälle** bei `istPalindrom`? Es gibt mindestens zwei – welche, und warum braucht man beide?
2. Zeichnet den Aufruf-Stack für `quersumme(123)` an der Tafel – was passiert bei jedem Aufruf mit `n`?
3. Was passiert, wenn `links` und `rechts` sich „überkreuzen" (`links > rechts`) – warum ist das kein Fehler, sondern ein gültiger Basisfall?
4. Baut **live** einen fehlerhaften Basisfall ein (z.B. `if (n == 0) return 1` statt `return 0` bei `quersumme`) – was passiert mit den Testergebnissen?
5. Für welche Eingabewerte würde `quersumme` **ohne** Basisfall in einen Stack Overflow laufen – und warum?

---

</br>

## 1.2. Gruppenarbeit B – «Binärsuche rekursiv»

**Szenario:**

Die binäre Suche ist ein klassischer Algorithmus, der sich besonders
elegant rekursiv implementieren lässt: Teile das Problem jedes Mal
in zwei Hälften, bis der gesuchte Wert gefunden ist.

**Aufgabenstellung:**

**Voraussetzung:** Ein **aufsteigend sortiertes** Array (die Sortierung selbst
müsst ihr nicht implementieren – die Testdaten werden bereits sortiert vorgegeben).

```c
// Binäre Suche – rekursiv
// Gibt den INDEX des gesuchten Wertes zurück, oder -1 falls nicht gefunden
// links = linke Grenze des aktuellen Suchbereichs
// rechts = rechte Grenze des aktuellen Suchbereichs
int binaersuche(int arr[], int links, int rechts, int suchwert);
```

**Rekursive Idee:**

```console
1. Berechne die Mitte: mitte = links + (rechts - links) / 2
2. Ist arr[mitte] == suchwert → GEFUNDEN, gib mitte zurück (Basisfall 1)
3. Ist links > rechts → NICHT GEFUNDEN, gib -1 zurück (Basisfall 2)
4. Ist arr[mitte] < suchwert → suche rekursiv in der RECHTEN Hälfte
5. Ist arr[mitte] > suchwert → suche rekursiv in der LINKEN Hälfte
```

**Testdaten:**

```c
int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72, 91};
int n = 11;
```

**Testet mit folgenden Suchwerten und gebt dabei die Ausgabe aus:**

| **Suchwert** | **Erwartetes Ergebnis**              |
| ------------ | ------------------------------------ |
| `23`         | Index 5 (gefunden)                   |
| `2`          | Index 0 (Randfall: erstes Element)   |
| `91`         | Index 10 (Randfall: letztes Element) |
| `10`         | -1 (nicht im Array)                  |
| `100`        | -1 (grösser als Maximum)             |

**Vergleichsfunktion – iterativ:**
Schreibt zusätzlich die **iterative** Version der Binärsuche und beweist,
dass beide für alle Testwerte dasselbe Ergebnis liefern:

```c
int binaersuche_iterativ(int arr[], int n, int suchwert);
```

**Pflichtschritt – Aufruf-Stack auf Papier:**
Zeichnet alle rekursiven Aufrufe für die Suche nach `23` im Testarray –
wie viele Aufrufe braucht es, bis der Wert gefunden ist?

**Pflichtanforderungen:**

- [ ] Rekursive Version korrekt implementiert (beide Basisfälle vorhanden)
- [ ] Iterative Version zum Vergleich implementiert
- [ ] Alle 5 Testwerte liefern **identische** Ergebnisse in beiden Versionen
- [ ] Aufruf-Stack für Suche nach `23` auf Papier gezeichnet
- [ ] Ausgabe zeigt klar: welcher Suchwert → welcher Index → wie viele Schritte?

**Präsentationsfragen:**

1. Zeichnet den Aufruf-Stack für die Suche nach `23` an der Tafel – wie viele Aufrufe braucht die rekursive Version?
2. Warum wird die Mitte mit `links + (rechts - links) / 2` berechnet statt einfach `(links + rechts) / 2`? (Hinweis: Integer Overflow)
3. Was passiert, wenn das Array **nicht** sortiert ist? Demonstriert mit einem Gegenbeispiel.
4. Vergleicht die rekursive mit der iterativen Version: Welche ist leichter zu lesen? Welche braucht mehr Stack-Speicher, und warum?
5. Wie viele Aufrufe braucht die binäre Suche im **schlechtesten Fall** für ein Array mit 1024 Elementen? (Tipp: log₂)

---

</br>

## 1.3. Gruppenarbeit C – «Türme von Hanoi»

**Szenario:**

Das Türme-von-Hanoi-Problem ist das Paradebeispiel für Rekursion: eine Aufgabe, die iterativ kaum lösbar scheint, sich aber rekursiv
in drei elegante Zeilen Code ausdrücken lässt.

**Das Problem:** n Scheiben liegen auf Stab A (grösste unten, kleinste oben).
Ziel: alle Scheiben auf Stab C bewegen, mit Hilfsstab B.
Regeln: immer nur eine Scheibe bewegen, nie eine grössere auf eine kleinere legen.

![Türme von Hanoi](https://upload.wikimedia.org/wikipedia/commons/0/07/Tower_of_Hanoi.jpeg)

**Aufgabenstellung:**

```c
// Bewegt n Scheiben von "von" nach "nach", mit "hilfs" als Hilfsstab
// Gibt jeden Einzelzug als Text aus
void hanoi(int n, char von, char nach, char hilfs);
```

**Rekursive Idee (drei Schritte):**

```console
1. Bewege n-1 Scheiben von A nach B (mit C als Hilfe)  → rekursiver Aufruf
2. Bewege die grösste Scheibe von A nach C              → 1 Zug ausgeben
3. Bewege n-1 Scheiben von B nach C (mit A als Hilfe)  → rekursiver Aufruf
```

**Basisfall:**

```c
if (n == 0) return;   // keine Scheiben = nichts zu tun
```

**Aufruf in `main()`:**

```c
hanoi(3, 'A', 'C', 'B');   // 3 Scheiben von A nach C
```

**Erwartete Ausgabe für `hanoi(3, 'A', 'C', 'B')`:**

```console
Scheibe von A nach C
Scheibe von A nach B
Scheibe von C nach B
Scheibe von A nach C
Scheibe von B nach A
Scheibe von B nach C
Scheibe von A nach C
```

*(7 Züge für 3 Scheiben):*

**Zusatzaufgabe – Zuganzahl zählen:**
Ergänzt einen **globalen Zähler** (oder Rückgabewert), der die Gesamtzahl
der Züge mitzählt, und testet für n = 1 bis 6:

| n   | Erwartete Zuganzahl |
| --- | ------------------- |
| 1   | 1                   |
| 2   | 3                   |
| 3   | 7                   |
| 4   | 15                  |
| 5   | 31                  |
| 6   | 63                  |

**Pflichtschritt – Muster erkennen:**
Leitet aus der Tabelle die Formel für die Anzahl Züge ab:
`Züge(n) = ?` (mathematische Formel in Abhängigkeit von n)

**Pflichtanforderungen:**

- [ ] `hanoi` korrekt rekursiv implementiert
- [ ] Ausgabe für `n=3` stimmt mit der erwarteten Ausgabe überein (7 Züge, korrekte Reihenfolge)
- [ ] Zuganzahl für n = 1 bis 6 gezählt und ausgegeben
- [ ] Formel für Zuganzahl hergeleitet und in der Präsentation erklärt
- [ ] Basisfall explizit kommentiert

**Präsentationsfragen:**

1. Erklärt die drei Schritte der Rekursion an `hanoi(2, 'A', 'C', 'B')` – zeichnet alle Aufrufe als Baum an der Tafel.
2. Was ist der Basisfall, und was passiert, wenn man ihn weglässt?
3. Führt `hanoi(4, ...)` aus und zählt die Züge – stimmt das mit eurer Formel überein?
4. Für `n = 64` (das originale Hanoi-Rätsel) braucht es `2^64 - 1` Züge. Wenn man einen Zug pro Sekunde macht – wie lange dauert das in Jahren?
5. Versucht, eine **iterative** Lösung für Hanoi zu beschreiben (keine Implementierung nötig) – was macht das so viel schwieriger als die rekursive Variante?

---

</br>

## 1.4. Gruppenarbeit D – «Fibonacci: Rekursion, Memoization und Stack-Analyse»

**Szenario:**

Die Fibonacci-Folge ist ein klassisches Beispiel, das die **Schwäche**
der naiven Rekursion sichtbar macht: derselbe Wert wird exponentiell
oft neu berechnet. Ihr implementiert die naive Version, messt das
Problem, und löst es dann mit **Memoization** (Zwischenspeichern
bereits berechneter Werte).

**Aufgabenstellung:**

**Funktion 1 – Naive Rekursion:**

```c
// Berechnet die n-te Fibonacci-Zahl rekursiv (naiv, OHNE Caching)
// fib(0) = 0, fib(1) = 1, fib(n) = fib(n-1) + fib(n-2)
long long fibRekursiv(int n);
```

**Funktion 2 – Mit Aufruf-Zähler:**

```c
// Wie fibRekursiv, zählt aber die Gesamtzahl der Funktionsaufrufe
long long fibMitZaehler(int n, int *zaehler);
```

**Funktion 3 – Iterativ (Vergleich):**

```c
long long fibIterativ(int n);
```

**Funktion 4 – Memoization (rekursiv mit Cache):**

```c
#define MAX_N 50
long long cache[MAX_N];   // mit -1 vorinitialisieren!

long long fibMemo(int n);
// Idee: vor dem rekursiven Aufruf prüfen ob cache[n] != -1
//       wenn ja: gecachten Wert zurückgeben
//       wenn nein: berechnen UND in cache[n] speichern
```

**Messtabelle – Aufruf-Zähler dokumentieren:**

Füllt folgende Tabelle aus (mit `fibMitZaehler`):

| n   | Fibonacci-Zahl | Anzahl Funktionsaufrufe |
| --- | -------------- | ----------------------- |
| 5   | 5              | ?                       |
| 10  | 55             | ?                       |
| 15  | 610            | ?                       |
| 20  | 6765           | ?                       |
| 30  | 832040         | ?                       |

**Pflichtschritt – Wachstum beobachten:**
Trägt die Aufruf-Anzahl in eine handgezeichnete Tabelle ein und
beschreibt das Wachstumsmuster: linear? Quadratisch? Exponentiell?

**Pflichtanforderungen:**

- [ ] Alle vier Funktionen implementiert
- [ ] `fibRekursiv` und `fibIterativ` liefern für alle n dieselben Ergebnisse
- [ ] Messtabelle vollständig ausgefüllt (Aufruf-Zähler für n=5 bis n=30)
- [ ] `fibMemo` liefert dieselben Ergebnisse wie `fibRekursiv`, aber mit deutlich weniger Aufrufen (messen und vergleichen!)
- [ ] `cache` korrekt mit `-1` vorinitialisiert (z.B. `memset(cache, -1, sizeof(cache))`)

**Präsentationsfragen:**

1. Zeichnet den Rekursionsbaum für `fibRekursiv(5)` an der Tafel – welcher Teilbaum wird **mehrfach** berechnet?
2. Zeigt die Messtabelle: Wie viele Aufrufe braucht `fibRekursiv(30)`? Was sagt das über die Zeitkomplexität aus?
3. Erklärt `fibMemo` Zeile für Zeile – was genau wird im Cache gespeichert, und wann wird er gelesen?
4. Wie viele Aufrufe braucht `fibMemo(30)` im Vergleich zu `fibRekursiv(30)`? Wo liegt die Verbesserung?
5. Warum ist `fibIterativ` in der Praxis oft vorzuziehen, auch wenn `fibMemo` das Aufrufproblem löst? (Hinweis: Stack)

---

© 2026 Lukas Müller – Licensed under CC BY-NC-ND 4.0
See [LICENSE](..\license.md) file for details.
