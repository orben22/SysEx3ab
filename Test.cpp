#include <sstream>
#include "./sources//Fraction.hpp"
#include "doctest.h"

using namespace ariel;

TEST_CASE("initialization of a fraction") {
    CHECK_THROWS(Fraction(1, 0));//the denominator can't be zero
    Fraction f1(0,9);
    Fraction f2(0,1);
    CHECK(((f1==f2)&&(f1==0)&&(f2==0)));//if the numerator is zero, so the value of the fraction is zero
    f1++;
    CHECK((f1==1));//no matter what is the denominator
}

TEST_CASE("Arithmetic operations") {
    Fraction f1(1, 2);
    Fraction f2(3, 2);
    Fraction f3(3,4);
    Fraction f4(0,1);
    f1++;
    CHECK(((f1.getNumerator()==3)&&(f1.getDenominator()==2)));
    CHECK((f1==f2));//f1 need to be equal to f2 after f1++
    f1--;
    CHECK(((f1.getNumerator()==1)&&(f1.getDenominator()==2)));
    CHECK((f1==0.5));//f1 need to be equal to 0.5 after f1--
    ++f1;
    CHECK(((f1.getNumerator()==3)&&(f1.getDenominator()==2)));
    CHECK((f1==f2));//f1 need to be equal to f2 after f1++
    --f1;
    CHECK(((f1.getNumerator()==1)&&(f1.getDenominator()==2)));
    CHECK((f1==0.5));//f1 need to be equal to 0.5 after f1--
    CHECK(f1+(f2+1)==(f1+f2)+1);//parenthesis in addition can move
    CHECK(f1*f2==f3);
    CHECK(f1*(f2*3)==(f1*f2)*3);//parenthesis in multiply can move
    CHECK_FALSE(f1/(f2/3)==(f1/f2)/3);//parenthesis in divide can't move
    CHECK_THROWS(f1/0);//can't divide by 0
    CHECK((1.0/f1)==2);
    CHECK(f1-(f2-3)!=(f1-f2)-3);//parenthesis in subtract cant move
    CHECK((f1-f1==f4));
}

TEST_CASE("Comparison operators") {
    Fraction f1(1, 2);
    Fraction f2(3, 2);
    Fraction f3(6,4);
    Fraction f4(1,3);
    CHECK(((f1<f2)&&(f1<=f2)));
    CHECK_FALSE(((f1>=f2)&&(f1>f2)));
    CHECK(((f1>0)&&(f1>=0)));
    CHECK_FALSE(((f1<=0)&&(f1<0)));
    CHECK(f1*(-1.0)<0);
    CHECK_FALSE(f1*(-1.0)>=0);
    CHECK(((f1==0.5)&&((f1<=0.5))&&(f1>=0.5)));
    CHECK_FALSE(((f1!=0.5)&&((f1>0.5))&&(f1<0.5)));
    CHECK(((f2==1.5)&&((f2<=1.5))&&(f2>=1.5)));
    CHECK_FALSE(((f2!=1.5)&&((f2>1.5))&&(f2<1.5)));
    CHECK((f2==f3));//check if 3/2==6/4
    CHECK_FALSE((f2!=f3));
    CHECK((f4==0.333));
    CHECK_FALSE((f4==0.433));
}
TEST_CASE("output & input operators"){
    Fraction f1;

    // Simulate user input of "1 5"
    std::istringstream input("1 5");
    input >> f1;

    CHECK((f1 == 0.2));

    // Simulate output to console
    std::ostringstream output;
    output << f1;

    CHECK(output.str() == "1/5");
}

