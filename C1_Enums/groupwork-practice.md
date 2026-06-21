|                             |                          |                               |
| --------------------------- | ------------------------ | ----------------------------- |
| **Elektrotechniker/-in HF** | **Programmiertechnik B** | ![logo](../x_gitres/logo.png) |

- [1. Gruppenarbeit Enum's](#1-gruppenarbeit-enums)
  - [Gruppenarbeit A – Wochenplaner mit Array von Enums](#gruppenarbeit-a--wochenplaner-mit-array-von-enums)
  - [Gruppenarbeit B –  Kartenspiel-Simulation](#gruppenarbeit-b---kartenspiel-simulation)

---

</br>

# 1. Gruppenarbeit Enum's

| **Vorgabe**         | **Beschreibung**                                                       |
| :------------------ | :--------------------------------------------------------------------- |
| **Lernziele**       | Enum in Kombination mit Arrays, Zählen, Filtern                        |
|                     | Mehrere Enums kombiniert in einer struct, Vergleichslogik              |
| **Sozialform**      | Gruppenarbeit: 2-3 Personen                                            |
| **Auftrag**         | siehe unten                                                            |
| **Hilfsmittel**     |                                                                        |
| **Zeitbedarf**      | 60min                                                                  |
| **Lösungselemente** | Funktionierendes Programm und Präsentation (Code erklären), ca. 5 min. |
|                     | Jedes Gruppenmitglied muss Teile des Codes erklären können             |

> Hinweis zum KI-Einsatz
> Ihr dürft KI-Tools verwenden – aber: Ihr werdet den Code in der Präsentation erklären müssen.
> Das bedeutet:
>
> - Jede Zeile, die ihr abgebt, müsst ihr verstehen und erklären können
> - Ihr werdet gefragt: „Was passiert hier genau?", „Warum habt ihr das so gelöst?", „Was gibt diese Funktion zurück?"
> - Eine Lösung, die ihr nicht erklären könnt, gilt als nicht bestanden
> - Empfehlung: Nutzt KI als Lernhilfe, nicht als Schreibmaschine. Schreibt Teile selbst, lasst andere erklären, diskutiert als Gruppe.

---

## Gruppenarbeit A – Wochenplaner mit Array von Enums

Erstelle:

```c
typedef enum { MONTAG, DIENSTAG, MITTWOCH, DONNERSTAG, FREITAG, SAMSTAG, SONNTAG } Wochentag;
typedef enum { ARBEIT, FREIZEIT, SPORT, RUHETAG } Aktivitaetstyp;
```

Lege ein Array `Aktivitaetstyp plan[7]` an, das jedem Wochentag eine Aktivität zuordnet (z.B. Mo–Fr `ARBEIT`, Sa `SPORT`, So `RUHETAG`).

Implementiere:

1. `const char *wochentagName(Wochentag t)`
2. `const char *aktivitaetName(Aktivitaetstyp a)`
3. `void zeigeWochenplan(Aktivitaetstyp plan[7])` – gibt Tag + Aktivität aus
4. `int zaehleAktivitaet(Aktivitaetstyp plan[7], Aktivitaetstyp gesucht)` – zählt wie oft eine Aktivität vorkommt

**Erwartete Ausgabe:**

```console
Montag:     Arbeit
Dienstag:   Arbeit
Mittwoch:   Arbeit
Donnerstag: Arbeit
Freitag:    Arbeit
Samstag:    Sport
Sonntag:    Ruhetag
 
Anzahl Arbeitstage: 5
Anzahl Ruhetage: 1
```

---

</br>

## Gruppenarbeit B –  Kartenspiel-Simulation

Verwende die Enums aus Abschnitt 5, Beispiel 3 (`Farbe`, `Wert`) und die `Spielkarte`-struct.

Implementiere:

1. `void zeigeKarte(Spielkarte k)` – gibt z.B. "König Herz" aus
2. `int vergleicheKarten(Spielkarte a, Spielkarte b)` – gibt `1` zurück wenn `a` höher ist als `b` (nur nach `Wert`, Farbe spielt keine Rolle), `-1` wenn niedriger, `0` bei Gleichstand
3. `Spielkarte hoechsteKarte(Spielkarte karten[], int anzahl)` – findet die höchste Karte in einem Array
Teste mit einem Array von mindestens 5 Karten.

**Erwartete Ausgabe (Beispiel):**

```console
Karte 1: 7 Karo
Karte 2: König Herz
Karte 3: Ass Pik
Karte 4: 10 Kreuz
Karte 5: Dame Herz
 
Höchste Karte: Ass Pik
```

**Präsentationsfragen:**

Beantworte nach Abschluss der Aufgaben folgende Fragen schriftlich (3–5 Sätze je Frage):

1. Wann würdest du `#define`-Konstanten statt `enum` verwenden – gibt es überhaupt noch sinnvolle Fälle?
2. Warum ist die Konvertierung `int → enum` in C riskant? Was könnte in einem grossen Programm schiefgehen, wenn man Werte aus einer Datei oder Benutzereingabe direkt in ein `enum` castet?
3. In Sprachen wie Java oder C# gibt es eingebaute Methoden, um einen Enum-Wert direkt in einen String umzuwandeln (`.toString()`, `.name()`). Warum bietet C das nicht von sich aus an, und wie wirkt sich das auf die Codequalität aus, die man selbst schreiben muss?

---

© 2026 Lukas Müller – Licensed under CC BY-NC-ND 4.0
See [LICENSE](..\license.md) file for details.
