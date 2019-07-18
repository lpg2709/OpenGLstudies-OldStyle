#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

char* readFile(const char *path){
    FILE *f = fopen(path, "rt");
    if(f == NULL){
        printf("Erro ao abrir arquivo");
        exit(1);
    }
    fseek(f, 0, SEEK_END);
    int tamArquivo = ftell(f);
    char *text = (char*) malloc(sizeof(char) * (tamArquivo+1));
    fseek(f, 0, SEEK_SET);
    memset(text,0,(tamArquivo + 1));
    fread(text, sizeof(char), (tamArquivo+1), f);

    fclose(f);

    return text;
}

static unsigned int compileShader(unsigned int type, const char *source){
    unsigned int shaderID = glCreateShader(type);
    glShaderSource(shaderID, 1, &source, NULL);
    glCompileShader(shaderID);

    return shaderID;
}

static unsigned int createrShader(const char *vertexShader, const char *fragmentShader){
    unsigned int programa = glCreateProgram();

    unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(programa, vs);
    glAttachShader(programa, fs);
    glLinkProgram(programa);
    glValidateProgram(programa);

    glDetachShader(programa, vs);
    glDetachShader(programa ,fs);

    return programa;

}



void renderScene(){
    glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);

    glutSwapBuffers();
}

void setUp(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    float vertexPosition[6] = {
            -0.5,-0.5,
             0.0, 0.5,
             0.5,-0.5
     };

    unsigned int bufferID;
    glCreateBuffers(1, &bufferID);
    glBindBuffer(GL_ARRAY_BUFFER, bufferID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6, vertexPosition, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof(float),0);

    char *vertexShader = readFile("vertexShader.shader");
    char *fragmentShader = readFile("freagmentShader.shader");

    unsigned int shader = createrShader(vertexShader, fragmentShader);
    glUseProgram(shader);

}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(600,600);
    glutCreateWindow("OpenGL Shader File");
    glutDisplayFunc(renderScene);
    glewInit();

    setUp();

    glutMainLoop();

    return 0;
}
