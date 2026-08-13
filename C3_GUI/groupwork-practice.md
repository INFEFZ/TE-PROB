|                             |                          |                               |
| --------------------------- | ------------------------ | ----------------------------- |
| **Elektrotechniker/-in HF** | **Programmiertechnik B** | ![logo](../x_gitres/logo.png) |

</br>

# Gruppenarbeit WPF-Oberflächen mit C\#

| **Vorgabe**         | **Beschreibung**                                                                                      |
| :------------------ | :---------------------------------------------------------------------------------------------------- |
| **Lernziele**       | Die .NET-Entwicklungsumgebung (SDK, VS Code, C# Dev Kit) einrichten und verifizieren                  |
|                     | Ein WPF-Projekt mit dotnet new wpf erstellen, mit dotnet build kompilieren und mit dotnet run starten |
|                     | Den Unterschied zwischen XAML (Oberfläche) und Code-Behind (Logik) erklären                           |
|                     | Eine WPF-Oberfläche mit Label, TextBox, Button, ListBox und ComboBox in XAML erstellen                |
|                     | Eventhandler für Benutzerinteraktionen (z.B. Click) implementieren                                    |
|                     | Eingaben validieren und Fehler ohne Programmabsturz behandeln (TryParse)                              |
| **Sozialform**      | Gruppenarbeit: 2-3 Personen                                                                           |
| **Auftrag**         | siehe unten                                                                                           |
| **Hilfsmittel**     |                                                                                                       |
| **Zeitbedarf**      | 60min                                                                                                 |
| **Lösungselemente** | Abgabe: Alle Dateien (.h und .c) als Gesamtprojekt                                                    |
|                     | Funktionierendes Programm und Präsentation (Code erklären), ca. 5 min.                                |
|                     | Jedes Gruppenmitglied muss Teile des Codes erklären können                                            |

> ## Hinweis zum KI-Einsatz
>
> Eine WPF-Oberfläche mit ein paar Eventhandlern ist für KI-Tools eine triviale
> Aufgabe. Genau deshalb zählt bei dieser Präsentation **nicht nur**, dass die
> Anwendung läuft, sondern dass ihr sie **live bedienen, erweitern und erklären**
> könnt. Jedes Mitglied wird einzeln gefragt:
>
> - *„Klick mal auf diesen Button – was passiert im Code, Zeile für Zeile?"*
> - *„Wie heisst dieses Textfeld im XAML, und wie greifst du im Code-Behind darauf zu?"*
> - *„Ich gebe jetzt absichtlich nichts/Unsinn ein und klicke trotzdem – was passiert? Sollte das so sein?"*
> - *„Füge live einen weiteren Button mit einer neuen Funktion hinzu."*
> - *„Was ist der Unterschied zwischen `Content` und `Text` bei euren Elementen?"*
>
> Wer die eigene Oberfläche nicht live bedienen und erweitern kann, hat sie
> nicht verstanden – unabhängig davon, wie professionell sie aussieht.

---

</br>

## Gruppenarbeit A – «Temperaturumrechner mit Verlauf»

**Szenario:**

- Ihr entwickelt eine WPF-Anwendung, die Celsius in Fahrenheit und Kelvin umrechnet und dabei alle bisherigen Umrechnungen in einer Liste protokolliert.

**Anforderungen:**

**Projekt erstellen:**

```bash
dotnet new wpf -n Temperaturumrechner
cd Temperaturumrechner
```

**Geforderte Oberflächenelemente (`MainWindow.xaml`):**

| Element   | `x:Name`                | Zweck                              |
| --------- | ----------------------- | ---------------------------------- |
| `Label`   | –                       | Beschriftung „Temperatur in °C:"   |
| `TextBox` | `CelsiusTextBox`        | Eingabe der Celsius-Zahl           |
| `Button`  | `UmrechnenButton`       | Löst die Umrechnung aus            |
| `Label`   | `FahrenheitLabel`       | Zeigt das Ergebnis in Fahrenheit   |
| `Label`   | `KelvinLabel`           | Zeigt das Ergebnis in Kelvin       |
| `ListBox` | `VerlaufListBox`        | Zeigt alle bisherigen Umrechnungen |
| `Button`  | `VerlaufLoeschenButton` | Leert die Verlaufsliste            |

**Geforderte Logik (`MainWindow.xaml.cs`):**

```csharp
private void UmrechnenButton_Click(object sender, RoutedEventArgs e)
{
    // 1. Text aus CelsiusTextBox auslesen
    // 2. In double umwandeln (double.TryParse verwenden - NICHT Convert.ToDouble!)
    // 3. Bei ungueltiger Eingabe: Fehlermeldung anzeigen, NICHT abstuerzen
    // 4. Fahrenheit und Kelvin berechnen
    // 5. Ergebnisse in den Labels anzeigen
    // 6. Eintrag zum Verlauf hinzufuegen (Format: "20.0 C -> 68.0 F, 293.15 K")
}

private void VerlaufLoeschenButton_Click(object sender, RoutedEventArgs e)
{
    // Verlaufsliste leeren
}
```

**Wichtiger Hinweis zu `double.TryParse`:**

```csharp
if (double.TryParse(CelsiusTextBox.Text, out double celsius))
{
    // Umwandlung war erfolgreich, celsius enthaelt den Wert
}
else
{
    FahrenheitLabel.Content = "Ungueltige Eingabe!";
}
```

> **Warum `TryParse` statt `Convert.ToDouble`?** `TryParse` gibt `true`/`false`
> zurück und wirft **keine Exception** bei ungültiger Eingabe – das Programm
> stürzt nicht ab, wenn der Benutzer z.B. Buchstaben eingibt.

**Pflichtanforderungen:**

- [ ] Alle Elemente aus der Tabelle vorhanden und korrekt benannt (`x:Name`)
- [ ] `double.TryParse` korrekt verwendet (kein Absturz bei Buchstaben-Eingabe)
- [ ] Fahrenheit-Formel: `F = C * 1.8 + 32`
- [ ] Kelvin-Formel: `K = C + 273.15`
- [ ] Jede erfolgreiche Umrechnung wird dem Verlauf hinzugefügt
- [ ] `VerlaufLoeschenButton` leert die `ListBox` vollständig
- [ ] Layout ist sauber mit `Grid` oder `StackPanel` strukturiert (keine überlappenden Elemente)

**Präsentationsfragen:**

1. Gebt live `"abc"` in das Textfeld ein und klickt auf „Umrechnen" – was passiert? Zeigt die Stelle im Code, die das behandelt.
2. Erklärt `double.TryParse` – was bedeuten die zwei Teile nach `out`?
3. Zeigt die Zeile, die einen neuen Eintrag zur `ListBox` hinzufügt – wie ist der Text zusammengesetzt (`$"..."`-Syntax)?
4. Fügt **live** ein drittes Eingabefeld hinzu, das die Umrechnung **umgekehrt** macht (Fahrenheit → Celsius) – mit einem zweiten Button.
5. Was ist der Unterschied zwischen `CelsiusTextBox.Text` (string) und der Variable `celsius` (double) in eurem Code?

---

</br>

## Gruppenarbeit B – «Notizverwaltung mit Auswahl und Löschen»

**Szenario:**

Ihr entwickelt eine kleine Notizverwaltung: Notizen können hinzugefügt, in einer Liste angezeigt, ausgewählt und gelöscht werden. Die ausgewählte Notiz wird in einem grossen Textfeld zur Anzeige/Bearbeitung dargestellt.

**Anforderungen:**

**Projekt erstellen:**

```bash
dotnet new wpf -n Notizverwaltung
cd Notizverwaltung
```

**Geforderte Oberflächenelemente:**

| Element   | `x:Name`            | Zweck                                                       |
| --------- | ------------------- | ----------------------------------------------------------- |
| `TextBox` | `TitelTextBox`      | Titel der neuen Notiz                                       |
| `TextBox` | `InhaltTextBox`     | Inhalt der neuen Notiz (mehrzeilig, `AcceptsReturn="True"`) |
| `Button`  | `HinzufuegenButton` | Fügt die Notiz zur Liste hinzu                              |
| `ListBox` | `NotizenListBox`    | Zeigt alle Notiz-Titel                                      |
| `Label`   | `DetailLabel`       | Zeigt den Inhalt der ausgewählten Notiz                     |
| `Button`  | `LoeschenButton`    | Löscht die ausgewählte Notiz                                |
| `Label`   | `AnzahlLabel`       | Zeigt „X Notizen vorhanden"                                 |

**Wichtiger Hinweis – eigene Klasse für eine Notiz:**

```csharp
public class Notiz
{
    public string Titel { get; set; }
    public string Inhalt { get; set; }

    public override string ToString()
    {
        return Titel;   // WICHTIG: bestimmt, was die ListBox anzeigt!
    }
}
```

> **Warum `ToString()` überschreiben?** Wenn man Objekte vom Typ `Notiz`
> direkt in eine `ListBox` einfügt (`NotizenListBox.Items.Add(neueNotiz)`),
> zeigt WPF standardmässig nur `Notizverwaltung.Notiz` an. Durch das
> Überschreiben von `ToString()` wird stattdessen der Titel angezeigt.

**Geforderte Logik:**

```csharp
private List<Notiz> notizen = new List<Notiz>();   // interne Datenhaltung

private void HinzufuegenButton_Click(object sender, RoutedEventArgs e)
{
    // 1. Pruefen: Titel darf nicht leer sein
    // 2. Neue Notiz erstellen, zur Liste UND zur ListBox hinzufuegen
    // 3. Eingabefelder leeren
    // 4. AnzahlLabel aktualisieren
}

private void NotizenListBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
{
    // Wird automatisch aufgerufen, wenn eine andere Notiz ausgewaehlt wird
    // DetailLabel mit dem Inhalt der ausgewaehlten Notiz aktualisieren
}

private void LoeschenButton_Click(object sender, RoutedEventArgs e)
{
    // Ausgewaehlte Notiz aus der Liste UND der ListBox entfernen
    // AnzahlLabel aktualisieren
}
```

**`SelectionChanged` im XAML verknüpfen:**

```xml
<ListBox x:Name="NotizenListBox"
         SelectionChanged="NotizenListBox_SelectionChanged"/>
```

**Pflichtanforderungen:**

- [ ] Eigene Klasse `Notiz` mit `Titel` und `Inhalt`, `ToString()` überschrieben
- [ ] `HinzufuegenButton` verhindert leere Titel (keine leeren Einträge in der Liste)
- [ ] `SelectionChanged`-Event korrekt implementiert – Detailanzeige aktualisiert sich beim Klick auf einen Listeneintrag
- [ ] `LoeschenButton` entfernt korrekt **die ausgewählte** Notiz (nicht die erste/letzte!)
- [ ] `AnzahlLabel` ist nach jeder Änderung (Hinzufügen/Löschen) korrekt
- [ ] Mehrzeilige Eingabe im `InhaltTextBox` funktioniert (`AcceptsReturn="True"`, `TextWrapping="Wrap"`)

**Präsentationsfragen:**

1. Klickt live auf verschiedene Notizen in der Liste – woher weiss der Code, **welche** Notiz gerade ausgewählt ist?
2. Erklärt, warum `ToString()` überschrieben werden musste – was würde ohne diese Überschreibung in der `ListBox` stehen?
3. Löscht eine Notiz **aus der Mitte** der Liste – funktioniert das korrekt? Zeigt die Code-Stelle.
4. Was passiert, wenn ihr auf „Löschen" klickt, **ohne** vorher eine Notiz auszuwählen? Sollte das einen Fehler verursachen – testet es live.
5. Fügt **live** ein Feature hinzu: ein zweiter Button „Bearbeiten", der den Inhalt der ausgewählten Notiz ins `InhaltTextBox` zum Weiterbearbeiten lädt.

---

</br>

## Gruppenarbeit C – «Einfacher Taschenrechner mit Verlaufsspeicher»

**Szenario**: Ihr entwickelt einen Taschenrechner mit den vier Grundrechenarten. Jede Berechnung wird zusätzlich in einer Verlaufsliste festgehalten, die durchsucht werden kann.

**Anforderungen:**

**Projekt erstellen:**

```bash
dotnet new wpf -n Taschenrechner
cd Taschenrechner
```

**Geforderte Oberflächenelemente:**

| Element   | `x:Name`                    | Zweck                                   |
| --------- | --------------------------- | --------------------------------------- |
| `TextBox` | `ZahlATextBox`              | Erste Zahl                              |
| `TextBox` | `ZahlBTextBox`              | Zweite Zahl                             |
| `Button`  | `AddierenButton`            | Berechnet A + B                         |
| `Button`  | `SubtrahierenButton`        | Berechnet A − B                         |
| `Button`  | `MultiplizierenButton`      | Berechnet A × B                         |
| `Button`  | `DividierenButton`          | Berechnet A ÷ B (mit Fehlerbehandlung!) |
| `Label`   | `ErgebnisLabel`             | Zeigt das aktuelle Ergebnis             |
| `ListBox` | `VerlaufListBox`            | Zeigt alle bisherigen Berechnungen      |
| `TextBox` | `SucheTextBox`              | Filtert den Verlauf nach Eingabe        |
| `Button`  | `FilterAnwendenButton`      | Zeigt nur passende Verlaufseinträge     |
| `Button`  | `FilterZuruecksetzenButton` | Zeigt wieder alle Einträge              |

**Wichtiger Hinweis – gemeinsame Berechnungsmethode (Vermeidung von Code-Duplizierung):**

```csharp
private List<string> vollstaendigerVerlauf = new List<string>();

private void Berechne(string operatorSymbol, Func<double, double, double> operation)
{
    if (double.TryParse(ZahlATextBox.Text, out double a) &&
        double.TryParse(ZahlBTextBox.Text, out double b))
    {
        double ergebnis = operation(a, b);
        ErgebnisLabel.Content = ergebnis.ToString();

        string eintrag = $"{a} {operatorSymbol} {b} = {ergebnis}";
        vollstaendigerVerlauf.Add(eintrag);
        VerlaufListBox.Items.Add(eintrag);
    }
    else
    {
        ErgebnisLabel.Content = "Ungueltige Eingabe!";
    }
}

private void AddierenButton_Click(object sender, RoutedEventArgs e)
{
    Berechne("+", (x, y) => x + y);
}

private void DividierenButton_Click(object sender, RoutedEventArgs e)
{
    if (double.TryParse(ZahlBTextBox.Text, out double b) && b == 0)
    {
        ErgebnisLabel.Content = "Division durch 0 nicht moeglich!";
        return;
    }
    Berechne("/", (x, y) => x / y);
}
```

> **Warum eine gemeinsame `Berechne`-Methode?** Ohne sie müsste die
> Eingabeprüfung und Verlaufsprotokollierung in **jedem** der vier Button-Handler
> wiederholt werden – das verstösst gegen das Prinzip „Wiederholung vermeiden",
> das wir bereits bei der Modularisierung in C kennengelernt haben.

**Filterlogik (Suche im Verlauf):**

```csharp
private void FilterAnwendenButton_Click(object sender, RoutedEventArgs e)
{
    string suchbegriff = SucheTextBox.Text;
    VerlaufListBox.Items.Clear();

    foreach (string eintrag in vollstaendigerVerlauf)
    {
        if (eintrag.Contains(suchbegriff))
        {
            VerlaufListBox.Items.Add(eintrag);
        }
    }
}

private void FilterZuruecksetzenButton_Click(object sender, RoutedEventArgs e)
{
    VerlaufListBox.Items.Clear();
    foreach (string eintrag in vollstaendigerVerlauf)
    {
        VerlaufListBox.Items.Add(eintrag);
    }
}
```

**Pflichtanforderungen:**

- [ ] Alle vier Grundrechenarten funktionieren korrekt
- [ ] Division durch 0 wird **explizit abgefangen** (keine Exception, klare Fehlermeldung)
- [ ] Gemeinsame Hilfsmethode (`Berechne` o.ä.) wird verwendet – **kein** kopierter Code in den vier Button-Handlern
- [ ] `vollstaendigerVerlauf` (interne Liste) bleibt **immer vollständig** – auch wenn die `ListBox` gefiltert/zurückgesetzt wird
- [ ] Filterfunktion findet Teilstrings (z.B. Suche nach „5" findet alle Berechnungen, die irgendwo eine 5 enthalten)
- [ ] „Zurücksetzen" zeigt wieder den **vollständigen** Verlauf

**Präsentationsfragen:**

1. Erklärt die `Berechne`-Methode – was bedeutet `Func<double, double, double>` als Parametertyp? (Vergleich: erinnert das an etwas aus C?)
2. Testet die Division durch 0 live – was passiert genau, und wo im Code wird das verhindert?
3. Warum gibt es **zwei** Listen (`vollstaendigerVerlauf` und die Inhalte der `VerlaufListBox`)? Was wäre das Problem, wenn es nur die `ListBox` gäbe?
4. Filtert live nach einem Begriff, der **nichts** trifft – was zeigt die Liste dann an? Ist das gewünschtes Verhalten?
5. Fügt **live** einen fünften Operator hinzu (z.B. Potenzieren) – wie viele Zeilen Code braucht ihr dafür dank der gemeinsamen Methode?

---

</br>

## Gruppenarbeit D – «Mini-Umfragetool mit Auswertung»

**Szenario:** Ihr entwickelt ein kleines Umfragetool: Teilnehmende geben einen Namen und eine Bewertung (1–5) ein, das Tool sammelt die Antworten und zeigt eine laufende
Auswertung (Durchschnitt, Anzahl pro Bewertung) an.

**Anforderungen:**

**Projekt erstellen:**

```bash
dotnet new wpf -n Umfragetool
cd Umfragetool
```

**Geforderte Oberflächenelemente:**

| Element    | `x:Name`              | Zweck                                                     |
| ---------- | --------------------- | --------------------------------------------------------- |
| `TextBox`  | `NameTextBox`         | Name der teilnehmenden Person                             |
| `ComboBox` | `BewertungComboBox`   | Auswahl 1–5 (vorbefüllt)                                  |
| `Button`   | `AbsendenButton`      | Speichert die Bewertung                                   |
| `ListBox`  | `AntwortenListBox`    | Zeigt alle bisherigen Antworten                           |
| `Label`    | `DurchschnittLabel`   | Zeigt den aktuellen Durchschnitt                          |
| `Label`    | `AnzahlLabel`         | Zeigt die Gesamtanzahl Antworten                          |
| `Label`    | `VerteilungLabel`     | Zeigt z.B. "1Stern:0 2Stern:1 3Stern:2 4Stern:5 5Stern:3" |
| `Button`   | `ZuruecksetzenButton` | Löscht alle Antworten (mit Bestätigung!)                  |

**`ComboBox` mit Werten 1–5 vorbefüllen (im XAML):**

```xml
<ComboBox x:Name="BewertungComboBox">
    <ComboBoxItem Content="1"/>
    <ComboBoxItem Content="2"/>
    <ComboBoxItem Content="3"/>
    <ComboBoxItem Content="4"/>
    <ComboBoxItem Content="5"/>
</ComboBox>
```

**Geforderte Logik – Auswertungsstruktur:**

```csharp
public class Antwort
{
    public string Name { get; set; }
    public int Bewertung { get; set; }
}

private List<Antwort> antworten = new List<Antwort>();

private void AbsendenButton_Click(object sender, RoutedEventArgs e)
{
    // 1. Name darf nicht leer sein
    // 2. Eine Bewertung muss in der ComboBox ausgewaehlt sein (SelectedItem pruefen!)
    // 3. Antwort erstellen und zur Liste hinzufuegen
    // 4. AntwortenListBox aktualisieren
    // 5. AuswertungAktualisieren() aufrufen
    // 6. Eingabefelder zuruecksetzen
}

private void AuswertungAktualisieren()
{
    // Durchschnitt ueber alle antworten berechnen
    // Anzahl je Bewertungsstufe (1-5) zaehlen
    // DurchschnittLabel, AnzahlLabel, VerteilungLabel aktualisieren
}

private void ZuruecksetzenButton_Click(object sender, RoutedEventArgs e)
{
    // Bestaetigung einholen mit MessageBox, dann erst loeschen!
    MessageBoxResult ergebnis = MessageBox.Show(
        "Wirklich alle Antworten loeschen?", "Bestaetigung",
        MessageBoxButton.YesNo, MessageBoxImage.Warning);

    if (ergebnis == MessageBoxResult.Yes)
    {
        antworten.Clear();
        AntwortenListBox.Items.Clear();
        AuswertungAktualisieren();
    }
}
```

**Hinweis zum Auslesen der `ComboBox`:**

```csharp
if (BewertungComboBox.SelectedItem is ComboBoxItem ausgewaehlt)
{
    int bewertung = int.Parse(ausgewaehlt.Content.ToString());
    // ...
}
else
{
    // Keine Auswahl getroffen - Fehlermeldung anzeigen
}
```

### Erwartete Anzeige (Beispiel nach mehreren Eingaben)

```console
Durchschnitt: 3.67
Anzahl Antworten: 6
Verteilung: 1:0  2:1  3:2  4:2  5:1
```

**Pflichtanforderungen:**

- [ ] `ComboBox` korrekt mit fünf Werten vorbefüllt
- [ ] Fehlerbehandlung: leerer Name **und** keine ausgewählte Bewertung werden beide abgefangen
- [ ] `AuswertungAktualisieren()` als **eigene Methode**, nicht im Button-Handler dupliziert
- [ ] Durchschnitt korrekt berechnet (auf 2 Nachkommastellen formatiert)
- [ ] Verteilung zeigt alle 5 Stufen, auch wenn eine Stufe `0` Antworten hat
- [ ] `ZuruecksetzenButton` fragt **zwingend** vorher mit `MessageBox` nach Bestätigung

**Präsentationsfragen:**

1. Klickt live auf „Zurücksetzen", aber wählt „Nein" in der Bestätigung – bleiben die Daten erhalten? Zeigt die Code-Stelle, die das sicherstellt.
2. Erklärt `BewertungComboBox.SelectedItem is ComboBoxItem ausgewaehlt` – was passiert hier genau? (Pattern Matching)
3. Gebt eine Antwort ab, **ohne** eine Bewertung auszuwählen – was passiert? Sollte das einen Fehler verursachen?
4. Warum ist `AuswertungAktualisieren()` eine **eigene Methode** statt direkt im Button-Click-Code? Was wäre der Nachteil, wenn es das nicht wäre?
5. Fügt **live** eine Anforderung hinzu: Der „Absenden"-Button soll deaktiviert sein (`IsEnabled = false`), solange das Namensfeld leer ist.

---

© 2026 Lukas Müller – Licensed under CC BY-NC-ND 4.0
See [LICENSE](../license.md) file for details.
