#pragma once
#include "Polynomial.h"
using namespace std;

class Rational
{
private:
    Polynomial numerator;
    Polynomial denominator;

public:
    Rational();
    Rational(const Polynomial& num, const Polynomial& denom);

    const Polynomial& getNom() const;
    const Polynomial& getDenom() const;
    friend std::ostream& operator<<(std::ostream& , const Rational&  ) ;	
    void print() const;
    Rational operator+( Rational& other) ;
    Rational operator*( Rational& other);
    
};
