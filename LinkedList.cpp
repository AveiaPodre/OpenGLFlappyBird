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

    void display() const {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};