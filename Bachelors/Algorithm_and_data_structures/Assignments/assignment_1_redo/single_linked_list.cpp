#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T data) : data(data), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        Node<T>* current = head;
        Node<T>* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
    }

    void insertAtFront(T data) {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    bool deleteNode(T data) {
        if (head == nullptr) return false;

        if (head->data == data) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            return true;
        }

        Node<T>* current = head;
        while (current->next != nullptr && current->next->data != data) {
            current = current->next;
        }

        if (current->next == nullptr) return false;

        Node<T>* temp = current->next;
        current->next = current->next->next;
        delete temp;
        return true;
    }

    void display() const {
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
};

int main() {
    LinkedList<int> list;

    list.insertAtFront(10);
    list.insertAtFront(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    cout << "List after inserting 20, 10, 30, 40:" << endl;
    list.display();

    list.deleteNode(20);
    cout << "List after deleting 20:" << endl;
    list.display();

    list.deleteNode(40);
    cout << "List after deleting 40:" << endl;
    list.display();

    return 0;
}
