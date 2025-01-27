#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <class T>
class node
{
    public:
        T data;
        node *prev,*next;
        node()
        {
            prev = nullptr;
            next = nullptr;
        }
        node(T Data)
        {
            data = Data;
            prev = nullptr;
            next = nullptr;
        }
};

template <class T>
class doublelist
{
    private:
        node<T> *head,*tail;
        int size;
    public:
        doublelist() : head(nullptr), tail(nullptr), size(0) {}

        ~doublelist()
        {
            node<T> *current = head;
            while (current != nullptr)
            {
                node<T> *next = current->next;
                delete current;
                current = next;
            }
            
        }

        void insertAtFront(T val)
        {
            node<T> *newNode = new node<T>(val);
            if (head == nullptr)
            {
                head = tail = newNode;
            }
            else
            {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            size++;
        }

        void insertAtBack(T val)
        {
            node<T> *newNode = new node<T>(val)
            if (head == nullptr)
            {
                head = tail = newNode;
            }
            else
            {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            size++;
        }

        T removeFront()
        {
            if (head == nullptr)
            {
                std::cout << "error" << std::endl;
                exit(1);
            }
        }
        node<T> *temp = head;
        T val = temp->data;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr;
        }
        delete temp
        size--;
        return val;
        
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
