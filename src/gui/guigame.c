#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

// To be updated, duh.
char Version[11] = "Beta 1.1.0";

void guigame(int Puzzle[9][9], int Answer[9][9], int MaxY, int MaxX, int Seed) {

  // Setting up the colors:
  init_pair(1,COLOR_BLACK,COLOR_WHITE);
  init_pair(2,COLOR_CYAN,COLOR_CYAN);
  init_pair(3,COLOR_WHITE,COLOR_RED);
  init_pair(4,COLOR_BLACK,COLOR_BLUE);

  // We also need to call the four integers used for user input:
  int UserInput;
  int UserInputX = 0;
  int UserInputY = 0;
  int PuzzleBuffer = 0;

  // Then, as the final step of preparation, we need to mark down which
  // of the puzzle spaces are changable.
  int UnfilledStorage[9][9];
  for(int y = 0; y < 9; y++) {
    for(int x = 0; x < 9; x++) {
      if(Puzzle[y][x] == 0)
        UnfilledStorage[y][x] = 0;
      else
        UnfilledStorage[y][x] = 1;
    }
  }

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
  keypad(MainWindow,TRUE);

  // Then we print out the information:
  wattron(InfoWindow,A_BOLD);
  mvwprintw(InfoWindow,1,1,"ACT's Pseudoku	Version: %s",Version);
  mvwprintw(InfoWindow,2,1,"CONTROLS:");
  mvwprintw(InfoWindow,3,1,"UP/DOWN/LEFT/RIGHT - Move Cursor  ENTER - Choose Highlighted Square");
  mvwprintw(InfoWindow,4,1,"1-9 - Enter value  S - Export Seed.");
  mvwprintw(InfoWindow,5,1,"SEED: %d",Seed);
  wattroff(InfoWindow, A_BOLD);

  // Now we have to do I/O.
  while(1) {

    // We print out the current puzzle.
    for(int y = 0; y < 9; y++) {
      for(int x = 0; x < 9; x++) {

        // In the case that we're printing the "selected" element,
        // we print in reverse.
        if(y == UserInputY && x == UserInputX)
          wattron(MainWindow,A_REVERSE);

        // In the case that the element was originally unfilled,
        // we print in blue.
        if(UnfilledStorage[y][x] == 0)
          wattron(MainWindow,COLOR_PAIR(4));

        if(Puzzle[y][x] == 0)
          mvwprintw(MainWindow,(2 * y) + 4,(4 * x) + 18," ");
        else
          mvwprintw(MainWindow,(2 * y) + 4,(4 * x) + 18,"%d",Puzzle[y][x]);

        // This is to undo any potential attribute changes made above.
        wattroff(MainWindow,A_REVERSE);
        wattron(MainWindow,COLOR_PAIR(1));
      }
    }

    // Then refresh
    refresh();
    wrefresh(MainWindow);
    wrefresh(InfoWindow);
    wrefresh(stdscr);

    // Now we must take the input of the user:
    UserInput = wgetch(MainWindow);

    switch(UserInput) {

    case KEY_UP:
      if(UserInputY == 0)
        break;
      UserInputY--;
      break;

    case KEY_DOWN:
      if(UserInputY == 8)
        break;
      UserInputY++;
      break;

    case KEY_RIGHT:
      if(UserInputX == 8)
        break;
      UserInputX++;
      break;

    case KEY_LEFT:
      if(UserInputX == 0)
        break;
      UserInputX--;
      break;

    // In the case the user presses ENTER:
    case 10:
      // First, we check to see if the entry was one of the originally unfilled entries.
      if(UnfilledStorage[UserInputY][UserInputX] == 0) {
        echo();
        // This loop will repeat until the user enters a valid input.
        do {
          mvwscanw(MainWindow,(2 * UserInputY) + 4,(4 * UserInputX) + 18,"%d",&PuzzleBuffer);
          wattron(InfoWindow,COLOR_PAIR(3));
          wattron(InfoWindow,A_BOLD);
          wrefresh(InfoWindow);
          mvwprintw(InfoWindow,6,1,"Error! Inputted value is not valid!");
        } while(PuzzleBuffer < 1 || PuzzleBuffer > 9);
        // This routine just clears the error messages, printed above.
        noecho();
        wattron(InfoWindow,COLOR_PAIR(1));
        wattroff(InfoWindow,A_BOLD);
        mvwprintw(InfoWindow,6,1,"                                     ");
        // This line just removes any extra characters from the line.
        mvwprintw(MainWindow,(2 * UserInputY) + 4,(4 * UserInputX) + 18,"    ");
        Puzzle[UserInputY][UserInputX] = PuzzleBuffer;
        PuzzleBuffer = 0;
      }
      break;

    default:
      break;
    }
  }

  return;
}
