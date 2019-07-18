#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#define PI 3.1415f

void renderScene(){
    GLfloat x, y, z, angulo;

    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glRotatef(65.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(45.0f, 0.0f, 1.0f, 0.0f);

    z = -50;
    glBegin(GL_LINE_STRIP);
    for(angulo = 0.0f; angulo <= (2.0f*PI)*3.0f; angulo += 0.1f){
        x = 50*sin(angulo);
        y = 50*cos(angulo);

        glVertex3f(x, y, z);
        z += 0.5f;
    }
    glEnd();

    glPopMatrix();

    glutSwapBuffers();
}

void setUp(){
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

    glColor3f(1.0f, 0.0f, 0.0f);
}

void reSize(int w, int h){
    GLfloat aspectRatio;
    GLfloat canvasSize = 100.0f;

    if(h == 0)
        h = 1;

    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    aspectRatio = (float) w / (float) h;

    if(w >= h){
        glOrtho(-canvasSize * aspectRatio, canvasSize * aspectRatio, -canvasSize, canvasSize, -canvasSize, canvasSize);
    }else{
        glOrtho(-canvasSize, canvasSize, -canvasSize / aspectRatio, canvasSize / aspectRatio, -canvasSize, canvasSize);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}


int main(int argc, char **argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(600,600);
    glutCreateWindow("Espiral Linha");
    glutDisplayFunc(renderScene);
    glutReshapeFunc(reSize);

    setUp();

    glutMainLoop();


    return 0;
}
