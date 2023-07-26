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
// Calculate the region code for a point
int calculateCode(int x, int y, int xmin, int ymin, int xmax, int ymax) {
 int code = 0;
 if (x < xmin) {
 code |= 1;
 } else if (x > xmax) {
 code |= 2;
 }
 if (y < ymin) {
 code |= 4;
 } else if (y > ymax) {
Page17
 code |= 8;
 }
 return code;
}
// Clip the line against an edge of the clipping window
void clipAgainstEdge(int *x, int *y, float *m, int left, int bottom, int right, int top,
int code) {
 if (code & 1) { // Clip against left edge
 *y += (int) (*m * (left - *x));
 *x = left;
 } else if (code & 2) { // Clip against right edge
 *y += (int) (*m * (right - *x));
 *x = right;
 } else if (code & 4) { // Clip against bottom edge
 *x += (int) (1 / *m * (bottom - *y));
 *y = bottom;
 } else if (code & 8) { // Clip against top edge
 *x += (int) (1 / *m * (top - *y));
 *y = top;
 }
}
// Function to clip a line using Cohen Sutherland algorithm
void clipLineCohenSutherland(int x1, int y1, int x2, int y2, int left, int bottom, int
right, int top, int color) {
 // Calculate the region codes for the endpoints of the line
 int code1 = calculateCode(x1, y1, left, bottom, right, top);
 int code2 = calculateCode(x2, y2, left, bottom, right, top);
 int code;

 // Initialize the slope and intercept of the line
 float m = (float) (y2 - y1) / (x2 - x1);
 float b = y1 - m * x1;
 // Keep clipping until the line is either completely inside or outside the clipping window
 while ((code1 | code2) != 0) {
 // If both endpoints are in the same region, the line is completely outside the
clipping window
 if ((code1 & code2) != 0) {
 return;
 }
 // Calculate which endpoint to clip against an edge of the clipping window
 code = code1 != 0 ? code1 : code2;
 // Clip the endpoint against the edge of the clipping window
 clipAgainstEdge(&x1, &y1, &m, left, bottom, right, top, code);
 clipAgainstEdge(&x2, &y2, &m, left, bottom, right, top, code);
 // Recalculate the region codes for the endpoints of the clipped line
 code1 = calculateCode(x1, y1, left, bottom, right, top);
 code2 = calculateCode(x2, y2, left, bottom, right, top);
Page18
 }
 // Draw the clipped line
 drawLineDDA(x1, y1, x2, y2, color);
}
// Main function to test the code
int main() {
 int left, right, bottom, top;
 int x1, y1, x2, y2;
 // Initialize the graphics mode
 int gd = DETECT, gm;
 initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
 // Set the clipping window
 left = 100;
 bottom = 100;
 right = 400;
 top = 300;
 rectangle(left, bottom, right, top);
 // Draw a line inside the clipping window
 x1 = 150;
 y1 = 150;
 x2 = 350;
 y2 = 250;
 drawLineDDA(x1, y1, x2, y2, WHITE);
 // Draw a line partially outside the clipping window
 x1 = 50;
 y1 = 200;
 x2 = 450;
 y2 = 200;
 clipLineCohenSutherland(x1, y1, x2, y2, left, bottom, right, top, RED);
 // Draw a line completely outside the clipping window
 x1 = 50;
 y1 = 50;
 x2 = 450;
 y2 = 350;
 clipLineCohenSutherland(x1, y1, x2, y2, left, bottom, right, top, GREEN);
 delay(5000);
 closegraph();
 return 0;
}