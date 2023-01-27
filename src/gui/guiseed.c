#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

void guiseed(int MaxY, int MaxX, int Options[3]) {

  WINDOW * MainWin = newwin(36,72,MaxY,MaxX);
  int UserChoice = 0;
  int SeedBuffer = 0;
  int SeedEntryCheck = 0;

  echo();

  init_pair(1,COLOR_CYAN,COLOR_CYAN);
  init_pair(2,COLOR_BLACK,COLOR_WHITE);

  box(MainWin,0,0);
  wbkgd(stdscr,COLOR_PAIR(1));
  wbkgd(MainWin,COLOR_PAIR(2));
  wattron(MainWin,COLOR_PAIR(2));
  keypad(MainWin,TRUE);

  wattron(MainWin,A_BOLD);
  mvwprintw(MainWin,1,28,"SEED SELECTION:");
  wattroff(MainWin,A_BOLD);

  mvwprintw(MainWin, 33, 1, "Press ENTER to begin entering the seed. Press ENTER again to confirm.");
  mvwprintw(MainWin, 34, 1, "Press the 'T' Key to select the current time as the seed.");
  mvwprintw(MainWin, 3, 1, "Seed:");

  refresh();
  wrefresh(MainWin);
  wrefresh(stdscr);

  while (SeedEntryCheck == 0) {

    UserChoice = wgetch(MainWin);
    switch(UserChoice) {

    case 't':
      SeedBuffer = time(0);
      SeedEntryCheck++;
      break;

    case 10:
      echo();
      mvwscanw(MainWin,3,6,"%d",&SeedBuffer);
      SeedEntryCheck++;
      break;

    default:
      break;
    }

  }

  Options[0] = SeedBuffer;

  return;
}
