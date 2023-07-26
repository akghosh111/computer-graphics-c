#include <graphics.h>
int main()
{
 // Initialize graphics window
 int gd = DETECT, gm;
 initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
 // Draw lines
 line(100, 100, 200, 100);
 line(150, 50, 150, 150);
 // Close graphics window
 delay(5000);
 closegraph();
 return 0;
}