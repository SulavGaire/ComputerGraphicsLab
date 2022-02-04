#include "rotsctrsh.h"

int main()
{
    allinone *all;
    all->set(100, 100, 100, 200, 200, 200);
    initwindow(600, 600, "allinone");

    all->plot();

    do{
        std::cout << "Enter the option(0 to quit)\n"
        "1. Rotation about centroid\n"
        "2. Rotation about center\n"
        "3. Scaling\n"
        "4. Translation\n" 
        "5. Shear"<< std::endl;

        int option, angle, sx, sy, tx, ty, shx, shy;
        std::cin >> option;
        if(option == 1)
        {
            std::cout << "Enter Angle: ";
            std::cin >> angle;
            all->RotateAboutCentroid(angle);
        }
        else if(option == 2)
        {
            std::cout << "Enter Angle: ";
            std::cin >> angle;
            all->RotateAboutCenter(angle);
        }
        else if(option == 3)
        {
            std::cout << "Enter scale factors(sx, sy): ";
            std::cin >> sx >> sy;
            all->scale(sx, sy);
        }
        else if(option == 4)
        {
            std::cout << "Enter traslation factors(tx, ty): ";
            std::cin >> tx >> ty;
            all->translation(tx, ty);
        }
        else if(option == 5)
        {
            std::cout << "Enter traslation factors(shx, shy): ";
            std::cin >> shx >> shy;
            all->shear(shx, shy);
        }
        else
            exit(0);
    }while(1);
    getch();
    closegraph();
}
