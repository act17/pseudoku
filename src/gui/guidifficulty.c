#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

void guidifficulty(int MaxY, int MaxX, int Options[3]) {

  WINDOW * MainWin = newwin(36,72,MaxY,MaxX);
  char DifficultyOptionsChar[3][15] = {"Easy","Medium","Hard"};
  char EasyClassicChar[2][24] = {"OFF (Classic)","ON (Easy)"};
  int EasyClassicSwitch = 0;
  int DifficultyOptionsInt[3] = {10,20,30};
  int Highlight = 0;
  int UserChoice = 0;

  noecho();

  init_pair(1,COLOR_CYAN,COLOR_CYAN);
  init_pair(2,COLOR_BLACK,COLOR_WHITE);

  box(MainWin,0,0);
  wbkgd(stdscr,COLOR_PAIR(1));
  wbkgd(MainWin,COLOR_PAIR(2));
  wattron(MainWin,COLOR_PAIR(2));
  keypad(MainWin,TRUE);

  wattron(MainWin,A_BOLD);
  mvwprintw(MainWin,1,25,"DIFFICULTY SELECTION:");
  wattroff(MainWin,A_BOLD);

  mvwprintw(MainWin, 33, 1, "Use the UP/DOWN and ENTER keys to select a difficulty.");
  mvwprintw(MainWin, 34, 1, "Press the 'E' Key to Enable/Disable Easy Mode");

  do {

    for(int i = 0; i < 3; i++) {
      if(i == Highlight)
        wattron(MainWin,A_REVERSE);
      mvwprintw(MainWin,i + 3,1,"%s",DifficultyOptionsChar[i]);
      mvwprintw(MainWin,i + 3,69,"%d",DifficultyOptionsInt[i]);
      wattroff(MainWin,A_REVERSE);
    }

    mvwprintw(MainWin,7,1,"Easy mode is:");
    if(EasyClassicSwitch == 1)
      wattron(MainWin,A_REVERSE);
    mvwprintw(MainWin,7,15,"%s        ",EasyClassicChar[EasyClassicSwitch]);
    wattroff(MainWin,A_REVERSE);

    refresh();
    wrefresh(MainWin);
    wrefresh(stdscr);

    UserChoice = wgetch(MainWin);
    switch(UserChoice) {

    case KEY_UP:
      if(Highlight == 0)
        break;
      Highlight--;
      break;

    case KEY_DOWN:
      if(Highlight == 2)
        break;
      Highlight++;
      break;

    case 'e':
      if(EasyClassicSwitch == 0)
        EasyClassicSwitch = 1;
      else
        EasyClassicSwitch = 0;
      break;

    case 10:
      break;

    }

  } while (UserChoice != 10);

  Options[1] = DifficultyOptionsInt[Highlight];
  Options[2] = EasyClassicSwitch;

  return;
}
