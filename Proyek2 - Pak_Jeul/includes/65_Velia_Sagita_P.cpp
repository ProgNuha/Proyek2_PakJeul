#include "65_Velia_Sagita_P.h"
#include "50_Mufida_Nuha_S.h"
#include "46_Kiki_Pratiwi.h"
#include "54_Nikita_Nabila.h"
#include "03_Ananda_K.h"

void main_menu()
{
	cleardevice();
	readimagefile("assets/bg/main_menu.bmp",ORIGIN_POINT, ORIGIN_POINT, WIDTH, HEIGHT);
	
	/*Pendeklarasian Koordinat Button*/
	bool valid=false;
	Point RankButton1, RankButton2, AboutButton1, AboutButton2, HelpButton1, HelpButton2, StartButton1, StartButton2, ExitButton1, ExitButton2;
	int mX, mY, //batas koordinat x dan y
		width 		= 200, //jarak antara koordinat dalam satu button secara horizontal
		height 		=  45, //jarak antara koordinat dalam satu button secara vertikal
		gap_x 	   	= 230, //batas antara koordinat x1 dan x2
		gap_y      	=  75, //batas antara koordinat y1 dan y2
		gap_button 	=   5, //batas antar button
		gapImage   	=   5, //batas antar gambar
	
	/*Pendeklarasian Warna*/
		difColor   	=   5; //perbedaan wawrna untuk button saat diklik
	int Orange = COLOR(241,175,1), 		
		Orange1 = COLOR(241,175,1 + difColor),		 
		Fill_Orange1	 = COLOR(241,175, 1), 	
		Fill_Orange2	 = COLOR(230,134,24);
	int LightGreen 		 = COLOR(180,190,65), 
		LightGreen1		 = COLOR(180,190,65 + difColor),
		Fill_LightGreen1 = COLOR(180,190,65), 	
		Fill_LightGreen2 = COLOR(115,142,63);
	int DarkGreen		 = COLOR( 87,125,38), 
		DarkGreen1		 = COLOR( 87,125,38 + difColor),
		Fill_DarkGreen1  = COLOR( 87,125,38), 	
		Fill_DarkGreen2  = COLOR( 38, 62,14);
	int Brown 			 = COLOR(165, 97,42), 	
		Brown1 			 = COLOR(165, 97,42 + difColor), 
		Fill_Brown1 	 = COLOR(165, 97,42), 
		Fill_Brown2 	 = COLOR(105, 55,43);;
	
	/*Create Button*/
	AboutButton1.x	= 350;
	AboutButton1.y	= 245;
	AboutButton2.x	= AboutButton1.x+width;
	AboutButton2.y	= AboutButton1.y+height;
	RankButton1.x	= AboutButton1.x-gap_x;
	RankButton1.y	= AboutButton1.y;
	RankButton2.x	= RankButton1.x+width;
	RankButton2.y	= RankButton1.y+height;
	HelpButton1.x	= AboutButton1.x+gap_x;
	HelpButton1.y	= AboutButton1.y;
	HelpButton2.x	= HelpButton1.x+width;
	HelpButton2.y	= HelpButton1.y+height;
	StartButton1.x	= AboutButton1.x;
	StartButton1.y	= AboutButton1.y-gap_y;
	StartButton2.x	= StartButton1.x+width;
	StartButton2.y	= StartButton1.y+height;
	ExitButton1.x	= AboutButton1.x;
	ExitButton1.y	= AboutButton1.y+gap_y;
	ExitButton2.x	= ExitButton1.x+width;
	ExitButton2.y	= ExitButton1.y+height;
	
	/*Create Button*/
	//Button About
	setcolor	(DarkGreen);	
	Button_Image(AboutButton1, AboutButton2, gap_button, gapImage, "assets/button/about.bmp"); 
	ColorButton	(AboutButton1, AboutButton2, Fill_DarkGreen1, Fill_DarkGreen2, DarkGreen);   	
	//Button Rank
	setcolor	(LightGreen);
	Button_Image(RankButton1, RankButton2, gap_button, gapImage, "assets/button/rank.bmp"); 
	ColorButton	(RankButton1, RankButton2, Fill_LightGreen1, Fill_LightGreen2, LightGreen);
	//Button Help
	Button_Image(HelpButton1, HelpButton2, gap_button, gapImage, "assets/button/help.bmp"); 
	ColorButton	(HelpButton1, HelpButton2, Fill_LightGreen1, Fill_LightGreen2, LightGreen);	
	//Button Start Game
	setcolor	(Orange);	
	Button_Image(StartButton1, StartButton2, gap_button, gapImage, "assets/button/start_game.bmp"); 
	ColorButton	(StartButton1, StartButton2, Fill_Orange1, Fill_Orange2, Orange);	
	//Button Exit
	setcolor	(Brown);
	Button_Image(ExitButton1, ExitButton2, gap_button, gapImage, "assets/button/exit.bmp"); 
	ColorButton	(ExitButton1, ExitButton2, Fill_Brown1, Fill_Brown2, Brown);	


	/*Doing Action*/
    while(!valid)
    {
		getmouseclick(WM_LBUTTONDOWN,mX,mY);
	    delay(100);
	    
	    //button Rank
		if(mX >= RankButton1.x and mX <= RankButton2.x and mY >= RankButton1.y and mY <= RankButton2.y)
		{
			printf("\nrank"); 	/* log */
			setcolor	(LightGreen1);
			Button		(RankButton1, RankButton2, gap_button);	
			ColorButton	(RankButton1, RankButton2, Fill_LightGreen2, Fill_LightGreen1, LightGreen1); 		
			delay(200);
			ColorButton	(RankButton1, RankButton2, Fill_LightGreen1, Fill_LightGreen2, LightGreen1); 		
			delay(200);
		
			valid = true;
			Rank();
		}		    
	    //button about
		if(mX >= AboutButton1.x and mX <= AboutButton2.x and mY >= AboutButton1.y and mY <= AboutButton2.y)
		{
			printf("\nabout"); 	/* log */
			setcolor	(DarkGreen1);
			Button		(AboutButton1, AboutButton2, gap_button);
			ColorButton	(AboutButton1, AboutButton2, Fill_DarkGreen2, Fill_DarkGreen1, DarkGreen1);   	
			delay(200);
			ColorButton	(AboutButton1, AboutButton2, Fill_DarkGreen1, Fill_DarkGreen2, DarkGreen1);   
			delay(200);
			
			valid = true;
			about();
		}			    		    
	    //button help
		if(mX >= HelpButton1.x and mX <= HelpButton2.x and mY >= HelpButton1.y and mY <= HelpButton2.y)
		{
			printf("\nhelp"); 	/* log */
			setcolor	(LightGreen1);
			Button		(HelpButton1, HelpButton2, gap_button);	
			ColorButton	(HelpButton1, HelpButton2, Fill_LightGreen2, Fill_LightGreen1, LightGreen1); 		
			delay(200);
			ColorButton	(HelpButton1, HelpButton2, Fill_LightGreen1, Fill_LightGreen2, LightGreen1); 
			delay(200);
		
			valid = true;
			help();
		}
	    //button start_game
		if(mX >= StartButton1.x and mX <= StartButton2.x and mY >= StartButton1.y and mY <= StartButton2.y)
		{
			printf("\nstart_game"); 	/* log */
			setcolor	(Orange1);
			Button		(StartButton1, StartButton2, gap_button);	
			ColorButton	(StartButton1, StartButton2, Fill_Orange2, Fill_Orange1, Orange1);	
			delay(200);
			ColorButton	(StartButton1, StartButton2, Fill_Orange1, Fill_Orange2, Orange1);		
			delay(200);
			
			valid = true;
			set_goal_and_level();
		}	
		//button exi
		if(mX >= ExitButton1.x and mX <= ExitButton2.x and mY >= ExitButton1.y and mY <= ExitButton2.y)
		{
			printf("\nexit"); 	/* log */
			setcolor	(Brown1);
			Button		(ExitButton1, ExitButton2, gap_button);	
			ColorButton	(ExitButton1, ExitButton2, Fill_Brown2, Fill_Brown1, Brown1);	
			delay(200);
			ColorButton	(ExitButton1, ExitButton2, Fill_Brown1, Fill_Brown2, Brown1);	
			delay(200);
		
			valid = true;
			praexit ();
		}  
	}
}

void about()
{
	cleardevice();
	readimagefile("assets/bg/about.bmp",ORIGIN_POINT, ORIGIN_POINT, WIDTH, HEIGHT);
	
	/*Pendeklarasian Koordinat Button*/
	int mX, mY;	//batas koordinat x dan y

	/*Create Button*/
	/*		button back	*/
	Point BackButton1, BackButton2;
	int height = 35, //jarak antara koordinat dalam satu button secara horizontal
		width = 35;	//jarak antara koordinat dalam satu button secara vertikal
	BackButton1.x = ORIGIN_POINT;
	BackButton1.y = ORIGIN_POINT;
	BackButton2.x = ORIGIN_POINT + width;
	BackButton2.y = ORIGIN_POINT + height;
	set_back_button();

	/*Doing Action*/
	while(1)
	{
		getmouseclick(WM_LBUTTONDOWN,mX,mY);
		delay(100);
	//	button back
		if(mX >= BackButton1.x and mX <= BackButton2.x and mY >= BackButton1.y and mY <= BackButton2.y)
		{
			back_button_effect();
			main_menu();
		}
	}
}

void help()
{
	cleardevice();
	readimagefile("assets/bg/help.bmp",ORIGIN_POINT, ORIGIN_POINT, WIDTH, HEIGHT);

	/*Pendeklarasian Koordinat Button*/
	Point BackButton1, BackButton2; 
	int mX, mY;	//batas koordinat x dan y
	int height = 35, 	//jarak antara koordinat dalam satu button secara horizontal
		width  = 35;	//jarak antara koordinat dalam satu button secara vertikal
	
	/*Create Button*/
	/*		button back	*/
	BackButton1.x = ORIGIN_POINT;
	BackButton1.y = ORIGIN_POINT;
	BackButton2.x = ORIGIN_POINT + width;
	BackButton2.y = ORIGIN_POINT + height;
	set_back_button();
	
	/*Doing Action*/
	while(1)
	{
		getmouseclick(WM_LBUTTONDOWN,mX,mY);
		delay(100);
	//	button back
		if(mX >= BackButton1.x and mX <= BackButton2.x and mY >= BackButton1.y and mY <= BackButton2.y)
		{
			back_button_effect();
			main_menu();
		}
	}
}

void set_back_button()
{
	/*Pendeklarasian Koordinat Button*/
	Point BackButton1, BackButton2;
	int gap_button  =  3, //batas antara button 
		gapImage 	=  3, //batas antara gambar
		height 		= 35, //jarak antara koordinat dalam satu button secara horizontal
		 width 		= 35;//jarak antara koordinat dalam satu button secara vertikal
	BackButton1.x = ORIGIN_POINT;
	BackButton1.y = ORIGIN_POINT;
	BackButton2.x = ORIGIN_POINT + width;
	BackButton2.y = ORIGIN_POINT + height;
	
	/*Create Button*/
	setcolor	(COLOR(230,134,24));
	Button_Image(BackButton1, BackButton2, gap_button, gapImage, "assets/button/left.bmp");
	ColorButton (BackButton1, BackButton2, COLOR(230,134,24), COLOR(159,58,6), COLOR(230,134,24));
}

void back_button_effect()
{
	/*Pendeklarasian Koordinat Button*/
	Point BackButton1, BackButton2;
	int gap_button 	=  3, //batas antara button
		height 		= 35, //jarak antara koordinat dalam satu button secara horizontal
		width 		= 35; //jarak antara koordinat dalam satu button secara vertikal
	BackButton1.x = ORIGIN_POINT;
	BackButton1.y = ORIGIN_POINT;
	BackButton2.x = ORIGIN_POINT + width;
	BackButton2.y = ORIGIN_POINT + height;
	
	/*Doing Action*/
	printf("\nback"); 	/* log */
	setcolor	(COLOR(230,134,30));
	Button		(BackButton1, BackButton2, gap_button);	
	ColorButton	(BackButton1, BackButton2, COLOR(159,58,6), COLOR(230,134,24), COLOR(230,134,30));	//Brown
	delay(200);
	setcolor	(COLOR(230,134,35));
	Button		(BackButton1, BackButton2, gap_button);
	ColorButton	(BackButton1, BackButton2, COLOR(230,134,24), COLOR(159,58,6), COLOR(230,134,35));	//Brown	
	delay(300);
}

void set_next_button()
{
	/*Pendeklarasian Koordinat Button*/
	Point NextButton1, NextButton2;
	int gap_button  =  3, //batas antara button 
		gapImage 	=  3, //batas antara gambar
		height 		= 35, //jarak antara koordinat dalam satu button secara horizontal
		 width 		= 35;//jarak antara koordinat dalam satu button secara vertikal	
	NextButton1.x = WIDTH - width;
	NextButton1.y = ORIGIN_POINT;
	NextButton2.x = WIDTH;
	NextButton2.y = ORIGIN_POINT + height;
	
	/*Create Button*/
	setcolor	(COLOR(230,134,24));
	Button_Image(NextButton1, NextButton2, gap_button, gapImage, "assets/button/right.bmp");
	ColorButton	(NextButton1, NextButton2, COLOR(230,134,24), COLOR(159,58,6), COLOR(230,134,24));

}

void next_button_effect()
{
	/*Pendeklarasian Koordinat Button*/
	Point NextButton1, NextButton2;
	int gap_button  =  3, //batas antara button 
		height 		= 35, //jarak antara koordinat dalam satu button secara horizontal
		width 		= 35;//jarak antara koordinat dalam satu button secara vertikal
	NextButton1.x = WIDTH - width;
	NextButton1.y = ORIGIN_POINT;
	NextButton2.x = WIDTH;
	NextButton2.y = ORIGIN_POINT + height;
	
	/*Doing Action*/
	printf("\nnext"); 	/* log */
	setcolor	(COLOR(230,134,30));
	Button		(NextButton1,NextButton2, gap_button);	
	ColorButton (NextButton1, NextButton2, COLOR(159,58,6), COLOR(230,134,24), COLOR(230,134,30));	//Brown
	delay(200);
	setcolor	(COLOR(230,134,35));
	Button		(NextButton1, NextButton2, gap_button);	
	ColorButton (NextButton1, NextButton2, COLOR(230,134,24), COLOR(159,58,6), COLOR(230,134,35));	//Brown	
	delay(200);	
}

//	define position per box (element)
void letak(PzlPosition *Petak_Puzzle){
	int min_y  = MINIMUM+65, min_x;	//batas minimum titik patokan petak puzzle
		min_x  = MINIMUM;	//batas minimum titik patokan petak puzzle
	for (int i = 0;i<nPzl;i+=3){
		Petak_Puzzle[i].t1.x   = min_x;
		Petak_Puzzle[i].t2.x   = min_x + 150;
		Petak_Puzzle[i+1].t1.x = Petak_Puzzle[i].t2.x;
		Petak_Puzzle[i+1].t2.x = Petak_Puzzle[i].t2.x +150;
		Petak_Puzzle[i+2].t1.x = Petak_Puzzle[i+1].t2.x;
		Petak_Puzzle[i+2].t2.x = Petak_Puzzle[i+1].t2.x + 150;
		for(int j=i;j<=i+2;j++){
			Petak_Puzzle[j].t1.y = min_y;
			Petak_Puzzle[j].t2.y = min_y + 150;
		}
		min_y = min_y + 150;
	}
}

//Goal
void Goal(char g)
{
	setbkcolor	(COLOR(218,239,251));
	settextstyle(BOLD_FONT,0,4);
	outtextxy	(535,35,"Goal");

	switch(g)
	{
		case '1' : readimagefile("assets/button/goal1.bmp",500,70,635,218);	break;
		case '2' : readimagefile("assets/button/goal2.bmp",500,70,635,218);	break;
		case '3' : readimagefile("assets/button/goal_custom.bmp",500,70,635,218);	break;
	}
}

//Dificullity
void ShowLevel(char* lvl)
{
	readimagefile("assets/element/star.bmp",200,25,245,70);
	
	setbkcolor	(COLOR(218,239,251));
	settextstyle(BOLD_FONT,0,4);
	outtextxy	(260,35,lvl);
}

//Time icon
void Time_icon()
{
	readimagefile("assets/element/time.bmp",25,25,70,70);
}

//Countdown Time
void Showtime(Times time_left)
{
	/*Deklarasi satuan */
	char Minute[3];	//satuan waktu yang tersisa dalam menit
	char Second[3];	//satuan waktu yang tersisa dalam detik
	
	/*Deklarasi wlayout display time*/
	setbkcolor	(COLOR(218,239,251));
	setcolor	(COLOR(230,134,24));
	settextstyle(BOLD_FONT,0,4);

	/*Doing Action*/
	sprintf(Minute, "%d", time_left.minute);
	sprintf(Second, "%d", time_left.second);
	delay(1000);
	
	strcat (Minute, ":");
	if (time_left.second<10){
		strcat(Minute, "0");
	}
	strcat (Minute, Second);
	
	/*Display countdown time*/
	outtextxy(80,35, Minute);
	delay(10);
}

//Arrow
void Button_Arrow (Point *ConsoleUpButton1, Point *ConsoleUpButton2, Point *ConsoleRightButton1, Point *ConsoleRightButton2, Point *ConsoleDownButton1, Point *ConsoleDownButton2, Point *ConsoleLeftButton1, Point *ConsoleLeftButton2 )  
{
	/*Pendeklarasian Koordinat Button*/
	int gap_button 	=  5,	//batas antara button 
		gapImage	=  5,	//batas antara gambar
		gap_x 		= 75,	//batas antara koordinat x
		gap_y 		= 75, 	//batas antara koordinat y
		height 		= 75,	//jarak antara koordinat dalam satu button secara horizontal
		width 		= 75;  //jarak antara koordinat dalam satu button secara vertikal
	/*Pendeklarasian Warna*/
	int DarkOrange  	 = COLOR(230,134,24),
		Fill_DarkOrange1 = COLOR(230,134,24),
		Fill_DarkOrange2 = COLOR(159, 58, 6);
	
	/*Create Button*/
	(ConsoleDownButton1)->x 	= 650;
	(ConsoleDownButton1)->y 	= 465;
	(ConsoleDownButton2)->x 	= (ConsoleDownButton1)->x  +  width;
	(ConsoleDownButton2)->y 	= (ConsoleDownButton1)->y  + height;
	(ConsoleUpButton1)->x 	= (ConsoleDownButton1)->x;
	(ConsoleUpButton1)->y 	= (ConsoleDownButton1)->y  -  gap_y;
	(ConsoleUpButton2)->x 	= (ConsoleUpButton1)->x    +  width;
	(ConsoleUpButton2)->y 	= (ConsoleUpButton1)->y    + height;
	(ConsoleRightButton1)->x = (ConsoleDownButton1)->x  +  gap_x;
	(ConsoleRightButton1)->y = (ConsoleDownButton1)->y;
	(ConsoleRightButton2)->x = (ConsoleRightButton1)->x +  width;
	(ConsoleRightButton2)->y = (ConsoleRightButton1)->y + height;
	(ConsoleLeftButton1)->x 	= (ConsoleDownButton1)->x  -  gap_x;
	(ConsoleLeftButton1)->y 	= (ConsoleDownButton1)->y;
	(ConsoleLeftButton2)->x 	= (ConsoleLeftButton1)->x +  width;
	(ConsoleLeftButton2)->y 	= (ConsoleLeftButton1)->y + height;
	
	setcolor	(DarkOrange);
	Button_Image(*ConsoleDownButton1,  *ConsoleDownButton2, gap_button, gapImage, "assets/button/down.bmp");	
	ColorButton	(*ConsoleDownButton1,  *ConsoleDownButton2, Fill_DarkOrange1, Fill_DarkOrange2, DarkOrange);	//ConsoleDownButton
	Button_Image(*ConsoleUpButton1, 	  *ConsoleUpButton2,   gap_button, gapImage,  "assets/button/up.bmp");		
	ColorButton	(*ConsoleUpButton1,    *ConsoleUpButton2,   Fill_DarkOrange1, Fill_DarkOrange2, DarkOrange);		//ConsoleUpButton
	Button_Image(*ConsoleRightButton1, *ConsoleRightButton2,gap_button, gapImage, "assets/button/right.bmp");	
	ColorButton	(*ConsoleRightButton1, *ConsoleRightButton2,Fill_DarkOrange1, Fill_DarkOrange2, DarkOrange);	//ConsoleRightButton
	Button_Image(*ConsoleLeftButton1,  *ConsoleLeftButton2, gap_button, gapImage, "assets/button/left.bmp");
	ColorButton	(*ConsoleLeftButton1,  *ConsoleLeftButton2, Fill_DarkOrange1, Fill_DarkOrange2, DarkOrange);	//ConsoleLeftButton

}

//Set Button_Menu_Collection
void Button_Menu_Collection(Point *RandomButton1, Point *RandomButton2, Point *SolveButton1, Point *SolveButton2, Point *PauseButton1, Point *PauseButton2, Point *BackButton1,Point *BackButton2)
{
	/*Pendeklarasian Koordinat Button*/
	int gap_button  =   5,	//batas antara button
	    gapImage 	=   5,	//batas antara gambar
		gap_x 		= 190,	//batas antara koordinat x
		gap_y		=  60, 	//batas antara koordinat y
		height		=  50,	//jarak antara koordinat dalam satu button secara horizontal
		width		= 160;  //jarak antara koordinat dalam satu button secara vertikal 
	
	/*Pendeklarasian Warna*/
	int LightGreen 		 = COLOR(180,190,65), 
		Fill_LightGreen1 = COLOR(180,190,65), 	
		Fill_LightGreen2 = COLOR(115,142,63);
	int DarkGreen 		 = COLOR( 87,125,38),
		Fill_DarkGreen1  = COLOR( 87,125,38), 	
		Fill_DarkGreen2  = COLOR( 38, 62,14);
	int Orange 			 = COLOR(241,175, 1), 		
		Fill_Orange1 	 = COLOR(241,175, 1), 	
		Fill_Orange2 	 = COLOR(230,134,24);
	int Brown 			 = COLOR(165, 97,42), 	
		Fill_Brown1 	 = COLOR(165, 97,42), 
		Fill_Brown2 	 = COLOR(105, 55,43);
	
	/*Create Button*/
	RandomButton1->x = 500;	
	RandomButton1->y = 240;
	RandomButton2->x = RandomButton1->x +  width;	
	RandomButton2->y = RandomButton1->y + height;
	SolveButton1->x = RandomButton1->x +  gap_x;
	SolveButton1->y = RandomButton1->y;
	SolveButton2->x = SolveButton1->x +  width;
	SolveButton2->y = SolveButton1->y + height;
	PauseButton1->x = RandomButton1->x;
	PauseButton1->y = RandomButton1->y +  gap_y;
	PauseButton2->x = PauseButton1->x +  width;	
	PauseButton2->y = PauseButton1->y + height;
	BackButton1->x = RandomButton1->x +  gap_x;	
	BackButton1->y = RandomButton1->y +  gap_y;
	BackButton2->x = BackButton1->x +  width;	
	BackButton2->y = BackButton1->y + height;
	
	setcolor	(Orange);
	Button_Image(*RandomButton1, *RandomButton2, gap_button, gapImage,  "assets/button/random.bmp");
	ColorButton	(*RandomButton1, *RandomButton2, Fill_Orange1, Fill_Orange2, Orange);
	setcolor	(DarkGreen);
	Button_Image(*SolveButton1, *SolveButton2, gap_button, gapImage, "assets/button/solve.bmp");
	ColorButton	(*SolveButton1, *SolveButton2, Fill_DarkGreen1, Fill_DarkGreen2, DarkGreen);
	setcolor	(LightGreen);
	Button_Image(*PauseButton1, *PauseButton2, gap_button, gapImage, "assets/button/pause.bmp");
	ColorButton	(*PauseButton1, *PauseButton2, Fill_LightGreen1, Fill_LightGreen2, LightGreen);
	setcolor	(Brown);
	Button_Image(*BackButton1, *BackButton2, gap_button, gapImage, "assets/button/back.bmp");
	ColorButton	(*BackButton1, *BackButton2, Fill_Brown1, Fill_Brown2, Brown);
	
}

//Algoritma
void play_game() 
{ 
	Loading();

	//Kamus Data Lokal
	
	/*Pendeklarasian Koordinat Button*/
	Point ConsoleUpButton1, ConsoleUpButton2, ConsoleDownButton1, ConsoleDownButton2, ConsoleRightButton1, ConsoleRightButton2, ConsoleLeftButton1, ConsoleLeftButton2;	//batas koordinat dari console arrow button
	Point RandomButton1,RandomButton2,SolveButton1,SolveButton2,PauseButton1,PauseButton2,BackButton1,BackButton2;	//batas koordinat dari button menu pada play
	int gap_button 	= 5,	//batas antara button
		difColor 	= 5;	//perbedaan wawrna untuk button saat diklik
	
	/*Pendeklarasian Warna*/
	int Orange1 	 	 = COLOR(241,175, 1 + difColor),		 
		Fill_Orange1 	 = COLOR(241,175, 1), 	
		Fill_Orange2 	 = COLOR(230,134,24);
	int LightGreen1 	 = COLOR(180,190,65 + difColor),
		Fill_LightGreen1 = COLOR(180,190,65), 	
		Fill_LightGreen2 = COLOR(115,142,63);
	int DarkGreen1 		 = COLOR( 87,125,38 + difColor),
		Fill_DarkGreen1  = COLOR( 87,125,38), 	
		Fill_DarkGreen2  = COLOR( 38, 62,14);
	int Brown1 			 = COLOR(165, 97,42 + difColor), 
		Fill_Brown1   	 = COLOR(165, 97,42), 
		Fill_Brown2  	 = COLOR(105, 55,43);
	int DarkOrange1 	 = COLOR(230,134,24 + difColor),
		Fill_DarkOrange1 = COLOR(230,134,24),
		Fill_DarkOrange2 = COLOR(159, 58, 6);
	
	/*Array */
	int  element_puzzle[nPzl];
	int  PuzzleNumber[nPzl];
	
	PzlPosition Petak_Puzzle[nPzl];
	char ArrayGoal[nPzl];	//Array isi elemen puzzle
	int  ArrayIndexofArrayGoal[nPzl];	//Array yang berisi indeks dari aarray goal
	int  IndexEmptyPuzzleInRandomArrayGoal;	//nomor indeks empty puzzle saat setelah random
	int IndexEmpty;	//nomor indeks empty pada goal
	
	/*Deklarasi Setting player*/
	game_setting UserGameSetting;
	player PlayerInfo;
	
	bool valid, interupted, use_help;
	use_help 	= false;
	valid 		= false;
	
	int mX, mY;
	int PictureNumber, CurentPosition, IndexArrayGoal, IndexCurentPosition;
	short int depth;

	/*Deklarasi untuk proses game*/
	Tree treePuzzle;
	addressLink userMoves, userMoves1;
	infotypeLink temp;
	//open file goal_and_level_setting
	UserGameSetting=get_game_setting ();
	//log
	printf ("\nopen setting game file : %c\t", UserGameSetting.goal);
	printf ("%s\t", UserGameSetting.level);
	printf ("%s\t", UserGameSetting.song);
	printf ("%d\t", UserGameSetting.time_limit.minute);
	printf ("%d\t", UserGameSetting.time_limit.second);
	
	// set array goal
	memcpy(ArrayGoal, UserGameSetting.ArrGoal, sizeof(ArrayGoal)*nPzl);
	//	set posisi puzzle board
	letak(Petak_Puzzle);

    // get index of empty puzzle
    IndexEmpty = find_index_of_empty_puzzle(ArrayGoal);
    
    int count_leaf;
    addressLink leaf,CurentRandom, stackBacktrack, newNode, compareNewNode;
    infotype infoNewNode;
    address new_Node;
    bool firstPush = true, secondPush = true;
	depth = get_random_number(LIMIT_A, LIMIT_B);

	//log
	tree_and_leaf info;
	info = generate_tree(ArrayGoal, depth); 
	treePuzzle.root = info.root;
	printf("depth:%d\n");
	leaf = info.leaf;
	
	count_leaf=countleaf(leaf);
	CurentRandom=randomLeaf(leaf, count_leaf);

	userMoves = BackTrack(treePuzzle, CurentRandom);
	
	for(int i=0;i<nPzl;i++) ArrayIndexofArrayGoal[i]=i;
	stackBacktrack = randomGoal(userMoves, ArrayGoal, ArrayIndexofArrayGoal);
	
	//set screen and its element
	cleardevice();
//	PlaySound(gm_stg.song ,NULL,SND_ASYNC | SND_LOOP);
	readimagefile("assets/bg/game.bmp",0,0,900,600);
	
	//set player info
	strcpy(PlayerInfo.name, "");
	strcpy(PlayerInfo.level, UserGameSetting.level);
	PlayerInfo.movement 	 	= 0;
	PlayerInfo.time_left.minute = UserGameSetting.time_limit.minute-1;
	PlayerInfo.time_left.second = 59;
	
	Time_icon();
	ShowLevel(PlayerInfo.level);
	Goal(UserGameSetting.goal);
	Show_Image_Goal_Custom(UserGameSetting.ArrGoal);
	Button_Menu_Collection(&RandomButton1, &RandomButton2, &SolveButton1, &SolveButton2, &PauseButton1 ,&PauseButton2, &BackButton1, &BackButton2);
	Button_Arrow (&ConsoleUpButton1, &ConsoleUpButton2, &ConsoleRightButton1, &ConsoleRightButton2, &ConsoleDownButton1, &ConsoleDownButton2, &ConsoleLeftButton1, &ConsoleLeftButton2 );
	
	// get idx of empty puzzle in rand ArrGoal
    IndexEmptyPuzzleInRandomArrayGoal = find_index(ArrayIndexofArrayGoal,IndexEmpty);
    
	printf("\nidx_empty_pzl_in_rand_ArrGoal : %d - %d\n", IndexEmptyPuzzleInRandomArrayGoal,IndexEmpty);
    
	place_all_puzzle_on_board(Petak_Puzzle, ArrayIndexofArrayGoal, ArrayGoal);
	
	PlayerInfo.win = false;
	interupted  = false;
	
    while(!PlayerInfo.win && !interupted)
    {
		if(is_same_as_goal(ArrayIndexofArrayGoal))
		{
			PlayerInfo.win   = true;
			valid 			= true;
			break;
		}
		
    	while(!valid)
    	{
	    	Showtime(PlayerInfo.time_left);
	    	PlayerInfo.time_left.second--;
	    	
	    	if(PlayerInfo.time_left.minute<=0 && PlayerInfo.time_left.second<=0)
	    	{
				interupted=true;
				valid=true;
			}
			else if(PlayerInfo.time_left.second == 0)
			{
				PlayerInfo.time_left.minute--;
				PlayerInfo.time_left.second = 59;
			}
	
			getmouseclick(WM_LBUTTONDOWN,mX,mY);
	        delay(100);
	        
			if(mX >= RandomButton1.x and mX <= RandomButton2.x and mY >= RandomButton1.y and mY <= RandomButton2.y)
			{
				printf("\nrandom"); 	/* log */
				setcolor	(Orange1);
				Button		(RandomButton1, RandomButton2, gap_button);	
				ColorButton (RandomButton1, RandomButton2, Fill_Orange2, Fill_Orange1, Orange1);
				delay(100);
				ColorButton	(RandomButton1, RandomButton2, Fill_Orange1, Fill_Orange2, Orange1);
				
				stackBacktrack = deAlokasiStack(stackBacktrack);			
				CurentRandom=randomLeaf(leaf, count_leaf);
			//	printf("\nNode \n move : %d\n reverse : %d\n empty : %d\n parent : %d\n ", curRandom->info->infoTree.move, curRandom->info->infoTree.reverse, curRandom->info->infoTree.empty, curRandom->info->parent);
				userMoves = BackTrack(treePuzzle, CurentRandom);
				
				for(int i=0;i<nPzl;i++) ArrayIndexofArrayGoal[i]=i;
				stackBacktrack = randomGoal(userMoves, ArrayGoal, ArrayIndexofArrayGoal);
			
				// get idx of empty puzzle in rand ArrGoal
    			IndexEmptyPuzzleInRandomArrayGoal = find_index(ArrayIndexofArrayGoal,IndexEmpty);
    
				place_all_puzzle_on_board(Petak_Puzzle, ArrayIndexofArrayGoal, ArrayGoal);
				valid=true;
			}		        
	   		//button Pause
			if(mX >= PauseButton1.x and mX <= PauseButton2.x and mY >= PauseButton1.y and mY <= PauseButton2.y)
			{
				printf("\npause"); 	/* log */
				setcolor	(LightGreen1);
				Button		(PauseButton1, PauseButton2, gap_button);	
				ColorButton (PauseButton1 ,PauseButton2, Fill_LightGreen2, Fill_LightGreen1, LightGreen1);
	
				pause_act(PauseButton1, PauseButton2);
			}
			//button Back
			if(mX >= BackButton1.x and mX <= BackButton2.x and mY >= BackButton1.y and mY <= BackButton2.y)
			{
				printf("\nback"); 	/* log */
				setcolor	(Brown1);
				Button		(BackButton1, BackButton2, gap_button);		
				ColorButton (BackButton1, BackButton2, Fill_Brown2, Fill_Brown1, Brown1);
				delay(100);
				ColorButton (BackButton1, BackButton2, Fill_Brown1, Fill_Brown2, Brown1);
				
				interupted = true;
				set_goal_and_level();
			}
			//button Solve
			if(mX >= SolveButton1.x and mX <= SolveButton2.x and mY >= SolveButton1.y and mY <= SolveButton2.y)
			{
				printf("\nsolve"); 	/* log */
				setcolor	(DarkGreen1);
				Button		(SolveButton1, SolveButton2, gap_button);		
				ColorButton (SolveButton1, SolveButton2, Fill_DarkGreen2, Fill_DarkGreen1, DarkGreen1);
				delay(200);
				ColorButton (SolveButton1, SolveButton2, Fill_DarkGreen1, Fill_DarkGreen2, DarkGreen1);
				
				animatePuzzle(stackBacktrack, ArrayGoal, ArrayIndexofArrayGoal);
				
//				solve_puzzle(ArrayIndexofArrayGoal);
//				place_all_puzzle_on_board(Petak_Puzzle, ArrayIndexofArrayGoal, ArrayGoal);
				
				use_help = true;
				valid	 = true;
				delay(400);
			}
			
				/*		console button		*/        
			//button atas
			if(GetAsyncKeyState(VK_UP) or mX >= ConsoleUpButton1.x and mX <= ConsoleUpButton2.x and mY >= ConsoleUpButton1.y and mY <= ConsoleUpButton2.y)
			{
				if(IndexEmptyPuzzleInRandomArrayGoal!=0 and IndexEmptyPuzzleInRandomArrayGoal!=1 and IndexEmptyPuzzleInRandomArrayGoal!=2)
				{
					PlayerInfo.movement++;
					setcolor	(DarkOrange1);
					Button		(ConsoleUpButton1, ConsoleUpButton2, gap_button);	
					ColorButton	(ConsoleUpButton1, ConsoleUpButton2, Fill_DarkOrange2, Fill_DarkOrange1, DarkOrange1);
					delay(100);
					ColorButton	(ConsoleUpButton1, ConsoleUpButton2, Fill_DarkOrange1, Fill_DarkOrange2, DarkOrange1);

					IndexCurentPosition = IndexEmptyPuzzleInRandomArrayGoal-3;
					
					infoNewNode = set_info_tree_node(0, IndexEmptyPuzzleInRandomArrayGoal);
					new_Node = createNodeTree(infoNewNode);
					newNode = createNode(new_Node);
					
					if((stackBacktrack->info->infoTree.move)*(-1) == newNode->info->infoTree.move)
						temp = deleteAwal(&stackBacktrack);
					else
						push(&stackBacktrack, newNode);
					
					//swap position
					swap_position(&IndexEmptyPuzzleInRandomArrayGoal, IndexCurentPosition, ArrayIndexofArrayGoal, Petak_Puzzle, ArrayGoal);
					valid = true;
				}
				
			}
			//button bawah
			if(GetAsyncKeyState(VK_DOWN) or mX >= ConsoleDownButton1.x and mX <= ConsoleDownButton2.x and mY >= ConsoleDownButton1.y and mY <= ConsoleDownButton2.y)
			{
				if(IndexEmptyPuzzleInRandomArrayGoal!=6 and IndexEmptyPuzzleInRandomArrayGoal!=7 and IndexEmptyPuzzleInRandomArrayGoal!=8)
				{
					PlayerInfo.movement++;
					setcolor	(DarkOrange1);
					Button		(ConsoleDownButton1, ConsoleDownButton2, gap_button);		//ConsoleDownButton
					ColorButton	(ConsoleDownButton1, ConsoleDownButton2, Fill_DarkOrange2, Fill_DarkOrange1, DarkOrange1);
					delay(100);
					ColorButton	(ConsoleDownButton1, ConsoleDownButton2, Fill_DarkOrange1, Fill_DarkOrange2, DarkOrange1);
						
					IndexCurentPosition = IndexEmptyPuzzleInRandomArrayGoal+3;
					
					infoNewNode = set_info_tree_node(1, IndexEmptyPuzzleInRandomArrayGoal);
					new_Node = createNodeTree(infoNewNode);
					newNode = createNode(new_Node);
					
					if((stackBacktrack->info->infoTree.move)*(-1) == newNode->info->infoTree.move)
						temp = deleteAwal(&stackBacktrack);
					else
						push(&stackBacktrack, newNode);
					
					//swap position
					swap_position(&IndexEmptyPuzzleInRandomArrayGoal, IndexCurentPosition, ArrayIndexofArrayGoal, Petak_Puzzle, ArrayGoal);
					valid = true;
				}
				
			}
			//button kiri
			if(GetAsyncKeyState(VK_LEFT) or mX >= ConsoleLeftButton1.x and mX <= ConsoleLeftButton2.x and mY >= ConsoleLeftButton1.y and mY <= ConsoleLeftButton2.y)
			{
				if(IndexEmptyPuzzleInRandomArrayGoal!=0 and IndexEmptyPuzzleInRandomArrayGoal!=3 and IndexEmptyPuzzleInRandomArrayGoal!=6)
				{
					PlayerInfo.movement++;
					setcolor	(DarkOrange1);
					Button		(ConsoleLeftButton1, ConsoleLeftButton2, gap_button);		//ConsoleLeftButton
					ColorButton (ConsoleLeftButton1,ConsoleLeftButton2, Fill_DarkOrange2, Fill_DarkOrange1, DarkOrange1);
					delay(100);
					ColorButton (ConsoleLeftButton1, ConsoleLeftButton2, Fill_DarkOrange1, Fill_DarkOrange2, DarkOrange1);

					IndexCurentPosition = IndexEmptyPuzzleInRandomArrayGoal-1;
					
					infoNewNode = set_info_tree_node(2, IndexEmptyPuzzleInRandomArrayGoal);
					new_Node = createNodeTree(infoNewNode);
					newNode = createNode(new_Node);
					
					if((stackBacktrack->info->infoTree.move)*(-1) == newNode->info->infoTree.move)
						temp = deleteAwal(&stackBacktrack);
					else
						push(&stackBacktrack, newNode);
					
					//swap position
					swap_position(&IndexEmptyPuzzleInRandomArrayGoal, IndexCurentPosition, ArrayIndexofArrayGoal, Petak_Puzzle, ArrayGoal);
					valid = true;
				}
				
			}
			//button kanan
			if(GetAsyncKeyState(VK_RIGHT) or mX >= ConsoleRightButton1.x and mX <= ConsoleRightButton2.x and mY >= ConsoleRightButton1.y and mY <= ConsoleRightButton2.y)
			{
				if(IndexEmptyPuzzleInRandomArrayGoal!=2 and IndexEmptyPuzzleInRandomArrayGoal!=5 and IndexEmptyPuzzleInRandomArrayGoal!=8)
				{
					PlayerInfo.movement++;
					setcolor	(COLOR(230,134,30));
					Button		(ConsoleRightButton1, ConsoleRightButton2, gap_button);		//ConsoleRightButton
					ColorButton (ConsoleRightButton1, ConsoleRightButton2, COLOR(159,58,6), COLOR(230,134,24), COLOR(230,134,30));
					delay(100);
					ColorButton (ConsoleRightButton1, ConsoleRightButton2, COLOR(230,134,24), COLOR(159,58,6), COLOR(230,134,30));
					
					IndexCurentPosition = IndexEmptyPuzzleInRandomArrayGoal+1;
					
					infoNewNode = set_info_tree_node(3, IndexEmptyPuzzleInRandomArrayGoal);
					new_Node = createNodeTree(infoNewNode);
					newNode = createNode(new_Node);
					
					if((stackBacktrack->info->infoTree.move)*(-1) == newNode->info->infoTree.move)
						temp = deleteAwal(&stackBacktrack);
					else
						push(&stackBacktrack, newNode);
					
					//swap position
					swap_position(&IndexEmptyPuzzleInRandomArrayGoal, IndexCurentPosition, ArrayIndexofArrayGoal, Petak_Puzzle, ArrayGoal);
					valid = true;
				}
			}			    		    
		}	
		stackBacktrack = deAlokasiStack(info.leaf);
		inOrder(info.root);
		valid = false;
		clearmouseclick(WM_LBUTTONDOWN);	
	}
	
	treePuzzle.root = NULL;
	stackBacktrack  = NULL;
	//log
	printf("\ncurrent player data :\nlevel:%s\n", PlayerInfo.level);
	printf("movement:%d\n", PlayerInfo.movement);
	printf("result:%s\n", (PlayerInfo.win?"Success":"Failed"));
	printf("%d:%d\n", PlayerInfo.time_left.minute, PlayerInfo.time_left.second);

	delay(1000);
	
	strcpy(PlayerInfo.name, "");
	player PlayerName = inputname();
								
	strcpy(PlayerInfo.name, PlayerName.name);
		
	if(use_help) PlayerInfo.win = false;
	if(PlayerInfo.win)
	{
		int n_player_data;
		save_data_player(PlayerInfo);
		n_player_data = count_data_player();
		if(n_player_data>0)
		{
			player plyr[n_player_data];
			get_data_player(plyr);
			sort_data_rank(plyr, n_player_data);
			sort_file_rank();
		}
	}

	result(PlayerInfo);
}

game_setting input_custom(game_setting player_setting)
{
	set_custom_goal();

	//Kamus Data Lokal
	PzlPosition Petak_Puzzle[nPzl];
	game_setting custom_setting = player_setting, cheat_setting;
	char Image;	//gambar yang dipilih untuk custom goal
	boolean done=false, using_cheat=false;
	char path[25];
	int empty,	//pilihan kotak kosong
		i,	//counter looping
		mX,mY; //batas koordinat x dan y
	int IndexPuzzle[nPzl];
	char ArrGoal3[nPzl] = {'-','-','-','-','-','-','-','-','-'};
	
	for(i=0;i<nPzl;i++) IndexPuzzle[i]=i;
	
	//Algoritma
	memcpy(custom_setting.ArrGoal,ArrGoal3,sizeof(custom_setting.ArrGoal)*nPzl);
	set_puzzle_input_custom_coordinate(Petak_Puzzle);
	place_all_puzzle_on_board(Petak_Puzzle, IndexPuzzle, custom_setting.ArrGoal);
	
	empty=input_empty_puzzle(Petak_Puzzle);
	custom_setting.ArrGoal[empty]='0';
//============================================================================================================
	/*Displaying Button*/
	//Kamus Data Lokal
	int difColor = 5;
	Point ResetButton1, ResetButton2, BackButton1, BackButton2;
	Point DoneButton1 ,DoneButton2;
	int LightGreen   	 = COLOR(180,190,65), 
		LightGreen1  	 = COLOR(180,190,65 + difColor),
		Fill_LightGreen1 = COLOR(180,190,65), 	
		Fill_LightGreen2 = COLOR(115,142,63);
	int width 		= 120, 
	    height 		=  40, 
		gap_x 		= 135, 
		gap_button  =   5,
		gapImage 	=   6;

	ResetButton1.x = 65;
	ResetButton1.y = 485;
	ResetButton2.x = ResetButton1.x+width;
	ResetButton2.y = ResetButton1.y+height;		
	DoneButton1.x = 65+gap_x;
	DoneButton1.y = 485;
	DoneButton2.x = DoneButton1.x+width;
	DoneButton2.y = DoneButton1.y+height;
	height = width = 35;
	BackButton1.x = ORIGIN_POINT;
	BackButton1.y = ORIGIN_POINT;
	BackButton2.x = ORIGIN_POINT + width;
	BackButton2.y = ORIGIN_POINT + height;
	
	Point NextButton1, NextButton2;
	NextButton1.x = WIDTH - width;
	NextButton1.y = ORIGIN_POINT;
	NextButton2.x = WIDTH;
	NextButton2.y = ORIGIN_POINT + height;
	
//============================================================================================================	
	while(!done and !using_cheat)
	{
		Image=choose_pic(custom_setting.ArrGoal);
		
		// done
		if(Image == '-' and isArrFull(custom_setting.ArrGoal))
		{
			printf("\ndone"); 	
			setcolor	(LightGreen1);
			Button		(DoneButton1, DoneButton2, gap_button);	
			ColorButton (DoneButton1 ,DoneButton2, Fill_LightGreen2, Fill_LightGreen1, LightGreen1);
			delay(100);
			ColorButton (DoneButton1 ,DoneButton2, Fill_LightGreen1, Fill_LightGreen2, LightGreen1);
			delay(100);
					
			done=true;
//			return custom_setting;
		}
		// using cheat
		if(Image == 'C')
		{
			custom_setting = cheat_input_custom(find_index_of_empty_puzzle(custom_setting.ArrGoal));
			//log 
			printf("\ncheat process 2/2 done");

			using_cheat = true;
			delay(500);
		}
		
		if(!done and !using_cheat)
		{
			mX=-1;mY=-1;
			while (mX < 0 and mY < 0)
			{
				getmouseclick(WM_LBUTTONDOWN,mX,mY);
			    delay(100);
			}
//			//	button done
//			if(mX >= Do1.x and mX <= Do2.x and mY >= Do1.y and mY <= Do2.y || Image == '-')
//			{
//				if(isArrFull(custom_setting.ArrGoal))
//				{
//					printf("\ndone"); 	
//					setcolor	(LightGreen1);
//					Button		(Do1, Do2, gap_button);	
//					ColorButton (Do1 ,Do2, Fill_LightGreen2, Fill_LightGreen1, LightGreen1);
//					delay(100);
//					ColorButton (Do1 ,Do2, Fill_LightGreen1, Fill_LightGreen2, LightGreen1);
//					delay(100);
//					
//					done  = true;
//					break;
//				}
//			}
//	
//			//	button reset
//			else if(mX >= ResetButton1.x and mX <= ResetButton2.x and mY >= ResetButton1.y and mY <= ResetButton2.y)
//			{
//				reset_action(mX, mY, custom_setting.ArrGoal);
//			}
//			
//			//	button back
//		    else if(mX >= BackButton1.x and mX <= BackButton2.x and mY >= BackButton1.y and mY <= BackButton2.y)
//			{
//				back_action(mX, mY);
//			}
			
			// petak puzzle area
			if(mX>=Petak_Puzzle[0].t1.x and mX<=Petak_Puzzle[8].t2.x and mY>=Petak_Puzzle[0].t1.y and mY<=Petak_Puzzle[8].t2.y)
//			else if(mX>=Petak_Puzzle[0].t1.x and mX<=Petak_Puzzle[8].t2.x and mY>=Petak_Puzzle[0].t1.y and mY<=Petak_Puzzle[8].t2.y)
			{
				// jika gambar yang dipilih telah ada di puzzle maka declined
				if(Image != 'X')
				{
					for(int i=0;i<nPzl;i++)
					{  
						if(mX>=Petak_Puzzle[i].t1.x and mX<=Petak_Puzzle[i].t2.x and mY>=Petak_Puzzle[i].t1.y and mY<=Petak_Puzzle[i].t2.y and custom_setting.ArrGoal[i]!='0')
						{
							sprintf(path, "assets/element/puzzle/%c.bmp", Image);
							readimagefile(path, Petak_Puzzle[i].t1.x,Petak_Puzzle[i].t1.y,Petak_Puzzle[i].t2.x,Petak_Puzzle[i].t2.y);
							custom_setting.ArrGoal[i]=Image;
							break;
						}	
					}
				}
			}			
		}		
		clearmouseclick(WM_LBUTTONDOWN);
	}
	
	return custom_setting;

}

addressLink BackTrack (Tree root, addressLink leaf)
{
	addressLink stack = NULL, stack1 = NULL, newNode;
//	addressLink front = NULL, rear = NULL, newNode;
	address node, pcur, info;
	
	pcur = leaf->info;
	node = pcur;

	while(pcur->parent!=NULL)
	{
//		printf("\nbacktrack");
		newNode = createNode(node);
//		enque(&front, &rear, node);
		insertAwal(&stack,newNode);
		pcur = pcur->parent;
		node = pcur;
	}

	return stack;
//	return front;
}

addressLink randomLeaf(addressLink Front, int leaf)
{
	//kamus data lokal
	unsigned short LeafNumber,i;
	addressLink pCur;
	//algoritma
	LeafNumber=get_random_number(1, leaf);
	printf("chosen leaf : %d th node\n", LeafNumber);
	pCur=Front;
	for(i=0;i<LeafNumber;i++)
	{
		pCur=pCur->next;
	}
	return pCur;
}

