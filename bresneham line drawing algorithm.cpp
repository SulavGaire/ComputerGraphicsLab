#include <iostream>
#include <graphics.h>
#include <cmath>

void bresenham(float x1, float y1, float x2, float y2)
{
    float x=x1, y=y1, xincr, yincr;
    int p, dx, dy;
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    if(dx>0)  xincr = 1; else  xincr = -1;
    if(dy>0)  yincr = 1; else  yincr = -1;
    putpixel(x, y, WHITE);
    if(dx > dy)
    {
        p =2*dy-dx;
        int k = 0;
        while(k <= dx)
        {
            if(p < 0){
                x += xincr;
                p += 2*dy;
            }else{
                x += xincr;
                y += yincr;
                p += 2*dy - 2*dx;
            }
            k++;
            putpixel(x, y, WHITE);
        }
    }
    else{
        p = 2*dx-dy;
        int k = 0;

        while(k <= dy)
        {
            if(p < 0){
                y += yincr;
                p += 2*dx;
            }
            else{
                x += xincr;
                y += yincr;
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
    //inputs
    bresenham(150, 100, 250, 250);
    bresenham(300, 150, 150, 250);
    bresenham(300, 200, 100, 50);
    getch();
    closegraph();
    return 0;
}
