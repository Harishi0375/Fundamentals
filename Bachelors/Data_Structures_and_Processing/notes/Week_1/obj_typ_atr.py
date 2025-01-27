x = 1 
dir(x)

x = 2
x.denominator # => 1

x.bit_length # => <built-in method bit_length of int object at 0x7f3bef6c0110>

x.bit_length()                  # => 2

x = 2
help(x.bit_length)

from fractions import Fraction

x = Fraction(2, 1)  # Creating a fraction with numerator 2 and denominator 1
print(x.denominator)  # This will output 1

x= 2
type(x) # => <class 'int'>

issubclass(cl1, cl2)            # => True when cl1 is a subclass of cl2, False otherwise.
