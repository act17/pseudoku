#include <stdio.h>
#include <ncurses.h>
#include <time.h>
#include "../pseudoku.h"

void guiwrapper(int Puzzle[9][9], int Answer[9][9], int Options[3])
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

  /* Quick Refresher on Options:
   * Options[0] = Seed
   * Options[1] = Numeric Difficulty
   * Options[2] = Classic/Easy Mode
   */
  Options[0] = time(0);

  guimainmenu(MaxY,MaxX);
  guidifficulty(MaxY,MaxX,Options);

  pseudokugen(Answer, Options[0]);
  pseudokugen(Puzzle, Options[0]);
  pseudokudel(Puzzle, Options[0], Options[1]);

  guigame(Puzzle, Answer, MaxY, MaxX, Options[0]);

  endwin();
  return;
}
