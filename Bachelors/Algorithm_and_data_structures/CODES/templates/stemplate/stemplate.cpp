#include <iostream>
#include "stemplate.h"

template <class T>
Test<T>::Test(T p) {
	prop = p;
}

template <class T>
void Test<T>::print() {
	std::cout << prop << std::endl;
}

// Solution 2: instantiate the class with needed types

//we write this because there are 3 different files 
template class Test<int>;
template class Test<double>; //i had to add this inorder to work 

template class Test<std::string>;