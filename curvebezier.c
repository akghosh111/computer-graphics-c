#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <stdio.h>
void main()
{
 // Declare variables
 int x[4], y[4], i, gr = DETECT, gm;
 double put_x, put_y, t;
 // Initialize graphics
 initgraph(&gr, &gm, "C:\\TURBOC3\\BGI");
 // Get control points from user
 printf("\n****** Bezier Curve ***********");
 printf("\n Please enter x and y coordinates ");
 for (i = 0; i < 4; i++) {
 scanf("%d%d", &x[i], &y[i]);
 putpixel(x[i], y[i], 3); // Plot control points

 }
 // Draw Bezier curve
 for (t = 0.0; t <= 1.0; t += 0.001) {
 // Formula to draw curve
 put_x = pow(1 - t, 3) * x[0] + 3 * t * pow(1 - t, 2) * x[1] + 3 * t * t * (1 - t) *
x[2] + pow(t, 3) * x[3];
 put_y = pow(1 - t, 3) * y[0] + 3 * t * pow(1 - t, 2) * y[1] + 3 * t * t * (1 - t) *
y[2] + pow(t, 3) * y[3];
 // Check if point is within screen boundaries
 if (put_x >= 0 && put_x < getmaxx() && put_y >= 0 && put_y < getmaxy()) {
 putpixel(put_x, put_y, WHITE); // Plot pixel
 }
 }
 // Wait for user input
 delay(5000);
 // Close graphics
 closegraph();
}
