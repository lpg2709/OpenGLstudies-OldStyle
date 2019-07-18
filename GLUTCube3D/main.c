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

    glBegin(GL_QUADS);
        //Frente
        glColor3f(1.0f,0.0f,0.0f);
        glVertex3f(-1.0,  1.0, 1.0);
        glVertex3f( 1.0,  1.0, 1.0);
        glVertex3f( 1.0, -1.0, 1.0);
        glVertex3f(-1.0, -1.0, 1.0);

        //Direia
        glColor3f(0.0f,1.0f,0.0f);
        glVertex3f( 1.0,  1.0, 1.0);
        glVertex3f( 1.0,  1.0,-1.0);
        glVertex3f( 1.0, -1.0,-1.0);
        glVertex3f( 1.0, -1.0, 1.0);

        //Esquerda
        glColor3f(0.0f,0.0f,1.0f);
        glVertex3f(-1.0,  1.0,-1.0);
        glVertex3f(-1.0,  1.0, 1.0);
        glVertex3f(-1.0, -1.0, 1.0);
        glVertex3f(-1.0, -1.0,-1.0);

        //Traz
        glColor3f(1.0f,0.0f,1.0f);
        glVertex3f(-1.0,  1.0,-1.0);
        glVertex3f( 1.0,  1.0,-1.0);
        glVertex3f( 1.0, -1.0,-1.0);
        glVertex3f(-1.0, -1.0,-1.0);

        //Cima
        glColor3f(1.0f,1.0f,0.0f);
        glVertex3f(-1.0,  1.0, 1.0);
        glVertex3f(-1.0,  1.0,-1.0);
        glVertex3f( 1.0,  1.0,-1.0);
        glVertex3f( 1.0,  1.0, 1.0);

        //Baixo
        glColor3f(0.0f,1.0f,1.0f);
        glVertex3f(-1.0, -1.0, 1.0);
        glVertex3f( 1.0, -1.0, 1.0);
        glVertex3f( 1.0, -1.0,-1.0);
        glVertex3f(-1.0, -1.0,-1.0);


    glEnd();

    angulo += 1.0f;
    if(angulo >= 360.0f)
        angulo = 0;

    glutSwapBuffers();
}

void setUp(){
    glClearColor( 0.0f, 0.0f, 0.0f, 1.0f);

    glEnable(GL_DEPTH_TEST);

    glDepthFunc(GL_LEQUAL);
}

void reSize(int w, int h){
    GLfloat aspectRatio;
    GLdouble canvasSize = 400;

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

void functionTime(int val){
    glutPostRedisplay();
    glutTimerFunc(10,functionTime,1);
}

int main(int argc, char **argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutCreateWindow("Cube 3D");
    glutDisplayFunc(renderScene);
    glutReshapeFunc(reSize);
    glutTimerFunc(10,functionTime,1);

    setUp();

    glutMainLoop();
    return 0;
}
