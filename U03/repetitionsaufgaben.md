|                             |                          |                                        |
| --------------------------- | ------------------------ | -------------------------------------- |
| **Elektrotechniker/-in HF** | **Programmiertechnik B** | ![IPSO Logo](./x_gitres/ipso_logo.png) |

---

# Funktionen - Simulation von call by reference. Funktionsprototyp

| **Vorgabe**         | **Beschreibung**                                                        |
| :------------------ | :---------------------------------------------------------------------- |
| **Lernziele**       | Kennt die Möglichkeiten zur Modularisierung und Strukturierung von Code |
|                     | Kann Funktionen mit und ohne Parameter implementieren                   |
|                     | Kann Funktionen korrekt aufrufen                                        |
|                     | Kann zwischen "call by value" und "call by pointer" unterscheiden       |
| **Sozialform**      | Einzelarbeit                                                            |
| **Auftrag**         | siehe unten                                                             |
| **Hilfsmittel**     |                                                                         |
| **Zeitbedarf**      | 20min                                                                   |
| **Lösungselemente** | Funktionierendes Programm                                               |

- Das folgende Programm soll zwei float-Zahlen `a` und `b` einlesen und ihren Wert am Bildschirm ausgeben.
- Für das Einlesen wird die Funktion `einlesen()` verwendet.
- Fehlende Stellen im Programm sind mit .... gekennzeichnet. Bringen Sie das Programm zum Laufen!

```c
#include <stdio.h> 
 
void einlesen (float *, float *); /* Funktionsprototyp */ 
 
int main (void) 
{ 
   float a, b; 
   einlesen (...., ....); 
   printf ("\na ist %6.2f", a); 
   printf ("\nb ist %6.2f", b); 
   return 0; 
} 
 
void einlesen (float * x, float * y) 
{ 
   printf ("\nGib einen float-Wert fuer a ein: "); 
   scanf ("%e", ....); 
   printf ("\nGib einen float-Wert fuer b ein: "); 
   scanf ("%e", ....); 
} 
```

---

# Übergabeparameter

| **Vorgabe**         | **Beschreibung**                                                        |
| :------------------ | :---------------------------------------------------------------------- |
| **Lernziele**       | Kennt die Möglichkeiten zur Modularisierung und Strukturierung von Code |
|                     | Kann Funktionen mit und ohne Parameter implementieren                   |
|                     | Kann Funktionen korrekt aufrufen                                        |
|                     | Kann zwischen "call by value" und "call by pointer" unterscheiden       |
| **Sozialform**      | Einzelarbeit                                                            |
| **Auftrag**         | siehe unten                                                             |
| **Hilfsmittel**     |                                                                         |
| **Zeitbedarf**      | 20min                                                                   |
| **Lösungselemente** | Funktionierendes Programm                                               |

Schreiben Sie eine Funktion `rechne_kreisdaten()`, die den Umfang und die Fläche eines Kreises aus dem Radius berechnet.

- Die Funktion erhält drei Übergabeparameter:
  - den Radius und zwei Zeiger auf double-Variablen, in welche die Funktion `rechne_kreisdaten()` die Fläche und den Umfang des Kreises zurückschreibt.  
- Die Ein- und Ausgabe erfolgt in main().
- Für einen Kreis mit Radius R gilt:
  - Fläche = `PI * R * R`
  - Umfang = `2 * PI * R`

---

# Funktionen - Rückgabe mit return und über die Parameterliste

| **Vorgabe**         | **Beschreibung**                                                        |
| :------------------ | :---------------------------------------------------------------------- |
| **Lernziele**       | Kennt die Möglichkeiten zur Modularisierung und Strukturierung von Code |
|                     | Kann Funktionen mit und ohne Parameter implementieren                   |
|                     | Kann Funktionen korrekt aufrufen                                        |
|                     | Kann zwischen "call by value" und "call by pointer" unterscheiden       |
| **Sozialform**      | Einzelarbeit                                                            |
| **Auftrag**         | siehe unten                                                             |
| **Hilfsmittel**     |                                                                         |
| **Zeitbedarf**      | 20min                                                                   |
| **Lösungselemente** | Funktionierendes Programm                                               |

- Das folgende Programm dient zur Berechnung des Durchschnitts von 10 int-Zahlen, die im Dialog eingegeben werden.
- Der berechnete Durchschnitt wird von der Funktion `durchschnitt1()` über die Parameterliste und von der Funktion `durchschnitt2()` mit return zurückgegeben.

Schreiben Sie die Funktionen `einlesen()`, `durchschnitt1()` und `durchschnitt2()`.
Fehlende Teile sind mit .... gekennzeichnet.
Es wird mit dem globalen Array `a` gearbeitet.

```c
#include <stdio.h>

#define MAX 10

int summe(???) { ??? }

int maximum(???) { ??? }

double durchschnitt(???) { ??? }

void statistik(int* sum, int* max, double* avg, ???) { ??? }

int main(void) {
  int a[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  int sum;
  int max;
  double avg;
  
  statistik(???);
  
  printf("Summe: %d\n", sum);
  printf("Maximum: %d\n", max);
  printf("Durchschnitt: %f\n", avg);

  return 0;
}
```
