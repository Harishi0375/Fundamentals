#include <iostream>

using namespace std;

class One
{
	private:
		int x;
	public:
		One()
		{
			x = 0;
			cout << "Empty constructor One" << endl;
		}
		One(int nx)
		{
			x = nx;
			cout << "Constructor One" << endl;
		}
		One(const One& o)
		{
			x = o.x;
			cout << "Copy constructor One" << endl;
		}
};

class Two
{
	private:
		One o;
		double y;
	public:
		//either this way
		Two(One no, double ny): o(no), y(ny)
		{
			cout << "Constructor Two" << endl;
		
		}

		//or this way
		Two(One no, double ny): o(no)
		{
			y = ny;
			cout << "Constructor Two" << endl;
		}

		//or this one
		Two(One no, double ny)
		{
			o = One(no);
			y = ny;
			cout << "Constructor Two" << endl;
		}
};

int main()
{
	One obj1(4);
	Two obj2(obj1, 1.7);
	return 0;
}