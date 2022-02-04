#pragma once

#ifndef _ROTSCTRSH_H
#define _ROTSCTRSH_H

#include <iostream>
#include <cmath>
#include <graphics.h>

class allinone
{
    int x1, y1, x2, y2, x3, y3, angle;

public:
    void set(int x1, int y1, int x2, int y2, int x3, int y3); 
    void plot();
    void RotateAboutCentroid(const int& angle);
    void RotateAboutCenter(int& angle);
    void scale(int& sx, int& sy);
    void translation(int& tx, int& ty);
    void shear(int& shx, int& shy);
};

#endif /*_ROTSCTRSH_H*/