#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#define PI 3.1415

void renderScene(){
    GLfloat x, y, z, angulo;

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINES);
    z = 0.0f;
    for(angulo = 0; angulo <= PI; angulo += (PI/20.0f)){
        x = 50*sin(angulo);
        y = 50*cos(angulo);

        glVertex3f(x, y, z);

        x = 50*sin(angulo + PI);
        y = 50*cos(angulo + PI);

        glVertex3f(x, y, z);

    }

    glEnd();

    glutSwapBuffers();
}

void setup(){
    glClearColor(0.0f, 0.0f, 1.0f, 0.0f);

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
    glutCreateWindow("Linhas Diametro");
    glutDisplayFunc(renderScene);
    glutReshapeFunc(reSize);

    setup();

    glutMainLoop();


    return 0;
}
