#ifndef __PSEUDOKU_H
#define __PSEUDOKU_H

static const char VERSION_NUM[7] = "B1.2.0";
static const char VERSION_DATE[11] = "2023-01-21";

void pseudokugen(int Puzzle[9][9], int Seed);
void pseudokudel(int Puzzle[9][9], int Seed, int Difficulty);
int pseudokucmp(int Puzzle[9][9], int Answer[9][9], int Wrong[9][9]);

void guiwrapper(int Puzzle[9][9], int Answer[9][9], int Seed);
void guimainmenu(int MaxY, int MaxX);
void guigame(int Puzzle[9][9], int Answer[9][9], int MaxY, int MaxX, int Seed);

#endif
