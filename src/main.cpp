#include<iostream>
#include<stdlib.h>
#include<GL/freeglut.h>
using namespace std;
/*
    Dev Parzival
    Code for rotating a Cube
*/
void display();
void init();
void timer(int);
void reshape(int,int);
void quad(int,int,int,int);
void specialKey(int,int,int);
float ver[8][3] = {
    {-1.0,-1.0,1.0},
    {-1.0,1.0,1.0},
    {1.0,1.0,1.0},
    {1.0,-1.0,1.0},
    {-1.0,-1.0,-1.0},
    {-1.0,1.0,-1.0},
    {1.0,1.0,-1.0},
    {1.0,-1.0,-1.0},
};

GLfloat color[8][3] = {
    {0.0,0.0,0.0},
    {1.0,0.0,0.0},
    {1.0,1.0,0.0},
    {0.0,1.0,0.0},
    {0.0,0.0,1.0},
    {1.0,0.0,1.0},
    {1.0,1.0,1.0},
    {0.0,1.0,1.0},
};
double rotateX=0,rotateY=0;
double speed=2;
const double GRAVITY=0.96;
double speedX=0;
double speedY=0;
double increment=1.5;
/////Main///////
int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("3D Cube");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(10,timer,0);
    glutSpecialFunc(specialKey);
    init();
    glutMainLoop();
    return 0;
}
///////Display///////
void display(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0,0,-8.0);
    speedX*=GRAVITY;
    speedY*=GRAVITY;
    if(speedX>15)
    speedX=15;
    if(speedX<-15)
    speedX=-15;
    if(speedY>15)
    speedY=15;
    if(speedY<-15)
    speedY=-15;
    rotateX=rotateX+speedX;
    rotateY=rotateY+speedY;
    glRotatef(rotateX,0,1,0);
    glRotatef(rotateY,1,0,0);
    
    quad(0,3,2,1);
    quad(2,3,7,6);
    quad(0,4,7,3);
    quad(1,2,6,5);
    quad(4,5,6,7);
    quad(0,1,5,4);

    glutSwapBuffers();
}
///////Quad///////
//Draws a quaditateral in 3d space with a,b,c & d are the vertices
void quad(int a,int b,int c,int d){
    glBegin(GL_QUADS);
        glColor3fv(ver[a]);
        glVertex3fv(ver[a]);
        glColor3fv(ver[b]);
        glVertex3fv(ver[b]);
        glColor3fv(ver[c]);
        glVertex3fv(ver[c]);
        glColor3fv(ver[d]);
        glVertex3fv(ver[d]);
    glEnd();
}
//////Init////////
void init(){
    glClearColor(0,0,0,1.0);
    glEnable(GL_DEPTH_TEST);
}
//////Reshape//////
void reshape(int w,int h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40,1,2.0,30);
    glMatrixMode(GL_MODELVIEW);
}
///////Special////////////
void specialKey(int key,int a,int b){
    if(key==GLUT_KEY_UP){
        // rotateY-=speed;
        speedY-=increment;
    }
    if(key==GLUT_KEY_DOWN){
        // rotateY+=speed;
        speedY+=increment;
    }
    if(key==GLUT_KEY_LEFT){
        // rotateX-=speed;
        speedX-=increment;
    }
    if(key==GLUT_KEY_RIGHT){
        // rotateX+=speed;
        speedX+=increment;
    }
}
///////Timer///////
void timer(int){
    glutPostRedisplay();
    glutTimerFunc(100,timer,0);
}