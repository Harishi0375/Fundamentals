#include <iostream>
#include <cstdlib>

using namespace std;

const int size = 100;

/* 
This class holds a vector of elements of type T, to be specified 
at declaration time 
*/
template <class T> 
class BoundedArray {
	private:
		T array[size];
	public:
		BoundedArray(){};
		T& operator[](int); // overloaded access operator
};

/* 
As the class holds a vector of elements of type T, the access operator 
will return a reference to T. This way it can be used both for reading 
and writing
*/
template<class T> 
T& BoundedArray<T>::operator[](int pos) {
	if ((pos < 0) || (pos >= size)) 
		exit(1);
	return array[pos];
}

/* 
Note that a function using a templatized class should be templatized as well 
*/
template<class T>
void printall(BoundedArray<T> top) {
	for (int i = 0; i < size; i++)
    	cout << top[i] << endl;
}

int main(int argc, char** argv) {

	// declares instances and plays with them
	BoundedArray<int> intarray;
	BoundedArray<const char*> chararray;

	for (int i = 0; i < size; i++)
    	intarray[i] = i * i;

	for (int i = 0; i < size; i++)
		chararray[i] = "";

	chararray[0] = "first";
	chararray[1] = "second";

	printall(intarray);
	printall(chararray);
}