#pragma once

#include <string>

class Rational {
    int numerator_;
    int denominator_;
public:
    int GetNumerator() const;
    int GetDenominator() const;
    explicit Rational(int numerator=0, int denominator=1);
    Rational operator+(const Rational& src) const;
    Rational operator-(const Rational& src) const;
    Rational operator*(const Rational& src) const;
    Rational operator/(const Rational& src) const;
    bool operator==(const Rational& src) const;
    bool operator<(const Rational& src) const;
    bool operator>(const Rational& src) const;
    bool operator!=(const Rational& src) const;
    bool operator<=(const Rational& src) const;
    bool operator>=(const Rational& src) const;
    explicit operator float() const;
    explicit operator double() const;
    std::string PrintRational() const;
};

std::ostream& operator << (std::ostream& stream, const Rational& src);
std::istream& operator >> (std::istream& stream, Rational& src);