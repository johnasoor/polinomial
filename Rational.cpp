#include "Rational.h"
#include <iostream>

Rational::Rational() {}

Rational::Rational(const Polynomial& num, const Polynomial& denom) : numerator(num), denominator(denom) {}

const Polynomial& Rational::getNom() const {
	return numerator;
}

const Polynomial& Rational::getDenom() const {
	return denominator;
}

void Rational::print() const {

	if (numerator.getDegree(false) == 0)
	{
		cout << "polynomial = 0"<<endl;
	}
	else
	{
		numerator.print();
	}
	cout << "-----------------" << endl;
	if (denominator.getDegree(true) == 0)
	{
		cout << "polynomial = 1" << endl;
	}
	else
	{
		denominator.print();
	}
}



Rational Rational::operator+( Rational& other)  {
   
    Polynomial newNum = numerator * other.denominator + denominator * other.numerator;
    Polynomial newDenom = denominator * other.denominator;
    return Rational(newNum, newDenom);
}


Rational Rational::operator*( Rational& other)  {
  
    Polynomial newNum = numerator * other.numerator;
    Polynomial newDenom = denominator * other.denominator;
    return Rational(newNum, newDenom);
}
ostream& operator<<(std::ostream& out, const Rational& other)
    {
   other.print();
  return out;
    }
