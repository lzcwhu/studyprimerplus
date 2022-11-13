#include <iostream>
using namespace std;
#include "complex0.h"

Complex::Complex(){
    real = imag = 0;
}

Complex::Complex(double re, double im){
    real = re;
    imag = im;
}

Complex Complex::operator+(const Complex &c) const{
    Complex sum;
    sum.real = real + c.real;
    sum.imag = imag + c.imag;
    return sum;
}

Complex Complex::operator-(const Complex &c) const{
    Complex diff;
    diff.real = real - c.real;
    diff.imag = imag - c.imag;
    return diff;
}

Complex Complex::operator*(const Complex &c) const{
    Complex mul;
    mul.real = real * c.real - imag * c.imag;
    mul.imag = real * c.imag + imag + c.real;
    return mul;
}

Complex Complex::operator*(double x) const{
    Complex mul2;
    mul2.real = real * x;
    mul2.imag = imag * x;
    return mul2;
}

std::istream & operator>>(std::istream &is, Complex &co){
std::cout << "real: ";
    if (is >> co.real) //若实数部分读取失败则虚数部分不读取;
    {
        std::cout << "imaginary: ";
        is >> co.imag;
    }
    return is;
}

std::ostream & operator<<(std::ostream &os, const Complex &co){
    os << '(' << co.real << "," << co.imag << "i)";
    return os;
}