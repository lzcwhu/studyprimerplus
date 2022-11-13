#ifndef COMPLEX0_H_
#define COMPLEX0_H_
#include <iostream>
class Complex{
    private:
        double real;
        double imag; 
    public:
        Complex();
        Complex(double re, double im);
        Complex operator+(const Complex &c) const;
        Complex operator-(const Complex &c) const;
        Complex operator*(const Complex &c) const;
        Complex operator*(double x) const;
        friend std::istream & operator>>(std::istream &os, Complex &c);
        friend std::ostream & operator<<(std::ostream &os, const Complex &c);
};

#endif
