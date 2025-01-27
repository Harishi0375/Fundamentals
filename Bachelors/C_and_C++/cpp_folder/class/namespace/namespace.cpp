#include "namespace.h"
#include <iostream>

using namespace std;

namespace CPPCourse { // here I am providing the implementation for a class defined in the CPPCourse namespace
	FirstExample::FirstExample(const string& n) : name(n) 
	{
	}


	void FirstExample::print() const {
		cout << name << endl;
	}
}

int main() {

	using CPPCourse::FirstExample;	// here I am out of the namespace and 
									// I declare I will use just that class
	FirstExample a("rt");           // thanks to the former line, no complete 
									// name is required

    FirstExample b(a); //copy 

	a.print();
    b.print();
	return 0;
 }