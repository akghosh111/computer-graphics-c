#include <graphics.h> // include graphics library
#include <stdio.h> // include standard input/output library
int main() {
 int x, y, rx, ry;
 int gd = DETECT, gm; // graphics driver and mode
 initgraph(&gd, &gm, "C:\\TURBOC3\\BGI"); // initialize graphics window
 // draw an ellipse
 x = getmaxx() / 2; // x-coordinate of center
 y = getmaxy() / 2; // y-coordinate of center
 rx = 150; // horizontal radius
 ry = 100; // vertical radius
 ellipse(x, y, 0, 360, rx, ry); // draw ellipse
 delay(5000); // wait for 5000 milliseconds
 closegraph(); // close graphics window
 return 0;
}