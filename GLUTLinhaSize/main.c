#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>


void renderScene(){
    GLfloat x, y, z;
    GLfloat rengSize[2];
    GLfloat curentSize;

    glClear(GL_COLOR_BUFFER_BIT);

    glGetFloatv(GL_LINE_WIDTH_RANGE, rengSize);

    curentSize = rengSize[0];

    z = 0.0f;
    x = 80.0f;
    for(y = -90.0f; y <= 90.0f; y += 20.0f){
        glLineWidth(curentSize);
        glBegin(GL_LINES);
            glVertex3f(x, y, z);
            glVertex3f(-x, y, z);
        glEnd();

        curentSize += 1.0f;
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
    glutCreateWindow("Tamanho Linha");
    glutDisplayFunc(renderScene);
    glutReshapeFunc(reSize);

    setUp();

    glutMainLoop();


    return 0;
}
