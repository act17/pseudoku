#include <stdio.h>
#include <stdlib.h>

int pseudokucmp(int Puzzle[9][9], int Answer[9][9], int Wrong[9][9]) {

  int IncorrectEntries = 0;

  for(int y = 0; y < 9; y++) {
    for(int x = 0; x < 9; x++) {
      if(Puzzle[y][x] != Answer[y][x]) {
        IncorrectEntries++;
        // I feel so sinful nesting another if statement in here.
        // But it's just the simplest way to achieve this.
        if(Puzzle[y][x] != 0)
          Wrong[y][x] = 1;
      }
      else
        Wrong[y][x] = 0;
    }
  }

  return IncorrectEntries;
}
