/*
  CH-230-A
  a12_p4.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

// simple class for fractions

#ifndef FRACTION_H_
#define FRACTION_H_

class Fraction {

private:						// internal implementation is hidden
	int num;					// numerator
	int den;					// denominator

	int gcd(int a, int b);		// calculates the gcd of a and b
	int lcm(int a, int b);

public:
	Fraction();					// empty constructor
	Fraction(int, int = 1); 	// constructor taking values for fractions and
								// integers. Denominator by default is 1
	
    friend std::istream &operator>>(std::istream& in, Fraction& obj) //cin
    {

        std::cout << "Enter numerator part: ";
        in >> obj.num;

        std::cout << "Enter denominator part: ";
        in >> obj.den;

        return in;    
    }

    friend std::ostream &operator<<(std::ostream& out, const Fraction &obj) //cout
    {
        out << obj.num << "/" << obj.den << std::endl;
        return out; 
    }

    Fraction operator*(const Fraction &other) const
    {
        if (other.num != 0 || other.den != 0)
        {
            Fraction temp;
            temp.num = num * other.num;
            temp.den = den * other.den;
            return temp;
        }
        return 0; //easier to validate as per question 
    }

    Fraction operator/(const Fraction &other) const
    {
        if (other.num != 0)
        {
            Fraction temp;
            temp.num = num * other.num;
            temp.den = den * other.den;
            return temp; 
        }
        std::abort(); //program terminates when divided by 0
        
    }

    inline void setNum(const int n) {num = n;}
    const int getNum() {return num;}

    inline void setDen(const int d) {den = d;}
    const int getDen() {return den;}

};


#endif /* FRACTION_H_ */