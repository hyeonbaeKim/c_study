//
// Created by robin on 2026-11-19.
//

#include "MemberConstructThis.h"
#include <iostream>

/*
 c++은 java와 다르게 위임생성자를 무조건 멤버 초기화 리스트로 호출한다.
 */
MemberConstructThis::MemberConstructThis(std::string name, int age)
    : MemberConstructThis(name, age, 10) {}
/*
    this.name = name;
    this.age = age; 부분이 중복되서 코드 중복 방지를 위해 this키워드 사용
    이 코드는 첫번째 생성자 내부에서 두번째 생성자를 호출한다.
    java는 생성자 본문 안에 this(name, age, 10)로 생성자 코드의 첫 줄에만 작성할 수 있다.
*/


MemberConstructThis::MemberConstructThis(std::string name, int age, int grade) {
    this->name = name;
    this->age = age;
    this->grade = grade;
    std::cout << this->name  << " " << this->age << " " << this->grade << std::endl;
}

int main() {
    MemberConstructThis* memberConstructThis = new MemberConstructThis("lee",33);
}