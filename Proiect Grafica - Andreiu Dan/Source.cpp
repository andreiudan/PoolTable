#include "glos.h"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>


void myinit(void);
void drawPlane(void);

void CALLBACK rotateUp(void);
void CALLBACK rotateDown(void);
void CALLBACK rotateRight(void);
void CALLBACK rotateLeft(void);

void CALLBACK display(void);
void CALLBACK myReshape(GLsizei w, GLsizei h);
void CALLBACK tableLegs(void);
void CALLBACK table(void);
void CALLBACK balls(void);
void CALLBACK ballMovement(void);


static int horizontalRotation = 0, verticalRotation = 0, ballRotation = 0;
static float ballMoving = 0.0;
boolean  ballDirection = 0;
GLUquadricObj* quadricObject = 0;

void CALLBACK rotateUp(void)
{
    verticalRotation = (verticalRotation + 5) % 360;
}

void CALLBACK rotateDown(void)
{
    verticalRotation = (verticalRotation - 5) % 360;
}

void CALLBACK rotateRight(void)
{
    horizontalRotation = (horizontalRotation - 5) % 360;
}

void CALLBACK rotateLeft(void)
{
    horizontalRotation = (horizontalRotation + 5) % 360;
}

void CALLBACK ballMovement(void)
{
    ballRotation = (ballRotation + 15) % 360;

    if ((ballMoving + 0.1) > 2.2)
    {
        ballDirection = 0;
    }
    else
    {
        if ((ballMoving - 0.1) < -2.2)
        {
            ballDirection = 1;
        }
    }

    switch (ballDirection) {
    case 0:
        ballMoving = ballMoving - 0.02;
        break;
    case 1:
        ballMoving = ballMoving + 0.02;
        break;
    }

    display();
    Sleep(30);
}

void CALLBACK tableLegs(void)
{
    glColor3f(0.5, 0.20, 0.005);

    //left front leg
    glPushMatrix();
    glTranslatef(-1.7, -1.5, 0.7);
    auxSolidBox(0.2, 1.0, 0.2);
    glPopMatrix();

    //left back leg
    glPushMatrix();
    glTranslatef(-1.7, -1.5, -0.7);
    auxSolidBox(0.2, 1.0, 0.2);
    glPopMatrix();

    //right front leg
    glPushMatrix();
    glTranslatef(1.7, -1.5, 0.7);
    auxSolidBox(0.2, 1.0, 0.2);
    glPopMatrix();

    //right back leg
    glPushMatrix();
    glTranslatef(1.7, -1.5, -0.7);
    auxSolidBox(0.2, 1.0, 0.2);
    glPopMatrix();
}

void CALLBACK table(void)
{
    glColor3f(0.0, 1.0, 0.0);
    glPushMatrix();
    glTranslatef(0.0, -1.0, 0.0);
    auxSolidBox(4.4, 0.1, 1.9);
    glPopMatrix();
}

void CALLBACK tableMargins(void)
{
    glColor3f(0.5, 0.20, 0.005);

    //left margin
    glPushMatrix();
    glTranslatef(-2.225, -0.965, 0.0);
    auxSolidBox(0.05, 0.175, 2.0);
    glPopMatrix();

    //right margin
    glPushMatrix();
    glTranslatef(2.225, -0.965, 0.0);
    auxSolidBox(0.05, 0.175, 2.0);
    glPopMatrix();

    //front margin
    glPushMatrix();
    glTranslatef(0, -0.965, 0.975);
    auxSolidBox(4.4, 0.175, 0.05);
    glPopMatrix();

    //back margin
    glPushMatrix();
    glTranslatef(0, -0.965, -0.975);
    auxSolidBox(4.4, 0.175, 0.05);
    glPopMatrix();
}

void CALLBACK tableHoles(void)
{
    glColor3f(0.0, 0.0, 0.0);

    //middle back hole
    glPushMatrix();
    quadricObject = gluNewQuadric();
    gluQuadricDrawStyle(quadricObject, GLU_FILL);
    glTranslatef(0, -0.945, -0.95);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    gluPartialDisk(quadricObject, 0, 0.1, 20, 2, 0, 180);
    glPopMatrix();

    //middle fron hole
    glPushMatrix();
    quadricObject = gluNewQuadric();
    gluQuadricDrawStyle(quadricObject, GLU_FILL);
    glTranslatef(0, -0.945, 0.95);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glRotatef(270.0, 0.0, 0.0, 1.0);
    gluPartialDisk(quadricObject, 0, 0.1, 20, 2, 0, 180);
    glTranslatef(0, 0.945, -0.95);
    glPopMatrix();

    //left back hole
    glPushMatrix();
    quadricObject = gluNewQuadric();
    gluQuadricDrawStyle(quadricObject, GLU_FILL);
    glTranslatef(-2.2, -0.945, -0.95);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    gluPartialDisk(quadricObject, 0, 0.14, 20, 2, 0, 90);
    glPopMatrix();

    //left front hole
    glPushMatrix();
    quadricObject = gluNewQuadric();
    gluQuadricDrawStyle(quadricObject, GLU_FILL);
    glTranslatef(-2.2, -0.945, 0.95);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glRotatef(-90.0, 0.0, 0.0, 1.0);
    gluPartialDisk(quadricObject, 0, 0.14, 20, 2, 0, 90);
    glPopMatrix();

    //right back hole
    glPushMatrix();
    quadricObject = gluNewQuadric();
    gluQuadricDrawStyle(quadricObject, GLU_FILL);
    glTranslatef(2.2, -0.945, -0.95);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    gluPartialDisk(quadricObject, 0, 0.14, 20, 2, 0, 90);
    glPopMatrix();

    //right front hole
    glPushMatrix();
    quadricObject = gluNewQuadric();
    gluQuadricDrawStyle(quadricObject, GLU_FILL);
    glTranslatef(2.2, -0.945, 0.95);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glRotatef(-180.0, 0.0, 0.0, 1.0);
    gluPartialDisk(quadricObject, 0, 0.14, 20, 2, 0, 90);
    glPopMatrix();
}

void CALLBACK balls(void)
{
    //white ball
    glShadeModel(GL_SMOOTH);
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(0.0, -0.895, 0.0);
    glTranslatef(ballMoving, 0.0, 0.0);
    glRotatef((GLfloat)ballRotation, 0.0, 0.0, 1.0);
    auxSolidSphere(0.06);
    glPopMatrix();

    //black ball
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(1.0, -0.895, 0.5);
    auxSolidSphere(0.06);
    glPopMatrix();

    //red ball
    glPushMatrix();
    glColor3f(1.0, 0.0, 0.0);
    glTranslatef(-1.8, -0.895, 0.8);
    auxSolidSphere(0.06);
    glPopMatrix();

    //yellow ball
    glPushMatrix();
    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(1.24, -0.895, -0.14);
    auxSolidSphere(0.06);
    glPopMatrix();
}

void CALLBACK display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.5, 0.5, 0.5, 0);
    glPushMatrix();

    glTranslatef(0.0, 0.0, 0.0);
    glRotatef((GLfloat)verticalRotation, 1.0, 0.0, 0.0);
    glRotatef((GLfloat)horizontalRotation, 0.0, 1.0, 0.0);

    tableLegs();

    table();

    tableMargins();

    tableHoles();

    balls();

    glPopMatrix();
    glFlush();
}

void myinit(void)
{

    GLfloat mat_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
    GLfloat mat_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };

    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };

    GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };

    GLfloat light_position[] = { 5.0, 2.0, 1.0, 0.0 };

    GLfloat lmodel_ambient[] = { 0.2, 0.2, 0.2, 1.0 };

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_AUTO_NORMAL);

    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_FLAT);
    glEnable(GL_COLOR_MATERIAL);
}

void CALLBACK myReshape(GLsizei w, GLsizei h)
{
    if (!h) return;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 500.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0, 0.0, -5.0);
}


int main(int argc, char** argv)
{
    auxInitDisplayMode(AUX_SINGLE | AUX_RGB);
    auxInitPosition(0, 0, 800, 800);
    auxInitWindow((LPCWSTR)"PoolTable");

    myinit();
    auxIdleFunc(ballMovement);

    auxKeyFunc(AUX_LEFT, rotateLeft);
    auxKeyFunc(AUX_RIGHT, rotateRight);
    auxKeyFunc(AUX_UP, rotateUp);
    auxKeyFunc(AUX_DOWN, rotateDown);

    auxReshapeFunc(myReshape);
    auxMainLoop(display);

    return(0);
}
