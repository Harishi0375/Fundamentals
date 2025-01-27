/*
  CH-230-A
  a12_p5.cpp
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

public:
    int gcd(int a, int b) const;		// calculates the gcd of a and b
	int lcm(int a, int b) const;

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
        Fraction temp;
        temp.num = this->num * other.num;
        temp.den = this->den * other.den;
        
        return temp; 
    }

    Fraction operator/(const Fraction &other) const
    {
        if (other.num != 0 && other.den != 0)
        {
            Fraction temp;
            temp.num = this->num * other.den;
            temp.den = this->den * other.num;
            return temp; 
        }
        return 0; //incase invalid input
    }

    Fraction operator+(const Fraction &other) const
    {
        Fraction temp;
        int commonDenominator = lcm(this->den,other.den);
        temp.num = (this->num * (commonDenominator / this->den)) + (other.num * (commonDenominator / other.den));
        temp.den = commonDenominator;
        return temp;
    }

    Fraction operator-(const Fraction &other) const
    {
        Fraction result;
        int commonDenominator = lcm(this->den, other.den);
        result.num = (this->num * (commonDenominator / this->den)) - (other.num * (commonDenominator / other.den));
        result.den = commonDenominator;
        return result;
    }

    bool operator<(const Fraction &other) const
    {
        int commonDenominator = lcm(this->den, other.den);
        return (this->num * (commonDenominator / this->den)) < (other.num * (commonDenominator / other.den));
    }

    bool operator>(const Fraction &other) const
    {
        int commonDenominator = lcm(this->den, other.den);
        return (this->num * (commonDenominator / this->den)) > (other.num * (commonDenominator / other.den));
    }

    Fraction& operator=(const Fraction &other) 
    {
        if (this != &other) //used help from TA for this line -- thankyou :) --
        {
            int tmp_gcd = gcd(other.num, other.den);
            this->num = other.num / tmp_gcd;
            this->den = other.den / tmp_gcd;
        }
        return *this;
    }

};


#endif /* FRACTION_H_ */