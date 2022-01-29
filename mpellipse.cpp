#include <iostream>
#include <graphics.h>
#include <cmath>

void midPointEllipse(int x_radius, int y_radius, int x_c, int y_c)
{
    float x = 0, y = y_radius;
    //putpixel(x, y, WHITE);

    float p = pow(y_radius, 2) + (1/4 * pow(x_radius, 2)) -(pow(x_radius, 2) * y_radius);
    float dx = 2 * pow(y_radius, 2) * x;
    float dy = 2 * pow(x_radius, 2) * y;

    while (dx < dy)
    {
        putpixel(x + x_c, y + y_c, WHITE);
        putpixel(-x + x_c, y + y_c, WHITE);
        putpixel(x + x_c, -y + y_c, WHITE);
        putpixel(-x + x_c, -y + y_c, WHITE);

        if (p < 0)
        {
            x++;
            dx += 2 * pow(y_radius, 2);
            p += dx + pow(y_radius, 2);
        }
        else
        {
            x++;
            y--;
            dx += 2 * pow(y_radius, 2);
            dy -= 2 * pow(x_radius, 2);
            p += dx - dy + pow(y_radius, 2);
        }
    }

    float p2 = ((pow(y_radius, 2)) *pow(x + 0.5, 2)) + (pow(x_radius, 2)*pow(y - 1, 2)) - (pow(x_radius, 2) * pow(y_radius, 2));

    while(y >= 0)
    {
        putpixel(x + x_c, y + y_c, WHITE);
        putpixel(-x + x_c, y + y_c, WHITE);
        putpixel(x + x_c, -y + y_c, WHITE);
        putpixel(-x + x_c, -y + y_c, WHITE);

        if (p2 > 0)
        {
            y--;
            dy -= 2 * pow(x_radius, 2);
            p2 += pow(x_radius, 2) - dy; 
        }
        else
        {
            y--;
            x++;
            dx += 2 * pow(y_radius, 2);
            dy -= 2 * pow(x_radius, 2);
            p2 += dx - dy + pow(x_radius, 2);
        }
    }
}

int main()
{
    initwindow(600, 600, "MidPointEllipse");
    //inputs
    midPointEllipse(100, 75, 200, 125);
    midPointEllipse(160, 250, 300, 300);
    getch();
    closegraph();
}
