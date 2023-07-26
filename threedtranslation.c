#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
//Definitaion for drawing object function
void draw_object(int x1,int y1,int x2,int y2)
{
 //Draw The original object..3d bar
 setfillstyle(1,6);
 bar3d(x1,y1,x2,y2,30,1); //30 is the depth
}

//translation function defination
void translation_3d(x1,y1,x2,y2,tx,ty)
{
 //After Traslation:
 setfillstyle(1,6);
 bar3d(x1+tx,y1+ty,x2+tx,y2+ty,30,1); //30 is the depth
 outtextxy(x2+tx+15,y2,"After Translation.");
}
//Driver Program
void main()
{
 int x1,y1,x2,y2,tx,ty;
 int gd=DETECT,gm;
 clrscr();
 //initialize graphics function
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 //Taking input of variables
 printf("Enter the first point(Top-left)\n");
 scanf("%d %d",&x1,&y1);
 printf("Enter the second point(Bottom-Right):\n");
 scanf("%d %d",&x2,&y2);
 cleardevice();
 //draw original object
 draw_object(x1,y1,x2,y2);
 printf("Enter translation vectors...\n");
 scanf("%d %d",&tx,&ty);
 translation_3d(x1,y1,x2,y2,tx,ty); //Call 3D-translation function
 delay(5000);
 closegraph();
}