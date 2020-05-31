#include <cmath>
#include "Rational.hpp"

using namespace std;

void test_0() {
    Rational r = Rational();
    if (r.GetNumerator()!=0 && r.GetDenominator()!=1) {
        cout << "FAIL!!!" << endl;
    }
}

void test_1() {
    Rational r = Rational(1,2);
    if (r.GetNumerator()!=1 && r.GetDenominator()!=2) {
        cout << "FAIL!!!" << endl;
    }
}

void test_2() {
    Rational r = Rational(1, 2) + Rational(1, 3) - Rational(1, 4);
    if (r != Rational(7, 12)) {
        cout << "FAIL!!!" << endl;
    }
}

void test_3() {
    Rational r = Rational(1, 2) * Rational(1, 3) / Rational(1, 4);
    if (r != Rational(2, 3)) {
        cout << "FAIL!!!" << endl;
    }
}

void test_4() {
    Rational r = Rational(1,2);
    if (abs(static_cast<double>(r)-0.5000) > 0.0001) {
        cout << "FAIL!!!" <<endl;
    }
}

void test_5() {
    Rational r = Rational(1,3);
    if (abs(static_cast<float>(r)-0.3333) > 0.0001) {
        cout << "FAIL!!!" <<endl;
    }
}

void test_6() {
    try {
        Rational r;
        cin >> r;
        cout << r << endl;
    } catch (const invalid_argument& err ) {
        cerr << "zero division was caught" << endl;
    }
}

int main() {
    test_0();
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();
    test_6();
    return 0;
}