#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void renderScene(){
    static GLfloat angulo = 0.0f;

    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();

    glRotated(angulo, 1.0, 0.0, 0.0);
    glRotated(angulo, 0.0, 1.0, 0.0);

    glutWireCube(50.0f);

    glPopMatrix();

    angulo += 1.0f;

    if(angulo >= 360.0f){
        angulo = 0.0f;
    }

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

void timerFunction(int val){

    glutPostRedisplay();
    glutTimerFunc(10, timerFunction, 1);
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Rotacao Cubo Simples");
    glutDisplayFunc(renderScene);
    glutReshapeFunc(reSize);
    glutTimerFunc(33, timerFunction, 1);

    setUp();

    glutMainLoop();

    return 0;
}
