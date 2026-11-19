//
// Created by robin on 2026-11-19.
//

#ifndef C_STUDY_MEMBERCONSTRUCTTHIS_H
#define C_STUDY_MEMBERCONSTRUCTTHIS_H

#include <string>
class MemberConstructThis {
    std::string name;
    int age;
    int grade;

public:
    MemberConstructThis(std::string name, int age);
    MemberConstructThis(std::string name, int age, int grade);
};


#endif //C_STUDY_MEMBERCONSTRUCTTHIS_H
