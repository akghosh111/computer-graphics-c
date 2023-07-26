#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

void draw_object(float x1,float y1,float x2,float y2,float x3,float y3)
{
 
 setcolor(RED);
 
 line(x1,y1,x2,y2);
 line(x2,y2,x3,y3);
 line(x3,y3,x1,y1);
 outtextxy(x2, y2 + 10 ,"Original Triangle");
}

void rotation_2d(float x1,float y1,float x2,float y2,float x3,float y3,float angle)
{
 /
 float x11,y11,x21,y21,x31,y31,a;
 
 a=angle*(3.14/180.0); //convert degree to radian
 x11=(x1*cos(a))-(y1*sin(a));
 y11=(x1*sin(a))+(y1*cos(a));
 x21=(x2*cos(a))-(y2*sin(a));
 y21=(x2*sin(a))+(y2*cos(a));
 x31=(x3*cos(a))-(y3*sin(a));
 y31=(x3*sin(a))+(y3*cos(a));
 setcolor(GREEN);
 
 line(x11,y11,x21,y21);
 line(x21,y21,x31,y31);
 line(x31,y31,x11,y11);
 outtextxy(x11 + 10, y11 + 70,"Rotated Triangle");
}

void main()
{
 float x1, x2, x3, y1, y2, y3, angle;
 int gd=DETECT,gm;
 clrscr();
 
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 
 x1 = 300, y1 = 40, x2 = 300, y2 = 150, x3 = 410, y3 = 150;

 
 angle = 45;
 draw_object(x1, y1, x2, y2, x3, y3);
 
 rotation_2d(x1, y1, x2, y2, x3, y3, angle);
 getch();
 closegraph();

}