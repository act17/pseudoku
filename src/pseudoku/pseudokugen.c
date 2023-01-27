#include <stdio.h>
#include <stdlib.h>

/*
 * ACT's Sudoku Generator
 * Version Alpha 0.1.0
 *
 * This function must have a 9x9 multidimensional array
 * passed into it. It will proceed to generate a series of 9
 * integers from 1 through 9 inclusive that does not repeat
 * in the vertical rows, horizontal columns, or within a 3x3
 * area.
 *
 * It must also have a random seed passed into it; usually that
 * of the time (Seconds from January 1st, 1970) the puzzle was created.
 *
 */

void pseudokugen(int Puzzle[9][9], int Seed)
{

  srand(Seed);

  // First step is to generate two arrays; the first
  // is the actually "Seen-by-the-user" series of numbers.
  // The second, on the other hand, is an "offset" that
  // shifts each of the 9 rows.

  int InitialSeries[9];
  int RowOffset[9];
  int OverlapCheck = 0;
  int OffsetOverflowCheck = 0;

  // This is simply done as a workaround for my bad algorithm skills.
  InitialSeries[0] = rand() % 9 + 1;
  RowOffset[0] = rand() % 9;

  // This for loop will scan through each of the elements (past the first)
  // in InitialSeries, and replace them with a randomly generated number.
  // Before moving onto the next element of the array, however, it will check
  // all the series before it to see if the number has already been generated.
  for (int i = 1; i < 9; i++)
  {

    // This while-loop will continue until an original number is found.
    while (OverlapCheck < i)
    {

      // This generates a new random number from 1 through 9, inclusive.
      InitialSeries[i] = rand() % 9 + 1;

      // This goes through all the elements filled sofar.
      for (int j = 0; j < i; j++)
      {

        // If they aren't equal, we signal that the number is original.
        if (InitialSeries[i] != InitialSeries[j])
          OverlapCheck++;

        // If one unoriginal element is found, however, the program is
        // instructed to generate a new number and reset the original counter
        // (OverlapCheck)
        else
          OverlapCheck = 0;
      }
    }

    // Once an original number is found, the original counter is reset.
    OverlapCheck = 0;
  }

  // The following is exactly the same process as above - but with a few things
  // switched around to simply generate 0 through 8 inclusive on a different
  // array. Extra commenting has been removed to compress the block of code.
  for (int i = 1; i < 9; i++)
  {
    while (OverlapCheck < i)
    {
      RowOffset[i] = rand() % 9;
      for (int j = 0; j < i; j++)
      {
        if (RowOffset[i] != RowOffset[j])
          OverlapCheck++;
        else
          OverlapCheck = 0;
      }
    }
    OverlapCheck = 0;
  }

  // The next step is to write to the initially passed MD Array Puzzle.
  // This process writes all the elements of InitialArray to Puzzle - using
  // the randomly generated numbers of RowOffset as, obviously, an offset.
  // This creates a pseudorandomly generated Sudoku puzzle - without the
  // 3x3 tiles being fixed.
  for (int y = 0; y < 9; y++)
  {

    // First we set the offset for this row by using the RowOffset array.
    OffsetOverflowCheck = RowOffset[y];

    for (int x = 0; x < 9; x++)
    {

      // Then we write to the Puzzle that the current element of
      // the current row is equal to our initial combination, plus the
      // offset.
      Puzzle[y][x] = InitialSeries[OffsetOverflowCheck];

      // In the case that we have reached the end of the array (8),
      // we reset the offset to zero.
      if (OffsetOverflowCheck == 8)
        OffsetOverflowCheck = 0;

      // Otherwise, we add one to the offset.
      else
        OffsetOverflowCheck++;
    }
  }

  return;
}
