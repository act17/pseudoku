#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

// To be updated, duh.
char Version[12] = "Alpha 1.3.0";

void guigame(int Puzzle[9][9], int Answer[9][9], int MaxY, int MaxX, int Seed) {

  // Setting up the colors:
  init_pair(1,COLOR_BLACK,COLOR_WHITE);
  init_pair(2,COLOR_CYAN,COLOR_CYAN);

  // First we create two windows; one that will display the game,
  // and one that will display extra information.
  WINDOW * MainWindow = newwin(28,72,MaxY,MaxX);
  WINDOW * InfoWindow = newwin(8,72,MaxY + 28, MaxX);

  // We apply nessicary attributes:
  wbkgd(stdscr,COLOR_PAIR(2));
  wbkgd(MainWindow,COLOR_PAIR(1));
  wbkgd(InfoWindow,COLOR_PAIR(1));
  wattron(MainWindow,COLOR_PAIR(1));
  wattron(InfoWindow,COLOR_PAIR(1));
  box(MainWindow,0,0);
  box(InfoWindow,0,0);

  // Then we print out the information:
  wattron(InfoWindow,A_BOLD);
  mvwprintw(InfoWindow,1,1,"ACT's Pseudoku	Version: %s",Version);
  mvwprintw(InfoWindow,2,1,"CONTROLS:");
  mvwprintw(InfoWindow,3,1,"UP/DOWN/LEFT/RIGHT - Move Cursor  ENTER - Choose Highlighted Square");
  mvwprintw(InfoWindow,4,1,"1-9 - Enter value  S - Export Seed.");
  mvwprintw(InfoWindow,5,1,"SEED: %d",Seed);
  wattroff(InfoWindow, A_BOLD);

  // Then we top it off with printing out the puzzle:
  for(int y = 0; y < 9; y++) {
    for(int x = 0; x < 9; x++) {
      if(Puzzle[y][x] == 0)
        mvwprintw(MainWindow,(2 * y) + 4,(4 * x) + 18," ");
      else
        mvwprintw(MainWindow,(2 * y) + 4,(4 * x) + 18,"%d",Puzzle[y][x]);
    }
  }

  // Then refresh
  refresh();
  wrefresh(MainWindow);
  wrefresh(InfoWindow);
  wrefresh(stdscr);

  getch();
  return;
}
