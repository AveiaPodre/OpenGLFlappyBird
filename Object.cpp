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
public:
    Object(const std::vector<float>& vertices, float x, float y, float z)
        : vertices(vertices), xCoord(x), yCoord(y), zCoord(z) {}

    void draw() {
        glPushMatrix();  
        glTranslatef(xCoord, yCoord, zCoord);  

        glBegin(GL_TRIANGLES);
        for (size_t i = 0; i < vertices.size(); i += 3) {
            glVertex3f(vertices[i], vertices[i + 1], vertices[i + 2]);
        }
        glEnd();

        glPopMatrix(); 
    }

private:
    std::vector<float> vertices;  
    float xCoord;  
    float yCoord;  
    float zCoord; 
};

class Player : public Object {
public:
    Player(const std::vector<float>& vertices, float x, float y, float z, float speed, float strength)
        : Object(vertices, x, y, z), playerSpeed(speed), jumpStrength(strength) {}

private:
    float playerSpeed;
    float jumpStrength;
    bool isJumping = false;
};