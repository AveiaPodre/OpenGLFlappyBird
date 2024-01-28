#ifdef __APPLE__
    #define GL_SILENCE_DEPRECATION
    #include <GLUT/glut.h>
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
#else
    #include <GL/glut.h>
    #include <GL/gl.h>
    #include <GL/glu.h>
#endif

#include <iostream>
#include <stdio.h>
#include "object.cpp"


void init(void);
void keyboard (unsigned char key, int x, int y);
void display(void);
void reshape (int w, int h);
void update(int value)

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Flappy Bird 3D");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutTimerFunc(25, update, 0);

    init();
    glutMainLoop();
    return 0;
}

void init(void){
    glClearColor (1.0, 1.0, 1.0, 1.0);
    glEnable(GL_DEPTH_TEST); 
}

void reshape (int w, int h){
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();

    glViewport (0, 0, (GLsizei) w, (GLsizei) h);

    gluPerspective(60, (float)w/(float)h , 1.0, 9.0); //(angulo, aspecto, ponto_proximo, ponto distante)
    gluLookAt(0.0,0.0,7.0,  // posicao da camera (olho)
              0.0,1.0,0.0,  // direcao da camera (geralmente para centro da cena)
              0.0,1.0,0.0); // sentido ou orientacao da camera (de cabeca para cima)

    glMatrixMode (GL_MODELVIEW);
}

void keyboard (unsigned char key, int x, int y){
	
}

void display(void){

}
