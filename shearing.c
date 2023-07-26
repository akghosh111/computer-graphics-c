#include <graphics.h>
int main() {
 // Declare variables
 int gd = DETECT, gm;
 int xc = 320, yc = 240, r = 100; // center coordinates and radius of circle
 int x, y, p;
 // Initialize graphics mode
 initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
 // Draw circle
 circle(xc, yc, r);
 // Apply shear transformation
 for (y = yc - r; y <= yc + r; y++) {
 for (x = xc - r; x <= xc + r; x++) {
 p = getpixel(x, y);
 putpixel(2 * (x - xc) + xc, y, p);
 }
 }
 // Pause for 5 seconds before closing graphics mode
 delay(5000);
 closegraph();
 return 0;
}
