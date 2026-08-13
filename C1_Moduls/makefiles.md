|                             |                          |                               |
| --------------------------- | ------------------------ | ----------------------------- |
| **Elektrotechniker/-in HF** | **Programmiertechnik B** | ![Logo](../x_gitres/logo.png) |

- [1. Makefiles](#1-makefiles)
  - [1.1. Lernziele](#11-lernziele)
  - [1.2. Wozu dienen Makefiles?](#12-wozu-dienen-makefiles)
  - [1.3. Die Lösung: `make` und Makefile](#13-die-lösung-make-und-makefile)
  - [1.4. Wie wird ein Makefile erstellt?](#14-wie-wird-ein-makefile-erstellt)
    - [1.4.1. Dateiname](#141-dateiname)
    - [1.4.2. Erstellen](#142-erstellen)
    - [1.4.3. Aufrufen](#143-aufrufen)
  - [1.5. Aufbau eines Makefiles](#15-aufbau-eines-makefiles)
    - [1.5.1. Grundstruktur: Regeln](#151-grundstruktur-regeln)
    - [1.5.2. Minimales Beispiel](#152-minimales-beispiel)
    - [1.5.3. Kommentare](#153-kommentare)
  - [1.6. Kompilierung in Schritten – Object-Dateien](#16-kompilierung-in-schritten--object-dateien)
    - [1.6.1. Warum nicht immer alles auf einmal kompilieren?](#161-warum-nicht-immer-alles-auf-einmal-kompilieren)
    - [1.6.2. Zweistufige Kompilierung](#162-zweistufige-kompilierung)
    - [1.6.3. Makefile mit Object-Dateien](#163-makefile-mit-object-dateien)
  - [1.7. Variablen in Makefiles](#17-variablen-in-makefiles)
    - [1.7.1. Variablen definieren und verwenden](#171-variablen-definieren-und-verwenden)
    - [1.7.2. Typische Variablen](#172-typische-variablen)
    - [1.7.3. Häufig verwendete Compiler-Flags](#173-häufig-verwendete-compiler-flags)
    - [1.7.4. Automatische Variablen](#174-automatische-variablen)
  - [1.8. Phony Targets](#18-phony-targets)
  - [1.9. Vollständiges Makefile für ein Mehrfachdatei-Projekt](#19-vollständiges-makefile-für-ein-mehrfachdatei-projekt)
    - [1.9.1. Projektstruktur](#191-projektstruktur)
    - [1.9.2. Das vollständige Makefile](#192-das-vollständige-makefile)
    - [1.9.3. Ablauf beim ersten `make`](#193-ablauf-beim-ersten-make)
    - [1.9.4. Ablauf nach Änderung in `rechner.c`](#194-ablauf-nach-änderung-in-rechnerc)
  - [1.10. Erweiterte Möglichkeiten](#110-erweiterte-möglichkeiten)
    - [1.10.1. Generische Regel mit Muster (`%`)](#1101-generische-regel-mit-muster-)
    - [1.10.2. Debug- vs. Release-Build](#1102-debug--vs-release-build)
    - [1.10.3. Bedingte Ausgabe mit `@`](#1103-bedingte-ausgabe-mit-)
    - [1.10.4. Mehrere Ausgabeprogramme](#1104-mehrere-ausgabeprogramme)
    - [1.10.5. Automatische Abhängigkeitserkennung](#1105-automatische-abhängigkeitserkennung)
  - [1.11. Häufige Fehler und deren Lösung](#111-häufige-fehler-und-deren-lösung)
  - [1.12. Zusammenfassung](#112-zusammenfassung)
    - [1.12.1. Die goldene Regel](#1121-die-goldene-regel)
- [2. Aufgaben](#2-aufgaben)
  - [2.1. Makefile für Trennstrich-Modul](#21-makefile-für-trennstrich-modul)

---

</br>

# 1. Makefiles

## 1.1. Lernziele

- Nach dieser Lektion kannst du ein Makefile für ein C-Projekt mit **mehreren Dateien** erstellen, verstehst den Unterschied zwischen **Kompilierung** und **Linking**, nutzt Variablen und Phony-Targets sinnvoll und kannst erklären, warum **Make** nur geänderte Dateien neu kompiliert.

**Kurze Einführung (Video):**
[Programme mit "make" kompilieren - Schritt für Schritt zum soliden Makefile](https://www.youtube.com/watch?v=K96jRX92_PM)

## 1.2. Wozu dienen Makefiles?

Im letzten Modul haben wir unser Programm aus mehreren `.c`-Dateien kompiliert:

```bash
gcc main.c geometrie.c statistik.c ausgabe.c -o programm -lm
```

Das funktioniert – aber stellen wir uns vor, das Projekt wächst:

```bash
gcc main.c geometrie.c statistik.c ausgabe.c config.c logger.c \
    rechner.c lager.c bericht.c utils.c -o programm -lm -Wall -O2
```

**Probleme bei manuellem Kompilieren:**

| **Problem**              | **Beschreibung**                                              |
| ------------------------ | ------------------------------------------------------------- |
| **Fehleranfälligkeit**   | Tippt man eine Datei falsch, fehlt sie stillschweigend        |
| **Langsam**              | Bei 50 Dateien wird *alles* neu kompiliert, auch Ungeändertes |
| **Nicht reproduzierbar** | Jeder Entwickler tippt den Befehl anders                      |
| **Nicht dokumentiert**   | Welche Flags wurden nochmal verwendet?                        |
| **Mühsam**               | Aufräumen, Testen, Installieren – alles manuelle Schritte     |

---

## 1.3. Die Lösung: `make` und Makefile

`make` ist ein **Build-Automatisierungswerkzeug**. Es liest ein `Makefile` und weiss:

- **Was** kompiliert werden muss
- **Wie** es kompiliert wird
- **Wann** eine Datei neu kompiliert werden muss (nur bei Änderungen)

```bash
make          # kompiliert nur was nötig ist
make clean    # löscht alle erzeugten Dateien
make test     # führt Tests aus
```

> **Kernidee von Make:** Eine Datei wird nur neu erstellt, wenn sie **älter** ist als ihre Quelldatei. Make vergleicht Zeitstempel – nicht Inhalte.

---

## 1.4. Wie wird ein Makefile erstellt?

### 1.4.1. Dateiname

Das Makefile heisst immer **exakt** `Makefile` (grosses M, keine Endung) und liegt im **Projektverzeichnis**:

```bash
mein_projekt/
├── Makefile       ← hier
├── main.c
├── rechner.h
├── rechner.c
└── ausgabe.c
```

> Alternativ ist auch `makefile` (klein) möglich, aber `Makefile` ist die weitverbreitete Konvention.

---

### 1.4.2. Erstellen

```bash
# Im Projektverzeichnis:
touch Makefile          # leere Datei anlegen
code Makefile           # mit code bearbeiten
# oder: code Makefile   # mit VS Code öffnen
```

### 1.4.3. Aufrufen

```bash
make                    # führt das erste (Standard-)Target aus
make clean              # führt Target "clean" aus
make -f MeinMakefile    # andere Datei als Makefile verwenden
make --dry-run          # zeigt Befehle, führt sie aber nicht aus
```

---

## 1.5. Aufbau eines Makefiles

### 1.5.1. Grundstruktur: Regeln

Ein Makefile besteht aus **Regeln** (*Rules*). Jede Regel hat drei Teile:

```makefile
target: dependencies
   recipe
```

| **Teil**       | **Bedeutung**            | **Beispiel**             |
| -------------- | ------------------------ | ------------------------ |
| `target`       | Was soll erzeugt werden? | `programm`, `main.o`     |
| `dependencies` | Was wird dafür benötigt? | `main.c`, `rechner.o`    |
| `recipe`       | Wie wird es erzeugt?     | `gcc main.c -o programm` |

> **Kritisch:** Das `recipe` muss mit einem **echten Tabulator** (`Tab`) eingerückt sein – **nicht** mit Leerzeichen! Das ist die häufigste Fehlerquelle bei Makefiles.

### 1.5.2. Minimales Beispiel

```makefile
programm: main.c rechner.c
    gcc main.c rechner.c -o programm
```

```bash
$ make
gcc main.c rechner.c -o programm
 
$ make          # nochmal aufrufen – nichts geändert
make: 'programm' is up to date.
 
$ touch main.c  # Zeitstempel von main.c aktualisieren
$ make          # jetzt wird neu kompiliert
gcc main.c rechner.c -o programm
```

### 1.5.3. Kommentare

```makefile
# Das ist ein Kommentar – beginnt mit #
# Kommentare können überall stehen (ausser in recipe-Zeilen)
```

---

## 1.6. Kompilierung in Schritten – Object-Dateien

### 1.6.1. Warum nicht immer alles auf einmal kompilieren?

```bash
# Alles auf einmal – einfach, aber langsam bei grossen Projekten:
gcc main.c rechner.c statistik.c ausgabe.c -o programm
```

Bei 20 Dateien und einer kleinen Änderung in `rechner.c` werden trotzdem alle 20 Dateien neu kompiliert.

### 1.6.2. Zweistufige Kompilierung

`gcc` arbeitet in zwei getrennten Schritten:

```console
Schritt 1 – Kompilieren:    .c → .o  (Object-Dateien)
Schritt 2 – Linken:         .o → ausführbares Programm
```

```bash
# Schritt 1: Jede .c separat kompilieren (erzeugt .o Dateien)
gcc -c main.c      -o main.o       # -c = compile only, kein Linken
gcc -c rechner.c   -o rechner.o
gcc -c statistik.c -o statistik.o
 
# Schritt 2: Alle .o zusammenlinken
gcc main.o rechner.o statistik.o -o programm
```

**Vorteil:** Ändert sich nur `rechner.c`, wird nur `rechner.o` neu erzeugt. Alle anderen `.o`-Dateien bleiben unverändert – **Make** erkennt das anhand der Zeitstempel.

```console
Änderung in rechner.c:
- rechner.o  → muss neu kompiliert werden
- main.o    → unverändert, wird wiederverwendet
- statistik.o → unverändert, wird wiederverwendet
- programm   → muss neu gelinkt werden (da rechner.o neu)
```

### 1.6.3. Makefile mit Object-Dateien

```makefile
# Makefile mit zwei Stufen
 
programm: main.o rechner.o statistik.o
    gcc main.o rechner.o statistik.o -o programm
 
main.o: main.c rechner.h statistik.h
    gcc -c main.c -o main.o
 
rechner.o: rechner.c rechner.h
    gcc -c rechner.c -o rechner.o
 
statistik.o: statistik.c statistik.h
    gcc -c statistik.c -o statistik.o
```

**Abhängigkeitsgraph:**

```bash
programm
├── main.o       ← main.c, rechner.h, statistik.h
├── rechner.o    ← rechner.c, rechner.h
└── statistik.o  ← statistik.c, statistik.h
```

> Die Header-Dateien als Dependencies einzutragen ist wichtig! Ändert sich `rechner.h`, muss `main.o` neu erzeugt werden – weil `main.c` die Header-Datei einbindet.

---

## 1.7. Variablen in Makefiles

**Makefiles** kennen **Variablen** – damit werden Wiederholungen vermieden und Anpassungen zentralisiert.

### 1.7.1. Variablen definieren und verwenden

```makefile
VARIABLE = wert           # Definition
$(VARIABLE)               # Verwendung – immer mit $()
```

### 1.7.2. Typische Variablen

```makefile
# Compiler und Flags
CC      = gcc                        # C-Compiler
CFLAGS  = -Wall -Wextra -std=c11     # Compiler-Flags
LDFLAGS = -lm                        # Linker-Flags (Libraries)
 
# Dateien
TARGET  = programm                   # Name des Zielprogramms
SRCS    = main.c rechner.c statistik.c ausgabe.c   # alle .c Dateien
OBJS    = main.o rechner.o statistik.o ausgabe.o   # alle .o Dateien
```

### 1.7.3. Häufig verwendete Compiler-Flags

| Flag       | Bedeutung                               |
| ---------- | --------------------------------------- |
| `-Wall`    | Alle Warnungen aktivieren               |
| `-Wextra`  | Zusätzliche Warnungen                   |
| `-std=c11` | C11-Standard verwenden                  |
| `-g`       | Debug-Informationen einbetten (für gdb) |
| `-O2`      | Optimierung Stufe 2 (Release-Build)     |
| `-o name`  | Name der Ausgabedatei                   |
| `-c`       | Nur kompilieren, nicht linken           |
| `-lm`      | Math-Bibliothek linken                  |
| `-I pfad`  | Suchpfad für Header-Dateien             |

### 1.7.4. Automatische Variablen

Make kennt besondere **automatische Variablen**, die in recipe-Zeilen verwendet werden:

| **Variable** | **Bedeutung**              | **Beispiel**           |
| ------------ | -------------------------- | ---------------------- |
| `$@`         | Name des aktuellen Targets | `programm`             |
| `$<`         | Erste Dependency           | `main.c`               |
| `$^`         | Alle Dependencies          | `main.o rechner.o ...` |

```makefile
# Mit automatischen Variablen – kürzer und generischer:
programm: main.o rechner.o statistik.o
    $(CC) $^ -o $@ $(LDFLAGS)
#          ^^    ^^
#          alle  Target-Name
#          .o's
 
main.o: main.c main.h
    $(CC) $(CFLAGS) -c $< -o $@
#                      ^^
#                      erste Dep = main.c
```

---

## 1.8. Phony Targets

Nicht jedes Target erzeugt eine Datei. **Phony Targets** sind Befehle, die immer ausgeführt werden – unabhängig davon, ob eine gleichnamige Datei existiert.

```makefile
.PHONY: clean all help test
 
clean:
    rm -f $(OBJS) $(TARGET)
 
all: $(TARGET)
 
help:
    @echo "Verfügbare Targets:"
    @echo "  make         - Programm kompilieren"
    @echo "  make clean   - Objektdateien und Programm löschen"
    @echo "  make help    - Diese Hilfe anzeigen"
```

> Das `@` vor einem Befehl unterdrückt die Ausgabe des Befehls selbst – nur die Ausgabe des Befehls erscheint, nicht der Befehl.

```bash
$ make help
Verfügbare Targets:
  make         - Programm kompilieren
  make clean   - Objektdateien und Programm löschen
  make help    - Diese Hilfe anzeigen
```

> Warum `.PHONY` wichtig ist: Existiert zufällig eine Datei namens `clean` im Verzeichnis, würde `make clean` ohne `.PHONY` sagen: *"clean ist up to date"* – und nichts tun. Mit `.PHONY` wird das Target immer ausgeführt.

---

## 1.9. Vollständiges Makefile für ein Mehrfachdatei-Projekt

### 1.9.1. Projektstruktur

```bash
mein_projekt/
├── Makefile
├── main.c
├── rechner.h
├── rechner.c
├── statistik.h
├── statistik.c
├── ausgabe.h
└── ausgabe.c
```

### 1.9.2. Das vollständige Makefile

```makefile
# ============================================================
# Makefile – Programmiertechnik Demo-Projekt
# ============================================================
 
# --- Konfiguration (hier anpassen) --------------------------
CC      = gcc
CFLAGS  = -Wall -Wextra -std=c11 -g
LDFLAGS = -lm
TARGET  = programm
 
# --- Dateien -------------------------------------------------
SRCS = main.c rechner.c statistik.c ausgabe.c
OBJS = $(SRCS:.c=.o)        # ersetzt alle .c durch .o automatisch
 
# --- Standard-Target (erstes Target = Standard) -------------
all: $(TARGET)
 
# --- Programm linken ----------------------------------------
$(TARGET): $(OBJS)
    $(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)
    @echo ">>> $(TARGET) erfolgreich erstellt."
 
# --- Einzelne Object-Dateien kompilieren --------------------
main.o: main.c rechner.h statistik.h ausgabe.h
    $(CC) $(CFLAGS) -c main.c -o main.o
 
rechner.o: rechner.c rechner.h
    $(CC) $(CFLAGS) -c rechner.c -o rechner.o
 
statistik.o: statistik.c statistik.h
    $(CC) $(CFLAGS) -c statistik.c -o statistik.o
 
ausgabe.o: ausgabe.c ausgabe.h
    $(CC) $(CFLAGS) -c ausgabe.c -o ausgabe.o
 
# --- Aufräumen ----------------------------------------------
clean:
    rm -f $(OBJS) $(TARGET)
    @echo ">>> Aufgeräumt."
 
# --- Rebuild: sauber neu kompilieren ------------------------
rebuild: clean all
 
# --- Hilfe --------------------------------------------------
help:
    @echo "========================================"
    @echo "  Makefile – Verfügbare Targets"
    @echo "========================================"
    @echo "  make         - Programm kompilieren"
    @echo "  make clean   - Aufräumen"
    @echo "  make rebuild - Sauber neu kompilieren"
    @echo "  make help    - Diese Hilfe anzeigen"
    @echo "========================================"
 
# --- Phony Targets deklarieren ------------------------------
.PHONY: all clean rebuild help
```

### 1.9.3. Ablauf beim ersten `make`

```bash
$ make
gcc -Wall -Wextra -std=c11 -g -c main.c -o main.o
gcc -Wall -Wextra -std=c11 -g -c rechner.c -o rechner.o
gcc -Wall -Wextra -std=c11 -g -c statistik.c -o statistik.o
gcc -Wall -Wextra -std=c11 -g -c ausgabe.c -o ausgabe.o
gcc main.o rechner.o statistik.o ausgabe.o -o programm -lm
>>> programm erfolgreich erstellt.
```

### 1.9.4. Ablauf nach Änderung in `rechner.c`

```bash
$ # nur rechner.c wurde geändert
$ make
gcc -Wall -Wextra -std=c11 -g -c rechner.c -o rechner.o   ← nur diese Datei
gcc main.o rechner.o statistik.o ausgabe.o -o programm -lm ← neu linken
>>> programm erfolgreich erstellt.
```

---

## 1.10. Erweiterte Möglichkeiten

### 1.10.1. Generische Regel mit Muster (`%`)

Statt für jede `.c`-Datei eine eigene Regel zu schreiben, kann man eine **Musterregel** verwenden:

```makefile
# Musterregel: jede .o-Datei wird aus der gleichnamigen .c-Datei erzeugt
%.o: %.c
   $(CC) $(CFLAGS) -c $< -o $@
 
# Damit entfallen alle einzelnen .o-Regeln!
# Nachteil: Header-Abhängigkeiten müssen separat gepflegt werden
```

### 1.10.2. Debug- vs. Release-Build

```makefile
# Debug-Build (mit Debug-Symbolen, ohne Optimierung)
debug: CFLAGS += -g -DDEBUG
debug: $(TARGET)
 
# Release-Build (optimiert, ohne Debug-Symbole)
release: CFLAGS = -O2 -std=c11 -Wall
release: $(TARGET)
```

```bash
make debug    # kompiliert mit -g -DDEBUG
make release  # kompiliert mit -O2
```

### 1.10.3. Bedingte Ausgabe mit `@`

```makefile
$(TARGET): $(OBJS)
    @echo "Linke $(TARGET)..."
    @$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)
    @echo "Fertig!"
```

```bash
$ make
Linke programm...
Fertig!
# Die gcc-Befehle selbst werden nicht angezeigt
```

### 1.10.4. Mehrere Ausgabeprogramme

```makefile
all: server client tools
 
server: server_main.o netzwerk.o protokoll.o
    $(CC) $^ -o server
 
client: client_main.o netzwerk.o ui.o
    $(CC) $^ -o client
 
tools: tools_main.o utils.o
    $(CC) $^ -o tools
```

### 1.10.5. Automatische Abhängigkeitserkennung

```makefile
# gcc kann automatisch Abhängigkeiten von Header-Dateien erkennen
# und .d-Dateien erzeugen (fortgeschritten, für grössere Projekte)
DEPS = $(OBJS:.o=.d)
 
-include $(DEPS)
 
%.o: %.c
    $(CC) $(CFLAGS) -MMD -MP -c $< -o $@
```

---

## 1.11. Häufige Fehler und deren Lösung

| **Fehler**                        | **Ursache**                             | **Lösung**                                        |
| --------------------------------- | --------------------------------------- | ------------------------------------------------- |
| `missing separator`               | Leerzeichen statt Tab vor recipe        | Tab-Taste verwenden                               |
| `Nothing to be done`              | Alle Targets aktuell                    | Normal – kein Fehler                              |
| `No rule to make target`          | Datei fehlt oder Tippfehler             | Dateinamen prüfen                                 |
| `undefined reference to`          | Linker findet Funktion nicht            | `.c`-Datei in SRCS ergänzen oder `-l`-Flag prüfen |
| Header-Änderung hat keinen Effekt | Header nicht als Dependency eingetragen | `.h` zu den Dependencies hinzufügen               |

---

## 1.12. Zusammenfassung

```console
┌──────────────────────────────────────────────────────────────────┐
│                    Makefile – Übersicht                          │
├────────────────────────┬─────────────────────────────────────────┤
│ Dateiname              │ Makefile  (im Projektverzeichnis)       │
│ Grundstruktur          │ target: deps / TAB recipe               │
│ Einrückung             │ Zwingend TAB – kein Leerzeichen!        │
│ Variablen              │ CC, CFLAGS, LDFLAGS, TARGET, SRCS, OBJS │
│ Automatisch            │ $@ = Target, $< = 1. Dep, $^ = alle Dep │
│ Phony Targets          │ .PHONY: clean all rebuild help           │
│ Kompilierungsschritte  │ .c → .o  (gcc -c)  →  Programm (linken)│
│ Zeitstempel-Prüfung    │ Nur geänderte Dateien werden neu gebaut │
│ Musterregel            │ %.o: %.c → generisch für alle Module    │
│ Aufrufen               │ make / make clean / make rebuild         │
└────────────────────────┴─────────────────────────────────────────┘
```

### 1.12.1. Die goldene Regel

> **Nie wieder manuell kompilieren.**
> Was einmal in einem Makefile steht, ist dokumentiert, reproduzierbar und für alle Teammitglieder identisch. Ein sauberes Makefile gehört zu jedem professionellen C-Projekt wie die `.h`-Dateien selbst.

---

</br>

# 2. Aufgaben

## 2.1. Makefile für Trennstrich-Modul

| **Vorgabe**         | **Beschreibung**                                        |
| :------------------ | :------------------------------------------------------ |
| **Lernziele**       | Kennt die Möglichkeiten des Makefiles Buildprozesses    |
|                     | Kann ein einfaches Makefile erstellen                   |
|                     | Kann die Programmerstellung über ein Makefile ausführen |
| **Sozialform**      | Einzelarbeit                                            |
| **Auftrag**         | siehe unten                                             |
| **Hilfsmittel**     |                                                         |
| **Zeitbedarf**      | 30min                                                   |
| **Lösungselemente** | Funktionierendes Programm                               |

In vorheriger Aufgabe zur Modularisierung wurde eine Trennstrichfunktion in eine separate Datei ausgelagert.
Schreibe nun ein Makefile, welches das Hauptprogramm (main) und die `func.c` Datei zusammen erstellt.

---

© 2026 Lukas Müller – Licensed under CC BY-NC-ND 4.0
See [LICENSE](../license.md) file for details.
