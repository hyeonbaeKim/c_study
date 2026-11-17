//
// Created by robin on 2026-11-17.
//

#include "String.h"
#include <stdio.h>

const char* String::getBuffer() const {
    return buffer;
}

//반환값이 그냥 값임. 왜냐면 *this로 객체자체를 수정하지 않기 위함 ex) a+b+a의 결과로 a+b를해서 a가 a+b가 되면
//a+b+a = a+b+(a+b)가 되는 것임
String String::operator+ (const char* right) {
    String temp = *this; //생성자 string temp(*this);
    //객체타입을 받는 생성자를 안만들었는데 컴파일되는이유는? 컴파일러가 자동적으로 복사생성자 만들어주기 때문
    //멤버가 포인터가 아니라 배열 (메모리에 박힌)이기 때문에 배열 전체가 복사된다.
    strcat(temp.buffer,right);
    return temp;
}

//=는 대입으로 피연산자 객체 자체를 수정하게 되는 것이라 멤버함수 const도 안들어가고 반환값이 참조형
String& String::operator= (const String& right) {
    memcpy(buffer, right.buffer, sizeof(buffer));
    return *this;
}

String operator+ (const char* left, const String& right) {
    String temp(left); //생성자
    strcat(temp.buffer, right.buffer);
    return temp;
}

int main() {
    String s("hello");
    s = s + "world" + " !"; //(객체 + "world") + "hi" -> 객체 + "hi"
    printf("s = %s", s.getBuffer());

    String s2("hello");
    String t = "hello" + s; //"문자열" + 객체 (외부함수 이용)
}
