/*
Programul afiseaza o masa de biliard
*/

#include "glos.h"

#include <GL/GLU.h>
#include <GL/GL.H>
#include <GL/GLAux.h>

void myinit(void);
void CALLBACK display(void);
void CALLBACK myReshape(GLsizei w, GLsizei h);

GLUquadricObj* gluObj = gluNewQuadric();

void myinit(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0); //culoarea background-ului
    glColor3f(0.0, 0.0, 0.0);
}

void CALLBACK display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
        gluQuadricDrawStyle(gluObj,GLU_LINE);
        gluCylinder(gluObj,10,10,10,100,100);
    glPopMatrix();
    glFlush();
}

void CALLBACK myReshape(GLsizei w, GLsizei h)
{
    if (!h) return;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-5.0, 5.0, -5.0 * (GLfloat)h / (GLfloat)w,
            5.0 * (GLfloat)h / (GLfloat)w, -5.0, 5.0);
    else
        glOrtho(-5.0 * (GLfloat)w / (GLfloat)h,
            5.0 * (GLfloat)w / (GLfloat)h, -5.0, 5.0, -5.0, 5.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv)
{
    auxInitDisplayMode(AUX_SINGLE | AUX_RGB);
    auxInitPosition(0, 0, 500, 500);
    auxInitWindow((LPCWSTR)"PoolTable");
    myinit();
    auxReshapeFunc(myReshape);
    auxMainLoop(display);
    return(0);
}