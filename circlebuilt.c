#include <graphics.h>
int main() {
int gd = DETECT, gm;
initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
// Set color to blue
setcolor(WHITE);
// Draw a circle of radius 50 at (100, 100)
circle(100, 100, 50);
delay(5000);
closegraph();
return 0;
}
