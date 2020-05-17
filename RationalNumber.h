#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

class RationalNumber
{
public:
  RationalNumber();  //default constructor
  RationalNumber(int num, int denom);  //overloaded constructor
  void printRational();
  const RationalNumber& operator=(const RationalNumber& r);  //  = overloaded assignment
  RationalNumber operator+(RationalNumber& r);   //  +
  RationalNumber operator-(RationalNumber& r);   //  -
  RationalNumber operator*(const RationalNumber& r) const;   //  *
  RationalNumber operator/(const RationalNumber& r) const;   //  /
  bool operator>(RationalNumber& r);   //  >
  bool operator<(RationalNumber& r);   //  <
  bool operator>=(RationalNumber& r);  //  >=
  bool operator<=(RationalNumber& r);  //  <=
  bool operator==(RationalNumber& r);  //  ==
  bool operator!=(RationalNumber& r);  //  !=

private:
  int numerator;
  int denominator;
  void reduceRN(RationalNumber* r);  //utility function to reduce fraction 
  void expandRatio(RationalNumber* l, RationalNumber& r);  //utility to find common denominator

};

#endif
