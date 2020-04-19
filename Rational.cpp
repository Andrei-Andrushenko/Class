#include "Rational.hpp"
#include <stdexcept>
#include <sstream>

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

int NOK(int a, int b) {
    return a*b/NOD(a,b);
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
    int a=NOD(GetNumerator(), GetDenominator());
    numerator_/=a;
    denominator_/=a;
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
    return NOK(denominator_, src.denominator_)/denominator_*numerator_ < NOK(denominator_, src.denominator_)/src.denominator_*src.numerator_;
}

bool Rational::operator>(const Rational &src) const {
    return NOK(denominator_, src.denominator_)/denominator_*numerator_ > NOK(denominator_, src.denominator_)/src.denominator_*src.numerator_;
}

bool Rational::operator!=(const Rational &src) const {
    return numerator_*src.denominator_ != denominator_*src.numerator_;
}

bool Rational::operator<=(const Rational &src) const {
    return NOK(denominator_, src.denominator_)/denominator_*numerator_ <= NOK(denominator_, src.denominator_)/src.denominator_*src.numerator_;
}

bool Rational::operator>=(const Rational &src) const {
    return NOK(denominator_, src.denominator_)/denominator_*numerator_ >= NOK(denominator_, src.denominator_)/src.denominator_*src.numerator_;
}

double Rational::Cast_Double() const {
    return static_cast<double>(GetNumerator()) / static_cast<double>(GetDenominator());
}

float Rational::Cast_Float() const {
    return static_cast<float>(GetNumerator()) / static_cast<float>(GetDenominator());
}

string Rational::PrintRational() const {
    stringstream ss;
    ss << GetNumerator() << '/' << GetDenominator();
    return ss.str();
}

ostream& operator<<(ostream& stream, const Rational& rational) {
    return stream << rational.PrintRational();
}

istream& operator>>(istream& stream, Rational& rational) {
    int numerator = 0;
    int denominator = 1;
    stream >> numerator >> denominator;
    rational = Rational{numerator, denominator};
    return stream;
}