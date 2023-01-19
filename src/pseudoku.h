#ifndef __PSEUDOKU_H
#define __PSEUDOKU_H

void pseudokugen(int Puzzle[9][9], int Seed);
void pseudokudel(int Puzzle[9][9], int Seed, int Difficulty);

void guiwrapper(int Puzzle[9][9], int Answer[9][9]);
void guimainmenu(int MaxY, int MaxX);

#endif
