#include "46_Kiki_Pratiwi.h"
#include "50_Mufida_Nuha_S.h"
#include "65_Velia_Sagita_P.h"
#include "54_Nikita_Nabila.h"
#include "03_Ananda_K.h"

//========================================================Screen Feature============================================================//
void splash_screen()
{
	cleardevice();
	
	//set background
	readimagefile("assets/bg/splash_screen.bmp",ORIGIN_POINT, ORIGIN_POINT, WIDTH, HEIGHT); 
	
	int  width = 0, init_width = 60;
	int  left = 240, right = 292, top = 441, bottom = 507;
	char path[23];
	
	// initializing player name
	strcpy(latest_player_name,"");
	
	//play sound in background
	PlaySound("sounds/loading.wav", NULL, SND_FILENAME | SND_SYNC);		

	for (int i=0; i<7; i++)
	{
		sprintf(path, "assets/element/loading/%d.jpg", i+1);
		readimagefile(path, left+width, top, right+width, bottom);
		
		PlaySound("sounds/loading.wav", NULL, SND_FILENAME | SND_SYNC);
		
		width += init_width;
	}
	delay(1000);
}

//=======================================================Set Goal Feature==========================================================//
void set_goal_and_level()
{
	cleardevice();
	readimagefile("assets/bg/set_level_&_goal.bmp",0,0,WIDTH,HEIGHT);
//    PlaySound("sounds/goal_and_level.wav",NULL,SND_ASYNC | SND_LOOP);
	
	int mX, mY;
	bool valid=false, next_clicked=false;
	game_setting setting, custom;

	// button point
	Point E1, E2, M1, M2, H1, H2, 
		  ga1, ga2, gb1, gb2, gc1, gc2, 
		  Bck1, Bck2, nxt1, nxt2;
	
	// button size	
	int gapImage 	=   8, 
		gap_button  =   5, 
		difColor    =   5, 
		width       = 135, 
		height 	    = 145,
		gap_x       = 250;

	// button color initializing
	int Orange 			 = COLOR(241,175,1), 		
		Fill_Orange1	 = COLOR(241,175,1), 	
		Fill_Orange2	 = COLOR(230,134,24);
	int LightGreen 		 = COLOR(180,190,65), 
		Fill_LightGreen1 = COLOR(180,190,65), 	
		Fill_LightGreen2 = COLOR(115,142,63);
	int Brown 			 = COLOR(165,97,42), 	
		Fill_Brown1 	 = COLOR(165,97,42), 
		Fill_Brown2 	 = COLOR(105,55,43);
	int SkyBlue 		 = COLOR(218,239,255),
		Fill_SkyBlue	 = COLOR(218,239,255);
	int DarkOrange 		 = COLOR(229,133,30),
		Fill_DarkOrange  = COLOR(229,133,30);
			
	/* set appearance of goal button	*/
	//	goal1 button
	ga1.x = 138;
	ga1.y = 233;
	ga2.x = ga1.x + width;
	ga2.y = ga1.y + height;
	setcolor	(DarkOrange);
	Button_Image(ga1, ga2, gap_button, gapImage, "assets/button/goal1.bmp");
	ColorButton	(ga1, ga2, Fill_DarkOrange, Fill_DarkOrange, DarkOrange);
		
	//	goal2 button
	gb1.x = ga1.x + gap_x;
	gb1.y = ga1.y;
	gb2.x = gb1.x + width;
	gb2.y = gb1.y + height;
	setcolor	(SkyBlue);
	Button_Image(gb1, gb2, gap_button, gapImage, "assets/button/goal2.bmp");
	ColorButton	(gb1, gb2, Fill_SkyBlue, Fill_SkyBlue, SkyBlue);	

	//	goal3 button
	gc1.x = gb1.x + gap_x;
	gc1.y = gb1.y;
	gc2.x = gc1.x + width;
	gc2.y = gc1.y + height;
	setcolor	(SkyBlue);
	Button_Image(gc1, gc2, gap_button, gapImage, "assets/button/goal_custom.bmp");
	ColorButton	(gc1, gc2, Fill_SkyBlue, Fill_SkyBlue, SkyBlue); 	
	
	gapImage = 5,	width = 160, height = 40, gap_x = 253;
	
	/* set appearance of level button	*/
	//	easy button
	E1.x = 120;
	E1.y = 485;
	E2.x = E1.x + width;
	E2.y = E1.y + height;
	setcolor(Orange);
	Button_Image(E1,E2, gap_button, gapImage, "assets/button/easy.bmp");	
	ColorButton(E1,E2, Fill_Orange2, Fill_Orange1, Orange);
	
	//	medium button
	M1.x = E1.x + gap_x;
	M1.y = E1.y;
	M2.x = M1.x + width;
	M2.y = M1.y + height;
	setcolor	(LightGreen);
	Button_Image(M1, M2, gap_button, gapImage, "assets/button/medium.bmp");
	ColorButton	(M1, M2, Fill_LightGreen1, Fill_LightGreen2, LightGreen);	

	//	hard button
	H1.x = M1.x + gap_x;
	H1.y = M1.y;
	H2.x = H1.x + width;
	H2.y = H1.y + height;
	setcolor	(Brown);
	Button_Image(H1, H2, gap_button, gapImage, "assets/button/hard.bmp");
	ColorButton	(H1, H2, Fill_Brown1, Fill_Brown2, Brown);		
	
	height = 35, width = 35;
	
	/* set appearance of back button */
	Bck1.x = ORIGIN_POINT;
	Bck1.y = ORIGIN_POINT;
	Bck2.x = ORIGIN_POINT + width;
	Bck2.y = ORIGIN_POINT + height;
	set_back_button();
	
	/* set appearance of next button */
	nxt1.x = WIDTH - width;
	nxt1.y = ORIGIN_POINT;
	nxt2.x = WIDTH;
	nxt2.y = ORIGIN_POINT + height;
	set_next_button();
	
	// default setting
	char ArrGoal1[nPzl] = {'1','2','3','4','5','6','7','8','0'};
	char ArrGoal2[nPzl] = {'1','2','3','8','0','4','7','6','5'};
	
	setting.goal 			  = '1';
	setting.level 			  = "Easy"; 
	setting.time_limit.minute =  10;
	setting.time_limit.second =   0;
	setting.song 			  = "sounds/easygame.wav";	
	
	while(!next_clicked)
	{   
	    while(!valid)
	    {
	    	getmouseclick(WM_LBUTTONDOWN,mX,mY);
	    	delay(100);
	    	
			//	back button
		    if(mX >= Bck1.x and mX <= Bck2.x and mY >= Bck1.y and mY <= Bck2.y)
			{
	    		PlaySound("sounds/opening.wav",NULL,SND_ASYNC | SND_LOOP);
		    	back_button_effect();
		    
		    	main_menu();
			}
			//	next button 
			if(mX >= nxt1.x and mX <= nxt2.x and mY >= nxt1.y and mY <= nxt2.y)
			{
				next_clicked = true;
				next_button_effect();
				
				// memory copy array goal
				switch(setting.goal)
				{
					case '1' : memcpy(setting.ArrGoal, ArrGoal1, sizeof(setting.ArrGoal)*nPzl);	break;
					case '2' : memcpy(setting.ArrGoal, ArrGoal2, sizeof(setting.ArrGoal)*nPzl);	break;
					case '3' : memcpy(setting.ArrGoal, custom.ArrGoal, sizeof(setting.ArrGoal)*nPzl); break;
					default  : memcpy(setting.ArrGoal, ArrGoal1, sizeof(setting.ArrGoal)); break;
				}
				
				save_setting(setting);
				printf("\nsave setting game :%c-%s-%s-%d mnt", setting.goal, setting.level, setting.song, setting.time_limit.minute);
		
				// go to play screen
				play_game();
			}
			
		    /*	set goal button	*/
			if(mX >= ga1.x and mX <= ga2.x and mY >= ga1.y and mY <= ga2.y)
			{
				printf("\ngoal1"); 	/* log */
								
				setting.goal = '1';
				valid = true;
				
				int SkyBlue 		 = COLOR(218,239,255),
					Fill_SkyBlue	 = COLOR(218,239,255);
				int DarkOrange 		 = COLOR(229,133,30),
					Fill_DarkOrange  = COLOR(229,133,30);					
				
				//	efek button clicked
 				setcolor	(DarkOrange);
				Button		(ga1, ga2, gap_button);
				ColorButton (ga1, ga2, Fill_DarkOrange, Fill_DarkOrange, DarkOrange);
				delay(100);
				setcolor	(SkyBlue);
				Button		(gb1, gb2, gap_button);
				ColorButton (gb1, gb2, Fill_SkyBlue, Fill_SkyBlue, SkyBlue);
				setcolor	(SkyBlue);
				Button		(gc1, gc2, gap_button);
				ColorButton	(gc1, gc2, Fill_SkyBlue, Fill_SkyBlue, SkyBlue);
			}
			else if(mX >= gb1.x and mX <= gb2.x and mY >= gb1.y and mY <= gb2.y)
			{
				printf("\ngoal2"); 	/* log */
				
				setting.goal = '2';
				valid		 = true;
				
				int SkyBlue 		 = COLOR(218,239,255),
					Fill_SkyBlue	 = COLOR(218,239,255);
				int DarkOrange 		 = COLOR(229,133,30),
					Fill_DarkOrange  = COLOR(229,133,30);
				
				//	efek button clicked
				setcolor	(DarkOrange);
				Button		(gb1, gb2, gap_button);
				ColorButton	(gb1, gb2, Fill_DarkOrange, Fill_DarkOrange, DarkOrange);
				delay(100);
				setcolor	(SkyBlue);
				Button		(ga1, ga2, gap_button);
				ColorButton	(ga1,ga2, Fill_SkyBlue, Fill_SkyBlue, SkyBlue);	
				setcolor	(SkyBlue);
				Button		(gc1, gc2, gap_button);
				ColorButton	(gc1,gc2, Fill_SkyBlue, Fill_SkyBlue, SkyBlue);	
			}
			else if(mX >= gc1.x and mX <= gc2.x and mY >= gc1.y and mY <= gc2.y)
			{
				printf("\ngoalcustom"); 	/* log */
				
				setting.goal = '3';
				valid		 = true;
				
				int SkyBlue 		 = COLOR(218,239,255),
					Fill_SkyBlue	 = COLOR(218,239,255);
				int DarkOrange 		 = COLOR(229,133,30),
					Fill_DarkOrange  = COLOR(229,133,30);
				
				//	efek button clicked
				setcolor	(DarkOrange);
				Button		(gc1, gc2, gap_button);
				ColorButton	(gc1, gc2, Fill_DarkOrange, Fill_DarkOrange, DarkOrange);
				delay(100);
				setcolor	(SkyBlue);
				Button		(ga1, ga2, gap_button);
				ColorButton	(ga1,ga2, Fill_SkyBlue, Fill_SkyBlue, SkyBlue);
				setcolor	(SkyBlue);
				Button		(gb1, gb2, gap_button);
				ColorButton	(gb1, gb2, Fill_SkyBlue, Fill_SkyBlue, SkyBlue);

				custom = input_custom(setting);
				show_all_button_set_goal_and_level(setting.level, setting.goal);
			}
				
		    /*	set level button	*/
			if(mX >= E1.x and mX <= E2.x and mY >= E1.y and mY <= E2.y)
			{
				printf("\neasy"); 	/* log */
				
				setting.level 				= "Easy";
				setting.song 				= "sounds/easygame.wav";
				setting.time_limit.minute 	= 10;
				valid = true;
				
				int Orange1 		 = COLOR(241,175,6),		 
					Fill_Orange1	 = COLOR(241,175,1), 	
					Fill_Orange2	 = COLOR(230,134,24);
				int LightGreen2 	 = COLOR(180,190,75),	 
					Fill_LightGreen1 = COLOR(180,190,65), 	
					Fill_LightGreen2 = COLOR(115,142,63);
				int Brown2 			 = COLOR(165,97,52), 
					Fill_Brown1 	 = COLOR(165,97,42), 
					Fill_Brown2 	 = COLOR(105,55,43);
				
				//	efek button clicked
				setcolor	(Orange1);
				Button		(E1, E2, gap_button);	
				ColorButton	(E1, E2, Fill_Orange2, Fill_Orange1, Orange1);	
				delay(100);
				setcolor	(LightGreen2);
				Button		(M1, M2, gap_button);	
				ColorButton	(M1, M2, Fill_LightGreen1, Fill_LightGreen2, LightGreen2);
				setcolor	(Brown2);
				Button		(H1, H2, gap_button);		
				ColorButton	(H1,H2, Fill_Brown1, Fill_Brown2, Brown2);
			}
			else if(mX >= M1.x and mX <= M2.x and mY >= M1.y and mY <= M2.y)
			{
				printf("\nmedium"); 	/* log */
			
				setting.level 				= "Medium";
				setting.song 				= "sounds/mediumgame.wav";
				setting.time_limit.minute	= 5;
				valid = true;
			
				int Orange2 		 = COLOR(241,175,11),
					Fill_Orange1	 = COLOR(241,175,1), 	
					Fill_Orange2	 = COLOR(230,134,24);
				int LightGreen1 	 = COLOR(180,190,70),
					Fill_LightGreen1 = COLOR(180,190,65), 	
					Fill_LightGreen2 = COLOR(115,142,63);
				int Brown2 			 = COLOR(165,97,52), 
					Fill_Brown1 	 = COLOR(165,97,42), 
					Fill_Brown2 	 = COLOR(105,55,43);				
			
				//	efek button clicked
				setcolor	(LightGreen1);
				Button		(M1, M2, gap_button);	
				ColorButton	(M1, M2, Fill_LightGreen2, Fill_LightGreen1, LightGreen1);	
				delay(100);
				setcolor	(Brown2);
				Button		(H1, H2, gap_button);		
				ColorButton	(H1,H2, Fill_Brown1, Fill_Brown2, Brown2);
				setcolor	(Orange2);
				Button		(E1, E2, gap_button);	
				ColorButton	(E1, E2, Fill_Orange1, Fill_Orange2, Orange2);
			}
			else if(mX >= H1.x and mX <= H2.x and mY >= H1.y and mY <= H2.y)
			{
				printf("\nhard"); 	/* log */
				
				setting.level 				= "Hard";
				setting.song 				= "sounds/hardgame.wav";
				setting.time_limit.minute 	= 3;
				valid = true;
				
				int	Orange2 		 = COLOR(241,175,11),
					Fill_Orange1	 = COLOR(241,175,1), 	
					Fill_Orange2	 = COLOR(230,134,24);
				int LightGreen2 	 = COLOR(180,190,75),	 
					Fill_LightGreen1 = COLOR(180,190,65), 	
					Fill_LightGreen2 = COLOR(115,142,63);
				int Brown1 			 = COLOR(165,97,47), 
					Fill_Brown1 	 = COLOR(165,97,42), 
					Fill_Brown2 	 = COLOR(105,55,43);
				
				//	efek button clicked
				setcolor	(Brown1);
				Button		(H1, H2, gap_button);
				ColorButton	(H1, H2, Fill_Brown2, Fill_Brown1, Brown1);			
				delay(100);
				setcolor	(Orange2);
				Button		(E1, E2, gap_button);	
				ColorButton	(E1, E2, Fill_Orange1, Fill_Orange2, Orange2);
				setcolor	(LightGreen2);
				Button		(M1, M2, gap_button);	
				ColorButton	(M1, M2, Fill_LightGreen1, Fill_LightGreen2, LightGreen2);
			}
		}
		
		delay(200);
		valid = false;
		clearmouseclick(WM_LBUTTONDOWN);		
	}
}

void set_puzzle_input_custom_coordinate(PzlPosition Petak_Puzzle[])
{
	int init_height = 135;
	int init_width  = 18;
	int init_gap	= 100;
	int min_y  = MINIMUM+init_height;
	int min_x  = MINIMUM+init_width;
	
	for (int i = 0;i<nPzl;i+=3)
	{
		Petak_Puzzle[i].t1.x   = min_x;
		Petak_Puzzle[i].t2.x   = min_x + init_gap;
		Petak_Puzzle[i+1].t1.x = Petak_Puzzle[i].t2.x;
		Petak_Puzzle[i+1].t2.x = Petak_Puzzle[i].t2.x +init_gap;
		Petak_Puzzle[i+2].t1.x = Petak_Puzzle[i+1].t2.x;
		Petak_Puzzle[i+2].t2.x = Petak_Puzzle[i+1].t2.x + init_gap;
		
		for(int j=i;j<=i+2;j++)
		{
			Petak_Puzzle[j].t1.y = min_y;
			Petak_Puzzle[j].t2.y = min_y + init_gap;
		}
		min_y = min_y + init_gap;
	}
}

game_setting cheat_input_custom(int empty)
{
	//log 
	printf("\ncheat");
	
	PzlPosition  Petak_Puzzle[nPzl];
	game_setting custom_setting;
	char ArrGoal3[nPzl] = {'a','b','c','d','e','f','g','h','i'};
	int  idx_pzl[nPzl];
	
	for(int i=0;i<nPzl;i++) idx_pzl[i]=i;
	set_puzzle_input_custom_coordinate(Petak_Puzzle);
	
	memcpy(custom_setting.ArrGoal,ArrGoal3,sizeof(custom_setting.ArrGoal)*nPzl);
	custom_setting.ArrGoal[empty]='0';
	
	int LightGreen = COLOR(180,190,65);
	PzlPosition coordinate[24];
	Pic_Position(coordinate);
		
	// empty puzzle placed
	readimagefile("assets/element/puzzle/empty.bmp", Petak_Puzzle[empty].t1.x,Petak_Puzzle[empty].t1.y,Petak_Puzzle[empty].t2.x,Petak_Puzzle[empty].t2.y);
	
	// puzzle element palced on board
	for (int i=0 ; i<nPzl; i++)
	{
		if(i != empty)
		{
			printf("\nposisi %d  oleh  gambar : %c", i, custom_setting.ArrGoal[i]);
	        show_board_element(Petak_Puzzle[i].t1, Petak_Puzzle[i].t2, custom_setting.ArrGoal[i]);
	        Box_Pic(LightGreen, coordinate[i].t1, coordinate[i].t2);
		}
        delay(200);
    }
		
	//log 
	printf("\ncheat process 1/2 done");
	
	return custom_setting;
}

void back_action(int mX, int mY)
{
	//Deklarasi variabel titik
	Point backButton1, backButton2;

	/* = = = jarak antara koordinat = = = */
	int	gap_x 		= 135,	// antara dua button secara horizontal
		gap_button  =   5,	// antara dua button secara vertikal
		gapImage 	=   6,	// antara gambar dan button
		height 		=  35,	// dalam satu button secara horizontal
		width 		=  35; 	// dalam satu button secara vertikal
	
	/*	button back	*/
	backButton1.x = ORIGIN_POINT;
	backButton1.y = ORIGIN_POINT;
	backButton2.x = ORIGIN_POINT + width;
	backButton2.y = ORIGIN_POINT + height;
					
	//	button back action
	back_button_effect();
	set_goal_and_level();
}

void reset_action(char arr_custom_setting[])
{
	/* = = = Kamus Data Lokal = = = */
	// Deklarasi posisi puzzle
	PzlPosition Petak_Puzzle[nPzl+1];
	
	/* Deklarasi yang merepresentasikan puzzle kembali kosong */
	int idx_pzl[nPzl];
	int idx_empty= 0;
	char ArrGoal3[nPzl] = {'-','-','-','-','-','-','-','-','-'};
	for(int i=0;i<nPzl;i++) idx_pzl[i]=i;
	PzlPosition coordinate[24];
	char path[28];
	int alphabet_initial = 'a';
		
	//Define position per box (element)
	Pic_Position(coordinate);
	
	/* jarak antara koordinat*/	
	int width 		= 120,	// dalam satu button secara horizontal 
	    height 		=  40,	// dalam satu button secara vertikal
		gap_x 		= 135,	// antara dua button secara horizontal
		gap_button  =   5,	// antara dua button secara vertikal
		gapImage 	=   6;	// antara gambar dan button
		
	//Deklarasi variabel titik	
	Point resetButton1, resetButton2;
	
	/* reset Button */
	resetButton1.x = 65;
	resetButton1.y = 485;
	resetButton2.x = resetButton1.x+width;
	resetButton2.y = resetButton1.y+height;
		
	/* Deklarasi warna */	
	int orange1 = COLOR(241,175,6),		 
		orange2	= COLOR(241,175,1), 	
		orange3 = COLOR(230,134,24);
		
	/* button reset */
	printf("\nreset");
	setcolor	(orange1);
	Button		(resetButton1, resetButton2, gap_button);	
	ColorButton	(resetButton1, resetButton2, orange3, orange2, orange1);		
	delay(100);
	ColorButton	(resetButton1, resetButton2, orange2, orange3, orange1);
			
	for(int i=0;i<24;i++)
	{
		sprintf(path,"assets/element/puzzle/customgoal/%c.bmp", i+alphabet_initial);
		readimagefile(path, coordinate[i].t1.x, coordinate[i].t1.y, coordinate[i].t2.x, coordinate[i].t2.y);
	}	
		
	//	replace and reset puzzle
	memcpy(arr_custom_setting,ArrGoal3,sizeof(arr_custom_setting)*nPzl);
	set_puzzle_input_custom_coordinate(Petak_Puzzle);
	place_all_puzzle_on_board(Petak_Puzzle, idx_pzl, arr_custom_setting);
	
	//	back to input empty puzzle
	idx_empty=input_empty_puzzle(Petak_Puzzle);
	arr_custom_setting[idx_empty]='0';
}

void show_all_button_set_goal_and_level(char* level, char goal)
{
	cleardevice();
	readimagefile("assets/bg/set_level_&_goal.bmp",0,0,WIDTH,HEIGHT);
	
	// button size initialization
	int gapImage 	=   8, 
		gap_button  =   5, 
		difColor    =   5, 
		width       = 135, 
		height 	    = 145,
		gap_x       = 250;
	
	// button point	
	Point E1, E2, M1, M2, H1, H2, 
		  ga1, ga2, gb1, gb2, gc1, gc2, 
		  Bck1, Bck2, nxt1, nxt2;
	
	// button color
	int Orange 			 = COLOR(241,175,1), 		
		Orange1 		 = COLOR(241,175,1 + difColor),		 
		Orange2 		 = COLOR(241,175,1 + (2*difColor)),
		Fill_Orange1	 = COLOR(241,175,1), 	
		Fill_Orange2	 = COLOR(230,134,24);
	int LightGreen 		 = COLOR(180,190,65), 
		LightGreen1 	 = COLOR(180,190,65 + difColor),
		LightGreen2 	 = COLOR(180,190,65 + (2*difColor)),	 
		Fill_LightGreen1 = COLOR(180,190,65), 	
		Fill_LightGreen2 = COLOR(115,142,63);
	int Brown 			 = COLOR(165,97,42), 	
		Brown1 			 = COLOR(165,97,42 + difColor), 
		Brown2 			 = COLOR(165,97,42 + (2*difColor)), 
		Fill_Brown1 	 = COLOR(165,97,42), 
		Fill_Brown2 	 = COLOR(105,55,43);
	int SkyBlue 		 = COLOR(218,239,255),
		Fill_SkyBlue	 = COLOR(218,239,255);
	int DarkOrange 		 = COLOR(229,133,30),
		Fill_DarkOrange  = COLOR(229,133,30);
	
	/*		button set goal	*/
	//	goal1 button
	ga1.x = 138;
	ga1.y = 233;
	ga2.x = ga1.x + width;
	ga2.y = ga1.y + height;
	Button_Image(ga1, ga2, gap_button, gapImage, "assets/button/goal1.bmp");
		
	//	goal2 button
	gb1.x = ga1.x + gap_x;
	gb1.y = ga1.y;
	gb2.x = gb1.x + width;
	gb2.y = gb1.y + height;
	Button_Image(gb1, gb2, gap_button, gapImage, "assets/button/goal2.bmp");

	//	goal3 button
	gc1.x = gb1.x + gap_x;
	gc1.y = gb1.y;
	gc2.x = gc1.x + width;
	gc2.y = gc1.y + height;
	Button_Image(gc1, gc2, gap_button, gapImage, "assets/button/goal_custom.bmp");
	
	gapImage = 5,	width = 160, height = 40, gap_x = 253;
	
	/*	set button  level	*/
	//	easy button
	E1.x = 120;
	E1.y = 485;
	E2.x = E1.x + width;
	E2.y = E1.y + height;
	Button_Image(E1,E2, gap_button, gapImage, "assets/button/easy.bmp");
	
	//	medium button
	M1.x = E1.x + gap_x;
	M1.y = E1.y;
	M2.x = M1.x + width;
	M2.y = M1.y + height;
	Button_Image(M1, M2, gap_button, gapImage, "assets/button/medium.bmp");	

	//	hard button
	H1.x = M1.x + gap_x;
	H1.y = M1.y;
	H2.x = H1.x + width;
	H2.y = H1.y + height;
	Button_Image(H1, H2, gap_button, gapImage, "assets/button/hard.bmp");
	
	height = 35, width = 35;
	
	/* button back */
	Bck1.x = ORIGIN_POINT;
	Bck1.y = ORIGIN_POINT;
	Bck2.x = ORIGIN_POINT + width;
	Bck2.y = ORIGIN_POINT + height;
	set_back_button();
	
	/* button next */
	nxt1.x = WIDTH - width;
	nxt1.y = ORIGIN_POINT;
	nxt2.x = WIDTH;
	nxt2.y = ORIGIN_POINT + height;
	set_next_button();

    /*	set goal button	*/
	if(goal == '1')
	{
		//	efek button clicked
		setcolor	(DarkOrange);
		Button		(ga1, ga2, gap_button);
		ColorButton (ga1, ga2, Fill_DarkOrange, Fill_DarkOrange, DarkOrange);
		delay(100);
		setcolor	(SkyBlue);
		Button		(gb1, gb2, gap_button);
		ColorButton (gb1, gb2, Fill_SkyBlue, Fill_SkyBlue, SkyBlue);
		setcolor	(SkyBlue);
		Button		(gc1, gc2, gap_button);
		ColorButton	(gc1, gc2, Fill_SkyBlue, Fill_SkyBlue, SkyBlue);
	}
	else if(goal == '2')
	{	
		//	efek button clicked
		setcolor	(DarkOrange);
		Button		(gb1, gb2, gap_button);
		ColorButton	(gb1, gb2, Fill_DarkOrange, Fill_DarkOrange, DarkOrange);
		delay(100);
		setcolor	(SkyBlue);
		Button		(ga1, ga2, gap_button);
		ColorButton	(ga1,ga2, Fill_SkyBlue, Fill_SkyBlue, SkyBlue);	
		setcolor	(SkyBlue);
		Button		(gc1, gc2, gap_button);
		ColorButton	(gc1,gc2, Fill_SkyBlue, Fill_SkyBlue, SkyBlue);	
	}
	else
	{
	//	efek button clicked
		setcolor	(DarkOrange);
		Button		(gc1, gc2, gap_button);
		ColorButton	(gc1, gc2, Fill_DarkOrange, Fill_DarkOrange, DarkOrange);
		delay(100);
		setcolor	(SkyBlue);
		Button		(ga1, ga2, gap_button);
		ColorButton	(ga1,ga2, Fill_SkyBlue, Fill_SkyBlue, SkyBlue);
		setcolor	(SkyBlue);
		Button		(gb1, gb2, gap_button);
		ColorButton	(gb1, gb2, Fill_SkyBlue, Fill_SkyBlue, SkyBlue);
	}
	
	/*set level button */
	if(level == "Easy")
	{
		//	efek button clicked
		setcolor	(Orange1);
		Button		(E1, E2, gap_button);	
		ColorButton	(E1, E2, Fill_Orange2, Fill_Orange1, Orange1);	
		delay(100);
		setcolor	(LightGreen2);
		Button		(M1, M2, gap_button);	
		ColorButton	(M1, M2, Fill_LightGreen1, Fill_LightGreen2, LightGreen2);
		setcolor	(Brown2);
		Button		(H1, H2, gap_button);		
		ColorButton	(H1,H2, Fill_Brown1, Fill_Brown2, Brown2);
		printf("show all easy\n");
	}
	else if(level == "Medium")
	{
		//	efek button clicked
		setcolor	(LightGreen1);
		Button		(M1, M2, gap_button);	
		ColorButton	(M1, M2, Fill_LightGreen2, Fill_LightGreen1, LightGreen1);	
		delay(100);
		setcolor	(Brown2);
		Button		(H1, H2, gap_button);		
		ColorButton	(H1,H2, Fill_Brown1, Fill_Brown2, Brown2);
		setcolor	(Orange2);
		Button		(E1, E2, gap_button);	
		ColorButton	(E1, E2, Fill_Orange1, Fill_Orange2, Orange2);
		printf("show all medium\n");
	}
	else
	{
		//	efek button clicked
		setcolor	(Brown1);
		Button		(H1, H2, gap_button);
		ColorButton	(H1, H2, Fill_Brown2, Fill_Brown1, Brown1);			
		delay(100);
		setcolor	(Orange2);
		Button		(E1, E2, gap_button);	
		ColorButton	(E1, E2, Fill_Orange1, Fill_Orange2, Orange2);
		setcolor	(LightGreen2);
		Button		(M1, M2, gap_button);	
		ColorButton	(M1, M2, Fill_LightGreen1, Fill_LightGreen2, LightGreen2);
	}
}

void save_data_player(player p)
{
	FILE *fplayer;
	int  chars;

	fplayer = fopen("player_master.dat", "ab");	
	chars   = fwrite(&p, sizeof(p), 1, fplayer);
	printf ("%d data saved to file\n", chars); 	/* log */
	fclose (fplayer);
}

//========================================================Play Feature============================================================//
int count_data_player()
{
	player data;
	FILE   *fplayer;
	int    tot_data=0;
          
	if((fplayer=fopen("player_master.dat", "rb"))==NULL) printf("opening file failed\n");
	else
	{
		rewind(fplayer);
		while ( fread(&data, sizeof(data), 1, fplayer) == 1) tot_data++;
	}

	fclose(fplayer);
	
	return tot_data;
}

void get_data_player(player p[])
{
	player data;
	FILE   *fplayer;
	int    idx=0;
          
	if((fplayer=fopen("player_master.dat","rb"))==NULL)	printf("File tidak dapat dibuat!\r\n");
	else {
		player temp, player;

		rewind(fplayer);
		while((fread(&data,sizeof(data),1,fplayer))==1)
		{
			strcpy(p[idx].name,  data.name);
			strcpy(p[idx].level, data.level);
			p[idx].win 			= data.win;
			p[idx].movement 	= data.movement;
			p[idx].time_left	= data.time_left;
			idx++;
		}
	}
	fclose(fplayer);
}

void sort_file_rank()
{
	FILE *fplayer;
          
	if((fplayer=fopen("player_master.dat","rb+"))==NULL)
	{
		printf("File tidak dapat dibuat!\r\n");
	}
	else {
		player temp, player;
		int structSize;
		int fileSize;
		
		structSize = sizeof(player);
		fseek(fplayer, 0, SEEK_END);
		fileSize = ftell(fplayer);
		rewind(fplayer);
		  
		for (int i = 0; i < fileSize; i += structSize){
		  for (int j = 0; j < (fileSize - structSize); j += structSize){
		    fread(&player, structSize, 1, fplayer);
		    fread(&temp, structSize, 1, fplayer);
		    if (player.time_left.minute <= temp.time_left.minute && player.time_left.second <= temp.time_left.second)
			{
		      fseek(fplayer, -(structSize * 2), SEEK_CUR);
		      fwrite(&temp, structSize, 1, fplayer);
		      fwrite(&player, structSize, 1, fplayer);
		      fseek(fplayer, -structSize, SEEK_CUR);
		    }
		    else{
		      fseek(fplayer, -structSize, SEEK_CUR);
		    }
		  }
		  rewind(fplayer);
		}
		fclose(fplayer);
	}
}

void sort_data_rank(player p[], int n)
{
	FILE *fplayer;
	int i, j, min_idx;
	
	for(i=0;i<n;i++)
	{
		printf("\ncurrent player data :\nlevel:%s\n", p[i].level);
		printf("%s\n", p[i].name);
		printf("%d\n", p[i].movement);
		printf("%s\n", (p[i].win?"Success":"Failed"));
		printf("%d:%d\n", p[i].time_left.minute, p[i].time_left.second);
	}
          
	if((fplayer=fopen("player_master.dat","rb+"))==NULL)
	{
		printf("File tidak dapat dibuat!\r\n");
	}
	else {
	    // One by one move boundary of unsorted subarray
	    for (i = 0; i < n-1; i++)
	    {
	        // Find the minimum element in unsorted array
	        min_idx = i;
	        for (j = i+1; j < n; j++)
	        {
	        	if ((p[j].time_left.minute >= p[min_idx].time_left.minute) && (p[j].time_left.second >= p[min_idx].time_left.second) && (p[j].movement < p[min_idx].movement))
				{
	    	        min_idx = j;
				}
			}
	        // Swap the found minimum element with the first element
	        swap_data_player(&p[min_idx], &p[i]);
	    }

		int chars = fwrite(p, sizeof(player), sizeof(p), fplayer);
		printf ("%d data saved to file\n", chars);
		
		// log
		for(i=0;i<n;i++) printf("\n%d. %s \t %s \t %d \t %d:%d\n", i+1, p[i].name, p[i].level, p[i].movement, p[i].time_left.minute, p[i].time_left.second);
	}
	fclose(fplayer);
}

void swap_data_player(player *compared_dt, player *moved_dt)
{
    player temp;
	
	//	temporary diisi oleh data yang dibandingkan
	strcpy(temp.name,   compared_dt->name);
	strcpy(temp.level,  compared_dt->level);
	temp.win 			= compared_dt->win;
	temp.movement 		= compared_dt->movement;
	temp.time_left		= compared_dt->time_left;
		
	//	data yang dibandigngkan diisi oleh data yang berpindah
	strcpy(compared_dt->name,   moved_dt->name);
	strcpy(compared_dt->level, moved_dt->level);
	compared_dt->win	   = moved_dt->win;
	compared_dt->movement  = moved_dt->movement;
	compared_dt->time_left = moved_dt->time_left;
    
	//	data yang berpindah diisi temporary
	strcpy(moved_dt->name, temp.name);
	strcpy(moved_dt->level, temp.level);
	moved_dt->win 		= temp.win;
	moved_dt->movement 	= temp.movement;
	moved_dt->time_left = temp.time_left;
}

//========================================================Play Feature============================================================//
void pause_act(Point Pp, Point Pp1)
{
	int mX, mY, gap_button = 5;
	bool valid = false;
	
	while(!valid)
	{
		getmouseclick(WM_LBUTTONDOWN,mX,mY);
	    delay(100);	
		if(mX >= Pp.x and mX <= Pp1.x and mY >= Pp.y and mY <= Pp1.y)
		{
			printf("\nunpause"); 	/* log */
			setcolor 	(COLOR(180,190,70));
			Button		(Pp, Pp1, gap_button);	
			ColorButton	(Pp, Pp1, COLOR(180,190,65), COLOR(115,142,63), COLOR(180,190,70));
			
			valid = true;
		}
	}
}

void swap_position(int *idx_empty_pzl, int idx_curpos, int ArrIdx[], PzlPosition PetakPuzzle[], char ArrGoal[])
{
	int temp;
	
	//swap value element array
	temp 					= ArrIdx[*idx_empty_pzl];
	ArrIdx[*idx_empty_pzl] 	= ArrIdx[idx_curpos];
	ArrIdx[idx_curpos] 		= temp;
	
	//tampilkan puzzle yang berpindah posisi di layar
	show_board_element(PetakPuzzle[*idx_empty_pzl].t1, PetakPuzzle[*idx_empty_pzl].t2, ArrGoal[ArrIdx[*idx_empty_pzl]]); 
	show_board_element(PetakPuzzle[idx_curpos].t1, PetakPuzzle[idx_curpos].t2, ArrGoal[ArrIdx[idx_curpos]]);
	
	//swap position
	*idx_empty_pzl 	= idx_curpos;
}

int find_index_of_empty_puzzle(char a[])
{
   int i;
   for (i=0; i<nPzl; i++)
	 if (a[i]=='0') return(i);  /* it was found */

   return(-1);  /* if it was not found */
} 

int find_index(int a[], int value)
{
   int i;
   for (i=0; i<nPzl; i++)
	 if (a[i]==value) return(i);  /* it was found */

   return(-1);  /* if it was not found */
}

bool is_same_as_goal(int arrPuzzle[])
{
	bool same = true;
	int  	i = 0;
	
	while(i<nPzl and same)
	{
		if (arrPuzzle[i] != i) same = false;
		i++;
	}
	
	return same;
}

void show_board_element(Point t1, Point t2, char image_name)
{
	char str[80];
	
	sprintf(str, "assets/element/puzzle/%c.bmp", image_name);
	Box(t1,t2);
	readimagefile(str, t1.x,t1.y,t2.x,t2.y);
}

void place_all_puzzle_on_board(PzlPosition pp[], int idx_pzl[], char ArrGoal[])
{
	int i;
	for (i=0 ; i<nPzl; i++) {
		printf("\nposisi %d  oleh  gambar : %c", i, ArrGoal[idx_pzl[i]]); // Log
        show_board_element(pp[i].t1, pp[i].t2, ArrGoal[idx_pzl[i]]);
    }
}

unsigned short get_random_number(int limit_a, int limit_b)
{
	unsigned short N=0;
	
	srand(time(NULL));
		N = rand()%(limit_b-limit_a + 1) + limit_a;
	
	return N;
}

//========================================================Solve Feature============================================================//
tree_and_leaf generate_tree(char ArrGoal[], short int depth) 
{
	/* Kamus Data Lokal */
	tree_and_leaf info_tree;
	Tree treePuzzle;
	addressLink Front = NULL, Rear = NULL, newNode,
				parentFront = NULL, parentRear = NULL, cekPoint;
				
	address parentCurrent, newNodeTree, levelNode;
	infoMovement infoMove;
	infotype info;
	short int level = 0;
	int idx_empty = find_index_of_empty_puzzle(ArrGoal);
	
	/* Membuat root Tree Puzzle */
	createTree(&treePuzzle);
	treePuzzle.root = NULL;
	treePuzzle.root = createRoot(idx_empty);
	
	// Insert node root ke queue
	enque(&Front, &Rear, treePuzzle.root);
	levelNode = Rear->info;
	
	while(level<depth)
	{
		/* delete queue */
		parentCurrent = deque(&Front);
		infoMove = movementFreeSpace(parentCurrent->infoTree.empty);
			
		/* Create child of Front */
		for(int i = 0;i<4;i++)
		{	
			// Mengisi info node baru
			info = set_info_tree_node(i,parentCurrent->infoTree.empty);
			newNodeTree = createNodeTree(info);
			
			/* cek pergerakan node baru, jika true node baru dibuat */
			if(infoMove.status[i])
			{
				if(parentCurrent == treePuzzle.root)
				{
					newNodeTree = insertNodeTree(&treePuzzle, parentCurrent, info);
					enque(&Front ,&Rear, newNodeTree);
					// log
					printf("\nmove : %d\n empty : %d\n parent : %d\n ", Rear->info->infoTree.move, Rear->info->infoTree.empty, Rear->info->parent);	
				}
				else if((newNodeTree->infoTree.empty) != (parentCurrent->parent->infoTree.empty))
				{
					newNodeTree = insertNodeTree(&treePuzzle, parentCurrent, info);
					enque(&Front ,&Rear, newNodeTree);
					// log
					printf("\n move : %d\n empty : %d\n parent : %d\n ", Rear->info->infoTree.move, Rear->info->infoTree.empty, Rear->info->parent);
				}
			}
		}
		
		/* Get parent untuk membandingkan */
		if(Rear->info->parent == levelNode)  
		{
			levelNode = Rear->info;
			level++;
		}		
	}
	
	/* Mengisi info tipe data komposit tree_and_leaf */
	info_tree.root = treePuzzle.root;
	info_tree.leaf = Front;
	
	return info_tree;
}

infotype set_info_tree_node(short int movement, short int empty)
{
	infotype data;
	
	/* Mengisi infotype node baru berdasarkan arah pergerakannya */
	switch(movement)
	{
		case 0 : data.move = -3; data.empty = empty + data.move; break;	//up
		case 1 : data.move =  3; data.empty = empty + data.move; break;	//down
		case 2 : data.move = -1; data.empty = empty + data.move; break;	//left
		case 3 : data.move =  1; data.empty = empty + data.move; break;	//right
	}
	
	return data;	
}

void swap_position_array(int *idx_empty_pzl, int idx_curpos, int ArrIdx[], PzlPosition PetakPuzzle[], char ArrGoal[])
{
	int temp;
	
	//swap value element array
	temp 					= ArrIdx[*idx_empty_pzl];
	ArrIdx[*idx_empty_pzl] 	= ArrIdx[idx_curpos];
	ArrIdx[idx_curpos] 		= temp;
	
	//swap position
	*idx_empty_pzl 	= idx_curpos;
}


//=========================================================For Debug==============================================================//
void print_tree(address node)
{
	if(node != NULL)
	{
		print_tree(node->firstSon);
		printf("\nNode \n move : %d\n empty : %d\n parent : %d\n ", node->infoTree.move, node->infoTree.empty, node->parent);
		print_tree(node->nextBrother);		
	}
}

void show_linkedlist(addressLink p)
{
	while (p != NULL)
	{
		printf("%d ", p->info->infoTree.move);
		p = p->next;
	}	
	printf("\n");
}
