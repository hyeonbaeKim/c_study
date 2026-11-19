//
// Created by robin on 2026-11-19.
//

#ifndef C_STUDY_EXAMPLE1_H
#define C_STUDY_EXAMPLE1_H


class Example1 {
private:
    const int id; //생성 후 값을 바꿀 수 없어서 반드시 생성 시 초기화해야함
    int& value; //반드시 생성 시 참조 대상을 정해야 함

public:
    Example1(int id, int& value);
};


#endif //C_STUDY_EXAMPLE1_H
