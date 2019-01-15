#include "general.h"
#include "03_Ananda_K.h"
#include "46_Kiki_Pratiwi.h"
#include "65_Velia_Sagita_P.h"
#include "50_Mufida_Nuha_S.h"
	
char latest_player_name[7];
	
player inputname()
{
	cleardevice();
	
	/* = = = = = = = = = = = = Set Background = = = = = = = = = = = */
	readimagefile("assets/bg/inputname.bmp",ORIGIN_POINT, ORIGIN_POINT, WIDTH, HEIGHT);
		
	char c;
	char nama[7];
	player p;
	strcpy(nama, latest_player_name);
	int len = strlen(nama);
	int input_pos = len, the_last=0, i;
	
	// ===== Set Text Color ===== /
	setbkcolor	(COLOR(218,239,251)); //give background color 
	settextstyle(BOLD_FONT,0,6); // give text style
	setcolor	(COLOR(77,77,77)); // give text color

/* = = = = = Input Name = = = = =*/
	do
	{
		outtextxy(350,400,nama);
		c = getch();	
		switch (c)
		{
			case 8: 						/* backspace */
	          	if (input_pos){
	          		nama[input_pos] = 0;
	             	input_pos--;
	             	nama[input_pos] = 0;
					readimagefile("assets/bg/inputname.bmp",ORIGIN_POINT, ORIGIN_POINT, WIDTH, HEIGHT);
	             	outtextxy(350,400,nama);
				}
			break;
			case 13: the_last = 1; break;	/* enter */
			default:
	      		if(input_pos < 6 && c==' '){
	      			nama[input_pos] = ' ';
	      			input_pos++;
	      			nama[input_pos] = 0;
				  }
				else if (input_pos < 6 && c >= ' ' && c < '{'){
	         		nama[input_pos] = c;
	         		input_pos++;
	         		nama[input_pos] = 0;
	      		  }
    	}
	}while (!the_last);
	
	strcpy(latest_player_name, nama);								
	strcpy(p.name, nama);
	
	return p;
}

void result(player p)
{
	cleardevice();
	
	/* = = = = =  Set Background = = = = = */
	readimagefile("assets/bg/result.bmp",ORIGIN_POINT, ORIGIN_POINT, WIDTH, HEIGHT);
	PlaySound("sounds/result.wav", NULL, SND_FILENAME | SND_ASYNC);
	
	// Deklarasi Point
	Point PlayGame1, PlayGame2, HighScore1, HighScore2, Menu1, Menu2;
	
	// Mouse Coordinate
	int mX, mY;		
	
	// Button Size
	int gap_button = 5, 
		gapImage   = 5, 
		width      = 225, 
		height 	   = 50, 
		gap_y 	   = 60;
		
	// Button Color Initializing
	int Orange 			 = COLOR(241,175,1), 		
		Orange1 		 = COLOR(241,175,5),		 
		Fill_Orange1 	 = COLOR(241,175,1),		
		Fill_Orange2 	 = COLOR(230,134,24); 
	int LightGreen 		 = COLOR(180,190,65), 
		LightGreen1		 = COLOR(180,190,70), 
		Fill_LightGreen1 = COLOR(180,190,65), 	
		Fill_LightGreen2 = COLOR(115,142,63);
	int Brown 			 = COLOR(165,97,42), 	
		Brown1 			 = COLOR(165,97,45), 	
		Fill_Brown1 	 = COLOR(165,97,42), 	
		Fill_Brown2 	 = COLOR(105,55,43);

// play game Button 
	PlayGame1.x = 555;
	PlayGame1.y = 245;
	PlayGame2.x = PlayGame1.x + width; 
	PlayGame2.y = PlayGame1.y + height;
	
// High Score Button
	HighScore1.x = PlayGame1.x;
	HighScore1.y = PlayGame1.y + gap_y;
	HighScore2.x = HighScore1.x + width;
	HighScore2.y = HighScore1.y + height;
	
// menu
	Menu1.x = PlayGame1.x;
	Menu1.y = HighScore1.y + gap_y;
	Menu2.x = Menu1.x  + width;
	Menu2.y = Menu1.y  + height;
	
// Background Result 
	readimagefile("assets/element/result.bmp",120,200,495,450);

/* Menampilkan Button */
// Button Play again
	setcolor	(Orange); 
	Button_Image(PlayGame1, PlayGame2, gap_button, gapImage, "assets/button/play_again.bmp");
	ColorButton	(PlayGame1, PlayGame2, Fill_Orange1, Fill_Orange2, Orange);	
// Button High Score
	setcolor	(LightGreen); 
	Button_Image(HighScore1, HighScore2, gap_button, gapImage, "assets/button/rank.bmp");
	ColorButton	(HighScore1, HighScore2, Fill_LightGreen1, Fill_LightGreen2, LightGreen);
// Button Menu
	setcolor	(Brown); 
	Button_Image(Menu1, Menu2, gap_button, gapImage, "assets/button/home.bmp");
	ColorButton	(Menu1, Menu2, Fill_Brown1, Fill_Brown2, Brown);	
	
// Deklarasi waktu  

	int second, minutes;
	char mnt[3];
	char scd[3];
	char movement[3];
	
/* = = = = = Set Text = = = = = */
	setbkcolor	(COLOR(218,239,251));// give background text
	settextstyle(BOLD_FONT,0,4); // give text style
	setcolor	(COLOR(77,77,77)); // give text color
	
	outtextxy(310,230, p.name);
	outtextxy(310,313, p.level);
	sprintf	 (movement, "%d", p.movement);
	outtextxy(310,353, movement);
	
	if(p.win)
	{
		setcolor(COLOR(180,190,65));	
		outtextxy(310,400, "Success");
	}
	else 
	{
		setcolor(COLOR(255,0,0));
		outtextxy(310,400, "Failed");
	}


/*= = = = = Time Left = = = = = */
	for (minutes=0;minutes<=p.time_left.minute;minutes++)
	{
		for(second=0;second<=p.time_left.second;second++){
			setcolor(COLOR(241, 175 ,1));
			sprintf(mnt, "%d", minutes);
			sprintf(scd, "%d", second);
				
			strcat (mnt, ".");
			if (second<10){
				strcat(mnt, "0");
			}
			strcat (mnt, scd);
			
			outtextxy(310,270, mnt);
			delay(5);
		}
	}
	
	// Click Button
	while(1)
	{
		getmouseclick(WM_LBUTTONDOWN,mX,mY);
	    delay(100);	
	    
		//button play again
		if(mX >= PlayGame1.x and mX <= PlayGame2.x and mY >= PlayGame1.y and mY <= PlayGame2.y)
		{
			printf("\nstart_game"); 	/* log */
			// = = = = = Click Effect = = = = = //
			setcolor	(Orange1);
			Button		(PlayGame1, PlayGame2, gap_button);	
			ColorButton	(PlayGame1, PlayGame2, Fill_Orange2, Fill_Orange1, Orange1);		
			delay(200);
			ColorButton	(PlayGame1, PlayGame2, Fill_Orange1, Fill_Orange2, Orange1);		
			delay(200);
			
			set_goal_and_level();
		}
		
					    		    
	    //button High Score
		if(mX >= HighScore1.x and mX <= HighScore2.x and mY >= HighScore1.y and mY <= HighScore2.y)
		{
			printf("\nscore"); 	/* log */
			// = = = = = Click Effect = = = = = //
			setcolor	(LightGreen1);
			Button		(HighScore1, HighScore2, gap_button);	
			ColorButton	(HighScore1, HighScore2, Fill_LightGreen2, Fill_LightGreen1, LightGreen1); 		
			delay(200);
			ColorButton	(HighScore1, HighScore2, Fill_LightGreen1, Fill_LightGreen2, LightGreen1); 	
			delay(200);
		
			
			PlaySound("sounds/opening.wav", NULL, SND_FILENAME | SND_ASYNC);
			Rank();
		}
		
	    //button menu
		if(mX >= Menu1.x and mX <= Menu2.x and mY >= Menu1.y and mY <= Menu2.y)
		{
			printf("\nmenu"); 	/* log */
			// = = = = = Click Effect = = = = = //
			setcolor	(Brown1);
			Button		(Menu1, Menu2, gap_button);	
			ColorButton	(Menu1, Menu2, Fill_Brown2, Fill_Brown1, Brown1);	
			delay(200);
			ColorButton	(Menu1, Menu2, Fill_Brown1, Fill_Brown2, Brown1);	
			delay(200);	
			
			//  = = = = = Set Sound = = = = = //
	    	PlaySound("sounds/opening.wav",NULL,SND_ASYNC | SND_LOOP);
			main_menu();
		}
	}
}

void reset_arr_custom (char array[]) // memeriksa semua elemen array
{
	int i; 
	// reset array custom (semua element array NULL)
	for(i=0; i<nPzl; i++){
		array[i] = '\0';
	}
}


boolean isArrFull(char array[]) // Memeriksa array pada custom goal
{
	
	unsigned short nfilled=0; // unsigned short digunakan karena lebih hemat memory
	bool full = false;
	
	// memeriksa setiap elemen
	for(int i=0; i<nPzl; i++)
	{
		if(array[i] == '0' or array[i] != '-') nfilled++;
	}
	printf("\n%d", nfilled);
	return (nfilled == nPzl);
}

int input_empty_puzzle (PzlPosition pp[nPzl])
{
	// declaration and initialitation back button coordinate
	Point Back1, Back2;
	
	int width, height,
		gap_x 		= 135, 
		gap_button  =   5,
		gapImage 	=   6;

	height = width = 35;
	
	Back1.x = ORIGIN_POINT;
	Back1.y = ORIGIN_POINT;
	Back2.x = ORIGIN_POINT + width;
	Back2.y = ORIGIN_POINT + height;

	bool valid=false, valid_area=false;
	int i=0, idx_empty, mX=-1, mY=-1;
	
	
	readimagefile("assets/element/textballon1.bmp",565, 157, 805, 198);
	
	// click button
	while (!valid)
	{	
		while (!valid_area)
		{
			getmouseclick(WM_LBUTTONDOWN,mX,mY);
			delay(100);
			
			// Memeriksa Koordinat Mouse 
			if(mX>=pp[0].t1.x and mX<=pp[8].t2.x and mY>=pp[0].t1.y and mY<=pp[8].t2.y)
			{
				valid_area=true;
			}
			//	button back
		    else if(mX >= Back1.x and mX <= Back2.x and mY >= Back1.y and mY <= Back2.y)
			{
				back_action(mX, mY);
				valid_area=true;
			}
		}

//cek klik di kotak mana
		for(i=0; i<nPzl; i++)
	    {
	    	if(mX >= pp[i].t1.x and mX <= pp[i].t2.x and mY >= pp[i].t1.y and mY <= pp[i].t2.y)
	    	{
				readimagefile("assets/element/puzzle/empty.bmp", pp[i].t1.x,pp[i].t1.y,pp[i].t2.x,pp[i].t2.y);
	    		
				idx_empty = i;
	    		valid = true;
	    		break;
			}
		}
		
		readimagefile("assets/element/textballon2.bmp",565, 157, 805, 198);
	}
	return idx_empty;
}


addressLink randomGoal (addressLink stack, char ArrGoal[], int Arridx_ofGoal[])
{
	
	int idx_empty, idx_temp, idx_reverse;
	addressLink nodeCurrent, stackBacktrack=NULL, pDel, newNode;
	infotypeLink info;
	idx_empty = find_index_of_empty_puzzle(ArrGoal); // find arrgoal
 	idx_temp = 0;
	idx_reverse = 0;
	nodeCurrent = stack;
	PzlPosition Petak_Puzzle[nPzl];
	letak(Petak_Puzzle);
	
	while(nodeCurrent != NULL)
	{
		//log
		printf("*m:%d ", nodeCurrent->info->infoTree.move);
		
		// posisi baru empty
		idx_reverse = idx_empty + nodeCurrent->info->infoTree.move;

		swap_position_array(&idx_empty, idx_reverse, Arridx_ofGoal, Petak_Puzzle, ArrGoal);

		// Menyimpan Ke Backtrack 
		pDel = nodeCurrent;
		nodeCurrent = nodeCurrent->next;
		info = pop(&pDel);
		newNode = createNode(info);
		insertAwal(&stackBacktrack,newNode);

	}
	printf("\n");
	show_linkedlist (stackBacktrack);
	return stackBacktrack;
}

void Loading()
{
	cleardevice();
	
	/* = = = = = Menampilkan Background Loading = = = = = */
	readimagefile("assets/bg/loading.bmp",ORIGIN_POINT, ORIGIN_POINT, WIDTH, HEIGHT);
	
}

