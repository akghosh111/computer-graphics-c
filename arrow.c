#include<stdio.h> 
#include<conio.h> 
#include<graphics.h> 
void main() 
{ 
    int gm,gd=DETECT; 
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI"); 
    outtextxy(180,30,"C Program to Draw Arrow using Graphics"); 
    setcolor(RED); 
 
    line(300,80,340,80); 
    line(300,100,340,100); 
    line(300,80,300,100); 
    line(340,80,340,70); 
    line(340,100,340,110); 
    line(340,70,360,90); 
    line(340,110,360,90); 
     
    getch(); 
    closegraph(); 
} 