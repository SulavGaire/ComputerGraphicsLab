#include <iostream>
#include <graphics.h>

void midPoint(int x_c, int y_c, int r)
{
    int x = r, y = 0;
    putpixel(x + x_c, y + y_c, WHITE);

    if(r > 0)
    {
        putpixel(x + x_c, -y + y_c, WHITE);
        putpixel(y + x_c, x + y_c, WHITE);
        putpixel(-y + x_c, x + y_c, WHITE);
    }

    int p = 1 - r;
    while(x > y)
    {
        y++;
        if(p <= 0)
            p += 2*y + 1;
        else
        {
            x--;
            p += 2*(y - x) + 1;
        }
        if(x < y)
            break;
        putpixel(x + x_c, y + y_c, WHITE);
        putpixel(-x + x_c, y + y_c, WHITE);
        putpixel(x + x_c, -y + y_c, WHITE);
        putpixel(-x + x_c, -y + y_c, WHITE);
    

    if(x != y)
    {
        putpixel(y + x_c, x + y_c, WHITE);
        putpixel(-y + x_c, x + y_c, WHITE);
        putpixel(y + x_c, -x + y_c, WHITE);
        putpixel(-y + x_c, -x + y_c, WHITE);
    }
    }
}

int main()
{
    initwindow(500, 500, "Mid Point Circle Algorithm");
    // inputs
    midPoint(200, 125, 100); 
    midPoint(100, 150, 50);
    getch();
    closegraph();
}