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
// Driver code
int main() {
 int color = WHITE;
 // Initialize the graphics mode
 int gd = DETECT, gm;
 initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
 // Draw the line
 drawLine(100, 100, 200, 200, color);

 // Wait for 5 sec before closing the window
 delay(5000);
 closegraph();
 return 0;
}
