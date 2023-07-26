#include <graphics.h>
// Function to draw a line using Bresenham's algorithm
void drawLine(int x1, int y1, int x2, int y2, int color) {
 // Calculate the change in x and y coordinates
 int dx = abs(x2 - x1);
 int dy = abs(y2 - y1);
 // Initialize the decision parameter
 int pk = 2 * dy - dx;
 // Initialize the starting point of the line
 int x = x1;
 int y = y1;
 // Draw the first pixel
 putpixel(x, y, color);
 // Draw the remaining pixels
 while (x < x2) {
 x++;
 // If the decision parameter is less than zero,
 // only increment it and continue to the next point
 if (pk < 0) {
 pk += 2 * dy;
 }
 // Otherwise, increment the y-coordinate and update
 // the decision parameter before plotting the point
 else {
 y++;
 pk += 2 * dy - 2 * dx;
 }
 // Plot the current point on the screen
 putpixel(x, y, color);
 }
}
// Function to translate a line by (tx, ty) units
void translateLine(int x1, int y1, int x2, int y2, int tx, int ty, int color) {
 // Translate the starting and ending points of the line
 x1 += tx;
 y1 += ty;
 x2 += tx;
 y2 += ty;
 // Draw the translated line
 drawLine(x1, y1, x2, y2, color);
 setcolor(color);
 outtextxy(x2 + 10, y2, "Translated Line");
}
// Driver code
int main() {
 int x1, y1, x2, y2, tx, ty, color;
 int gd = DETECT, gm;
 initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
 // Draw the original line
 x1 = 100, y1 = 100;
 x2 = 200, y2 = 200;
 color = WHITE;
 drawLine(x1, y1, x2, y2, color);
 outtextxy(x1 + 10, y1, "Original Line");
 // Translate the line by 15 units in both axes
 tx = 15, ty = 15;
 color = RED;
 translateLine(x1, y1, x2, y2, tx, ty, color);
 // Wait for input before closing the window
 delay(5000);
 closegraph();
 return 0;
}