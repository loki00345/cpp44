#include <iostream>
using namespace std;
class Fraction {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b) const 
    {
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void reduce() {
        int divisor = gcd(numerator, denominator);
        numerator /= divisor;
        denominator /= divisor;
        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Fraction() : numerator(0), denominator(1) {}

    Fraction(int num, int den) : numerator(num), denominator(den)
    {
        if (denominator == 0)
        {
            throw invalid_argument("Denominator cannot be zero.");
        }
        reduce();
    }

    void input(int num, int den)
    {
        numerator = num;
        denominator = den;
        if (denominator == 0)
        {
            throw invalid_argument("Denominator cannot be zero.");
        }
        reduce();
    }

    Fraction add(const Fraction& other) const
    {
        int num = numerator * other.denominator + other.numerator * denominator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    Fraction subtract(const Fraction& other) const
    {
        int num = numerator * other.denominator - other.numerator * denominator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    Fraction multiply(const Fraction& other) const
    {
        int num = numerator * other.numerator;
        int den = denominator * other.denominator;
        return Fraction(num, den);
    }

    Fraction divide(const Fraction& other) const 
    {
        if (other.numerator == 0) {
            throw invalid_argument("Cannot divide by zero fraction.");
        }
        int num = numerator * other.denominator;
        int den = denominator * other.numerator;
        return Fraction(num, den);
    }

    void print() const {
        cout << numerator << "/" << denominator << endl;
    }
};

int main() {
    Fraction frac1(1, 2);
    Fraction frac2(3, 4);

    Fraction result;

    result = frac1.add(frac2);
    result.print();

    result = frac1.subtract(frac2);
    result.print();

    result = frac1.multiply(frac2);
    result.print();

    result = frac1.divide(frac2);
    result.print();
}
