//
// Created by robin on 2026-11-19.
//

#ifndef C_STUDY_MEMBERCONSTRUCT_H
#define C_STUDY_MEMBERCONSTRUCT_H

#include <string>
class MemberConstruct {
private:
    std::string name;
    int age;
    int grade;

public:
    //생성자는 중복 정의 가능. 객체 생성 시 하나 골라 쓰면 된다.
    MemberConstruct(std::string name, int age, int grade);
    MemberConstruct(std::string name, int age);
};

/*
 생성자의 진짜 강점은 직접 정의한 생성자가 한개 혹은 오버로딩하여 여러개라면 무조건 하나를 호출해야한다.
 (유령객체 막을 수 있음)
 또 생성자를 사용하면 필수값 입력을 보장할 수 있게 된다.
 좋은 프로그램은 무한한 자유도가 주어지는 프로그램이 아니라 적당한 제약이 있는 프로그램이다.
 */

#endif //C_STUDY_MEMBERCONSTRUCT_H
