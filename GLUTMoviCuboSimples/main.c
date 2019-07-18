#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void renderScene(){
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRotatef(65.0f, 1.0f, 1.0f, 0.0f);

    glPushMatrix();

    glTranslatef(45.0f, 0.0f, 0.0f);

    glColor3f(0.0f, 0.0f, 1.0f);
    glutWireCube(20.0);

    glPopMatrix();
    glPushMatrix();

    glTranslatef(0.0f, 0.0f, 0.0f);

    glColor3f(0.0f, 1.0f, 0.0f);
    glutWireCube(20.0);

    glPopMatrix();
    glPushMatrix();

    glTranslatef(-45.0f, 0.0f, 0.0f);

    glColor3f(1.0f, 0.0f, 0.0f);
    glutWireCube(20.0);

    glPopMatrix();

    glutSwapBuffers();
}

void setUp(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void reSize(int w, int h){
    GLfloat aspectRatio;
    GLfloat canvasSize = 100;

    if(h == 0)
        h = 1;

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    aspectRatio = (float) w / (float) h;

    if(w >= h){
        glOrtho(-canvasSize, canvasSize, -canvasSize / aspectRatio, canvasSize / aspectRatio, -canvasSize, canvasSize);
    }else{
        glOrtho(-canvasSize * aspectRatio, canvasSize * aspectRatio, -canvasSize, canvasSize, -canvasSize, canvasSize);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Movimentacao Simples Cubo");
    glutDisplayFunc(renderScene);
    glutReshapeFunc(reSize);

    setUp();

    glutMainLoop();

    return 0;
}
