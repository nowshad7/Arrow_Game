/*
	Robiul Hasan Nowshad
	AUST37
	CSE
*/
# include "iGraphics.h"

#define screenWith 1200
#define screenHight 700
#define animalNo 7
#define arrowNo 30


void arrowRelease();
void arrowFly();
char bc[8][25] = { "stage\\11.bmp", "stage\\22.bmp", "stage\\33.bmp", "stage\\44.bmp", "stage\\55.bmp", "stage\\77.bmp", "stage\\88.bmp", "stage\\99.bmp" };
int stage = 0;
//int stageIndex = 0;
char hit[7][25] = { "hit\\h0.bmp", "hit\\h1.bmp", "hit\\h2.bmp", "hit\\h3.bmp", "hit\\h4.bmp", "hit\\h5.bmp", "hit\\h6.bmp" };
int hitIndex = 0;
bool hitShow = true;
bool continueShow = false;
bool newgameShow = false;
bool highscoreShow = false;
bool controlShow = false;
bool aboutShow = false;
bool exitShow = false;
bool backShow = false;
bool mainShow = false;
int flag1 = 0;
int arrowX;
int arrowY;
int p = -1;
int A1;
int A2;
int A3;
//int p = 0;
//int arrowNumber = 10;
char enemyOne[7][25] = { "eMan\\1.bmp", "eMan\\2.bmp", "eMan\\3.bmp", "eMan\\4.bmp", "eMan\\5.bmp", "eMan\\6.bmp", "eMan\\7.bmp" };
int enemyOneIndex=0;

struct enemy01
{
	int animalX;
	int animalY;
	int animalIndex;
	bool animalShow;
};
enemy01 animal[animalNo];

struct hitArrow 
{
	int x;//=200;
	int y;//=212;
	bool arrowShow;
	int arrowDx;
};
hitArrow arrow[arrowNo];

void animalMovement()
{
	for (int i = 0; i < animalNo; i++)
	{
		if (animal[i].animalShow)
		iShowBMP2(animal[i].animalX, animal[i].animalY, enemyOne[animal[i].animalIndex], 0);
	}
}

void arrowMovement()
{
		for (int i = 0; i < arrowNo; i++)
		{
			if (arrow[i].arrowShow)
			iShowBMP2(arrow[i].x, arrow[i].y, "hit\\arrow.bmp", 0);
		}
}


void iDraw()
{
	if (stage == 0)														//start page
	{
		iClear();
		iShowBMP(0, 0, bc[0]);
		iShowBMP2(900, 50, "b1\\continue.bmp", 0);
		if (continueShow)
			iShowBMP2(900, 50, "b2\\continue.bmp", 0);
	}
	if (stage == 1)														//menu page
	{
		iShowBMP(0, 0, bc[1]);
		iShowBMP2(500, 600, "b1\\newgame.bmp", 0);
		if (newgameShow)
			iShowBMP2(500, 600, "b2\\newgame.bmp", 0);

		iShowBMP2(600, 500, "b1\\highScore.bmp", 0);
		if (highscoreShow)
			iShowBMP2(600, 500, "b2\\highScore.bmp", 0);

		iShowBMP2(700, 400, "b1\\control.bmp", 0);
		if (controlShow)
			iShowBMP2(700, 400, "b2\\control.bmp", 0);

		iShowBMP2(800, 300, "b1\\about.bmp", 0);
		if (aboutShow)
			iShowBMP2(800, 300, "b2\\about.bmp", 0);

		iShowBMP2(900, 200, "b1\\exit.bmp", 0);
		if (exitShow)
			iShowBMP2(900, 200, "b2\\exit.bmp", 0);


	}
	if (stage == 5)													//control page
	{
		iShowBMP(0, 0, bc[6]);
		iShowBMP(50, 400, "help\\control.bmp");
		iShowBMP2(900, 50, "b1\\back.bmp", 0);
		if (backShow)
			iShowBMP2(900, 50, "b2\\back.bmp", 0);
	}

	if (stage == 4)													//about page
	{
		iClear();
		iShowBMP(0, 0, bc[5]);
		iShowBMP(50, 500, "help\\nsd.bmp");
		iShowBMP(50, 300, "help\\mna.bmp");
		iShowBMP(250, 500, "help\\nsd1.bmp");
		iShowBMP(250, 300, "help\\mna1.bmp");
		iShowBMP2(900, 50, "b1\\back.bmp",0);
		if (backShow)
			iShowBMP2(900, 50, "b2\\back.bmp", 0);
	}
	if (stage == 2)													//game page
	{
		iClear();
		iShowBMP(0, 0, bc[3]);
		if (hitShow)
			iShowBMP2(100, 170, hit[hitIndex], 0);

		animalMovement();
		arrowMovement();
	}
	if (stage == 6)
	{
		iClear();
		iShowBMP(0, 0, bc[7]);
		iShowBMP2(900, 50, "b1\\main.bmp", 0);
		if (backShow)
			iShowBMP2(900, 50, "b2\\main.bmp", 0);
	}
	if (stage == 7)
	{
		iClear();
		iShowBMP(0, 0, bc[2]);
		iShowBMP2(950, 20, "b1\\main.bmp", 0);
		if (mainShow)
			iShowBMP2(950, 20, "b2\\main.bmp", 0);
	}

}
void iMouseMove(int mx, int my)
{
	
}

void iMouse(int button, int state, int mx, int my)
{
	if (stage == 0)
	{
		if (mx >= 900 && mx <= 1120 && my >= 50 && my <= 100)
			stage = 1;
	}
	if (stage == 1)
	{
		if (mx >= 500 && mx <= 700 && my >= 600 && my <= 645)
			stage = 2;
		if (mx >= 700 && mx <= 900 && my >= 400 && my <= 445)
			stage = 5;
		if (mx >= 800 && mx <= 1000 && my >= 300 && my <= 345)
			stage = 4;
		if (mx >= 950 && mx <= 1150 && my >= 200 && my <= 245)
			exit(0);
	}
	if (stage == 4)
	{
		if (mx >= 900 && mx <= 1100 && my >= 50 && my <= 95)
			stage = 1;
	}
	if (stage == 5)
	{
		if (mx >= 900 && mx <= 1100 && my >= 50 && my <= 95)
			stage = 1;
	}
	if (stage == 6)
	{
		if (mx >= 900 && mx <= 1100 && my >= 50 && my <= 95)
			stage = 1;
	}
	if (stage == 7)
	{
		if (mx >= 950 && mx <= 1150 && my >= 20 && my <= 65)
			stage = 1;
	}

}
void iPassiveMouseMove(int mx,int my)
{ 
	if (stage == 0)
	{
		if (mx >= 900 && mx <= 1100 && my >= 50 && my <= 95)
			continueShow = true;
		else continueShow = false;
	}
	if (stage == 1)
	{

		if (mx >= 500 && mx <= 700 && my >= 600 && my <= 645)
			newgameShow = true;
		else newgameShow = false;
		if (mx >= 600 && mx <= 800 && my >= 500 && my <= 545)
			highscoreShow = true;
		else highscoreShow = false;
		if (mx >= 700 && mx <= 900 && my >= 400 && my <= 445)
			controlShow = true;
		else controlShow = false;
		if (mx >= 800 && mx <= 1000 && my >= 300 && my <= 345)
			aboutShow = true;
		else aboutShow = false;
		if (mx >= 900 && mx <= 1100 && my >= 200 && my <= 245)
			exitShow = true;
		else exitShow = false;
	}
	if (stage == 4)
	{
		if (mx >= 900 && mx <= 1100 && my >= 50 && my <= 95)
			backShow = true;
		else backShow = false;
	}
	if (stage == 5)
	{
		if (mx >= 900 && mx <= 1100 && my >= 50 && my <= 95)
			backShow = true;
		else backShow = false;
	}
	if (stage == 6)
	{
		if (mx >= 900 && mx <= 1100 && my >= 50 && my <= 95)
			backShow = true;
		else backShow = false;
	}
	if (stage == 7)
	{
		if (mx >= 900 && mx <= 1100 && my >= 20 && my <= 65)
			mainShow = true;
		else mainShow = false;
	}

}

void iKeyboard(unsigned char key)
{
	if (key == 'k')
	{
		p++;
		iResumeTimer(A1);

	}
	if (key == 13)
	{
		//stage = 1;
	}

		

}
	  
void iSpecialKeyboard(unsigned char key)
{
 
}
void arrowRelease()
{
	hitIndex++;
	if (hitIndex >= 7)
	{
		hitIndex = 0;
		iPauseTimer(A1);
		arrow[p].arrowShow = true;
		iResumeTimer(A2);

	}
		
}
void arrowFly()
{
	for (int i = 0; i <= 10; i++)
	{
		if (arrow[i].arrowShow)
		{
			arrow[i].x += 10;
			if (arrow[i].x >= animal[i].animalX)
			{
				arrow[i].arrowShow = false;
				animal[i].animalShow = false;
				if ((i+1) == animalNo)
					stage = 6;
			}
		}
	}
	
}
void change()
{
	for (int i = 0; i < animalNo; i++)
	{
		if (animal[i].animalShow)
		{
			animal[i].animalX -= 10;
			animal[i].animalIndex++;

			if (animal[i].animalIndex >= 7)
				animal[i].animalIndex = 0;

			if (animal[i].animalX < 100)
			{
				hitShow = false;
				//stage = 7;
			}
		}
		
			
	}
	
}
void setAnimalVeriable()
{
	for (int i = 0; i < animalNo; i++)
	{
		animal[i].animalX = 1200 + rand() % 300;
		animal[i].animalY = 170;//0 + rand() % 170;
		animal[i].animalIndex = rand() % 7;
		animal[i].animalShow = true;
	}
}

void setArrowVeriable()
{
	for (int i = 0; i < arrowNo; i++)
	{
		arrow[i].x = 200;
		arrow[i].y = 232;
		//arrow[i].arrowDx = 10;
		arrow[i].arrowShow = false;
	}
}

int main()
{
	setArrowVeriable();
	setAnimalVeriable();
	iSetTimer(100, change);
	A1 = iSetTimer(200, arrowRelease);
	iPauseTimer(A1);
	A2 = iSetTimer(1, arrowFly);
	iPauseTimer(A2);
	
	iInitialize(screenWith, screenHight, "Arrow");
	return 0;
}