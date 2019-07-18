#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#define PI 3.1415f

void renderScene(){
    GLfloat x, y, angulo;
    GLint verCor = 1;

    glPushMatrix();
    glRotatef(65.0f, 1.0f, 0.0f, 0.0f);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH);



    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(0.0f, 0.0f, 75.0f);
    for(angulo = 0; angulo <= 2.0f*PI; angulo += (PI/8.0f)){
        x = 50*sin(angulo);
        y = 50*cos(angulo);

        if(verCor%2 == 0){
            glColor3f(0.0f, 0.0f, 1.0f);
        }else{
            glColor3f(1.0f, 0.0f, 0.0f);
        }

        glVertex2f(x,y);
        verCor++;
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(0.0f, 0.0f, 0.0f);
    for(angulo = 0; angulo <= 2.0f*PI; angulo += (PI/8.0f)){
        x = 50*sin(angulo);
        y = 50*cos(angulo);

        if(verCor%2 == 0){
            glColor3f(0.0f, 0.0f, 1.0f);
        }else{
            glColor3f(1.0f, 0.0f, 0.0f);
        }

        glVertex2f(x,y);
        verCor++;
    }
    glEnd();

    glPopMatrix();

    glutSwapBuffers();
}

void setup(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glShadeModel(GL_FLAT);
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
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutCreateWindow("Cone Triangulo Fan");
    glutDisplayFunc(renderScene);
    glutReshapeFunc(reSize);

    setup();

    glutMainLoop();

    return 0;
}
