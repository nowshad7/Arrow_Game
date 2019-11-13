# include "iGraphics.h"
int mposx, mposy;

void iDraw()
{
	//place your drawing codes here	
	iClear();
	iSetColor(255, 128, 128);
	iFilledRectangle(300, 500, 200, 50);
	iSetColor(0, 0, 0);
	iText(350, 520, "YELLOW", GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255, 128, 128);
	iFilledRectangle(300, 400, 200, 50);
	iSetColor(255, 255, 0);
	iText(370, 420, "Black", GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255, 255, 255);
	iFilledRectangle(0, 0, 100, 50);
	iSetColor(255, 255, 255);
	iFilledRectangle(700, 0, 100, 50);
	iSetColor(64, 0, 64);
	iText(25, 15, "YES", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(725, 15, "NO", GLUT_BITMAP_TIMES_ROMAN_24);
	
}


void iMouseMove(int mx, int my)
{
	//place your codes here
}


void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
}

void iPassiveMouseMove(int mx, int my)
{
	//place your code here

	mposx = mx;
	mposy = my;
	if (mx == 2){}        /*Something to do with mx*/
	else if (my == 2){}   /*Something to do with my*/

}


void iKeyboard(unsigned char key)
{
	if (key == 'q')
	{
		//do something with 'q'
	}
	//place your codes for other keys here
}

void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	//place your codes for other keys here
}
//
int main()
{
	//place your own initialization codes here. 
	iInitialize(800, 600, "Shake Your Brain");
	return 0;
}