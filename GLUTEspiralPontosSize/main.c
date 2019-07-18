#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#define PI 3.1415f

void renderScene(){
    GLfloat x, y, z, angulo;
    GLfloat rengeSize[2];
    GLfloat encSize;
    GLfloat curentSize;

    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glRotatef(-120.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(  0.0f, 0.0f, 1.0f, 0.0f);

    glGetFloatv(GL_POINT_SIZE_RANGE,rengeSize);
    glGetFloatv(GL_POINT_SIZE_GRANULARITY,&encSize);

    curentSize = rengeSize[0];


    z = -50.f;
    for(angulo = 0.0f; angulo <= (2.0f*PI)*3.0f; angulo += 0.1f){
        x = 50.0f*sin(angulo);
        y = 50.0f*cos(angulo);

        glPointSize(curentSize);

        glBegin(GL_POINTS);
            glVertex3f(x, y, z);
        glEnd();

        z += 0.5f;
        curentSize += encSize;
    }

    glPopMatrix();

    glutSwapBuffers();

}

void setup(){
    glClearColor(0.0f, 0.0f, 1.0f, 0.0f);

    glColor3f(1.0f, 0.0f, 0.0f);

}

void reSize(int w, int h){
    GLfloat aspectRatio;
    GLfloat canvasSize = 100.f;

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
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(600,600);
    glutCreateWindow("Espiral Pontos");
    glutDisplayFunc(renderScene);
    glutReshapeFunc(reSize);


    setup();

    glutMainLoop();

    return 0;
}
