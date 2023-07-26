#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
// Function to draw a line using DDA algorithm
void drawLineDDA(int x1, int y1, int x2, int y2, int color) {
 // Calculate the change in x and y coordinates
 int dx = x2 - x1;
 int dy = y2 - y1;
 // Calculate the number of steps needed to complete the line
 int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
 // Calculate the increment in x and y coordinates
 float xi = dx / (float) steps;
 float yi = dy / (float) steps;
 // Initialize the starting point of the line

 float x = x1;
 float y = y1;
 // Draw the pixels of the line
 int i;
 for (i = 0; i <= steps; i++) {
// Plot the current pixel on the screen
putpixel(x, y, color);
 // Increment the x and y coordinates
 x += xi;
 y += yi;
 }
}
// Driver code
int main() {
 // Initialize the graphics mode
 int gd = DETECT, gm;
 initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
 // Draw a line using DDA algorithm
 drawLineDDA(150, 150, 350, 250, WHITE);
 delay(5000);
 closegraph();
 return 0;
}