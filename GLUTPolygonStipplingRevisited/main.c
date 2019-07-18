#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#define PI 3.1415f

GLubyte fire[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                   0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x01, 0xf0,
                   0x00, 0x00, 0x07, 0xf0, 0x0f, 0x00, 0x1f, 0xe0,
                   0x1f, 0x80, 0x1f, 0xc0, 0x0f, 0xc0, 0x3f, 0x80,
                   0x07, 0xe0, 0x7e, 0x00, 0x03, 0xf0, 0xff, 0x80,
                   0x03, 0xf5, 0xff, 0xe0, 0x07, 0xfd, 0xff, 0xf8,
                   0x1f, 0xfc, 0xff, 0xe8, 0xff, 0xe3, 0xbf, 0x70,
                   0xde, 0x80, 0xb7, 0x00, 0x71, 0x10, 0x4a, 0x80,
                   0x03, 0x10, 0x4e, 0x40, 0x02, 0x88, 0x8c, 0x20,
                   0x05, 0x05, 0x04, 0x40, 0x02, 0x82, 0x14, 0x40,
                   0x02, 0x40, 0x10, 0x80, 0x02, 0x64, 0x1a, 0x80,
                   0x00, 0x92, 0x29, 0x00, 0x00, 0xb0, 0x48, 0x00,
                   0x00, 0xc8, 0x90, 0x00, 0x00, 0x85, 0x10, 0x00,
                   0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00 };

void render(){

    GLfloat x, y, angulo;
    int cor = 1;

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);
        glVertex2f(-20.0f, 50.0f);
        glVertex2f(20.0f, 50.0f);
        glVertex2f(50.0f, 20.0f);
        glVertex2f(50.0f, -20.0f);
        glVertex2f(20.0f, -50.0f);
        glVertex2f(-20.0f, -50.0f);
        glVertex2f(-50.0f, -20.0f);
        glVertex2f(-50.0f, 20.0f);
    glEnd();


    glutSwapBuffers();
}
void setup(){
    glClearColor( 0.0f, 0.0f, 0.0f, 1.0f);

    glColor3f(1.0f, 0.0f, 0.0f);

    glEnable(GL_POLYGON_STIPPLE);

    glPolygonStipple(fire);
}

void ajustaTam(int w, int h){
    GLfloat aspectRatio;
    GLfloat canvasSize = 100;
    if(h == 0){
        h = 1;
    }

    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    aspectRatio = (float)w / (float) h;
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
    glutInitWindowPosition((GLUT_SCREEN_WIDTH-800)/2,(GLUT_SCREEN_HEIGHT-600)/2);
    glutInitWindowSize(600,600);
    glutCreateWindow("Teste");
    glutDisplayFunc(render);
    glutReshapeFunc(ajustaTam);

    setup();

    glutMainLoop();

    return 0;
}

