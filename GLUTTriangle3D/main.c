#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void renderScene(){

    static GLfloat angulo = 0.0f;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -7.0f);
    glRotatef(angulo, 1.0f, 1.0f, 0.0f);

    glBegin(GL_TRIANGLES);

        //Frente
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(  0.0f, 0.5f, 0.0f);
        glVertex3f(  0.8f,-0.5f,-0.5f);
        glVertex3f( -0.8f,-0.5f,-0.5f);

        //Esquerda
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(  0.0f, 0.5f, 0.0f);
        glVertex3f( -0.8f,-0.5f,-0.5f);
        glVertex3f(  0.0f,-0.5f, 1.0f);

        //Direita
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(  0.0f, 0.5f, 0.0f);
        glVertex3f(  0.0f,-0.5f, 1.0f);
        glVertex3f(  0.8f,-0.5f,-0.5f);


        //Baixo
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(  0.0f,-0.5f, 1.0f);
        glVertex3f(  0.8f,-0.5f,-0.5f);
        glVertex3f( -0.8f,-0.5f,-0.5f);

    glEnd();

    angulo += 1.0f;

    if(angulo >= 360.0f)
        angulo = 0.0f;


    glutSwapBuffers();
}

void setUp(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);


    glEnable(GL_DEPTH_TEST);

    glDepthFunc(GL_LEQUAL);
}

void reSize(int w, int h){

    GLfloat aspectRatio;
    GLfloat canvasSize = 400.0f;

    if(h == 0)
        h = 1;

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    aspectRatio = (float) w / (float) h;

    gluPerspective(65.0, aspectRatio, 1.0, canvasSize);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void timerFunction(int val){
    glutPostRedisplay();

    glutTimerFunc(10,timerFunction,1);
}

int main(int argc, char **argv){
    glutInit(&argc ,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutCreateWindow("Triangle 3D");
    glutDisplayFunc(renderScene);
    glutReshapeFunc(reSize);
    glutTimerFunc(10,timerFunction,1);

    setUp();

    glutMainLoop();

    return 0;
}
