//
// Created by robin on 2026-11-17.
//

#include "Complex.h"

Complex Complex::operator+(const Complex& c) const {
    Complex temp(real + c.real, img + c.img);
    return temp;
}
Complex Complex::operator-(const Complex& c) const {
    Complex temp(real - c.real, img - c.img);
    return temp;
}
Complex Complex::operator*(const Complex& c) const {
    Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
    return temp;
}
Complex Complex::operator/(const Complex& c) const {
    Complex temp(
      (real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
      (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
    return temp;
}

int main() {
    Complex a(1.0, 2.0);
    Complex b(3.0, -2.0);
    Complex d = a + b + a ; //대입이 아니라 생성자 호출됌
    d.println(); //(5,2)

    /*
     만약
     Complex& operator+(const Complex& c) {
          real += c.real;
          img += c.img;
          return *this;
     } 였다면  a + b + a  =  (a.operator+(b)).plus(a)가 되는데
     (a.operator+(b))를 통해 a는 a+b가 되버리므로 (a+b) + (a+b)가 되서 2a+2b가 된다.
     */
}