#ifndef KENNETH_COMPLEX_H // include guard
#define KENNETH_COMPLEX_H
#pragma once
#include <iostream>
namespace Kenneth {
    template<typename T>
    class ComplexNumber {
    public:
        ComplexNumber();//Default construct function
        ComplexNumber(T real, T image = 0);
        ~ComplexNumber();

    public:
        void print();//output the complex number
        void conjugate();
        void mod();
    public:
        //We will implement the some useful operator
        ComplexNumber& operator=(const ComplexNumber& c);
        ComplexNumber& operator+(const ComplexNumber& c);
        ComplexNumber& operator-(const ComplexNumber& c);
        ComplexNumber& operator*(const ComplexNumber& c);
        ComplexNumber& operator/(const ComplexNumber& c);

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
    void ComplexNumber<T>::conjugate() {
        _real = _real;
        _image = -1 * _image;
    }
    template<typename T>
    void ComplexNumber<T>::mod() {
        double mod;
        mod = _real * _real + _image * _image;
        std::cout << "The modulus of the given complex number is "
            << mod<<"\n";
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
        std::cout << "The real part is " << _real<<"\n";
        std::cout << "The imaginary part is " << _image << "\n";
    }

    template<typename T>
    ComplexNumber<T>& ComplexNumber<T>::operator=(const ComplexNumber& c) {
        _real = c._real;
        _image = c._image;
        return *this;
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
}
#endif /* KENNETH_COMPLEX_H */
