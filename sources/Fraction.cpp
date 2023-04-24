#include "Fraction.hpp"

namespace ariel {
    //constructors
    Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {}

    Fraction::Fraction(const Fraction &otherFraction) : numerator(otherFraction.numerator),
                                                  denominator(otherFraction.denominator) {}

    Fraction::Fraction() : numerator(0), denominator(1) {};

    Fraction::~Fraction() = default;

//plus methods
    Fraction Fraction::operator+(const Fraction &other) const {
        return {0, 0};
    }

    Fraction Fraction::operator+(float num) const {
        return {0, 0};
    }

    Fraction operator+(float num, const Fraction &other) {
        return {0, 0};
    }

//subtract methods
    Fraction Fraction::operator-(const Fraction &other) const {
        return {0, 0};
    }

    Fraction Fraction::operator-(float num) const {
        return {0, 0};
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
        return {0, 0};
    }

    Fraction Fraction::operator*(float num) const {
        return {0, 0};
    }

    Fraction operator*(float num, const Fraction &other) {
        return {0, 0};
    }

//divide methods
    Fraction Fraction::operator/(const Fraction &other) const {
        return {0, 0};
    }

    Fraction Fraction::operator/(float num) const {
        return {0, 0};
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
        return true;
    }

    bool Fraction::operator>(float num) const {
        return true;
    }

    bool operator>(float num, const Fraction &other) {
        return true;
    }

//less than (<)
    bool Fraction::operator<(const Fraction &other) const {
        return true;
    }

    bool Fraction::operator<(float num) const {
        return true;
    }

    bool operator<(float num, const Fraction &other) {
        return true;
    }

//greater or equal (>=)
    bool Fraction::operator>=(const Fraction &other) const {
        return true;
    }

    bool Fraction::operator>=(float num) const {
        return true;
    }

    bool operator>=(float num, const Fraction &other) {
        return true;
    }

//less or equal (<=)
    bool Fraction::operator<=(const Fraction &other) const {
        return true;
    }

    bool Fraction::operator<=(float num) const {
        return true;
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
        return true;
    }

    bool Fraction::operator==(float num) const {
        return true;
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

    Fraction::Fraction(Fraction &&other) noexcept {};

}












