#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<GL/glut.h>
#include<math.h>
int s=0;
char *st="HELLO WORLD";
int p=0,b1=0,b=0,i=0,paused=0;
void drawCircle(int centerX, int centerY, int radius);
void singleBuilding(float height, float startX, float startY);
void makeBuildings();
void makeCar();
void makeCarSmoke();
void drawSingleCloud(float x, float y);
void makeRoad();
void makeRoad1();
void eyes(int starts, int ends, int i);
void drawMouse();
void ball(int radius, int p, int q);
void DrawHair(int x, int y,int h,int w);
void DrawEllipse(int radius1,int radius2, int p, int q);
void drawEllipseUnfilled(int radius1,int radius2, int p, int q);
void cat();
void cur1();
void cur2();
void drawText(float x, float y, char* str, int size);
void drawRoom();
void drawTable();
void drawTable4();
void drawCPU();
void drawCPU4();
void drawKeyboard();
void drawChair();
void drawWindowPart();
void drawSun();
void drawMan();
void drawMan2();
void drawConversationCloud(float x, float y, int left); //if left=1, object at left, otherwise object at right
void draw(float x, float y, float size, float distance);  //size=size of , distance=distance b/w two
void drawPaper();
void drawDustbin();
void drawBooksPart();
void drawCatSweat(int k);
void makeSky();
void makeMountains(int i);
void makeRain1(int i);
void makeRain2(int p);
void makeNewMountains();
void makeSea();
void drawPentagon(int x,int y,int side);
void makePieces1();//mountain1
void makePieces2();//mountain1
void makePieces3();//mountain1
void makePieces4();//mountain1
void makeSmoke(int x,int y);
void makeBirds();
void makeChair();
void makeLaptop();
void drawGarbage(int q);
void makeTree(int x, int y, int x1, int y1);
void makeChimneys();
void makeBrainWaves(int w);
void drawThinkingCloud(float x, float y, int left);
void print(int x,int y,char *string);
void init();
void display0();
void display1();
void display2();
void display3();
void display4();
void display5();
void display6();
void display7();
void display8();
void display9();

void drawCircle(int centerX, int centerY, int radius)
{
	int i;
	glBegin(GL_POLYGON);
	for(i=0; i<360; i++)
	{
		float degInRad = i*3.141/180;
		glVertex2f(cos(degInRad)*radius+centerX, sin(degInRad)*radius+centerY);
	}
	glEnd();
}

void singleBuilding(float height, float startX, float startY)
{
	float i,j;
	glBegin(GL_POLYGON);
	glVertex2f(startX, startY);
	glVertex2f(startX+150.0, startY);
	glVertex2f(startX+150.0, startY+height);
	glVertex2f(startX, startY+height);
	glEnd();

	glColor3f(1.0,1.0,1.0);
	for(i=startX+20.0; i<=startX+150.0-40.0; i+=40.0)
	{
		for(j=startY+20.0; j<=startY+height-40.0; j+=40.0)
		{
			int endX, endY;
			endX=i+20;
			endY=j+20;
			glBegin(GL_POLYGON);
			glVertex2f(i, j);
			glVertex2f(endX, j);
			glVertex2f(endX, endY);
			glVertex2f(i, endY);
			glEnd();
		}
	}
}
void makeBuildings()
{
	glColor3f(0.0,1.0,0.95);
	singleBuilding(275.0, 40.0, 375.0);

	glColor3f(1.0,1.0,0.2);
	singleBuilding(185.0, 200.0, 375.0);

	glColor3f(0.2,0.8,0.0);
	singleBuilding(170.0, 120.0, 300.0);

	glColor3f(1.0, 0.1, 1.0);
	singleBuilding(275.0, 310.0, 300.0);

	glColor3f(0.1, 1.0, 1.0);
	singleBuilding(190.0, 480, 350);

	glColor3f(1.0, 0.1, 1.0);
	singleBuilding(210.0, 760, 380);


	glColor3f(0.2,0.8,0.0);
	singleBuilding(350.0, 650, 340);

	glColor3f(1.0,1.0,0.2);
	singleBuilding(270.0, 560, 300);


	glColor3f(0.0, 0.9, 0.45);
	singleBuilding(280.0, 930, 310);

	glColor3f(1.0, 0.2, 0.52);
	singleBuilding(270.0, 1200, 340);

	glColor3f(0.64, 0.1, 1.0);
	singleBuilding(250.0, 1100, 310);


	glColor3f(1.0, 0.2, 0.2);
	singleBuilding(200.0, 1010, 290);

	glColor3f(0.0,1.0,0.95);
	singleBuilding(180.0, 810, 290);

	glColor3f(1.0, 0.2, 0.2);
	singleBuilding(180.0, 380, 290);

	glColor3f(1.0, 0.1, 0.46);
	singleBuilding(230.0, -60, 320);
}
void makeCar()
{
	glBegin(GL_POLYGON);
	glVertex2f(0.0, 175.0);
	glVertex2f(190.0, 175.0);
	glVertex2f(190.0, 225.0);
	glVertex2f(10.0, 225.0);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2f(75.0,225.0);
	glVertex2f(75.0,175.0);
	glEnd();

	//window
	glColor3f(0.7,0.85,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(25.0, 225.0);
	glVertex2f(140.0, 225.0);
	glVertex2f(125.0, 275.0);
	glVertex2f(40.0, 275.0);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2f(70.0,275.0);
	glVertex2f(75.0, 225.0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(140.0,225.0);
	glVertex2f(140.0,175.0);
	glEnd();


	//metal part below
	glColor3f(0.35,0.35,0.35);
	glBegin(GL_POLYGON);
	glVertex2f(00.0, 175.0);
	glVertex2f(50.0, 175.0);
	glVertex2f(50.0, 190.0);
	glVertex2f(0.0, 190.0);
	glEnd();
	glColor3f(0.35,0.35,0.35);
	glBegin(GL_POLYGON);
	glVertex2f(160.0, 175.0);
	glVertex2f(200.0, 175.0);
	glVertex2f(200.0, 195.0);
	glVertex2f(160.0, 195.0);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(85.0, 210.0);
	glVertex2f(110.0, 210.0);
	glVertex2f(110.0, 216.0);
	glVertex2f(85.0, 216.0);
	glEnd();

	//wheels
	drawCircle(35.0,170.0,25.0);
	drawCircle(155.0,170.0,25.0);
	glColor3f(1.0,1.0,1.0);
	drawCircle(35.0,170.0,10.0);
	drawCircle(155.0,170.0,10.0);
}

void makeCarSmoke()
{
	drawCircle(220, 210, 25);
	drawCircle(215, 190, 25);
	drawCircle(235, 200, 35);
	drawCircle(260, 190, 45);
	drawCircle(270, 190, 35);
	drawCircle(290, 180, 30);
	drawCircle(325, 190, 25);
	drawCircle(340, 190, 20);
	drawCircle(365, 190, 15);
}

void drawSingleCloud(float x, float y)
{
	//glColor3f(0.8,0.8,0.7);
	glColor3f(0.90,0.90,0.90);
	drawCircle(x+15, y, 15);
	drawCircle(x+35, y, 20);
	drawCircle(x+60, y, 25);
	drawCircle(x+70, y, 30);
	drawCircle(x+90, y, 35);
	drawCircle(x+125, y, 45);
	drawCircle(x+140, y, 35);
	drawCircle(x+165, y, 25);
}

void makeRoad()
{
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_POLYGON);
	glVertex2f(0.0,120.0);
	glVertex2f(1300.0,120.0);
	glVertex2f(1300.0,260.0);
	glVertex2f(0.0,260.0);
	glEnd();


	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(30.0,183.0);
	glVertex2f(110.0,183.0);
	glVertex2f(110.0,197.0);
	glVertex2f(30.0,197.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(140.0,183.0);
	glVertex2f(220.0,183.0);
	glVertex2f(220.0,197.0);
	glVertex2f(140.0,197.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(250.0,183.0);
	glVertex2f(330.0,183.0);
	glVertex2f(330.0,197.0);
	glVertex2f(250.0,197.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(360.0,183.0);
	glVertex2f(440.0,183.0);
	glVertex2f(440.0,197.0);
	glVertex2f(360.0,197.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(470.0,183.0);
	glVertex2f(550.0,183.0);
	glVertex2f(550.0,197.0);
	glVertex2f(470.0,197.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(580.0,183.0);
	glVertex2f(660.0,183.0);
	glVertex2f(660.0,197.0);
	glVertex2f(580.0,197.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(690.0,183.0);
	glVertex2f(770.0,183.0);
	glVertex2f(770.0,197.0);
	glVertex2f(690.0,197.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(800.0,183.0);
	glVertex2f(880.0,183.0);
	glVertex2f(880.0,197.0);
	glVertex2f(800.0,197.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(910.0,183.0);
	glVertex2f(990.0,183.0);
	glVertex2f(990.0,197.0);
	glVertex2f(910.0,197.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(1020.0,183.0);
	glVertex2f(1100.0,183.0);
	glVertex2f(1100.0,197.0);
	glVertex2f(1020.0,197.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(1130.0,183.0);
	glVertex2f(1210.0,183.0);
	glVertex2f(1210.0,197.0);
	glVertex2f(1130.0,197.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(1240.0,183.0);
	glVertex2f(1300.0,183.0);
	glVertex2f(1300.0,197.0);
	glVertex2f(1240.0,197.0);
	glEnd();
}
void makeRoad1()
{
	glColor3f(0.65,0.65,0.65);
	glBegin(GL_POLYGON);
	glVertex2f(0.0,0.0);
	glVertex2f(1300.0,0.0);
	glVertex2f(1300.0,140.0);
	glVertex2f(0.0,140.0);
	glEnd();


	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(30.0,63.0);
	glVertex2f(110.0,63.0);
	glVertex2f(110.0,77.0);
	glVertex2f(30.0,77.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(140.0,63.0);
	glVertex2f(220.0,63.0);
	glVertex2f(220.0,77.0);
	glVertex2f(140.0,77.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(250.0,63.0);
	glVertex2f(330.0,63.0);
	glVertex2f(330.0,77.0);
	glVertex2f(250.0,77.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(360.0,63.0);
	glVertex2f(440.0,63.0);
	glVertex2f(440.0,77.0);
	glVertex2f(360.0,77.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(470.0,63.0);
	glVertex2f(550.0,63.0);
	glVertex2f(550.0,77.0);
	glVertex2f(470.0,77.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(580.0,63.0);
	glVertex2f(660.0,63.0);
	glVertex2f(660.0,77.0);
	glVertex2f(580.0,77.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(690.0,63.0);
	glVertex2f(770.0,63.0);
	glVertex2f(770.0,77.0);
	glVertex2f(690.0,77.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(800.0,63.0);
	glVertex2f(880.0,63.0);
	glVertex2f(880.0,77.0);
	glVertex2f(800.0,77.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(910.0,63.0);
	glVertex2f(990.0,63.0);
	glVertex2f(990.0,77.0);
	glVertex2f(910.0,77.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(1020.0,63.0);
	glVertex2f(1100.0,63.0);
	glVertex2f(1100.0,77.0);
	glVertex2f(1020.0,77.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(1130.0,63.0);
	glVertex2f(1210.0,63.0);
	glVertex2f(1210.0,77.0);
	glVertex2f(1130.0,77.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(1240.0,63.0);
	glVertex2f(1300.0,63.0);
	glVertex2f(1300.0,77.0);
	glVertex2f(1240.0,77.0);
	glEnd();

	glColor3f(0.65,0.65,0.65);
	glBegin(GL_POLYGON);
	glVertex2f(700.0,140.0);
	glVertex2f(840.0,140.0);
	glVertex2f(840.0,500.0);
	glVertex2f(700.0,500.0);
	glEnd();
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(763.0,150.0);
	glVertex2f(777.0,150.0);
	glVertex2f(777.0,230.0);
	glVertex2f(763.0,230.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(763.0,270.0);
	glVertex2f(777.0,270.0);
	glVertex2f(777.0,350.0);
	glVertex2f(763.0,350.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(763.0,380.0);
	glVertex2f(777.0,380.0);
	glVertex2f(777.0,460.0);
	glVertex2f(763.0,460.0);
	glEnd();
}

void drawMouse()
{
	//filled
	glColor3f(0.9,0.9,0.9);
	DrawEllipse(15, 28, 850, 350);

	//buttons
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2f(835,357);
	glVertex2f(865,357);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(850,357);
	glVertex2f(850,379);
	glEnd();

	//wire
	int i;
	glBegin(GL_POINTS);
	for(i=0; i<135; i++)
	{
		float degInRad = i*3.141/180;
		glVertex2f(cos(degInRad)*30+821, sin(degInRad)*30+379);
	}
	glEnd();
	glBegin(GL_POINTS);
	for(i=190; i<270; i++)
	{
		float degInRad = i*3.141/180;
		glVertex2f(cos(degInRad)*30+800, sin(degInRad)*30+430);
	}
	glEnd();
	glBegin(GL_POINTS);
	for(i=37; i<140; i++)
	{
		float degInRad = i*3.141/180;
		glVertex2f(cos(degInRad)*35+741, sin(degInRad)*43+400);
	}
	glEnd();
}

void ball(int radius, int p, int q)
{

	float x=3.14159/180;

	glBegin(GL_POLYGON);
	for(int i=0;i<360;i++)
	{
		float degInRad= i*x;
		glVertex2f(cos(degInRad)*radius + p, sin(degInRad)*radius +q);
	}
	glEnd();
}
void DrawHair(int x, int y,int h,int w)
{

    glColor3f(0.0,0.0,0.0);
	float x1,y1,z;
	int t;
    glBegin(GL_POLYGON);
    for(t = 0; t <= 20; t +=1)
	{
		x1 = h*sin(t)+x;
		y1 = w*cos(t)+y;
		z = 0;
		glVertex3f(x1,y1,z);
    }
    glEnd();
}

void DrawEllipse(int radius1,int radius2, int p, int q)
{
	float x,y,z;
	int t;
    glBegin(GL_POLYGON);
    for(t = 0; t <= 360; t +=1)
	{
		x = radius1*sin(t)+p;
		y = radius2*cos(t)+q;
		z = 0;
		glVertex3f(x,y,z);
    }
    glEnd();
}
void drawEllipseUnfilled(int radius1,int radius2, int p, int q)
{
	float x,y,z;
	int t;

	glPointSize(1.5);
    glBegin(GL_POINTS);
    for(t = 0; t <= 360; t +=1)
	{
		x = radius1*sin(t)+p;
		y = radius2*cos(t)+q;
		z = 0;
		glVertex3f(x,y,z);
    }
    glEnd();
}
void cat()
{
	//head
	glColor3f(1.0,0.8,0.0);
	ball(30, 1000, 180);
	//body
	DrawEllipse(60,40,1060,140);
	//ears
	glBegin(GL_POLYGON);
	glVertex2f(970,186);
	glVertex2f(990,190);
	glVertex2f(975,230);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(1000,186);
	glVertex2f(1030,180);
	glVertex2f(1015,233);
	glEnd();

	//paws
	DrawEllipse(8,12,1090,100);
	DrawEllipse(8,12,1035,100);

	//eyes blinking & whiskers
	glColor3f(0.0,0.0,0.0);

	//whiskers
	glLineWidth(1.0);
	glBegin(GL_LINES);
	glVertex2f(995,176);
	glVertex2f(970,180);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(995,173);
	glVertex2f(970,173);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(995,170);
	glVertex2f(970,167);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(1006,176);
	glVertex2f(1033,180);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(1006,173);
	glVertex2f(1033,171);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(1006,169);
	glVertex2f(1033,165);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(1000,176);
	glVertex2f(1004,172);
	glVertex2f(996,172);
	glEnd();

	ball(3,990,185);
	ball(3,1010,185);


	 //cat's tail
	float x=3.14159/180,degInRad;
	int radius = 60,p=1162,q=120,i;
	glPointSize(3.0);
	glBegin(GL_POINTS);
	for(i=80;i<145;i++)
	{
		degInRad= i*x;
		glVertex2f(cos(degInRad)*radius + p, sin(degInRad)*radius +q);
	}
	glEnd();

	radius = 60,p=1162,q=237,i;
	glPointSize(3.0);
	glBegin(GL_POINTS);
	for(i=282;i<320;i++)
	{
		degInRad= i*x;
		glVertex2f(cos(degInRad)*radius + p, sin(degInRad)*radius +q);
	}
	glEnd();
	radius = 20,p=1001,q=181,i;
	glPointSize(1.5);
	glBegin(GL_POINTS);
	for(i=260;i<275;i++)
	{
		degInRad= i*x;
		glVertex2f(cos(degInRad)*radius + p, sin(degInRad)*radius +q);
	}
	glEnd();
}

void cur1()
{
	//curtains
	glLineWidth(1.0);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2f(1220,410);
	glVertex2f(1205,310);
	glVertex2f(1205,310);
	glVertex2f(1204,309);
	glVertex2f(1204,309);
	glVertex2f(1203,307);
	glVertex2f(1203,307);
	glVertex2f(1202,305);
	glVertex2f(1202,305);
	glVertex2f(1201,303);
	glVertex2f(1201,303);
	glVertex2f(1200,301);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(1270,420);
	glVertex2f(1255,320);
	glVertex2f(1255,320);
	glVertex2f(1254,319);
	glVertex2f(1254,319);
	glVertex2f(1253,317);
	glVertex2f(1253,317);
	glVertex2f(1252,315);
	glVertex2f(1252,315);
	glVertex2f(1251,313);
	glVertex2f(1251,313);
	glVertex2f(1250,311);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(1200,301);
	glVertex2f(1250,311);
	glEnd();
}
void cur2()
{

	glLineWidth(1.0);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2f(1220,410);
	glVertex2f(1205,301);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(1270,420);
	glVertex2f(1255,311);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(1205,301);
	glVertex2f(1255,311);
	glEnd();
}
void drawText(float x, float y, char* str, int size)
{
	int len = strlen(str);
	//glPushMatrix();
	glRasterPos2f(x, y);
	//glTranslatef(x,y, 0);
	//glScalef(0.5, 0.5, 0.5);
	for(int i=0; i<len; i++)
	{
		if(size == 1)
			//glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, str[i]);
		else if(size==2)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);

	}
}

void drawRoom()
{
	//room

	//top
	glColor3f(0.93,0.97,0.99);
	glBegin(GL_POLYGON);
	glVertex2f(0.0,700.0);
	glVertex2f(100.0,600.0);
	glVertex2f(1200.0,600.0);
	glVertex2f(1300.0,700.0);
	glEnd();

	//left
	glColor3f(0.90,0.59,0.70);
	glBegin(GL_POLYGON);
	glVertex2f(0.0,0.0);
	glVertex2f(100.0,100.0);
	glVertex2f(100.0,600.0);
	glVertex2f(0.0,700.0);
	glEnd();

	//bottom
	glColor3f(0.9,0.9,0.9);
	glBegin(GL_POLYGON);
	glVertex2f(0.0,0.0);
	glVertex2f(100.0,200.0);
	glVertex2f(1200.0,200.0);
	glVertex2f(1300.0,0.0);
	glEnd();

	//right
	glColor3f(0.90,0.59,0.70);
	glBegin(GL_POLYGON);
	glVertex2f(1200.0,200.0);
	glVertex2f(1300.0,0.0);
	glVertex2f(1300.0,700.0);
	glVertex2f(1200.0,600.0);
	glEnd();
}
void drawTable()
{
	//top
	glColor3f(0.5,0.37,0.25);
	glBegin(GL_POLYGON);
	glVertex2f(200.0,300.0);
	glVertex2f(300.0,450.0);
	glVertex2f(1000.0,450.0);
	glVertex2f(900.0,300.0);
	glEnd();
	//leg left
	glBegin(GL_POLYGON);
	glVertex2f(200.0,100.0);
	glVertex2f(450.0,100.0);
    glVertex2f(450.0,300.0);
	glVertex2f(200.0,300.0);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2f(200,300);
	glVertex2f(450,300);
	glEnd();
}
void drawTable4()
{
	//top
	glColor3f(0.5,0.37,0.25);
	glBegin(GL_POLYGON);
	glVertex2f(0.0,600.0);
	glVertex2f(0.0,700.0);
	glVertex2f(1300.0,700.0);
	glVertex2f(1300.0,600.0);
	glEnd();
	//leg left
	glBegin(GL_POLYGON);
	glVertex2f(0.0,30.0);
	glVertex2f(350.0,30.0);
    glVertex2f(350.0,600.0);
	glVertex2f(0.0,600.0);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2f(0,600);
	glVertex2f(350,600);
	glEnd();
}
void drawCPU()
{
	//CPU cabinet
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(270,120);
	glVertex2f(370,120);
    glVertex2f(370.0,260.0);
	glVertex2f(270.0,260.0);
	glEnd();
	glColor3f(0,0,0);
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2f(270,240);
	glVertex2f(370,240);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(270,230);
	glVertex2f(370,230);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(270,140);
	glVertex2f(370,140);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(275,210);
	glVertex2f(285,210);
	glVertex2f(285,220);
	glVertex2f(275,220);
	glEnd();

	//cpu name
	glColor3f(0.0,0.0,0.0);
	drawText(290,125,"Stardust CPU",1);
}
void drawCPU4()
{
	//CPU cabinet
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(40,70);
	glVertex2f(310,70);
    glVertex2f(310.0,530.0);
	glVertex2f(40.0,530.0);
	glEnd();
	glColor3f(0,0,0);
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2f(40,460);
	glVertex2f(310,460);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(40,440);
	glVertex2f(310,440);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(40,140);
	glVertex2f(310,140);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(60,380);
	glVertex2f(60,420);
	glVertex2f(100,420);
	glVertex2f(100,380);
	glEnd();

	//CPU name
	glColor3f(0.0,0.0,0.0);
	drawText(105,100,"Stardust CPU",2);
}
void drawKeyboard()
{
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(510.0,375.0);
	glVertex2f(720.0,375.0);
    glVertex2f(700.0,320.0);
	glVertex2f(490.0,320.0);
	glEnd();
	glLineWidth(1.0);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2f(507.0,366.0);
	glVertex2f(720.0,366.0);
    glVertex2f(503.0,358.0);
	glVertex2f(720.0,358.0);
	glVertex2f(500.0,350.0);
	glVertex2f(720.0,350.0);
	glVertex2f(497.0,342.0);
	glVertex2f(720.0,342.0);
	glVertex2f(495.0,334.0);
	glVertex2f(720.0,334.0);
	glVertex2f(492.0,327.0);
	glVertex2f(720.0,327.0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(503.0,320.0);
	glVertex2f(523.0,375.0);
    glVertex2f(516.0,320.0);
	glVertex2f(536.0,375.0);
	glVertex2f(529.0,320.0);
	glVertex2f(549.0,375.0);
	glVertex2f(541.0,320.0);
	glVertex2f(561.0,375.0);
	glVertex2f(554.0,320.0);
	glVertex2f(574.0,375.0);
	glVertex2f(567.0,320.0);
	glVertex2f(587.0,375.0);
	glVertex2f(580.0,320.0);
	glVertex2f(600.0,375.0);
	glEnd();
}
void drawChair()
{
	//chair left leg
	glColor3f(0.396,0.26,0.13);
	glBegin(GL_POLYGON);
	glVertex2f(585.0,100.0);
	glVertex2f(625.0,100.0);
    glVertex2f(625.0,220.0);
	glVertex2f(585.0,220.0);
	glEnd();

    //chair top
	glColor3f(0.396,0.26,0.13);
	glBegin(GL_POLYGON);
	glVertex2f(585.0,220.0);
	glVertex2f(585.0,370.0);
    glVertex2f(745.0,370.0);
	glVertex2f(745.0,220.0);
	glEnd();

	//chair right leg
	glColor3f(0.396,0.26,0.13);
	glBegin(GL_POLYGON);
	glVertex2f(745.0,100.0);
	glVertex2f(745.0,220.0);
    glVertex2f(705.0,220.0);
	glVertex2f(705.0,100.0);
	glEnd();
}
void drawWindowPart()
{
	//window
	glColor3f(1.0,1.0,0.6);
	glBegin(GL_POLYGON);
	glVertex2f(1220.0,290.0);
	glVertex2f(1270.0,300.0);
    glVertex2f(1270.0,420.0);
	glVertex2f(1220.0,410.0);
	glEnd();
	glLineWidth(3.0);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2f(1245.0,295.0);
	glVertex2f(1245.0,415.0);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2f(1220.0,350.0);
	glVertex2f(1270.0,360.0);
	glEnd();
	//curtains
	if((b1)<300)
	{
	(b1)++;
	cur1();

	}
	else if((b1)>=300 && (b1)<600)
	{
		(b1)++;
		cur2();

	}
	if((b1)==600)
		(b1)=0;
}
void drawSun()
{
	if(b<500)
	{
	glColor3f(1.0,0.86,0.3);
	b++;

	}
	else if(b>=500 && b<1000)
	{
		glColor3f(1.0,0.8,0.0);
		b++;

	}
	if(b==1000)
		b=0;
	ball(10,1232,390);
}
void drawMan()
{
	//man's hands
	glColor3f(0.92,0.75,0.53);
	glBegin(GL_POLYGON);
	glVertex2f(605,370);
	glVertex2f(605,410);
    glVertex2f(555,310);
	glVertex2f(585,310);
	glEnd();
	//glColor3f(0.92,0.75,0.53);
	glBegin(GL_POLYGON);
	glVertex2f(725,370);
	glVertex2f(725,410);
    glVertex2f(775,310);
	glVertex2f(740,310);
	glEnd();

	//man's body
	glColor3f(0.4,0.0,0.34);
	glBegin(GL_POLYGON);
	glVertex2f(605.0,370.0);
	glVertex2f(605.0,410.0);
    glVertex2f(725.0,410.0);
	glVertex2f(725.0,370.0);
	glEnd();

	//man's head
	glColor3f(0.92,0.75,0.53);
	DrawEllipse(40,45,665,465);
	glColor3f(0.0,0.0,0.0);

	DrawHair(665, 465, 45, 50);

	//neck
	glColor3f(0.92,0.75,0.53);
	glBegin(GL_POLYGON);
	glVertex2f(650.0,410.0);
	glVertex2f(680.0,410.0);
    glVertex2f(675,422);
	glVertex2f(655,422);
	glEnd();
}
void drawMan2()
{
	DrawHair(1000,400,30,35);
	//head
	glColor3f(0.92,0.75,0.53);
	DrawEllipse(25,30,1000,400);

	//neck
	glBegin(GL_POLYGON);
	glVertex2f(995,370);
	glVertex2f(990,360);
	glVertex2f(1005,360);
	glVertex2f(1000,370);
	glEnd();

	//body
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(970,360);
	glVertex2f(970,300);
	glVertex2f(1030,300);
	glVertex2f(1030,360);
	glEnd();

	//left leg
	glColor3f(0,0,0);

	//shoes
	DrawEllipse(15,10,979,215);
	DrawEllipse(15,10,1021,215);

	glBegin(GL_POLYGON);
	glVertex2f(970,300);
	glVertex2f(970,220);
	glVertex2f(995,220);
	glVertex2f(1005,300);

	//right leg
	glBegin(GL_POLYGON);
	glVertex2f(995,300);
	glVertex2f(1005,220);
	glVertex2f(1030,220);
	glVertex2f(1030,300);
	glEnd();

	//hands
	glColor3f(0.92,0.75,0.53);
	DrawEllipse(10,15,960,310);
	DrawEllipse(10,15,1040,310);
	glBegin(GL_POLYGON);
	glVertex2f(970,360);
	glVertex2f(950,310);
	glVertex2f(970,310);
	glEnd();
	glColor3f(0.92,0.75,0.53);
	glBegin(GL_POLYGON);
	glVertex2f(1030,360);
	glVertex2f(1050,310);
	glVertex2f(1030,310);
	glEnd();

	//
	glColor3f(0,0,0);
	DrawEllipse(3,5,990,410);
	DrawEllipse(3,5,1010,410);

	//smile
	glColor3f(0,0,0);
	glLineWidth(2.0);
	glBegin(GL_POLYGON);
	for(i=240; i<300; i++)
	{
		float degInRad = i*3.141/180;
		glVertex2f(cos(degInRad)*20+1000, sin(degInRad)*30+411);
	}
	glEnd();
	//more hair

	glColor3f(0,0,0);
	glLineWidth(2.0);
	glBegin(GL_POLYGON);
	for(i=55; i<140; i++)
	{
		float degInRad = i*3.141/180;
		glVertex2f(cos(degInRad)*30+1000, sin(degInRad)*40+391);
	}
	glEnd();

}
void drawConversationCloud(float x, float y, int left)
{
	glColor3f(1.0,1.0,1.0);
	drawCircle(x+100, y, 65);
	drawCircle(x+110, y, 70);
	drawCircle(x+130, y, 75);
	drawCircle(x+165, y, 85);
	drawCircle(x+180, y, 85);
	drawCircle(x+215, y, 65);

	if(left == 1) //conversing object at left
	{
		glBegin(GL_POLYGON);
		glVertex2f(x+90, y+35);
		glVertex2f(x+40, y-70);
		glVertex2f(x+120, y+35);
		glEnd();
	}
	else //conversing object at right
	{
		glBegin(GL_POLYGON);
		glVertex2f(x+270, y+25);
		glVertex2f(x+290, y-40);
		glVertex2f(x+240, y+25);
		glEnd();
	}
}
void draw(float x, float y, float size, float distance)
{
	//distance means distance beteen two
	glColor3f(0.0,0.0,0.0);
	glLineWidth(1.0);
	drawEllipseUnfilled(size/1.6,size, x, y);
	DrawEllipse((size/1.6)/1.5,size/1.5,x,y);
	drawEllipseUnfilled(size/1.6,size, x+distance, y);
	DrawEllipse((size/1.6)/1.5,size/1.5,x+distance,y);
}
void drawPaper()
{
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(1020,80);
	glVertex2f(1050,120);
	glVertex2f(1110,120);
	glVertex2f(1080,80);
	glEnd();
}
void drawDustbin()
{
	//drawDustbin();
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(650,350);
	glVertex2f(770,350);
	glVertex2f(770,370);
	glVertex2f(650,370);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(650,350);
	glVertex2f(670,200);
	glVertex2f(750,200);
	glVertex2f(770,350);
	glEnd();

	glColor3f(1.0,1.0,1.0);
	drawText(685, 300, "USE", 2);
	drawText(690, 275, "ME", 2);
}
void drawBooksPart()
{
	glColor3f(0.7,0.24,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(1000,320);
	glVertex2f(1000,400);
	glVertex2f(1250,400);
	glVertex2f(1250,320);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(1000,400);
	glVertex2f(1250,400);
	glVertex2f(1260,370);
	glVertex2f(990,370);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(1000,400);
	glVertex2f(1250,400);
	glVertex2f(1260,370);
	glVertex2f(990,370);
	glEnd();
	for(int j=1000; j<=1240; j+=10)
	{
		glColor3f(0.7,0.0,0.0);
		glBegin(GL_POLYGON);
		glVertex2f(j,400);
		glVertex2f(j+10,400);
		glVertex2f(j+10,410);
		glVertex2f(j,410);
		glEnd();
		glColor3f(0.0,0.0,0.0);
		glBegin(GL_LINE_LOOP);
		glVertex2f(j,400);
		glVertex2f(j+10,400);
		glVertex2f(j+10,410);
		glVertex2f(j,410);
		glEnd();
	}
	glColor3f(0.7,0.24,0.0);
	glBegin(GL_LINES);
	glVertex2f(1000,400);
	glVertex2f(1250,400);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	drawText(1085,335,"BOOKS",2);
}
void drawCatSweat(int k)
{
	glColor3f(0.4,0.7,1.0);
	if(k>=0 && k<200)
	{
		DrawEllipse(3,8,840,110);
		DrawEllipse(3,8,860,110);
		DrawEllipse(3,8,850,130);
		DrawEllipse(3,8,870,130);
		DrawEllipse(3,8,880,110);
		DrawEllipse(3,8,880,130);
		DrawEllipse(3,8,850,150);
		DrawEllipse(3,8,870,150);
		DrawEllipse(3,8,890,150);
		DrawEllipse(3,8,890,120);
	}
	else
	{
		DrawEllipse(3,8,840,100);
		DrawEllipse(3,8,860,100);
		DrawEllipse(3,8,850,120);
		DrawEllipse(3,8,870,120);
		DrawEllipse(3,8,880,100);
		DrawEllipse(3,8,880,120);
		DrawEllipse(3,8,850,140);
		DrawEllipse(3,8,870,140);
		DrawEllipse(3,8,890,140);
		DrawEllipse(3,8,890,110);
	}
}

void makeSky()
{

	glColor3f(0.9,0.96,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(0.0,700.0);
	glVertex2f(1300.0,700.0);
	glVertex2f(1300.0, 450.0);
	glVertex2f(0.0,450.0);
	glEnd();
}
void makeMountains(int i)
{
	glColor3f(0.396,0.26,0.13);
	glBegin(GL_POLYGON);
	glVertex2f(0,450);
	glVertex2f(250,660);
	glVertex2f(500,450);
	glEnd();
	if(i<400)
	{
	glColor3f(0.38,0.24,0.13);
	glBegin(GL_POLYGON);
	glVertex2f(400,450);
	glVertex2f(500,690);
	glVertex2f(650,450);
	glEnd();
	glColor3f(0.396,0.26,0.13);
	glBegin(GL_POLYGON);
	glVertex2f(630,450);
	glVertex2f(800,600);
	glVertex2f(970,450);
	glEnd();
	}
	glColor3f(0.38,0.24,0.13);
	glBegin(GL_POLYGON);
	glVertex2f(950,450);
	glVertex2f(1100,680);
	glVertex2f(1300,450);
	glEnd();

}
void makeRain1(int i)
{

	glPushMatrix();
	glTranslatef((0.0-(i/2.0)),(0.0-(i/3.0)),0.0);
	DrawEllipse(3,4,1100,630);
	DrawEllipse(3,4,1130,620);
	DrawEllipse(3,5,1150,630);
	DrawEllipse(3,4,1100,600);
	DrawEllipse(3,5,1170,620);
	DrawEllipse(3,5,1190,640);
	DrawEllipse(3,4,1170,590);
	DrawEllipse(3,5,1210,630);
	DrawEllipse(2,4,1230,620);
	glPopMatrix();
	//rain cloud2
	glPushMatrix();
	glTranslatef((0.0-(i/2.0)),(0.0-(i/3.0)),0.0);
	DrawEllipse(3,4,800,610);
	DrawEllipse(3,4,830,600);
	DrawEllipse(3,5,810,560);
	DrawEllipse(3,4,850,600);
	DrawEllipse(3,5,890,620);
	DrawEllipse(3,5,820,570);
	DrawEllipse(3,4,820,590);
	DrawEllipse(3,5,910,560);
	DrawEllipse(2,4,930,620);
	glPopMatrix();
}
void makeRain2(int p)
{

	//rain cloud1
	glPushMatrix();
	glTranslatef((0.0-(p/2.0)),(0.0-(p/3.0)),0.0);
	DrawEllipse(3,4,1000,630);
	DrawEllipse(3,4,1030,620);
	DrawEllipse(3,5,1050,630);
	DrawEllipse(3,4,1000,600);
	DrawEllipse(3,5,1070,620);
	DrawEllipse(3,5,1090,640);
	DrawEllipse(3,4,1070,590);
	DrawEllipse(3,5,1110,630);
	DrawEllipse(2,4,1130,620);
	glPopMatrix();
	//rain cloud2
	glPushMatrix();
	glTranslatef((0.0-(p/2.0)),(0.0-(p/3.0)),0.0);
	DrawEllipse(3,4,700,610);
	DrawEllipse(3,4,730,600);
	DrawEllipse(3,5,710,560);
	DrawEllipse(3,4,750,600);
	DrawEllipse(3,5,790,620);
	DrawEllipse(3,5,720,570);
	DrawEllipse(3,4,720,590);
	DrawEllipse(3,5,810,560);
	DrawEllipse(2,4,830,620);
	glPopMatrix();
}
void makeNewMountains()
{

	glColor3f(0.38,0.24,0.13);
	glBegin(GL_POLYGON);
	glVertex2f(400,450);
	glVertex2f(500,690);
	glVertex2f(590,540);
	glVertex2f(570,530);
	glVertex2f(590,520);
	glVertex2f(590,480);
	glVertex2f(640,460);
	glVertex2f(650,450);
	glEnd();
	glColor3f(0.396,0.26,0.13);
	glBegin(GL_POLYGON);
	glVertex2f(650,450);
	glVertex2f(800,600);
	glVertex2f(820,580);
	glVertex2f(840,530);
	glVertex2f(890,480);
	glVertex2f(970,450);
	glEnd();
}
void makeSea()
{
//sea
	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glVertex2f(0,450);
	glVertex2f(1300,450);
	glVertex2f(1300,0);
	glEnd();
}
void drawPentagon(int x,int y,int side)
{
	glBegin(GL_POLYGON);
	glVertex2f(x,y);
	glVertex2f(x-side,y+10);
	glVertex2f(x,y+side+10);
	glVertex2f(x+side,y+side+10);
	glVertex2f(x+side+25,y+10);
	glVertex2f(x+side,y);
	glEnd();
}
void makePieces1()//mountain1
{
	//ellipse
	DrawEllipse(20,30,650,450);//mountain1

	DrawEllipse(25,40,640,390);//m1
	drawPentagon(650,390,30);
	drawPentagon(660,430,40);

}
void makePieces2()//mountain1
{

	DrawEllipse(30,65,650,430);//m1
	drawPentagon(640,460,32);
}
void makePieces3()
{
	drawPentagon(940,500,45);
	drawPentagon(950,465,50);
	DrawEllipse(10,15,950,420);//m2
	DrawEllipse(25,44,940,460);//m2

}
void makePieces4()
{
	DrawEllipse(30,24,950,430);

	drawPentagon(950,480,60);
		DrawEllipse(30,40,950,450);//mountain2

}
void makeSmoke(int x,int y)
{
	drawCircle(x+15, y, 15);
	drawCircle(x+35, y, 20);
	drawCircle(x+60, y, 25);
	drawCircle(x+70, y, 30);
	drawCircle(x+90, y, 35);
	drawCircle(x+115, y, 25);

}
void makeBirds()
{
	glLineWidth(2.0);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2f(680,600);
	glVertex2f(690,600);
	glVertex2f(690,600);
	glVertex2f(710,580);
	glVertex2f(710,580);
	glVertex2f(730,600);
	glVertex2f(730,600);
	glVertex2f(740,600);

	glVertex2f(630,620);
	glVertex2f(640,620);
	glVertex2f(640,620);
	glVertex2f(660,600);
	glVertex2f(660,600);
	glVertex2f(680,620);
	glVertex2f(680,620);
	glVertex2f(690,620);

	glVertex2f(580,640);
	glVertex2f(590,640);
	glVertex2f(590,640);
	glVertex2f(610,620);
	glVertex2f(610,620);
	glVertex2f(630,640);
	glVertex2f(630,640);
	glVertex2f(640,640);
	glEnd();
}
void makeChair()
{
	//chair legs
	glColor3f(0.55,0.27,0.07);
	glBegin(GL_POLYGON);
	glVertex2f(100,300);
	glVertex2f(115,300);
	glVertex2f(115,220);
	glVertex2f(100,220);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(400,300);
	glVertex2f(385,300);
	glVertex2f(385,220);
	glVertex2f(400,220);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(140,380);
	glVertex2f(165,380);
	glVertex2f(165,300);
	glVertex2f(140,300);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(440,380);
	glVertex2f(425,380);
	glVertex2f(425,300);
	glVertex2f(440,300);
	glEnd();

	//sitting space
	glColor3f(0.0,0.48,0.8);
	glBegin(GL_POLYGON);
	glVertex2f(100,300);
	glVertex2f(400,300);
	glVertex2f(440,380);
	glVertex2f(140,380);
	glEnd();

	//rester
	glLineWidth(3.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(140,380);
	glVertex2f(440,380);
	glVertex2f(440,480);
	glVertex2f(140,480);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(140,400);
	glVertex2f(440,400);
	glVertex2f(140,420);
	glVertex2f(440,420);
	glVertex2f(140,440);
	glVertex2f(440,440);
	glVertex2f(140,460);
	glVertex2f(440,460);
	glEnd();
}
void makeLaptop()
{
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(200,320);
	glVertex2f(300,320);
	glVertex2f(330,370);
	glVertex2f(230,370);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(200,320);
	glVertex2f(300,320);
	glVertex2f(330,370);
	glVertex2f(330,360);
	glVertex2f(300,310);
	glVertex2f(200,310);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(230,440);
	glVertex2f(330,440);
	glVertex2f(330,370);
	glVertex2f(230,370);
	glEnd();

	glColor3f(0.0,0.48,0.8);
	glBegin(GL_LINES);
	glVertex2f(245,365);
	glVertex2f(315,365);
	glEnd();

	//laptop screen
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(240,430);
	glVertex2f(320,430);
	glVertex2f(320,380);
	glVertex2f(240,380);
	glEnd();

	//keyboard
	glPushMatrix();
	glTranslatef(-3,-5,0);
	glLineWidth(1.0);
	glBegin(GL_LINES);
	for(int j=215; j<=295; j+=10)
	{
		glVertex2f(j,330);
		glVertex2f(j+18,360);
	}
	glVertex2f(215,330);
	glVertex2f(295,330);
	glVertex2f(221,340);
	glVertex2f(301,340);
	glVertex2f(227,350);
	glVertex2f(307,350);
	glVertex2f(233,360);
	glVertex2f(313,360);
	glEnd();
	glPopMatrix();
}

void makeEarth()
{
	glColor3f(0.2,0.6,1.0);
	drawCircle(1050,550,100);
	glColor3f(0.4,1.0,0.6);
	drawCircle(1030,500,20);
	drawCircle(1050,500,20);
	drawCircle(1050,470,20);
	drawCircle(1000,530,30);
	drawCircle(980,530,20);

	drawCircle(1075,625,20);
	drawCircle(1055,615,20);
	drawCircle(1075,595,30);
	drawCircle(1060,635,15);

	drawCircle(1115,500,20);
	drawCircle(1125,520,20);
}
void drawGarbage(int q)
{
	glColor3f(0.81,0.52,0.25);
	glPushMatrix();
	glTranslatef(0-(q/26.0),0,0);
	drawPentagon(500,500,13);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0+(q/26.0),0+(q/29.0),0);
	drawPentagon(200,400,16);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0+(q/28.0),0+q/26.0,0);
	drawPentagon(200,400,16);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0+(q/29.0),0-(q/27.0),0);
	DrawEllipse(15,10,340,560);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0-(q/29.0),0,0);
	drawPentagon(400,300,23);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0+(q/26.0),0,0);
	drawPentagon(100,300,13);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0+(q/29.0),0-(q/29.0),0);
	drawPentagon(100,300,13);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0+(q/27.0),0-(q/28.0),0);
	drawPentagon(100,600,33);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0-(q/29.0),0-(q/30.0),0);
	drawPentagon(600,600,23);
	glPopMatrix();


	DrawEllipse(25,10,600,450);
	DrawEllipse(15,20,400,240);

	drawPentagon(400,600,13);
}
void makeTree(int x, int y, int x1, int y1)
{
	glColor3f(0,0.7,0);
	drawCircle(x+35,y,25);
	drawCircle(x+60,y,42);
	drawCircle(x+85,y,25);

	glColor3f(0.38,0.24,0.13);
	glBegin(GL_POLYGON);
	glVertex2f(x1+10,y1+50);
	glVertex2f(x1,y1);
	glVertex2f(x1+40,y1);
	glVertex2f(x1+30,y1+50);
	glEnd();

}
void makeChimneys()
{

	glColor3f(0.545,0.545,0.478);
	glBegin(GL_POLYGON);
	glVertex2f(825,580);
	glVertex2f(825,640);
	glVertex2f(845,650);
	glVertex2f(845,580);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(1005,580);
	glVertex2f(1005,640);
	glVertex2f(1025,650);
	glVertex2f(1025,580);
	glEnd();
}
void makeBrainWaves(int w)
{

	glColor3f(0,0,0);
	glPushMatrix();
	glTranslatef(0+(w/10.0),0+(w/10.0),0);
	glLineWidth(0.5);
	glBegin(GL_LINES);
	glVertex2f(1030,420);
	glVertex2f(1080,440);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0+(w/10.0),0,0);
	glLineWidth(0.5);
	glBegin(GL_LINES);
	glVertex2f(1030,400);
	glVertex2f(1080,400);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0+(w/10.0),0-(w/10.0),0);
	glLineWidth(0.5);
	glBegin(GL_LINES);
	glVertex2f(1030,390);
	glVertex2f(1080,370);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0-(w/10.0),0+(w/10.0),0);
	glLineWidth(0.5);
	glBegin(GL_LINES);
	glVertex2f(970,420);
	glVertex2f(920,440);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0-(w/10.0),0,0);
	glLineWidth(0.5);
	glBegin(GL_LINES);
	glVertex2f(970,400);
	glVertex2f(920,400);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0-(w/10.0),0-(w/10.0),0);
	glLineWidth(0.5);
	glBegin(GL_LINES);
	glVertex2f(970,390);
	glVertex2f(920,370);
	glEnd();
	glPopMatrix();
}
void drawThinkingCloud(float x, float y, int left)
{
	glColor3f(1.0,1.0,1.0);
	drawCircle(x+80, y, 25);
	drawCircle(x+90, y, 30);
	drawCircle(x+110, y, 35);
	drawCircle(x+105, y, 45);
	drawCircle(x+120, y, 35);
	drawCircle(x+145, y, 25);

	if(left == 1) //conversing object at left
	{
		DrawEllipse(15,10,x+45,y-5);
		DrawEllipse(10,7,x+30,y-15);

	}
	else //conversing object at right
	{

		DrawEllipse(15,10,x+183,y-5);
		DrawEllipse(10,7,x+195,y+5);

	}

}

void makeWave(int x, int y)
{
glLineWidth(3.5);
	glBegin(GL_LINES);
	for(i=240; i<300; i++)
	{
		float degInRad = i*3.141/180;
		glVertex2f(cos(degInRad)*40+x, sin(degInRad)*40+y);
	}
	glEnd();
	glBegin(GL_LINES);
	for(i=40; i<120; i++)
	{
		float degInRad = i*3.141/180;
		glVertex2f(cos(degInRad)*40+(x+35), sin(degInRad)*40+(y-70));
	}
	glEnd();
}
void makeManyWaves()
{
for(int a=0;a<800;a+=200)
			for(int g=0;g<800;g+=100)
				makeWave(0+a,300+g);
}

void print(int x,int y,char *string)
{
	int i;
	glPushMatrix();
	glRasterPos2f(x,y);
	glTranslatef(x, y, 0);
	glScalef(0.5, 0.5, 0.5);
	int len=(int)strlen(string);
	for(i=0;i<len;i++)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN,string[i]);
	}
	glPopMatrix();
}

void display0()
{
	glLoadIdentity();
	gluOrtho2D(0,1300,0,700);
	glClear(GL_COLOR_BUFFER_BIT);
	//background
	glColor3f(0.0,0.2,0.4);
	glBegin(GL_POLYGON);
	glVertex2f(0.0,0.0);
	glVertex2f(1300.0,0.0);
	glVertex2f(1300.0, 700.0);
	glVertex2f(0.0,700.0);
	glEnd();


	glColor3f(1.0,1.0,0.2);

	//continue option
	drawText(1000, 120, "Help",2);
	drawText(1000, 70, "Press C to continue", 2);
	drawText(1000, 40, "At any time, press 1-9 to switch among slides", 2);

	//Team Members
	drawText(10, 100, "Team Members:", 2);
	drawText(20, 60, "1. Apoorva Jaiswal (USN: 1DS14CS014)", 2);
	drawText(20, 35, "2. Ashish Agarwal (USN: 1DS14CS016)", 2);

	//guidance
	drawText(500, 300, "Under the guidance of:", 2);
	drawText(300, 235, "Prof. Sasidhar B", 2);
	drawText(700, 235, "Prof. Sahana Damale", 2);

	glColor3f(1.0,1.0,1.0);
	//Topic
	print(250, 390, "COMPUTERS'  DAY" );


	glFlush();
	glutSwapBuffers();
}

void display1()
{
	b=0; b1=0; i=0;
	int pauses=0;
	glLoadIdentity();
	gluOrtho2D(0,1300,0,700);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.90,0.59,0.70);
	for(int h=0;h<3000;h++)
	{

	glClear(GL_COLOR_BUFFER_BIT);

	//room
	drawRoom();

	//table
	drawTable();

	//CPU cabinet
	drawCPU();

	//right front left
	glColor3f(0.5,0.37,0.25);
	glBegin(GL_POLYGON);
	glVertex2f(850.0,300.0);
	glVertex2f(900.0,300.0);
    glVertex2f(900.0,100.0);
	glVertex2f(850.0,100.0);
	glEnd();
	//right behind leg
	glBegin(GL_POLYGON);
	glVertex2f(1000.0,450.0);
	glVertex2f(1000.0,200.0);
    glVertex2f(960.0,200.0);
	glVertex2f(960.0,400.0);
	glEnd();
	//monitor screen
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(520.0,400.0);
	glVertex2f(520.0,550.0);
    glVertex2f(720.0,550.0);
	glVertex2f(720.0,400.0);
	glEnd();

	//monitor inside
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(530.0,410.0);
	glVertex2f(530.0,540.0);
    glVertex2f(710.0,540.0);
	glVertex2f(710.0,410.0);
	glEnd();
	//text changing
	//TEXTTTT
	glColor3f(0.0,0.0,0.0);
	if(p == 0)
	{
		if(h%200 == 0)
			st++;
		if(*st =='\0')
			p=1;
		else
			drawText(540, 460, st,2);
	}
	else
	{
		drawText(540,460,"Shut down",2);
	}

	//keyboard
	drawKeyboard();

	//triangle under monitor
	glBegin(GL_POLYGON);
	glVertex2f(625.0,400.0);
	glVertex2f(600.0,390.0);
    glVertex2f(650.0,390.0);
	glEnd();

	//man
	drawMan();

	//chair
	drawChair();

	//mouse
	drawMouse();

	//window and curtain
	drawWindowPart();

	//sun
	drawSun();

	//Cat
	glPushMatrix();
	glTranslatef((0.0-(float)(h/6)),0.0-(float)(h/36),0.0);
	cat();
	glPopMatrix();

	glPushMatrix();
	//cat's ball
	glColor3f(1.0,0.0,0.0);


	glTranslatef((0.0-(float)(h/12)),0.0-(float)(h/36),0.0);
	ball(20,800,100);
	glPopMatrix();
	if(h>=1200 && h<=3000)
	{
		glPushMatrix();
		glTranslatef(0,0,0);
		glScalef(3.7,2.6,0);
		drawThinkingCloud(170,190,1);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(850,410,0);
		glScalef(0.3,0.4,0);
		makeRoad();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(830+(h/15.0),0+370,0);
		glScalef(0.7,0.7,0);
		glColor3f(0.8,0.0,0.0);
		makeCar();
		glPopMatrix();

	}


	glFlush();
	glutSwapBuffers();
	}
//	glFlush();
	display2();

}
void display2()
{
	b1=0; b=0; i=0;
	glLoadIdentity();
	gluOrtho2D(0,1300,0,700);
	glClear(GL_COLOR_BUFFER_BIT);
	int p=0;
	glColor3f(0.90,0.59,0.70);
	for(int h=0;h<1550;h++)
	{
	if(h>750 && h<=850)
	{
		glLoadIdentity();
		gluOrtho2D(100,1300,0,700);
	}
	else if(h<=900)
	{
		glLoadIdentity();
		gluOrtho2D(250,1300,20,660);
	}
	else if(h<=950)
	{
		glLoadIdentity();
		gluOrtho2D(400,1300,40,640);
	}
	else if(h<=1000)
	{
		glLoadIdentity();
		gluOrtho2D(500,1300,60,620);
	}
	else if(h<=1050)
	{
		glLoadIdentity();
		gluOrtho2D(600,1299,80,600);
	}
	else if(h<=1100)
	{
		glLoadIdentity();
		gluOrtho2D(750,1297,100,580);
	}
	else if(h<=1150)
	{
		glLoadIdentity();
		gluOrtho2D(850,1295,120,560);
	}
	else if(h<=1200)
	{
		glLoadIdentity();
		gluOrtho2D(950,1293,140,540);
	}
	else if(h<=1250)
	{
		glLoadIdentity();
		gluOrtho2D(1000,1290,160,520);
	}
	else if(h<=1350)
	{
		glLoadIdentity();
		gluOrtho2D(1100,1285,200,480);
	}
	else if(h<=1400)
	{
		glLoadIdentity();
		gluOrtho2D(1150,1280,220,460);
	}
	else if(h<=1450)
	{
		glLoadIdentity();
		gluOrtho2D(1200,1274,240,440);
	}
	else
	{
		glLoadIdentity();
		gluOrtho2D(1219,1271,280,420);
	}
	glClear(GL_COLOR_BUFFER_BIT);

	//room
	drawRoom();

	//table
	drawTable();

	//CPU
	drawCPU();
	if(h>30)
		draw(280, 270, 16, 80);

	//right front left
	glColor3f(0.5,0.37,0.25);
	glBegin(GL_POLYGON);
	glVertex2f(850.0,300.0);
	glVertex2f(900.0,300.0);
    glVertex2f(900.0,100.0);
	glVertex2f(850.0,100.0);
	glEnd();
	//right behind leg
	glBegin(GL_POLYGON);
	glVertex2f(1000.0,450.0);
	glVertex2f(1000.0,200.0);
    glVertex2f(960.0,200.0);
	glVertex2f(960.0,400.0);
	glEnd();
	//monitor screen
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(520.0,400.0);
	glVertex2f(520.0,550.0);
    glVertex2f(720.0,550.0);
	glVertex2f(720.0,400.0);
	glEnd();

	//monitor inside
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(530.0,410.0);
	glVertex2f(530.0,540.0);
    glVertex2f(710.0,540.0);
	glVertex2f(710.0,410.0);
	glEnd();
	if(h>30)
		draw(570, 540, 16, 100);
	char *st="HELLO WORLD";

	int v=0;

	//keyboard
	drawKeyboard();
	if(h>30)
		draw(550, 375, 12, 120);

	//triangle under monitor
	glBegin(GL_POLYGON);
	glVertex2f(625.0,400.0);
	glVertex2f(600.0,390.0);
    	glVertex2f(650.0,390.0);
	glEnd();

	//chair
	drawChair();

	//mouse
	drawMouse();
	if(h>30)
		draw(840, 375, 8, 21);

	//window and curtains with sun
	drawWindowPart();

	//sun
	drawSun();

	//Cat
	glPushMatrix();
	glTranslatef(-h/3, 0.0,0.0);
	cat();
	glPopMatrix();

	//monitor saying
	if(h == 700)
	{
		drawConversationCloud(710, 545, 1);
		glColor3f(0.0,0.0,0.0);
		drawText(820,555, "Its so hot", 2);
		drawText(825, 530, "outside.", 2);
	}
	//mouse saying
	if(h == 740)
	{
		drawConversationCloud(830, 420, 1);
		glColor3f(0.0,0.0,0.0);
		drawText(920,435, "The condition", 2);
		drawText(935, 410, "outside is", 2);
		drawText(945, 385, "pathetic.", 2);
	}
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
	if(h==25 || h==700 || h==740)
		for(int i=0; i<40000; i++)
			for(int j=0; j<20000; j++);
	}
	display3();
}
void display3()
{
	glLoadIdentity();
	gluOrtho2D(0,1300,0,700);
	float i;
	int j=0;
	for(i=0; i<2000; i=i+0.5, j=(j+1)%400)
	{

		glClear(GL_COLOR_BUFFER_BIT);
		//background
		glColor3f(1.0,1.0,1.0);
		glBegin(GL_POLYGON);
		glVertex2f(0.0,0.0);
		glVertex2f(1300.0,0.0);
		glVertex2f(1300.0, 700.0);
		glVertex2f(0.0,700.0);
		glEnd();

		//road
		makeRoad();

		//grass
		glColor3f(0.47,1.0,0.3);
		glBegin(GL_POLYGON);
		glVertex2f(0.0,120.0);
		glVertex2f(1300.0,120.0);
		glVertex2f(1300.0, 0.0);
		glVertex2f(0.0,0.0);
		glEnd();

		//ground for buildings
		glColor3f(0.95,0.9,0.85);
		glBegin(GL_POLYGON);
		glVertex2f(0.0,260.0);
		glVertex2f(1300.0,260.0);
		glVertex2f(1300.0, 400.0);
		glVertex2f(0.0,400.0);
		glEnd();

		//blue sky
		glColor3f(0.9,0.96,1.0);
		glBegin(GL_POLYGON);
		glVertex2f(0.0,700.0);
		glVertex2f(1300.0,700.0);
		glVertex2f(1300.0, 400.0);
		glVertex2f(0.0,400.0);
		glEnd();

		//buildings
		makeBuildings();

		//sun
		if(j<200)
			//glColor3f(1.0,1.0,0.3);
			glColor3f(1.0, 0.86, 0.3);
			//glColor3f(1.1, 1.0, 0.0);
		else
			glColor3f(1.0,0.8,0.0);
		drawCircle(1130, 650, 40);

		//clouds
		glPushMatrix();
		glTranslatef((0.0-i/16),0.0,0.0);
		drawSingleCloud(770, 650);
		drawSingleCloud(400, 600);
		drawSingleCloud(150, 650);
		glPopMatrix();

		//car
		float s1,s2;
		if(i<350)
		{
			glPushMatrix();
			glTranslatef((0.0+i),0.0,0.0);
			glColor3f(0.8,0.0,0.0);
			makeCar();
			glPopMatrix();
			s1=350.0;
		}
		else if(i>=350 && i<=600)
		{
			glPushMatrix();
			s1+=0.25;
			glTranslatef((0.0+s1),0.0,0.0);
			glColor3f(0.8,0.0,0.0);
			makeCar();
			glPopMatrix();
			s2=s1;
		}
		else
		{
			glPushMatrix();
			s2+=0.5;
			glTranslatef((0.0+s2),0.0,0.0);
			glColor3f(0.8,0.0,0.0);
			makeCar();
			glPopMatrix();
		}

		//car smoke
		//glColor3f(0.0,0.0,0.0);
		if(i>=445 && i<=1000)
		{
			glPushMatrix();
			glTranslatef((0.0+i/16),0.0,0.0);
			glColor3f(i/2000.0, i/2000.0,i/2000.0);
			makeCarSmoke();
			glPopMatrix();
		}

		glFlush();

		glutSwapBuffers();

	}
	display4();
}
void display4()
{
	int a1,a2,a3,k=0;
	glLoadIdentity();
	gluOrtho2D(0,1300,0,700);
	glClear(GL_COLOR_BUFFER_BIT);
	for(int i=0; i<3800; i++,k=(k+1)%400)
	{
		//background
		glColor3f(0.7,0.7,0.7);
		glBegin(GL_POLYGON);
		glVertex2f(0.0,0.0);
		glVertex2f(1300.0,0.0);
		glVertex2f(1300.0, 700.0);
		glVertex2f(0.0,700.0);
		glEnd();
		//table
		drawTable4();

		//CPU
		drawCPU4();
		draw(80,530,32,180);

		//dustbin
		drawDustbin();

		//books and its container
		drawBooksPart();

		//paper
		glPushMatrix();
		a2=650/2;
		if(i>650 && i<=2100)
		{
			glTranslatef(0,0+a2-i/8,0);
			a3=a2-i/8;
			drawPaper();
		}
		else if(i>2100)
		{
			glTranslatef(0,0+a3,0);
			drawPaper();
		}
		//drawPaper();
		glPopMatrix();

		//cat
		glPushMatrix();
		glTranslatef(80,0,0);
		if(i<=1300)
		{
			glTranslatef(0.0-i/6, 0,0);
			a1=i;
		}
		else
		{
			glTranslatef(0.0-a1/6,0,0);
		}
		cat();
		glPopMatrix();

		//cat sweat
		if(i>1300 && i<3200)
		{
			glPushMatrix();
			glTranslatef(0,50,0);
			drawCatSweat(k);
			glPopMatrix();
		}

		//CPU talks
		if(i == 3300)
		{
			drawConversationCloud(300,550,1);
			glColor3f(0.0,0.0,0.0);
			drawText(360,560,"  Look how badly",2);
			drawText(370,540,"   this cat is", 2);
			drawText(385,520,"sweating.",2);

		}
		if(i == 3400)
		{
			drawConversationCloud(300,550,1);
			glColor3f(0.0,0.0,0.0);
			drawText(360,560,"Few years back, we",2);
			drawText(342,540,"used to have fine weather", 2);
			drawText(360,520,"during this month.",2);

		}
		if(i == 3500)
		{
			drawConversationCloud(300,550,1);
			glColor3f(0.0,0.0,0.0);
			drawText(360,560,"  These are the",2);
			drawText(370,540,"   results of", 2);
			drawText(370,520,"global warming.",2);

		}
		if(i == 3600)
		{
			drawConversationCloud(300,550,1);
			glColor3f(0.0,0.0,0.0);
			drawText(370,560,"But things are",2);
			drawText(360,540,"totally opposite in", 2);
			drawText(360,520,"case of technology.",2);

		}
		if(i == 3700)
		{
			drawConversationCloud(300,550,1);
			glColor3f(0.0,0.0,0.0);
			drawText(350,560,"Nowadays, people can",2);
			drawText(360,540,"even control objects", 2);
			drawText(360,520,"   with their brain.",2);

		}
		glFlush();
		glutSwapBuffers();
		if(i==3300 || i==3400 || i==3500 || i==3600 || i==3700)
		{
			for(int x=0; x<20000; x++)
				for(int y=0; y<60000; y++);
		}
	}
	display5();
}

void display5()
{
	glLoadIdentity();
	gluOrtho2D(0,1300,0,700);
	int j,w;

	for(int q=0;q<2500;q++,j=(j+1)%400,w=(w+1)%200)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		//background
		glColor3f((96/255.0),(147/255.0),(172/255.0));
		glBegin(GL_POLYGON);
		glVertex2f(0,0);
		glVertex2f(0,700);
		glVertex2f(1300,700);
		glVertex2f(1300,0);
		glEnd();

		//garbage
		drawGarbage(q);

		//ground
		glColor3f(0.65,0.43,0.23);
		glBegin(GL_POLYGON);
		glVertex2f(800,700);
		glVertex2f(800,150);
		glVertex2f(1300,150);
		glVertex2f(1300,700);
		glEnd();
		glColor3f(0.65,0.43,0.23);
		glBegin(GL_POLYGON);
		glVertex2f(0,150);
		glVertex2f(0,200);
		glVertex2f(800,200);
		glVertex2f(800,150);
		glEnd();
		glLineWidth(1.5);
		glColor3f(0,0,0);
		glBegin(GL_LINE_LOOP);
		glVertex2f(10,190);
		glVertex2f(10,240);
		glVertex2f(790,240);
		glVertex2f(790,190);
		glEnd();

		glBegin(GL_LINES);
		for(int s=20;s<=780;s=s+10)
		{
			glVertex2f(s,190);
			glVertex2f(s,240);
		}
		glEnd();

		glBegin(GL_LINE_LOOP);
		glVertex2f(810,240);
		glVertex2f(810,660);
		glVertex2f(760,690);
		glVertex2f(760,270);
		glEnd();

		glBegin(GL_LINES);
		for(s=250;s<=650;s=s+10)
		{
			glVertex2f(760,s+30);
			glVertex2f(810,s);
		}
		glEnd();


		//factories
		glColor3f(0.545,0.545,0.478);
		singleBuilding(150,820,430);
		glColor3f(0.545,0.545,0.478);
		singleBuilding(150,1000,430);

		//chimney 1 and 2
		makeChimneys();

		//smoke
		glPushMatrix();
		glTranslatef(0+j/6,0,0);
		glColor3f(0.25+(j/800.0),0.25+(j/800.0),0.25+(j/800.0));
		makeSmoke(820,640);
		makeSmoke(1000,640);
		glPopMatrix();

		//road
		glColor3f(0.60,0.60,0.60);
		glBegin(GL_POLYGON);
		glVertex2f(0,0);
		glVertex2f(0,150);
		glVertex2f(1300,150);
		glVertex2f(1300,0);
		glEnd();

		for(int k=0;k<1200;k=k+100)
		{
			glColor3f(1,1,1);
			glBegin(GL_POLYGON);
			glVertex2f(80+k,90);
			glVertex2f(80+k,100);
			glVertex2f(130+k,100);
			glVertex2f(130+k,90);
			glEnd();
		}
		if(q>=400 && q<=1500)
		{

			drawThinkingCloud(750,410,2);
			glColor3f(0.0,0.0,0.0);
			drawText(825,405, "Move...", 2);
			glPushMatrix();
			glTranslatef(0+(q/4.0),-50,0);
			glColor3f(0.8,0.5,0.6);
			makeCar();
			glPopMatrix();

			//makeBrainWaves
			makeBrainWaves(w);

		}
		else if(q>1500)
		{
			if(q<2000)
			{
				drawThinkingCloud(1040,410,1);
				glColor3f(0.0,0.0,0.0);
				drawText(1120,405, "Stop!", 2);
			}
			glPushMatrix();
			glTranslatef(375,-50,0);
			glColor3f(0.8,0.5,0.6);
			makeCar();
			glPopMatrix();
		}
		else
		{
			drawConversationCloud(680,410,2);
			glColor3f(0.0,0.0,0.0);
			drawText(770,425, "Look how I can", 2);
			drawText(770, 405, "drive the car", 2);
			drawText(770, 385, "with my brain.", 2);

			glPushMatrix();
			glTranslatef(0,-50,0);
			glColor3f(0.8,0.5,0.6);
			makeCar();
			glPopMatrix();
		}

		//man
		drawMan2();
		//waves

		glPushMatrix();
		glTranslatef(0+(q/20.0),0,0);
		glColor3f(0.25,0.42,0.88);
		makeManyWaves();
		glPopMatrix();

		glFlush();
		glutSwapBuffers();
	}
	display6();

}
void display6()
{
	glLoadIdentity();
	gluOrtho2D(0,1300,0,700);
	glClear(GL_COLOR_BUFFER_BIT);
	for(int i=0; i<1000; i++)
	{
		//background
		glColor3f(0.7,0.7,0.7);
		glBegin(GL_POLYGON);
		glVertex2f(0.0,0.0);
		glVertex2f(1300.0,0.0);
		glVertex2f(1300.0, 700.0);
		glVertex2f(0.0,700.0);
		glEnd();
		//table
		drawTable4();

		//CPU
		drawCPU4();
		draw(80,530,32,180);

		//dustbin
		drawDustbin();

		//books and its container
		drawBooksPart();

		//paper
		drawPaper();

		//cat
		glPushMatrix();
		glTranslatef(0-550,250,0);
		cat();
		glPopMatrix();

		//CPU talks
		if(i == 300)
		{
			drawConversationCloud(300,550,1);
			glColor3f(0.0,0.0,0.0);
			drawText(360,560,"Seems like the rate",2);
			drawText(360,540,"at which technology", 2);
			drawText(360,520,"  is developing is",2);

		}
		if(i == 350)
		{
			drawConversationCloud(300,550,1);
			glColor3f(0.0,0.0,0.0);
			drawText(360,560," same as the rate",2);
			drawText(342,540,"   at which nature", 2);
			drawText(340,520,"        is degrading.",2);

		}
		if(i == 400)
		{
			drawConversationCloud(300,550,1);
			glColor3f(0.0,0.0,0.0);
			drawText(360,560,"  Let's contact our",2);
			drawText(360,540,"laptop friend to see", 2);
			drawText(360,520,"  how he's doing.",2);

		}

		glFlush();
		glutSwapBuffers();
		if(i==300 || i==350 || i==400)
		{
			for(int x=0; x<20000; x++)
				for(int y=0; y<60000; y++);
		}
	}
	display7();
}void display7()
{
	int a;
	glLoadIdentity();
	gluOrtho2D(0,1300,0,700);
	glClear(GL_COLOR_BUFFER_BIT);
	for(int i=0; i<8000; i++)
	{
		//background
		glColor3f(1.0,1.0,1.0);
		glBegin(GL_POLYGON);
		glVertex2f(0.0,0.0);
		glVertex2f(1300.0,0.0);
		glVertex2f(1300.0, 700.0);
		glVertex2f(0.0,700.0);
		glEnd();

		//grass
		glColor3f(0.0,1.0,0.0);
		glBegin(GL_POLYGON);
		glVertex2f(0.0,0.0);
		glVertex2f(1300.0,0.0);
		glVertex2f(1300.0, 500.0);
		glVertex2f(0.0,500.0);
		glEnd();

		//road
		makeRoad1();

		//sky
		glColor3f(0.9,0.97,1.0);
		glBegin(GL_POLYGON);
		glVertex2f(0.0,500.0);
		glVertex2f(1300.0,500.0);
		glVertex2f(1300.0,700.0);
		glVertex2f(0.0,700.0);
		glEnd();

		//buildings
		glColor3f(1.0,0.7,0.2);
		singleBuilding(200, 1100, 320);
		glColor3f(1.0,0.2,0.2);
		singleBuilding(250, 900, 320);

		glPushMatrix();
		glTranslatef(-i/16-300,i/64,0);
		//birds
		makeBirds();
		glPopMatrix();

		//chair
		makeChair();

		//laptop
		makeLaptop();

		//man
		glPushMatrix();
		if(i<920)
		{
			glTranslatef(-430,200-i/4,0);
			a=200-i/4;
			drawMan2();
		}
		else if(i<1200)
		{
			glTranslatef(-430,-30,0);
			drawMan2();
		}
		glPopMatrix();

		//garbage
		if(i>920)
		{
			glPushMatrix();
			if(i<1000)
				glTranslatef(0,1000-i,0);
			glColor3f(0.7,0.7,0.7);
			drawPentagon(490,150,20);
			drawPentagon(510,160,20);
			DrawEllipse(20,10,475,165);
			DrawEllipse(20,15,490,200);
			drawPentagon(560,170,15);
			glPopMatrix();
		}

		//man leaving
		if(i>1200)
		{
			glPushMatrix();
			glTranslatef(-430,a+250-i/4,0);
			drawMan2();
			glPopMatrix();
		}

		//laptop text
		glColor3f(0.0,0.0,0.0);
		drawText(260,420,"Internet",1);
		glBegin(GL_LINES);
		glVertex2f(240,415);
		glVertex2f(320,415);
		glEnd();
		if(i<7000)
		{
			drawText(260,400,"Friend is",1);
			drawText(262,385,"calling...",1);
		}
		else if(i<7400)
		{
			drawText(260,390,"On call...",1);
			draw(250,440,10,60);
		}
		else
		{
			drawText(257,405,"Breaking",1);
			drawText(265,395,"News:",1);
			drawText(253,385,"\"Landside\"",1);
			draw(250,440,10,60);
		}

		//laptop talks
		if(i == 7100)
		{
			drawConversationCloud(-27,480,0);
			glColor3f(0.0,0.0,0.0);
			drawText(30,480,"Hey guys!",2);
			drawText(30,455,"How you're doing?",2);
		}
		else if(i == 7150)
		{
			drawConversationCloud(-27,480,0);
			glColor3f(0.0,0.0,0.0);
			drawText(30,480,"You're saying how",2);
			drawText(30,460,"nature is degrading.",2);
		}
		if(i == 7200)
		{
			drawConversationCloud(305,480,1);
			glColor3f(0.0,0.0,0.0);
			drawText(370,490,"I'm doing fine. But",2);
			drawText(390,470,"even I am",2);
			drawText(370,450,"concerned about",2);
		}
		else if(i == 7250)
		{
			drawConversationCloud(305,480,1);
			glColor3f(0.0,0.0,0.0);
			drawText(370,490,"the disconcern of",2);
			drawText(378,470,"the humans for",2);
			drawText(390,450,"the nature.",2);
		}
		else if(i == 7300)
		{
			drawConversationCloud(305,480,1);
			glColor3f(0.0,0.0,0.0);
			drawText(378,490,"Just heard the",2);
			drawText(378,470,"news through the",2);
			drawText(370,450,"Internet about how",2);
		}
		else if(i == 7350)
		{
			drawConversationCloud(305,480,1);
			glColor3f(0.0,0.0,0.0);
			drawText(360,490,"a landslide blocked",2);
			drawText(368,470,"water supply for",2);
			drawText(378,450,"a whole town.",2);
		}

		glFlush();
		glutSwapBuffers();

		if(i==7100 || i==7150 || i==7200 || i==7250 || i==7300 || i==7350 || i==7450)
		{
			for(int x=0; x<20000; x++)
				for(int y=0; y<60000; y++);
		}

	}
	display8();
}
void display8()
{
	glLoadIdentity();
	gluOrtho2D(0,1300,0,700);
	int j,p=0;
	for(int i=0;i<1550;i++,j=(j+1)%400)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(0,0.75,1.0);

		//sea
		makeSea();

		//blue sky
		makeSky();

		//mountains
		makeMountains(i);

		//sun
		if(j<200)
			glColor3f(1.0,0.86,0.3);
		else
			glColor3f(1.0,0.8,0.0);
		drawCircle(350,650,40);

		//clouds
		if(i<400)
		{
			glPushMatrix();
			glTranslatef((0.0-(i/2.0)),0.0,0.0);
			drawSingleCloud(1100,650);
			drawSingleCloud(800,620);
			glPopMatrix();

			glColor3f(0.9,0.94,1.0);

			//rain cloud1
			makeRain1(i);
			if(i>200)
			{
				glColor3f(0.9,0.94,1.0);
				makeRain2(p);
				p++;
			}

		}
		else if(i>=400)
		{
			drawSingleCloud(850,650);
			drawSingleCloud(550,620);//landslide
			makeNewMountains();
			if(i>=1499)//draught
			{
				glColor3f(0.803,0.745,0.44);
				glBegin(GL_POLYGON);
				glVertex2f(805,0);
				glVertex2f(930,450);
				glVertex2f(1300,450);
				glVertex2f(1300,0);
				glEnd();
			}
			//pieces of land
			glColor3f(0.38,0.24,0.13);
			glPushMatrix();
			glTranslatef((0.0+i/9.0),(0.0-i/4.0),0.0);
			makePieces1();
			glPopMatrix();
			glPushMatrix();
			glTranslatef((0.0+i/7.0),(0.0-i/5.0),0.0);
			makePieces2();
			glPopMatrix();
			glPushMatrix();
			glTranslatef((0.0-i/28.0),(0.0-i/15.0),0.0);
			makePieces3();
			glPopMatrix();
			glPushMatrix();
			glTranslatef((0.0-i/20.0),(0.0-i/7.0),0.0);
			makePieces4();
			glPopMatrix();


		}
		glFlush();
		glutSwapBuffers();
		if(i==1510)
		{
			for(int x=0; x<20000; x++)
				for(int y=0; y<40000; y++);
		}
	}
	display9();

}
void display9()
{
	char *st1="\"It is good to develop the Technology.";
	char *st2="But we must not forget our Dear Earth..\"";
	char t1[50];
	char t2[50];
	int j=0,k=0;
	glLoadIdentity();
	gluOrtho2D(0,1300,0,700);
	glClear(GL_COLOR_BUFFER_BIT);
	for(int i=0; i<2900; i++)
	{
		glColor3f(1.0,0.3,0.3);
		glBegin(GL_POLYGON);
		glVertex2f(0.0,0.0);
		glVertex2f(1300.0,0.0);
		glVertex2f(1300.0, 700.0);
		glVertex2f(0.0,700.0);
		glEnd();

		glColor3f(1.0,1.0,0.0);

		//"moral of the story" text
		drawText(550, 440, "MORAL OF THE STORY", 2);

		glColor3f(1.0,1.0,1.0);
		//moral

		if(i>=0 && i<=38)
		{
			memcpy(t1,st1,j);
			t1[j++]='\0';
		}
		else if(i<=79)
		{
			memcpy(t2,st2,k);
			t2[k++]='\0';
		}
		drawText(450, 390, t1, 2);
		if(i>38)
			drawText(450, 360, t2, 2);

		//factory
		if(i>80)
		{
			glPushMatrix();
			if(i<780)
				glTranslatef(-700,0-780+i,0);
			else
				glTranslatef(-700,0,0);
			glColor3f(0.545,0.545,0.478);
			singleBuilding(150,820,430);
			glColor3f(0.545,0.545,0.478);
			glBegin(GL_POLYGON);
			glVertex2f(825,580);
			glVertex2f(825,640);
			glVertex2f(845,650);
			glVertex2f(845,580);
			glEnd();
			glColor3f(0.25+(170/800.0),0.25+(170/800.0),0.25+(170/800.0));
			makeSmoke(820,640);
			glPopMatrix();
		}

		//tree
		if(i>790)
		{
			glPushMatrix();
			if(i<1490)
				glTranslatef(-1490+i,0,0);
			makeTree(400,190,440,100);
			glPopMatrix();
		}

		//laptop
		if(i>1500)
		{
			glPushMatrix();
			if(i<1800)
				glTranslatef(-100,-200-1800+i,0);
			else
				glTranslatef(-100,-200,0);
			makeLaptop();
			glLineWidth(2.0);
			glColor3f(1.0,0.3,0.3);
			glBegin(GL_LINES);
			glVertex2f(245,365);
			glVertex2f(315,365);
			glEnd();
			glPopMatrix();
		}

		//earth
		if(i>1900)
		{
			glPushMatrix();
			if(i<2600)
				glTranslatef(0,-2600+i,0);
			makeEarth();
			glPopMatrix();
		}

		//thank you
		glColor3f(1.0,1.0,1.0);
		if(i>2880)
			drawText(800, 200, "THANK YOU  ^_^", 2);

		glFlush();
		glutSwapBuffers();
		if(i>=0 && i<=79)
		{
			for(int x=0; x<4000; x++)
				for(int y=0; y<6000; y++);
		}
	}
}


void myKeyboard(unsigned char key, int xmouse, int ymouse)
{
	switch(key)
	{
	case '0':
		display0();
		break;
	case '1':
		display1();
		break;
	case '2':
		display2();
		break;
	case '3':
		display3();
		break;
	case '4':
		display4();
		break;
	case '5':
		display5();
		break;
	case '6':
		display6();
		break;
	case '7':
		display7();
		break;
	case '8':
		display8();
		break;
	case '9':
		display9();
		break;
	case 'c':
		display1();
		break;
	case 'C':
		display1();
		break;
	}
}
void init()
{
	glClearColor(0.0,1.0,1.0,0.5);
	glColor3f(1.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,1300,0,700);

}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(1300,700);
	glutInitWindowPosition(0,0);
	glutCreateWindow("COMPUTERS' DAY");
	glutKeyboardFunc(myKeyboard);
	glutDisplayFunc(display0);
	init();
	glutMainLoop();
}
