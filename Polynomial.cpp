
השיחה נפתחה. הודעה אחת שלא נקראה.


דילוג לתוכן
שימוש ב-Gmail עם קוראי מסך

1 מתוך 5,538
Fwd: מטלה 2
דואר נכנס

ג'ון עשור <johnasoor@gmail.com‏>
קבצים מצורפים
16:25 ‎(לפני 0 דקות)‎
אני

   
תרגום הודעה
השבתה עבור: אנגלית

---------- Forwarded message ---------
מאת: ג'ון עשור <johnasoor@gmail.com>
‪Date: יום ג׳, 22 באוג׳ 2023, 15:34‬
‪Subject: מטלה 2‬
To: <yanapro@outlook.co.il>




5
 קבצים מצורפים
  •  נסרקו על ידי Gmail
#include <iostream>
#include "Polynomial.h"

using namespace std;

int Polynomial::MaxDegree = 0;


Polynomial::Polynomial()
{
	coefficientArray.push_back(0.0);


}

Polynomial::Polynomial(int degree)
{
	coefficientArray.assign(degree + 1, 0.0);
	for (int i = 0; i < coefficientArray.size(); i++)
	{
		if (coefficientArray[i] != 0)
		{
			MaxDegree = i;
		}
	}

}

Polynomial::Polynomial(double coeffArr[], int degree)
{


	coefficientArray.assign(degree + 1, 0.0);

	for (int i = 0; i < degree + 1; i++)
	{
		coefficientArray[i] = coeffArr[i];
	}

	int CurrObjectDegree = 0;
	for (int i = 0; i < coefficientArray.size(); i++)
	{
		if (coefficientArray[i] != 0)
		{
			CurrObjectDegree = i;
		}
	}
	if (CurrObjectDegree > MaxDegree)
	{
		MaxDegree = CurrObjectDegree;

	}
	
}

int Polynomial::getDegree(bool ignoreLeadingZeros) const
{
	if (!ignoreLeadingZeros)
	{
		return coefficientArray.size() - 1;
	}
	else
	{
		int size = coefficientArray.size();
		int maxIndex = 0;
		for (int i = 0; i < size; i++)
		{
			if (coefficientArray[i] != 0)
			{
				maxIndex = i;
			}
		}
		return maxIndex;
	}
}

double Polynomial::getCoeff(int index) const {
    int size = coefficientArray.size();
	if (index >= 0 && index < size)
		return coefficientArray[index];
	else if(index>size-1)
		return 0;
	else
	    return 56789;
}

int Polynomial::getMaxDegree() {
	return MaxDegree;
}

void Polynomial::print() const
{
	if (this->getDegree(false) == 0)
	{
		cout << "polynomial = 0";
		cout << endl;
	}
	else
	{
		cout << "polynomial = ";
		int maxIndexNoZero = this->getDegree(true);


		for (int i = 0; i <= maxIndexNoZero; i++)
		{
			if (i == 0)
			{
				cout << coefficientArray[i];
			}
			else
			{
				cout << "+";
				cout << "("<<coefficientArray[i]<<")";
				cout << "X^" << i;
			}
		}
		cout << endl;
	}
}

void Polynomial::setCoeff(int degree, double coeff)
{
	coefficientArray[degree] = coeff;
	int size = coefficientArray.size();
	int maxIndex = 0;
	for (int i = 0; i < size; i++)
	{
		if (coefficientArray[i] != 0)
		{
			maxIndex = i;
		}
	}
	if (maxIndex > MaxDegree)
	{
		MaxDegree = maxIndex;
	}

}
  ostream& operator<<(std::ostream& out, const Polynomial& other)   {
  other.print();
  return out;
}

Polynomial Polynomial::operator=(const Polynomial& other)
{

    this->coefficientArray.resize(other.coefficientArray.size());
    int size = this->coefficientArray.size();
    for (int i = 0; i < size; i++)
    {
        this->coefficientArray[i] = other.coefficientArray[i];
    }
    if (getDegree(this) > MaxDegree)
        MaxDegree = getDegree(this);
    return *this;
}	

Polynomial operator*(double scalar,  Polynomial& other)
{
    Polynomial Scalar_multiplication(other);
 
   for(int i=0;i< other.coefficientArray.size();i++){
    Scalar_multiplication.coefficientArray[i]=other.coefficientArray[i]*scalar;
    }
    
return Scalar_multiplication;
}

Polynomial Polynomial::operator*( Polynomial& other) 
{
    Polynomial temp;
    int size = other.coefficientArray.size();
    int size_this = this->coefficientArray.size();
    temp.coefficientArray.resize(size + size_this-1);

    for (int i = 0; i < size_this; i++)
    {
        for (int j = 0; j < size; j++)
        {
     temp.coefficientArray[i + j] = temp.coefficientArray[i + j]+ this->coefficientArray[i] * other.coefficientArray[j];
        }
    }
    if(temp.coefficientArray.size()-1>MaxDegree)
    {
        MaxDegree=temp.coefficientArray.size()-1;
    }

    return temp;
}
Polynomial::Polynomial(const Polynomial& other) {
    int degree = other.getDegree(true);
    coefficientArray.resize(degree + 1);

    for (int i = 0; i <= degree; ++i)
    {
        coefficientArray[i] = other.getCoeff(i);
    }
}
Polynomial Polynomial::operator+(const Polynomial& other)
{
    int size;

    Polynomial result(*this);
    if (result.coefficientArray.size() < other.coefficientArray.size()) {
        result.coefficientArray.resize(other.coefficientArray.size());
        size = other.coefficientArray.size();
    }
    else if (result.coefficientArray.size() > other.coefficientArray.size())
        size = other.coefficientArray.size();
    else
        size = result.coefficientArray.size();
    for (int i = 0; i < size; i++)
    {
        result.coefficientArray[i] += other.coefficientArray[i];
    }

    return result;
}

Polynomial Polynomial::operator+(double scalar)
{
    Polynomial Multiplication_scalar(*this);

    Multiplication_scalar.coefficientArray[0] = Multiplication_scalar.coefficientArray[0]+scalar; 
    return Multiplication_scalar; 
}

Polynomial Polynomial::operator-(const Polynomial& other) const
{
    Polynomial result(*this);
    if (result.coefficientArray.size() < other.coefficientArray.size())
        result.coefficientArray.resize( other.coefficientArray.size());
    int size = result.coefficientArray.size();
    for (int i = 0; i < size; i++)
    {
        result.coefficientArray[i] -= other.coefficientArray[i];
    }
    return result;
}

const double Polynomial::operator[](int index)const
{  
    if (index>=0&& index<this->coefficientArray.size())
    
        return this->coefficientArray[index];
    else 
        return 12345;
}

Polynomial Polynomial::operator*(double scalar){
Polynomial temp(*this);
    for(int i=0;i<this->coefficientArray.size();i++)
                {
         temp.coefficientArray[i]=temp.coefficientArray[i]*scalar;
                }
return temp;
}
Polynomial.cpp.cpp
מציג את Polynomial.cpp.cpp.
