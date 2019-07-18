#include <stdio.h>
#include <stdlib.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void renderScene(){

    static float angulo = 0.0f;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    glPushMatrix();
        glTranslatef(0.0f, 0.0f, -7.0f);
        glRotatef(angulo, 0.0f, 1.0f, 0.0f);
        glutSolidTorus(0.5,1,25,30);
    glPopMatrix();

    angulo += 1.0f;

    if(angulo >= 360)
        angulo = 0.0f;

    glutSwapBuffers();
}

void setup(){

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glEnable(GL_DEPTH_TEST);

    glEnable(GL_LIGHTING);

    glEnable(GL_COLOR_MATERIAL);

    float ambientLigh[] = {1.0f, 1.0f, 1.0f, 1.0f};

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLigh);

    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

}

void reSize(int w, int h){
    float aspectRatio;

    if(h == 0)
        h = 1;

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    aspectRatio = (double) w / (double) h;

    gluPerspective(65.0, aspectRatio, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


}

void timerFunction(int val){
    glutPostRedisplay();
    glutTimerFunc(10, timerFunction, 1);
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutCreateWindow("Ambient Light");
    glutDisplayFunc(renderScene);
    glutReshapeFunc(reSize);
    glutTimerFunc(10, timerFunction, 1);

    setup();

    glutMainLoop();

    return 0;
}
