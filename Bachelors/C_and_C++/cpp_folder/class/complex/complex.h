class Complex {

private:  // internal implementation is hidden
	float real;  // real part
	float imag;  // imaginary part

public:
	Complex();                 // empty constructor
	Complex(float, float = 0); // constructor taking values for real and
							   // imaginary parts. Imaginary defaults to 0
	
    double magnitude();        // computes the magnitude of the number
	void print();              // prints it to the screen
};

