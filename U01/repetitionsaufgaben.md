|                             |                          |                                        |
| --------------------------- | ------------------------ | -------------------------------------- |
| **Elektrotechniker/-in HF** | **Programmiertechnik A** | ![IPSO Logo](./x_gitres/ipso_logo.png) |

- [1. Kapitalbildung](#1-kapitalbildung)
- [2. Volumenberechnung](#2-volumenberechnung)
- [3. Bremswegberechnung](#3-bremswegberechnung)
- [4. Erweiterter Taschenrechner](#4-erweiterter-taschenrechner)
- [5. Erweiterte Kapitalbildung](#5-erweiterte-kapitalbildung)
- [6. Erweiterte Volumenberechnung](#6-erweiterte-volumenberechnung)
- [7. Erweiterte Bremswegberechnung](#7-erweiterte-bremswegberechnung)
- [8. Wechselkurs](#8-wechselkurs)
- [9. Wechselkurs 2](#9-wechselkurs-2)
- [10. Zahl raten](#10-zahl-raten)

---

# 1. Kapitalbildung

- Ein Kapital von **2800 CHF** wird angelegt.
- Der Zinssatz ist **3.2 Prozent**.
- Wie hoch ist das Endkapital nach einem Jahr?

Löse die Aufgabe mit einen C-Konsolen-Programm. Üebergebe die Parameter via Konsole.

Die Formel dafür ist folgende:
> ![Formel](./x_gitres/task-kapitalbildung.png)

---

</br>

# 2. Volumenberechnung

- Berechne das Volumen eines Körpers.
- Es wird die Länge, Breite und Höhe in [m] als Parameter übergeben.

Löse die Aufgabe als C-Konsolen-Programm.

---

</br>

# 3. Bremswegberechnung

- Berechne den Bremsweg bei einer vorgegebenen Verzögerung in [m/s2] und mit einer Zeit in [s] mit der Formel.
  
> ![Formel](./x_gitres/task-bremsweg.png)

---

</br>

# 4. Erweiterter Taschenrechner

- Implementiere einen Taschrechner der zuerst nach der 1. Zahl fragt.
- Dann nach dem Operanden.
- Dann nach der 2. Zahl.
- Es sind folgende Operationen möglich: +, -, * u. /. (Additon. Subtraktion, Multiplikation u. Division).

> - **Tipp**: Nach der Eingabe muss der Eingangspuffer mit `getchar()` geleert werden.
> - **Grund**: `scanf` leert den Eingangspuffer nicht vollständig, wenn Zahlen eingelesen werden.

---

</br>

# 5. Erweiterte Kapitalbildung

- Erweitere die Kapitalbildung mit einer User-Eingabe-Überprüfung.
- Überpruefe ob ein gültiges Kapital und ein gültiger Prozentsatz eingegeben wird.
- Der Prozentsatz soll grösser als 0 und kleiner gleich 100 sein.
- Das Kapital sollte ein Wert grösser als 0 haben.

---

</br>

# 6. Erweiterte Volumenberechnung

- Erweitere die Volumenberechnung mit einer User-Eingabe-Überprüfung.
- Überpruefe, ob die Länge, Breite und Höhe einen Wert grösser als 0 hat.

---

</br>

# 7. Erweiterte Bremswegberechnung

- Erweitere die Bremswegberechnung mit einer User-Eingabe-Überprüfung.
- Überpruefe, ob die Verzögerung und die Zeit einen Wert grösser als 0 hat.

---

</br>

# 8. Wechselkurs

- Schreibe ein Programm, dass den Wechselkurs rechnet.
- Das Programm fragt den Betrag in Schweizer Franken [CHF] und in welche Währung es umrechnen soll.
- Untersützt werden sollen '$', '£', 'e' und 'E' für Euro.
- Löse die Aufgabe mit einem C-Programm.

> **Tipp:** Nicht vergessen hier den Eingangspuffer mit `getchar()` zu leeren. Nach jeder Eingabe.

---

</br>

# 9. Wechselkurs 2

- Erweitere die Aufgabe Wechselkurs so, damit immer wieder ein neuer Betrag und eine neue Währung eingegeben werden kann.
- Das Programm kann mit `'q'` beendet werden.
- Erkläre warum diese Aufgabe mit jeder Schleifen-Art gelöst werden kann und warum deine gewählte Art die Beste ist.

--

</br>

# 10. Zahl raten

- Der Benutzer soll eine Zahl zwischen 1 und 100 erraten.
- Das Programm gibt Feedback, ob die Zahl zu hoch oder zu niedrig ist, bis der Benutzer die richtige Zahl erraten hat.
- Erweitere das Programm, indem die Anzahl der Versuche gezählt und angezeigt werden.
