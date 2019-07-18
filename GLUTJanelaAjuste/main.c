#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void render(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);
    glRectf(-25.0f, 25.0f, 25.0f, -25.0f);

    glFlush();

}

void ajustTela(int w, int h){
    GLfloat aspectRatio;

    if(h == 0){
        h = 1;
    }
    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    aspectRatio = (float) w / (float) h;

    if(w >= h){
        glOrtho(-100 * aspectRatio, 100 * aspectRatio, -100, 100, -1.0, 1.0);
    }else{
        glOrtho(-100, 100, -100 / aspectRatio, 100 / aspectRatio, -1.0, 1.0);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


}

void startup(){
    glClearColor( 0.0f, 0.0f, 1.0f ,1.0f);
}

int main(int argc, char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Janela com Reajuste");
    glutDisplayFunc(render);
    glutReshapeFunc(ajustTela);

    startup();

    glutMainLoop();


    return 0;
}
