#include <iostream>
#include <graphics.h>
#include <cmath>

void bresenham(float x1, float y1, float x2, float y2)
{
    float x, y, xincr, yincr;
    int p, dx, dy;
    dx = x2 - x1;
    dy = y2 - y1;
    if(dx<0)    xincr = -1;
    if(dy<0)    yincr = -1;
    dx = abs(dx);
    dy = abs(dy);

    if(dx < dy)
    {
        putpixel(x, y, WHITE);
        p =2*dy-dx;
        int k = 0;
        while(k < dx)
        {
            if(p < 0){
                x += 1;
                p += 2*dy;
            }else{
                x += 1;
                y += 1;
                p += 2*dy - 2*dx;
            }
            k++;
            putpixel(x, y, WHITE);
        }
    }
    else{
        putpixel(x, y, WHITE);
        p = 2*dy-dx;
        int k = 0;

        while(k < dy)
        {
            if(p < 0){
                y += 1;
                p += 2*dx;
            }
            else{
                x += 1;
                y += 1;
                p += 2*dx -2*dy;
            }
            k++;
            putpixel(x, y, WHITE);
        }
    }
}

int main()
{
    initwindow(600,600,"Bresenhams Line Drawing Algorithm");
    bresenham(150, 100, 250, 250);
    bresenham(300, 150, 150, 250);
    bresenham(300, 200, 100, 50);
    getch();
    closegraph();
}