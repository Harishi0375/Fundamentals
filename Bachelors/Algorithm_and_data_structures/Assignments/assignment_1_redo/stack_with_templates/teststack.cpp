#include "stack.h"


int main()
{
    stack<int>stack1;
    
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    std::cout << stack1.getNumEntries() << std::endl;

    stack<float,11>stack2;
    stack2.push(12.3);
    stack2.push(12.4);
    stack2.push(12.5);
    
    



    return 0;
}
