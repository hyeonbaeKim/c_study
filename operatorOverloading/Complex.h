//
// Created by robin on 2026-11-17.
//

#ifndef C_STUDY_COMPLEX_H
#define C_STUDY_COMPLEX_H

#include <iostream>

class Complex {
private:
    double real, img; //real + imgi

public:
    Complex(double real, double img) : real(real), img(img){}
    Complex(const Complex& c) {
        real = c.real;
        img = c.img;
    }

    void println() { std::cout << "( " << real << " , " << img << " ) " << std::endl; }

    //맨 마지막의 const 멤버함수 : 이 멤버함수는 자기 객체(*this)를 수정하지 않는다는 약속
    Complex operator+(const Complex& c) const;
    Complex operator-(const Complex& c) const;
    Complex operator*(const Complex& c) const;
    Complex operator/(const Complex& c) const;
};


#endif //C_STUDY_COMPLEX_H
