/*
    CH-231-A
    a1_p2.c
    Nikolay Tsonev
    nTsonev@jacobs-univeristy.de
*/

#include <iostream>
#include "Stack.h"

template <typename T>
Stack<T>::Stack() : size(10), entries(-1) {
    stack = new T[size];
}

template <typename T>
Stack<T>::Stack(int size) : size(size), entries(-1) {
    stack = new T[size];
}

template <typename T>
Stack<T>::Stack(const Stack& s) : size(s.size), entries(s.entries) {
    stack = new T[size];
    for (int i = 0; i < size; i++)
        stack[i] = s.stack[i];
}

template <typename T>
Stack<T>::~Stack() {
    delete[] stack;
}

template <typename T>
bool Stack<T>::push(T element) {
    // because entries is = index, the max index is size -1

    if (entries == size-1 || entries == size-1)
        return false;

    stack[entries] = element;
    entries++;

    return true;
}

template <typename T>
bool Stack<T>::pop(T& out) {
    // -1 corresponds to an empty stack
    if (entries == -1)
        return false;

    out = stack[entries];
    entries--;

    return true;
}

template <typename T>
T Stack<T>::back(void) {
    if (entries == -1)
        return stack[0];
    return stack[entries];
}

template <typename T>
int Stack<T>::getNumEntries() { return (entries+1); }


int main() {
    // creatuing a dummy stack
    Stack<int> s;
    s.push(3);
    s.push(4);
    s.push(5);

    // testing the results
    int poppy = 5;
    bool popped = s.pop(poppy);
    std::cout << "the pop is " << popped << std::endl;

    Stack<char> s2(5);

    for (int i = 0; i < 4; i++) 
        s2.push('2');

    bool pushed = s2.push('M');
    std::cout << "the push is " << pushed << std::endl;

    std::cout << s2.getNumEntries() << std::endl;

    return 0;
}