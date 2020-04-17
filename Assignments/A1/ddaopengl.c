#include<stdio.h>
#include<math.h>
#include<GL/glut.h>

double xa,xb,yb,ya;
float round_value(float v)
{
return floor(v+0.5);
}
void lineDDa(void)
{
double dx=(xb-xa);
double dy=(yb-ya);
double steps;
float xinc,yinc,x=xa,y=ya;
steps=(abs(dx)>abs(dy))?(abs(dx)):(abs(dy));
xinc= dx/(float)steps;
yinc=dy/(float)steps;
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_POINTS);
glVertex2d(x,y);
int k;
for(k=0;k<steps;k++)
{
x=x+xinc;
y=y+yinc;
glVertex2d(round_value(x),round_value(y));
}
glEnd();
glFlush();
}
void Init()
{
glClearColor(1.0,1.0,1.0,0.0);
glColor3f(0.0,0.0,0.0);
gluOrtho2D(0,640,0,480);
}
int main(int argc,char **argv)
{
printf("Enter the point x1,y1 \n");
scanf("%lf%lf",&xa,&ya);
printf("Enter the point x2,y2 \n");
scanf("%lf%lf",&xb,&yb);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(0,0);
glutInitWindowSize(640,480);
glutCreateWindow("DDA_LINE");
Init();
glutDisplayFunc(lineDDa);
glutMainLoop();
return 0;
}
