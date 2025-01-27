#include <iostream>
#include "LinkedList.h"

template <typename T>
Node<T>::Node(T item) {
    this->item = item;
    this->prev = nullptr;
    this->next = nullptr;
}

template <typename T>
LinkedList<T>::LinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList& l) {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
    Node<T>* temp = l.head;
    while (temp != nullptr) {
        pushBack(temp->data);
        temp = temp->next;
    }
}

template <typename T>
LinkedList<T>::~LinkedList() {
    while (head != nullptr) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
T LinkedList<T>::getFirstLoss() {
    if (head == nullptr) {
        return T();
    }
    T item = head->item;
    Node<T> *temp = head;
    head = head->next;
    delete temp;
    this->size--;
    return item;
}

template <typename T>
T LinkedList<T>::getLestLoss() {
    if (this->tail == nullptr) {
        return T();
    }
    T item = tail->item;
    Node<T> *temp = tail;
    tail = tail->prev;
    delete temp;
    this->size--;
    return item;
}

template <typename T>
T LinkedList<T>::getFirst() const {
    if (head == nullptr) {
        return T();
    }
    return head->item;
}

template <typename T>
T LinkedList<T>::getLast() const{
    if (tail == nullptr) {
        return T();
    }
    return tail->item;
}

template <typename T>
bool LinkedList<T>::pushFront(const T& item) {
    Node<T> *temp = new Node<T>(item, nullptr, head);
    if (head == nullptr) {
        tail = temp;
    } else {
        head->prev = temp;
    }
    head = temp;
    this->size++;
    return true;
}

template <typename T>
bool LinkedList<T>::pushBack(const T& item) {
    Node<T> *temp = new Node<T>(item, tail, nullptr);
    if (tail == nullptr) {
        this->head = temp;
    } else {
        this->tail->next = temp;
    }
    this->tail = temp;
    this->size++;
    return true;
}

template <typename T>
int LinkedList<T>::getAmount() const { return this->size; }

int main() {


    LinkedList<int> l;
    l.pushFront(1);
    l.pushFront(2);
    l.pushFront(3);
    l.pushFront(4);
    l.pushFront(5);

    // teting the results
    std::cout << l.getAmount() << std::endl;
    std::cout << l.getFirst() << std::endl;
    std::cout << l.getLast() << std::endl;
    std::cout << l.getFirstLoss() << std::endl;
    std::cout << l.getLestLoss() << std::endl;
    std::cout << l.getAmount() << std::endl;

    return 0;
}