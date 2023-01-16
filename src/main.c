#include "pseudoku.h"
#include <stdio.h>
#include <time.h>

int main() {

  int Puzzle[9][9];
  pseudokugen(Puzzle, time(0));

  for (int y = 0; y < 9; y++) {
    printf("\n");
    for (int x = 0; x < 9; x++) {
      printf("%d ", Puzzle[y][x]);
    }
  }

  return 0;
}
