#include <graphics.h>
int main() {
 int gd = DETECT, gm;
 initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
 // draw a pixel at position (100, 100) in white color
 putpixel(100, 100, WHITE);
 delay(5000);
 closegraph();
 return 0;
}