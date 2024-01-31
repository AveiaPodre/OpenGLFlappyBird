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
};

class Pipe : public Object {
public:
    Pipe() : Object() {}

    Pipe(float x, float y, float z) : Object(x, y, z) {}

private:
	
};

template <typename Item>
class LinkedList {
private:
    class Node {
    public:
        Item data;
        Node* next;

        Node(const Item& item) : data(item), next(NULL) {}
    };

    Node* head;

public:
    LinkedList() : head(NULL) {}

    ~LinkedList() {
        clear();
    }

    void enqueue(const Item& item) {
        Node* newNode = new Node(item);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    bool dequeue(Item& item) {
        if (!head) {
            return false;
        }

        Node* temp = head;
        item = temp->data;
        head = head->next;
        delete temp;

        return true;
    }

    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void display() const {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};