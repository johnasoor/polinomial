#pragma once
#include <vector>
#include <iostream>

class Polynomial
{
private:
	static int MaxDegree;
	std::vector<double> coefficientArray;


public:
	int static getMaxDegree();
	void print()const;
	void setCoeff(int degree, double coeff);
	Polynomial();
	Polynomial(int degree);
	Polynomial(double coeffArr[], int index);
	double getCoeff(int index) const;
	int getDegree(bool ignoreLeadingZeros) const;
	friend std::ostream& operator<<(std::ostream& , const Polynomial& ) ;	
	Polynomial operator=(const Polynomial& other);
    friend Polynomial operator*(double scalar,  Polynomial& polynomial);
    Polynomial operator*( Polynomial& other);
    Polynomial operator-(const Polynomial& other) const;
    Polynomial(const Polynomial& other);
    Polynomial operator+(const Polynomial& other);
    Polynomial operator+(double scalar);
    const double operator[](int index) const;
    Polynomial operator*(double scalar);

};
