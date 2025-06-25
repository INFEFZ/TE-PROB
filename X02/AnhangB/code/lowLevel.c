// MSVC meldet fuer veraltete, unsichere C-Funktionen wie
// die low-level-Dateizugriffsfunktionen einen Fehler.
// Mittels folgender Zeile koennen diese Fehler ausgeschaltet werden:
#define _CRT_SECURE_NO_WARNINGS

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>

#ifdef _WIN32
  #include <io.h>
  #include <windows.h>
  #define CREATE_MODE _S_IWRITE
#else
  #include <unistd.h>
  #define CREATE_MODE S_IWUSR | S_IRUSR
#endif

#define SRC_FILE "source.dat"
#define DST_FILE "dest.dat"

int main(void) {
  int source_fd;
  int dest_fd;

  struct adresse {
    char name[30];
    char ort[30];
    char strasse[30];
    long plz;
  } adr;
  
  const int dataSize = sizeof(struct adresse);

  // Quelldatei oeffnen.
  if ((source_fd = open(SRC_FILE, O_RDONLY)) < 0) {
    printf("Fehler beim Oeffnen der source-Datei\n");
    return 1;
  }

  // Zieldatei erstellen.
  if ((dest_fd = creat(DST_FILE, CREATE_MODE)) < 0) {
    printf("Fehler beim Erstellen der dest-Datei\n");
    return 1;
  }

  // Ausrechnen, wieviele Adressen sich in der Datei befinden.
  off_t size = lseek(source_fd, 0, SEEK_END);
  int zaehler = (int)size / dataSize;

  // Rueckwaerts durch die Datei gehen und die Adressen auslesen.
  for (int i = zaehler - 1; i >= 0; --i) {
    if (lseek(source_fd, i * dataSize, SEEK_SET) < 0) {
       printf("Fehler beim Positionieren in der source-Datei\n");
       return 1;
    }

    // Daten aus Quelldatei auslesen
    if (read(source_fd, &adr, dataSize) < 0) {
       printf("Fehler beim Lesen aus der source-Datei\n");
       return 1;
    }

    // Daten in Zielatei eintragen
    if (write(dest_fd, &adr, dataSize) < dataSize) {
      printf("Fehler beim Schreiben in die dest-Datei\n");
      return 1;
    }
  }

  // Schliessen der geoeffneten Dateien
  if (close(source_fd) < 0) {
    printf("Fehler beim Schliessen der source-Datei\n");
    return 1;
  }

  if (close(dest_fd) < 0) {
    printf("Fehler beim Schliessen der dest-Datei\n");
    return 1;
  }
  
  return 0;
}
