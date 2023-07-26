#include <graphics.h>
int main() {
 // Initialize graphics mode
 int gd = DETECT, gm;
 initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
 // Draw rectangle with top-left corner at (100, 100)
 // and bottom-right corner at (300, 200)
 rectangle(100, 100, 300, 200);
 // Add a delay of 5 seconds
 delay(5000);
 // Close graphics mode

 closegraph();
 return 0;
}