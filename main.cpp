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
#include "Object.cpp"
#include "LinkedList.cpp"
#include "glut_text.h"

float xPlayer = -3.5;
float yPlayer = 0;
float zPlayer = 0;

float xEP = xPlayer;
float xDP = xPlayer + 0.4;

float gravity = 0.0015f;
float jumpStrength = 0.05f;
float decremento = -0.02f;

int score = 0;
bool gameOver = false;

void init(void);
void keyboard (unsigned char key, int x, int y);
void display(void);
void reshape (int w, int h);
void update(int value);

Player player = Player::Player(xPlayer, yPlayer, zPlayer, false);
LinkedList<Pipe> pipeList();
Pipe pipe1 = Pipe::Pipe(400, 0, 0, 100);
Pipe pipe2 = Pipe::Pipe(500, 0, 0, 200);
Pipe pipe3 = Pipe::Pipe(600, 0, 0, 50);

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glEnable(GL_DEPTH_TEST);
    glutInitWindowSize(1200, 675);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Flappy Bird 3D");
    
<<<<<<< Updated upstream
    //pipeList.enqueue(pipe1);
    //pipeList.enqueue(pipe2);
    //pipeList.enqueue(pipe3);
=======
    pipeList.enqueue(Pipe(0, randomNumber(-2.0, 2.0), 0, 1.8));
    pipeList.enqueue(Pipe(4, randomNumber(-2.0, 2.0), 0, 1.8));
    pipeList.enqueue(Pipe(8, randomNumber(-2.0, 2.0), 0, 1.8));
>>>>>>> Stashed changes

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
<<<<<<< Updated upstream
    gluPerspective(30, (float)w/(float)h , 5.0, 100.0); //(angulo, aspecto, ponto_proximo, ponto distante)
    gluLookAt(0.0,3.0,10.0,  // posicao da camera (olho)
=======
    gluPerspective(30, (float)w/(float)h , 5.0, 50.0); //(angulo, aspecto, ponto_proximo, ponto distante)
    gluLookAt(0.0,1.0,9.0,  // posicao da camera (olho)
>>>>>>> Stashed changes
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
	if (gameOver){
		std::cout << "Game Over!" << std::endl;
	    exit(0);
	}
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Desenha o jogador e os obstáculos
	//drawBackground();
    player.drawPlayer();
<<<<<<< Updated upstream

=======
	pipeList.drawList(decremento);
>>>>>>> Stashed changes
    //drawObstacle();

    glutSwapBuffers();
}

void update(int value) {
    // Atualiza a posição do jogador
    if (player.getIsJumping()) {
        player.setYCoord(player.getYCoord() + jumpStrength);
        jumpStrength -= gravity;
        
        if (player.getYCoord() < -4.5f || player.getYCoord() > 4.5f){
			gameOver = true;
		}
        
        LinkedList<Pipe>::Iterator it = pipeList.begin();
	    LinkedList<Pipe>::Iterator end = pipeList.end();
	    for (; it != end; ++it) {
	        Pipe& pipe = *it; 
	        // Faça algo com o item, por exemplo, desenhe
	        pipe.setXCoord(pipe.getXCoord()+decremento);
	        if (pipe.getXCoord() < -4.0f){
				pipeList.dequeue(pipe);
				pipeList.enqueue(Pipe(8, randomNumber(-2.0, 2.0), 0, 1.6));
				score++;
			}
			if (xEP <= (pipe.getXCoord()+1.0) && xDP >= pipe.getXCoord()){
				if ((player.getYCoord() <= pipe.getYCoord()-0.8) || (player.getYCoord()+0.4) >= pipe.getYCoord()+ 0.8){
					gameOver = true;
				}
			}
	    }
    }

    // Atualiza a tela
    glutPostRedisplay();
    glutTimerFunc(10, update, 0);
}
