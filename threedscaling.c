#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
//Definition for drawing object function
void draw_object(int x1,int y1,int x2,int y2)
{
 //Draw The original object..3d bar
 setfillstyle(1,6);
 bar3d(x1,y1,x2,y2,30,1); //30 is the depth
}
//scaling function defination
void scaling_3d(int x1,int y1,int x2,int y2,int sx,int sy,int sz)
{
 //After scaling:
 setfillstyle(1,6);
 bar3d(x1*sx,y1*sy,x2*sx,y2*sy,30*sz,1); //30*sz is the depth
 outtextxy(x2*sx,y2*sy,"After scaling.");
}
//Driver Program
void main()
{
 int x1,y1,x2,y2,sx,sy,sz;
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
 printf("Enter Scaling factors...\n");
 scanf("%d %d %d",&sx,&sy,&sz);
 scaling_3d(x1,y1,x2,y2,sx,sy,sz); //Call 3D-scaling function
 delay(5000);
 closegraph();
}
