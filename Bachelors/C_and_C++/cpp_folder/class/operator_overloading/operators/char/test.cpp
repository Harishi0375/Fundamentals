#include "charbuffer.h"

#include <iostream>

int main()
{
    Charbuffer b1,b2,b3;
    b2 = b3;
    b3 = b1;

    b3 = b2 = b1; // this is same as b3.(operator) = (b2.operator=(b1));
                  //this is not correct hence to make this work the reference is used (Charbuffer& operator=(const Charbuffer&); )
                  //and thats why the return type is (return *this;)
}