#ifndef HEADERFILE_H
#define HEADERFILE_H

#include <iostream> 

template<class T,int initializesize = 10>
class Stack{
    private:
        T *ptr;
        int size,where;
    public:
        Stack(){
            size = initializesize;
            ptr = new T[size];
            where = -1;
        }

        Stack(const Stack &obj) {
            size = obj.size;
            ptr = new T[size];
            where = obj.where;
            for (int i = 0; i < size; i++)
            {
                ptr[i] = obj.ptr[i];
            }  
        }

        Stack(int size){
            this->size = size;
            ptr = new T[size];
            where = -1;
        }

        ~Stack(){
            delete[] ptr;
        }

        bool push(T element){
            if(where == size - 1){
                return false;
            }
            ptr[++where] = element;
            return true;
        }

        bool pop(T &out){
            if(where == -1){
                return false;
            }
            out = ptr[where--];
            return true;
        }

        T back() const{
            return ptr[where];
        } 

        int getNumEntries() const{
            return where + 1;
        }
};

//copied this syntax from geeksforgeeks 
//part of my notebook references

template<class T> 
class Node{ 
    public:
        T data;
        Node *prev;
        Node *next;

        Node(T val) : data(val), prev(nullptr), next(nullptr){}
};

template<class T>
class doublylinkedlist{
    private:
        Node<T> *head;
        Node<T> *tail;
        int size;
    public:
        doublylinkedlist() : head(nullptr) ,tail(nullptr), size(0) {}

        ~doublylinkedlist(){
            Node<T> *current = head;
            while(current !=nullptr){
                Node<T> *next = current->next;
                delete current;
                current = next;
            }
        }

        void insertAtFront(T val) {
            Node<T>* newNode = new Node<T>(val);
            if (head == nullptr) {
                head = tail = newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            size++;
        }

        void insertAtEnd(T val) {
            Node<T>* newNode = new Node<T>(val);
            if (head == nullptr) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            size++;
        }

        T removeFront() {
            if (head == nullptr) {
                std::cout << "error" << std::endl; 
                exit(1);
            }
            Node<T>* temp = head;
            T val = temp->data;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            } else {
                tail = nullptr; 
            }
            delete temp;
            size--;
            return val;
        }

        T removeEnd() {
            if (tail == nullptr) {
                std::cout << "error" << std::endl; 
                exit(1);
            }
            Node<T>* temp = tail;
            T val = temp->data;
            tail = tail->prev;
            if (tail != nullptr) {
                tail->next = nullptr;
            } else {
                head = nullptr; 
            }
            delete temp;
            size--;
            return val;
        }

        T getFirst() const {
            if (head == nullptr) {
                std::cout << "error" << std::endl;
                exit(1);
            }
            return head->data;
        }

        T getLast() const {
            if (tail == nullptr) {
                std::cout << "error" << std::endl;
                exit(1);
            }
            return tail->data;
        }

        int getSize() const {
            return size;
        }
};

#endif
