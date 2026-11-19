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


#endif //C_STUDY_MEMBERCONSTRUCT_H
