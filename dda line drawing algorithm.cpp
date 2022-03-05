// LAB task #1 DDA line drawing algorithm
#include <graphics.h>
#include <iostream>
#include <cmath>

using namespace std;


void ddalinedraw(int x1,int y1,int x2,int y2)
{


  int dx=x2-x1,dy=y2-y1,step;
  float xincr,yincr,x=x1,y=y1;

  if(abs(dx)>abs(dy))
    step = abs(dx);
  else 
    step = abs(dy);

  xincr = dx/(float)step;
  yincr = dy/(float)step;
  putpixel(round(x),round(y),WHITE);

  int i=1;
  while(i<=step){
    x=x+xincr;
    y=y+yincr;
    i++;
    delay(10);
    putpixel(round(x),round(y),WHITE);
  }

}




int main()
{
  initwindow(500,500,"DDA Line Drawing Algorithm");
  ddalinedraw(100,100,200,250);
  ddalinedraw(300,100,100,250);
  ddalinedraw(300,400,100,250);
  getch();
  closegraph();
  return 0;
}

