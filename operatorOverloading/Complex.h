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

    //맨 마지막의 const 멤버함수 : 이 멤버함수는 자기 객체(*this)를 수정하지 않는다는 약속가 들어가지 않는다.
    //왜냐면 대입연산자는 피연산자를 수정하는 일이기 때문
    Complex& operator+=(const Complex& c);
    Complex& operator-=(const Complex& c);
    Complex& operator*=(const Complex& c);
    Complex& operator/=(const Complex& c);

    Complex& operator=(const Complex& c);
};


#endif //C_STUDY_COMPLEX_H
