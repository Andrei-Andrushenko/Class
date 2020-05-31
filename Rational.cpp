#include "Rational.hpp"
#include <stdexcept>

using namespace std;

int NOD(int a, int b) {
    if (a<0) {
        a*=-1;
    }
    while (a!=0 and b!=0) {
        if (a>b) {
            a=a%b;
        } else {
            b=b%a;
        }
    }
    return a+b;
}

int Rational::GetNumerator() const {
    return numerator_;
}

int Rational::GetDenominator() const {
    return denominator_;
}

Rational::Rational(int numerator, int denominator) : numerator_(numerator), denominator_(denominator) {
    if (denominator==0) {
        throw invalid_argument("Denominator cannot be zero");
    }
    if (denominator<0) {
        denominator_*=-1;
        numerator_*=-1;
    }
    numerator_/=NOD(GetNumerator(), GetDenominator());
    denominator_/=NOD(GetNumerator(), GetDenominator());
}

Rational Rational::operator+(const Rational &src) const {
    return Rational{numerator_*src.denominator_+denominator_*src.numerator_, denominator_*src.denominator_};
}

Rational Rational::operator-(const Rational &src) const {
    return Rational{numerator_*src.denominator_-denominator_*src.numerator_, denominator_*src.denominator_};
}

Rational Rational::operator*(const Rational &src) const {
    return  Rational{numerator_*src.numerator_, denominator_*src.denominator_};
}

Rational Rational::operator/(const Rational &src) const {
    return Rational{numerator_*src.denominator_, denominator_*src.numerator_};
}

bool Rational::operator==(const Rational &src) const {
    return numerator_*src.denominator_ == denominator_*src.numerator_;
}

bool Rational::operator<(const Rational &src) const {
    return numerator_*src.denominator_ < denominator_*src.numerator_;
}

bool Rational::operator>(const Rational &src) const {
    return numerator_*src.denominator_ > denominator_*src.numerator_;
}

bool Rational::operator!=(const Rational &src) const {
    return numerator_*src.denominator_ != denominator_*src.numerator_;
}

bool Rational::operator<=(const Rational &src) const {
    return numerator_*src.denominator_ <= denominator_*src.numerator_;
}

bool Rational::operator>=(const Rational &src) const {
    return numerator_*src.denominator_ >= denominator_*src.numerator_;
}

Rational::operator float() const {
    return static_cast<float>(numerator_) / static_cast<float>(denominator_);
}

Rational::operator double() const {
    return static_cast<double>(numerator_) / static_cast<double>(denominator_);
}

ostream& operator<<(ostream& stream, const Rational& rational) {
    return stream << rational.GetNumerator() << '/' << rational.GetDenominator();
}

istream& operator>>(istream& stream, Rational& rational) {
    int numerator = 0;
    int denominator = 1;
    stream >> numerator >> denominator;
    rational = Rational{numerator, denominator};
    return stream;
}