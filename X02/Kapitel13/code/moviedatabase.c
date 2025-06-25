#include <stdio.h>

struct Movie {
  char        name[50];
  int         dauer;
  const char* tags[10];
};

void printMovie(const struct Movie* movie) {
  printf("\"%s\", ", movie->name);
  printf("%d Minuten\nTags:\n", movie->dauer);

  int tagindex = 0;
  while (movie->tags[tagindex]) {
    printf("\"%s\"\n", movie->tags[tagindex]);
    ++tagindex;
  }
  
  printf("\n");
}

int main(void) {
  struct Movie film1 = {
    "Lion King",
    85,
    {"Simba", "Circle of Life"}
  };
  struct Movie film2 = {
    "Terminator 2",
    147,
    {"Bad to the bone", "T-1000", "Hasta la vista"}
  };

  printMovie(&film1);
  printMovie(&film2);
  return 0;
}
