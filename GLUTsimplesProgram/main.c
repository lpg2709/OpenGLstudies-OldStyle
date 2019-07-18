#include <GL/glut.h>   // -lglut
#include <GL/glu.h>    // -lGLU
#include <GL/gl.h>     // -lGL

void render(){

	glClear(GL_COLOR_BUFFER_BIT);

	glFlush();

}

void setuprender(){

	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

}

int main(int argc, char **argv){

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Simples");
	glutDisplayFunc(render);
	setuprender();
	glutMainLoop();

	return 0;


}
