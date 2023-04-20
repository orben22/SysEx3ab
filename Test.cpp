#include "./sources//Fraction.hpp"
#include "doctest.h"

using namespace ariel;

TEST_CASE("initialization of a fraction") {
    CHECK_THROWS(Fraction(1, 0));//the denominator can't be zero
    Fraction f1(0,9);
    Fraction f2(0,1);
    CHECK(((f1==f2)&&(f1==0)&&(f2==0)));//if the numerator is zero, so the value of the fraction is zero
    f1++;
    CHECK(f1==1);//no matter what is the denominator
}

TEST_CASE("Arithmetic operations") {
    Fraction f1(1, 2);
    Fraction f2(3, 2);
    Fraction f3(3,4);
    f1++;
    CHECK(f1==f2);//f1 need to be equal to f2 after f1++
    f1--;
    CHECK(f1==0.5);//f1 need to be equal to 0.5 after f1--
    CHECK(f1+(f2+1)==(f1+f2)+1);//parenthesis in addition can move
    CHECK(f1*f2==f3);
    CHECK(f1*(f2*3)==(f1*f2)*3);//parenthesis in multiply can move
    CHECK(f1/(f2/3)==(f1/f2)/3);//parenthesis in divide can move
    CHECK_THROWS(f1/0);//can't divide by 0
    CHECK((1/f1)==2);
}

TEST_CASE("Comparison operators") {
    Fraction f1(1, 2);
    Fraction f2(3, 2);
    Fraction f3(6,4);
    Fraction(2,3)+Fraction(1,0);
    CHECK(((f1<f2)&&(f1<=f2)));
    CHECK(((f1>0)&&(f1>=0)));
    CHECK(((f1==0.5)&&((f1<=0.5))&&(f1>=0.5)));
    CHECK(((f2==1.5)&&((f2<=1.5))&&(f2>=1.5)));
    CHECK(f2==f3);//check if 3/2==6/4
}

