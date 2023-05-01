#include "Fraction.hpp"

namespace ariel {
    //constructors
    Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {
        if (this->denominator==0) throw std::logic_error("the denominator can't be zero");
        this->reduction();
    }

    Fraction::Fraction(const Fraction &otherFraction)= default;

    Fraction::Fraction(Fraction &&other) noexcept {
        this->numerator=other.numerator;
        this->denominator=other.denominator;
    }

    Fraction::Fraction() : numerator(0), denominator(1) {};//default constructor

    Fraction::Fraction(float num) {
        this->numerator=(int)(num*1000);
        this->denominator=1000;
        this->reduction();
    };

    Fraction::~Fraction() = default;

//plus methods
    Fraction Fraction::operator+(const Fraction &other) const {
        Fraction res((this->numerator*this->denominator)+(other.numerator*this->denominator),this->denominator*other.denominator);
        res.reduction();
        return res;
    }

    Fraction Fraction::operator+(float num) const {
        Fraction temp(num);
        return *this+temp;
    }

    Fraction operator+(float num, const Fraction &other) {
        Fraction temp(num);
        return other+temp;
    }

    Fraction &Fraction::operator+=(const Fraction &other) {
        *this = *this + other;
        return *this;
    }

    Fraction &Fraction::operator+=(float num) {
        Fraction temp(num);
        *this=*this+temp;
        return *this;
    }

//subtract methods
    Fraction Fraction::operator-(const Fraction &other) const {
        Fraction res((this->numerator*this->denominator)-(other.numerator*this->denominator),this->denominator*other.denominator);
        res.reduction();
        return res;
    }

    Fraction Fraction::operator-(float num) const {
        Fraction temp(num);
        return *this-temp;
    }

    Fraction operator-(float num, const Fraction &other) {
        Fraction temp(num);
        return temp-other;
    }
//dont know
    Fraction Fraction::operator-(const Fraction &other) {
        return {0, 0};
    }
//dont know
    Fraction Fraction::operator-() const {
        return {0, 0};
    }

    Fraction &Fraction::operator-=(const Fraction &other) {
        *this = *this - other;
        return *this;
    }

    Fraction &Fraction::operator-=(float num) {
        Fraction temp(num);
        *this=*this-temp;
        return *this;
    }

//multiply methods
    Fraction Fraction::operator*(const Fraction &other) const {
        Fraction res(this->numerator*other.numerator,this->denominator*other.denominator);
        res.reduction();
        return res;
    }

    Fraction Fraction::operator*(float num) const {
        Fraction temp(num);
        return *this*temp;
    }

    Fraction operator*(float num, const Fraction &other) {
        Fraction temp(num);
        return temp*other;
    }

    Fraction &Fraction::operator*=(const Fraction &other) {
        *this = *this * other;
        return *this;
    }

    Fraction &Fraction::operator*=(float num) {
        Fraction temp(num);
        *this=*this*temp;
        return *this;
    }

//divide methods
    Fraction Fraction::operator/(const Fraction &other) const {
        Fraction res(this->numerator/other.numerator,this->denominator/other.denominator);
        res.reduction();
        return res;
    }

    Fraction Fraction::operator/(float num) const {
        Fraction temp(num);
        return *this/temp;
    }

    Fraction operator/(float num, const Fraction &other) {
        Fraction temp(num);
        return temp/other;
    }
//not sure if i need that func
    Fraction Fraction::operator/(const Fraction &other) {
        return {0, 0};
    }

    Fraction &Fraction::operator/=(const Fraction &other) {
        *this = *this / other;
        return *this;
    }

    Fraction &Fraction::operator/=(float num) {
        Fraction temp(num);
        *this=*this/temp;
        return *this;
    }

//comparison methods
//greater than (>)
    bool Fraction::operator>(const Fraction &other) const {
        return (this->numerator*other.denominator)>(other.numerator*this->denominator);
    }

    bool Fraction::operator>(float num) const {
        Fraction temp(num);
        return *this>temp;
    }

    bool operator>(float num, const Fraction &other) {
        Fraction temp(num);
        return temp>other;
    }

//less than (<)
    bool Fraction::operator<(const Fraction &other) const {
        return (this->numerator*other.denominator)<(other.numerator*this->denominator);
    }

    bool Fraction::operator<(float num) const {
        Fraction temp(num);
        return *this<temp;
    }

    bool operator<(float num, const Fraction &other) {
        Fraction temp(num);
        return temp<other;
    }

//greater or equal (>=)
    bool Fraction::operator>=(const Fraction &other) const {
        return (this->numerator*other.denominator)>=(other.numerator*this->denominator);
    }

    bool Fraction::operator>=(float num) const {
        Fraction temp(num);
        return *this>=temp;
    }

    bool operator>=(float num, const Fraction &other) {
        Fraction temp(num);
        return temp>=other;
    }

//less or equal (<=)
    bool Fraction::operator<=(const Fraction &other) const {
        return (this->numerator*other.denominator)<=(other.numerator*this->denominator);
    }

    bool Fraction::operator<=(float num) const {
        Fraction temp(num);
        return *this<=temp;
    }

    bool operator<=(float num, const Fraction &other) {
        Fraction temp(num);
        return temp<=other;
    }

// equal (=)
    Fraction &Fraction::operator=(const Fraction &other) {
        this->numerator=other.numerator;
        this->denominator=other.denominator;
        return *this;
    }

    Fraction &Fraction::operator=(float num) {
        return *this;
    }

    Fraction &Fraction::operator=(Fraction &&other) noexcept {
        this->numerator=other.numerator;
        this->denominator=other.denominator;
        other.numerator=0;
        other.denominator=1;
        return *this;
    }

//is equal (==)
    bool Fraction::operator==(const Fraction &other) const {
        return (!(*this>other))&&(!(*this<other));
    }

    bool Fraction::operator==(float num) const {
        Fraction temp(num);
        return *this==temp;
    }

    bool operator==(float num, const Fraction &other) {
        Fraction temp(num);
        return temp==other;
    }

//is not equal (!=)
    bool Fraction::operator!=(const Fraction &other) const {
        return !(*this==other);
    }

    bool Fraction::operator!=(float num) const {
        Fraction temp(num);
        return *this!=temp;
    }

    bool operator!=(float num, const Fraction &other) {
        Fraction temp(num);
        return temp!=other;
    }
//increment a fraction:

//++this
    Fraction &Fraction::operator++() {
        return *this+=1;
    }

//this++
    const Fraction Fraction::operator++(int) {
        Fraction copy(*this);
        *this+=1;
        return copy;
    }

//--this
    Fraction &Fraction::operator--() {
        return *this-=1;
    }

//this--
    const Fraction Fraction::operator--(int) {
        Fraction copy(*this);
        *this-=1;
        return copy;
    }

//output method
    std::ostream &operator<<(std::ostream &ostream, const Fraction &other) {
        return ostream<<other.numerator<<"/"<<other.denominator;
    }

//input method
    std::istream &operator>>(std::istream &istream, Fraction &other) {
        return istream;
    }

    int Fraction::gcd() const {
        int min= std::min(this->numerator,this->denominator);
        int gcd=1;
        for (int i=2;i<=min;i++) {
            if (this->numerator % i == 0 && this->denominator % i == 0) gcd = i;
        }
        return gcd;
    }

    void Fraction::reduction() {
        int mygcd=this->gcd();
        this->numerator=this->numerator/mygcd;
        this->denominator=this->denominator/mygcd;
    }
}












