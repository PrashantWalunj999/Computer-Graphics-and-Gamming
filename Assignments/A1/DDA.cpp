#include<stdio.h>
#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;


class pixel
{
public:
int x1,y1,x2,y2;
void getpoint()
{
cout<<"enter x1:";
cin>>x1;
cout<<"enter x2:";
cin>>x2;
cout<<"enter y1:";
cin>>y1;
cout<<"enter y2:";
cin>>y2;
}
};

class DDA_BRE:public pixel
{
public:
float dx,dy,x,y,xinc,yinc;
int steps,i,p;
void drawline();
void drawline(int x,int y);
};

void DDA_BRE::drawline()
{
dx=abs(x2-x1);
dy=abs(y2-y1);
if(dx>=dy)
steps=dx;
else
steps=dy;
x=x1,y=y1;
xinc=dx/steps;
yinc=dy/steps;
for(i=0;i<=steps;i++)
{
putpixel(x,y,11) ;
x=x+xinc;
y=y+yinc;
}
}
void DDA_BRE::drawline(int x,int y)
{
dx=x2-x1;
dy=y2-y1;
p=2*(dy-dx);
x=x1;
y=y1;
while(x<=x2)
{
x=x+1;
if(p<0)
{
p=p+2*dy;
}
else
{
y=y+1;
p=p+2*(dy-dx);
}
putpixel(x,y,11);
}
}
int main()
{
int gdrive=DETECT,gmode,i,y=0,x=0;
initgraph(&gdrive,&gmode,"c:\\tc\\bgi");
DDA_BRE obj1;
     obj1. getpoint();
     obj1.drawline();


     obj1.getpoint();
     obj1.drawline(0,0);

return 0;
getch();
}