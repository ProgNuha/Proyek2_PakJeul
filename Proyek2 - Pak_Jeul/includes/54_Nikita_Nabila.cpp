#include "general.h"
#include "50_Mufida_Nuha_S.h"
#include "65_Velia_Sagita_P.h"
#include "46_Kiki_Pratiwi.h"
#include "54_Nikita_Nabila.h"
#include "03_Ananda_K.h"

/*************************************************SET GOAL FEATURE*************************************************/

void save_setting(game_setting gs)
{
	/* kamus data lokal */
	FILE *goal_and_level_setting; // file yang berisi info goal dan level
	
	/* open file */
	goal_and_level_setting=fopen("goal_and_level_setting.dat", "wb");	
	
	/* write file*/
	fwrite(&gs, sizeof(gs), 1, goal_and_level_setting);
	
	/* close file */
	fclose (goal_and_level_setting);
}

game_setting get_game_setting ()
{
	/* kamus data lokal */ 
	game_setting gs;
	game_setting file_gs; 
	FILE *goal_and_level_setting; // file yang berisi info goal dan level
	
	/* open file */	
	goal_and_level_setting=fopen("goal_and_level_setting.dat", "rb");
	
	/* read file */
	if (fread(&file_gs, sizeof(file_gs), 1, goal_and_level_setting)==0)
	{
		printf ("\nFile kosong"); // jika file kosong
	}
	else // jika file terisi
	{
		// record yang dibaca dari file_gs di asign ke variabel lokal gs
		gs.goal 		  = file_gs.goal;
		gs.level		  = file_gs.level;
		gs.song			  = file_gs.song;
		gs.time_limit	  = file_gs.time_limit;
		memcpy(gs.ArrGoal, file_gs.ArrGoal, sizeof(file_gs.ArrGoal)*nPzl); // menyalin karakter dari memori area file_gs ke memori area gs
	}

	/* close file */
	fclose (goal_and_level_setting);
	
	return gs;
}

/*************************************************SCREEN FEATURE*************************************************/

void praexit ()
{
	/* button point */
	Point EX1, EX2, YEX1, YEX2, NEX1, NEX2;
	
	/* button size */
	int mX, mY, 
	gap_button = 5, 
	gapImage = 6, 
	difColor = 5;
		
	/* button color initializing */	
	int DarkOrange  	 = COLOR(230,134,25), // button no
		DarkOrange1		 = COLOR(230,134,25 + difColor),
		Fill_DarkOrange1 = COLOR(230,134,24),
		Fill_DarkOrange2 = COLOR(159, 58, 6);
	int LightGreen 		 = COLOR(180,190,66), // button yes
		LightGreen1 	 = COLOR(180,190,66 + difColor),
		Fill_LightGreen1 = COLOR(180,190,65), 	
		Fill_LightGreen2 = COLOR(115,142,63);	
	
	/* coordinate declaration */
	EX1.x  = 120; // area button exit
	EX1.y  = 170;
	EX2.x  = 780;
	EX2.y  = 365;
	YEX1.x = 300; // area button yes
	YEX1.y = 300;
	YEX2.x = 400;
	YEX2.y = 340;
	NEX1.x = YEX2.x + 100; // area button no
	NEX1.y = YEX1.y;
	NEX2.x = NEX1.x + 100;
	NEX2.y = NEX1.y + 40;

	/* show background exit */
	readimagefile("assets/bg/bgexit.bmp",EX1.x,EX1.y,EX2.x,EX2.y);

	/* show background button yes */
	setcolor	(LightGreen);  
	Button_Image(YEX1, YEX2, gap_button, gapImage, "assets/button/yes.bmp");
	ColorButton	(YEX1, YEX2, Fill_LightGreen1, Fill_LightGreen2, LightGreen);
	
	/* show background button no */
	setcolor	(DarkOrange); 
	Button_Image(NEX1, NEX2, gap_button, gapImage, "assets/button/no.bmp");
	ColorButton	(NEX1, NEX2, Fill_DarkOrange1, Fill_DarkOrange2, DarkOrange);	

	
	while(1)
	{
		getmouseclick(WM_LBUTTONDOWN,mX,mY); // click button
		delay(100);
		
		if(mX >= YEX1.x and mX <= YEX2.x and mY >= YEX1.y and mY <= YEX2.y) // jika klik button yes
		{
			/* click effect */
			setcolor	(LightGreen1);
			Button		(YEX1, YEX2, gap_button);
			ColorButton	(YEX1, YEX2, Fill_LightGreen2, Fill_LightGreen1, LightGreen1);	
			delay(200);
			ColorButton	(YEX1, YEX2, Fill_LightGreen1, Fill_LightGreen2, LightGreen1);
			delay(200);
			
			/* close graphic.h */
	    	closegraph();
	    	
			exit(1);
		}
		
		else if(mX >= NEX1.x and mX <= NEX2.x and mY >= NEX1.y and mY <= NEX2.y) // jika klik button no
		{
			/* click effect */
			setcolor	(DarkOrange1);
			Button		(NEX1, NEX2, gap_button);
			ColorButton	(NEX1, NEX2, Fill_DarkOrange2, Fill_DarkOrange1, DarkOrange1);
			delay(200);
			ColorButton	(NEX1, NEX2, Fill_DarkOrange1, Fill_DarkOrange2, DarkOrange1);
			delay(200);	
			
			/* back to menu */	
			main_menu();
		}
	}
}

/*************************************************CUSTOM FEATURE*************************************************/

void Set_Coordinate_Image_Goal_Custom (PzlPosition *Petak_Puzzle) 
{
	/* kamus data lokal */
	int min_y, min_x ;
		min_y  = 89;
		min_x  = 513;
		
	/* Koordinat titik goal custom */	
	for (int i = 0;i<nPzl;i+=3)
	{
		Petak_Puzzle[i].t1.x   = min_x;
		Petak_Puzzle[i].t2.x   = min_x + 36;
		Petak_Puzzle[i+1].t1.x = Petak_Puzzle[i].t2.x;
		Petak_Puzzle[i+1].t2.x = Petak_Puzzle[i].t2.x + 36;
		Petak_Puzzle[i+2].t1.x = Petak_Puzzle[i+1].t2.x;
		Petak_Puzzle[i+2].t2.x = Petak_Puzzle[i+1].t2.x + 36;
	
		for(int j=i;j<=i+2;j++)
		{
			Petak_Puzzle[j].t1.y = min_y;
			Petak_Puzzle[j].t2.y = min_y + 36;
		}
		min_y = min_y + 36;
	}
}

void Show_Image_Goal_Custom (char ArrGoal[])
{
	/* button point */
	Point SX1, SX2;
	
	/* coordinate declaration */
	SX1.x = 501;
	SX1.y = 70;
	SX2.x = 631;
	SX2.y = 214;
	
	PzlPosition Petak_Puzzle [nPzl]; // variabel petak puzzle tipenya PzlPosition dengan banyak nPzl
	Set_Coordinate_Image_Goal_Custom(Petak_Puzzle);
	
	for (int i=0 ; i<nPzl; i++) // menampilkan board puzzle
	{
        show_board_element(Petak_Puzzle[i].t1, Petak_Puzzle[i].t2, ArrGoal[i]);
    }
}

/*************************************************SOLVE FEATURE*************************************************/

addressLink get_leaf (address nodeRoot)
{
	/* kamus data lokal */		
	address pCur = nodeRoot;
	boolean arah;
	arah=0;
	addressLink Front = NULL, Rear = NULL;
	
	/* Tranversal Preorder */
	if (pCur->firstSon == NULL)
	{
		enque (&Front,&Rear, pCur);
	}
	do
	{
		if(pCur->firstSon!=NULL && arah==0)
		{
			pCur=pCur->firstSon;
			if (pCur->firstSon == NULL)
			{
				enque (&Front,&Rear, pCur);	
			}
		}
		else
		{
			arah=0;
			if (pCur->nextBrother!= NULL)
			{
				pCur=pCur->nextBrother;
				if (pCur->firstSon == NULL)
				{
					enque (&Front,&Rear, pCur);
				}
			}
			else
			{
				pCur=pCur->parent;
				arah=1;
			}
		}
	}while(pCur!=NULL);
	return Front;
}

int countleaf (addressLink node)
{
	/* kamus data lokal */
	int countleaf = 0;
	
	while (node->next!=NULL)
	{
		countleaf++; // menghitung jumlah daun
		node = node->next;
	}
	printf("leaves:%d\n",countleaf); // menampilkan jumlah total daun 
	return countleaf;
}


