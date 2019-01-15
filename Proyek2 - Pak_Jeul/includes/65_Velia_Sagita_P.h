#ifndef VELIA_SAGITA_P_H_INCLUDED
#define VELIA_SAGITA_P_H_INCLUDED
#include "general.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>
//Deklarasi Konstanta
#define ERR_NO_NUM -1
#define ERR_NO_MEM -2 


void main_menu();	
//UI awal yang berisi pilihan

void about();		
//UI yang ditampilkan saat klik button about di main menu, berisi penjelasan games dan anggota kelompok

void help();		
//UI yang menampilkan cara bermain

void set_back_button();		
//tampilan button back

void back_button_effect();		
//kembali ke UI sebelumnya

void back();		
//kembali ke UI sebelumnya

void set_next_button();		
//tampilan button next

void next_button_effect();		
//menuju ke UI selanjutnya

void letak(PzlPosition *Petak_Puzzle);
// Modul untuk menentukan/ mendefinisikan titik acuan untuk membuat box pada papan puzzle.

void Button_Arrow (Point *ConsoleUpButton1, Point *ConsoleUpButton2, Point *ConsoleRightButton1, Point *ConsoleRightButton2, Point *ConsoleDownButton1, Point *ConsoleDownButton2, Point *ConsoleLeftButton1, Point *ConsoleLeftButton2 );
//Modul untuk membuat button arrow pada UI play

void Button_Menu_Collection(Point *RandomButton1, Point *RandomButton2, Point *SolveButton1, Point *SolveButton2, Point *PauseButton1, Point *PauseButton2, Point *BackButton1,Point *BackButton2);
//Modul untuk membuat button pilihan menu pada UI play

void Goal(char g);
// Modul untuk menampilkan teks "GOAL"

void Info(int n, char *textstring);
//

void ShowLevel(char* lvl);
// Modul untuk menampilkan info level yang sebelumnya telah dipilih

void Time_icon();
// Modul untuk menampilkan icon time

void Showtime(Times time_left);
// Modul untuk menampilkan countdown time dari waktu yang telah ditentukan yang sebelumnya telah dipilih

void Button_Menu_Collection();
// Modul untuk membuat button menu pada UI play

void play_game();		//prosedur 
//Modul untuk menjalankan proses gameplay.

game_setting input_custom(game_setting player_setting);
//Modul untuk menyimpan data custom goal

addressLink BackTrack (Tree root, addressLink leaf);
//Modul untuk backtrack dari step terakhir sampai goal

addressLink randomLeaf(addressLink Front, int Leaf);
//Modul untuk random leaf yang dipilih sebagai hasil random
#endif
