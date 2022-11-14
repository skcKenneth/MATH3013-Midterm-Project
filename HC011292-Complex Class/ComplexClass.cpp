#include "kenneth_complex.h"
int main() {
    //The first complex number test
    Kenneth::ComplexNumber<int> a(3, 5);
    std::cout << "The complex number a is: ";
    a.print();
    a.mod();
    Kenneth::ComplexNumber<int> b(3, -5);
    std::cout << "The complex number b is: ";
    b.print();
    Kenneth::ComplexNumber<int> e = a * b;
    std::cout << "The complex number e is: ";
    e.print();
    double r1, r2;
    std::cout << "Input real part of a complex number: ";
    std::cin >> r1;
    std::cout  << "Input imaginary part of a complex number: ";
    std::cin >> r2;
    Kenneth::ComplexNumber<double> c(r1, r2);
    std::cout << "The complex number you input is: ";
    c.print();
    c.mod();
    std::cout << "The complex conjugate is: ";
    c.conjugate();c.print();
    return 0;
}