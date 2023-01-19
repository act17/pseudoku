#include <stdio.h>
#include <ncurses.h>
#include "../pseudoku.h"

void guiwrapper(int Puzzle[9][9], int Answer[9][9])
{

  // No idea how to error-handle these lmao. Gotta read up.
  // Hopefully grandpa doesn't bring out his 300-pound computer
  // that NASA used to send people to the moon in 1969.
  initscr();
  start_color();

  int MaxX,MaxY;
  getmaxyx(stdscr,MaxY,MaxX);

  // In case the screen size is too small:
  if(MaxX < 72 || MaxY < 36)
    {
      endwin();
      printf("\n\nError: Screen size too small!");
      printf("\n  Required:  Your:");
      printf("\nX 72         %d",MaxX);
      printf("\nY 36         %d",MaxY);
      return;
    }

  // If the size of the screen passes, we re-define MaxY and MaxX as
  // being the offset used by windows.
  MaxY = (MaxY - 36) / 2;
  MaxX = (MaxX - 72) / 2;

  guimainmenu(MaxY,MaxX);

  endwin();
  return;
}
