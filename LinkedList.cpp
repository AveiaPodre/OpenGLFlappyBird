#include <iostream>

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
    
    class Iterator {
    private:
        Node* current;

<<<<<<< Updated upstream
    void display() const {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
=======
    public:
        Iterator(Node* node) : current(node) {}

        Item& operator*() const {
            return current->data;
        }

        Iterator& operator++() {
            current = current->next;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };

    Iterator begin() const {
        return Iterator(head);
    }

    Iterator end() const {
        return Iterator(NULL);
    }

    void drawList(float decremento) const {
        Node* current = head;
        while (current) {
            current->data.drawPipe(decremento);
>>>>>>> Stashed changes
            current = current->next;
        }
        std::cout << std::endl;
    }
};