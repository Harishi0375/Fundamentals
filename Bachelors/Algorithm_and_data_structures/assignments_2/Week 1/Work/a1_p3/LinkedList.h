//
// Created by Nikolay Tsonev on 13/02/2024.
//

#ifndef WEEK_1_LINKEDLIST_H
#define WEEK_1_LINKEDLIST_H

template <typename T>
class Node {
public:
    T item;
    Node<T> *next;
    Node<T> *prev;
    Node(T item);
};

template <typename T>
class LinkedList {
public:
    LinkedList();
    LinkedList(const LinkedList& l);
    ~LinkedList();
    T getFirstLoss();
    T getLestLoss();
    T getFirst() const;
    T getLast() const;
    bool pushFront(const T& item);
    bool pushBack(const T& item);
    int getAmount() const;
private:
    Node<T> head;
    Node<T> tail;
};


#endif //WEEK_1_LINKEDLIST_H
