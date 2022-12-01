#ifndef KENNETH_COMPLEX_H // include guard
#define KENNETH_COMPLEX_H
#pragma once
#include <iostream>
#include <cmath> //just for calculating the argument of complex number
#include <string>
#include <sstream>
namespace Kenneth {
    template<typename T>
    class ComplexNumber {
    public:
        ComplexNumber();//Default construct function
        ComplexNumber(T real, T image = 0);
        ~ComplexNumber();
    public:
        void print();//output the complex number
        double mod(); //Finding the modules
        double arg(); //Finding the argument
        double CtoP_r(Kenneth::ComplexNumber<T>& c); // The r of polar form
        double CtoP_arg(Kenneth::ComplexNumber<T>& c); // The argument of polar form
        double PtoC_x(double r,double arg); // x coordinate
        double PtoC_y(double r,double arg); // y coordinate
    public:
        //We will implement the some useful operator
        ComplexNumber& operator=(const ComplexNumber& c);
        ComplexNumber& operator+(const ComplexNumber& c);
        ComplexNumber& operator-(const ComplexNumber& c);
        ComplexNumber& operator*(const ComplexNumber& c);
        ComplexNumber& operator/(const ComplexNumber& c);
        ComplexNumber& conjugate(const Kenneth::ComplexNumber<T>& c); //Conjugate
    protected:
        T _real;
        T _image;
    };
    template<typename T>
    ComplexNumber<T>::ComplexNumber() {
        _real = 0;
        _image = 0;
    }

    template<typename T>
    ComplexNumber<T>::ComplexNumber(T real, T image) {
        _real = real;
        _image = image;
    }

    template<typename T>
    ComplexNumber<T>::~ComplexNumber() {
    }
    template<typename T>
    double ComplexNumber<T>::mod() {
        double com_mod = _real * _real + _image * _image;
        return com_mod;
    }

    template<typename T>
    double ComplexNumber<T>::arg() {
        double arg = 0;
        if (_real > 0) {
            arg = atan(_image / _real);
        }
        else if (_real < 0 && _image >= 0) {
            arg = atan(_image / _real) + atan(1) * 4; // atan(1)*4 is pi
        }
        else if (_real < 0 && _image < 0) {
            arg = atan(_image / _real) - atan(1) * 4;
        }
        else if (_real = 0 && _image > 0) {
            arg = atan(1) * 2;
        }
        else if (_real = 0 && _image < 0) {
            arg = atan(1) * -2;
        }
        else {
            std::cout << "The argument is undefined" << std::endl;
        }
        return arg;
    }
    template<typename T>
    double ComplexNumber<T>::CtoP_r(Kenneth::ComplexNumber<T>& c) {
        double r = sqrt(c._real * c._real + c._image * c._image);
        return r;
    }

    template<typename T>
    double ComplexNumber<T>::CtoP_arg(Kenneth::ComplexNumber<T>& c) {
        double arg;
        if (c._real > 0) {
            arg = atan(c._image / c._real);
        }
        else if (c._real < 0 && c._image >= 0) {
            arg = atan(c._image / c._real) + atan(1) * 4; // atan(1)*4 is pi
        }
        else if (c._real < 0 && c._image < 0) {
            arg = atan(c._image / c._real) - atan(1) * 4;
        }
        else if (c._real = 0 && c._image > 0) {
            arg = atan(1) * 2;
        }
        else if (c._real = 0 && c._image < 0) {
            arg = atan(1) * -2;
        }
        else {
            std::cout << "The argument is undefined" << std::endl;
        }
        return arg;
    }

    template<typename T>
    double ComplexNumber<T>::PtoC_x(double r, double arg) {
        double x = r * cos(arg);
        return x;
    }

    template<typename T>
    double ComplexNumber<T>::PtoC_y(double r, double arg) {
        double y = r * sin(arg);
        return y;
    }

    template<typename T>
    void ComplexNumber<T>::print() {
        std::cout << _real;
        if (_image > 0) {
            std::cout << "+" << _image << "i";
        }
        else if (_image < 0) {
            std::cout << "-" << abs(_image) << "i";
        }
        std::cout << "\n";
        std::cout << "The real part is " << _real << "\n";
        std::cout << "The imaginary part is " << _image << "\n";
    }

    template<typename T>
    ComplexNumber<T>& ComplexNumber<T>::operator=(const ComplexNumber& c) {
        ComplexNumber<T> temp;
        temp._real = c._real;
        temp._image = c._image;
        return temp;
    }

    template<typename T>
    ComplexNumber<T>& ComplexNumber<T>::operator+(const ComplexNumber<T>& c) {
        _real += c._real;
        _image += c._image;
        return *this;
    }
    template<typename T>
    ComplexNumber<T>& ComplexNumber<T>::operator-(const ComplexNumber<T>& c) {
        _real -= c._real;
        _image -= c._image;
        return *this;
    }
    template<typename T>
    ComplexNumber<T>& ComplexNumber<T>::operator*(const ComplexNumber<T>& c) {
        ComplexNumber<T> temp;
        temp._real = _real * c._real - _image * c._image;
        temp._image = _real * c._image + _image * c._real;
        return temp;
    }
    template<typename T>
    ComplexNumber<T>& ComplexNumber<T>::operator/(const ComplexNumber<T>& c) {
        ComplexNumber<T> temp;
        temp._real = (_real * c._real + _image * c._image) / (c._real * c._real + c._image * c._image);
        temp._image = -1 * (_real * c._image - _image * c._real) / (c._real * c._real + c._image * c._image);
        return temp;
    }
    template<typename T>
    ComplexNumber<T>& ComplexNumber<T>::conjugate(const Kenneth::ComplexNumber<T>& c) {
        ComplexNumber<T> temp;
        temp._real = c._real;
        temp._image = -1 * c._image;
        return temp;
    };
}
#endif /* KENNETH_COMPLEX_H */
