#include "stdlib.h"
#include "stdio.h"

int main(void) {
  char number[10];
  int sum = 0;
  int cumulation = 0;

  // Oeffnen der Input-Datei
  FILE* infile = fopen("input.txt", "r");
  if (infile == NULL) {
    perror("Inputdatei"); exit(1);
  }

  // Oeffnen der Output-Datei
  FILE* outfile = fopen("result.txt", "w");
  if (outfile == NULL) {
    perror("Outputdatei"); exit(1);
  }

  // Lesen der Zahlen:
  while (!feof(infile)) {
    fgets(number, 10, infile);    // Einlesen einer Zeile
    sum += atoi(number);          // Umwandeln in int
  }

  // Zuruecksetzen der Input-Datei. Auch moeglich: rewind(infile);
  fseek(infile, 0, SEEK_SET);

  // Berechnen der kumulativen Verteilfunktion
  while (!feof(infile)) {
    fgets(number, 10, infile);
    fprintf(outfile, "%f\n", (double)cumulation / sum);
    cumulation += atoi (number);
  }
  fprintf(outfile, "%f\n", 1.);

  fflush(outfile); // Nicht noetig. Einfach zur Demo.
  printf("Datei result.txt erfolgreich beschrieben.\n");

  // Schliessen der Dateien
  fclose(outfile);
  fclose(infile);

  return 0;
}
