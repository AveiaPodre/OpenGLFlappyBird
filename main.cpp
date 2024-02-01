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
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include "Object.cpp"
#include "LinkedList.cpp"

float xPlayer = -3.5;
float yPlayer = 0;
float zPlayer = 0;

float gravity = 0.0015f;
float jumpStrength = 0.05f;

void init(void);
void keyboard (unsigned char key, int x, int y);
void display(void);
void reshape (int w, int h);
void update(int value);
float randomNumber(float min, float max);

Player player = Player::Player(xPlayer, yPlayer, zPlayer, false);
LinkedList<Pipe> pipeList;

int main(int argc, char** argv) {
	// Inicializa a semente para a função rand() usando o tempo atual
    std::srand(static_cast<unsigned int>(std::time(NULL)));
	
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glEnable(GL_DEPTH_TEST);
    glutInitWindowSize(1200, 675);
    glutInitWindowPosition(50, 0);
    glutCreateWindow("Flappy Bird 3D");
    
    pipeList.enqueue(Pipe(4, randomNumber(-2.0, 2.0), 0, 1.8));
    pipeList.enqueue(Pipe(8, randomNumber(-2.0, 2.0), 0, 1.8));
    pipeList.enqueue(Pipe(12, randomNumber(-2.0, 2.0), 0, 1.8));

	// Funções de Callback
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutTimerFunc(25, update, 0);

    init();
    glutMainLoop();
    return 0;
}

void init(void){
    glClearColor(0.19f, 0.75f, 0.87f, 1.0);
}

void reshape (int w, int h){
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	
	// Define a matriz de projeção
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluPerspective(45.0f, (float)w / (float)h, 1.0f, 100.0f);
    gluPerspective(30, (float)w/(float)h , 5.0, 100.0); //(angulo, aspecto, ponto_proximo, ponto distante)
    gluLookAt(-8.0,1.0,7.0,  // posicao da camera (olho)
              0.0,0.0,0.0,  // direcao da camera (geralmente para centro da cena)
              0.0,1.0,0.0); // sentido ou orientacao da camera (de cabeca para cima)

    // Define a matriz de modelo e visualização
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	
}

void keyboard (unsigned char key, int x, int y){
	switch (key) {
        case 32: // Espaço
            player.setIsJumping(true);
            jumpStrength = 0.04f;
            break;
        case 27: // Esc
            exit(0);
            break;
    }
}

void drawBackground(){
	glPushMatrix();
	glTranslatef(0.0, 0.0, -10.0);
	glColor3f(0.19f, 0.75f, 0.87f);
	glBegin(GL_QUADS);
	glVertex3f(-10.0f, -10.0f, 0.0f);
	glVertex3f(-10.0f, 10.0f, 0.0f);
	glVertex3f(10.0f, 10.0f, 0.0f);
	glVertex3f(10.0f, -10.0f, 0.0f);
	glEnd();
	glPopMatrix();
}

void display(void){
	// Apaga o video e o depth buffer, e reinicia a matriz
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Desenha o jogador e os obstáculos
	//drawBackground();
    player.drawPlayer();
	pipeList.drawList();
    //drawObstacle();

    glutSwapBuffers();
}

void update(int value) {
    // Atualiza a posição do jogador
    if (player.getIsJumping()) {
        player.setYCoord(player.getYCoord() + jumpStrength);
        jumpStrength -= gravity;
    }

    // Atualiza a tela
    glutPostRedisplay();
    glutTimerFunc(10, update, 0);
}

float randomNumber(float min, float max) {
    // Gera um número inteiro aleatório no intervalo [min, max]
    int range = static_cast<int>((max - min) * 1000.0f) + 1;
    int numeroInteiro = std::rand() % range + static_cast<int>(min * 1000.0f);

    // Converte o número inteiro para um número de ponto flutuante no intervalo [min, max]
    float numeroFloat = static_cast<float>(numeroInteiro) / 1000.0f;

    return numeroFloat;
}
