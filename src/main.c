#include "pseudoku.h"
#include <stdio.h>
#include <time.h>

int main()
{

  int Puzzle[9][9];
  int Answer[9][9];
  int Seed = time(0);

  pseudokugen(Puzzle, Seed);
  pseudokugen(Answer, Seed);
  pseudokudel(Puzzle, Seed, 20);

  guiwrapper(Puzzle, Answer, Seed);


  return 0;
}
