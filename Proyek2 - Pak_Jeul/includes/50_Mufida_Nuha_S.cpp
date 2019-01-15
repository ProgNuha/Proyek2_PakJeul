#include "50_Mufida_Nuha_S.h"
#include "03_Ananda_K.h"

void ColorButton(Point t1, Point t2, int fillcolor1, int fillcolor2, int bordercolor1)
{
	/* Deklarasi koordinat */
	int x1 = t1.x; 
	int y1 = t1.y;
	int x2 = t2.x; 
	int y2 = t2.y;
	
	/* = = = Color Button = = = */   
	setfillstyle(1, fillcolor1); // give color
	floodfill	(x1+20,y1+2,bordercolor1); //at top 
	floodfill	(x1+2,y1+20,bordercolor1); //at left
	setfillstyle(1, fillcolor2); // give color
	floodfill	(x2-20,y2-2,bordercolor1); //at down
	floodfill	(x2-2,y2-20,bordercolor1); //at right
}

void Rank()
{
	cleardevice();
	
	/* = = = = = = = = = = = = = = = Background = = = = = = = = = = = = = = = */
	readimagefile("assets/bg/rank.bmp",ORIGIN_POINT, ORIGIN_POINT,WIDTH, HEIGHT);
	
	/* = = = = = = = = = = = = = = Create Button = = = = = = = = = = = = = = */
	
	//Deklarasi variabel titik
	Point easyButton1, easyButton2, mediumButton1, mediumButton2,
		  hardButton1 ,hardButton2, backButton1, backButton2;
	int mX, mY; 		 	// batas koordianat area clickable
	
	/* jarak antara koordinat*/
	int width 		= 180, 	// dalam satu button secara horizontal 
	    height 		=  45, 	// dalam satu button secara vertikal
		gap_x 		= 250, 	// antara dua button secara horizontal
		gap_button  =   5, 	// antara dua button secara vertikal
		gapImage 	=   5; 	// antara gambar dan button
		
	/* Deklarasi warna */
	int difColor = 5;	   	//perbedaan wawrna untuk button saat diklik
	int orange1		= COLOR(241,175,1), 		
		orange2 	= COLOR(241,175,1 + difColor),		 
		orange3 	= COLOR(230,134,24);
	int lightGreen1 = COLOR(180,190,65), 
		lightGreen2 = COLOR(180,190,65 + difColor),
		lightGreen3 = COLOR(115,142,63);
	int brown1 		= COLOR(165,97,42), 	
		brown2 		= COLOR(165,97,42 + difColor), 
		brown3 	 	= COLOR(105,55,43);
	int skyBlue1 	= COLOR(218,239,255),
		skyBlue2 	= COLOR(218,239,255 + difColor),
		skyBlue3	= COLOR(218,239,255 + (2*difColor)),
		skyBlue4 	= COLOR(218,239,255 + (3*difColor));
		
	/* Deklarasi koordinat */	
	easyButton1.x 	= 100;
	easyButton1.y 	= 175;
	easyButton2.x 	= easyButton1.x + width;		
	easyButton2.y 	= easyButton1.y + height;
	mediumButton1.x = easyButton1.x + gap_x;	
	mediumButton1.y = easyButton1.y;
	mediumButton2.x = mediumButton1.x + width;
	mediumButton2.y = mediumButton1.y + height;	
	hardButton1.x 	= mediumButton1.x + gap_x;	
	hardButton1.y 	= mediumButton1.y;
	hardButton2.x 	= hardButton1.x + width;	
	hardButton2.y 	= hardButton1.y + height;
	
	/* button back	*/
	/* = = = jarak antara koordinat = = = */
	height = 35;	// dalam satu button secara horizontal
	width = 35; 	// dalam satu button secara vertikal
	backButton1.x = ORIGIN_POINT;
	backButton1.y = ORIGIN_POINT;
	backButton2.x = ORIGIN_POINT + width;
	backButton2.y = ORIGIN_POINT + height;		

	/* menampilkan button */
	//Button Easy
	setcolor	(orange1);	
	Button_Image(easyButton1, easyButton2, gap_button, gapImage, "assets/button/easy.bmp");
	ColorButton	(easyButton1, easyButton2, orange1, orange3, orange1);
	//Button Medium
	setcolor	(lightGreen1);
	Button_Image(mediumButton1, mediumButton2, gap_button, gapImage, "assets/button/medium.bmp");
	ColorButton	(mediumButton1, mediumButton2, lightGreen1, lightGreen3, lightGreen1);		
	//Button Hard
	setcolor	(brown1);
	Button_Image(hardButton1, hardButton2, gap_button, gapImage, "assets/button/hard.bmp");
	ColorButton	(hardButton1, hardButton2, brown1, brown3, brown1);		
	//Button Back
	set_back_button();
	
	//default level
	char *level = "Easy";
	Show_Rank(level, orange2);
	
	//click button
	while(1){
        getmouseclick(WM_LBUTTONDOWN,mX,mY);
        delay(100);
		// button back
	    if(mX >= backButton1.x and mX <= backButton2.x and mY >= backButton1.y and mY <= backButton2.y)
		{
	    	back_button_effect();
	    	main_menu();
		}
        
		// button easy
		if(mX >= easyButton1.x and mX <= easyButton2.x and mY >= easyButton1.y and mY <= easyButton2.y)
		{
			printf("\nEASY"); 	//log
			/*= = = efek click = = =*/
			setcolor	(orange2);
			Button		(easyButton1, easyButton2, gap_button);	
			ColorButton	(easyButton1, easyButton2, orange3, orange1, orange2);		// click
			delay(200);
			ColorButton	(easyButton1, easyButton2, orange1, orange3, orange2);		// after click		
			delay(100);
			
			/*cek level yang sebelumnya tampil*/
			if(level!="Easy")
			{
				Show_Rank(level, skyBlue1);		// menghapus rank level yang sebelumnya tampil
				level = "Easy";				
				Show_Rank(level, orange2);		// menampilkan rank level yang diklik
			}
		}
		// button medium
		if(mX >= mediumButton1.x and mX <= mediumButton2.x and mY >= mediumButton1.y and mY <= mediumButton2.y)
		{
			printf("\nMEDIUM"); 	//log
			/*= = = efek click = = =*/
			setcolor	(lightGreen2);
			Button		(mediumButton1, mediumButton2, gap_button);	
			ColorButton	(mediumButton1, mediumButton2, lightGreen3, lightGreen1, lightGreen2); 	// click		
			delay(200);
			ColorButton	(mediumButton1, mediumButton2, lightGreen1, lightGreen3, lightGreen2); 	// after click
			delay(100);
			
			/*cek level yang sebelumnya tampil*/
			if(level!="Medium")
			{
				Show_Rank(level, skyBlue1);			// menghapus rank level yang sebelumnya tampil
				level = "Medium";
				Show_Rank(level, lightGreen2);		// menampilkan rank level yang diklik
			} 
		}	
		// button hard
		if(mX >= hardButton1.x and mX <= hardButton2.x and mY >= hardButton1.y and mY <= hardButton2.y)
		{
			printf("\nHARD"); 	//log
			/*= = = efek click = = =*/
			setcolor	(brown2);
			Button		(hardButton1, hardButton2, gap_button);	
			ColorButton	(hardButton1, hardButton2, brown3, brown1, brown2);		// click
			delay(200);
			ColorButton	(hardButton1, hardButton2, brown1, brown3, brown2);		// after click
			delay(100);
			
			/*cek level yang sebelumnya tampil*/
			if(level!="Hard")
			{
				Show_Rank(level, skyBlue1);		// menghapus rank level yang sebelumnya tampil
				level = "Hard";
				Show_Rank(level, brown2);		// menampilkan rank level yang diklik
			}
		}
	}
}

void Show_Rank(char *level, int colorfont)
{
	/* = = = Kamus Data Lokal = = = */
	FILE *fplayer;		// File yang berisi info player
	player temp;		
	int count = 0 ;		// menghitung jumlah player tampil
	
	/* Info Player */
	char print[30];
	char str_name[7];
	char str_movement[3];
	char str_timeleft[6];
	
	/* Deklarasi koordinat */
	int  nama_x = 155, 
		 score_y = 270,
		 score_x = 485,
		 number_x = 100,
		 level_x = 320,
		 title_y = 235,
		 title_x = 150,
		 titleTime_x = 615,
		 titleMove_x = 365;	 
		 
	int skyBlue = COLOR(218,239,255); // warna default
	
	/* Menampilkan judul dari tiap kolom */
	setcolor	(colorfont);
	setbkcolor	(skyBlue);
	settextstyle(BOLD_FONT, LEFT_TEXT, 4);
	outtextxy	(title_x, title_y, "NAMA");
	outtextxy	(titleMove_x, title_y, "MOVEMENT");
	outtextxy	(titleTime_x, title_y, "TIMELEFT");

	// Menampilkan gambar trophy
	readimagefile("assets/element/trophy.bmp",70, 270, 95, 295);
	
	/* = = = = = = = = = = = = = = = Sort Rank = = = = = = = = = = = = = = = */
	if((fplayer=fopen("player_master.dat","rb"))==NULL)
	{
		printf("File tidak dapat dibuat!\r\n");
	}
	else
	{
		rewind(fplayer); // kembali ke awal file
		
		/* = = = = = = = = = Menampilkan hasil sort = = = = = = = = =*/
		char num[3];
		while(((fread(&temp,sizeof(temp),1,fplayer))==1) && (count<10))
		{	
			
			setbkcolor	(skyBlue);
			settextstyle(BOLD_FONT, LEFT_TEXT, 4);
			if(strcmp(temp.level, level) == 0)
			{
				/* Menyalin ke karakter */
				sprintf(str_name,"%s",temp.name);
				sprintf(str_movement,"%d",temp.movement);
				sprintf(str_timeleft,"%d:%d",temp.time_left.minute, temp.time_left.second); 
				sprintf(num,"%d",count+1);
				
				/* Mencetak pada UI*/
				outtextxy(number_x, score_y, num);
				outtextxy(nama_x, score_y, str_name);
				outtextxy(nama_x+275, score_y, str_movement);
				outtextxy(nama_x+500, score_y, str_timeleft);
				
				score_y += 28;	// Menambah nilai untuk menmapilkan hasil selanjutnya
				count++;
				
				if(colorfont==skyBlue)	delay(50); // menghapus rank sebelumnya
				else delay(200); 
			}
		}
		
		printf("\n");
		fclose(fplayer); // close file
	}
}

void set_custom_goal()
{
	cleardevice();
	
	/* = = = = = = = = = = = = = = = Background = = = = = = = = = = = = = = = */
	readimagefile("assets/bg/set_goal_custom.bmp",ORIGIN_POINT, ORIGIN_POINT,WIDTH, HEIGHT);	
	
	/* = = = = = = = = = = = = = Set Custom Goal = = = = = = = = = = = = = = = */
	
	//Kamus Data Lokal
	PzlPosition coordinate[24];
	Pic_Position(coordinate);
	char img[24];
	char path[28];
	int alphabet_initial = 'a';
	int j = 0;
	
	//Define position per box (element)
	for(int i=0;i<24;i++)
	{
		img[i] = i+alphabet_initial;
		sprintf(path,"assets/element/puzzle/customgoal/%c.bmp", img[i]);
		readimagefile(path, coordinate[i].t1.x, coordinate[i].t1.y, coordinate[i].t2.x, coordinate[i].t2.y);
	}

	//Deklarasi variabel titik
	Point resetButton1, resetButton2, doneButton1 ,doneButton2, backButton1, backButton2;
	
	/* Deklarasi warna */
	int orange1  	= COLOR(241,175,1), 		
		orange2 	= COLOR(230,134,24);
	int lightGreen1	= COLOR(180,190,65), 
		lightGreen2	= COLOR(115,142,63);

	/* jarak antara koordinat*/	
	int width 		= 120,	// dalam satu button secara horizontal 
	    height 		=  40,	// dalam satu button secara vertikal
		gap_x 		= 135,	// antara dua button secara horizontal
		gap_button  =   5,	// antara dua button secara vertikal
		gapImage 	=   6;	// antara gambar dan button
		
	/*	button reset */
	resetButton1.x = 65;
	resetButton1.y = 485;
	resetButton2.x = resetButton1.x+width;
	resetButton2.y = resetButton1.y+height;
	/*	button done	*/	
	doneButton1.x = resetButton1.x+gap_x;
	doneButton1.y = resetButton1.y;
	doneButton2.x = doneButton1.x+width;
	doneButton2.y = doneButton1.y+height;
	/*	button back	*/
	/* = = = jarak antara koordinat = = = */
	height = 35;	// dalam satu button secara horizontal
	width = 35; 	// dalam satu button secara vertikal
	backButton1.x = ORIGIN_POINT;
	backButton1.y = ORIGIN_POINT;
	backButton2.x = ORIGIN_POINT + width;
	backButton2.y = ORIGIN_POINT + height;	
	
	/* menampilkan button */
	set_back_button();
	setcolor	(orange1);
	Button_Image(resetButton1,resetButton2, gap_button, gapImage, "assets/button/reset.bmp");
	ColorButton	(resetButton1,resetButton2, orange1, orange2, orange1);
	setcolor	(lightGreen1);
	Button_Image(doneButton1,doneButton2, gap_button, gapImage, "assets/button/done.bmp");
	ColorButton	(doneButton1,doneButton2, lightGreen1, lightGreen2, lightGreen1);
}

void Pic_Position(PzlPosition *coor)
{
	int  x = 440, y = 347;
	for(int i=0;i<24;i++)
	{
		coor[i].t1.x = x;
		coor[i].t2.x = x + 50;
		x = coor[i].t2.x;
		coor[i].t1.y = y;
		coor[i].t2.y = y + 50;
		if(i==7 || i==15) 
		{
			x = 440;
			y += 50;
		}
	}
}

char choose_pic(char ArrGoal[])
{
	
	//Deklarasi variabel titik	
	Point resetButton1, resetButton2, doneButton1 ,doneButton2, 
		  backButton1, backButton2, nextButton1, nextButton2;

	/* Deklarasi warna */
	int orange1		= COLOR(241,175,1), 		
		orange2 	= COLOR(241,175,6),		 	
		orange3 	= COLOR(230,134,24);
	int lightGreen1 = COLOR(180,190,65), 
		lightGreen2 = COLOR(180,190,70),
		lightGreen3 = COLOR(115,142,63);
	
	/* jarak antara koordinat*/	
	int width 		= 120,	// dalam satu button secara horizontal 
	    height 		=  40,	// dalam satu button secara vertikal
		gap_x 		= 135,	// antara dua button secara horizontal
		gap_button  =   5,	// antara dua button secara vertikal
		gapImage 	=   6;	// antara gambar dan button
		
	/* = = = Deklarasi variabel titik = = = */	
	/* button reset */
	resetButton1.x = 65;
	resetButton1.y = 485;
	resetButton2.x = resetButton1.x+width;
	resetButton2.y = resetButton1.y+height;
	/* button done	*/	
	doneButton1.x = resetButton1.x+gap_x;
	doneButton1.y = resetButton1.y;
	doneButton2.x = doneButton1.x+width;
	doneButton2.y = doneButton1.y+height;
	/* button back	*/
	/* = = = jarak antara koordinat = = = */
	height = 35;	// dalam satu button secara horizontal
	width = 35; 	// dalam satu button secara vertikal
	backButton1.x = ORIGIN_POINT;
	backButton1.y = ORIGIN_POINT;
	backButton2.x = ORIGIN_POINT + width;
	backButton2.y = ORIGIN_POINT + height;	
	/* button next	*/
	nextButton1.x = WIDTH - width;
	nextButton1.y = ORIGIN_POINT;
	nextButton2.x = WIDTH;
	nextButton2.y = ORIGIN_POINT + height;

	/* = = = Kamus Data Lokal = = =*/
	game_setting custom_setting;
	int mX = -1, mY = -1; 
	PzlPosition coordinate[24];
	//Define position per box (element)
	Pic_Position(coordinate);
	
	bool valid_area=false;
	char  img[24];
	bool  cek[24] ={false};
	int  j = 0;
	
	char path[28];	
	int alphabet_initial = 'a';
		
	for(int i=0;i<24;i++)
	{
		img[i] = i+alphabet_initial;
		printf("\n%c", img[i]);
		while(!cek[i] and j<nPzl)
		{
			if(ArrGoal[j] == img[i]) cek[i] = true;
			j++;
		}
		if(cek[i]) Box_Pic(lightGreen1, coordinate[i].t1, coordinate[i].t2);
		else
		{
			sprintf(path,"assets/element/puzzle/customgoal/%c.bmp", img[i]);
			readimagefile(path, coordinate[i].t1.x, coordinate[i].t1.y, coordinate[i].t2.x, coordinate[i].t2.y);
		}
		j=0;
	}
	
	while (!valid_area)
	{
		getmouseclick(WM_LBUTTONDOWN,mX,mY);
		delay(100);
		if(mX>=coordinate[0].t1.x and mX<=coordinate[23].t2.x and mY>=coordinate[0].t1.y and mY<=coordinate[23].t2.y)
		{
			valid_area=true;
		}
		//  button reset
		if(mX >= resetButton1.x and mX <= resetButton2.x and mY >= resetButton1.y and mY <= resetButton2.y)
		{
			valid_area=true;
		}
		//	button back
		if(mX >= backButton1.x and mX <= backButton2.x and mY >= backButton1.y and mY <= backButton2.y)
		{
			valid_area=true;
		}
		// button done
		else if(mX >= doneButton1.x and mX <= doneButton2.x and mY >= doneButton1.y and mY <= doneButton2.y)
		{
			valid_area=true;
			return '-';
		}
		//	cheat area
		else if(mX >= nextButton1.x and mX <= nextButton2.x and mY >= nextButton1.y and mY <= nextButton2.y)
		{
			valid_area = true;
			return 'C';
		}
	}
		
	//	puzzle collection
	if(mX>=coordinate[0].t1.x and mX<=coordinate[23].t2.x and mY>=coordinate[0].t1.y and mY<=coordinate[23].t2.y)
	{
		for(int i=0;i<24;i++)
		{
		    if(mX >= coordinate[i].t1.x and mX <= coordinate[i].t2.x and mY >= coordinate[i].t1.y and mY <= coordinate[i].t2.y)
			{
				if(!cek[i])
				{
					Box_Pic(lightGreen1, coordinate[i].t1, coordinate[i].t2);
					printf("\n%c", img[i]);
					return img[i];
				}
			}		
		}
	}
	
	//  button reset
	else if(mX >= resetButton1.x and mX <= resetButton2.x and mY >= resetButton1.y and mY <= resetButton2.y)
	{		
		reset_action(ArrGoal);
		mX=-1;mY=-1;
	}
	
	//	button back
	else if(mX >= backButton1.x and mX <= backButton2.x and mY >= backButton1.y and mY <= backButton2.y)
	{
		back_action(mX, mY);
		mX=-1;mY=-1;
	}
	
	return 'X';
}

void Box_Pic (int color1, Point dot1, Point dot2)
{
	setcolor(color1);
	Button(dot1, dot2, 3);
	ColorButton	(dot1, dot2, color1, color1, color1);
}


/* = = = = = = = = = = = = = = = = = = Generate Tree = = = = = = = = = = = = = = = = = */

infoMovement movementFreeSpace(int indexPuzzle)
{
	infoMovement freeSpace;
	
	/* Mengisi info pergerakan berdasarkan indeks puzzle yang kosong */
	switch (indexPuzzle)
	{
		case 0 : 
			freeSpace.status[0]	= false;	//up
			freeSpace.status[1]	=  true;	//down
			freeSpace.status[2]	= false;	//left
			freeSpace.status[3]	=  true;	//right
			break;
		case 1 : 
			freeSpace.status[0]	= false;	//up
			freeSpace.status[1]	=  true;	//down
			freeSpace.status[2]	=  true;	//left
			freeSpace.status[3]	=  true;	//right
			break;
		case 2 : 
			freeSpace.status[0]	= false;	//up
			freeSpace.status[1]	=  true;	//down		
			freeSpace.status[2]	=  true;	//left
			freeSpace.status[3]	= false;	//right
			break;		
		case 3 : 
			freeSpace.status[0]	=  true;	//up
			freeSpace.status[1]	=  true;	//down
			freeSpace.status[2]	= false;	//left
			freeSpace.status[3]	=  true;	//right
			break;	
		case 4 : 
			freeSpace.status[0]	=  true;	//up
			freeSpace.status[1]	=  true;	//down
			freeSpace.status[2]	=  true;	//left
			freeSpace.status[3]	=  true;	//right
			break;
		case 5 : 
			freeSpace.status[0]	=  true;	//up	
			freeSpace.status[1]	=  true;	//down
			freeSpace.status[2]	=  true;	//left
			freeSpace.status[3]	= false;	//right
			break;
		case 6 : 
			freeSpace.status[0]	=  true;	//up
			freeSpace.status[1]	= false;	//down
			freeSpace.status[2]	= false;	//left
			freeSpace.status[3]	=  true;	//right
			break;		
		case 7 : 
			freeSpace.status[0]	=  true;	//up
			freeSpace.status[1]	= false;	//down
			freeSpace.status[2]	=  true;	//left
			freeSpace.status[3]	=  true;	//right
			break;	
		case 8 : 
			freeSpace.status[0]	=  true;	//up
			freeSpace.status[1]	= false;	//down
			freeSpace.status[2]	=  true;	//left
			freeSpace.status[3]	= false;	//right
			break;
	}
	return freeSpace;
}

infotype set_info_tree_nodeRoot(int indexEmpty)
{
	infotype root;
	
	/* Mengisi infotype root */
	root.empty = indexEmpty;
	root.move = 0;
	
	return root;
}

address createRoot(int indexEmpty)
{
	address root;
	
	/* Membuat root Tree */
	root = alokasiNodeTree();
	root->infoTree = set_info_tree_nodeRoot(indexEmpty);
	root->parent = NULL;
	root->firstSon = NULL;
	root->nextBrother = NULL;
	
	return root;
}

void animatePuzzle(addressLink topStack, char ArrGoal[], int ArrIdx[])
{
	int idx_empty  = find_index(ArrIdx, find_index_of_empty_puzzle(ArrGoal)), 
		idx_curpos = 0;
	infotypeLink info;
	PzlPosition Petak_Puzzle[nPzl];
	
	// define posis Petak Puzzle
	letak(Petak_Puzzle);
	
	// log	
	printf("indeks empty : %d \n", idx_empty );
	
	/* Animate Puzzle */
	while(topStack != NULL)
	{
		/* Mengisi info pergerakan kembali atau reverse */
		info = pop(&topStack);
		idx_curpos = idx_empty + ((info->infoTree.move)*(-1));
		
		// log
		printf("*r:%d  ", ((info->infoTree.move)*(-1)));
		
		swap_position(&idx_empty, idx_curpos, ArrIdx, Petak_Puzzle, ArrGoal);	
		delay(500);
	}
}


/* = = = = = = = = = = = = = = = ADT Linked List Dynamic = = = = = = = = = = = = = = = */

boolean isEmpty(addressLink p)
{
	if(p == NULL)
		return true;
	else return false;
}

addressLink alokasiNode()
{
	addressLink newNode;
	newNode = (addressLink) malloc(sizeof(node));
	return newNode;
}

addressLink createNode(infotypeLink info)
{
	addressLink newNode;
	newNode = alokasiNode();
	
	if (newNode != NULL)
	{
		newNode->info = info;
		newNode->next		  = NULL;
	}
}

void insertAwal(addressLink *awal, addressLink newNode)
{
	if(isEmpty(*awal))
	{	
		newNode->next = NULL;
		*awal  = newNode;
   	}
	else
	{
		newNode->next = NULL;
		newNode->next = *awal;
		*awal = newNode;	
	}
}

void insertAkhir (addressLink *awal, addressLink *akhir, addressLink newNode)
{
	if(isEmpty(*awal) || isEmpty(*akhir))
	{
		newNode->next = NULL; 
		*awal = newNode;     
   		*akhir = newNode;
	}
	else 
	{
		(*akhir)->next = newNode;
		*akhir = newNode;
		newNode->next = NULL;
	}	
}

void push(addressLink *awal, addressLink newNode)
{
	insertAwal(&(*awal), newNode);
}

void enque(addressLink *nodeAwal, addressLink *nodeAkhir, infotypeLink info)
{
	addressLink pNew;
	
	pNew = createNode(info);
	insertAkhir(&(*nodeAwal), &(*nodeAkhir), pNew);
}

void deAlokasi (addressLink *pDel)
{
	if(!isEmpty(*pDel)) free(*pDel);
}

addressLink deAlokasiStack(addressLink pDel)
{
	infotypeLink deleteNode;
	
	while(pDel != NULL)
	{
		deleteNode = deleteAwal(&pDel);
	}
	
	return pDel;
}

infotypeLink deleteAwal(addressLink *node)
{
	infotypeLink deleteNode;
	addressLink pDel;
	
	pDel = *node;
	deleteNode = (*node)->info;
	
	*node = (*node)->next;
	pDel->next = NULL;
	
	deAlokasi(&pDel);
	
	return deleteNode;
}

infotypeLink deque(addressLink *nodeFront)
{
	infotypeLink deleteNode;
	deleteNode = deleteAwal(&(*nodeFront));
	
	return deleteNode;
}

infotypeLink pop(addressLink *top)
{
	infotypeLink deleteNode;
	deleteNode = deleteAwal(&(*top));
	
	return deleteNode;
}


/* = = = = = = = = = = = = = = = = = ADT Tree Dynamic = = = = = = = = = = = = = = = = */

boolean IsEmpty(address p)
{
	if(p == NULL)
		return true;
	else return false;
}

address alokasiNodeTree()
{
	address newNode;
	newNode = (address) malloc(sizeof(nodeTree));
	return newNode;
}

address createNodeTree(infotype info)
{
	address newNode;
	newNode = alokasiNodeTree();
	
	if (newNode != NULL)
	{
		newNode->infoTree 	  = info;
		newNode->firstSon	  = NULL;
		newNode->nextBrother  = NULL;
		newNode->parent		  = NULL;
	}
	
	return newNode;
}

address insertNodeTree(Tree *tree, address parent, infotype info)
{
	address newNode, temp;
	newNode = createNodeTree(info);
	
	if(newNode!=NULL)
	{
		if(parent==NULL)
			tree->root = newNode;
		else
		{
			temp = parent;
			if(temp->firstSon!=NULL)
			{
				temp = temp->firstSon;
				while(temp->nextBrother!=NULL)
				{
					temp = temp->nextBrother;
				}
				temp->nextBrother = newNode;	
			}
			else
			{
				temp->firstSon = newNode;
			}	
			newNode->parent = parent;
		}	
	}
	return newNode;
}

void createTree(Tree *tree)
{
	(*tree).root=NULL;
}

void deAlokasiTree (address *pDel)
{
	(*pDel)->firstSon = NULL;
	(*pDel)->nextBrother = NULL;
	(*pDel)->parent = NULL;
	if(!IsEmpty(*pDel)) free(*pDel);
}

void inOrder(address nodeTree)
{
	if(!IsEmpty(nodeTree))
	{
		inOrder(nodeTree->firstSon);
		if(IsEmpty(nodeTree->firstSon))
			deAlokasiTree(&nodeTree);	
		if(!IsEmpty(nodeTree->parent))
			if(nodeTree->parent->firstSon == nodeTree)
				deAlokasiTree(&nodeTree);
		inOrder(nodeTree->nextBrother);
	}		
}
