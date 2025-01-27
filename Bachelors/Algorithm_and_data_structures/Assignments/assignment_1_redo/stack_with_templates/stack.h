#ifndef STACK_H
#define STACK_H

#include <iostream> 

template <typename T, int initialsize = 10>
class stack
{
private:
    int size, where;
    T *ptr;
    void extend();

public:
    stack();
    stack(const stack& other);
    stack(int sizeT);
    bool push(T elementT);
    bool pop(T& outT);
    T back() const;
    int getNumEntries() const;
    ~stack();
};

template <typename T, int initialsize>
stack<T, initialsize>::stack()
{
    ptr = new T[initialsize];
    size = initialsize;
    where = -1;
}

template <typename T, int initialsize>
stack<T, initialsize>::stack(const stack& obj)
{
    size = obj.size;
    where = obj.where;
    ptr = new T[size];
    for (int i = 0; i <= where; ++i)
    {
        ptr[i] = obj.ptr[i];
    }
}

template <typename T, int initialsize>
stack<T, initialsize>::stack(int sizeT)
{
    size = sizeT;
    ptr = new T[size];
    where = -1;
}

template <typename T, int initialsize>
bool stack<T, initialsize>::push(T elementT)
{
    if (where < size - 1)
    {
        ptr[++where] = elementT;
        std::cout << "added" << std::endl;
        return true;
    }
    else
    {
        std::cout << "The stack is full. Extending the stack." << std::endl;
        extend();
        return push(elementT); // Try to push again after extending
    }
}

template <typename T, int initialsize>
void stack<T, initialsize>::extend()
{
    int newsize = size * 2; // Typically double the size
    T *newptr = new T[newsize];

    for (int i = 0; i <= where; ++i)
    {
        newptr[i] = ptr[i];
    }

    delete[] ptr;
    ptr = newptr;
    size = newsize;
    std::cout << "New stack created successfully." << std::endl;
}

template <typename T, int initialsize>
bool stack<T, initialsize>::pop(T& outT)
{
    if (where >= 0)
    {
        outT = ptr[where--];
        return true;
    }
    return false;
}

template <typename T, int initialsize>
T stack<T, initialsize>::back() const
{
    if (where >= 0)
    {
        return ptr[where];
    }
    throw std::out_of_range("Stack is empty");
}

template <typename T, int initialsize>
int stack<T, initialsize>::getNumEntries() const
{
    return where + 1;
}

template <typename T, int initialsize>
stack<T, initialsize>::~stack()
{
    delete[] ptr;
}

#endif
