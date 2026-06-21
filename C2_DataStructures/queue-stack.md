|                             |                          |                               |
| --------------------------- | ------------------------ | ----------------------------- |
| **Elektrotechniker/-in HF** | **Programmiertechnik B** | ![logo](../x_gitres/logo.png) |

- [1. Stack](#1-stack)
  - [1.1. Was ist ein Stack](#11-was-ist-ein-stack)
  - [1.2. Eigenschaften einer Stack-Struktur](#12-eigenschaften-einer-stack-struktur)
  - [1.3. Grundstruktur einer Stack-Struktur](#13-grundstruktur-einer-stack-struktur)
  - [1.4. Typische Anwendungen einer Stack-Struktur](#14-typische-anwendungen-einer-stack-struktur)
- [2. Queue](#2-queue)
  - [2.1. Was ist eine Queue](#21-was-ist-eine-queue)
  - [2.2. Grundstruktur einer Queue](#22-grundstruktur-einer-queue)
  - [2.3. Eigenschaften einer Queue](#23-eigenschaften-einer-queue)
  - [2.4. Typische Anwendungen einer Queue](#24-typische-anwendungen-einer-queue)
- [3. Aufgaben](#3-aufgaben)
  - [3.1. Stack- und Queue Datenstruktur implementieren](#31-stack--und-queue-datenstruktur-implementieren)

---

</br>

# 1. Stack

## 1.1. Was ist ein Stack

- Ein Stack ist eine **lineare Datenstruktur**, die nach dem **LIFO-Prinzip (Last In, First Out)** arbeitet.
- Das zuletzt eingefügte Element wird als erstes wieder entfernt – ähnlich wie ein Stapel Teller, bei dem man immer den obersten Teller zuerst wegnimmt.

## 1.2. Eigenschaften einer Stack-Struktur

- **LIFO-Prinzip**: Letztes Element rein → erstes Element raus
- Zugriff nur auf das oberste Element (Top)
- Dynamisch in der Grösse (je nach Implementierung)
- Unterstützt in der Regel folgende Kernoperationen:
  - `push(element)` – legt ein Element oben auf den Stapel
  - `pop()` – entfernt und liefert das oberste Element
  - `peek()` oder `top()` – liefert das oberste Element, ohne es zu entfernen
  - `isEmpty()` – prüft, ob der Stapel leer ist

## 1.3. Grundstruktur einer Stack-Struktur

- Ablegen und Entnahme der Elemente von **oben**, d.h. die Elemente, die **zuletzt eingefügt wurden, werden als nächstes wieder entnommen** (**Last-in-First-out, LIFO**).

![Datenstruktur Stack](./x_gitres/datenstruktur-stack.png)

## 1.4. Typische Anwendungen einer Stack-Struktur

- Funktionsaufruf-Stack (Call Stack) in Programmiersprachen
- Undo-/Redo-Funktionen in Textverarbeitungen
- Klammern-Überprüfung in Ausdrücken
- Tiefensuche (Depth-First Search) in Graphen

# 2. Queue

## 2.1. Was ist eine Queue

- Eine Queue ist eine **lineare Datenstruktur**, die nach dem **FIFO-Prinzip (First In, First Out)** arbeitet.
- Das zuerst eingefügte Element wird als erstes wieder entfernt – wie eine Warteschlange im Supermarkt.

## 2.2. Grundstruktur einer Queue

- Ablegen der Elemente erfolgt von **oben** und Entnahme von **unten**, d.h. die Elemente, die zuletzt eingefügt wurden, werden als letzte wieder entnommen (**First-in-First-out, FIFO**).

![Datenstruktur Queue](./x_gitres/datenstruktur-queue.png)

## 2.3. Eigenschaften einer Queue

- FIFO-Prinzip: Erstes Element rein → erstes Element raus
- Zugriff nur auf das vorderste (Front) und hinterste (Rear) Element
- Unterstützt in der Regel folgende Kernoperationen:
  - `enqueue(element)` – fügt ein Element hinten ein
  - `dequeue()` – entfernt und liefert das erste Element
  - `peek()` oder `front()` – liefert das erste Element, ohne es zu entfernen
  - `isEmpty()` – prüft, ob die Warteschlange leer ist

## 2.4. Typische Anwendungen einer Queue

- Warteschlangenverwaltung (z. B. Druckaufträge, Kundenservice)
- Breitensuche (Breadth-First Search) in Graphen
- Task Scheduling in Betriebssystemen
- Paket- oder Nachrichtenverarbeitung in Netzwerken

---

</br>

# 3. Aufgaben

## 3.1. Stack- und Queue Datenstruktur implementieren

| **Vorgabe**         | **Beschreibung**                                                                        |
| :------------------ | :-------------------------------------------------------------------------------------- |
| **Lernziele**       | Kennt die Stack- und Queue-Datenstruktur                                                |
|                     | Kann eine Stack- und Queue-Datenstruktur mit den erforderlichen Methoden implementieren |
| **Sozialform**      | Einzelarbeit                                                                            |
| **Auftrag**         | siehe unten                                                                             |
| **Hilfsmittel**     | [Wiki Datenstrukturen](https://de.wikipedia.org/wiki/Datenstruktur)                     |
| **Zeitbedarf**      | 50min                                                                                   |
| **Lösungselemente** |                                                                                         |

a) Erstelle ein C-Programm, das die **Stack**-Datenstruktur basierend auf einer verketteten Liste mit den folgenden Funktionen implementiert:

- `push(element)` – legt ein Element oben auf den Stapel
- `pop()` – entfernt und liefert das oberste Element
- `peek()` oder `top()` – liefert das oberste Element, ohne es zu entfernen
- `isEmpty()` – prüft, ob der Stapel leer ist

b) Erstelle ein C-Programm, das die **Queue**-Datenstruktur basierend auf einer verketteten Liste mit folgenden Funktionen implementiert:

- `enqueue(element)` – fügt ein Element hinten ein
- `dequeue()` – entfernt und liefert das erste Element
- `peek()` oder `front()` – liefert das erste Element, ohne es zu entfernen
- `isEmpty()` – prüft, ob die Warteschlange leer ist
