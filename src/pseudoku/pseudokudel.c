#include <stdio.h>
#include <stdlib.h>

void pseudokudel(int Puzzle[9][9], int Seed, int Difficulty)
{

  srand(Seed);

  int X = rand() % 9;
  int Y = rand() % 9;

  // The following block of code will replace a random entry of the
  // puzzle array as many times as the integer, Difficulty, insists.
  for(int i = 0; i < Difficulty; i++)
    {

      // This loop will repeat until a non-zero entry is found.
      while(Puzzle[Y][X] == 0)
        {
          X = rand() % 9;
          Y = rand() % 9;
        }

      // When found, the entry is set to zero, and a new random entry is set.
      Puzzle[Y][X] = 0;

      X = rand() % 9;
      Y = rand() % 9;

    }

  return;
}
