#include "general.h"

//	Create Line
void Garis(Point t1, Point t2){
	int x1 = t1.x;
	int y1 = t1.y;
	int x2 = t2.x;
	int y2 = t2.y;
	
	line(x1, y1, x2, y2);
}

//	Create Rectangle
void Box(Point t1, Point t2)
{
	int x1 = t1.x;
	int y1 = t1.y;
	int x2 = t2.x;
	int y2 = t2.y;
	
	line(x1, y1, x2, y1);
	line(x1, y1, x1, y2);
	line(x1, y2, x2, y2);
	line(x2, y2, x2, y1);
}

//	Create Button
void Button(Point t1,Point t2, int gap) 
{ 
	Point t3,t4;
	
	int x1 = t1.x; 
	int y1 = t1.y; 
	int x2 = t2.x; 
	int y2 = t2.y; 
	t3.x   = t1.x+gap; 
	t3.y   = t1.y+gap; 
	t4.x   = t2.x-gap;  
	t4.y   = t2.y-gap;
	int x3 = t3.x; 
	int y3 = t3.y; 
	int x4 = t4.x;  
	int y4 = t4.y; 
	
	Box(t1,t2); 
	Box(t3,t4);
	Garis(t1,t3);
	Garis(t2,t4);
	line(x2,y1,x4,y3); 
	line(x1,y2,x3,y4); 
}

//	Create Button for Click with image
void Button_Image(Point t1,Point t2, int gap, int gap_image, const char* image) 
{ 
	Point t3,t4;
	Button(t1, t2, gap);
		
	t3.x   = t1.x+gap_image; 
	t3.y   = t1.y+gap_image; 
	t4.x   = t2.x-gap_image;  
	t4.y   = t2.y-gap_image; 
	int x3 = t3.x; 
	int y3 = t3.y; 
	int x4 = t4.x;  
	int y4 = t4.y;
 
	readimagefile(image, x3, y3, x4, y4); 
}
