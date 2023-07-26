#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <dos.h>
// Define boundaryfill algorithm
void boundaryfill(int x, int y, int fill, int boundary) {
 int current;
 current = getpixel(x, y); // get the current color of seed pixel
 // if current color is not boundary color as well as filled color
 if ((current != boundary) && (current != fill)) {
 putpixel(x, y, fill); // put the color
 delay(5);
 // use 8-connected method to fill the neighbouring pixel
 boundaryfill(x + 1, y, fill, boundary);
 boundaryfill(x - 1, y, fill, boundary);
 boundaryfill(x, y + 1, fill, boundary);
 boundaryfill(x, y - 1, fill, boundary);
 boundaryfill(x - 1, y - 1, fill, boundary);
 boundaryfill(x - 1, y + 1, fill, boundary);
 boundaryfill(x + 1, y - 1, fill, boundary);
 boundaryfill(x + 1, y + 1, fill, boundary);
 }
}
// Driver Program
void main() {
 int x1, y1, x2, y2;
 int gd = DETECT, gm;
 clrscr();
 // initialize graphics function
 initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
 printf("Boundary Fill Algorithm: 8-Connected Method.\n");
 // initialize the coordinate of rectangle to be filled
 x1 = 250, y1 = 200, x2 = 310, y2 = 260;
 setcolor(10);
 rectangle(x1, y1, x2, y2); // Draw rectangle
 boundaryfill(280, 250, 12, 10); // Call boundaryfill function
 delay(5000);
 closegraph();
}