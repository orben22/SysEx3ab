#include <limits>
#include "Fraction.hpp"

namespace ariel {
    //constructors
    Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {
        if (this->denominator == 0) throw std::invalid_argument("the denominator can't be zero");
        if (this->denominator < 0) {
            this->numerator = -this->numerator;
            this->denominator = -this->denominator;
        }
        this->reduction();
    }

    Fraction::Fraction(const Fraction &otherFraction) = default;

    Fraction::Fraction(Fraction &&other) noexcept {
        this->numerator = other.numerator;
        this->denominator = other.denominator;
    }

    Fraction::Fraction() : numerator(0), denominator(1) {};//default constructor

    Fraction::Fraction(float num) {
        this->numerator = (int) (num * 1000);
        this->denominator = 1000;
        this->reduction();
    };

    Fraction::~Fraction() = default;

//plus methods
    Fraction Fraction::operator+(const Fraction &other) const {
        long thisnume = (long) this->numerator;
        long thisdeno = (long) this->denominator;
        long othernume = (long) other.numerator;
        long otherdeno = (long) other.denominator;
        if ((thisnume * otherdeno + othernume * thisdeno) > std::numeric_limits<int>::max())
            throw std::overflow_error("the numbers are too big");
        if (thisdeno * otherdeno > std::numeric_limits<int>::max())
            throw std::overflow_error("the numbers are too big");
        if ((thisnume * otherdeno + othernume * thisdeno) < std::numeric_limits<int>::min())
            throw std::overflow_error("the numbers are too small");
        Fraction res((this->numerator * other.denominator) + (other.numerator * this->denominator),
                     this->denominator * other.denominator);
        return res;
    }

    Fraction Fraction::operator+(float num) const {
        Fraction temp(num);
        return *this + temp;
    }

    Fraction operator+(float num, const Fraction &other) {
        Fraction temp(num);
        return other + temp;
    }

    Fraction &Fraction::operator+=(const Fraction &other) {
        *this = *this + other;
        return *this;
    }

    Fraction &Fraction::operator+=(float num) {
        Fraction temp(num);
        *this = *this + temp;
        return *this;
    }

//subtract methods
    Fraction Fraction::operator-(const Fraction &other) const {
        long thisnume = (long) this->numerator;
        long thisdeno = (long) this->denominator;
        long othernume = (long) other.numerator;
        long otherdeno = (long) other.denominator;
        if ((thisnume * otherdeno - othernume * thisdeno) > std::numeric_limits<int>::max())
            throw std::overflow_error("the numbers are too big");
        if (thisdeno * otherdeno > std::numeric_limits<int>::max())
            throw std::overflow_error("the numbers are too big");
        if ((thisnume * otherdeno - othernume * thisdeno) < std::numeric_limits<int>::min())
            throw std::overflow_error("the numbers are too small");
        Fraction res((this->numerator * other.denominator) - (other.numerator * this->denominator),
                     this->denominator * other.denominator);
        return res;
    }

    Fraction Fraction::operator-(float num) const {
        Fraction temp(num);
        return *this - temp;
    }

    Fraction operator-(float num, const Fraction &other) {
        Fraction temp(num);
        return temp - other;
    }

    Fraction &Fraction::operator-=(const Fraction &other) {
        *this = *this - other;
        return *this;
    }

    Fraction &Fraction::operator-=(float num) {
        Fraction temp(num);
        *this = *this - temp;
        return *this;
    }

//multiply methods
    Fraction Fraction::operator*(const Fraction &other) const {
        long thisnume = (long) this->numerator;
        long thisdeno = (long) this->denominator;
        long othernume = (long) other.numerator;
        long otherdeno = (long) other.denominator;
        if (thisnume * othernume > std::numeric_limits<int>::max())
            throw std::overflow_error("the numbers are too big");
        if (thisdeno * otherdeno > std::numeric_limits<int>::max())
            throw std::overflow_error("the numbers are too big");
        if (thisnume * otherdeno < std::numeric_limits<int>::min())
            throw std::overflow_error("the numbers are too small");
        Fraction res(this->numerator * other.numerator, this->denominator * other.denominator);
        return res;
    }

    Fraction Fraction::operator*(float num) const {
        Fraction temp(num);
        return *this * temp;
    }

    Fraction operator*(float num, const Fraction &other) {
        Fraction temp(num);
        return temp * other;
    }

    Fraction &Fraction::operator*=(const Fraction &other) {
        *this = *this * other;
        return *this;
    }

    Fraction &Fraction::operator*=(float num) {
        Fraction temp(num);
        *this = *this * temp;
        return *this;
    }

//divide methods
    Fraction Fraction::operator/(const Fraction &other) const {
        if (other.numerator == 0) throw std::runtime_error("can't divide by zero");
        long thisnume = (long) this->numerator;
        long thisdeno = (long) this->denominator;
        long othernume = (long) other.numerator;
        long otherdeno = (long) other.denominator;
        if (thisnume * otherdeno > std::numeric_limits<int>::max())
            throw std::overflow_error("the numbers are too big");
        if (thisdeno * othernume > std::numeric_limits<int>::max())
            throw std::overflow_error("the numbers are too big");
        if (thisnume * otherdeno < std::numeric_limits<int>::min())
            throw std::overflow_error("the numbers are too small");
        Fraction res(this->numerator * other.denominator, this->denominator * other.numerator);
        return res;
    }

    Fraction Fraction::operator/(float num) const {
        Fraction temp(num);
        return *this / temp;
    }

    Fraction operator/(float num, const Fraction &other) {
        Fraction temp(num);
        return temp / other;
    }

    Fraction &Fraction::operator/=(const Fraction &other) {
        *this = *this / other;
        return *this;
    }

    Fraction &Fraction::operator/=(float num) {
        Fraction temp(num);
        *this = *this / temp;
        return *this;
    }

//comparison methods
//greater than (>)
    bool Fraction::operator>(const Fraction &other) const {
        return (this->numerator * other.denominator) > (other.numerator * this->denominator);
    }

    bool Fraction::operator>(float num) const {
        Fraction temp(num);
        return *this > temp;
    }

    bool operator>(float num, const Fraction &other) {
        Fraction temp(num);
        return temp > other;
    }

//less than (<)
    bool Fraction::operator<(const Fraction &other) const {
        return (!(*this > other) && !(*this == other));
    }

    bool Fraction::operator<(float num) const {
        Fraction temp(num);
        return *this < temp;
    }

    bool operator<(float num, const Fraction &other) {
        Fraction temp(num);
        return temp < other;
    }

//greater or equal (>=)
    bool Fraction::operator>=(const Fraction &other) const {
        return !(*this < other);
    }

    bool Fraction::operator>=(float num) const {
        Fraction temp(num);
        return *this >= temp;
    }

    bool operator>=(float num, const Fraction &other) {
        Fraction temp(num);
        return temp >= other;
    }

//less or equal (<=)
    bool Fraction::operator<=(const Fraction &other) const {
        return !(*this > other);
    }

    bool Fraction::operator<=(float num) const {
        Fraction temp(num);
        return *this <= temp;
    }

    bool operator<=(float num, const Fraction &other) {
        Fraction temp(num);
        return temp <= other;
    }

// equal (=)
    Fraction &Fraction::operator=(const Fraction &other) {
        this->numerator = other.numerator;
        this->denominator = other.denominator;
        return *this;
    }

    Fraction &Fraction::operator=(float num) {
        Fraction temp(num);
        this->numerator = temp.numerator;
        this->denominator = temp.denominator;
        return *this;
    }

    Fraction &Fraction::operator=(Fraction &&other) noexcept {
        this->numerator = other.numerator;
        this->denominator = other.denominator;
        other.numerator = 0;
        other.denominator = 1;
        return *this;
    }

//is equal (==)
    bool Fraction::operator==(const Fraction &other) const {
        auto temp1Num = (float) this->numerator;
        auto temp2Den = (float) this->denominator;
        auto temp3Num = (float) other.numerator;
        auto temp4Den = (float) other.denominator;
        return (std::abs((temp1Num / temp2Den) - (temp3Num / temp4Den)) < 0.001);
    }

    bool Fraction::operator==(float num) const {
        Fraction temp(num);
        return *this == temp;
    }

    bool operator==(float num, const Fraction &other) {
        Fraction temp(num);
        return temp == other;
    }

//is not equal (!=)
    bool Fraction::operator!=(const Fraction &other) const {
        return !(*this == other);
    }

    bool Fraction::operator!=(float num) const {
        Fraction temp(num);
        return *this != temp;
    }

    bool operator!=(float num, const Fraction &other) {
        Fraction temp(num);
        return temp != other;
    }

//increment a fraction:
//++this
    Fraction &Fraction::operator++() {
        return *this += Fraction{1,1};
    }

//this++
    const Fraction Fraction::operator++(int) {
        Fraction copy(*this);
        *this += 1;
        return copy;
    }

//--this
    Fraction &Fraction::operator--() {
        return *this -= 1;
    }

//this--
    const Fraction Fraction::operator--(int) {
        Fraction copy(*this);
        *this -= 1;
        return copy;
    }

//output method
    std::ostream &operator<<(std::ostream &ostream, const Fraction &other) {
        return ostream << other.numerator << "/" << other.denominator;
    }

//input method
    std::istream &operator>>(std::istream &istream, Fraction &other) {
        int nume, deno;
        istream >> nume;
        char space;
        istream.get(space);
        if (space == ' ') {
            istream >> deno;
        } else throw std::runtime_error("try another input");

        if (deno < 0) {
            nume = -nume;
            deno = -deno;
        } else if (deno == 0) {
            throw std::runtime_error("can't divide by zero");
        }

        other = Fraction(nume, deno);

        return istream;

    }

    int Fraction::gcd() const {
        int a=abs(this->numerator);
        int b=abs(this->denominator);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void Fraction::reduction() {
        int mygcd = this->gcd();
        this->numerator = this->numerator / mygcd;
        this->denominator = this->denominator / mygcd;
    }

    int Fraction::getNumerator() const {
        return numerator;
    }

    void Fraction::setNumerator(int num) {
        Fraction::numerator = num;
    }

    int Fraction::getDenominator() const {
        return denominator;
    }

    void Fraction::setDenominator(int den) {
        Fraction::denominator = den;
    }

}












