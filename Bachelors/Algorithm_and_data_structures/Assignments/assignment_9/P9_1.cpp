#include <iostream>

template<typename T,int defaultsize = 10>
class Stack
{
    private:
        struct StackNode 
        {
            T data;
            StackNode* next;
        };

        StackNode* top;
        int size;
        int current_size;

    public:
        Stack(int new_size);
        Stack();
        ~Stack();

        void push(T x);
        T pop();
        bool isEmpty() const;
        bool isFull() const;
};

template<typename T,int defaultsize>
Stack<T,defaultsize>::Stack(int new_size)
{
    size = new_size;
    current_size = 0;
    top = nullptr;
}

template<typename T,int defaultsize>
Stack<T,defaultsize>::Stack()
{
    size = defaultsize;
    current_size = 0;
    top = nullptr;
}

template<typename T,int defaultsize>
Stack<T,defaultsize>::~Stack()
{
    while (!isEmpty())
    {
        pop();
    }
}

template<typename T,int defaultsize>
void Stack<T,defaultsize>::push(T x)
{
    if(isFull())
    {
        throw std::overflow_error("stack overflow");
    }
    StackNode* newNode = new StackNode();
    newNode->data = x;
    newNode->next = top;
    top = newNode;
    ++current_size;
}

template<typename T,int defaultsize>
T Stack<T,defaultsize>::pop()
{
    if(isEmpty())
    {
        throw std::underflow_error("stack underflow");
    }
    StackNode* Temp = top;
    T poppedvalue = top->data;
    top = top->next;
    delete Temp;
    --current_size;
    return poppedvalue;
}

template<typename T,int defaultsize>
bool Stack<T,defaultsize>::isEmpty() const
{
    return current_size == 0;
}

template<typename T,int defaultsize>
bool Stack<T,defaultsize>::isFull() const
{
    return current_size == size;
}


int main()
{
    Stack<int> stack1(5); //custom size;
    Stack<int> stack2; //default

    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);
    stack1.push(5);
    // stack1.push(6);

    for (int i = 10; i > 0; --i)
    {
        stack2.push(i);
    }

    std::cout << stack2.pop() << std::endl;
    

    return 0;
}





