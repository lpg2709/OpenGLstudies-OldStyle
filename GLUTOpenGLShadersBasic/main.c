#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>


static unsigned int compileShader(const char *source, unsigned int type){
    unsigned int id = glCreateShader(type);
    glShaderSource(id, 1, &source, NULL);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if(result == GL_FALSE){
        int lenght;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &lenght);

        char *mensage = (char*) malloc(lenght*sizeof(char));

        glGetShaderInfoLog(id, lenght, &lenght, mensage);
        printf("Fail to compile ");

        if(type == GL_VERTEX_SHADER){
            printf("vertex\n");
        }else{
            printf("fragment\n");
        }

        printf("%s", mensage);
        glDeleteShader(id);
        return 0;
    }

    return id;
}

static unsigned int CreateShader(const char *vertexShader, const char *fragmentShader){
    unsigned int program = glCreateProgram();
    unsigned int vs = compileShader(vertexShader, GL_VERTEX_SHADER);
    unsigned int fs = compileShader(fragmentShader, GL_FRAGMENT_SHADER);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDetachShader(program,vs);
    glDetachShader(program,fs);

    return program;
}

void renderScene(){
    glClear(GL_COLOR_BUFFER_BIT);

    glDrawArrays(GL_TRIANGLES,0,3);

    glutSwapBuffers();
}

void setup(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0);

    float position[6] ={
        -0.5,-0.5,
         0.0, 0.5,
         0.5,-0.5
    };

    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER,6*sizeof(float), position, GL_STATIC_DRAW);


    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT,GL_FALSE,2*sizeof(float),0);

    char *vertexShader = {
        "#version 330 core\n"
        "\n"
        "layout(location = 0) in vec4 position;"
        "\n"
        "void main(){\n"
        "   gl_Position = position;\n"
        "}\n"
    };

    char *fragmentShader = {
        "#version 330 core\n"
        "\n"
        "layout(location = 0) out vec4 color;"
        "\n"
        "void main(){\n"
        "   color = vec4(1.0, 0.0, 0.0, 1.0);\n"
        "}\n"
    };
    unsigned int shader = CreateShader(vertexShader,fragmentShader);
    glUseProgram(shader);

}


int main(int argc, char **argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(600,600);
    glutCreateWindow("OpenGL Shaders Basic");
    glutDisplayFunc(renderScene);
    glewInit();

    setup();

    glutMainLoop();

    return 0;
}
