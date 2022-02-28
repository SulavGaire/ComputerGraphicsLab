/* 
    This is the very poor way of programming in C++,
    I do not recommend anyone to code like this,
    But for the assignment purpose I choosed the simpler way,
*/

#include <iostream>
#include <graphics.h>
#include <cmath>

void plot(int x1, int y1, int x2, int y2, int x3, int y3)
{
    moveto(x1, y1);
    lineto(x2, y2);
    lineto(x3, y3);
    lineto(x1, y1);
}

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

    plot(x1, y1, x2, y2, x3, y3);
}

void RotateAboutCenter(int x1, int y1, int x2, int y2, int x3, int y3, int angle)
{
    x1 = abs((x1 * cos(angle)) - (y1 * sin(angle)));
    y1 = abs((x1 * sin(angle)) + (y1 * cos(angle)));

    x2 = abs((x2 * cos(angle)) - (y2 * sin(angle)));
    y2 = abs((x2 * sin(angle)) + (y2 * cos(angle)));

    x3 = abs((x3 * cos(angle)) - (y3 * sin(angle)));
    y3 = abs((x3 * sin(angle)) + (y3 * cos(angle)));

   plot(x1, y1, x2, y2, x3, y3);
}

void scale(int x1, int y1, int x2, int y2, int x3, int y3, int sx, int sy)
{
    x1 = sx * x1;
    y1 = sy * y1;
    x2 = sx * x2;
    y2 = sy * y2;
    x3 = sx * x3;
    y3 = sy * y3;

    plot(x1, y1, x2, y2, x3, y3);
}

void traslation(int x1, int y1, int x2, int y2, int x3, int y3, int tx, int ty)
{
    x1 = tx + x1;
    y1 = ty + y1;
    x2 = tx + x2;
    y2 = ty + y2;
    x3 = tx + x3;
    y3 = ty + y3;

   plot(x1, y1, x2, y2, x3, y3);
}

void shear(int x1, int y1, int x2, int y2, int x3, int y3, int shx, int shy)
{
    int option;
    std::cout << "Enter the direction of shear: (1 for x, 2 for y, 3 for both): " ;
    std::cin >> option;
    if(option == 1)
        shy = 0;
    else if(option == 2)
        shx = 0; 
    else if(option == 3)
        ;
    else  
        exit(0);
    x1 = x1 + shx * y1;
    y1 = shy * x1 + y1;
    x2 = x2 + shx * y2;
    y2 = shy * x2 + y2;
    x3 = x3 + shx * y3;
    y3 = shy * x3 + y3;

    plot(x1, y1, x2, y2, x3, y3);
}         

int main()
{
    initwindow(600,600, "AllinOne");
    int x1 = 100, y1 = 100, x2 = 100, y2 = 200, x3 = 200, y3 = 200;
    plot(x1, y1, x2, y2, x3, y3);
    std::cout << "Enter the option\n"
    "1. Rot about centroid\n"
    "2. Rot about center\n"
    "3. Scaling\n"
    "4. Translation\n" 
    "5. Shear"<< std::endl;

    int option, angle, sx, sy, tx, ty, shx, shy;
    std::cin >> option;
    if(option == 1)
    {
        std::cout << "Enter Angle: ";
        std::cin >> angle;
        RotateAboutCentroid(x1, y1, x2, y2, x3, y3, angle);
    }
    else if(option == 2)
    {
        std::cout << "Enter Angle: ";
        std::cin >> angle;
        RotateAboutCenter(x1, y1, x2, y2, x3, y3, angle);
    }
    else if(option == 3)
    {
        std::cout << "Enter scale factors(sx, sy): ";
        std::cin >> sx >> sy;
        scale(x1, y1, x2, y2, x3, y3, sx, sy);
    }
    else if(option == 4)
    {
        std::cout << "Enter traslation factors(tx, ty): ";
        std::cin >> tx >> ty;
        traslation(x1, y1, x2, y2, x3, y3, tx, ty);
    }
    else if(option == 5)
    {
        std::cout << "Enter shear factors(shx, shy): ";
        std::cin >> shx >> shy;
        shear(x1, y1, x2, y2, x3, y3, shx, shy);
    }

    else
        exit(0);
    getch();
    closegraph();
}
