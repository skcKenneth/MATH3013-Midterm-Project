#include "kenneth_complex.h"
int main() {
    //The first complex number test
    Kenneth::ComplexNumber<int> a(3, 5);
    std::cout << "The complex number a is: ";
    a.print();
    a.magnitude();
    Kenneth::ComplexNumber<int> b(3, -5);
    std::cout << "The complex number b is: ";
    b.print();
    double r1, r2;
    std::cout << "Input real part of a complex number: ";
    std::cin >> r1;
    std::cout  << "Input imaginary part of a complex number: ";
    std::cin >> r2;
    Kenneth::ComplexNumber<double> c(r1, r2);
    std::cout << "The complex number you input is: ";
    c.print();
    Kenneth::ComplexNumber<double> d(1.0, 2.0);
    std::cout << "The complex number d is: ";
    d.print();
    std::cout << "----------------\n";
    Kenneth::ComplexNumber<int> e = a * b;
    std::cout << "The complex number e is: ";
    e.print();
    Kenneth::ComplexNumber<double> f = c / d;
    std::cout << "The complex number f is: ";
    f.print();
    Kenneth::ComplexNumber<double> g(1.2, 3.5);
    std::cout << "The complex number g is: ";
    g.print();
    g.conjugate();
    std::cout << "The complex conjugate of g is: ";
    g.print();
    return 0;
}