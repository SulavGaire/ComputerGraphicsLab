#include <iostream>
#include <graphics.h>
#include <cmath>

void RotateAboutCentroid(int x1, int y1, int x2, int y2, int x3, int y3, int angle)
{
    int x = (x1 + x2 + x3)/3, y = (y1 + y2+ y3)/3;
   

    int x1_S = x1 - x;
    int y1_S = y1 -y;
    int x2_S = x2 - x;
    int y2_S = y2 -y;
    int x3_S = x3 - x;
    int y3_S = y3 -y;

    x1 = x + (x1_S * cos(angle)) - (y1_S * sin(angle));
    y1 = y + (x1_S * sin(angle)) + (y1_S * cos(angle));

    x2 = x + (x2_S * cos(angle)) - (y2_S * sin(angle));
    y2 = y + (x2_S * sin(angle)) + (y2_S * cos(angle));

    x3 = x + (x3_S * cos(angle)) - (y3_S * sin(angle));
    y3 = y + (x3_S * sin(angle)) + (y3_S * cos(angle));

    moveto(x1, y1);
    lineto(x2, y2);
    lineto(x3, y3);
    lineto(x1, y1);

}

void plot(int x1, int y1, int x2, int y2, int x3, int y3)
{
    moveto(x1, y1);
    lineto(x2, y2);
    lineto(x3, y3);
    lineto(x1, y1);
}

int main()
{
    initwindow(600,600, "Rotation");
    int x1 = 100, y1 = 100, x2 = 100, y2 = 200, x3 = 200, y3 = 200;
    plot(x1, y1, x2, y2, x3, y3);
    RotateAboutCentroid(x1, y1, x2, y2, x3, y3, 60);
    getch();
    closegraph();
}