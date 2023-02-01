#ifndef __PSEUDOKU_H
#define __PSEUDOKU_H

static const char VERSION_NUM[8] = "R1.0.0";
static const char VERSION_DATE[11] = "2023-01-31";

void pseudokugen(int Puzzle[9][9], int Seed);
void pseudokudel(int Puzzle[9][9], int Seed, int Difficulty);
int pseudokucmp(int Puzzle[9][9], int Answer[9][9], int Wrong[9][9]);

void guiwrapper(int Puzzle[9][9], int Answer[9][9], int Options[3]);
void guimainmenu(int MaxY, int MaxX);
void guiseed(int MaxY, int MaxX, int Options[3]);
void guidifficulty(int MaxY, int MaxX, int Options[3]);
void guigame(int Puzzle[9][9], int Answer[9][9], int MaxY, int MaxX, int Options[3]);

#endif
