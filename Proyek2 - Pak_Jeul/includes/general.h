#ifndef GENERAL_H_INCLUDED
#define GENERAL_H_INCLUDED

//header
#include <graphics.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Deklarasi Konstanta
const int ORIGIN_POINT	= 0;
const int MINIMUM 		= 25;
const int WIDTH 		= 900;
const int HEIGHT		= 600;
const int MARGIN_LEFT 	= 220;
const int MARGIN_RIGHT 	= 50;
const int nPzl 			= 9;
const int N 			= 100;
const char EMPTY_PUZZLE	= '0';
const short int TOP  	= -3;
const short int BOTTOM  = 3;
const short int LEFT  	= -1;
const short int RIGHT  	= 1;
//const short int KEY_UP    = 24;
//const short int KEY_DOWN  = 25;
//const short int KEY_RIGHT = 26;
//const short int KEY_LEFT  = 27;
const unsigned short LIMIT_A = 11;
const unsigned short LIMIT_B = 17;

//Kamus data global
typedef struct
{
	int   x,y;
} Point;

typedef struct
{
	Point t1,t2;
} PzlPosition;

typedef struct
{
	int   second;
	int   minute;
} Times;

typedef struct
{
	char  goal;
	char* level;
	Times time_limit;
	char* song;
//	int   ArrGoal[nPzl];
	char ArrGoal[nPzl];
}game_setting;

typedef struct
{
	char  name[7];
//	const char* name;
	char  level[7];
	int   movement;
	Times time_left;
	char  result[8];
	bool  win;
}player;

typedef struct infoMovement{
	bool status[4];
};

typedef struct nodeTree *address;
typedef struct node *addressLink;
typedef address infotypeLink;

typedef struct infotype{  //tree
	short int move, empty;
};

typedef struct node{
	infotypeLink info;
	addressLink next; 
};

typedef struct nodeTree{
	infotype  infoTree;
	address	parent;
	address	firstSon;
	address	nextBrother;
};

typedef struct Tree{
	address root;
};

typedef struct tree_and_leaf{
	address root;
	addressLink leaf;
};

//Prototype
//
void Garis(Point t1,Point t2);
void Box(Point t1,Point t2);
//Modul untuk membuat persegi
void Button(Point t1,Point t2, int gap);
// Modul untuk membuat button
void Button_Image(Point t1,Point t2, int gap, int gap_image, const char* image); 
// Modul untuk membuat button yang terdapat gambar
void Count_Down(Times waktu);
// 
#endif
