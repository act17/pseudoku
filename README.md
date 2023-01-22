# pseudoku
A Sudoku-like Puzzle Game

Version: Alpha 1.3.0 (January 19th, 2023)

# Description
  Pseudoku is a puzzle game where 81 numbers are arranged in a 9x9 grid. The numbers do not repeat in vertical columns or horizontal rows. Some numbers will be blanked out, and the objective of the game is to deduct which numbers replace the blank spaces.

# Compiling and Usage
  To compile Pseudoku, simply run the command ``make`` in the source directory. You must have ``gcc`` installed in order to compile the program!
  To run Pseudoku, simply run the binary that you've compiled. It only prints out a completed Pseudoku puzzle.

# Changelog

  *Alpha 1.3.0 - 2023/01/21*
  - Added the file ``./src/gui/guigame.c``. This includes the function ``void guigame(int Puzzle[9][9], int Answer[9][9], int MaxY, int MaxX, int Seed)``. This prints two windows, one with various information, and one that prints out ``Puzzle``. It will be used for the user of the program to actually play the game - obviously.
  - Altered the file ``./src/gui/guiwrapper.c`` to include a new parameter for the function ``guiwrapper()`` - this is an integer called ``Seed``, and is the actual seed used for Random Number Generation.
  - Altered the file ``./src/pseudoku.h`` to include ``void guigame()`` and include changes to ``void guiwrapper()``.
  - Altered the file ``./src/main.c`` to include the usage of ``void guigame()`` and include changes made to ``guiwrapper()``.
  - Altered the file ``./Makefile`` to include the file ``./src/gui/guigame.c``.

  *Alpha 1.2.0 - 2023/01/19*
- Added the directory ``./src/gui/``. This includes several files that handle the NCurses GUI. It includes the following files:
  - Added: ``./src/gui/guiwrapper.c``. This includes the function ``void guiwrapper(int Puzzle[9][9], int Answer[9][9])``. It handles potential errors for NCurses, and in the case that they do, it prints error messages. Otherwise, it runs the functions that include NCurses within them.
  - Added: ``./src/gui/guimainmenu.c``. This includes the function ``void guimainmenu(int MaxY, int MaxX)``. It prints a simple box that behaves like a main menu.
- Altered the file ``./src/pseudoku.h`` to include headers for the functions above.
- Altered the file ``./src/pseudoku/pseudokugen.c`` to no longer include printing diagnostic information.
- Altered the file ``./src/pseudoku/pseudokudel.c`` to include an extra comment.
- Altered the file ``./src/main.c`` to include functions included in ``./src/gui/*.c``.
- Altered the file ``./Makefile`` to include the two new files described at the top of the changelog entry for the current verison.
- Now all files within the repository are styled with ``astyle`` because Clang and LLVM don't play nice with my install of headless Arch Linux I use to develop this program.

  *Alpha 1.1.0 - 2023/01/18*
- Added a new file ``./src/pseudoku/pseudokudel.c``. This includes the function ``void pseudokudel(int Puzzle[9][9], int Seed, int Difficulty)``. It takes the multidimensional array, ``int Puzzle[9][9]``, and randomly replaces as many entries in the array with zeros as defined by ``int Difficulty``.
- Altered ``./src/pseudoku.h``. It now includes the header file definition for the functions in ``pseudokudel.c``.
- Altered ``./src/main.c``. It now includes ``void pseudokudel(..)``, and will print a whitespace in place of a zero when printing the puzzle.
- Altered ``./Makefile``. It now includes ``./src/pseudoku/pseudokudel.c``.


  *Alpha 1.0.0 - 2023/01/15*
- Added the directory ``./src``.
  - Added the file ``./src/main.c``. This file contains the function ``main()``.
  - Added the file ``./src/pseudoku.h``. This is the header file for all functions contained in the folder ``./src/pseudoku``.
  - Added the directory ``./src/pseudoku``. This is the directory that shall contain the files whom have functions defined in ``./src/pseudoku.h``.
  - Added the file ``./src/pseudoku/pseudokugen.c``. This contains the function ``void pseudokugen(int Puzzle[9][9], int Seed)``. It generates a completed Pseudoku puzzle.

# Credits

  Credit goes to a special lady who gave the idea and the name for this project. <3
