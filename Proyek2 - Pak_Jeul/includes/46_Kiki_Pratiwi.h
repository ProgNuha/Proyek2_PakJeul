#ifndef KIKI_PRATIWI_H_INCLUDED
#define KIKI_PRATIWI_H_INCLUDED

#include "general.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>

//Deklarasi Konstanta
#define ERR_NO_NUM -1
#define ERR_NO_MEM -2

//========================================================Screen Feature============================================================//
void splash_screen();

//=======================================================Set Goal Feature==========================================================//
void set_goal_and_level();
// Modul untuk memilih goal dan level

void set_puzzle_input_custom_coordinate(PzlPosition Petak_Puzzle[]);
// Modul untuk menginisialisasi koordinat papan puzzle pada inupt custom goal

game_setting cheat_input_custom(int empty);
// Modul untuk mengisi array puzzle custom secara otomatis

void back_action(int mX, int mY);
// Modul untuk kembali ke screen set_goal_and_level dari screen input custom goal

void reset_action(char arr_custom_setting[]);
// Modul untuk mereset array puzzle pada input custom goal

void show_all_button_set_goal_and_level(char* level, char goal);
// Modul menampilkan emua button pada screen set goal and level
// dipanggil setelah memilih input goal custom

void save_data_player(player p);
// Modul untuk menyimpan data player ke dalam File

//========================================================Rank Feature============================================================//
int count_data_player();
// Modul untuk menghitung data player yang tersimpan File
// digunakan untuk menentukan banyak elemen pada array data player

void get_data_player(player p[]);
// Modul untuk membaca data player dari File untuk disimpan ke dalam array

void sort_file_rank();
// Modul untuk mengurutkan rank berdasarkan timeleft terbesar
// sort in file

void sort_data_rank(player p[], int n);
// Modul untuk mengurutkan rank berdasarkan timeleft terbesar
// sort an array

void swap_data_player(player *compared_dt, player *moved_dt);
// Menukarkan element aray
// digunakan pada modul sort data rank

//========================================================Play Feature============================================================//
void pause_act(Point Pp, Point Pp1);
// Modul untuk menjeda waktu dan fungsi button pada screen play game
// dipanggil saat button pause ditekan

void swap_position(int *idx_empty_pzl, int idx_curpos, int ArrIdx[], PzlPosition PetakPuzzle[], char ArrGoal[]);
// Modul untuk menukar isi array puzzle yang dimainkan
// dipanggil saat player menggerakkan kotak kosong

int find_index_of_empty_puzzle(char a[]);
// Modul untuk menemukan index array yang berisi EMPTY_PUZZLE

int find_index(int a[], int value);
// Modul untuk menemukan index array yang berisi parameter value

bool is_same_as_goal(int arrPuzzle[]);
// Modul untuk memeriksa apakah elemen puzzle telah sama dengan goal atau belum

void show_board_element(Point t1, Point t2, char image_name);
// Modul untuk menempatkan gambar pada titik koodinat yang menjadi parameter

void place_all_puzzle_on_board(PzlPosition pp[], int idx_pzl[], char ArrGoal[]);
// Modul untuk menempatkan semua gambar puzzle pada papan puzzle

unsigned short get_random_number(int limit_a, int limit_b);
// Modul untuk mendapatkan angka acak pada batas tertentu

//========================================================Solve Feature============================================================//
tree_and_leaf generate_tree(char ArrGoal[], short int depth);
// Modul untuk membuat Tree yang mengembalikan tipe data komposit 'tree_and_leaf' 
// tree adalah pointer yang menunjuk ke root dan leaf adalah Queue yang berisi level terakhir tree

infotype set_info_tree_node(short int movement, short int empty);
// Modul untuk mengisi info node tree
// node tree bertipe data komposit 'infotype' yang berisi move, reverse, 
// dan indeks empty node baru

void swap_position_array(int *idx_empty_pzl, int idx_curpos, int ArrIdx[], PzlPosition PetakPuzzle[], char ArrGoal[]);

//=========================================================For Debug==============================================================//
void print_tree(address node);

void show_linkedlist (addressLink p);

#endif
