#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>


void renderScene(){
    GLfloat x, y, z;
    GLint factor =  1;
    GLushort pattern = 0x5555;

    glEnable(GL_LINE_STIPPLE);

    glClear(GL_COLOR_BUFFER_BIT);

    z = 0.0f;
    x = 80.0f;
    for(y = -90.0f; y <= 90.0f; y += 20.0f){
        glLineStipple(factor, pattern);

        glBegin(GL_LINE_STRIP);
            glVertex3f(x, y, z);
            glVertex3f(-x, y, z);
        glEnd();

        factor++;
    }

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
    glutCreateWindow("Linha Pontilhada");
    glutDisplayFunc(renderScene);
    glutReshapeFunc(reSize);

    setUp();

    glutMainLoop();


    return 0;
}
