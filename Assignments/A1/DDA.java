


public class DDA
{
public:
int x1,y1,x2,y2;

void getpoint()
{
System.out.println("enter x1:");

System.out.println("enter x2:");

System.out.println("enter y1:")

System.out.println("enter y2:")

}
}

class DDA_BRE extends pixel
{
public:
float dx,dy,x,y,xinc,yinc;
int steps,i,p;
void drawline();
void drawline(int x,int y);


void drawline()
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
void drawline(int x,int y)
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
}}

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