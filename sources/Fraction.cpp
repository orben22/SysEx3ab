#include "Fraction.hpp"

namespace ariel {
    //constructors
    Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {
        if (this->denominator==0) throw std::logic_error("the denominator can't be 0");
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
        return {0, 0};
    }

    Fraction Fraction::operator-(const Fraction &other) {
        return {0, 0};
    }

    Fraction Fraction::operator-() const {
        return {0, 0};
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
        return {0, 0};
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
        return {0, 0};
    }

    Fraction Fraction::operator/(const Fraction &other) {
        return {0, 0};
    }

//comparison methods
//greater than (>)
    bool Fraction::operator>(const Fraction &other) const {
        if ((this->numerator*other.denominator)>(other.numerator*this->denominator)) return true;
        return false;
    }

    bool Fraction::operator>(float num) const {
        Fraction temp(num);
        if (*this>temp) return true;
        return false;
    }

    bool operator>(float num, const Fraction &other) {
        return true;
    }

//less than (<)
    bool Fraction::operator<(const Fraction &other) const {
        if ((this->numerator*other.denominator)<(other.numerator*this->denominator)) return true;
        return false;
    }

    bool Fraction::operator<(float num) const {
        Fraction temp(num);
        if (*this<temp) return true;
        return false;
    }

    bool operator<(float num, const Fraction &other) {
        return true;
    }

//greater or equal (>=)
    bool Fraction::operator>=(const Fraction &other) const {
        if ((this->numerator*other.denominator)>=(other.numerator*this->denominator)) return true;
        return false;
    }

    bool Fraction::operator>=(float num) const {
        Fraction temp(num);
        if (*this>=temp) return true;
        return false;
    }

    bool operator>=(float num, const Fraction &other) {
        return true;
    }

//less or equal (<=)
    bool Fraction::operator<=(const Fraction &other) const {
        if ((this->numerator*other.denominator)<=(other.numerator*this->denominator)) return true;
        return false;
    }

    bool Fraction::operator<=(float num) const {
        Fraction temp(num);
        if (*this<=temp) return true;
        return false;
    }

    bool operator<=(float num, const Fraction &other) {
        return true;
    }

// equal (=)
    Fraction &Fraction::operator=(const Fraction &other) {
        return *this;
    }

    Fraction &Fraction::operator=(float number) {
        return *this;
    }

    Fraction &Fraction::operator=(Fraction &&other) noexcept {
        return *this;
    }

//is equal (==)
    bool Fraction::operator==(const Fraction &other) const {
        if ((!(*this>other))&&(!(*this<other))) return true;
        return false;
    }

    bool Fraction::operator==(float num) const {
        Fraction temp(num);
        if (*this==temp) return true;
        return false;
    }

    bool operator==(float num, const Fraction &other) {
        return true;
    }

//is not equal (!=)
    bool Fraction::operator!=(const Fraction &other) const {
        return true;
    }

    bool Fraction::operator!=(float num) const {
        return true;
    }

    bool operator!=(float num, const Fraction &other) {
        return true;
    }
//increment a fraction:

//++this
    Fraction &Fraction::operator++() {
        return *this;
    }

//this++
    const Fraction Fraction::operator++(int) {
        return {0, 0};
    }

//--this
    Fraction &Fraction::operator--() {
        return *this;
    }

//this--
    const Fraction Fraction::operator--(int) {
        return {0, 0};
    }

//output method
    std::ostream &operator<<(std::ostream &ostream, const Fraction &other) {
        return ostream;
    }

//input method
    std::istream &operator>>(std::istream &istream, Fraction &other) {
        return istream;
    }

    int Fraction::gcd() {
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












