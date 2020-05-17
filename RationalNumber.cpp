#include <iostream>
#include "RationalNumber.h"
#include <stdexcept>

RationalNumber::RationalNumber()  //initializes objecto to 1/1
:numerator(1), denominator(1)
{}

RationalNumber::RationalNumber(int num, int denom)
{
  numerator = num;
  denominator = denom;

  if(denom == 0)
    throw std::invalid_argument("Cannot divide by zero.");
  else if((denominator < 0 && numerator > 0) || (denominator < 0 && numerator < 0))  //negates the rational number if 1/-2 changes to -1/2 & -1/-2 changes to 1/2
  {
    numerator = -numerator;
    denominator = -denominator;
  }
  reduceRN(this);
}

void RationalNumber::printRational()
{
  reduceRN(this);

  if(denominator == 1)
    std::cout << numerator;
  else if(numerator == 0)
    std::cout << numerator;
  else
    std::cout << numerator << "/" << denominator;
}

const RationalNumber& RationalNumber::operator=(const RationalNumber& r)
{
  numerator = r.numerator;
  denominator = r.denominator;

  reduceRN(this);

  return *this;
}

//expands rational numbers to have same denominator then adds the numerators
//by returning a new object
RationalNumber RationalNumber::operator+(RationalNumber& r)
{
  expandRatio(this, r);

  return RationalNumber(numerator + r.numerator, denominator);
}

//expands rational numbers to have same denominator then subtracts the numerators
//by returning a new object
RationalNumber RationalNumber::operator-(RationalNumber& r)
{
  expandRatio(this, r);

  return RationalNumber(numerator - r.numerator, denominator);
}

//multiplies both numerators and denominators together
//and returns new object
RationalNumber RationalNumber::operator*(const RationalNumber& r) const
{
  return RationalNumber(numerator * r.numerator, denominator * r.denominator);
}

//multiplies left numerator and right denominator together,
//left denominator and right numerator together,
//and returns new object
RationalNumber RationalNumber::operator/(const RationalNumber& r) const
{
  return RationalNumber(numerator * r.denominator, denominator * r.numerator);
}

bool RationalNumber::operator>(RationalNumber& r)
{
  expandRatio(this, r);


  return numerator > r.numerator;
}

bool RationalNumber::operator<(RationalNumber& r)
{
  expandRatio(this, r);


  return numerator < r.numerator;
}

bool RationalNumber::operator>=(RationalNumber& r)
{
  expandRatio(this, r);


  return numerator >= r.numerator;
}

bool RationalNumber::operator<=(RationalNumber& r)
{
  expandRatio(this, r);


  return numerator <= r.numerator;
}

bool RationalNumber::operator==(RationalNumber& r)
{
  expandRatio(this, r);


  return numerator == r.numerator;
}

bool RationalNumber::operator!=(RationalNumber& r)
{
  expandRatio(this, r);

  return numerator != r.numerator;  //uses overloaded == to compare the two objects and negates the is equal to operator; passing address r
}

void RationalNumber::reduceRN(RationalNumber* r)
{
  for(int i{denominator * numerator}; i > 1; i--)
  {
    if((denominator % i == 0) && (numerator % i == 0))
    {
      denominator /= i;
      numerator /= i;
    }
  }
}

//expands two ratios in order to compare and do arithmetic to rational numbers
void RationalNumber::expandRatio(RationalNumber* l, RationalNumber& r)
{
  int commonFactor;
  if(l->denominator != r.denominator)  //dont need to compare if they already have the same denominator
  {
    if(l->denominator > r.denominator)
    {
      commonFactor = l->denominator;
      while(commonFactor % r.denominator != 0)  //adds the common factor to common factor to find greatest common factor
      {
        commonFactor += l->denominator;
      }
    }
    else if(r.denominator > l->denominator)
    {
      commonFactor = r.denominator;
      while(commonFactor % l->denominator != 0)
      {
        commonFactor += r.denominator;
      }
    }
    //assigns and expands the new ratio with the common factor found 
    l->numerator = (commonFactor/l->denominator) * l->numerator;
    r.numerator = (commonFactor/r.denominator) * r.numerator;
    l->denominator = commonFactor;
    r.denominator = commonFactor;
  }
}
