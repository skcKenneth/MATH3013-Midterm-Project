#include "kenneth_complex.h"
int main() {
    //The first complex number test
    Kenneth::ComplexNumber<double> a(3, 5);
    Kenneth::ComplexNumber<double> a_new(5, 3);
    std::cout << "The complex number a is: ";
    a.print();
    a = a_new;
    std::cout << "The new complex number a is: ";
    a.print();
    std::cout << "The module of a is: ";
    double mod_a = a.mod();
    std::cout << mod_a << std::endl;
    std::cout << "The argument of a is: ";
    double arg_a = a.arg();
    std::cout << arg_a << " rad"<<std::endl;
    std::cout << "The polar form of a is: ";
    double pol_a_r = a.CtoP_r(a);double pol_a_arg = a.CtoP_arg(a);
    std::cout << pol_a_r<<"cos("<<pol_a_arg<<")+"<<pol_a_r<<"sin("<<pol_a_arg<<")i" << std::endl;
    Kenneth::ComplexNumber<double> con_a = a.conjugate(a);
    std::cout << "The original form of a is: ";
    Kenneth::ComplexNumber<double> temp(1.,1.);
    double cart_a_x = temp.PtoC_x(pol_a_r, pol_a_arg);
    double cart_a_y = temp.PtoC_y(pol_a_r, pol_a_arg);
    Kenneth::ComplexNumber<double> a_orig(cart_a_x,cart_a_y);
    a_orig.print();
    std::cout << "The conjugate of a is: ";
    con_a.print();

    Kenneth::ComplexNumber<double> b(3, -5);
    std::cout << "The complex number b is: ";
    b.print();
    Kenneth::ComplexNumber<double> e = a * b;
    std::cout << "The complex number a*b is: ";
    e.print();
    double r1, r2;
    std::cout << "Input real part of a complex number: ";
    std::cin >> r1;
    std::cout  << "Input imaginary part of a complex number: ";
    std::cin >> r2;
    Kenneth::ComplexNumber<double> c(r1, r2);
    c.print();
    return 0;
}