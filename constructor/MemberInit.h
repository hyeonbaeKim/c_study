//
// Created by robin on 2026-11-19.
//

#ifndef C_STUDY_MEMBERINIT_H
#define C_STUDY_MEMBERINIT_H
#include <string>

class MemberInit {
public:
    std::string name;
    int age;
    int grade;
    /*
     생성자가 정의되지 않았다고 생성자가 없는 것이 아니다.
     MemberInit() {}; <- 다음과 같은 아무일도 하지 않는 기본생성자가 생략된 것이다.
     */
};


#endif //C_STUDY_MEMBERINIT_H
