#include <iostream>
#include <graphics.h>
#include <cmath>
//#define Round(a) (a + 0.5)         Roundoff function can be represented as this also

inline int Round(float a)
{
    return static_cast<int>(a);
}

void DDA(float x1, float y1, float x2, float y2)
{
    float  x, y, dx, dy, step, xincr, yincr;
    dx = x1-x2;
    dy = y1-y2;

    if(abs(dx) > abs(dy))
        step = abs(dx);
    else    
        step = abs(dy);

    xincr = dx/static_cast<float>(dx);
    yincr = dy/static_cast<float>(dy);
    putpixel(Round(x), Round(y), WHITE);

    int i = 1;
    while(i <= step)
    {
        x += xincr;
        y += yincr;
        i++;
        delay(10);
        putpixel(Round(x), Round(y), WHITE);
    }
}

int main()
{
    initwindow(600, 600, "DDA");
    DDA(100, 100, 200, 250);
    DDA(300, 100, 100, 250);
    DDA(300, 400, 100, 250);
    getch();
    closegraph();
}