#ifndef MUFIDA_NUHA_S_H_INCLUDED
#define MUFIDA_NUHA_S_H_INCLUDED
#include "general.h"
#include "46_Kiki_Pratiwi.h"
#include "50_Mufida_Nuha_S.h"
#include "65_Velia_Sagita_P.h"

void ColorButton(Point t1, Point t2, int fillcolor1, int fillcolor2, int bordercolor1);
//Mewarnai area bingkai pada button

void Rank();
//Menampilkan UI Highscore

void Show_Rank(char *level, int colorfont);
// Modul untuk menampilkan urutan user terbaik berdasarkan waktu 
// untuk menyelesaikan game.

void set_custom_goal();
// Modul untuk membuat goal custom

void Pic_Position(PzlPosition *coor);
// Modul untuk mendefinisikan koordinate gambar

char choose_pic(char ArrGoal[]);
// Modul untuk memilih gambar pada set_custom_goal

void Box_Pic (int color1, Point dot1, Point dot2);
// Modul untuk mewarnai border diantara dua persegi


/* = = = = = = = = = = = = = = = = Generate Tree = = = = = = = = = = = = = = = = */
infoMovement movementFreeSpace(int indexPuzzle);
// Modul yang berfungsi mengembalikan tipe data komposit yaitu 'infoMovement' 
// yang memberi info perpindahan yang dapat dilakukan 'FreeSpace'

infotype isiInfoRoot(int indexEmpty);
// Mengembalikan tipe data komposit 'infotype' yang berisi move, reverse, 
// dan indeks empty Root.

address createRoot(int indexEmpty);
// Mengembalikan tipe data komposit 'address´ atau 'infotypeLink' 
// yang menjadi root pada Tree yang dibangun

void animatePuzzle(addressLink topStack, char ArrGoal[], int ArrIdx[]);
// Menggerakkan puzzle secara otomatis berdasarkan info pergerakan dari stack

/* = = = = = = = = = = = = = = = ADT Linked List Dynamic = = = = = = = = = = = = = = = */
boolean isEmpty(addressLink p);
// Mengecek isi suatu node, mengembalikkan nilai boolean

addressLink alokasiNode();
// Mengalikasikan sejumlah memori yang dipesan,
// mengembalikkan nilai addressLink

addressLink createNode(infotypeLink info);
// Membuat node baru, mengembalikan nilai addressLink

void insertAwal(addressLink *awal, addressLink newNode);
// Menambah / insert node baru pada di awal Linked List

void insertAkhir (addressLink *awal, addressLink *akhir, addressLink newNode);
// Menambah / insert node baru pada di akhir Linked List

void enque(addressLink *nodeAwal, addressLink *nodeAkhir, infotypeLink info);
// Menambah / insert node baru pada di akhir Linked List pada stuktur data Queue

void push(addressLink *awal, addressLink newNode);
// Menambah / insert node baru pada di awal Linked List pada stuktur data Stack

void deAlokasi(addressLink *pDel);
// Melakukan dealokasi dan pengembalian address pDel ke sistem

addressLink deAlokasiStack(addressLink pDel);
// 

infotypeLink deleteAwal(addressLink *node);
// Mengehapus elemen pertama pada Linked List dan mengembalikan nilai 'infotypeLink' 

infotypeLink deque(addressLink *nodeFront);
// Mengehapus elemen pertama pada Linked List dan 
// mengembalikan nilai 'infotypeLink' pada struktur data Queue

infotypeLink pop(addressLink *top);
// Mengehapus elemen pertama pada Linked List dan 
// mengembalikan nilai 'infotypeLink' pada struktur data Stack


/* = = = = = = = = = = = = = = = ADT Tree Dynamic = = = = = = = = = = = = = = = */
boolean IsEmpty(address p);
// Mengecek isi suatu node, mengembalikkan nilai boolean

address alokasiNodeTree();
// Mengalikasikan sejumlah memori yang dipesan, 
// mengembalikkan nilai address

address createNodeTree(infotype info);
// Membuat node baru, mengembalikan nilai address

address insertNodeTree(Tree *tree, address parent, infotype info);
// Menambah / insert node baru pada Tree

void createTree(Tree *tree);
// Membuat (Root) Tree baru

void deAlokasiTree (address *pDel);

void inOrder(address node);

#endif
