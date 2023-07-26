#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
//Define floodfill algorithm
void flodfill( int x,int y,int newcol,int oldcol)
{
 int current;
 current=getpixel(x,y); //get the current color of seed pixel
 //if current color is old color,then recolor
 if(current==oldcol)
 {
 putpixel(x,y,newcol); // color with new color
 delay(5);
 //use 4-connected method to fill the neighoubring pixel
 flodfill(x+1,y,newcol,oldcol);
 flodfill(x-1,y,newcol,oldcol);
 flodfill(x,y+1,newcol,oldcol);
 flodfill(x,y-1,newcol,oldcol);
 }
}//Function closed
//Driver Program
void main()
{
 int x,y,radius,cc;
 int gd=DETECT,gm;
 clrscr();
 //initialize graphics function
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 printf("Flood Fill Algorithm:4-Connected Method.\n");
 //Initialize centre and radius of circle
 x=200,y=150,radius=35;
 circle(x,y,radius);//Draw circle
 cc=getpixel(x,y); //get the color of centre..seed pixel
 flodfill(x,y,GREEN,cc); //call floodfill function
 delay(5000);
 closegraph();
}