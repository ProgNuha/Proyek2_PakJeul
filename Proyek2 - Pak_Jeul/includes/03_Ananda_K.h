#ifndef ANANDA_K_H_INCLUDED
#define ANANDA_K_H_INCLUDED

#include "general.h"
#include "65_Velia_Sagita_P.h"

extern char latest_player_name[7];

player inputname();
// Modul untuk input playername 
void result(player p);
// Modul yang ditampilkan setelah selesai memainkan game. 
// Menampilkan skor pemain,
// pilihan menu high score, play game dan menu.

void reset_arr_custom (char array[]);
// Mengisi semua elemen array dengan NULL

boolean isArrEmpty(char array[]);
// Memeriksa semua elemen array 

boolean isArrFull(char array[]);
// Memeriksa array pada custom goal

int input_empty_puzzle (PzlPosition pp[nPzl]);
// input empty puzzle saat custom goals

addressLink randomGoal (addressLink stack, char ArrGoal[], int Arridx_ofGoal[]);
// mengacak array goal berdasarkan backtract tree.

void Loading();

#endif
