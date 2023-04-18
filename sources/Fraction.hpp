#ifndef SYSEX3AB_FRACTION_H
#define SYSEX3AB_FRACTION_H

#include "ostream"

namespace ariel {
    class Fraction {
    private:// data members
        int numerator;
        int denominator;
    public:
        //constructors
        Fraction(int numerator,int denominator);

        Fraction(const Fraction &otherFraction);

        Fraction();
        //destructor
        ~Fraction();

        //plus methods
        Fraction operator+(const Fraction &other) const;

        Fraction operator+(float num) const;

        friend Fraction operator+(float num, const Fraction &other);

        //subtract method
        Fraction operator-(const Fraction &other) const;

        Fraction operator-(float num) const;

        friend Fraction operator-(float num, const Fraction &other);

        Fraction operator-(const Fraction &other);

        Fraction operator-() const;

        //multiply methods
        Fraction operator*(const Fraction &other) const;

        Fraction operator*(float num) const;

        friend Fraction operator*(float num, const Fraction &other);

        //divide methods
        Fraction operator/(const Fraction &other) const;

        Fraction operator/(float num) const;

        friend Fraction operator/(float num, const Fraction &other);

        Fraction operator/(const Fraction &other);

        //comparison methods:
        //greater than (>)
        bool operator>(const Fraction &other) const;

        bool operator>(float num) const;

        friend bool operator>(float num, const Fraction &other);

        //less than (<)
        bool operator<(const Fraction &other) const;

        bool operator<(float num) const;

        friend bool operator<(float num, const Fraction &other);

        //greater or equal (>=)
        bool operator>=(const Fraction &other) const;

        bool operator>=(float num) const;

        friend bool operator>=(float num, const Fraction &other);

        //less or equal (<=)
        bool operator<=(const Fraction &other) const;

        bool operator<=(float num) const;

        friend bool operator<=(float num, const Fraction &other);
        //equal (=)
        Fraction &operator=(const Fraction &other);

        Fraction &operator=(float number);

        Fraction &operator=(Fraction &&other) noexcept;
        //is equal (==)
        bool operator==(const Fraction &other) const;

        bool operator==(float num) const;

        friend bool operator==(float num, const Fraction &other);

        //is not equal (!=)
        bool operator!=(const Fraction &other) const;

        bool operator!=(float num) const;

        friend bool operator!=(float num, const Fraction &other);
        //increment a fraction:

        //++this
        Fraction &operator++();

        //this++
        const Fraction operator++(int);

        //--this
        Fraction &operator--();

        //this--
        const Fraction operator--(int);


        //output method
        friend std::ostream &operator<<(std::ostream &ostream, const Fraction &other);

        //input method
        friend std::istream &operator>>(std::istream &istream, Fraction &other);


    };
}

#endif //SYSEX3AB_FRACTION_H
