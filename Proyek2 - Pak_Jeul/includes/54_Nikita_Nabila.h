#ifndef NIKITA_NABILA_H_INCLUDED
#define NIKITA_NABILA_H_INCLUDED

#include "general.h"

void save_setting(game_setting gs);
game_setting get_game_setting ();
void  praexit ();
void Show_Image_Goal_Custom (char ArrGoal[]);
void Set_Coordinate_Image_Goal_Custom (PzlPosition *Petak_Puzzle);
int countleaf (addressLink node);

#endif
