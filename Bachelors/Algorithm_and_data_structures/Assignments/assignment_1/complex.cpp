#include <iostream>

template <typename T>
int array_search(T arr[],T val,int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == val)
            return i; //index starts from 0 
    }
    return -1;
    
}

using namespace std;

class Complex //complex used from prev ex
{
    private:
        double re,im;
    public:
        Complex(double re,double im)
        {
            this->re =re;
            this->im =im;
        }

        bool operator==(const Complex &obj)
        {
            return (re == obj.re) && (im == obj.im) ;
        }

        Complex operator+(const Complex &obj)
        {
            return Complex(this->re + obj.re,this->im + obj.im);
        }

        friend ostream& operator<<(ostream &obj, const Complex &c)
        {
            cout << c.re << "+" << c.im << "i" << endl;
            return obj;
        }

};

// template class array_search<int>;
// template class array_search<Complex>;

int main(int argc, char** argv)
{
    int intarr[] = {1,2,3,4,5,6};
    cout << array_search<int>(intarr,4,6) << endl;

    Complex arr[] = {Complex(1,2),Complex(3,4),Complex(5,6)};
    cout << array_search<Complex>(arr,Complex(3,4),3) << endl;

    return 0;
}