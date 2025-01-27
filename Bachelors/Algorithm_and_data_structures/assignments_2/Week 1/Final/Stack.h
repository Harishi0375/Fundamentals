
template <typename T>
class Stack {
public:
    Stack();
    Stack(int size);
    Stack(const Stack& s);
    ~Stack();

    bool push(T element);

    bool pop(T& out);
    
    T back(void);

    // since entries is index, the amount taken is index + 1
    int getNumEntries();

private:
    int size;
    int entries;
    T *stack;
};