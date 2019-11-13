
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>

#include "iGraphics.h"

/* 
	function iDraw() is called again and again by the system.
*/

int n=0;
double x [401], y[401];
double x1[5]={10,20,30,40,50};
double y11[5]={60,20,80,120,200};
int mposx, mposy;

void iDraw()
{
	//place your drawing codes here	
	iClear();
	iSetColor(255, 255, 0);
	iPoint (100,100);
	iLine(200,200,100,50);
	iCircle(400,200,20,10);
	iSetColor(255,0, 255);
	iFilledCircle(400,300,20);
	

	for (int i=0; i<n; i++)
	{
		//iPoint(x[i],y[i]);		
	//	iPolygon(x,y,n);
	}

	iShowBMP(400,400,"girl.bmp");
	//iPolygon(x1,y11,5);
	iSetColor(255, 255, 0);
	iPolygon(x,y,n);
	iText(100,300, "HHAHA", GLUT_BITMAP_TIMES_ROMAN_24);

}

void loop()
{
	//srand(100);
	
	//int i=(int)(20*rand()*1.0/RAND_MAX);
	//int j=(int)(20*rand()*1.0/RAND_MAX);
	//x[n]=((int)(x[n-1]+i))%700;
	//y[n]=((int)(y[n-1]+j))%500;
	
	int i=(int)(300*rand()*1.0/RAND_MAX);
	int j=(int)(300*rand()*1.0/RAND_MAX);
	x[n] = 200+i;
	y[n] = 100+j;
	
	
	if (n<100)
		n++;
}
/* 
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
	
}

/*iPassiveMouseMove is called to detect and use 
the mouse point without pressing any button */
void iPassiveMouseMove(int mx, int my)
{
	//place your codes here
	mposx = mx;
	mposy = my;
	//printf("%d %d\n",mx,my);
}

/* 
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
		printf("%d %d\n", mx, my);
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed. 
*/
void iKeyboard(unsigned char key)
{
	if(key == 'q')
	{
		exit(0);
		//do something with 'q'
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use 
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, 
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, 
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT 
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
	//place your codes for other keys here
}

void loop();

void main()
{
	srand(100);
	iSetTimer(100, loop);
	iInitialize(800, 600, "MyApp!");
	return;
}

