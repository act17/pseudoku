# pseudoku
A Sudoku-like Puzzle Game

Version: Alpha 1.0.0 (January 15th, 2023)

# Description
	Pseudoku is a puzzle game where 81 numbers are arranged in a 9x9 grid. The numbers do not repeat in vertical columns or horizontal rows. Some numbers will be blanked out, and the objective of the game is to deduct which numbers replace the blank spaces.

# Compiling and Usage
	To compile Pseudoku, simply run the command ``make`` in the source directory. You must have ``gcc`` installed in order to compile the program!
	To run Pseudoku, simply run the binary that you've compiled. It only prints out a completed Pseudoku puzzle.

# Changelog

	*Alpha 1.0.0 - 2023/01/15*
- Added the directory ``./src``.
  - Added the file ``./src/main.c``. This file contains the function ``main()``.
  - Added the file ``./src/pseudoku.h``. This is the header file for all functions contained in the folder ``./src/pseudoku``.
  - Added the directory ``./src/pseudoku``. This is the directory that shall contain the files whom have functions defined in ``./src/pseudoku.h``.
  - Added the file ``./src/pseudoku/pseudokugen.c``. This contains the function ``void pseudokugen(int Puzzle[9][9], int Seed)``. It generates a completed Pseudoku puzzle.

# Credits

  Credit goes to a special lady who gave the idea and the name for this project. <3
