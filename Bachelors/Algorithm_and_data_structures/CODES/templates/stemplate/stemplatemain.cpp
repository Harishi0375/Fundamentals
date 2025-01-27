#include <iostream>
#include "stemplate.h"

int main() {
	Test<int> t(3);
	t.print();

    Test<double> a(3.5);
    a.print();

    Test<std::string> b("hello");
    b.print();

    return 0;
}