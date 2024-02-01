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

class Object{
private:
    float xCoord;  
    float yCoord;  
    float zCoord; 
    
public:
    Object() : xCoord(0.0f), yCoord(0.0f), zCoord(0.0f) {}

    Object(float x, float y, float z) : xCoord(x), yCoord(y), zCoord(z) {}
    
    float getXCoord() const {
        return xCoord;
    }

    float getYCoord() const {
        return yCoord;
    }

    float getZCoord() const {
        return zCoord;
    }

    void setXCoord(float x) {
        xCoord = x;
    }

    void setYCoord(float y) {
        yCoord = y;
    }

    void setZCoord(float z) {
        zCoord = z;
    }
};

class Player : public Object {
private:
    bool isJumping;

public:
    Player() : Object(), isJumping(false) {}

    Player(float x, float y, float z, bool jumping) : Object(x, y, z), isJumping(jumping) {}

    bool getIsJumping() const {
        return isJumping;
    }

    void setIsJumping(bool jumping) {
        isJumping = jumping;
    }
 	
 	void drawPlayer(){
 		glPushMatrix();
		glTranslatef(getXCoord(), getYCoord(), getZCoord());
		glColor3f(1.0f, 0.0f, 0.0f);
	    glutSolidCube(0.5f);
	    glPopMatrix();
	}
    
};

class Pipe : public Object {
private:
	float gap;
	
public:
    Pipe() : Object() {}

    Pipe(float x, float y, float z, float hole) : Object(x, y, z), gap(hole) {}


};