#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

GLfloat x = 0.0f;
GLfloat y = 0.0f;
GLfloat rSize = 25.0f;

GLfloat modX = 1.0f;
GLfloat modY = 1.0f;

GLfloat canvasWidth = 100;
GLfloat canvasHieght = 100;

void renderScene(){
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.1f);
    glRectf(x, y, x+rSize, y-rSize);

    glutSwapBuffers();

}

void setup(){
    glClearColor(0.0f,0.0f,1.0f,1.0f);
}

void timerFunction(int val){
    if(x > canvasWidth-rSize || x < -canvasWidth){
        modX = -modX;
    }
    if(y > canvasHieght || y < -canvasHieght+rSize){
        modY = -modY;
    }

    x += modX;
    y += modY;

    if(x > (canvasWidth-rSize+modX)){
        x = canvasWidth-rSize-1;
    }else if(x < -(canvasWidth+modX)){
        x = -canvasWidth-1;
    }

    if(y > (canvasHieght + modY)){
        y = canvasHieght-1;
    }else if(y < -(canvasHieght-rSize+modY)){
        y = -canvasHieght+rSize-1;
    }

    glutTimerFunc(33,timerFunction,1);
    glutPostRedisplay();

}

void reSize(int w, int h){
    GLfloat aspectRatio;

    if(h == 0)
        h = 1;

    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    aspectRatio = (float) w / (float) h;

    if(w >= h){
        glOrtho(-100, 100, -100/aspectRatio, 100/aspectRatio, -100, 100);
    }else{
        glOrtho(-100 * aspectRatio, 100 * aspectRatio, -100, 100, -100, 100);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

int main(int argc, char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(600,600);
    glutCreateWindow("Animacao Simples");
    glutDisplayFunc(renderScene);
    glutReshapeFunc(reSize);
    glutTimerFunc(33,timerFunction,1);

    setup();

    glutMainLoop();


    return 0;
}
