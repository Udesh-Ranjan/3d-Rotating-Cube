#include<iostream>
#include<stdlib.h>
#include<GL/freeglut.h>
using namespace std;

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
float rotateX=0,rotateY=0;
float speed=2;
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
    gluPerspective(40,w/h,2.0,30);
    glMatrixMode(GL_MODELVIEW);
}
///////Special////////////
void specialKey(int key,int a,int b){
    if(key==GLUT_KEY_UP){
        rotateY-=speed;
    }
    if(key==GLUT_KEY_DOWN){
        rotateY+=speed;
    }
    if(key==GLUT_KEY_LEFT){
        rotateX-=speed;
    }
    if(key==GLUT_KEY_RIGHT){
        rotateX+=speed;
    }
}
///////Timer///////
void timer(int){
    glutPostRedisplay();
    glutTimerFunc(100,timer,0);
}