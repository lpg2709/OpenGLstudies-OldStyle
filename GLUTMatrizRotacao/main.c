#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

float matrixIdentity[16] = {1.0f, 0.0f, 0.0f, 0.0f,
                            0.0f, 1.0f, 0.0f, 0.0f,
                            0.0f, 0.0f, 1.0f, 0.0f,
                            0.0f, 0.0f, 0.0f, 1.0f };

void rotetionMatrix44(float m[16], float angulo, float x, float y, float z){
    float seno, cosseno, moduloVetor;
    float xx, yy, zz, xy, xz, yz, xseno, yseno, zseno, umMenosCosseno;

    angulo = angulo*0.017453292519943295;

    seno = (float) sin(angulo);
    cosseno = (float) cos(angulo);


    moduloVetor = (float) sqrt( (x*x) + (y*y) + (z*z));
    if(moduloVetor == 0){
        glLoadMatrixf(matrixIdentity);
        return;
    }

    x = x/moduloVetor;
    y = y/moduloVetor;
    z = z/moduloVetor;

    xx = x*x;
    yy = y*y;
    zz = z*z;
    xy = x*y;
    xz = x*z;
    yz = y*z;
    xseno = x*seno;
    yseno = y*seno;
    zseno = z*seno;
    umMenosCosseno = 1.0f-cosseno;

    #define M(linha,coluna) m[(linha*4) + coluna]

    M(0,0) = (xx*umMenosCosseno) + cosseno;
    M(0,1) = (xy*umMenosCosseno) + zseno;
    M(0,2) = (xz*umMenosCosseno) - yseno;
    M(0,3) = 0.0f;
    M(1,0) = (xy*umMenosCosseno) - zseno;
    M(1,1) = (yy*umMenosCosseno) + cosseno;
    M(1,2) = (yz*umMenosCosseno) + xseno;
    M(1,3) = 0.0f;
    M(2,0) = (xz*umMenosCosseno) + yseno;
    M(2,1) = (yz*umMenosCosseno) - xseno;
    M(2,2) = (zz*umMenosCosseno) + cosseno;
    M(2,3) = 0.0f;
    M(3,0) = 0.0f;
    M(3,1) = 0.0f;
    M(3,2) = 0.0f;
    M(3,3) = 1.0f;

    #undef M
}

void renderScene(){
    static GLfloat angulo = 0.0f;
    float transformMatriz[16];

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    rotetionMatrix44(transformMatriz,angulo, 1.0f, 1.0f, 0.0f);
    transformMatriz[12] = 0.0f;
    transformMatriz[13] = 0.0f;
    transformMatriz[14] = -7.0f;

    glLoadMatrixf(transformMatriz);

    glColor3f(1.0f, 1.0f, 1.0f);
    glutWireCube(2.0);


    angulo += 1.0f;
    if(angulo >= 360.0f){
        angulo = 0;
    }

    glutSwapBuffers();
}

void reSize(int w, int h){
    double aspectRatio;
    float canvasSize = 100.0f;

    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    aspectRatio = (double) w / (double) h;

    gluPerspective(65.0, aspectRatio, 1.0, canvasSize);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void timerFunction(int val){
    glutPostRedisplay();
    glutTimerFunc(10,timerFunction,0);
}

void setup(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glEnable(GL_DEPTH_TEST);
}

int main(int argc, char **argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GL_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutCreateWindow("Matriz Rotacao");
    glutDisplayFunc(renderScene);
    glutReshapeFunc(reSize);
    glutTimerFunc(10,timerFunction,0);

    setup();

    glutMainLoop();


    return 0;
}
