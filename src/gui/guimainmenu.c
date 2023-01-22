#include <ncurses.h>

// Here's what we use for the version and date of release.
char VersionName[6] = "Alpha";
char VersionNumber[6] = "1.3.0";
char ReleaseDate[11] = "2023-01-21";

void guimainmenu(int MaxY, int MaxX)
{

  // We begin by defining the colors the program uses:
  init_pair(1,COLOR_BLACK,COLOR_WHITE);
  init_pair(2,COLOR_CYAN,COLOR_CYAN);

  // We then create the window and apply attributes.
  WINDOW * MainWindow = newwin(36,72,MaxY,MaxX);

  wbkgd(stdscr,COLOR_PAIR(2));
  wbkgd(MainWindow,COLOR_PAIR(1));
  wattron(MainWindow,COLOR_PAIR(1));
  box(MainWindow,0,0);

  // Then we print on our newly-created window.
  mvwprintw(MainWindow,2,29,"ACT's Pseudoku");
  mvwprintw(MainWindow,4,29,"%s %s",VersionName,VersionNumber);
  mvwprintw(MainWindow,5,29,"%s",ReleaseDate);

  mvwprintw(MainWindow,7,29,"Copyright 2023");
  mvwprintw(MainWindow,8,21,"Released under the GNU GPL 3.0");

  wattron(MainWindow,A_BOLD);
  wattron(MainWindow,A_REVERSE);

  mvwprintw(MainWindow,12,25,"PRESS ANY KEY TO START");

  // And... refresh.
  refresh();
  wrefresh(MainWindow);
  wrefresh(stdscr);

  getch();
  return;
}
