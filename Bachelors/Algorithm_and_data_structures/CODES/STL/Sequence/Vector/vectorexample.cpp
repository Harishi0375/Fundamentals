#include <vector>
#include <iostream>

const int size = 50;

using namespace std;

int main(int argc, char** argv)
{
	vector<int> vint(5, 111);		// a vector of ints. Default size is accepted
	vector<int> vint20(20); // another vector of ints. Its initial size is 20
	unsigned int i;

	for(i = 0; i < 50; i++)  // pushes 50 elements
		vint20.push_back(i);
	
	cout << "How many? " << vint20.size() << endl;
	cout << "Empty? " << vint20.empty() << endl;

	for (i = 0; i < vint20.size(); i++)	// uses the overloaded [] operator 
										// to access data
    	cout << vint20[i] << " ";

	vint20.clear();  // removes all elements
	cout << endl << "How many? " << vint20.size() << endl;
	cout << "Empty? " << vint20.empty() << endl;
  
  for (i = 0; i < vint.size(); i++)	// uses the overloaded [] operator 
										// to access data
    	cout << vint[i] << " ";
}