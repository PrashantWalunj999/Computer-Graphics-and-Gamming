#include<GL/glut.h>
#include<GL/gl.h>
#include<stdio.h>


float x1,x2,y1,y2;
float x3,y3,x4,y4;
void dda(float x1, float y1,float x2, float y2)
{
glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POINTS);
        glColor3f(0.0f,1.0f,0.0f);
        float dx, dy, len,i,xinc,yinc;
        dx=abs(x2-x1);
        dy=abs(y2-y1);

        if(dx>=dy)
           len = dx;
        else
           len = dy;

        xinc=(x2-x1)/len;
        yinc=(y2-y1)/len;
        for(i=0; i<=len; i++)
        {
        x1=x1+xinc;
        y1=y1+yinc;
        glVertex2f(x1,y1);
        }

}
void display(void)
{
//for outer square

dda(x1,y1,x2,y1);
dda(x2,y1,x2,y2);
dda(x2,y2,x1,y2);
dda(x1,y2,x1,y1);

// for middle square

dda((x1+x2)/2,y1,x2,(y1+y2)/2);
dda(x2,(y1+y2)/2,(x1+x2)/2,y2);
dda((x1+x2)/2,y2,x1,(y1+y2)/2);
dda(x1,(y1+y2)/2,(x1+x2)/2,y1);

// for middle square

//dda((x1+x2)/4,(y1+y2)/3,(x1+x2)*3/4,(y1+y2)/4);
dda(((x1+x2)/2+y1)/2,(x2+(y1+y2)/2)/2,(x2+(y1+y2)/2)/2,((x1+x2)/2+y2)/2);
dda((x2+(y1+y2)/2)/2,((x1+x2)/2+y2)/2,((x1+x2)/2+y2)/2,(x1+(y1+y2)/2)/2);
dda(((x1+x2)/2+y2)/2,(x1+(y1+y2)/2)/2,((x1+x2)/2+y2)/2,(x1+(y1+y2)/2)/2);
dda(((x1+x2)/2+y2)/2,(x1+(y1+y2)/2)/2,(x1+(y1+y2)/2)/2,((x1+x2)/2+y1)/2);
dda((x1+(y1+y2)/2)/2,((x1+x2)/2+y1)/2,((x1+x2)/2+y1)/2,(x2+(y1+y2)/2)/2);
//dda(x1,y1,x2,y2);
//dda(x1,y2,x2,y1);

glEnd();
glFlush();

}


void Init()
{
glClearColor(1.0,1.0,1.0,0);
glColor3f(0.0,0.0,0.0);
gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char *argv[]){
        printf("Enter the value of x1,y1");
        scanf("%f",&x1);
        scanf("%f",&y1);
        printf("Enter the value of x2,y2");
        scanf("%f",&x2);
        scanf("%f",&y2);
        glutInit(&argc, argv);
        glutInitWindowSize(500,500);
        glutInitWindowPosition(100,100);
        glutCreateWindow("WIND");
        Init();
        glutDisplayFunc(display);
        glutMainLoop();
        return 0;
}
