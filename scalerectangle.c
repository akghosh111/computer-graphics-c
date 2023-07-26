#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
// Definition for drawing object function
void draw_object(float x1, float y1, float x2, float y2, float x3, float y3, float x4,
float y4)
{
 // The original object
 setcolor(RED);
 // Draw rectangle
 line(x1, y1, x2, y2);
 line(x2, y2, x3, y3);
 line(x3, y3, x4, y4);
 line(x4, y4, x1, y1);
 outtextxy(x1, y1 + 10 ,"Original Rectangle.");
}
// Scaling function defination
void scaling_2d(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float
y4, float sx, float sy)
{
 // After Scaling
 setcolor(GREEN);
 // Translating the Rectangle for better viewability
 x1 = x1 + 50;
 x2 = x2 + 50;
 x3 = x3 + 50;
 x4 = x4 + 50;
 // Draw rectangle after Scaling
 line(x1*sx, y1*sy, x2*sx, y2*sy);
 line(x2*sx, y2*sy, x3*sx, y3*sy);
 line(x3*sx, y3*sy, x4*sx, y4*sy);
 line(x4*sx, y4*sy, x1*sx, y1*sy);
 outtextxy(x4 * sx + 10, y1 * sy + 10, "Rectangle after Scaling.");
}
// Driver Program
void main()
{
 float x1, x2, x3, y1, y2, y3, x4, y4, sx, sy;
Page10
 int gd = DETECT, gm;
 clrscr();
 // Initialize graphics function
 initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
 // Initializing variables
 // Coords of the rectangle
 x1 = 100, y1 = 70, x2 = 200, y2 = 70, x3 = 200, y3 = 10, x4 = 100, y4 = 10;
 // Scaling Factor
 sx = 2, sy = 2;
 // draw original object
 draw_object(x1, y1, x2, y2, x3, y3, x4, y4);
 // Call 2D-scaling function
 scaling_2d(x1, y1, x2, y2, x3, y3, x4, y4, sx, sy);
 getch();
 closegraph();
}
